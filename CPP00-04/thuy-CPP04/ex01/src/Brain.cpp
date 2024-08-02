/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:06:13 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 20:56:14 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() : ideas() {
	cout << "A new Brain has been created!" << endl;
}

Brain::Brain(const Brain &copy) {
	cout << "A new Brain has been created as a copy of an existing one!" << endl;
	*this = copy; //Copy member variables to this current object
}

Brain &Brain::operator=(const Brain &copy) {
	cout << "A brain copy has been assigned!" << endl;
	if (this!= &copy) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	cout << "Brain Dead!" << endl;
}