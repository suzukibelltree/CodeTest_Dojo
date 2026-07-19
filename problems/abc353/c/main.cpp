#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<long long> a(n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // 愚直にやるとO(N^2)で詰む
    // 各要素はそれぞれn回参照される
    // 昇順にソートしておく
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        // a[i]との和が10^8以上になるindexを二分探索で求める
        int idx = lower_bound(a.begin(), a.end(), 100000000 - a[i]) - a.begin();
    }
    return 0;
}
