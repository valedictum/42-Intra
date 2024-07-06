/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:15:18 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 12:13:37 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_AANIMAL_HPP
# define H_AANIMAL_HPP

# include <iostream>

class	AAnimal
{
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &rhs);
	AAnimal &operator=(const AAnimal &rhs);
	virtual			~AAnimal();
	virtual void	makeSound() const = 0;
	std::string	getType() const;
	void		setType(std::string type);

protected:
	std::string	_type;
};

#endif
