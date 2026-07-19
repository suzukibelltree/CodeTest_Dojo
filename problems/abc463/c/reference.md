# abc463 c 解説の材料

## 公式解説
URL: https://atcoder.jp/contests/abc463/editorial/21941

### 問題概要
高橋くんたちが会議室に出入りする。各高橋くんには身長 H_i と退出時刻 L_i があり、
クエリで与えられる時刻 T について「T より後に退出する人たちの中で最も背が高い人の身長」を答える。

### 想定解法
1. **不要な人の除外(スタック)**: ある人 A がもう一方の人 B より「背が高く、かつ B より遅くまで会議室にいる」なら、
   B がいてもいなくても答えは変わらない。この関係をスタックで O(N) 処理すると、
   残った人たちは身長について降順・退出時刻について昇順という単調性を同時に満たすようになる。
2. **二分探索**: 退出時刻でソート済みの配列に対し、クエリ時刻 T に `upper_bound` をかけて
   「T より後に退出する人」の先頉インデックスを求め、そこから右側(退出時刻がより遅い側)の
   身長の最大値を答える。
3. 計算量は O(N + Q log N)。

補足: 実装上は、スタックで不要な人を除外しなくても、
「退出時刻 L の昇順にソートしたうえで身長 H の**接尾辞最大値(suffix max)**を前計算する」
だけで同じ答えが得られる(支配されている人がいても suffix max がその情報を自然に吸収するため)。
今回のAC版はこちらのシンプルな方法で実装した。

## 詰まったポイント
- 最初は「身長であらかじめソートしよう」としてしまったが、そもそも二分探索は
  **クエリと同じ軸(退出時刻 L)でソートされた配列**に対して行う必要がある。
  身長でソートすると、L の単調性が崩れて `upper_bound` が使えなくなる。
- WAの直接の原因は、提出コード(`main.cpp`)が **H・Lの組を一切ソートしていない** まま
  `upper_bound(L.begin(), L.end(), query)` を呼んでいたこと。
  `upper_bound` は対象範囲がソート済みであることが前提のため、入力順のままではそもそも正しく動作しない。
  → 退出時刻 L の昇順に (L, H) の組をソートし、そのソート後の配列で
    suffix max(H) を計算してから二分探索する必要がある。

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
    vector<pair<long long, long long>> HL(n); // (L, H) の順で持つ = Lでソートしやすくする
    for (int i = 0; i < n; i++)
    {
        long long h, l;
        cin >> h >> l;
        HL[i] = {l, h};
    }

    // 退出時刻 L の昇順にソート
    sort(HL.begin(), HL.end());

    vector<long long> Lsorted(n);
    vector<long long> highest(n + 1, 0);
    for (int i = 0; i < n; i++) Lsorted[i] = HL[i].first;
    for (int i = n - 1; i >= 0; i--)
    {
        // ソート後の i 番目以降(=退出時刻がより遅い人たち)の身長の最大値
        highest[i] = max(HL[i].second, highest[i + 1]);
    }

    int q;
    cin >> q;
    while (q > 0)
    {
        q--;
        long long query;
        cin >> query;
        // 退出時刻が query より後の人の中で最初の位置を二分探索
        int ans = upper_bound(Lsorted.begin(), Lsorted.end(), query) - Lsorted.begin();
        cout << highest[ans] << "\n";
    }
    return 0;
}
```

サンプル1で動作確認済み(出力が `sample-1-expected.txt` と一致)。