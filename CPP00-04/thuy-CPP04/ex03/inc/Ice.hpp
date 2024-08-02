/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:05:37 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:29:54 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concrete class, can be instantiated

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"


class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &copy);
		~Ice();
		
		Ice *clone() const; //Return a pointer to a new Ice object
		void use(ICharacter &target); 
};


#endif