#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m, 0));
    bool ok = false;
    int ans = 1200000;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // bit全探索による2^n回のループ
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        vector<int> skill(m, 0);
        int cost = 0;
        // 各要素 i が選ばれているか判定
        for (int i = 0; i < n; ++i)
        {
            if ((bit >> i) & 1)
            {
                // i 番目の要素が選ばれている場合の処理
                cost += c[i];
                for (int j = 0; j < m; j++)
                {
                    skill[j] += a[i][j];
                }
            }
        }
        if (*min_element(skill.begin(), skill.end()) >= x)
        {
            ok = true;
            ans = min(ans, cost);
        }
    }
    if (ok)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
