/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:44:59 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 20:06:07 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP


#include <iostream>
#include "AnsiEscSeq.hpp"

using std::cout;
using std::endl;
using std::string;


class Brain {
	public:
		string *ideas[100]; //Array of pointers to strings representing brain ideas

		Brain(); // Default constructor
		Brain(const Brain &copy); // Copy constructor
		Brain &operator=(const Brain &copy); //Copy assignment operator
		virtual ~Brain(); // Destructor
};


#endif