#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int ans = 0;
    do
    {
        if (p < a && a < q)
        {
            ans++;
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    return 0;
}
