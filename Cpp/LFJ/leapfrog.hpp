#ifndef __LEAPFROG_HPP__
#define __LEAPFROG_HPP__

#include <iostream>
#include <algorithm>
#include <vector>

namespace LFJ {

template<class RandomAccessIterator, class T>
inline RandomAccessIterator leapfrogSeek(RandomAccessIterator first, RandomAccessIterator last, const T &val) {
    // 1. We first look for an interval [bound/2, bound] such that contains our values of interset.
    int bound = 1;
    RandomAccessIterator it = first + bound;
    while (it < last && it[0] < val) {
        bound *= 2;
        it = first + bound;
    }

    // 2. We now check if the found upper bound is less than the end of the array
    if ((it + bound) < last) {
        last = it + bound;
    }

    int halfBound = bound / 2;
    // 3. Now that we have found the interval of interset, let's run a binary search
    return std::lower_bound(first + halfBound, last, val);
}

template<template<class...> class C, 
        class... A,
        class T = typename C<A...>::value_type,
        class RandomAccessIterator = typename C<A...>::iterator>
void leapfrogJoin(std::vector<C<A...>> &indexes, std::vector<T> &resultSet) {
    // 1. Check if any index is empty -> Intersection empty
    for (auto &index: indexes) {
        if (index.size() == 0) {
            return;
        }
    }

    // 2. Sort indexes by their first value and do some initial interators book-keeping
    std::sort(indexes.begin(), indexes.end(), 
        [](const C<A...> &a, const C<A...> &b) { return *a.begin() < *b.begin(); }
    );

    RandomAccessIterator its[indexes.size()];
    for (int i = 0; i < indexes.size(); ++ i) {
        its[i] = indexes[i].begin();
    }

    T max = *(its[indexes.size() - 1]);
    int it = 0;

    // 3. execute the join
    T value;
    while (true) {
        value = *(its[it]);

        if (value == max) {
            // 3.1 An intersecting value has been found!
            resultSet.push_back(value);
            its[it]++;
        } else {
            // 3.2 We shall find a value greater or equal than the currnet max
            its[it] = leapfrogSeek(its[it], indexes[it].end(), max);
        }

        if (its[it] == indexes[it].end()) {
            break;
        }
        
        // 4. Store the maximum
        max = *(its[it]);
        it = (++it) % indexes.size();
    }
}

template<template<class...> class C, 
        class... A, 
        class T = typename C<A...>::value_type>
std::vector<T> leapfrogJoin(std::vector<C<A...>> &indexes) {
    std::vector<T> resultSet;

    leapfrogJoin(indexes, resultSet);

    return resultSet;
}

}

#endif
