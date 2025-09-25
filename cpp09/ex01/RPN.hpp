/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:29:16 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/11 12:41:34 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN {
	private:
		std::stack<int> _stack;

		bool isOperator(const std::string &token) const;
		bool isNumber(const std::string &token) const;
		
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int evaluate(const std::string &expression);
};
