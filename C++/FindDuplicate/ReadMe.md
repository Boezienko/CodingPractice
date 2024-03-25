# Find Duplicate

## Problem Statement

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears once or twice, return an array of all the integers that appear twice.

The algorithm must run in O(n) time.

## Solution

The solution involves creating a frequency vector to keep track of the occurrence of each number in the input vector. The frequency vector is dynamically resized to accommodate larger indices. If a number appears more than once in the input vector, it is returned as the duplicate.