class Solution {
  public:
  
    int computeGCD ( int a, int b ){
        while( b !=0 ){
            int temp = b ;
            b = a%b;
            a = temp;
        }
        
        return a ;
    }
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        
        int gcd = computeGCD( a, b);
        int lcm = (a*b)/gcd;
        
        return {lcm, gcd};
        
    }
};