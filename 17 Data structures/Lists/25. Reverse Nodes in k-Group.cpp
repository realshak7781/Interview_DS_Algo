

// time : O(n/k) * [O(n)+ O(n-r*k)]
// space : O(n/k)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode*temp=head;

        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }

        if(cnt<k || !head){
            return head;
        }

        // this is the node that needs to be sent to recursion
        ListNode*cur=head;
        ListNode*prev=nullptr;

        int K=k;
        // reverse k nodes 
        while(K){
            ListNode*forw=cur->next;
            cur->next=prev;
            prev=cur;
            cur=forw;
            K--;
        }

        head->next=reverseKGroup(cur,k);

        return prev;
    }
};
