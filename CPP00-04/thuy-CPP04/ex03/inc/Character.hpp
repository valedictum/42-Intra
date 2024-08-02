/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:15:16 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 19:07:40 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concrete class that will implement the ICharacter interface

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"


class AMateria; //Forward declaration of AMateria class

class Character : public ICharacter {
	private:
		string name;
		AMateria *inventory[4];
		AMateria *floor[4]; //To handle unequiped Materias

	public:
		Character(const string &name);
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character();

		const string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};


#endif