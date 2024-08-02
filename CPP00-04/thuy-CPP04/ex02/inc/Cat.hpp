/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:09:02 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 16:58:27 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP


#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat : public AAnimal {
	private:
	    Brain *catBrain;
		
	public:
		Cat(); 
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		virtual ~Cat();

		void makeSound() const;
		Brain *getBrain() const; //Returns a pointer to the Cat's Brain object
};


#endif