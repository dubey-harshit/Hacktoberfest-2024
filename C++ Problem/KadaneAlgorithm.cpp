// Kadane's Algorithm to find the maximum sum of a contiguous subarray
// LeetCode Problem 53: Maximum Subarray

/*
    Given an integer array nums, find the 
    subarray
    with the largest sum, and return its sum.
*/

/*
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include <vector>
#include <limits.h>
#include <iostream> // For demonstration purposes

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for (int val : nums) {
            currSum += val;
            maxSum = max(currSum, maxSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

