class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            // Sum of consecutive pair
            int currSum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
