/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:41 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 17:03:03 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CURE_HPP
# define H_CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class	Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure &rhs);
	Cure &operator=(const Cure &rhs);
	~Cure();
	Cure 	*clone() const;
	void	use(ICharacter &target);
};

#endif
