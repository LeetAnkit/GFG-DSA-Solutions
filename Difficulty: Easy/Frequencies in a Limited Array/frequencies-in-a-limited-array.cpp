class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int> mp;
        vector<int> ans;
        for( auto ele : arr){
            mp[ele]++;
            
            
        }
        
        
       for( int i = 1; i<= n ; i++){
           if(mp.find(i) != mp.end()){
               ans.push_back(mp[i]);
           }
           else{
               ans.push_back(0);
           }
       }
       
       return ans;
        
        
    }
};
