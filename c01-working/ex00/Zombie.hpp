/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:30:33 by atang             #+#    #+#             */
/*   Updated: 2025/03/09 18:01:54 by atang            ###   ########.fr       */
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

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(std::string name);   // Constructor 
        ~Zombie();                  // Destructor
        void announce() const;      // Member announce function (doesn't modify object state)
};

// Function prototypes
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif