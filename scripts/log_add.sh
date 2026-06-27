#!/usr/bin/env bash
# 問題を解いた後の振り返りを log/log.csv に記録する。
#
# 使い方:
#   ./scripts/log_add.sh
# 対話形式で入力していくとログが1行追加される。

set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
LOG_FILE="$ROOT_DIR/log/log.csv"

if [ ! -f "$LOG_FILE" ]; then
  echo "date,contest,problem,result,time_minutes,tags,review,notes" > "$LOG_FILE"
fi

read -rp "Contest ID (例: abc300): " CONTEST
read -rp "Problem letter (例: a): " PROBLEM
read -rp "Result (AC/WA/TLE/RE/CE/giveup): " RESULT
read -rp "Time spent (minutes): " TIME
read -rp "Tags (例: dp,graph ※カンマ区切り): " TAGS
read -rp "Needs review later? (y/n): " REVIEW
read -rp "Notes (任意): " NOTES

DATE=$(date +%Y-%m-%d)

# CSV中のダブルクォートをエスケープ
TAGS_ESCAPED=$(echo "$TAGS" | sed 's/"/""/g')
NOTES_ESCAPED=$(echo "$NOTES" | sed 's/"/""/g')

echo "$DATE,$CONTEST,$PROBLEM,$RESULT,$TIME,\"$TAGS_ESCAPED\",$REVIEW,\"$NOTES_ESCAPED\"" >> "$LOG_FILE"
echo "Logged to $LOG_FILE"
