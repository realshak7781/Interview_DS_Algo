class Router {
private:
    unordered_map<string, vector<int>> packets;
    unordered_map<int, vector<int>> dR;
    queue<string> q;
    int size;
    int limit;

public:
    Router(int memoryLimit) {
        size = 0;
        limit = memoryLimit;
    }

    string get_key(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = get_key(source, destination, timestamp);

        if (packets.count(key))
            return false;

        if (size == limit) {
            // remove the first
            forwardPacket();
        }

        q.push(key);
        packets[key] = {source, destination, timestamp};
        dR[destination].push_back(timestamp);
        size++;

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        string key = q.front();
        q.pop();

        vector<int> packet = packets[key];
        int d=packet[1];
        packets.erase(key);
        dR[d].erase(dR[d].begin());
        size--;
        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        int count=0;
        auto &vec=dR[destination];
        auto start=lower_bound(vec.begin(),vec.end(),startTime);
        auto end=upper_bound(vec.begin(),vec.end(),endTime);

        count=end-start;

        return count;
    }
};
