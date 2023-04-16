#pragma once
#include <vector>
#include <stack>
#include <algorithm>

// Быстрая сортировка / Алгоритм Хоара
std::vector<int>& quick_sort(std::vector<int> &array_) {
    int left = 0, right = array_.size() - 1;

    std::stack<int> stk;
    stk.push(left);
    stk.push(right);
    int pivot, i, j;
    do
    {
        right = stk.top();
        stk.pop();
        left = stk.top();
        stk.pop();

        i = left;
        j = right;
        pivot = (i + j) / 2;
        int pivot_value = array_[pivot];

        do
        {
            while (array_[i] < pivot_value) ++i;
            while (array_[j] > pivot_value) --j;
            if (i <= j) {
                std::swap(array_[i], array_[j]);
                ++i;
                --j;
            }
        }
        while (i <= j);

        if (left < j)
        {
            stk.push(left);
            stk.push(j);
        }
        if (i < right)
        {
            stk.push(i);
            stk.push(right);
        }
    }
    while (!stk.empty());
    return array_;
};

/*
* Сортируем наиболее отдаленные элементы
* i                 j
* 4, 9, 7, 6, 2, 3, 8
* l        ^        r
* 
* pivot - серединный элемент
* p = (l + r) / 2;
* 
* по i - искать больший пока != p
* по j - искать меньший пока != p
* 
* i: (4 > 6) ?
* i                 j
* 4, 9, 7, 6, 2, 3, 8
* l        ^        r
* 
* i: (9 > 6) ? - элемент найден
*    i              j
* 4, 9, 7, 6, 2, 3, 8
* l        ^        r
* 
* j: (8 < 6) ?
*    i              j
* 4, 9, 7, 6, 2, 3, 8
* l        ^        r
* 
* j: (3 < 6) ? - элемент найден
*    i           j
* 4, 9, 7, 6, 2, 3, 8
* l        ^        r
* 
* std::swap(i, j)
*    i           j
* 4, 3, 7, 6, 2, 9, 8
* l        ^        r
* 
* i: (7 > 6) ? - элемент найден
*       i        j
* 4, 3, 7, 6, 2, 9, 8
* l        ^        r
* 
* j: (2 < 6) ? - элемент найден
*       i     j
* 4, 3, 7, 6, 2, 9, 8
* l        ^        r
* 
* std::swap(i, j)
*       i     j
* 4, 3, 2, 6, 7, 9, 8
* l        ^        r
* 
* i: (6 > 6) ? 
* j: (6 < 6) ?
*         ij
* 4, 3, 2, 6, 7, 9, 8
* l        ^        r
* 
* разбиваем на два отрезка (l, j) и (i, r) в СТЕК
*       j     i
* 4, 3, 2, 6, 7, 9, 8
* l        ^        r
* 
* повторяем предыдущие шаги
* i     j     i     j
* 4, 3, 2     7, 9, 8
* l  ^           ^  r
* 
*   ij           i  j
* 2, 3, 4     7, 9, 8
* l  ^           ^  r
* 
* j     i        ij
* 2, 3, 4     7, 8, 9
* l  ^           ^  r
* 
* j     i     j     i
* 2, 3, 4     7, 9, 8
* l  ^           ^  r
*/