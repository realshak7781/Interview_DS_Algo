


// O(1) AVERAGE : BRUTE FORCE

class WordDictionary {
private:
    unordered_set<string> vis;

public:
    WordDictionary() {
    }

    void addWord(string word) {
        if(vis.count(word)) return;
        vis.insert(word); 
    }

    bool search(string word) {
        int dotCnt = 0;
        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == '.') {
                dotCnt++;
                if (idx1 == -1) {
                    idx1 = i;
                } else {
                    idx2 = i;
                    break; 
                }
            }
        }

        if (dotCnt == 0) {
            return vis.count(word);
        } else if (dotCnt == 1) {
            for (char c = 'a'; c <= 'z'; c++) {
                word[idx1] = c;
                if (vis.count(word)) return true;
            }
        } else if (dotCnt == 2) {
            for (char c1 = 'a'; c1 <= 'z'; c1++) {
                word[idx1] = c1;
                for (char c2 = 'a'; c2 <= 'z'; c2++) {
                    word[idx2] = c2;
                    if (vis.count(word)) return true;
                }
            }
        }

        return false;
    }
};
