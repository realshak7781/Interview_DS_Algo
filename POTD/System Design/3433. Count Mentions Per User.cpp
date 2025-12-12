class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 int t1 = stoi(a[1]);
                 int t2 = stoi(b[1]);
                 if (t1 != t2) {
                     return t1 < t2;
                 } else {

                     return (a[0] == "OFFLINE" && b[0] != "OFFLINE");
                 }
             });

        vector<int> mentions(numberOfUsers, 0);
        unordered_map<int, int> offline;

        for (auto e : events) {
            int timeStamp = stoi(e[1]);

            if (e[0] == "MESSAGE") {
                if (e[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        mentions[i]++;
                } else if (e[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offline.count(i)) {
                            if (timeStamp > offline[i]) {
                                mentions[i]++;
                                offline.erase(i);
                            }
                        } else {
                            mentions[i]++;
                        }
                    }
                } else {
                    string s = e[2];
                    stringstream ss(s);
                    string token;

                    while (getline(ss, token, ' ')) {
                        string idS = token.substr(2);
                        int id = stoi(idS);
                        mentions[id]++;
                    }
                }
            } else {
                int id = stoi(e[2]);
                offline[id] = timeStamp + 59;
            }
        }

        return mentions;
    }
};
