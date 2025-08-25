class Solution {
    
//   private:
     
//      void dfs(int node , vector<int>&vis, stack<int> &st, vector<int> adj[]){
//          vis[node] =1;
//          for( auto it : adj[node]){
//              if(!vis[it]) dfs(it, vis , st, adj);
//          }
//          st.push(node);
         
//      }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        
        //making of the ajanceny list
        
    //     vector<int> adj[V];
    //     for( auto &e : edges){
    //         adj[e[0]].push_back(e[1]);
    //     }
        
    //   vector<int> vis( V, 0);
      
    //   stack<int>st;
    //   for( int i =0 ; i< V ; i++){
    //       if( !vis[i]) {
    //           dfs( i, vis, st, adj);
               
    //       }
    //   }
    //   vector<int> ans;
       
    //   while( !st.empty()){
    //       ans.push_back(st.top());
    //       st.pop();
    //   }
    //   return ans;
      
        // code here
        
        
        vector<int> adj[V];
        // Adjaency list is made 
        
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
        }
        
        vector<int> indegree(V, 0);
        
        for(int i =0 ; i< V ; i++){
                for( auto it : adj[i]){
                    indegree[it]++;
                }
            
        }
        
        queue<int> q;
        for( int i =0 ; i< V ; i++){
            if( indegree[i] == 0){
                q.push(i);
                
            }
        }
        vector<int> topo;
        while( !q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            
            //node is in your topo
            // so please remove it from the indegree
            
            for( auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] ==0) q.push(it);
                
            }
            
        }
        return topo;
        
        
        
        
    }
};