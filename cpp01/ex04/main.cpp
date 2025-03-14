/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:48:28 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/12 12:28:45 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

bool replaceAll(const std::string &str, const std::string &from, const std::string &to)
{
	std::ifstream infile(str.c_str());
	if (!infile)
	{
		std::cerr << "Error opening infile" << std::endl;
		return false;
	}
	
	std::string outName = str + ".replace";
	std::ofstream outfile(outName.c_str());
	if (!outfile)
	{
		std::cerr << "Error opening outfile" << std::endl;
		infile.close();
		return false;
	}
	size_t pos;
	std::string line;

	while (std::getline(infile, line))
	{
		pos = 0;
		while ((pos = line.find(from, pos)) != std::string::npos)
		{
			line.erase(pos, from.length());
			line.insert(pos, to);
			pos += to.length();
		}
		outfile << line << std::endl;
	}	
	infile.close();
	outfile.close();
	return true;
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string str(argv[1]);
		std::string s1(argv[2]);
		std::string s2(argv[3]);
		if (s1.empty())
		{
			std::cout << "Error: The string to replace cannot be empty" << std::endl;
			return 1;
		}
		if (!replaceAll(str, s1, s2))
			return 1;
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <file> <find> <replace>" << std::endl;
	}
	return 0;
}