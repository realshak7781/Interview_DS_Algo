


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
