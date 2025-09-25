/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:00:56 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/12 11:01:19 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter(argv + 1, argv + argc);
        sorter.displayBefore();
        sorter.sortVector();
        sorter.sortDeque();
        sorter.displayAfter();
        sorter.displayTimes();
    } catch (std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
