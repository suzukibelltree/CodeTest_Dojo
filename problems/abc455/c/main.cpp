#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, k;
    cin >> n >> k;
    vector<long long> input(n);
    vector<long long> a(300000);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        a[input[i] - 1] += input[i];
        sum += input[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < k; i++)
    {
        sum -= a[i];
    }
    cout << sum << endl;
    return 0;
}
