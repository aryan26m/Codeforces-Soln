void solve()
{
    int n, q;
    read(n,q);
    vi v(n);
    read(v);

    int ans = 0;
    FOR(i,0,n-1) ans += min(v[i], v[i + 1]);

    while (q--)
    {
        int i, x;
        cin >> i >> x;
        i--;

        if (i > 0)
            ans -= min(v[i - 1], v[i]);
        if (i < n - 1)
            ans -= min(v[i], v[i + 1]);

        v[i] = x;

        if (i > 0)
            ans += min(v[i - 1], v[i]);
        if (i < n - 1)
            ans += min(v[i], v[i + 1]);

        cout << ans << endl;
    }
}