/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:49:37 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:30:01 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concrete class, can be instantiated

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"


class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &copy);
		~Cure();
		
		Cure *clone() const; //Return a pointer to a new Cure object
		void use(ICharacter &target); 
};


#endif