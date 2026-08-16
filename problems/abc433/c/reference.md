# abc433 c 解説の材料

## 公式解説
<!-- 解説PDF/スライドのURL、または解説の要点をここに貼り付ける -->
URL: https://atcoder.jp/contests/abc433/editorial/14639

## 解き直し後のACコード
<!-- 解けなかった場合、後で解き直してACしたコードをここに貼る (無ければ空でOK) -->
explanation.md の解法(ランレングス圧縮 + 隣接runの境界でmin加算)をもとにした回答例。sample-1で動作確認済み(出力: 11)。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    // ランレングス圧縮: (数字, 連続個数) の列にする
    vector<pair<char, long long>> runs;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[j] == s[i])
        {
            j++;
        }
        runs.push_back({s[i], j - i});
        i = j;
    }

    // 隣り合うrunの境界で「後ろの数字 = 前の数字 + 1」なら min(個数, 個数) を加算
    long long ans = 0;
    for (size_t k = 0; k + 1 < runs.size(); k++)
    {
        if (runs[k].first + 1 == runs[k + 1].first)
        {
            ans += min(runs[k].second, runs[k + 1].second);
        }
    }

    cout << ans << endl;
    return 0;
}
```

## 詰まったポイント
<!-- log.csv の notes と合わせて、何が分からなかったかを書いておくとAIが要点をまとめやすい -->
