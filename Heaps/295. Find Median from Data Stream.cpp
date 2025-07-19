// APPROACH 1 :USING BRUTE FORCE AND SORTING

// time : O(n*n*logn)
// space : O(n)
class MedianFinder {
private:
vector<int> list;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        list.push_back(num);
    }
    
    double findMedian() {
        sort(list.begin(),list.end());
        int n=list.size();

        double med;
        if(n&1){
            int idx=n/2;
            med=list[idx];
        }
        else{
            int firstIdx=n/2-1;
            int secondIdx=n/2;

            med=(double)(list[firstIdx]+list[secondIdx])/2.0;
        }

        return med;
    }
};

