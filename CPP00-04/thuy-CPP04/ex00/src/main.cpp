/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:43:19 by tquemato          #+#    #+#             */
/*   Updated: 2024/08/02 16:40:12 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"

// int main()
// {
// 	const Animal *meta = new Animal(); //Declare a base class pointer to a new Animal object
// 	const Animal *j = new Dog(); //Declare a base class pointer to a new Dog object
// 	const Animal *i = new Cat(); //Declare a base class pointer to a new Cat object

// 	std::cout << j->getType() << " " << std::endl; //Will display the dog type!
// 	std::cout << i->getType() << " " << std::endl; //Will display the cat type!
// 	i->makeSound(); //Will output the cat sound!
// 	j->makeSound(); //Will output the dog sound!
// 	meta->makeSound(); // Will output the animal sound!
	
// 	return (0);
// }

//Run more tests here for WrongAnimal...

int main()
{
	const WrongAnimal *accident = new WrongAnimal(); //Call the WrongAnimal constructor, which calls the base class due to inheritance
	//For assignment operators, declaration and assignment must not be on the same line
	WrongAnimal assigned; //Call the WrongAnimal constructor, which calls the base class
	assigned = *accident; //Call the assignment operator

	const WrongCat *cat = new WrongCat(); //Call the WrongCat constructor, which calls the WrongAnimal constructor, which calls the base class
	WrongCat copycat; //Call the WrongCat constructor, which calls the WrongAnimal constructor, which calls the base class
	copycat = *cat; //Call the assignment operator

	//Get type and makeSound for each object, it should all be the same
	cout << accident->getType() << " " << endl;
	accident->makeSound();

	cout << cat->getType() << " " << endl;
	cat->makeSound();

	cout << assigned.getType() << " " << endl;
	assigned.makeSound();

	cout << copycat.getType() << " " << endl;
    copycat.makeSound();

    delete accident; //Deallocate memory for the objects
	delete cat; //Deallocate memory for the objects
	//Do not delete assigned or copycat as they are const pointers

	return (0);
}

