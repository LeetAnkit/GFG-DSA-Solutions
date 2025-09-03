class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        
        int count =0;
        
        int original = n;
        
        while(n > 0){
            int last = n % 10;
            if( last != 0 && original % last ==0){
                count++;
            }
            n/=10;
        }
        return count;      // code here
      
    }
};