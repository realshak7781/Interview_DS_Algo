class SmallestInfiniteSet {
private:
unordered_set<int> st;
int smallest;   
public:
    SmallestInfiniteSet() {
       for(int i=1;i<1001;i++){
        st.insert(i);
       }
       smallest=1;
    }
    
    int popSmallest() {
        int smll=smallest;
        st.erase(smll);
        for(int sm=smallest+1;sm<=1000;sm++){
            if(st.count(sm)){
                smallest=sm;
                break;
            }
        }
        return smll;
    }
    
    void addBack(int num) {
        if(st.count(num)) return;
        st.insert(num);

        if(num<smallest){
            smallest=num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
