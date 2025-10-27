// A little Optimized
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();

        vector<int> deviceCnt;

        for(int i=0;i<m;i++){
            string s=bank[i];
            int count=0;

            for(int j=0;j<n;j++){
                if(s[j]=='1') count++;
            }
            if(count>0){
                deviceCnt.push_back(count);
            }
        }

        if(deviceCnt.size()==0) return 0;

        // 1... Any curRow needs the first non zero row, it is not concerned with zeroes in b/w
        // 2....and it(curRow) wont check after it has found the first non zero val
        int totalCount=0;
        for(int i=0;i<deviceCnt.size()-1;i++){
            totalCount+=(deviceCnt[i]*deviceCnt[i+1]);
        }

        return totalCount;
    }
};

// Brute force : O(n^2) +  O(n) space
class Solution {
private:
bool isEmpty(string s){
    for(char c:s){
        if(c=='1') return false;
    }
    return true;
}
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].size();

        vector<int> deviceCnt(m,0);

        for(int i=0;i<m;i++){
            string s=bank[i];
            int count=0;

            for(int j=0;j<n;j++){
                if(s[j]=='1') count++;
            }
            deviceCnt[i]=count;
        }

        int count=0;
        for(int i=0;i<m;i++){
            if(isEmpty(bank[i])) continue;

            for(int j=i+1;j<m;j++){
                if(isEmpty(bank[j])) continue;

                bool hasLaser=true;

                for(int k=i+1;k<j;k++){
                    if(!isEmpty(bank[k])){
                        hasLaser=false;
                        break;
                    }
                }

                if(hasLaser){
                    count+=(deviceCnt[i]*deviceCnt[j]);
                }
            }
        }

        return count;
    }
};
