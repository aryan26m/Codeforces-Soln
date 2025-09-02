#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size(), m = ws.size();
        vector<pair<int, int>> land(n), water(m);
        for (int i = 0; i < n; i++) land[i] = {ls[i], ld[i]};
        for (int i = 0; i < m; i++) water[i] = {ws[i], wd[i]};

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> pre(m), sfx(m);
        pre[0] = water[0].second;
        for (int i = 1; i < m; i++) {
            pre[i] = min(pre[i - 1], water[i].second);
        }
        sfx[m - 1] = water[m - 1].first + water[m - 1].second;
        for (int i = m - 2; i >= 0; i--) {
            sfx[i] = min(sfx[i + 1], water[i].first + water[i].second);
        }

        vector<int> pre2(n), sfx2(n);
        pre2[0] = land[0].second;
        for (int i = 1; i < n; i++) {
            pre2[i] = min(pre2[i - 1], land[i].second);
        }
        sfx2[n - 1] = land[n - 1].first + land[n - 1].second;
        for (int i = n - 2; i >= 0; i--) {
            sfx2[i] = min(sfx2[i + 1], land[i].first + land[i].second);
        }

        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            int le = land[i].first + land[i].second;
            int idx = (int)(lower_bound(water.begin(), water.end(), make_pair(le, 0)) - water.begin());

            int cnt = INT_MAX;
            if (idx < m) cnt = min(cnt, sfx[idx]);
            if (idx > 0) cnt = min(cnt, le + pre[idx - 1]);

            res = min(res, cnt);
        }

        for (int i = 0; i < m; i++) {
            int we = water[i].first + water[i].second;
            int idx = (int)(lower_bound(land.begin(), land.end(), make_pair(we, 0)) - land.begin());

            int cnt = INT_MAX;
            if (idx < n) cnt = min(cnt, sfx2[idx]);
            if (idx > 0) cnt = min(cnt, we + pre2[idx - 1]);

            res = min(res, cnt);
        }

        return res;
    }
};
