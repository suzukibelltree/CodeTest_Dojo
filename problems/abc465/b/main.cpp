#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;
    int cost = 0;
    for (int i = a; i < b; i++)
    {
        if (i >= l && i < r)
        {
            cost += x;
        }
        else
        {
            cost += y;
        }
    }
    cout << cost << endl;
    return 0;
}
