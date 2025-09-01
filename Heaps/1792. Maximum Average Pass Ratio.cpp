using p=pair<double,pair<int,int>>;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int totalClasses=classes.size();

        priority_queue<p> maxHeap;
        for(auto it:classes){
            int pass=it[0];
            int total=it[1];

            long long num=total-pass;
            long long den=(long long)total*(long long)(total+1);

            double delta=(double)num/den;

            maxHeap.push({delta,{pass,total}});
        }


        while(extraStudents--){
            auto top=maxHeap.top();
            maxHeap.pop();

            int pass=top.second.first+1;
            int total=top.second.second+1;


           long long num=total-pass;
           long long den=(long long)total*(long long)(total+1);


            double delta=(double)num/den;

            maxHeap.push({delta,{pass,total}});
        }

        double res=0;

        while(!maxHeap.empty()){
            auto top=maxHeap.top();
            maxHeap.pop();

            int pass=top.second.first;
            int total=top.second.second;

            double ratio=(double)pass/total;

            res+=ratio;
        }


        res=(double)res/totalClasses;

        return res;
    }
};
