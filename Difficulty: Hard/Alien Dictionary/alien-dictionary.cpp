class Solution {
public:
    string findOrder(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            string first = words[i];
            string second = words[i + 1];
            int length = min(first.size(), second.size());
            bool found = false;
            for (int j = 0; j < length; j++) {
                if (first[j] != second[j]) {
                    int u = first[j] - 'a';
                    int v = second[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }
            // invalid case: prefix issue
            if (!found && first.size() > second.size()) {
                return "";
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }
        string result = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back('a' + node);
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        int totalChars = 0;
        for (int i = 0; i < 26; i++) if (present[i]) totalChars++;
        if (result.size() == totalChars) return result;
        return "";
    }
};