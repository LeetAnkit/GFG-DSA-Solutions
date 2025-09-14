class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<long long , int> sum_map;   // {prefix_sum : index}
        
        long long current_sum =0;
        
        int max_len =0;
        
        for( int i =0 ; i< n ; i++){
            current_sum += arr[i];
            // case 1  The SubArray with sum k starts from the index 0
            // if current_sum itself is k , the length is the current index +1;
             
            if( current_sum == k){
                max_len = i+1;
            }
            
            long long remainder = current_sum - k;
            
            if(sum_map.count(remainder)){
                int length = i - sum_map[remainder];
                max_len = max( max_len , length);
                
                
            }
            
            if( sum_map.count(current_sum) == 0){
                sum_map[current_sum] = i;
            }
  
        }
        return max_len;
        
    }
};