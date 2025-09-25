/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:23:57 by pausanch          #+#    #+#             */
/*   Updated: 2025/09/10 15:43:34 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack<T> &operator=(const MutantStack &other);
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	
	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}
};

#include "MutantStack.tpp"
