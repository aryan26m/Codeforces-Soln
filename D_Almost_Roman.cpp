#include <bits/stdc++.h>
using namespace std;

struct B
{
    long long a = 0;
    long long b = 0;
    long long c = 0;
};

B g(int k, char L, char R)
{
    if (k == 0)
        return {0, 0, 0};
    bool l = (L == 'I');
    bool r = (R == 'X' || R == 'V');
    B s;
    if (l && r)
    {
        s.a = k / 2;
        s.b = (k + 1) / 2;
        s.c = k / 2 + 1;
    }
    else if (l && !r)
    {
        if (k % 2 != 0)
        {
            s.a = (k - 1) / 2;
            s.b = (k - 1) / 2;
            s.c = (k + 1) / 2;
        }
        else
        {
            s.a = (k - 2) / 2;
            s.b = k / 2;
            s.c = k / 2;
        }
    }
    else if (!l && r)
    {
        if (k % 2 != 0)
        {
            s.a = (k + 1) / 2;
            s.b = (k + 1) / 2;
            s.c = (k + 1) / 2;
        }
        else
        {
            s.a = k / 2;
            s.b = k / 2 + 1;
            s.c = k / 2;
        }
    }
    else
    {
        s.a = k / 2;
        s.b = (k + 1) / 2;
        s.c = k / 2;
    }
    return s;
}

void solve()
{
    int n, q;
    if (!(cin >> n >> q))
        return;
    string s;
    cin >> s;
    long long bf = 0;
    long long fr = 0;
    long long kt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'X')
            bf += 10;
        else if (s[i] == 'V')
            bf += 5;
        else if (s[i] == 'I')
            bf += 1;
        else
            kt++;
        if (i < n - 1 && s[i] == 'I' && (s[i + 1] == 'X' || s[i + 1] == 'V'))
        {
            fr++;
        }
    }
    string p = "X" + s + "I";
    vector<int> f;
    for (int i = 0; i < (int)p.size(); ++i)
        if (p[i] != '?')
            f.push_back(i);
    long long tpmin = 0;
    long long tpmax = 0;
    long long tmax = 0;
    for (size_t j = 0; j + 1 < f.size(); ++j)
    {
        int i1 = f[j];
        int i2 = f[j + 1];
        int k = i2 - i1 - 1;
        if (k > 0)
        {
            B r = g(k, p[i1], p[i2]);
            tpmin += r.a;
            tpmax += r.b;
            tmax += r.c;
        }
    }
    for (int qi = 0; qi < q; ++qi)
    {
        long long cx, cv, ci;
        cin >> cx >> cv >> ci;
        long long ui = min(kt, ci);
        long long rem = kt - ui;
        long long uv = min(rem, cv);
        long long ux = rem - uv;
        long long cur = 0;
        if (ui < tpmin)
            cur = tmax - (tpmin - ui);
        else if (ui > tpmax)
            cur = tmax - (ui - tpmax);
        else
            cur = tmax;
        long long tot = fr + cur;
        long long val = bf + ui * 1 + uv * 5 + ux * 10 - 2 * tot;
        cout << val << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
    {
        while (t--)
            solve();
    }
    return 0;
}
