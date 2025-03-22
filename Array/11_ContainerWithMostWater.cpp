#include<bits/stdc++.h>
using namespace std;

/*
* @Problem description : 
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1: 
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/
/*
* @Solution : 
Approach 1: Brute Force
Algorithm:
Use two nested loops to consider all pairs of lines.
For each pair of lines i and j,
calculate the area of water that can be trapped: Area=(j - i)×min(height[i],height[j])
Keep track of the maximum area during the iterations

Complexity:
Time Complexity: O(n^2) ;Two nested loops over n elements.

Space Complexity: O(1)

No extra space is used.

Dry Run:
Input: 
height=[1,8,6,2,5,4,8,3,7]

Steps:

Start with 
i=0, iterate j from 1 to 8
i=0,j=1: (1)×min(1,8)=1
i=0,j=2: (2)×min(1,6)=2

...

Update maxArea=49 for i=1,j=8.

Continue for all i until the maximum area is found.

Output: 49


*/

int maxArea(vector<int>& height) {
    int n = height.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int area = (j - i) * min(height[i], height[j]);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

/*
Approach 2: Two Pointers (Optimized)
Algorithm:
Use two pointers, one starting at the beginning  (left) and the other at the end (right)
Calculate the area using the current two lines:
    Area=(right - left)×min(height[left],height[right])
Move the pointer pointing to the smaller height inward to potentially find a larger area.
Repeat until left meets right.

Complexity:
Time Complexity: O(n) Single pass through the array using two pointers.

Space Complexity: O(1) ;Only a few variables are used.

Dry Run:
Input: height=[1,8,6,2,5,4,8,3,7]

Steps:

Start with left=0,right=8.
(8−0)×min(1,7)=8. Move left inward.left=1,right=8:
Area: (8−1)×min(8,7)=49. Move right inward.

Continue until left=right.

Output: 
49
*/
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        maxArea = max(maxArea, area);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

/*
Approach 3: Divide and Conquer (Not Preferred)
Algorithm:
Divide the array into two halves.
Compute the maximum area in the left half and the right half recursively.
Calculate the maximum area spanning across the two halves.
Return the maximum of the three areas.
*/
int maxCrossArea(vector<int>& height, int left, int mid, int right) {
    int l = mid, r = mid + 1;
    int maxArea = 0;
    while (l >= left && r <= right) {
        int area = (r - l) * min(height[l], height[r]);
        maxArea = max(maxArea, area);
        if (height[l] < height[r]) {
            l--;
        } else {
            r++;
        }
    }
    return maxArea;
}

int maxAreaUtil(vector<int>& height, int left, int right) {
    if (left == right) return 0;
    int mid = left + (right - left) / 2;
    int leftArea = maxAreaUtil(height, left, mid);
    int rightArea = maxAreaUtil(height, mid + 1, right);
    int crossArea = maxCrossArea(height, left, mid, right);
    return max(leftArea, max(rightArea, crossArea));
}

int maxArea(vector<int>& height) {
    return maxAreaUtil(height, 0, height.size() - 1);
}

/*
Complexity:
Time Complexity: 
O(nlogn) Recursively dividing the array takes logn levels, and calculating the cross-area is O(n).

Space Complexity: O(logn)

Recursive stack space.

Dry Run:
Input: height=[1,8,6,2,5,4,8,3,7]

Steps:
Divide into [1,8,6,2] and [5,4,8,3,7].

Recursively calculate areas in left and right halves.
Combine areas across halves.
Output: 
49

*/
