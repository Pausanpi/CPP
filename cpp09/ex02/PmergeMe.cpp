/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:01:30 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/14 12:13:36 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// ----------------------------- Public interface -----------------------------

PmergeMe::PmergeMe(char **begin, char **end) : _timeVec(0.0), _timeDeq(0.0) {
	for (char **it = begin; it != end; ++it) {
		std::string arg(*it);
		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInputException();
		long nb = std::atol(arg.c_str());
		if (nb < 0 || nb > INT_MAX)
			throw InvalidInputException();
		if (std::find(_vec.begin(), _vec.end(), static_cast<int>(nb)) == _vec.end()) {
			_vec.push_back(static_cast<int>(nb));
			_deq.push_back(static_cast<int>(nb));
		}
	}
}

void PmergeMe::displayBefore() const {
	std::cout << "Before: ";
	size_t limit = std::min<size_t>(10, _vec.size());
	for (size_t i = 0; i < limit; ++i)
		std::cout << _vec[i] << ' ';
	if (_vec.size() > 10) std::cout << "[...]";
	std::cout << '\n';
}

void PmergeMe::displayAfter() const {
	std::cout << "After:  ";
	size_t limit = std::min<size_t>(10, _vec.size());
	for (size_t i = 0; i < limit; ++i)
		std::cout << _vec[i] << ' ';
	if (_vec.size() > 10) std::cout << "[...]";
	std::cout << '\n';
}

void PmergeMe::sortVector() {
	clock_t start = clock();
	this->recursiveSortVector(_vec, 1);
	clock_t end = clock();
	_timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; // ms
}

void PmergeMe::sortDeque() {
	clock_t start = clock();
	this->recursiveSortDeque(_deq, 1);
	clock_t end = clock();
	_timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; // ms
}

void PmergeMe::displayTimes() const {
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << _timeVec << " ms\n";
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << _timeDeq << " ms\n";
}

// ------------------------- Generic helpers (vector) -------------------------
static std::vector<int> generateJacobsthal(int n) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

static void    sortPairs(std::vector<int> &vec, size_t n_pairs) {
    size_t pairs_n_elemt = vec.size() / (n_pairs * 2);

    for (size_t i = 0; i < pairs_n_elemt; i++) {
        size_t start = i * n_pairs * 2;
        size_t mid = start + n_pairs;

        if (vec[mid + n_pairs - 1] < vec[start + n_pairs - 1])
            for (size_t j = 0; j < n_pairs; j++)
                std::swap(vec[start + j], vec[mid + j]);
    }
}

struct CompareByLastElement {
    bool operator()(const std::vector<int> &a, const std::vector<int> &b) const {
        return a.back() < b.back();
    }
};

static void insertBlock(std::vector<std::vector<int> > &main_chain, const std::vector<int> &block) {
    std::vector<std::vector<int> >::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), block, CompareByLastElement());

    main_chain.insert(pos, block);
}

static void insertJacobstal(std::vector<std::vector<int> > &main_chain, std::vector<std::vector<int> > b_blocks, std::vector<int> jacobsthal) {
    for (size_t i = 3; i < jacobsthal.size(); i++) {
        size_t  jacob_idx = jacobsthal[i] - 1;
        size_t  jacob_stop = jacobsthal[i - 1];

        if (jacob_idx >= b_blocks.size())
            jacob_idx = b_blocks.size() - 1;

    for (size_t j = jacob_idx; j >= jacob_stop; j--) {
            const std::vector<int>  block_to_insert = b_blocks[jacob_idx];
            insertBlock(main_chain, block_to_insert);
            jacob_idx--;
        }
    }
}

