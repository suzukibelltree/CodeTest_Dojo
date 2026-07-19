#!/usr/bin/env bash
# 解けなかった問題の reference.md (公式解説の貼り付け先) を用意する。
# 中身を埋めたら、Claude Codeなどに
#   「<contest> <problem> の解説をまとめて」
# と依頼すると reference.md をもとに explanation.md が生成できる。
#
# 使い方:
#   ./scripts/explain.sh <contest_id> <problem_letter>
# 例:
#   ./scripts/explain.sh abc447 b

set -e

CONTEST=$1
PROBLEM=$2

if [ -z "$CONTEST" ] || [ -z "$PROBLEM" ]; then
  echo "Usage: $0 <contest_id> <problem_letter>"
  echo "Example: $0 abc447 b"
  exit 1
fi

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIR="$ROOT_DIR/problems/$CONTEST/$PROBLEM"
REF="$DIR/reference.md"

if [ ! -d "$DIR" ]; then
  echo "Error: $DIR not found (先に new.sh で問題を作成してください)"
  exit 1
fi

if [ -f "$REF" ]; then
  echo "$REF はすでに存在します。スキップします。"
else
  cat > "$REF" <<EOF
# ${CONTEST} ${PROBLEM} 解説の材料

## 公式解説
<!-- 解説PDF/スライドのURL、または解説の要点をここに貼り付ける -->
URL: https://atcoder.jp/contests/${CONTEST}/editorial

## 解き直し後のACコード
<!-- 解けなかった場合、後で解き直してACしたコードをここに貼る (無ければ空でOK) -->

\`\`\`cpp
\`\`\`

## 詰まったポイント
<!-- log.csv の notes と合わせて、何が分からなかったかを書いておくとAIが要点をまとめやすい -->
EOF
  echo "Created $REF"
fi

echo ""
echo "次の手順で進めてください:"
echo "  1. ${REF} に公式解説のURL/内容、必要なら解き直し後のACコードを貼り付ける"
echo "  2. Claude Codeなどに「${CONTEST} ${PROBLEM} の解説をまとめて」と依頼する"
echo "     -> reference.md と main.cpp、log.csv の notes を踏まえて"
echo "        ${DIR}/explanation.md に解法のポイントが生成される"
echo "  3. log/log.csv の該当行の explanation_path 列に"
echo "     problems/${CONTEST}/${PROBLEM}/explanation.md を記入する"
