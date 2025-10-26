class Bank {
private:
unordered_map<int,long long> bank;
int totalAccs=0;
public:
    Bank(vector<long long>& balance) {
        totalAccs=balance.size();

        for(int i=0;i<totalAccs;i++){
            bank[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>totalAccs || account2>totalAccs || !withdraw(account1,money)) return false;

        deposit(account2,money);

        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account>totalAccs) return false;

        bank[account]+=money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>totalAccs || money>bank[account]) return false;

        bank[account]-=money;
        return true;
    }
};

