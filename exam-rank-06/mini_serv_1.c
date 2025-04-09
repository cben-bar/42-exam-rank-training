#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>


int    fd_max, id = 0, sockfd = 0;
int ids[65000];
char buffer[200100];
fd_set aset, rset, wset;

void    fatal(char *str)
{
    if (sockfd > 2)
        close(sockfd);
    write(2, str, strlen(str));
    write(2, "\n", 1);
    exit(1);
}

void    sending(int connfd)
{
        for (int fd = 3; fd <= fd_max; fd++)
        {
            if (fd != connfd && FD_ISSET(fd, &wset))
            {
                if (send(fd, buffer, strlen(buffer), 0) < 0)
                    fatal("Fatal error");
        }
    }
    bzero(&buffer, sizeof(buffer));
}

int main(int ac, char **av)
{
    int connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;

    if (ac != 2)
        fatal("Wrong number of arguments");

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1)
        fatal("Fatal error");
    bzero(&servaddr, sizeof(servaddr)); 

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(2130706433);
    servaddr.sin_port = htons(atoi(av[1])); 
  
    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        fatal("Fatal error"); 
    if (listen(sockfd, 6000) != 0)
        fatal("Fatal error");

    len = sizeof(cli);

    // ================================ //

    fd_max = sockfd;
    FD_ZERO(&aset);
    FD_SET(sockfd, &aset);

    // ================================ //

while (1)
{
        rset = wset = aset;
    
        if (select(fd_max + 1, &rset, &wset, 0, 0) < 0)
            continue ;

        if (FD_ISSET(sockfd, &rset))
        {
            connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
            if (connfd < 0)
                fatal("Fatal error");

            FD_SET(connfd, &aset);

            ids[connfd] = id;
            id++;
            sprintf(buffer, "server: client %d just arrived\n", ids[connfd]);
            sending(connfd);
            
            fd_max = connfd > fd_max ? connfd : fd_max;
            continue ;
        }

        for (int fd = 3; fd <= fd_max; ++fd)
        {
            if (FD_ISSET(fd, &rset))
            {
                int r = 1;
                char msg[200000];
                bzero(&msg, sizeof(msg));

                while (r == 1 && msg[strlen(msg) - 1] != '\n')
                    r = recv(fd, msg + strlen(msg), 1, 0);
                if (r <= 0) {
                    sprintf(buffer, "server: client %d just left\n", ids[fd]);
                    FD_CLR(fd, &aset);
                    close(fd);
                }
                else
                    sprintf(buffer, "client %d: %s", ids[fd], msg);
                sending(fd);
            }
        }
    }
    return (0);
}
