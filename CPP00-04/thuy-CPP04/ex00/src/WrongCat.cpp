/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:20:26 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 20:23:30 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
	cout << MAGENTA << "A WrongCat has been born by default!" << RESET << endl;
	type = "WrongCat"; 
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	cout << MAGENTA << "A WrongCat has been born from a copy!" << RESET << endl;
	type = copy.type; 
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	cout << MAGENTA << "A clone of a WrongCat has been assigned!" << RESET << endl;
	if (this != &copy)
        type = copy.type; 
    return (*this);
}

WrongCat::~WrongCat() {
	cout << RED_BB << "A WrongCat has died!" << RESET << endl;
}