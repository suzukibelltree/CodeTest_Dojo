#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<long long> H(n), L(n);
    for (int i = 0; i < n; i++)
    {
        cin >> H[i] >> L[i];
    }

    vector<long long> highest(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        // i番目以降の身長の最大値を求めている
        highest[i] = max(H[i], highest[i + 1]);
    }
    int q;
    cin >> q;
    while (q > 0)
    {
        q--;
        long long query;
        cin >> query;
        // queryより大きい最初の要素を二分探索で求めている
        int ans = upper_bound(L.begin(), L.end(), query) - L.begin();
        cout << highest[ans] << "\n";
    }
    return 0;
}
