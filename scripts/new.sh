#!/usr/bin/env bash
# 新しい問題のフォルダを作成し、テンプレートをコピーする。
# サンプル入出力はAtCoderのページから手動でコピペして配置する運用を前提にしている。
#
# 使い方:
#   ./scripts/new.sh <contest_id> <problem_letter>
# 例:
#   ./scripts/new.sh abc300 a

set -e

CONTEST=$1
PROBLEM=$2

if [ -z "$CONTEST" ] || [ -z "$PROBLEM" ]; then
  echo "Usage: $0 <contest_id> <problem_letter>"
  echo "Example: $0 abc300 a"
  exit 1
fi

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DIR="$ROOT_DIR/problems/$CONTEST/$PROBLEM"
mkdir -p "$DIR"

touch "$DIR/sample-1.txt" "$DIR/sample-1-expected.txt"
echo "Created $DIR/sample-1.txt"
echo "Created $DIR/sample-1-expected.txt"

if [ ! -f "$DIR/main.cpp" ]; then
  cp "$ROOT_DIR/templates/main.cpp" "$DIR/main.cpp"
  echo "Created $DIR/main.cpp"
else
  echo "$DIR/main.cpp already exists, skipping"
fi

echo ""
echo "Done. 次の手順で進めてください:"
echo "  1. https://atcoder.jp/contests/${CONTEST}/tasks/${CONTEST}_${PROBLEM} を開く"
echo "  2. 入力例1を ${DIR}/sample-1.txt に貼り付ける"
echo "  3. 出力例1を ${DIR}/sample-1-expected.txt に貼り付ける"
echo "     (入力例・出力例が複数あれば sample-2.txt, sample-2-expected.txt ... と続ける)"
echo "     ※sample-1.txt と sample-1-expected.txt は空ファイルとして作成済みです"
echo "  4. ${DIR}/main.cpp に解法を書く"
echo "  5. ./scripts/test.sh ${CONTEST} ${PROBLEM} でテストする"
