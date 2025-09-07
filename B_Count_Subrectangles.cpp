#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nextGreaterRight(const vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }

public:
    long long bowlSubarrays(vector<int>& parvostine) {
        int n = parvostine.size();
        vector<int> right = nextGreaterRight(parvostine);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (right[i] < n) {
                ans += max(0, right[i] - i - 1); // count only from left wall
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5,1,2,3,4};
    cout << sol.bowlSubarrays(nums) << "\n"; // Expected: 3
}


