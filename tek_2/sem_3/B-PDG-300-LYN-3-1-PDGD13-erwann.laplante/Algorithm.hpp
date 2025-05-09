/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD13-erwann.laplante
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
    #define ALGORITHM_HPP_

    #include <iostream>
    #include <algorithm>

    template <class Algorithm>
    void swap(Algorithm &one, Algorithm &two) {
        Algorithm tmp = one;
        one = two;
        two = tmp;
    }

    template <class Algorithm>
    const Algorithm &min(Algorithm const &one, Algorithm const &two) {
        if (one < two)
            return one;
        else
            return two;
    }

    template <class Algorithm>
    const Algorithm &max(Algorithm const &one, Algorithm const &two) {
        if (one < two)
            return two;
        return one;
    }

    template <class Algorithm>
    const Algorithm &clamp(const Algorithm &value, Algorithm const &min, Algorithm const &max) {
        return std::clamp(value, min, max);
    }

#endif /* !ALGORITHM_HPP_ */
