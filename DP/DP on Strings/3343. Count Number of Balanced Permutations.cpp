
//Approach-1 (Brute Force)
//T.C : O(n * n!)
//S.C : O(n * n!), storing all permutations in set
class Solution {
public:
    int countBalancedPermutations(string num) {
        sort(begin(num),end(num));
        // sorting helps to generate lexico order of permutations

        unordered_set<string> vis;
        // taking set in case of duplicate permutation in strings like :"1123"
        int count=0;

        do{
            if(vis.count(num)) continue;

            vis.insert(num);
            int evnSum=0,odSum=0;

            for(int i=0;i<num.length();i++){
                int dig=num[i]-'0';
                if(i&1){
                    odSum+=dig;
                }
                else{
                    evnSum+=dig;
                }
            }
            if(evnSum==odSum) count++;
        }
        while(next_permutation(begin(num),end(num)));


        return count;
    }
};
