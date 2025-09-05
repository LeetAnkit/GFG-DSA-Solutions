class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int  max = arr[0];
        int n = arr.size();
        for( int i =1; i< n ; i++){
            if(arr[i] >   max ) {
                max = arr[i];
            }
            else{
                continue;
            }
        }
        return max;
    }
};
