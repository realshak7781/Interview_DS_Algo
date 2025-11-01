/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// Using a Hashset and Locking Mechanism to find the NewHead;
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums),end(nums));

        ListNode*prev=nullptr;
        ListNode*cur=head;

        ListNode*newHead=nullptr;
        while(cur){

            if(st.count(cur->val)){

                ListNode*forward=cur->next;
                if(prev)prev->next=forward;
                cur->next=nullptr;
                cur=forward;
            }
            else{
                prev=cur;
                if(!newHead){
                    newHead=prev;
                }
                cur=cur->next;
            }
        }

        return newHead;
    }
};
