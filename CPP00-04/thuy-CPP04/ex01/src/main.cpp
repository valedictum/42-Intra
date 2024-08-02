/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:43:19 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 16:51:54 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Brain.hpp"

//Test provided by subject

/*
int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

return 0;
}
*/

//Run more tests here ...

// int main() 
// {
// 	Animal *array[6]; //Declare an array of 6 animals

// 	for (int i = 0; i < 6 / 2; i++) //For the first half of the array, create Dogs
// 		array[i] = new Dog();
	
// 	for (int i = 0; i < 6 / 2; i++) //For the second half of the array, create Cats
// 		array[i + (6 / 2)] = new Cat();

// 	for (int i = 0; i < 6; i++) //Delete all animals in the array
// 		delete array[i];

// 	return (0);
// }

//Test whether Dog/Cat copies are deep or shallow


int main()
{
	Dog basic;
	Dog tmp = basic;

	Cat basic2;
	Cat tmp2 = basic2;
	return 0;
}
