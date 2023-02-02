#ifndef TEMPLATE_CPLUS_H
#define TEMPLATE_CPLUS_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

///Prints parameter without ending the line
template<typename Template>
inline void print(Template t) {
    std::cout << t;
}

///Prints whole vector
template<typename Template>
inline void print(const std::vector<Template> &vector) {
    std::string string;
    string.reserve(vector.size());
    for (Template i: vector) string += std::to_string(i) + " ";
    std::cout << string << "\n";
}

///Prints parameter and ends the line
template<typename Template>
inline void println(Template t) {
    std::cout << "\n" << t;
}

///Return a random int number between min and max
inline int random(int min, int max) {
    static std::mt19937 randGen(time(nullptr));
    return std::uniform_int_distribution<>(min, max)(randGen);
}

///Map n in a new interval
inline float map(float n, float min1, float max1, float min2, float max2) {
    return min2 + (max2 - min2) * ((n - min1) / (max1 - min1));
}

///True if (x, y) is in the box formed by (upperLeftX, upperLeftY) and (downRightX, downRightY)
inline bool inBound(int x, int y, int upperLeftX, int upperLeftY, int downRightX, int downRightY) {
    return x >= upperLeftX && x < downRightX && y >= upperLeftY && y < downRightY;
}

inline float dist(float x1, float y1, float x2, float y2) {
    float result = 0;
    float arg = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    try {
        if (arg < 0) {
            throw std::invalid_argument("sqrt received negative argument");
        }
        result = sqrtf(arg);
    } catch (std::exception &e) {
        println(e.what());
    }
    return result;
}

template<typename Template>
inline void constraint(Template &t, int lower, int upper) {
    if (t < lower) t = lower;
    if (t > upper) t = upper;
}

#endif
