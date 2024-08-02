/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:14:18 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:33:21 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Interface for the MateriaSource class

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"


class IMateriaSource {
	public:
		virtual ~IMateriaSource() {} //Destructor
		virtual void learnMateria(AMateria*) = 0; //Learn a Materia
		virtual AMateria* createMateria(std::string const & type) = 0; //Create a Materia
};


#endif