/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:20:28 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/18 00:49:46 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"


class Dog : public Animal {
	public:
		Dog(); 
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		~Dog();

		void makeSound() const;
};


#endif