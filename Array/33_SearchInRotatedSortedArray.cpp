#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description : 
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104


*/
/*
* @Solution : 
Approach 1: Brute Force

Algorithm:
    Traverse the entire array.
    Compare each element with the target.
    If found, return its index; otherwise, return -1.

Complexity:
Time Complexity: O(n) (Linear traversal of the array)

Space Complexity: O(1) (No extra space used)

Dry Run:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0

Steps:

Compare nums[0] = 4 with target = 0. No match.
Compare nums[1] = 5 with target = 0. No match.
Compare nums[2] = 6 with target = 0. No match.
Compare nums[3] = 7 with target = 0. No match.
Compare nums[4] = 0 with target = 0. Match found at index 4.

Output: 4


*/
int search(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

/*
Approach 2: Binary Search (Optimized)
Algorithm:

Use binary search to exploit the rotated sorted structure.
Set left = 0 and right = nums.size() - 1.
While left <= right:
Compute mid = left + (right - left) / 2.
If nums[mid] == target, return mid.
Determine which part of the array is sorted:
Left sorted part: If nums[left] <= nums[mid]:
If nums[left] <= target < nums[mid], move to the left half (right = mid - 1).
Else, move to the right half (left = mid + 1).
Right sorted part: If nums[mid] <= nums[right]:
If nums[mid] < target <= nums[right], move to the right half (left = mid + 1).
Else, move to the left half (right = mid - 1).
If the loop ends without finding the target, return -1


*/

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        // Check if the left part is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Otherwise, the right part must be sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

/*
Complexity:
Time Complexity: O(logn) (Binary search reduces the search space by half at each step)

Space Complexity: O(1) (No extra space used)

Dry Run:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0

Steps:

left = 0, right = 6, mid = 3 (nums[3] = 7)
nums[left] <= nums[mid], so the left part is sorted.
target = 0 is not in the range [4, 7]. Move to the right half (left = 4).
left = 4, right = 6, mid = 5 (nums[5] = 1)
nums[mid] <= nums[right], so the right part is sorted.
target = 0 is in the range [0, 1]. Move to the left half (right = 4).
left = 4, right = 4, mid = 4 (nums[4] = 0)
nums[mid] == target. Return mid = 4.

Output: 4
*/

/*
Approach 3: Recursive Binary Search
Algorithm:
Define a recursive function that takes nums, left, right, and target.

Base Case:
If left > right, return -1.
If nums[mid] == target, return mid.

Recursive Case:
Compute mid = left + (right - left) / 2.
Determine which part of the array is sorted and apply the same logic as the iterative binary search.


*/
int searchHelper(vector<int>& nums, int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (nums[left] <= nums[mid]) { // Left part is sorted
        if (nums[left] <= target && target < nums[mid]) {
            return searchHelper(nums, left, mid - 1, target);
        } else {
            return searchHelper(nums, mid + 1, right, target);
        }
    } else { // Right part is sorted
        if (nums[mid] < target && target <= nums[right]) {
            return searchHelper(nums, mid + 1, right, target);
        } else {
            return searchHelper(nums, left, mid - 1, target);
        }
    }
}

int search(vector<int>& nums, int target) {
    return searchHelper(nums, 0, nums.size() - 1, target);
}

/*
Complexity:
Time Complexity: O(logn) (Recursive binary search)

Space Complexity: O(logn) (Recursive call stack)

Dry Run:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0

Steps:

Call searchHelper(nums, 0, 6, 0)
mid = 3 (nums[3] = 7)
Left part is sorted; move to the right half (left = 4).
Call searchHelper(nums, 4, 6, 0)
mid = 5 (nums[5] = 1)
Right part is sorted; move to the left half (right = 4).
Call searchHelper(nums, 4, 4, 0)
mid = 4 (nums[4] = 0)
Base Case: Return mid = 4.

Output: 4
*/