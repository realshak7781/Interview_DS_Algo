// optimal approach : just added an if condition in my main function:
class Solution {
private:
vector<vector<int>> dir={{100,0},{75,25},{50,50},{25,75}};
vector<vector<double>> dp;
double solve(int A,int B){
    if(A==0){
        if(B!=0){
            return 1.00;
        }
        return 0.5;
    }

    if(B==0){
        return 0.00;
    }

    if(dp[A][B]!=-1) return dp[A][B];
    double ans=0;
    for(auto &it:dir){
        int a=it[0];
        int b=it[1];
        int nA=max(0,A-a);
        int nB=max(0,B-b);
        ans=ans+solve(nA,nB);
    }

    ans*=0.25;

    return dp[A][B]=ans;
}
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0;
      // the problem converges after n>=5000 and it always results into 1.00 , let me share the maths behind this :

        dp=vector<vector<double>> (n+1,vector<double>(n+1,-1));
        return solve(n,n);
    }
};



// Brute force : MLE
class Solution {
private:
vector<vector<int>> dir={{100,0},{75,25},{50,50},{25,75}};
vector<vector<double>> dp;
double solve(int A,int B){
    if(A==0){
        if(B!=0){
            return 1.00;
        }
        return 0.5;
    }

    if(B==0){
        return 0.00;
    }

    if(dp[A][B]!=-1) return dp[A][B];
    double ans=0;
    for(auto &it:dir){
        int a=it[0];
        int b=it[1];
        int nA=max(0,A-a);
        int nB=max(0,B-b);
        ans=ans+solve(nA,nB);
    }

    ans*=0.25;

    return dp[A][B]=ans;
}
public:
    double soupServings(int n) {
        dp=vector<vector<double>> (n+1,vector<double>(n+1,-1));
        return solve(n,n);
    }
};
