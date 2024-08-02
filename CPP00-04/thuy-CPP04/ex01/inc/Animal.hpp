/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:55:35 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/18 17:34:37 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include "AnsiEscSeq.hpp"

using std::string;
using std::cout;
using std::endl;


class Animal {
	protected:
	    string type; 
	
	public:
		Animal(); //Default constructor
		Animal(const Animal &copy); //Copy constructor
		Animal &operator=(const Animal &copy); //Copy assignment operator
		virtual ~Animal(); //Destructor
		
		virtual void makeSound() const; //Virtual for derivatives to inherit and implement
		string getType() const; //Getter for type
};


#endif