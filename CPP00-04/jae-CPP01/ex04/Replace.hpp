/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:49:53 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/08 23:00:17 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
private:
	std::string	filename;
	std::string	targetStr;
	std::string	replaceStr;

public:
	Replace( std::string filename, std::string targetStr, std::string replaceStr );
	~Replace( void );

	void	replace( void );
};

#endif
