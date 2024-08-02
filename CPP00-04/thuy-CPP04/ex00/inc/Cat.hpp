/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:09:02 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 00:10:51 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP


#include "Animal.hpp"


class Cat : public Animal {
	public:
		Cat(); 
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat();

		void makeSound() const;
};


#endif