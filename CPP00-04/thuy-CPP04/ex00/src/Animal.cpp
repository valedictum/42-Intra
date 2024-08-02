/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:55:37 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 15:11:20 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : type("Rando") {
	cout << YELLOW_BB << "A Random animal " << type << " is born by default!" << RESET << endl;
}

Animal::Animal(const Animal &copy) : type(copy.type) {
	cout << YELLOW_BB << "A clone of Animal " << type << " is born!" << RESET << endl;

}

Animal &Animal::operator=(const Animal &copy) {
	cout << YELLOW_BB << "A clone of Animal " << type << " is assigned!" << RESET << endl;
	if (this!= &copy)
		type = copy.type;
	return (*this);
}

Animal::~Animal() {
	cout << RED_BB << "The animal " << type << " is dead!" << RESET << endl;
}

void Animal::makeSound() const {
	cout << YELLOW_BB << "Weowww coof coof!" << RESET << endl;
}

string Animal::getType() const {
	return (type);
}