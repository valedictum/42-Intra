/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:13:55 by atang             #+#    #+#             */
/*   Updated: 2025/03/09 18:01:55 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
    Stack allocation (randomChump) is suitable for short-lived objects as stack 
    memory is automatically managed e.g. temporary zombies.
    Heap allocation (newZombie) is suitable for long-lived objects which need
    to persist beyond the scope of the function call e.g. permanent zombies. 
    This requires manual deallocation using 'delete' to avoid memory leaks.
*/

int main()
{
    /* Add intentional leak + silence unused leak variable warning
    int* leak = new int[10];
    std::cout << "Leaked value: " << leak[0] << std::endl;
    */
    Zombie  *heapZombie = newZombie("HeapZombie"); // Create a Zombie on the heap
    heapZombie->announce();
    delete  heapZombie; // Clean up to prevent leaks
    randomChump("StackZombie"); // Stack allocation
    return (0);
}
