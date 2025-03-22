#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description : 
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
*/

/*
* @Solution : 
Approach 1: Brute Force
Algorithm:
    Traverse the array sequentially.
    Keep track of the smallest element seen so far.
    Return the smallest element at the end of the traversal.


Complexity:
Time Complexity: O(n) (Linear traversal of the array)

Space Complexity: O(1) (No extra space used)

Dry Run:
Input: nums = [4, 5, 6, 7, 0, 1, 2]

Steps:
minVal = 4

Compare minVal with nums[1] = 5. No update.
Compare minVal with nums[2] = 6. No update.
Compare minVal with nums[3] = 7. No update.
Compare minVal with nums[4] = 0. Update minVal = 0.
Compare minVal with nums[5] = 1. No update.
Compare minVal with nums[6] = 2. No update.

Output: 0
*/
int findMin(vector<int>& nums) {
    int minVal = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < minVal)
            minVal = nums[i];
    }
    return minVal;
}

/*
Approach 2: Binary Search (Optimized)
Algorithm:
    Use binary search to exploit the sorted and rotated structure of the array.
    Set left = 0 and right = nums.size() - 1.
    While left < right:
    Compute mid = left + (right - left) / 2.
    Compare nums[mid] with nums[right]:
    If nums[mid] > nums[right], the minimum is in the right half. Update left = mid + 1.
    Else, the minimum is in the left half or at mid. Update right = mid.
    Return nums[left].

Complexity:
Time Complexity: O(logn) (Binary search reduces the search space by half at each step)

Space Complexity: O(1) (No extra space used)

Dry Run:
Input: nums = [4, 5, 6, 7, 0, 1, 2]

Steps:

left = 0, right = 6
mid = 3 (nums[3] = 7)
Since nums[mid] > nums[right], set left = mid + 1 = 4.
left = 4, right = 6
mid = 5 (nums[5] = 1)
Since nums[mid] <= nums[right], set right = mid = 5.
left = 4, right = 5
mid = 4 (nums[4] = 0)
Since nums[mid] <= nums[right], set right = mid = 4.
left = 4, right = 4 (Loop ends)

Output: nums[left] = nums[4] = 0
*/
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

/*
Approach 3: Recursive Binary Search
Algorithm:
Define a recursive function that takes nums, left, and right.

Base Case:
If left == right, return nums[left].
Recursive Case:
Compute mid = left + (right - left) / 2.
Compare nums[mid] with nums[right]:
If nums[mid] > nums[right], search in the right half.
Else, search in the left half.

Complexity:
Time Complexity: O(logn) (Binary search recursion)

Space Complexity: O(logn) (Recursive call stack)

Dry Run:
Input: nums = [4, 5, 6, 7, 0, 1, 2]

Steps:
Call findMinHelper(nums, 0, 6)
mid = 3 (nums[3] = 7)
nums[mid] > nums[right], call findMinHelper(nums, 4, 6).

Call findMinHelper(nums, 4, 6)
mid = 5 (nums[5] = 1)
nums[mid] <= nums[right], call findMinHelper(nums, 4, 5).

Call findMinHelper(nums, 4, 5)
mid = 4 (nums[4] = 0)
nums[mid] <= nums[right], call findMinHelper(nums, 4, 4).
Call findMinHelper(nums, 4, 4)
Base Case: Return nums[4] = 0.

Output: 0



*/
int findMinHelper(vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right]) {
        return findMinHelper(nums, mid + 1, right);
    } else {
        return findMinHelper(nums, left, mid);
    }
}

int findMin(vector<int>& nums) {
    return findMinHelper(nums, 0, nums.size() - 1);
}
