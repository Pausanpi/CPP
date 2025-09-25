/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:30:47 by pausanch          #+#    #+#             */
/*   Updated: 2025/09/09 11:58:18 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> a(5);
        for (size_t i = 0; i < a.size(); ++i)
            a[i] = i * 10;

        Array<int> b = a;
        b[0] = 999;

        Array<int> c;
        c = a;
        c[1] = 888;

        std::cout << "a: ";
        for (size_t i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << "\n";

        std::cout << "b: ";
        for (size_t i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << "\n";

        std::cout << "c: ";
        for (size_t i = 0; i < c.size(); ++i)
            std::cout << c[i] << " ";
        std::cout << "\n";

        std::cout << "Trying to access out of bounds...\n";
        std::cout << a[-10] << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}