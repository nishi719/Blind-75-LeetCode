#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description: 
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104


*/

/*
* @Solution : 
Intuition :
We need to find the maximum profit from buying and selling on two different days. 
To maximize profit, we want to buy at the lowest price seen so far and sell at the 
highest possible price after buying. This can be done by tracking the minimum price as
 we traverse the list and calculating the potential profit each day by selling at the 
 current price.

Approach :
1.Initialize two variables:
    - min_price to keep track of the lowest price encountered so far.
    - max_profit to keep track of the maximum profit achieved so far.
2.Traverse through the prices list:
    - Update min_price if the current price is lower.
    - Calculate profit by subtracting min_price from the current price.
    - Update max_profit if the calculated profit is greater.
3.Return max_profit as the result.

Solving Steps :
1.Set min_price to a high value (or maximum integer value).
2.Initialize max_profit to 0.
3.Loop through each price in prices:
    - Update min_price if the current price is lower than min_price.
    - Calculate the profit as price - min_price.
    - Update max_profit if the calculated profit is greater than max_profit.
4.After the loop, max_profit contains the maximum possible profit. Return max_profit.

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};
/*
Algorithm:

1.Initialize minPrice with the first element of the prices array.
2.Initialize profit as 0.
3.Iterate through the array from index 1 to n-1:
4.If the current price is lower than minPrice, update minPrice.
5.Calculate the potential profit by subtracting minPrice from the current price.
6.Update profit if this value is greater than the previous maximum profit.
7.Return profit as the final answer.

*/


//-------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int min = prices[0];
            int profit = 0;
            for(int i = 0;i<prices.size();i++){
                if(prices[i]<min){
                    min = prices[i];
                }
                profit = max(profit,prices[i]-min);
            }
            return profit;
    }
};

//---------------------------------------------------
/*
Approach 2: Stack 

Intuition
The problem requires us to maximize profit by choosing the best day to buy and sell a 
stock. My first thought was to use a stack to track potential buying prices and compare 
them against future selling prices.

Approach
We iterate through the prices array while maintaining a stack to store potential buying prices.
If the stack is empty or the current price is lower than the top of the stack, we push it onto the stack.
Otherwise, we check if selling at the current price yields a better profit and update maxProfit.
Finally, we return the maximum profit found.

Complexity
Time complexity: O(n)


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>s;
        int maxProfit=0;
        int n=prices.size();
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(s.empty()|| s.top()>=prices[i]){
                s.push(prices[i]);
            }
            else{
                maxProfit=max(maxProfit,prices[i]-s.top());
            }
        }
        return maxProfit;
    }
};

/*
Approach 3 :Kadane's Algorithm

Intuition
The problem aims to find the maximum profit that can be obtained by buying and selling 
a stock. The given solution seems to follow a simple approach of iterating through the 
prices, keeping track of the minimum buying price, and updating the profit whenever a 
higher selling price is encountered.

Approach
1.Initialize variables buy with the first element of the prices array and profit as 0.
2.Iterate through the prices starting from the second element.
3.Update the buy variable if the current price is lower than the current buying price.
4.Update the profit if the difference between the current price and the buying price is greater than the current profit.
5.Return the final profit.

Kadane's Algorithm
Kadane's Algorithm is a dynamic programming technique used to find the maximum subarray 
sum in an array of numbers. The algorithm maintains two variables: 
max_current represents the maximum sum ending at the current position, 
and max_global represents the maximum subarray sum encountered so far. 
At each iteration, it updates max_current to include the current element or start a 
new subarray if the current element is larger than the accumulated sum. The max_global 
is updated if max_current surpasses its value.

Relating with the Approach
In the provided approach for finding the maximum profit in stock prices, the algorithm 
can be seen as a variation of Kadane's Algorithm. Instead of finding the maximum 
subarray sum directly, it focuses on finding the maximum positive difference between 
consecutive elements (prices) in the array.

Here's how the approach relates to Kadane's Algorithm:

1.Initialization:
    - In Kadane's Algorithm, max_current and max_global are initialized to the first element of the array.
    - In the stock profit approach, buy is initialized with the first element of the prices array, and profit is initialized to 0.

2.Iteration:
    - Kadane's Algorithm iterates through the array, updating max_current based on the current element's value and deciding whether to start a new subarray.
    - The stock profit approach iterates through the prices array, updating buy when a lower price is encountered and treating the difference between the current price and buy as a potential profit.

3.Comparison and Update:
    - Kadane's Algorithm compares and updates max_current and max_global at each iteration.
    - The stock profit approach compares and updates profit whenever a positive difference between the current price and buy exceeds the current profit.

Complexity
    Time complexity: O(n), where n is the length of the prices array. The algorithm iterates through the array once.
    Space complexity: O(1), as only a constant amount of extra space is used.

*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};

