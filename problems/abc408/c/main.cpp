#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // ここに解法を書く
    int n, m;
    cin >> n >> m;
    vector<int> L(m), R(m);
    vector<int> diff(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> L[i] >> R[i];
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    for (int i = 0; i < n; i++)
    {
        diff[L[i]] += 1;     // 城壁L[i]から守る砲台が1個増え
        diff[R[i] + 1] -= 1; // 城壁R[i]+1から守る砲台が1個減る
    }
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << diff[i] << " ";
    }
    auto ans = min_element(diff.begin() + 1, diff.end());
    cout << *ans << endl;
    return 0;
}
