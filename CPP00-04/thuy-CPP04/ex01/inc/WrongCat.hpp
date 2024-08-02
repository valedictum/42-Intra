/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:20:27 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 00:26:11 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP


#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal {
	public:
		WrongCat(); 
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &copy);
		~WrongCat();

		using WrongAnimal::makeSound;
};


#endif