
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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