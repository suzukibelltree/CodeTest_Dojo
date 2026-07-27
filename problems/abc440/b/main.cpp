#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<pair<int, int>> T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i].first;
        T[i].second = i + 1;
    }
    sort(T.begin(), T.end());
    cout << T[0].second << " " << T[1].second << " " << T[2].second << endl;
    return 0;
}
