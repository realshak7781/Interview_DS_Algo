// Using purely mathematics 
//o(1)
const int mod=1e9+7;
using ll=long long;
class Fancy {
private:
ll getPower(ll a,ll b){
    if(b==0) return 1;
    ll half=getPower(a,b/2)%mod;

    ll res=(half*half)%mod;

    if(b&1){
        res=(res*a)%mod;
    }
    return res;
}

ll modInverse(ll b){
    return getPower(b,mod-2)%mod;
}

ll fermat(ll a,ll b){
    a=a%mod;
    b=modInverse(b)%mod;

    return (a*b)%mod;
}

vector<ll> seq;
ll addVal;
ll mulVal;
public:
    Fancy() {
        addVal=0;
        mulVal=1;
    }
    
    void append(int val) {
        ll a=(val-addVal+mod)%mod;
        ll b=mulVal;

        ll z=fermat(a,b)%mod;

        seq.push_back(z);
    }
    
    void addAll(int inc) {
        addVal=(addVal+inc)%mod;
    }
    
    void multAll(int m) {
        mulVal=(mulVal*m)%mod;
        addVal=(addVal*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()) return -1;

        ll res=seq[idx];
        res=(res*mulVal)%mod;
        res=(res+addVal)%mod;

        return res;
    }
};


// Brute force Approach:
// Time :  O(Q*n)
// space : O(n)
const int mod=1e9+7;
struct opNode{
    char opType;
    int val;
    int timeStampValue;

    opNode(char op,int v,int t){
        opType=op;
        val=v;
        timeStampValue=t;
    }
};
class Fancy {
private:
vector<opNode> opOrder;
vector<pair<int,int>> seq;
int timeStamp;
public:
    Fancy() {
        // the order in which the number comes matter 
        // the timestamps also matter
        timeStamp=0;
    }
    
    void append(int val) {
        seq.push_back({val,timeStamp});
        timeStamp++;
    }
    
    void addAll(int inc) {
        opOrder.push_back(opNode('a',inc,timeStamp));
        timeStamp++;
    }
    
    void multAll(int m) {
        opOrder.push_back(opNode('m',m,timeStamp));
        timeStamp++;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()) return -1;

        long long result=seq[idx].first;
        int timeValue=seq[idx].second;

        for(int i=0;i<opOrder.size();i++){
            auto node=opOrder[i];

            if(node.opType=='a' && node.timeStampValue>=timeValue){
                result=(result+node.val)%mod;
            }
            else if(node.opType=='m' && node.timeStampValue>=timeValue){
                result=(1LL*result*node.val)%mod;
            }
        }
        return result;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
