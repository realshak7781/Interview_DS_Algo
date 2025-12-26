// time : O(n) : Using Prefix Sums
// space : O(n)
// approach 2:
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int resHr=INT_MAX;
        int minPenalty=INT_MAX;

        vector<int> yPref(n);
        vector<int> nPref(n);
        yPref[0]=customers[0]=='Y' ? 1 : 0;
        nPref[0]=customers[0]=='N' ? 1 : 0;

        for(int i=1;i<n;i++){
            yPref[i]=yPref[i-1] + (customers[i]=='Y' ? 1 : 0);
            nPref[i]=nPref[i-1] + (customers[i]=='N' ? 1 : 0);
        }

        for(int hr=0;hr<=n;hr++){
            int curPenalty=0;

            if(hr<n && customers[hr]=='Y') curPenalty+=1;

            curPenalty += (hr > 0 ? nPref[hr-1] : 0);
            if(hr<n)curPenalty += yPref[n-1] - yPref[hr];

            if(curPenalty<minPenalty){
                minPenalty=curPenalty;
                resHr=hr;
            }
            else if(curPenalty==minPenalty){
                if(hr<resHr){
                    resHr=hr;
                }
            }
        }

        return resHr;
    }
};


// Approach 1: Using Brute Force
// Time : O(n^2)
// space : O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int resHr=n;
        int minPenalty=INT_MAX;


        for(int hr=0;hr<=n;hr++){
            int curPenalty=0;

            if(hr<n && customers[hr]=='Y') curPenalty+=1;

            int j=hr-1;
            while(j>=0){
                if(customers[j]=='N') curPenalty+=1;
                j--;
            }

            int k=hr+1;
            while(k<n){
                if(customers[k]=='Y') curPenalty+=1;
                k++;
            }

            if(curPenalty<minPenalty){
                minPenalty=curPenalty;
                resHr=hr;
            }
            else if(curPenalty==minPenalty){
                if(hr<resHr){
                    resHr=hr;
                }
            }
        }

        return resHr;
    }
};
