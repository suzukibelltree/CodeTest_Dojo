#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> a(n);
    map<long long, long long> mp;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] += 1;
    }
    for (const auto &[key, value] : mp)
    {
        if (value >= 2)
        {
            long long tmp = (value * (value - 1)) / 2;
            ans += (n - value) * tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
