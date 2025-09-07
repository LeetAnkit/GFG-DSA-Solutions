class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;  // Stores prefixSum -> first index
        int prefixSum = 0;
        int maxLen = 0;

        mp[0] = -1; // Handle case where subarray starts from index 0

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            // Case 1: If current prefixSum itself equals k
            if (prefixSum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Case 2: If a subarray with sum k exists
            if (mp.find(prefixSum - k) != mp.end()) {
                int prevIndex = mp[prefixSum - k];
                maxLen = max(maxLen, i - prevIndex);
            }

            // Store prefixSum in map if it's not already there
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};