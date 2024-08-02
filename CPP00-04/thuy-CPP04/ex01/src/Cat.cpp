/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:09:00 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 16:59:32 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
	cout << MAGENTA_BB << "A Cat has been born by default!" << RESET << endl;
	type = "Cat"; 
	catBrain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	cout << MAGENTA_BB << "A Cat has been born from a copy!" << RESET << endl;
	type = copy.type; 
	catBrain = new Brain(*copy.catBrain); //Deep copy creates a unique brain, rather than using the same brain
}

Cat &Cat::operator=(const Cat &copy) {
	cout << MAGENTA_BB << "A clone of a Cat has been assigned!" << RESET << endl;
	if (this != &copy) {
        type = copy.type; 
		catBrain = new Brain(*copy.catBrain); //Deep copy creates a unique brain, rather than using the same brain
	}
    return (*this);
}

Cat::~Cat() {
	cout << RED_BB << "A Cat has died!" << RESET << endl;
	delete catBrain; 
}

void Cat::makeSound() const {
	cout << MAGENTA_BB << "Meow!" << RESET << endl;
}

Brain *Cat::getBrain() const {
	return (catBrain);
}