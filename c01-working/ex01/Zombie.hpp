/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:42:36 by atang             #+#    #+#             */
/*   Updated: 2025/03/09 17:42:36 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// ANSI Colour codes for terminal output
#define RST "\033[0m"       // Reset Colour
#define G 	"\033[1;32m"    // Green
#define R   "\033[1;31m"    // Red
#define Y 	"\033[1;33m"    // Yellow
#define B   "\033[1;34m"    // Blue 

class Zombie
{
    public:
        Zombie(); // Default constructor
        Zombie(std::string name); // Overloaded constructor
        ~Zombie();
        void announce() const; // Announce function
        void setName(const std::string& newName); // To set name after allocation

    private:
        std::string name;   
};

Zombie  *zombieHorde(int N, std::string name);

#endif