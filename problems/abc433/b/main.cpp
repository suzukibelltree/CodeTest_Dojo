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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int baseline = a[i]; // 基準となるi番目の人の身長
        int ans = -1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > baseline)
            {
                ans = j + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
