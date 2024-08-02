/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:20:28 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 16:58:35 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP


#include "AAnimal.hpp"
#include "Brain.hpp"


class Dog : public AAnimal {
	private:
		Brain *dogBrain;

	public:
		Dog(); 
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();

		void makeSound() const;
		Brain *getBrain() const; //Return a pointer to the Dog's Brain object
};


#endif