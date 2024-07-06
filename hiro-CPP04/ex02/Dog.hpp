/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 12:20:07 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_DOG_HPP
# define H_DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class	Dog: public AAnimal
{
public:
	Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);
	~Dog();
	Brain	*getBrain() const;
	void	setBrain(Brain *brain);
	void	makeSound() const;

private:
	Brain	*_brain;
};

#endif
