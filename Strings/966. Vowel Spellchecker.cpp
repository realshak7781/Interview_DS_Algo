class Solution {
private:
    string getLower(string s) {
        string cur = "";
        for (char c : s) {
            cur += tolower(c);
        }
        return cur;
    }

    string getWildCard(string s) {
        for (char& c : s) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> original(wordlist.begin(), wordlist.end());

        
        unordered_map<string, string> ci;
        unordered_map<string, string> wildcardMap;

        for (int i = 0; i < wordlist.size(); i++) {
            string s = wordlist[i];
            string ls = getLower(s);
            string ws = getWildCard(ls);

            if (!ci.count(ls)) ci[ls] = s;
            if (!wildcardMap.count(ws)) wildcardMap[ws] = s;
        }

        vector<string> res;
        for (string cur : queries) {
            if (original.count(cur)) {
                res.push_back(cur);
                continue;
            }

            // Check for case-insensitive match
            string lowerCur = getLower(cur);
            if (ci.count(lowerCur)) {
                res.push_back(ci[lowerCur]);
                continue;
            }

            // Check for wildcard match
            string wildCur = getWildCard(cur);
            if (wildcardMap.count(wildCur)) {
                res.push_back(wildcardMap[wildCur]);
                continue;
            }

            // Return empty string if no match found
            res.push_back("");
        }

        return res;
    }
};
