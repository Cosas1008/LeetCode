// Given the head of a linked list, return the list after sorting it in ascending order.
// Merge Sort O(nlogn) in all the cases, Qsort worst-case is O(n^2)
class Solution {
public:
    // Top-Down Merge Sort, Time Complexity O(nlogn)
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }
    ListNode* getMid(ListNode* head){
        ListNode* midptr = nullptr;
        while(head && head->next){
            midptr = (!midptr)? head : midptr->next;
            head = head->next->next;
        }
        ListNode* mid = midptr->next;
        midptr->next = nullptr;
        return mid;
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* ptr = &dummy;
        while(left && right){
            if(left->val < right->val){
                ptr->next = left;
                left = left->next;
            }else{
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        if(left) ptr->next = left;
        else ptr->next = right;
        return dummy.next;
    }
    // Bottom-Up ??
};