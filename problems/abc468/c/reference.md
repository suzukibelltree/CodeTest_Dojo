# abc468 c 解説の材料

## 問題概要
整数 N と、(1,2,…,N) を並び替えた2つの順列 P, Q が与えられる。
「(1,2,…,N) の順列 X であって、辞書順で **P < X < Q**」を満たすものの個数を求める。

- N ≤ 10（この小ささが「全順列を試せる」というヒント）
- 入力: `N` / `P_1 ... P_N` / `Q_1 ... Q_N`

## 公式解説
URL: https://atcoder.jp/contests/abc468/editorial/23508

### 想定解法（全探索）
N ≤ 10 なので、(1,2,…,N) の順列は最大でも `10! = 3,628,800` 通りしかない。これを**全部列挙して**、各順列 X について `P < X < Q` を満たすかどうかを O(N) で判定すればよい。全体で **O(N! × N)** で、この制約なら十分間に合う。

C++ では `next_permutation` を使うと、昇順の配列 `1,2,...,N` から出発して重複なく全ての順列を辞書順に生成できる。さらに `vector<int>` 同士は `<` 演算子で辞書式比較がそのままできるので、`p < a && a < q` の1行で判定できる。

### 実装手順
1. N, P, Q を読み込む
2. `a = {1,2,...,N}` を作る（`iota` で初期化）
3. `do { 判定 } while (next_permutation(a.begin(), a.end()));` で全順列を回す
4. `p < a && a < q` を満たすたびにカウント
5. カウントを出力

## 現状のコードについて
`main.cpp` は入力を読むところまでで、`ans` を実際に数える処理（順列を列挙するループ）がまだ書かれていない（`ans` は 0 のまま出力もされていない）。log.csv の note「N!通りを試す実装方法が分からない」の通り、`next_permutation` を使った全順列列挙のパターンがそのまま次のカギになる。

## 解き直し後のACコード
サンプル1（N=7, P=`3 6 5 2 7 1 4`, Q=`4 1 5 7 2 3 6` → 期待値 `223`）で一致を確認済み。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto &x : p) cin >> x;
    for (auto &x : q) cin >> x;

    vector<int> a(n);
    iota(a.begin(), a.end(), 1); // a = {1, 2, ..., n}

    long long ans = 0;
    do
    {
        if (p < a && a < q) // vector同士は辞書式比較できる
            ans++;
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << endl;
    return 0;
}
```

## 詰まったポイント
- N!通りを試す実装方法が分からない
  → C++では `next_permutation(a.begin(), a.end())` を `do-while` で回すのが定番パターン。`a` を昇順に初期化してから呼び始めると、辞書順で全ての順列を重複なく列挙できる。
  → 順列同士の大小比較は `vector<int>` の `<` 演算子（辞書式比較）がそのまま使える。
