/*
Given a singly linked list, return a random node's value from the linked list. 
Each node must have the same probability of being chosen.
*/
class Solution {
public:
    ListNode* _head;
    int       cnt;
    Solution(ListNode* head) {
        _head = head;
        ListNode* ptr = head;
        cnt = 0;
        while(ptr){
            cnt++;
            ptr = ptr->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand() % cnt;
        ListNode* ptr = _head;
        while(idx){
            ptr = ptr->next;
            idx--;
        }
        return ptr->value;
    }
};