/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:13:22 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:29:43 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Is an abstrace base class, cannot bew instantiated

#ifndef AMATERIA_HPP
#define AMATERIA_HPP


#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "AnsiEscSeq.hpp"

using std::cout;
using std::endl;
using std::string;


class ICharacter; //Forward declaration of ICharacter class

class AMateria {
	protected:
		string type;

	public:
		AMateria(string const &type);
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &copy);
		virtual ~AMateria();
		
		string const & getType() const; //Returns the materia type
		virtual AMateria *clone() const = 0; //Returns a pointer to a new copy of the materia
		virtual void use(ICharacter &target); //Use the materia on the target character
};


#endif