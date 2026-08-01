# abc398 c 解説の材料

## 公式解説
URL: https://atcoder.jp/contests/abc398/editorial/12482

### 問題概要
N 人がいて、人 i は数 A_i を持つ。「自分以外の N-1 人の中に自分と同じ数を持つ人がいない」
(= 自分の持つ数が全体でちょうど1回しか出現しない) という条件を満たす人のうち、
持っている数が最大の人の番号を出力する。満たす人がいなければ `-1`。

### 想定解法
- 素朴に「各人について他の全員と比較」すると O(N²) で TLE。
- 連想配列(map/unordered_map)で `cnt[v] = 値 v を持つ人数` を集計すれば、
  `cnt[A_i] == 1` であることが「A_i は自分しか持っていない」ことと同値になる。
- あとは `cnt[A_i] == 1` を満たす人の中で A_i が最大のものを探すだけ。O(N log N) または O(N)。

## 詰まったポイント
mapを使って数と登場回数を記録しようとしたが、回答には人の番号も必要であったためmapとは別にvectorのaを用意する必要があった？

## 解き直し後のACコード

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    unordered_map<long long, int> cnt;
    cnt.reserve(n * 2);
    for (auto x : a) cnt[x]++;

    int ansIdx = -1;
    long long best = -1;
    for (int i = 0; i < n; i++)
    {
        if (cnt[a[i]] == 1 && a[i] > best)
        {
            best = a[i];
            ansIdx = i + 1;
        }
    }

    cout << ansIdx << endl;
    return 0;
}
```

サンプル1で動作確認済み(出力 `-1` が `sample-1-expected.txt` と一致)。
また `2\n5 3`→`1`、`1\n7`→`1`、`3\n1 5 3`→`2`、`3\n5 5 3`→`3`、
`5\n10 10 9 8 8`→`3` など、提出コードが誤答していたケースも含めて正しく動くことを確認済み。