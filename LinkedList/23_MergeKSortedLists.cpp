#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description : 
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/

/*
* @Solution : 

1. Brute Force Approach: Combine All Values and Sort
Intuition: Extract all the values from the k linked lists, sort the combined values, and recreate a single sorted linked list.

- Time Complexity: O(N log N), where N is the total number of nodes in all lists.
- Space Complexity: O(N), for storing all values in an auxiliary array.


*/
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> values;

    // Extract all values from linked lists
    for (auto list : lists) {
        while (list) {
            values.push_back(list->val);
            list = list->next;
        }
    }

    // Sort all values
    sort(values.begin(), values.end());

    // Create a new sorted linked list
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (int val : values) {
        current->next = new ListNode(val);
        current = current->next;
    }

    return dummy->next;
}

/*
2. Optimized Approach: Using a Min-Heap (Priority Queue)
Intuition: Use a min-heap (priority queue) to efficiently get the smallest value among the heads of all k linked lists. Extract the smallest node, move its pointer to the next node, and repeat.

- Time Complexity: O(N log k), where N is the total number of nodes, and k is the number of linked lists (log k for heap operations).
- Space Complexity: O(k), for storing k nodes in the heap.


*/
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    // Push the head of each linked list into the heap
    for (auto list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;

    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();
        current->next = smallest;
        current = current->next;

        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}

/*
3. Optimized Divide and Conquer Approach
Intuition: Repeatedly merge pairs of linked lists until one list remains. This reduces the problem size logarithmically.

- Time Complexity: O(N log k), where N is the total number of nodes, and k is the number of lists.
- Space Complexity: O(1), as merging is done in-place.

*/

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

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    while (lists.size() > 1) {
        vector<ListNode*> mergedLists;

        for (int i = 0; i < lists.size(); i += 2) {
            ListNode* l1 = lists[i];
            ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
            mergedLists.push_back(mergeTwoLists(l1, l2));
        }

        lists = mergedLists;
    }

    return lists[0];
}

