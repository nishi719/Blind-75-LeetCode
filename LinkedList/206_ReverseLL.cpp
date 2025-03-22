#include<bits/stdc++.h>
using namespace std;
/*
* @Problem Description : 
Given the head of a singly linked list, reverse the list, and return the reversed list.
* @Input Description :
The input is a linked list of integers.
* @Output Description :
The output is the head of the reversed linked list.
* @Constraints :
The list is singly ended.
* @Example :
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
* @Time Complexity : O(n)
* @Space Complexity : O(1)
*/

/*
* @Solution : 
Approach 1 : Brute force Approach

Intuition : 
1.Traverse the linked list and store all the nodes in a stack.
2.Pop nodes from the stack and rebuild the linked list in reverse order.

- Time Complexity:O(N): One traversal to push nodes onto the stack, and another traversal to rebuild the list.
- Space Complexity:O(N): Additional space for the stack.


*/

struct ListNode{
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}

};

ListNode* ReverseLL(ListNode* head){
    if(!head) return nullptr;

    stack<ListNode*> st;
    ListNode* temp = head;

    while(temp){
        st.push(temp);
        temp = temp->next;
    }
  
    ListNode* newHead = st.top();
    st.pop();
    temp = newHead;

    while(!st.empty()){
        temp->next = st.top();
        st.pop();
        temp = temp->next;

    }
    temp->next =nullptr;
    return newHead;

}

/*
* @Solution : Iterative Approach

1.Reverse the pointers of the list in-place.
2.Use three pointers:
    - prev: Tracks the previous node.
    - curr: Tracks the current node.
    - next: Tracks the next node to avoid losing reference.

- Time Complexity:  O(N): Single traversal of the linked list.
- Space Complexity: O(1): No additional data structures used.

*/
ListNode* ReverseLL(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while(curr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
    }
    return prev;
}

/*
* @Solution : Recursively Approach

1.Recursively reverse the rest of the list, starting from the second node.
2.Adjust pointers at the current node.

-   Time complexity : O(N); recursion traverses list once
-   Space complexity : O(N); recursive call stack
*/

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* newHead = reverseList(head->next);
    head->next->next = head;  // Reverse the pointer
    head->next = nullptr;     // Set current node's next to null

    return newHead;
}
