/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 19:02:06 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_WRONG_CAT_HPP
# define H_WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class	WrongCat: public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat &rhs);
	WrongCat &operator=(WrongCat &rhs);
	~WrongCat();
	virtual void	makeSound() const;
};

#endif
