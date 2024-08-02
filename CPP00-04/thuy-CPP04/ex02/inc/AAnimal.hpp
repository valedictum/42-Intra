/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:55:35 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/18 17:34:37 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP


#include <iostream>
#include "AnsiEscSeq.hpp"

using std::string;
using std::cout;
using std::endl;


class AAnimal {
	protected:
	    string type; 
	
	public:
		AAnimal(); 
		AAnimal(const AAnimal &copy);  
		AAnimal &operator=(const AAnimal &copy); 
		virtual ~AAnimal();  
		
		virtual void makeSound() const = 0; //Pure virtual function to make class abstract
		string getType() const; 
};


#endif