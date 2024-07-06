/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:15:18 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 19:02:11 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_WRONG_ANIMAL_HPP
# define H_WRONG_ANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal &rhs);
	WrongAnimal &operator=(WrongAnimal &rhs);
	virtual	~WrongAnimal();
	virtual void	makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);

protected:
	std::string	_type;
};

#endif
