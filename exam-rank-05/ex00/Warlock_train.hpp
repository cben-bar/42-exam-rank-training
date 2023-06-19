/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock_train.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <cben-bar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:56:32 by cben-bar          #+#    #+#             */
/*   Updated: 2023/06/19 18:38:23 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_TRAIN_HPP
# define WARLOCK_TRAIN_HPP

#include <iostream>

class Warlock
{
	public:
	
		Warlock(std::string name, std::string title);
		Warlock &operator=(const Warlock & origin);
		~Warlock();

		std::string	const &getName() const;
		std::string	const &getTitle() const;

		void	setTitle(std::string const &title);

		void	introduce() const;
	
	private:
	
		Warlock();
		Warlock(const Warlock &origin);
	
		std::string _name;
		std::string _title;
};

#endif