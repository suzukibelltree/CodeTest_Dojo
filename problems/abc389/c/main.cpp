#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // ここに解法を書く
    int q;
    cin >> q;
    vector<long long> vec(q);
    int idx = 1;
    int escape_idx = 1;
    while (q--)
    {
        int num = 0;
        cin >> num;
        if (num == 1) // 長さ l のヘビが列の末尾に追加される
        {
            long long l;
            cin >> l;
            vec[idx] = l + vec[idx - 1];
            idx++;
        }
        else if (num == 2) // 列の先頭にいるヘビが列から抜ける
        {
            escape_idx++;
        }
        else // 列の先頭から数えて k 番目にいるヘビの頭の座標を出力
        {
            int k = 0;
            cin >> k;
            long long ans = vec[k - 2 + escape_idx] - vec[escape_idx - 1];
            cout << ans << endl;
        }
    }
    // for (int i = 1; i <= idx; i++)
    // {
    //     cout << vec[i] << " ";
    // }
    return 0;
}

// 普通のキューで解こうとするとタイプ3の入力で詰まる
// O(Q^2)はだめ
// キューに見せかけて実は累積和を使う問題？