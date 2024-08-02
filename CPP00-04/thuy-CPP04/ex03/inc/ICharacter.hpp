/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:07:29 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:04:39 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Interface with pure virtual functions

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"


class AMateria;

class ICharacter {
	public:
		virtual ~ICharacter() {} //Destructor
		virtual std::string const & getName() const = 0; //Return the name of the character
		virtual void equip(AMateria* m) = 0; //Equip an AMateria to the character
		virtual void unequip(int idx) = 0; //Unequip an AMateria from the character
		virtual void use(int idx, ICharacter& target) = 0; //Use an AMateria on a target
};


#endif