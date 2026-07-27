#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, m;
    cin >> n >> m;
    vector<int> maxSize(m + 1);
    for (int i = 0; i < n; i++)
    {
        int color, size;
        cin >> color >> size;
        if (maxSize[color] < size)
        {
            maxSize[color] = size;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (maxSize[i] == 0)
        {
            cout << -1;
        }
        else
        {
            cout << maxSize[i];
        }

        if (i != m)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
