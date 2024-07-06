/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:13:21 by hiono             #+#    #+#             */
/*   Updated: 2024/06/29 13:11:51 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main(void)
{
	std::cout << "[ Single instance ]" << "\n";
	std::cout << "[ - Construct - ]" << "\n";
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << "[ - Destruct - ]" << "\n";
	delete d; //should not create a leak
	delete c;
	
	std::cout << "\n";
	std::cout << "[ Array of instances ]" << "\n";
	std::cout << "[ - Construct - ]" << "\n";
	int size = 10;
	Animal *animal_array[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "array index: " << i << "\n";
		if (i % 2 == 0)
			animal_array[i] = new Dog();
		else
			animal_array[i] = new Cat();
	}
	std::cout << "[ - Destruct - ]" << "\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "array index: " << i << "\n";
		delete animal_array[i];
	}

	std::cout << "\n";
	std::cout << "[ Deep Copy Test Dog ]" << "\n";
	Dog dog;
	Brain	dog_brain;
	dog_brain.setIdea(0, "Original dog's brain");
	dog.setBrain(&dog_brain);
	Dog co_dog;
	co_dog = dog;
	Dog cc_dog(dog);
	std::cout << "original dog's brain             :" << dog.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by operator dog's brain   :" << co_dog.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by constuctor dog's brain :" << cc_dog.getBrain()->getIdea(0) << "\n";	
	dog_brain.setIdea(0, "NO DOG BRAIN!!");
	dog.setBrain(&dog_brain);
	std::cout << "original dog's brain             :" << dog.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by operator dog's brain   :" << co_dog.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by constuctor dog's brain :" << cc_dog.getBrain()->getIdea(0) << "\n";	

	std::cout << "\n";
	std::cout << "[ Deep Copy Test Cat ]" << "\n";
	Cat cat;
	Brain	cat_brain;
	cat_brain.setIdea(0, "Original cat's brain");
	cat.setBrain(&cat_brain);
	Cat co_cat;
	co_cat = cat;
	Cat cc_cat(cat);
	std::cout << "original cat's brain             :" << cat.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by operator cat's brain   :" << co_cat.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by constuctor cat's brain :" << cc_cat.getBrain()->getIdea(0) << "\n";	
	cat_brain.setIdea(0, "NO CAT BRAIN!!");
	cat.setBrain(&cat_brain);
	std::cout << "original cat's brain             :" << cat.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by operator cat's brain   :" << co_cat.getBrain()->getIdea(0) << "\n";	
	std::cout << "copied by constuctor cat's brain :" << cc_cat.getBrain()->getIdea(0) << "\n";	

	std::cout << "\n";
	std::cout << "[ - Destruct - ]" << "\n";

	return 0;

}
