/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:29:14 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/11 12:29:27 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string &token) const {
    return (token.size() == 1 && token[0] >= '0' && token[0] <= '9');
}

int RPN::evaluate(const std::string &expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isNumber(token)) {
            _stack.push(token[0] - '0');
        }
        else if (isOperator(token)) {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            if (token == "+")
                _stack.push(a + b);
            else if (token == "-")
                _stack.push(a - b);
            else if (token == "*")
                _stack.push(a * b);
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Error");
                _stack.push(a / b);
            }
        }
        else {
            throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
