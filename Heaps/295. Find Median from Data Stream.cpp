// optimal approach:
// time : o(NlogN)
class MedianFinder {
private:
priority_queue<int> firstHalf;
priority_queue<int,vector<int>,greater<int>> secondHalf;
int size;
public:
    MedianFinder() {
        // constructor called:
        //  if u wanna keep a size makes it easy to calculate;
        size=0;
    }
    
    void addNum(int num) {
        secondHalf.push(num);
        size++;

        if(!firstHalf.empty() && secondHalf.top()<firstHalf.top()){
            // needs rearranging between the tops of heaps
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }

        if(size%2==0 && secondHalf.size()>firstHalf.size()+1){
            // even size case
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
        else if(firstHalf.size()>secondHalf.size()){
            // odd size cases
            secondHalf.push(firstHalf.top());
            firstHalf.pop();
        }
    }
    
    double findMedian() {
        if(size&1){
            // if size is odd
            return (double)secondHalf.top();
        }

        double med=(double)(firstHalf.top()+secondHalf.top())/2.0;

        return med;
    }
};





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

