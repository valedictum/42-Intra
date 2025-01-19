/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:13:55 by atang             #+#    #+#             */
/*   Updated: 2025/01/19 15:27:33 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    /* Add intentional leak + silence unused leak variable warning
    int* leak = new int[10];
    std::cout << "Leaked value: " << leak[0] << std::endl;
    */
    Zombie  *heapZombie = newZombie("HeapZombie"); // Create a Zombie on the heap
    heapZombie->announce();
    delete  heapZombie; // Clean up memory
    randomChump("StackZombie");
    return (0);
}
