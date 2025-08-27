class Solution {
public:
   vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
    // Convert edge list to adjacency list
    vector<pair<int,int>> adj[V];
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // if graph is undirected
    }

    // Now same Dijkstra logic
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dis(V, 1e9);
    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (currDist > dis[node]) continue;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (currDist + edgeWeight < dis[adjNode]) {
                dis[adjNode] = currDist + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}

};
