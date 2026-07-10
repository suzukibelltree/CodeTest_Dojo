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
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        sum -= a[i];
        ans += a[i] * sum;
    }
    cout << ans << endl;
    return 0;
}
