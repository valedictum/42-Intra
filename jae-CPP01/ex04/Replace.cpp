/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:52:47 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/11 14:40:34 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace( std::string filename, std::string targetStr, std::string replaceStr )
{
	this->filename = filename;
	this->targetStr = targetStr;
	this->replaceStr = replaceStr;
}

Replace::~Replace( void ) {}

void	Replace::replace( void )
{
	std::string		fileName = this->filename;
	std::ifstream	inputFile(fileName);
	if (!inputFile)
	{
		std::cerr << "Failed to open the input file." << std::endl;
		return ;
	}

	size_t		pos = fileName.find(".");
	std::string	pureFileName;
	if (pos != 0)
		pureFileName = fileName.substr(0, pos);
	else
		pureFileName = fileName;
	std::string		outfileName = pureFileName + ".replace";
	std::ofstream	outputFile(outfileName);
	if (!outputFile)
	{
		std::cerr << "Failed to open the output file." << std::endl;
		return ;
	}

	std::string	line;
	size_t		posTarget;
	size_t		len;
	size_t		lenOfTarget;
	std::string	before;
	std::string	after;
	std::string	targetStr = this->targetStr;
	std::string	replaceStr = this->replaceStr;
	while (std::getline(inputFile, line))
	{
		while ((posTarget = line.find(targetStr)) != std::string::npos)
		{
			len = line.length();
			lenOfTarget = targetStr.length();
			before = line.substr(0, posTarget);
			after = line.substr(posTarget + lenOfTarget, len);
			before += replaceStr;
			line = before + after;
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
}
