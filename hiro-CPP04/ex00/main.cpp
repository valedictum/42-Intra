/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:13:21 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 17:05:19 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "[ Animal Construct ]" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "[ Animal Functions ]" << std::endl;
	std::cout << "j's type: " << j->getType() << " " << std::endl;
	std::cout << "i's type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "[ WrongAnimal Construct ]" << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongi = new WrongCat();
	std::cout << std::endl;

	std::cout << "[ WrongAnimal Functions ]" << std::endl;
	std::cout << "worngi's type: " << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); //will output the cat sound!
	wrongmeta->makeSound();
	std::cout << std::endl;

	std::cout << "[ Destruct ]" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongmeta;
	delete wrongi;
	return 0;
}
