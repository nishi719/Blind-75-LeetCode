/*
* @Problem Description:  Reorder List
Reordering a linked list involves arranging the list in a specific pattern where the 1st node is followed by the last node, the 2nd node is followed by the 2nd last node, and so on.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 1 -> 5 -> 2 -> 4 -> 3


*/

/*
* @ Solution :

Approach 1: Brute Force (Using Array)
Intuition:
    Convert the linked list into an array.
    Use two pointers, one starting from the beginning and the other from the end of the array, to reorder the list.
    Reconstruct the linked list from the reordered array.

Algorithm:
    Traverse the linked list and store all node references in an array
    Use two pointers (i and j) to select nodes from the start and end alternately.
    Rebuild the list using the selected nodes.
    Ensure the last node points to NULL.

-> Complexity:
    Time Complexity: O(n) for traversing the list and rebuilding.
    Space Complexity: O(n) for storing node references

-> Pseudo Code:

1. Convert the linked list into an array of nodes.
2. Initialize two pointers: left = 0, right = size - 1.
3. While left <= right:
     a. Append node at left to the new list.
     b. Append node at right to the new list.
     c. Increment left, decrement right.
4. Set the next pointer of the last node to NULL.
5. Return the reordered list.

->Dry Run Examples
Input: 1 -> 2 -> 3 -> 4 -> 5

    Convert the list to an array: [1, 2, 3, 4, 5]
    Use two pointers (i=0, j=4) to alternate nodes:
        i=0,j=4: Add 1 and 5
        i=1,j=3: Add 2 and 4 
        i=2: Add 3
    Reconstruct: 1 -> 5 -> 2 -> 4 -> 3

 */
#include <iostream>
#include <vector>
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Convert linked list to array
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Step 2: Reorder the list using two pointers
        int left = 0, right = nodes.size() - 1;
        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;
            if (left == right) break;
            nodes[right]->next = nodes[left];
            right--;
        }

        // Step 3: Set the last node's next to NULL
        nodes[left]->next = nullptr;
    }
};



/*
* @Solution : 
Approach 2: Optimized (Three Steps - Split, Reverse, Merge)
Intuition:
To reorder the list without extra space, use the following steps:
    Find the middle of the list.
    Reverse the second half of the list.
    Merge the two halves alternately.

Algorithm:
    Use the slow and fast pointer technique to find the middle of the list.
    Reverse the second half of the list in-place.
    Merge the two halves alternately by adjusting pointers.

-> Complexity:
    Time Complexity: O(n) for traversing, reversing, and merging.
    Space Complexity: O(1) as no extra space is used.

->Pseudo Code:
1. Find the middle of the list using slow and fast pointers.
2. Reverse the second half of the list.
3. Merge the first half and the reversed second half:
     a. Initialize two pointers: head1 = first half, head2 = second half.
     b. While head2 is not NULL:
          i. Store next pointers temporarily.
          ii. Merge nodes alternately.
          iii. Update pointers to the next nodes.
4. Return the reordered list.

->Dry Run Examples
Input: 1 -> 2 -> 3 -> 4 -> 5

Optimized (Split, Reverse, Merge):
    Split:
        Find the middle: 3 (list split into 1 -> 2 -> 3 and 4 -> 5)
    Reverse second half: 5 -> 4
    Merge:
        1 -> 5, 2 -> 4, 3
    Result: 1 -> 5 -> 2 -> 4 -> 3

*/
class Solution {
    public:
        void reorderList(ListNode* head) {
            if(!head || !head->next)  return ;
    
            ListNode* slow = head;
            ListNode* fast = head ;
    
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
    
            ListNode* prev = nullptr;
            ListNode* curr = slow;
    
            while(curr){
                ListNode* nextTemp = curr->next;
                curr->next= prev;
                prev = curr;
                curr = nextTemp;
            }
    
            ListNode* first = head;
            ListNode* second = prev;
    
            while(second->next){
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
    
                first->next = second;
                second->next = temp1;
    
                first= temp1;
                second = temp2;
            }
    
        }
    };