/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:17:15 by cben-bar          #+#    #+#             */
/*   Updated: 2021/11/18 02:20:40 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next_el;
	void	*content;

	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		next_el = ft_lstnew(content);
		if (!next_el)
		{
			del(content);
			ft_lstclear(&new, del);
		}
		ft_lstadd_back(&new, next_el);
		lst = lst->next;
	}
	return (new);
}
