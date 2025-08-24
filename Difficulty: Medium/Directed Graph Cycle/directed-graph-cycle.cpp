class Solution {
       
    private:
      bool dfsCheck(int node , vector<int> adj[], vector<int> &vis, vector<int>& pathVis){
          vis[node] =1;
          pathVis[node] =1;
          
          // traversing the adjancent node
          for(auto it : adj[node]){
              //when the node is not visited
              if(!vis[it]){
                  if(dfsCheck(it, adj , vis, pathVis) == true)
                  
                     return true;
                  
              }
              //if the node  has been proivouly visited 
              //but it has not visted ont  the same path
              
              else if ( pathVis[it]){
                  return true;
              }
          }
          
          pathVis[node ] =0;
          return false;
      }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        
        vector<int> adj[V];
        for( auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
        }
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVisited(V, 0);
        
        
        for( int i =0 ; i< V ; i++){
            if( !vis[i]){
                if(dfsCheck(i, adj , vis , pathVisited) == true) return true;
            }
        }
        return false;
        
    }
};