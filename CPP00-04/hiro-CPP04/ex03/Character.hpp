/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:21:45 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 16:48:57 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CHARACTER_HPP
# define H_CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class	Character: public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character &rhs);
	Character &operator=(const Character &rhs);
	~Character();
	std::string const	&getName() const;
	AMateria 			*getInventory(int index) const;
	AMateria 			*getTrash(int index) const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria	*_inventory[4];
	AMateria	*_trash[100];
	void		clearInventory();
	void		clearTrash();
};

#endif
