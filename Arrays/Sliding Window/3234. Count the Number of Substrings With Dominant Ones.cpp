class Solution {
private:
vector<int> prefixOnes, prefixZeroes;
int n;
void buildPrefixSum(string &s){
    n=s.length();

    prefixOnes.resize(n);
    prefixZeroes.resize(n);

    prefixOnes[0] = (s[0] == '1') ? 1 : 0;
    prefixZeroes[0] = (s[0] == '0') ? 1 : 0;

    for(int i=1;i<n;i++){
        prefixOnes[i] = prefixOnes[i - 1] + (s[i] == '1' ? 1 : 0);
        prefixZeroes[i] = prefixZeroes[i - 1] + (s[i] == '0' ? 1 : 0);
    }
}

int bruteForce(string &s){
    buildPrefixSum(s);


        int count=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int onesCount=prefixOnes[j]-(i>0 ? prefixOnes[i-1] : 0);
                int zeroesCount=prefixZeroes[j] - (i>0 ? prefixZeroes[i-1]:0);

                int zeroSq=zeroesCount*zeroesCount;

                if(onesCount>=zeroSq){
                    count++;
                }
            }
        }

        return count;
}

int optimal(string &s){
    int n=s.length();
    vector<int> cumOneSum(n);

    cumOneSum[0]= (s[0]=='1' ? 1 : 0);

    for(int i=1;i<n;i++){
        cumOneSum[i]=cumOneSum[i-1]+((s[i]=='1' ? 1 : 0));
    }


    int doms=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int oneCount=cumOneSum[j]-(i>0 ? cumOneSum[i-1] : 0);
            int zeroCount=(j-i+1)-oneCount;

            if((zeroCount*zeroCount)>oneCount){
                int needOnes=(zeroCount*zeroCount)-oneCount;
                // skipping indices to incorporate some more ones
                j=j+(needOnes-1);
            }
            else if((zeroCount*zeroCount)==oneCount){
                doms+=1;
            }
            else{
                // zero*zero < one
                // safely skip some indices
                doms+=1;
                int k=sqrt(oneCount)-zeroCount;
                // k is the amount by which we can safely skip indices incorporating more zeroes and increasing doms
                int nextj=j+k;

                if(nextj>=n){
                    // out of bounds;
                    doms+=(n-j-1);
                    break;
                }
                else{
                    doms+=k;
                }
                j=nextj;
            }
        }
    }

    return doms;
}
public:
    int numberOfSubstrings(string s) {
        return optimal(s);
    }
};
