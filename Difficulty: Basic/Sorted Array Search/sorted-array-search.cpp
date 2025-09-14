class Solution {
  public:
  
  
    bool find(vector<int>& arr , int first, int last, int k){
        
        if(first > last) return false;
        
        int mid = first + (last - first) / 2;
        
        
        
        if( arr[mid] == k ) {
            return true;
        }
        else if( arr[mid] >  k){
            return find(arr, first, mid-1, k);
            
            
        }
        else if(arr[mid] < k ){
            return find(arr, mid+1, last , k);
        }
        
        
        
    }
    bool searchInSorted(vector<int>& arr, int k) {
        
        return find(arr, 0, arr.size()-1 , k);
    
    
    
        // code here
        
    }
};