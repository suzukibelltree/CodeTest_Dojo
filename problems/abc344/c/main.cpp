#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, m, l, q;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cin >> l;
    vector<long long> c(l);
    for (int i = 0; i < l; i++)
    {
        cin >> c[i];
    }
    // A,B,C からそれぞれ 1 個ずつ要素を選び、和を X_iにすることができるか？(Yes/No)
    vector<long long> sums_list(n * m * l);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                sums_list[idx] = a[i] + b[j] + c[k];
                idx++;
            }
        }
    }
    sort(sums_list.begin(), sums_list.end());
    cin >> q;
    // 全体として計算時間は(Qlog{NML})
    while (q > 0)
    {
        q--;
        int x;
        cin >> x;
        int tmp = lower_bound(sums_list.begin(), sums_list.end(), x) - sums_list.begin();
        if (sums_list[tmp] == x)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
