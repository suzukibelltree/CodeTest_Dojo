#!/usr/bin/env bash
# サンプル入出力でコンパイル＆自動テストを行う。
#
# 使い方:
#   ./scripts/test.sh <contest_id> <problem_letter>
# 例:
#   ./scripts/test.sh abc300 a
#
# サンプルファイルの命名規則:
#   sample-1.txt           入力
#   sample-1-expected.txt  期待される出力

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
SRC="$DIR/main.cpp"
BIN="$DIR/main"

if [ ! -f "$SRC" ]; then
  echo "Error: $SRC not found"
  exit 1
fi

echo "Compiling $SRC ..."
CXX="${CXX:-g++}"
"$CXX" -std=gnu++20 -O2 -Wall -I "$ROOT_DIR/lib" -o "$BIN" "$SRC"

PASS=0
FAIL=0
FOUND_ANY=0

for infile in "$DIR"/sample-*.txt; do
  [[ -e "$infile" ]] || continue
  case "$infile" in
    *-expected.txt) continue ;;
  esac

  FOUND_ANY=1
  base=$(basename "$infile" .txt)
  expected="$DIR/${base}-expected.txt"

  if [ ! -f "$expected" ]; then
    echo "[SKIP] $base (期待される出力ファイルがありません)"
    continue
  fi

  actual=$("$BIN" < "$infile")
  expected_content=$(cat "$expected")

  if [ "$actual" == "$expected_content" ]; then
    echo "[PASS] $base"
    PASS=$((PASS+1))
  else
    echo "[FAIL] $base"
    echo "  --- expected ---"
    echo "$expected_content" | sed 's/^/  /'
    echo "  --- got ---"
    echo "$actual" | sed 's/^/  /'
    FAIL=$((FAIL+1))
  fi
done

if [ $FOUND_ANY -eq 0 ]; then
  echo "サンプルファイルが見つかりませんでした ($DIR/sample-*.txt)"
  exit 1
fi

echo ""
echo "Result: $PASS passed, $FAIL failed"

if [ $FAIL -gt 0 ]; then
  exit 1
fi
