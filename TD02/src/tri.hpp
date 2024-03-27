#pragma once
#include <vector>
#include <iostream>

bool is_sorted(std::vector<int> const& vec);
//bool is_sorted(std::vector<float> const& vec);

std::vector<int> generate_random_vector(size_t const size, int const max = 100);

//EX 1
void bubble_sort(std::vector<int> & vec);
void selection_sort(std::vector<int> & vec);

//EX 2
size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> & vec);

void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> & vec);

//EX 4
int search(std::vector<int> & vec, int const val);