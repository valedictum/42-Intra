/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:07:31 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 17:53:52 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(const string &name) : name(name) {
	cout << YELLOW_BB << "Character constructor called for " << name << endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL; //Start with an empty inventory at construction
		floor[i] = NULL; //Start with an empty floor at construction
	}
}

Character::Character(const Character &copy) : name(copy.name) {
	cout << YELLOW << "Character copy constructor called for " << name << endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = copy.inventory[i] ? copy.inventory[i]->clone() : NULL; //Deep copy of the inventory ensuring unique Materia objects
		floor[i] = copy.floor[i] ? copy.floor[i]->clone() : NULL; //Deep copy of the floor ensuring unique Materia objects
	}
} 

Character &Character::operator=(const Character &copy) {
	cout << YELLOW << "Character copy assignment operator called for " << name << endl;
	if (this != &copy) {
		name = copy.name;
		for (int i = 0; i < 4; i++) {
			delete inventory[i]; //Delete existing Materia before new Materia are created
			delete floor[i]; //Delete existing Materia before new Materia are created
			inventory[i] = copy.inventory[i] ? copy.inventory[i]->clone() : NULL; //Deep copy of the inventory ensuring unique Materia objects
			floor[i] = copy.floor[i] ? copy.floor[i]->clone() : NULL; //Deep copy of the floor ensuring unique Materia objects
		}
	}
	return (*this);
}

Character::~Character() {
	cout << RED_BB << "Character destructor called for " << name << RESET << endl;
	for (int i = 0; i < 4; i++) {
		delete inventory[i]; //Must delete inventory to prevent memory leaks
		delete floor[i]; //Must delete floor to prevent memory leaks
	}
}

const string &Character::getName() const {
	return (name);
}

void Character::equip(AMateria *m) {
	if (!m) //Check if the Materia is NULL, if so, return
		return ;
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) { //Check if the inventory is empty
			inventory[i] = m; //Equip the Materia
			cout << MAGENTA_BB << "The " << m->getType() << " Materia has been equipped to " << name << RESET << endl;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) //Check if the index within valid range
		return ;
	for (int i = 0; i < 4; i++) { //Find an empty floor slot
		if (!floor[i]) { //Check if the floor slot is empty (has a null pointer)
			floor[i] = inventory[idx]; //Move the Materia from the inventory to the floor
			inventory[idx] = NULL; //Unequip the Materia from the inventory by setting it to NULL
			cout << MAGENTA_BB << "The " << floor[i]->getType() << " Materia has been unequipped from " << name << RESET << endl;
			return ;
		}
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx > 3) { //Check if the index within valid range
		cout << RED_BB << "Invalid index: " << idx << ". Please enter a valid index between 0 and 3." << RESET << endl;
		return ;
	}
	if (inventory[idx]) //Check if the inventory slot is not empty
		inventory[idx]->use(target); //Use the Materia on the target
}