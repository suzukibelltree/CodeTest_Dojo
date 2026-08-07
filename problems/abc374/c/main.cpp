#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int n;
    cin >> n;
    vector<long long> k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    long long sum = reduce(k.begin(), k.end());
    long long ans = sum;
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        long long breaking = 0;
        long long working = 0;
        // 各要素 i が選ばれているか判定
        for (int i = 0; i < n; ++i)
        {
            if ((bit >> i) & 1)
            {
                // i 番目の要素が選ばれている場合の処理
                breaking += k[i];
            }
        }
        working = sum - breaking;
        ans = min(ans, max(breaking, working));
    }
    cout << ans << endl;
    return 0;
}
