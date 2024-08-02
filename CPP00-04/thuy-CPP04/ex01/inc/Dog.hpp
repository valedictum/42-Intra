/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:20:28 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 16:51:31 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP


#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal {
	private:
		Brain *dogBrain;

	public:
		Dog(); 
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		virtual ~Dog(); //virtual ensures proper cleanup of derived class resources when deleting through a base class pointer

		void makeSound() const;
		Brain *getBrain() const; //Return a pointer to the Dog's Brain object
};


#endif