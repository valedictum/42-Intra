/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:17:10 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:33:11 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concrete class which implements the IMateriaSource interface

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class AMateria;

class MateriaSource : public IMateriaSource {
	public:
		AMateria* materias[4];

		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &copy);
		~MateriaSource();

		void learnMateria(AMateria*); //Learn a Materia
		AMateria* createMateria(std::string const &type); //Create a Materia
};



#endif