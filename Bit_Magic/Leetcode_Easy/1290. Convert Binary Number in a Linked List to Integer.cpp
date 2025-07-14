// O(N)  time : N = no of  nodes in linked List;
// O(1) space : bit magic
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;

        int num=0;
        while(head!=nullptr){
            int bit=head->val;
            num=(num<<1)|bit;
            head=head->next;
        }

        return num;
    }
};

// using O(N) extra space :
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(!head) return 0;

        stack<int> st;
        ListNode*temp=head;

        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }

        int num=0;
        int pos=0;

        while(!st.empty()){
            int bit=st.top();st.pop();
            if(bit){
                num|=(1<<pos);
            }
            pos++;
        }
        return num;
    }
};
