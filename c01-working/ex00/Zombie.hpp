/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:30:33 by atang             #+#    #+#             */
/*   Updated: 2025/01/19 16:06:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

#define RST "\033[0m"
#define G 	"\033[1;32m"
#define R   "\033[1;31m"
#define Y 	"\033[1;33m"

class Zombie
{
    private:
        std::string name;
    
    public:
        Zombie(std::string name);   // Constructor 
        ~Zombie();                  // Destructor
        void announce() const;      // Announce function
};

#endif