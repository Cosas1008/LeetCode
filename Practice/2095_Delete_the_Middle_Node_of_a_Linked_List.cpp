// You are given the head of a linked list. Delete the middle node, 
// and return the head of the modified linked list.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return head;
        if(!head->next){
            delete head;
            return NULL;
        }
        ListNode* s, * f, * p; // slow, fast, pre
        s = head, f = head, p = head;
        
        while(f && f->next){
            if(s != head) p = s;
            s = s->next;
            f = f->next->next;
        }
        p->next = s->next;
        delete s;
        return head;
    }
};