#include<bits/stdc++.h>
using namespace std;

/*
* @Problem Description :
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.


*/

/*
* @Solution : 
Approach 1: Brute Force Recursion (O(n^2))
Intuition
The brute force approach involves recursively exploring all possible subarrays and 
calculating their product.

Approach
1.We begin by initiating a recursive function dfs, which takes the current index i and the array nums as parameters.
2.At each step of the recursion, we calculate the maximum product subarray ending at the current index.
3.We handle the base case where i reaches or exceeds the last index of nums. In this case, we return the value at that index, which represents a single-element subarray.
4.Otherwise, we recursively call dfs for the next index and store its result in res.
5.Within the recursive function, we iterate through all possible subarrays starting from the current index i to the end of the array nums.
6.For each subarray, we calculate its product and update the maximum product if necessary.
7.Finally, we return the maximum product found.

Complexity
    - Time complexity: O(n^2), where n is the length of the input array. This is due to the recursive exploration of all possible subarrays.
    - Space complexity: O(1) (excluding the space required for the input array).

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return dfs(0, nums);
    }

    int dfs(int i, vector<int>& nums) {
        if (i >= nums.size() - 1) return nums[nums.size() - 1];
        
        int res = dfs(i + 1, nums);
        int maxVal = INT_MIN;
        int product = 1;
        
        for (int j = i; j < nums.size(); j++) {
            product *= nums[j];
            maxVal = max(maxVal, product);
        }
        
        return max(res, maxVal);
    }
};

/*
Approach 2: Optimized Recursion with Max and Min Variables (O(n))
Intuition
In this approach, we optimize the recursive strategy by keeping track of both the maximum and minimum product subarrays encountered so far.

Approach
1.We implement a recursive function that explores each subarray starting from index 0.
2.At each step, we update the max and min variables to represent the maximum and minimum product subarrays ending at the current index.
3.We return the maximum product encountered during the recursion.

Complexity
    - Time complexity: O(n), where n is the length of the input array. This is because we only need to traverse the array once.
    - Space complexity: O(1) (excluding the space required for the input array).

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxVal = 1, minVal = 1;
        
        if (nums[nums.size() - 1] != 0) {
            maxVal = nums[nums.size() - 1];
            minVal = maxVal;
        }
        
        int res = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                minVal = 1;
                maxVal = 1;
                res = res > 0 ? res : 0;
                continue;
            }
            
            int temp = maxVal;
            maxVal = max(maxVal * nums[i], minVal * nums[i]);
            maxVal = max(maxVal, nums[i]);
            minVal = min(temp * nums[i], minVal * nums[i]);
            minVal = min(minVal, nums[i]);
            
            res = max(res, maxVal);
        }
        
        return res;
    }
};

/*
Approach 3: Tabulation (Bottom-up Dynamic Programming) (O(n))
Intuition
In this approach, we utilize tabulation to build the solution iteratively from the bottom up. We maintain an array to store the maximum product subarray ending at each index.

Approach
1.We initialize an array to store the maximum product subarray ending at each index.
2.We handle the base case by initializing the last element of the array based on whether it is zero or not.
3.We iterate backward through the array, updating the maximum product subarray ending at each index.
4.We return the maximum product subarray for the entire array.

Complexity
    - Time complexity: O(n), where n is the length of the input array. This is because we only need to traverse the array once.
    - Space complexity: O(n), as we require an additional array of size n to store the maximum product subarray ending at each index.


*/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int maxProd = 1, minProd = 1;
        std::vector<int> dp(nums.size());
        
        if (nums[nums.size() - 1] == 0) {
            dp[nums.size() - 1] = 0;
        } else {
            dp[nums.size() - 1] = nums[nums.size() - 1];
            maxProd = nums[nums.size() - 1];
            minProd = maxProd;
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            int res = dp[i + 1];
            
            if (nums[i] == 0) {
                minProd = 1;
                maxProd = 1;
                dp[i] = res > 0 ? res : 0;
                continue;
            }   
            
            int temp = maxProd;
            maxProd = std::max({maxProd * nums[i], minProd * nums[i], nums[i]});
            minProd = std::min({temp * nums[i], minProd * nums[i], nums[i]});
            
            res = std::max(res, maxProd);
            dp[i] = res;
        }
        
        return dp[0];
    }
};

/*
Approach 3.1: Optimized Tabulation with Constant Memory (Bottom-up Dynamic Programming) (O(n))
Intuition
In this approach, we optimize memory usage by eliminating the need for an additional array to store the maximum product subarray ending at each index. Instead, we only store the maximum product subarray ending at the current index.

Approach
1.We initialize variables to store the maximum and minimum product subarrays ending at the current index.
2.We handle the base case by initializing these variables based on whether the last element of the array is zero or not.
3.We iterate backward through the array, updating the maximum and minimum product subarrays ending at each index.
4.We return the maximum product subarray encountered during the iteration.

Complexity
    - Time complexity: O(n), where n is the length of the input array. This is because we only need to traverse the array once.
    - Space complexity: O(1), as we only require a constant amount of extra space for variables.

*/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int maxProd = 1, minProd = 1;
        
        if (nums[nums.size() - 1] != 0) {
            maxProd = nums[nums.size() - 1];
            minProd = maxProd;
        }
        
        int res = nums[nums.size() - 1];
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == 0) {
                minProd = 1;
                maxProd = 1;
                res = res > 0 ? res : 0;
                continue;
            }         
            
            int temp = maxProd;
            maxProd = std::max({maxProd * nums[i], minProd * nums[i], nums[i]});
            minProd = std::min({temp * nums[i], minProd * nums[i], nums[i]});
            
            res = std::max(res, maxProd);
        }     
        return res;
    }
};

/*
Approach 4 : Prefix and Suffix 

1.Initialize Variables:
    - pre and suff to 1 for storing the prefix and suffix products, respectively.
    - ans to INT_MIN to track the maximum product found.

2.Traverse the Array:
    - Compute the prefix product (pre) from left to right.
    - Compute the suffix product (suff) from right to left.
    - Update ans with the maximum of ans, pre, and suff.

3.Reset Products When Zero is Encountered:
    - If pre or suff becomes 0, reset it to 1 because the product of any subarray containing zero is 0, and we need to start a new subarray.

4.Return Result:
    - The variable ans will hold the maximum product of any contiguous subarray

Complexity
    - Time complexity: O(n)
    - Space complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1,suffix =1;
        int ans =INT_MIN;

        for(int i=0;i<n ;i++){
            if(prefix == 0) prefix =1;
            if (suffix == 0) suffix =1;

            prefix = prefix*nums[i];
            suffix = suffix*nums[n-i-1];
            ans = max(ans , max(prefix ,suffix));
        }
        return ans;
    }
};