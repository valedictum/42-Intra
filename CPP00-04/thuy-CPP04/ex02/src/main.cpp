/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:43:19 by tquemato          #+#    #+#             */
/*   Updated: 2024/08/02 17:07:07 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

/*
int main()
{
const AAnimal* j = new Dog();
const AAnimal* i = new Cat();
delete j;//should not create a leak
delete i;

return 0;
}
*/

//Run more tests here ...

int main() 
{
	//AAnimal test; //Compile error due to abstract class
	
	AAnimal *array[6]; //Declare an array of 6 animals

	for (int i = 0; i < 6 / 2; i++) //For the first half of the array, create Dogs
		array[i] = new Dog();
	
	for (int i = 0; i < 6 / 2; i++) //For the second half of the array, create Cats
		array[i + (6 / 2)] = new Cat();

	for (int i = 0; i < 6; i++) //Delete all animals in the array
		delete array[i];

	return (0);
}
