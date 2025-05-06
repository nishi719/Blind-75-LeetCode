/*
* @Problem Description : 
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

/*
* @Solution : 
Approach 1: Brute Force Using Two Passes
Algorithm:
Traverse the entire linked list to calculate its length (L).
Determine the position of the node to be removed from the beginning of the list (L−n+1).
Traverse the list again to find the node at position L−n+1 and adjust the pointers to skip it.

Pseudo Code:

Function removeNthFromEnd(head, n):
    length = 0
    temp = head
    // Step 1: Calculate the length of the linked list
    While temp is not NULL:
        length += 1
        temp = temp.next
    
    // Step 2: Find the position to remove
    position = length - n + 1
    
    // Edge case: Removing the head node
    If position == 1:
        Return head.next
    
    // Step 3: Traverse to the node just before the position to remove
    temp = head
    For i = 1 to position - 1:
        temp = temp.next
    
    // Step 4: Adjust pointers to skip the nth node
    temp.next = temp.next.next
    
    Return head

-> Complexity:
    Time Complexity: O(L) (Two traversals of the list)
    Space Complexity: O(1) (No additional space used)

Dry Run Example:
Input: head=[1,2,3,4,5],n=2

    Step 1: Calculate length = 5
    Step 2: Position to remove = 5−2+1=4.
    Step 3: Traverse to node at position 3(3).
    Step 4: Adjust pointers: Node 3→5.

    Output: head=[1,2,3,5].

*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;

        // Step 1: Calculate the length of the linked list
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: Find the position to remove
        int position = length - n + 1;

        // Edge case: Removing the head node
        if (position == 1) {
            return head->next;
        }

        // Step 3: Traverse to the node just before the position to remove
        temp = head;
        for (int i = 1; i < position - 1; ++i) {
            temp = temp->next;
        }

        // Step 4: Adjust pointers to skip the nth node
        temp->next = temp->next->next;

        return head;
    }
};

/* 
Approach 2: Optimized Single Pass Using Two Pointers
Intuition:
The idea is to use two pointers:

Keep one pointer n nodes ahead of the other.
Once the first pointer reaches the end of the list, the second pointer will be just before the node to be removed.

Algorithm:
Create a dummy node pointing to the head to handle edge cases like removing the head node.
Initialize two pointers (fast and slow) at the dummy node.Move the fast pointer n+1 steps ahead to maintain a gap of n nodes between fast and slow.

Move both pointers one step at a time until fast reaches the end.
Adjust the slow's next pointer to skip the nth node.


Pseudo Code:
Function removeNthFromEnd(head, n):
    dummy = New Node(-1)
    dummy.next = head
    fast = dummy
    slow = dummy

    // Step 1: Move fast pointer n + 1 steps ahead
    For i = 1 to n + 1:
        fast = fast.next
    
    // Step 2: Move both pointers until fast reaches the end
    While fast is not NULL:
        fast = fast.next
        slow = slow.next
    
    // Step 3: Skip the nth node
    slow.next = slow.next.next

    Return dummy.next

-> Complexity:
    Time Complexity:O(L) (Single traversal of the list)
    Space Complexity: O(1) (No additional space used)

-> Dry Run Example:
Input: 

    head=[1,2,3,4,5],n=2
    Step 1: Dummy list: [−1,1,2,3,4,5]. Initialize fast,slow=−1.
    Step 2: Move fast n+1=3 steps: fast=3.

    Step 3: Move both pointers:
        fast=4,slow=1
        fast=5,slow=2 
        fast=NULL,slow=3.

    Step 4: Adjust pointers: Node 3→5.
    Output: head=[1,2,3,5].



*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 1: Move fast pointer n + 1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Step 2: Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Skip the nth node
        slow->next = slow->next->next;

        return dummy->next;
    }
};

// --------------------------------------
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* result = new ListNode(0,head);
            ListNode* dummy = result;
    
            for(int i = 0; i<n ;i++){
                head = head->next;
            }
    
            while(head != nullptr){
                head = head->next;
                dummy = dummy->next;
            }
            dummy->next = dummy->next->next;
    
            return result->next;
        }
    };

