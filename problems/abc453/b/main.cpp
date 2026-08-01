#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int t, x;
    cin >> t >> x;
    vector<int> a(t + 1);
    int pre_save = 0;
    for (int i = 0; i <= t; i++)
    {
        cin >> a[i];
        if (i == 0 || abs(pre_save - a[i]) >= x)
        {
            cout << i << " " << a[i] << endl;
            pre_save = a[i];
        }
    }
    return 0;
}
