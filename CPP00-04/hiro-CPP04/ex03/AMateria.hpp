/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:02:26 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 16:13:44 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_AMATERIA_HPP
# define H_AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria();
	AMateria(const AMateria &rhs);
	AMateria &operator=(const AMateria &rhs);
	virtual	~AMateria();
	AMateria(std::string const &type);
	std::string const 	&getType() const;
	virtual AMateria 	*clone() const = 0;
	virtual void		use(ICharacter &target);

protected:
	std::string	_type;
};

#endif
