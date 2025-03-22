#include<bits/stdc++.h>
using namespace std;

/*
* @Problem description : 
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

/*
Approach 1: Brute Force
Algorithm:
Iterate through all combinations of triplets in the array using three nested loops.

Check if the sum of the current triplet equals 
0.

Use a data structure (like a set) to store the triplets to ensure uniqueness.
Convert the set back to a list before returning the result

Complexity:
Time Complexity: O(n^3⋅logn)
O(n^3)for three nested loops.
Sorting each triplet for uniqueness takes O(logn).

Space Complexity: O(m), where 𝑚 is the number of unique triplets stored.

Dry Run:
Input: nums = [-1, 0, 1, 2, -1, -4]

Steps:
Generate all combinations:
Triplet: [-1, 0, 1] → Sum = 0 → Add [-1, 0, 1] to the result.
Triplet: [0, 1, -1] → Sum = 0 → Add [-1, 0, 1] (duplicate, ignored).
And so on.
Result: [[-1, 0, 1], [-1, -1, 2]].

Output: [[-1, 0, 1], [-1, -1, 2]]
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end()); // Ensure unique triplets
                    result.insert(triplet);
                }
            }
        }
    }
    return vector<vector<int>>(result.begin(), result.end());
}

/*

*/
/*
* @Solution :
Approach 2: Sorting + Two Pointers (Optimized)

Intuition
The problem asks us to find all unique triplets in an array that sum to zero. A brute-force approach would involve checking every combination of three numbers, but that would be inefficient (O(n^3)time complexity). A better approach involves sorting the array and using a two-pointer technique to efficiently find pairs that sum to a specific value (in this case, the negative of a fixed number).

Approach
Sort the array: Sorting helps us avoid duplicates and simplifies the logic for finding pairs that sum to a specific value.
Fix one element: Iterate over the array and for each element (let's call it nums[i]), treat it as the first element of the triplet.
Two-pointer technique: For each fixed element nums[i], use two pointers, j and k, to find pairs such that the sum of nums[i], nums[j], and nums[k] equals zero.
If the sum is greater than zero, move the k pointer left to reduce the sum.
If the sum is less than zero, move the j pointer right to increase the sum.
If the sum is zero, record the triplet and move both pointers to avoid duplicates.
Skip duplicates: To avoid considering duplicate triplets, skip duplicate values for the fixed element (nums[i]) and for the two-pointer elements (nums[j] and nums[k]).

Steps
Sort the array.
Iterate through the array, fixing one element at a time.
Use the two-pointer technique to find pairs that sum to the negation of the fixed element.
Skip duplicate elements to ensure unique triplets are returned.
Return the list of triplets

Complexity
Time complexity:O(n^2). The sorting step takes O(nlogn), and for each fixed element, we use the two-pointer technique which runs in linear time, so the total time complexity is O(n)
Space complexity:O(1) if we ignore the space used by the result. We only use a few extra variables (such as pointers), so the space complexity is constant. The result list will take O(k) space, where k is the number of unique triplets.

*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}
/*
Complexity:
Time Complexity: 𝑂(𝑛^2)
Sorting the array takes O(nlogn).
The two-pointer approach for each element takes O(n).

Space Complexity: O(1) (No extra space beyond the output).

Dry Run:
Input: nums = [-1, 0, 1, 2, -1, -4]

Steps:
Sort: nums = [-4, -1, -1, 0, 1, 2].

First Iteration (i = 0):
Fix nums[i] = -4.
Two-pointer search (left = 1, right = 5):
nums[1] + nums[5] = -1 + 2 = 1. Move right to 4.
nums[1] + nums[4] = -1 + 1 = 0. No triplet found.

Second Iteration (i = 1):
Fix nums[i] = -1.
Two-pointer search (left = 2, right = 5):
nums[2] + nums[5] = -1 + 2 = 0. Add [-1, -1, 2].
Skip duplicates, adjust left and right.
nums[3] + nums[4] = 0 + 1 = 1. No triplet found.
And so on.

Output: [[-1, -1, 2], [-1, 0, 1]].


*/
/*
* @Solution : 
Approach 3: Hashing (Less Preferred)
Algorithm:
Use a hash map to store seen elements and avoid duplicates.
Fix one element and find two others such that their sum equals 
0
0 using the hash map.
Ensure triplets are unique by sorting them before adding to the result.

Complexity:
Time Complexity: O(n^2.logn) (Hashing is O(1), but sorting triplets takes O(logn)).

Space Complexity: O(n) for the hash set.

Dry Run:
Input: nums = [-1, 0, 1, 2, -1, -4]

Steps:
Fix nums[i] = -1, use a hash set to find 0 - nums[j].
For nums[j] = 0, complement is 1. Add [-1, 0, 1].
Repeat for other indices.

Output: [[-1, -1, 2], [-1, 0, 1]].
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        unordered_set<int> seen;
        for (int j = i + 1; j < n; j++) {
            int complement = -nums[i] - nums[j];
            if (seen.count(complement)) {
                vector<int> triplet = {nums[i], nums[j], complement};
                sort(triplet.begin(), triplet.end());
                result.insert(triplet);
            }
            seen.insert(nums[j]);
        }
    }
    return vector<vector<int>>(result.begin(), result.end());
}
