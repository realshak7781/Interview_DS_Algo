class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int left=0,right=n-1;

        sort(people.begin(),people.end());
        int totalBoats=0;
        while(left<=right){
            int wtSum=people[left]+people[right];

            if(left==right){
                wtSum-=people[left];
            }
            
            if(wtSum>limit){
                right--;
                totalBoats+=1;
            }
            else{
                left++;
                right--;
                totalBoats+=1;
            }
           
        }

        return totalBoats;
    }
};
