#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.rbegin(), a.rend());
    int ans = a[0].second;
    for (int i = 2; i < n; i++)
    {
        if (a[i - 2].first != a[i - 1].first && a[i - 1].first != a[i].first)
        {
            ans = a[i - 1].second;
            cout << ans << endl;
            return 0;
        }
        else if (i == n - 1 && a[i - 1] != a[i])
        {
            ans = a[i].second;
            cout << ans << endl;
            return 0;
        }
    }
    if (n == 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
