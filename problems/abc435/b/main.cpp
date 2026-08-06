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
    vector<int> sum(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    for (int i = 1; i <= n; i++) // l
    {
        for (int j = i; j <= n; j++) // r
        {
            int subsum = sum[j] - sum[i - 1];
            bool ok = true;
            for (int k = i; k <= j; k++)
            {
                if (subsum % a[k] == 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
