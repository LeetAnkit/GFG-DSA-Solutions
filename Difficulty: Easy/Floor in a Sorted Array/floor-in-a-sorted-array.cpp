class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int position = -1;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] <= x) {
                position = i;  // keep updating to get the last valid index
            } else {
                break; // since array is sorted, no need to check further
            }
        }
        return position;
    }
};
