#pragma once

#include <vector>

// Largest element in the array
void largest_element_in_array(int arr[], int n);

// Second largest element in the array without sorting
void second_largest_element(int arr[], int n);

// check if an array is sorted in descending order
void check_sorted(int arr[], int n);

// Removing duplicates in place from sorted
void remove_duplicates_in_place_from_sorted(int arr[], int n);

// Left rotate the array by n places
void left_array(int arr[], int len, int n);

// right rotatae the array by n places
void right_array(int arr[], int len, int n);

// Move all zeroes to the end of the array
void move_all_zeroes(int arr[], int n);

// Union of two sorted arrays
std::vector<int> unionArray(std::vector<int>& num1, std::vector<int>& num2); // Using a set
std::vector<int> unionArray2(std::vector<int>& nums1, std::vector<int>& nums2); // Without Using a set

// Intersection of two sorted arrays
std::vector<int> intersectionArray(std::vector<int>& nums1, std::vector<int>& nums2);