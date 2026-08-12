#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> c(n + 1);
    vector<int> kind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        kind[c[i]] += 1;
    }
    int max_kind = *max_element(kind.begin(), kind.end());
    cout << n - max_kind << endl;
    return 0;
}
