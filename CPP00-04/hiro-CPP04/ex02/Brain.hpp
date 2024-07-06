/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:53:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/26 17:27:01 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_BRAIN_HPP
# define H_BRAIN_HPP

# include <iostream>

class	Brain
{
public:
	Brain();
	Brain(Brain &rhs);
	Brain &operator=(Brain &rhs);
	~Brain();
	std::string	getIdea(size_t index) const;
	void		setIdea(size_t index, std::string idea);

private:
	std::string	_ideas[100];
};

#endif
