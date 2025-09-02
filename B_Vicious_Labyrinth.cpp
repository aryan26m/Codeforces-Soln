#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        
        for(auto &x:nums){
            maxo = max(maxo,x);
        }
        int mxbit = 0;
        while ((1 << mxbit) <= maxo){
            mxbit++;
        } 
        int N = (1 << mxbit);

        vector<int> maxi(N, 0);
        for (int x : nums) {
            maxi[x] = max(maxi[x], x);
        }

        for (int i = 0; i < mxbit; ++i)
         {
            for (int mask = 0; mask < N; ++mask) 
            {
                if (mask & (1 << i)) 
                {
                    maxi[mask] = max(maxi[mask], maxi[mask ^ (1 << i)]);
                }
            }
        }

        long long res = 0;
        for (int x : nums) {
            int inv = ((1 << mxbit) - 1) ^ x; 

            res = max(res, 1LL * x * maxi[inv]);
        }
        return res;
    }
};