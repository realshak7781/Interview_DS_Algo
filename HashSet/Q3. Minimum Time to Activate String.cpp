class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        // the approach boils down to basic substring count:
        //  start at t=0 and keep on incrementing t
        // for each t you get a position to insert star from order[t]:
        // when you insert a star at that position you need to count the no of new subarrays introduced because of that insertion : (subarrays containing atleast one star)
        // this comes down to some maths :
        //     the new subarrays formed will be counted as follows:
            //   find the last prev pos where star was  inserted call it prev;
            // find the position after cur pos where star was inserted call it next
            // count the left elements and then right elements

            int n=s.length();
            set<int> st;

            st.insert(-1);
            st.insert(n);

            long long totalSub=0;
            for(int t=0;t<order.size();t++){
                int time=t;
                int pos=order[time];

                st.insert(pos);
                // this is the position where new star comes in

                auto it=st.find(pos);
                int leftPos=*(prev(it));
                int rightPos=*(next(it));

                // left pos is the pos of star on leftSide  and rightSide
                int leftCount=pos-leftPos;
                int rightCount=rightPos-pos;

              
                long long newSubarrayIntroduced=1LL*leftCount*rightCount;

                totalSub+=newSubarrayIntroduced;

                if(totalSub>=k) return time;
            }


            return -1;
    }
};
