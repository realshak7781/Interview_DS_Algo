

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        
        // To store whether a transaction is invalid
        vector<bool> invalid(n, false);
        
        // Step 1: Mark transactions with amount > 1000 as invalid
        for (int i = 0; i < n; i++) {
            string cur = transactions[i];
            int amount = -1;
            
            stringstream ss(cur);
            string temp;
            int idx = 0;
            
            while (getline(ss, temp, ',')) {
                if (idx == 2) {
                    amount = stoi(temp);
                    break;
                }
                idx++;
            }
            
    
            if (amount > 1000) {
                invalid[i] = true;
            }
        }

   
        for (int i = 0; i < n; i++) {
            if (invalid[i]) continue;  

            string cur = transactions[i];
            stringstream ss(cur);
            string temp;
            string name, city;
            int time;

            int idx = 0;
            while (getline(ss, temp, ',')) {
                if (idx == 0) {
                    name = temp;
                } else if (idx == 1) {
                    time = stoi(temp); 
                } else if (idx == 3) {
                    city = temp;
                }
                idx++;
            }

            for (int j = 0; j < n; j++) {
                if (i == j) continue;  
                
                
                string otherCur = transactions[j];
                stringstream otherSs(otherCur);
                string otherTemp;
                string otherName, otherCity;
                int otherTime;

                int otherIdx = 0;
                while (getline(otherSs, otherTemp, ',')) {
                    if (otherIdx == 0) {
                        otherName = otherTemp; 
                    } else if (otherIdx == 1) {
                        otherTime = stoi(otherTemp);
                    } else if (otherIdx == 3) {
                        otherCity = otherTemp;
                    }
                    otherIdx++;
                }

                if (name == otherName && city != otherCity) {
                    if (abs(time - otherTime) <= 60) {
                        invalid[i] = invalid[j] = true; 
                    }
                }
            }
        }

        // Step 3: Collect all invalid transactions
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (invalid[i]) {
                res.push_back(transactions[i]);
            }
        }
        
        return res;
    }
};
