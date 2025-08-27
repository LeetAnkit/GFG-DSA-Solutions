// User function Template for C++
class Solution {
    
  private : 
    void topoSort( int node , vector<pair<int, int>> adj[], vector<int>&vis, stack<int> &st){
        // this is the function to implement Topologicval Sort
        
        vis[node] =1;
        for( auto it : adj[node]){
            int v  = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
                
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, int>> adj[V];
        
        for( int i= 0 ; i< E; i ++){
            int u =edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
            
        }
        
        // find the topo Sort
        vector<int>vis(V, 0);
        stack<int> st;
        for( int i =0 ; i< V ; i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
                
            }
        }
        
        // now Step 2 distnace Sort
        
        vector<int>dis(V);
        for( int i =0 ; i< V ; i++){
            dis[i] = 1e9;
            
        }
        
        dis[0] =0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for( auto it : adj[node]){
                int v = it.first;
                int wt = it.second;
                
                
                if( dis[node] + wt < dis[v]){
                    dis[v] = wt+ dis[node];
                }
            }
        }
        
        for( int i =0 ; i< V ; i++){
            if( dis[i] == 1e9) dis[i] =-1;
        }
        return dis;
        
    }
};
