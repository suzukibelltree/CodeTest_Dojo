#include <bits/stdc++.h>
using namespace std;

vector<long long> a(300000);
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n; // O(N^2)だとTLE
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] += 1;
    }
    int ans = -1;
    for (const auto &[key, val] : mp)
    {
        if (key > ans && val == 1)
        {
            ans = key;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ans)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
