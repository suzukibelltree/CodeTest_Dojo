#include <bits/stdc++.h>
using namespace std;

long long factrial(int num)
{
    long long ans = 1;
    for (int i = 1; i <= num; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int absX = abs(x[i] - x[j]);
            int absY = abs(y[i] - y[j]);
            double distance = sqrt(absX * absX + absY * absY);
            ans += distance;
        }
    }
    ans /= n;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
