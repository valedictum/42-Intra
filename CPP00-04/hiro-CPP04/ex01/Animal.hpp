/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:15:18 by hiono             #+#    #+#             */
/*   Updated: 2024/06/29 13:08:06 by atang            ###   ########.fr       */
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
	~Animal();
	virtual void	makeSound() const;
	std::string		getType() const;
	void			setType(std::string type);

protected:
	std::string	_type;
};

#endif
