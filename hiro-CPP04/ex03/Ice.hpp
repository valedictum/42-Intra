/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:41 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 15:52:10 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_ICE_HPP
# define H_ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class	Ice: public AMateria
{
public:
	Ice();
	Ice(const Ice &rhs);
	Ice &operator=(const Ice &rhs);
	~Ice();
	Ice 	*clone() const;
	void	use(ICharacter &target);
};

#endif
