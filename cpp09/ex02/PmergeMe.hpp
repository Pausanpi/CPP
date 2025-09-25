/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:00:47 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/14 11:14:14 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int>  _deq;
    double _timeVec;
    double _timeDeq;

    void recursiveSortVector(std::vector<int> &vec, size_t n_pairs);
    void recursiveSortDeque(std::deque<int> &deq, size_t n_pairs);

public:

	PmergeMe(char **begin, char **end);

	void displayBefore() const;
	void displayAfter() const;
	void sortVector();
	void sortDeque();
	void displayTimes() const;
	
	class InvalidInputException : public std::exception {
		public:
			const char *what() const throw() { return "Invalid input"; }
	};
};

#endif
