class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // the question states that : " multiply the number on display by 2"
        // and the constraints are high : clearly they want you to implement a log base 2 solution
        

//         NOTE:
//         If during interview someone asks you why did you choose to work backward, you can give this solution


// When working forward from X to Y, at each step we face a decision problem: should we multiply or subtract? This creates a huge number of possible paths.
// But when working backwards from Y to X, there's always a clear best choice:

// If Y is odd, we must have added 1 to an even number (since multiplying by 2 always gives an even result)
// If Y is even, dividing by 2 is always better than adding 1 multiple times

// This approach eliminates any ambiguity about which operation to choose at each step, and it's guaranteed to give us the minimum number of operations


        int ops=0;
         while(target!=startValue){
            if(target%2==0 && target>startValue){
                target/=2;
            }
            else{
                target+=1;
            }
            ops++;
         }

         return ops;
    }
};


// BFS APPROACH : TLE
using ll=long long;
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        queue<pair<ll,ll>> q;
        q.push({startValue,0});

        unordered_set<ll> vis;
        while(!q.empty()){
            ll val=q.front().first;
            ll steps=q.front().second;
            q.pop();

            if(val==target) return steps;

            if(val-1>0 && !vis.count(val-1)){
                q.push({val-1,steps+1});
                vis.insert(val-1);
            }

            if((ll)2*val<=(ll)2*target && !vis.count(2*val)){
                 q.push({2*val,steps+1});
                 vis.insert(2*val);
            }
        }

        return -1;
    }
};
