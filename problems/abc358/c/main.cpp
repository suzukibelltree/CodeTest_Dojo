#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        vector<int> available(m, 0);

        int cost = 0;
        // 各要素 i が選ばれているか判定
        for (int i = 0; i < n; ++i)
        {
            if ((bit >> i) & 1)
            {
                // i 番目の要素が選ばれている場合の処理
                cost++;
                for (int j = 0; j < s[i].size(); j++)
                {
                    if (s[i].at(j) == 'o')
                    {
                        available[j] = 1;
                    }
                }
            }
            if (*min_element(available.begin(), available.end()) == 1)
            {
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
