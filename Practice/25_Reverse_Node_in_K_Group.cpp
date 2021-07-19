/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0; i < k; i++){
            if(!cur)
                return head;
            cur = cur->next;
        }
        ListNode* newhead = reverseList(head, cur);
        head->next = reverseKGroup(cur, k);
        return newhead;
    }
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = tail;
        while(head != tail){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};

// note: reverse linked-list
ListNode* reverseList(ListNode* head) {
    ListNode* nxt = nullptr;
    while(head){
        ListNode* tmp = head->next;
        head->next = nxt;
        nxt = head;
        head = tmp;
    }
    return nxt;
}