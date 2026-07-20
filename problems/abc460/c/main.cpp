#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int tmp = min(n, m);
    int idx = 0;
    for (int i = 0; i < tmp; i++)
    {
        if (a[i] * 2 >= b[idx])
        {
            ans++;
            idx++;
        }
    }

    cout << ans << endl;
    return 0;
}
