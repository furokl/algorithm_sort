#include <iostream>
#include <random>
#include "QuickSort.h"

// TO DO
// ----------------------------------------
// бустануть быструю
// пузырьковая / выбора / пирамидальная
// + recursive версия
// + тайминг кода
// + в многопотоке (?)
// ----------------------------------------

std::vector<int> init_vector(int size, int from = 0, int to = 100)
{
    std::random_device rn;
    std::mt19937 mersenne_engine {rn()}; 
    std::uniform_int_distribution<int> dist {from, to};

    std::vector<int> array(size);

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };
    
    std::ranges::generate(array, gen);
    return array;
}

void print(const std::vector<int>& array) {
    for (auto &i : array)
        std::cout << i << ' ';
    std::cout << std::endl;
}

int main()
{
    std::vector<int> array = init_vector(100);

    print(array); 
    std::cout << '\n';

    quick_sort(array);

    print(array);
}
