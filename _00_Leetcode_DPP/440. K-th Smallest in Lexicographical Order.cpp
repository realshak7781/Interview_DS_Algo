// BRUTE FORCE APPROACH : WILL GIVE YOU TLE DUE TO HIGH CONSTRAINTS

class Solution {
public:
    int findKthNumber(int n, int k) {
        // the goal is to use minHeap to get Kth smallest
        priority_queue<string,vector<string>,greater<string>> minHeap;

       for(int i=1;i<=9;i++){
            if(i<=n){
                minHeap.push(to_string(i));
            }
       }


        while(!minHeap.empty()){
            string top=minHeap.top();
            minHeap.pop();
            k--;

            int cur=stoi(top);
            if(k==0) return stoi(top);

            for(int i=0;i<=9;i++){
                int nxt=cur*10+i;

                if(nxt<=n){
                    string next=to_string(nxt);
                    minHeap.push(next);
                }
            }
        }


        return -1;
    }
};


//OPTIMISED APPROACH
class Solution {
private:
int  countNodesInChildSubtree(long cur,long  n,long next){

    int totalChilds=0;
    while(cur<=n){
        totalChilds=totalChilds + min((long)(n+1),next)-cur;
        cur*=10;
        next*=10;
    }
    return totalChilds;
}   
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        k--;


        while(k>0){
            int step=countNodesInChildSubtree(cur,n,cur+1);

            if(step<=k){
                cur++;
                k-=step;
            }
            else{
                cur*=10;
                k--;
            }
        }

        return cur;
    }
};
