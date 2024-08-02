/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:20:30 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 17:00:08 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
	cout << BLUE_BB << "A Dog has been born by default!" << RESET << endl;
	type = "Dog";
	dogBrain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy) {
	cout << BLUE_BB << "A Dog has been born from a copy!" << RESET << endl;
	type = copy.type;
	dogBrain = new Brain(*copy.dogBrain);
}

Dog &Dog::operator=(const Dog &copy) {
	cout << BLUE_BB << "A clone of a Dog has been assigned!" << RESET << endl;
	if (this != &copy) {
        type = copy.type;
		dogBrain = new Brain(*copy.dogBrain);
	}
    return (*this);
}

Dog::~Dog() {
	cout << RED_BB << "A Dog has died!" << RESET << endl;
	delete dogBrain;
}

void Dog::makeSound() const {
	cout << BLUE_BB << "Woof!" << RESET << endl;
}

Brain *Dog::getBrain() const {
	return (dogBrain);
}