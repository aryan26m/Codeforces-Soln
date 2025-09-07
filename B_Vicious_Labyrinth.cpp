#include <bits/stdc++.h>
using namespace std;

// Count bowl subarrays:
// A subarray [l, r] (r - l + 1 >= 3) is a bowl if
// min(nums[l], nums[r]) > max(nums[l+1..r-1]).
//
// Key observation with distinct elements:
// For any bowl [l, r], the interior maximum occurs at some unique index p (l < p < r).
// Then l must be the nearest greater to the left of p, and r must be the nearest greater to the right of p.
// Therefore there is a 1-1 correspondence between bowls and indices p that have both a
// nearest greater on the left and a nearest greater on the right.
// So, the answer is simply the count of indices p with NGL[p] != -1 and NGR[p] != n.

class Solution {
    vector<int> nextGreaterRight(const vector<int>& a) {
        int n = (int)a.size();
        vector<int> res(n, n);
        stack<int> st; // decreasing stack by value (indices)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && a[st.top()] < a[i]) st.pop();
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> nextGreaterLeft(const vector<int>& a) {
        int n = (int)a.size();
        vector<int> res(n, -1);
        stack<int> st; // decreasing stack by value (indices)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && a[st.top()] < a[i]) st.pop();
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }

public:
    long long bowlSubarrays(vector<int>& nums) {
        vector<int> v = nums;

        int n = (int)v.size();
        if (n < 3) return 0;

        vector<int> L = nextGreaterLeft(v);
        vector<int> R = nextGreaterRight(v);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (L[i] != -1 && R[i] != n) {
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 1, 2, 3, 4};
    cout << sol.bowlSubarrays(nums) << "\n"; // Expected: 3
    return 0;
}