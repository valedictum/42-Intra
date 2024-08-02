/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:13:30 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/31 17:11:45 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"


//Test provided by subject

int main()
{
	IMateriaSource* src = new MateriaSource(); //Create a new MateriaSource `src`
	src->learnMateria(new Ice()); //`src` learns the Ice materia
	src->learnMateria(new Cure()); //`src` learns the Cure materia
	ICharacter* me = new Character("me"); //Create a new Character `me`

	AMateria* tmp; //Create a temporary AMateria pointer for storing the created materia before equipping

	tmp = src->createMateria("ice"); //`tmp` is assigned the Ice materia created by `src`
	me->equip(tmp); //`me` equips `tmp`
	tmp = src->createMateria("cure"); //`tmp` is assigned the Cure materia created by `src`
	me->equip(tmp); //`me` equips `tmp`
	ICharacter* bob = new Character("bob"); //Create a new Character `bob`	
	me->use(0, *bob); //`me` uses the first materia on `bob`
	me->use(1, *bob); //`me` uses the second materia on `bob`

	delete bob;
	delete me;
	delete src; //Delete the MateriaSource to avoid memory leaks
	return 0;
}


/*
Should output:
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
*/

//Implement more tests...

/*
int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *thuggo = new Character("thuggo");

	AMateria *tmp;

	tmp = src->createMateria("ice");
	thuggo->equip(tmp);
	tmp = src->createMateria("cure");
	thuggo->equip(tmp);

	ICharacter *charlie = new Character("charlie");

	thuggo->use(0, *charlie); //Use ice materia
	thuggo->use(1, *charlie); //Use cure materia

	//Unequip a materia and use the remaining one
	thuggo->unequip(0); //Unequip ice materia
	thuggo->use(42, *charlie); //Test invalid index handling

	//Equip a new materia and use it
	tmp = src->createMateria("cure");
	thuggo->equip(tmp);
	thuggo->use(0, *charlie); //Use cure materia
	thuggo->use(1, *charlie); //Use cure materia

	delete charlie;
	delete thuggo;
	delete src;
	return (0);
}
*/

