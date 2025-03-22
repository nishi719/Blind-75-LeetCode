#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description : 
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false

Example 1: 
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

*/

/*
* @Solution :
Approach: Brute Force Approach: Using a Hash Set
Intuition: Traverse the list and store each node in a hash set. If you encounter a node that is already in the set, a cycle exists.

- Time Complexity: O(N), where N is the number of nodes in the list.
- Space Complexity: O(N), due to the storage of nodes in the hash set.


*/
#include <unordered_set>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    std::unordered_set<ListNode*> visited;
    while (head) {
        if (visited.find(head) != visited.end()) {
            return true; // Cycle detected
        }
        visited.insert(head);
        head = head->next;
    }
    return false; // No cycle
}

/*
Approach 2: Two-Pointer Technique (Slow and Fast Pointers with Head Start)

1.This approach utilizes two pointers, slow and fast.
2.Initially, slow starts at the head, and fast starts at the second node (head->next).
3.The slow pointer moves one step at a time, while the fast pointer moves two steps.
4.If there is a cycle, the fast pointer will eventually meet the slow pointer within the cycle.
5.If fast reaches the end of the list (NULL), it means there is no cycle.

Complexity
Time complexity: O(N)
Space complexity: O(1)


*/
class Solution {
    public:
        bool hasCycle(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return false;
            }
            ListNode* slow = head;
            ListNode* fast = head->next;
            while (fast != slow) {
                if (fast->next == NULL || fast->next->next == NULL) {
                    return false;
                }
                slow = slow->next;
                fast = fast->next->next;
        }
        return true;
    }
};

/*
Approach 3: Two-Pointer Technique (Slow and Fast Pointers without Head Start)

1.This is a variation of the first approach. Both slow and fast pointers start at the head.
2.slow moves one step at a time, and fast moves two steps.
3.If there is a cycle, they will meet at some point within the cycle.
4.If fast reaches the end (NULL), the list does not contain a cycle.

Complexity
Time complexity: O(N)
Space complexity: O(1)

*/

class Solution {
    public:
        bool hasCycle(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    return true;
                }
        }
        return false;
    }
};

/*
Approach 4: Hash Map for Node Visitation Tracking

1.This approach uses a hash map (visited) to keep track of nodes that have already been visited.
2.As we traverse the list, we check if the current node has been visited before by looking it up in the hash map.
3.If a node is found in the hash map, it indicates the presence of a cycle.
4.If the traversal reaches the end of the list without finding a cycle, the list is cycle-free.

Complexity
Time complexity: O(N)
Space complexity: O(N)

*/

class Solution {
    public:
        bool hasCycle(ListNode* head) {
            if (head == NULL) {
                return false;
            }
            map<ListNode*, bool> visited;
            ListNode* temp = head;
    
            while (temp != NULL) {
                if (visited[temp] == true) {
                    return true;
                }
                visited[temp] = true;
                temp = temp->next;
            }
        return false;
    }
};