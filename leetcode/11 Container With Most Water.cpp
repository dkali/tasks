// https://leetcode.com/problems/container-with-most-water/description/

// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        long left = 0, right = height.size() - 1;
        
        while (left < right){
            long d = (right - left) * min(height[left], height[right]);
            max_area = fmax(max_area, d);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};