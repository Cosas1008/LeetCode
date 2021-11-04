/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return;
        int sz = 0;
        ListNode* ptr = head;
        stack<ListNode*> st;
        while(ptr){
            sz++;
            st.push(ptr);
            ptr = ptr->next;
        }
        ptr = head;
        for(int j = 0; j < sz/2; ++j){
            ListNode* t = st.top(); st.pop();
            t->next   = ptr->next;
            ptr->next = t;
            ptr = ptr->next->next;
        }
        ptr->next = NULL;
    }
};