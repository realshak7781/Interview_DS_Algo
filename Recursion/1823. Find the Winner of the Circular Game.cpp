// recursion : o(N) time and space
class Solution {
private:
int josephus(int n,int k){
    if(n==1){
        return 0;
    }

    int idx=josephus(n-1,k);
    idx=(idx+k)%n;

    return idx;
}    
public:
    int findTheWinner(int n, int k) {
        // the goal is : the game starts at 1 and eliminates k-1th guy from start , so our goal should be to be: the guy to remain alive till last and not be eliminated : so think in terms of the position you would choose to not get eliminated:

       int idx=josephus(n,k);

       return idx+1;
    }
};


// queue based approacch:
class Solution {
public:
    int findTheWinner(int n, int k) {
        // the goal is : the game starts at 1 and eliminates k-1th guy from start , so our goal should be to be: the guy to remain alive till last and not be eliminated : so think in terms of the position you would choose to not get eliminated:

        // queue based approacch:
        queue<int> q;
        for(int i=1;i<=n;i++)q.push(i);

        while(q.size()>1){

            for(int cnt=1;cnt<k;cnt++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};

// brute force approach :
// time: O(nk + nlogn)
// space : O(N)
class Solution {
public:
    int findTheWinner(int n, int k) {
        multiset<int> ms;

        for(int i=1;i<=n;i++){
            ms.insert(i);
        }
        // ms keeps the element in sorted order;
        auto it=ms.begin();
        while(ms.size()>1){

            for(int i=1;i<k;i++){
                ++it;
                if(it==ms.end()){
                    it=ms.begin();
                }
            }
            auto nxt=next(it);
            if(nxt==ms.end()){
                nxt=ms.begin();
            }
            ms.erase(it);
            it=nxt;
        }

        return *it;
    }
};