static void sortJacobstal(std::vector<int> &vec, size_t n_pairs, std::vector<int> &jacobsthal) {
    size_t pairs_n_elemt = vec.size() / (n_pairs * 2);

    if (n_pairs == 1)
        pairs_n_elemt = vec.size();
    std::vector<std::vector<int> > a_blocks;
    std::vector<std::vector<int> > b_blocks;

    bool finish = false;
    if (n_pairs == 1) {
        finish = true;
        for (size_t i = 0; i < vec.size(); i++) {
            if (i % 2 == 0)
                b_blocks.push_back(std::vector<int>(1, vec[i]));
            else
                a_blocks.push_back(std::vector<int>(1, vec[i]));
        }

    } else {
        for (size_t i = 0; i < pairs_n_elemt; i++) {
            size_t start = i * n_pairs * 2;
            size_t mid = start + n_pairs;

            std::vector<int>    b_block(vec.begin() + start, vec.begin() + mid);
            std::vector<int>    a_block(vec.begin() + mid, vec.begin() + mid + n_pairs);
        
            b_blocks.push_back(b_block);
            a_blocks.push_back(a_block);
        }
    }

    std::vector<int> no_part;
    if (vec.size() % (n_pairs * 2) != 0 && !finish) {
        size_t start = pairs_n_elemt * n_pairs * 2;
        no_part.insert(no_part.end(), vec.begin() + start, vec.end());
    }

    while (no_part.size() >= n_pairs) {
        std::vector<int> new_b_block(no_part.begin(), no_part.begin() + n_pairs);
        b_blocks.push_back(new_b_block);
        no_part.erase(no_part.begin(), no_part.begin() + n_pairs);
    }

    std::vector<std::vector<int> >  main_chain;

    main_chain.push_back(b_blocks[0]);

    for (size_t i = 0; i < a_blocks.size(); i++)
        main_chain.push_back(a_blocks[i]);

    insertJacobstal(main_chain, b_blocks, jacobsthal);

    if (!no_part.empty())
        main_chain.push_back(no_part);

    vec.clear();
    for (size_t i = 0; i < main_chain.size(); i++)
        vec.insert(vec.end(), main_chain[i].begin(), main_chain[i].end());
}

static void    shortThree(std::vector<int> &vec) {
    int third = vec[2];
    vec.pop_back();

    std::vector<int>::iterator pos = std::lower_bound(vec.begin(), vec.end(), third);

    vec.insert(pos, third);
}

static void recursiveSortVectorImpl(std::vector<int> &vec, size_t n_pairs) {
    size_t paris_n_elemt = vec.size() / (n_pairs * 2);

    sortPairs(vec, n_pairs);

    if (vec.size() == 3)
        shortThree(vec);

    if (paris_n_elemt <= 1)
        return;
    
    recursiveSortVectorImpl(vec, n_pairs * 2);

    std::vector<int> jacobsta = generateJacobsthal(paris_n_elemt);

    sortJacobstal(vec, n_pairs * 2, jacobsta);

    if (n_pairs == 1) {
        jacobsta = generateJacobsthal(vec.size());
    sortJacobstal(vec, n_pairs, jacobsta);
    }
}

// ------------------------- Generic helpers (deque) --------------------------
static std::deque<int> generateJacobsthalDeque(int n) {
    std::deque<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    while (jacobsthal.back() < n) {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    return jacobsthal;
}

static void sortPairs(std::deque<int> &deq, size_t n_pairs) {
    size_t pairs_n_elemt = deq.size() / (n_pairs * 2);

    for (size_t i = 0; i < pairs_n_elemt; i++) {
        size_t start = i * n_pairs * 2;
        size_t mid = start + n_pairs;

        if (deq[mid + n_pairs - 1] < deq[start + n_pairs - 1])
            for (size_t j = 0; j < n_pairs; j++)
                std::swap(deq[start + j], deq[mid + j]);
    }
}

struct CompareByLastElementDeque {
    bool operator()(const std::deque<int> &a, const std::deque<int> &b) const {
        return a.back() < b.back();
    }
};

static void insertBlock(std::deque<std::deque<int> > &main_chain, const std::deque<int> &block) {
    std::deque<std::deque<int> >::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), block, CompareByLastElementDeque());

    main_chain.insert(pos, block);
}

