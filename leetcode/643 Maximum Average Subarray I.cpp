// https://leetcode.com/problems/maximum-average-subarray-i/description/

// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

// Example 1:
// Input: [1,12,-5,-6,50,3], k = 4
// Output: 12.75
// Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
// Note:
// 1 <= k <= n <= 30,000.
// Elements of the given array will be in the range [-10,000, 10,000].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_average = 0;
        int summ = 0;
        for (int i = 0; i < k; i++)
            summ += nums[i];
        max_average = double(summ) / k;
        
        for (int i = k; i < nums.size(); i++) {
            summ = summ - nums[i - k] + nums[i];
            double tmp = double(summ) / k;
            if (tmp > max_average) max_average = tmp;
        }
        
        return max_average;
    }
};