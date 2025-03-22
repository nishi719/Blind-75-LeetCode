#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description : 
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

/*
* @Solution : 
1. Brute Force Approach: Use an Auxiliary Array
Intuition: Extract all elements from both lists into an auxiliary array, sort the array, and recreate the linked list from the sorted elements.

- Time Complexity: O((m + n) log(m + n)), where m and n are the lengths of the two lists (due to sorting).
- Space Complexity: O(m + n), for storing all elements in an auxiliary array.

*/
#include <vector>
#include <algorithm>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    std::vector<int> values;

    while (l1) {
        values.push_back(l1->val);
        l1 = l1->next;
    }
    while (l2) {
        values.push_back(l2->val);
        l2 = l2->next;
    }

    std::sort(values.begin(), values.end());

    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy->next;
}

/*
2. Optimized Approach: Merge Directly Using Pointers
Intuition: Use two pointers to compare nodes from both lists, selecting the smaller node at each step and linking it to the merged list.

1️⃣ Base Cases: If either list is NULL, return the other list.
2️⃣ Ensure l1 starts with the smaller value (swap if needed).
3️⃣ Use two pointers to merge the lists while keeping the order.
4️⃣ Keep moving l1 until l2 should be inserted.
5️⃣ Swap l1 and l2 to always maintain sorted order.
6️⃣ Return the head of the merged list.

- Time Complexity: O(m + n), as each node is processed once.
- Space Complexity: O(1), as no extra data structures are used.

*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = l1 ? l1 : l2;
    return dummy->next;
}

/*
Approach 2 : Recursion 🔄

1️⃣ Base Case
If l1 is NULL, return l2.
If l2 is NULL, return l1.
Why? If one list is empty, the merged list should be the other list.

2️⃣ Compare the first node of both lists
If l1->val ≤ l2->val, the next node of l1 should be the result of merging l1->next and l2.
Otherwise, l1 should be placed first, and its next node should be **the result of merging **l1 and l2->next.

3️⃣ Recursive Calls
We keep making recursive calls until we reach the base case

- Time Complexity: O(n + m) (where n and m are the lengths of the two lists).Each recursive call processes one node, so we visit all nodes once.
- Space Complexity: O(n + m) (due to recursive stack).Each function call is stored in the recursion stack, making the worst case O(n + m).


*/

class Solution {
    public:
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(list1 == nullptr){
           return list2;
       }
       if(list2 == nullptr){
           return list1;
       }
   
       if(list1->val <= list2->val){
           list1->next = mergeTwoLists(list1->next,list2);
           return list1;
       }
       else{
           list2->next = mergeTwoLists(list1 ,list2->next);
           return list2;
       }
    }
};