static void insertJacobstal(std::deque<std::deque<int> > &main_chain, std::deque<std::deque<int> > b_blocks, std::deque<int> jacobsthal) {
    for (size_t i = 3; i < jacobsthal.size(); i++) {
        size_t jacob_idx = jacobsthal[i] - 1;
        size_t jacob_stop = jacobsthal[i - 1];

        if (jacob_idx >= b_blocks.size())
            jacob_idx = b_blocks.size() - 1;

        for (size_t j = jacob_idx; j >= jacob_stop; j--) {
            const std::deque<int> block_to_insert = b_blocks[jacob_idx];
            insertBlock(main_chain, block_to_insert);
            jacob_idx--;
        }
    }
}

static void sortJacobstal(std::deque<int> &deq, size_t n_pairs, std::deque<int> &jacobsthal) {
    size_t pairs_n_elemt = deq.size() / (n_pairs * 2);

    if (n_pairs == 1)
        pairs_n_elemt = deq.size();
    std::deque<std::deque<int> > a_blocks;
    std::deque<std::deque<int> > b_blocks;

    bool finish = false;

    if (n_pairs == 1) {
        finish = true;
        for (size_t i = 0; i < deq.size(); i++) {
            if (i % 2 == 0)
                b_blocks.push_back(std::deque<int>(1, deq[i]));
            else
                a_blocks.push_back(std::deque<int>(1, deq[i]));
        }
    } else {
        for (size_t i = 0; i < pairs_n_elemt; i++) {
            size_t start = i * n_pairs * 2;
            size_t mid = start + n_pairs;

            std::deque<int> b_block(deq.begin() + start, deq.begin() + mid);
            std::deque<int> a_block(deq.begin() + mid, deq.begin() + mid + n_pairs);
        
            b_blocks.push_back(b_block);
            a_blocks.push_back(a_block);
        }
    }

    std::deque<int> no_part;
    if (deq.size() % (n_pairs * 2) != 0 && !finish) {
        size_t start = pairs_n_elemt * n_pairs * 2;
        no_part.insert(no_part.end(), deq.begin() + start, deq.end());
    }

    while (no_part.size() >= n_pairs) {
        std::deque<int> new_b_block(no_part.begin(), no_part.begin() + n_pairs);
        b_blocks.push_back(new_b_block);
        no_part.erase(no_part.begin(), no_part.begin() + n_pairs);
    }

    std::deque<std::deque<int> > main_chain;

    main_chain.push_back(b_blocks[0]);

    for (size_t i = 0; i < a_blocks.size(); i++)
        main_chain.push_back(a_blocks[i]);

    insertJacobstal(main_chain, b_blocks, jacobsthal);

    if (!no_part.empty())
        main_chain.push_back(no_part);

    deq.clear();
    for (size_t i = 0; i < main_chain.size(); i++)
        deq.insert(deq.end(), main_chain[i].begin(), main_chain[i].end());
}

static void    shortThreeDeque(std::deque<int> &deq) {
    int third = deq[2];
    deq.pop_back();

    std::deque<int>::iterator pos = std::lower_bound(deq.begin(), deq.end(), third);

    deq.insert(pos, third);
}

static void recursiveSortDequeImpl(std::deque<int> &deq, size_t n_pairs) {
    size_t pairs_n_elemt = deq.size() / (n_pairs * 2);

    sortPairs(deq, n_pairs);

    if (deq.size() == 3)
        shortThreeDeque(deq);
    
    if (pairs_n_elemt <= 1)
        return;

    recursiveSortDequeImpl(deq, n_pairs * 2);

    std::deque<int> jacobsta = generateJacobsthalDeque(pairs_n_elemt);

    sortJacobstal(deq, n_pairs * 2, jacobsta);

    if (n_pairs == 1) {
        jacobsta = generateJacobsthalDeque(deq.size());
    sortJacobstal(deq, n_pairs, jacobsta);
    }
}

void PmergeMe::recursiveSortVector(std::vector<int> &vec, size_t n_pairs) {
    recursiveSortVectorImpl(vec, n_pairs);
}

void PmergeMe::recursiveSortDeque(std::deque<int> &deq, size_t n_pairs) {
    recursiveSortDequeImpl(deq, n_pairs);
}
