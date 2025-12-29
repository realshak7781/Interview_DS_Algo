// optimizing using a hashmap to check only those strings that are allowed
class Solution {
private:
    unordered_map<string,vector<char>> transitions;
    void generateStrings(string s, int pos, int len, string &prev,vector<string>&temp) {
        if (pos == len) {
            temp.push_back(s);
            return;
        }

        string key=prev.substr(pos,2);
        for (char c:transitions[key]) {
            generateStrings(s + c, pos + 1, len, prev,temp);
        }
    }

    bool solve(string cur) {
        int curLen = cur.length() - 1;
        if (curLen == 0) return true;

        vector<string> all; 
        generateStrings("", 0, curLen, cur,all);
        for (string &s : all) {
            if (solve(s)) return true;
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        for(string &s:allowed){
            char top=s[2];
            string key=s.substr(0,2);
            transitions[key].push_back(top);
        }
        return solve(bottom);
    }
};


// Using backtracking Brute force
// time : Exponential time complexoty
class Solution {
private:
    unordered_set<string> available;
    vector<char> input;
    void generateStrings(string s, int pos, int len, string &prev,vector<string>&temp) {
        if (pos == len) {
            temp.push_back(s);
            return;
        }

        vector<string> res;
        for (char c :input) {
            string key = prev.substr(pos, 2) + c;

            if (available.count(key)) {
                generateStrings(s + c, pos + 1, len, prev,temp);
            }
        }
    }

    bool solve(string cur) {
        int curLen = cur.length() - 1;
        if (curLen == 0) return true;

        vector<string> all; 
        generateStrings("", 0, curLen, cur,all);
        for (string &s : all) {
            if (solve(s)) return true;
        }
        return false;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        input={'A', 'B', 'C', 'D', 'E', 'F'};
        for (string &s : allowed)
            available.insert(s);

        return solve(bottom);
    }
};
