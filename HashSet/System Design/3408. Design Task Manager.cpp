struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

class TaskManager {
private:
    set<pair<int, int>, cmp> st;
    unordered_map<int, int> tU;
    unordered_map<int, int> tP;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];

            tU[taskId] = userId;
            tP[taskId] = priority;

            st.insert({priority, taskId});
        }
    }

    void add(int userId, int taskId, int priority) {
        tU[taskId] = userId;
        tP[taskId] = priority;

        st.insert({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        int oldPriority=tP[taskId];
        tP[taskId]=newPriority;

        st.erase({oldPriority,taskId});
        st.insert({newPriority,taskId});
    }

    void rmv(int taskId) {
        int userId=tU[taskId];
        int priority=tP[taskId];

        tU.erase(taskId);
        tP.erase(taskId);

        st.erase({priority,taskId});
    }

    int execTop() {
        if(st.empty()) return -1;

        auto top=st.begin();
        int priority=top->first;
        int taskId=top->second;
        int userId=tU[taskId];

        st.erase(st.begin());
        tU.erase(taskId);
        tP.erase(taskId);

        return userId;
    }
};
