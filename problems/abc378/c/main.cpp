#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    map<long long, long long> map;
    for (int i = 0; i < n; i++)
    {
        long long key;
        cin >> key;
        if (map[key] != 0)
        {
            cout << map[key] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        map[key] = i + 1;
    }
    return 0;
}
