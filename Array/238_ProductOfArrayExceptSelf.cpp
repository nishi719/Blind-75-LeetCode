#include<bits/stdc++.h>
using namespace std;

/*
* @Problem description : 
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

*/

/*
* @Solution : 

Intuition
Here in the problem we just have to give the product of all elements except the current 
element on which we are right now.

Approach
To solve this we can calculate the whole product of the array and handle the edge cases
seperately with the if-else statements.
Example if zero is present once we will calculate the product without zero and in array
all elements will be zero except the place where zero is.
if there are more than one zero then whole array will have zeros
and If no zero present then we will just divide the product with current element and 
return it.

Complexity
The provided solution for the problem of calculating the product of an array except self has the following time and space complexity analysis:

-Time Complexity:
The algorithm consists of a single pass through the input array nums to calculate the total product and count the number of zeros. This takes O(n) time, where n is the number of elements in the array.
In the worst-case scenario, there is another pass through the array to construct the result vector ans, which also takes O(n) time.
Therefore, the overall time complexity of the solution is O(n).

-Space Complexity:
The solution uses a constant amount of extra space for variables like product and countzero, which do not depend on the size of the input.
The output vector ans is created to store the results, which has a size of n. However, this is considered part of the output rather than extra space used by the algorithm.
Thus, the space complexity is O(1) for auxiliary space, excluding the output vector. If we include the output vector, it can be considered O(n) in terms of total space used.
In summary, the time complexity is O(n) and the space complexity is O(1) for auxiliary space, with O(n) for the output vector.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        int countzero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
            product*=nums[i];}
            else{
                countzero++;
            }
        }
        vector<int>ans;
        if(countzero==0){
            for(int i=0;i<nums.size();i++){
            ans.push_back(product/nums[i]);}

        }
        else{
            if(countzero==1){
                for(int i=0;i<nums.size();i++){

                    if(nums[i]==0){
            ans.push_back(product);}
            else{
                ans.push_back(0);
            }}

            }
            else{
                for(int i=0;i<nums.size();i++){
            ans.push_back(0);}
                
            }
        }return ans;
        
    }
};

/*
Optimized Intuition :
1.Use the result array to store prefix products in the first pass.
2.Compute suffix products on-the-fly in the second pass, directly updating the result array by multiplying the stored prefix values with the suffix product.

Algorithm :
1.Initialize:
    - result array with size ( n ), all elements set to 1.
    - A variable suffix initialized to 1.

2.First pass (Left-to-Right):
    - Compute prefix products and store them in result.

3.Second pass (Right-to-Left):
    - Update the result array by multiplying the current value with suffix.
    - Update suffix as ( \text{suffix} \times \text{nums}[i] ).

4.Return the updated result array.

Steps in Code :
1.First pass: Use the result array to store prefix products.
2.Second pass: Calculate suffix products in reverse order and multiply them directly 
with the values in result.
3.Return the result array.

Complexity Analysis :
1.Time Complexity: O(n)
    - Single traversal for prefix computation.
    - Single traversal for suffix computation.

2.Space Complexity: O(1) (excluding the result array)
    No additional arrays are used; we utilize the result array for both prefix and suffix computations.

*/

/*
Example Walkthrough :

Input: nums = [1, 2, 3, 4]

1.First Pass (Prefix):
    - Initial result = [1, 1, 1, 1]
    - Update:
        i =1 : result[1] = result[0] × nums[0] = 1 × 1 =1
        i = 2 : result[2] = result[1] × nums[1] = 1 × 2 = 2
        i = 3 : result[3] = result[2] × nums[2] = 2 × 3 = 6
    - Result after prefix computation: [1, 1, 2, 6]

2.Second Pass (Suffix):
    - Initialize suffix = 1.
    - Update:
        i = 3 : result[3] = result[3] × suffix = 6 × 1 = 6 ; suffix = suffix × nums[3]= 1 × 4 = 4
        i = 2 : result[2] = result[2] × suffix = 2 × 4 = 8 ; suffix = suffix × nums[2] = 4 × 3 = 12
        i = 1 : result[1] = result[1] × suffix = 1 × 12 = 12 ; suffix = suffix × nums[1] = 12 × 2 = 24
        i = 0 : result[0] = result[0] × suffix = 1 × 24 = 24 ; suffix = suffix × nums[0] = 24 × 1 = 24
    - Result after suffix computation: [24, 12, 8, 6]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // First pass: Calculate prefix products
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // Second pass: Calculate suffix products on the fly
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};
