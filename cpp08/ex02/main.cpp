/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:20:48 by pausanch          #+#    #+#             */
/*   Updated: 2025/09/10 16:05:28 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Valor stack[1]:" << mstack.top() << std::endl;

		std::cout << "Borro stack[1]..." << std::endl;
		mstack.pop();
		
		std::cout << "Size del stack: " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		std::cout << "Stack: ";
		while (it != ite)
		{
			std::cout << "[" << *it << "] ";
			++it;
		}
		std::cout <<"\n";
	}

	std::cout << "\n····················\n" << std::endl;

	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << "Valor stack[1]:" << mstack.back() << std::endl;

		std::cout << "Borro stack[1]..." << std::endl;
		mstack.pop_back();

		std::cout << "Size del stack: " << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		std::cout << "Stack: ";
		while (it != ite)
		{
			std::cout << "[" << *it << "] ";
			++it;
		}
		std::cout <<"\n";
	}
	return (0);
}