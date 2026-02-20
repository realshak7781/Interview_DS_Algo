
// TIME : O(turnOn*2^(6))
// space : O(O(6))
class Solution {
private:
vector<int> mins={1,2,4,8,16,32};
vector<int> hrs={1,2,4,8};

void calMins(int sum,int idx,int size,vector<string>&res){
    if(sum>59)  return; 

    if(size==0){
        string time=(sum < 10) ? "0" : "";
        time=time+to_string(sum);
        res.push_back(time);
        return;
    }

    if(idx>=mins.size()){
        return ;
    }
    // use the concept of pick and not Pick

    // pick
    calMins(sum+mins[idx],idx+1,size-1,res);
    // not pick
    calMins(sum,idx+1,size,res);
}

void calHrs(int sum,int idx,int size,vector<string>&res){
    if(sum>11) return;

    if(size==0){
        res.push_back(to_string(sum));
        return;
    }

    if(idx>=hrs.size()) return;

    calHrs(sum+hrs[idx],idx+1,size-1,res);
    calHrs(sum,idx+1,size,res);
}
public:
    vector<string> readBinaryWatch(int turnedOn) {

        vector<string> res;
        for(int i=0;i<=turnedOn;i++){
            if(i>4 || (turnedOn-i)>6) continue;

            vector<string> hr;
            vector<string> min;

            calHrs(0,0,i,hr);
            calMins(0,0,turnedOn-i,min);
            for(string h:hr){
                for(string m:min){
                    string time= h + ":" + m;

                    res.push_back(time);
                }
            }
        }
        return res;
    }
};
