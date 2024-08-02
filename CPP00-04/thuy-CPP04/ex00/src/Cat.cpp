/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:09:00 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 20:23:04 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
	cout << MAGENTA_BB << "A Cat has been born by default!" << RESET << endl;
	type = "Cat"; 
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	cout << MAGENTA_BB << "A Cat has been born from a copy!" << RESET << endl;
	type = copy.type; 
}

Cat &Cat::operator=(const Cat &copy) {
	cout << MAGENTA_BB << "A clone of a Cat has been assigned!" << RESET << endl;
	if (this != &copy)
        type = copy.type; 
    return (*this);
}

Cat::~Cat() {
	cout << RED_BB << "A Cat has died!" << RESET << endl;
}

void Cat::makeSound() const {
	cout << MAGENTA_BB << "Meow!" << RESET << endl;
}