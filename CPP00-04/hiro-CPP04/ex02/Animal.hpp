/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:15:18 by hiono             #+#    #+#             */
/*   Updated: 2024/06/26 18:21:46 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_ANIMAL_HPP
# define H_ANIMAL_HPP

# include <iostream>

class	Animal
{
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &rhs);
	Animal &operator=(const Animal &rhs);
	virtual		~Animal();
	void		makeSound() const;
	std::string	getType() const;
	void		setType(std::string type);

protected:
	std::string	_type;
};

#endif
