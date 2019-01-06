/**
* @file random_data_hpp
* @description Random Data Implementation
* @course II. Ogretim D Grubu
* @assignment Odev-III
* @date 20.12.2018
* @author Özge Öztataroglu ozge.oztataroglu@ogr.sakarya.edu.tr
* @author Oguzhan Ince oguzhan.ince@ogr.sakarya.edu.tr
**/
#ifndef RANDOM_DATA_HPP
#define RANDOM_DATA_HPP

#include <random>
int randomGenerator(size_t min, size_t max) {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    //rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

    return static_cast<int>(dist(rng));
}

#endif // RANDOM_DATA_HPP
