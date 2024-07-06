/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 18:58:53 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_DOG_HPP
# define H_DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class	Dog: public Animal
{
public:
	Dog();
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);
	~Dog();
	void	makeSound() const;
	Brain	*getBrain() const;
	void	setBrain(Brain *brain);

private:
	Brain	*_brain;
};

#endif
