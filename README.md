# competitive-programming

AtCoder × C++ のコーディングテスト対策用リポジトリ。

## ディレクトリ構成

```
competitive-programming/
├── templates/
│   └── main.cpp          # 新規問題用のC++テンプレート
├── scripts/
│   ├── new.sh            # 新規問題フォルダ作成
│   ├── test.sh           # サンプルケースでの自動テスト
│   └── log_add.sh        # 振り返りログの記録
├── lib/                  # 自分用ライブラリ(コピペ用スニペット)
│   ├── union_find.hpp
│   ├── segment_tree.hpp
│   └── dijkstra.hpp
├── problems/
│   ├── _example/a/       # 動作確認用のサンプル問題(A+B問題)
│   └── <contest_id>/<problem_letter>/
│       ├── main.cpp
│       ├── sample-1.txt
│       └── sample-1-expected.txt
└── log/
    └── log.csv           # 振り返りログ
```

問題は `problems/<contest_id>/<problem_letter>/` というルールで配置する。
例: ABC300のA問題 → `problems/abc300/a/`

## セットアップ

```bash
# C++コンパイラ (通常は最初から入っている)
g++ --version
```

サンプル入出力はAtCoderの問題ページから手動でコピペして配置する運用にしている

### macOSの場合の注意
macOSの `g++` は実体が Apple Clang のラッパーで、GNU専用の `bits/stdc++.h` が使えない。
AtCoderの採点環境は本物のGCCなので、Homebrewで本物のGCCを入れて使うのがおすすめ。

```bash
brew install gcc
ls /opt/homebrew/bin/g++-*   # 例: g++-16 のようにバージョン番号付きで入る
```

`test.sh` は `CXX` 環境変数で使うコンパイラを切り替えられるので、シェルの設定ファイル
(`~/.zshrc` など)に以下を追記しておくと毎回指定せずに済む。

```bash
export CXX=g++-16   # 実際にインストールされたバージョンに合わせる
```

## 使い方

### 1. 新しい問題を始める

```bash
./scripts/new.sh abc300 a
```

`problems/abc300/a/main.cpp` が作成され、次にやることが表示される。

### 2. サンプルケースを手動で配置する

表示されたURL(例: `https://atcoder.jp/contests/abc300/tasks/abc300_a`)を開き、

- 入力例1 → `problems/abc300/a/sample-1.txt`
- 出力例1 → `problems/abc300/a/sample-1-expected.txt`

にそれぞれ貼り付ける。入力例・出力例が複数ある場合は `sample-2.txt` / `sample-2-expected.txt` ...
と番号を増やしていく。

### 3. サンプルケースでテストする

```bash
./scripts/test.sh abc300 a
```

`main.cpp` をコンパイルし、`sample-*.txt` を全部入力として実行、
対応する `sample-*-expected.txt` と出力を比較して PASS/FAIL を表示する。

動作確認用に `_example/a` というサンプル問題(A+B問題)を用意しているので、
まずはこれで試すとよい:

```bash
./scripts/test.sh _example a
```

### 4. 解いたら振り返りを記録する

```bash
./scripts/log_add.sh
```

対話形式で以下を入力すると `log/log.csv` に1行追加される。

| 項目 | 説明 |
|---|---|
| date | 自動で今日の日付が入る |
| contest / problem | コンテストID・問題 |
| result | AC / WA / TLE / RE / CE / giveup など |
| time_minutes | かかった時間(分) |
| tags | 使ったアルゴリズム・分野(dp, graph, greedy 等。カンマ区切り) |
| review | 後で復習すべきか (y/n) |
| notes | 自由記述メモ(詰まった点、学んだことなど) |

ログが溜まってきたら、Excelやpandasなどで `tags` 別の正答率や `review=y` の問題を
集計すると、自分の苦手分野が見えてくる。

### 5. ライブラリを使う

`lib/` 以下のヘッダーは `main.cpp` から直接 include して使える。

```cpp
#include <bits/stdc++.h>
#include "union_find.hpp"
using namespace std;

int main() {
    UnionFind uf(10);
    uf.unite(1, 2);
    // ...
}
```

コンパイル時に `lib/` をインクルードパスに追加しているので、`test.sh` 経由で実行すれば
そのまま動く(`-I lib` を付けてコンパイルしている)。手元で直接 `g++` する場合は
`g++ -I lib problems/abc300/a/main.cpp` のように指定する。

## 運用の流れ(おすすめ)

1. `./scripts/new.sh <contest> <letter>` で問題フォルダを作る
2. AtCoderの問題ページからサンプル入出力を `sample-1.txt` / `sample-1-expected.txt` にコピペする
3. `main.cpp` に解法を書く
4. `./scripts/test.sh <contest> <letter>` でサンプルが通るか確認
5. 通ったら(または諦めたら) `./scripts/log_add.sh` で振り返りを記録
6. 週末などにまとめて `log/log.csv` を見返し、`review=y` の問題やタグ別の傾向を確認する
