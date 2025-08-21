class Solution {
    
  private:
  
  bool detect(int src, vector<int> adj[], int vis[]){
      vis[src] =1 ;
      
      queue<pair<int, int>> q;
      q.push({src, -1});   // node, parent
      
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto adjacentNode : adj[node]){
              if(!vis[adjacentNode]){
                  vis[adjacentNode] = 1;
                  q.push({adjacentNode, node});  
              }
              else if(parent != adjacentNode){  // cycle condition
                  return true;
              }
          }
      }
      return false;
  }
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        // Build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int vis[V] = {0};
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) 
                    return true;
            }
        }
        return false;
    }
};
