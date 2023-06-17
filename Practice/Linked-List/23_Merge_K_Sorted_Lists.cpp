/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
*/
class Solution {
public:
    // Priority_queue
    struct comp {
        bool operator()(const ListNode* lh, const ListNode* rh){
            return lh->val > rh->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto list : lists){
            if(list) pq.push(list);
        }
        if(pq.empty()) return NULL;
        ListNode* ret = pq.top(); pq.pop();
        if(ret->next) pq.push(ret->next);
        
        ListNode* tail = ret;
        while(pq.size()){
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if(tail->next) pq.push(tail->next);
        }
        return ret;
    }
};