#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sentan = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 1 || i <= sentan)
        {
            sentan = max(sentan, i + a[i] - 1);
        }
        if (sentan >= n)
        {
            sentan = n;
            break;
        }
    }
    cout << sentan << endl;

    return 0;
}
