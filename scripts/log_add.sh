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
  echo "date,contest,problem,result,time_minutes,tags,review,notes,explanation_path" > "$LOG_FILE"
fi

# tags の統制語彙 (README の語彙表と同期させること)
TAG_VOCAB="zentansaku map string sim ruisekiwa nibutan bfs-dfs greedy math sort dp shakutori kisokusei adhoc"

read -rp "Contest ID (例: abc300): " CONTEST
read -rp "Problem letter (例: a): " PROBLEM

# 同じ問題の過去ログがあれば表示し、再挑戦かどうかを確認する
PREV_ENTRIES=$(grep -E "^[0-9-]+,${CONTEST},${PROBLEM}," "$LOG_FILE" || true)
RETRY_PREFIX=""
if [ -n "$PREV_ENTRIES" ]; then
  echo "過去の記録が見つかりました:"
  echo "$PREV_ENTRIES"
  read -rp "これは再挑戦ですか? (y/n): " IS_RETRY
  if [ "$IS_RETRY" = "y" ]; then
    LAST_ENTRY=$(echo "$PREV_ENTRIES" | tail -1)
    LAST_DATE=$(echo "$LAST_ENTRY" | cut -d',' -f1)
    LAST_RESULT=$(echo "$LAST_ENTRY" | cut -d',' -f4)
    RETRY_PREFIX="[retry: ${LAST_DATE} ${LAST_RESULT}] "
  fi
fi

read -rp "Result (AC/WA/TLE/RE/CE/giveup): " RESULT
read -rp "Time spent (minutes): " TIME
echo "Tags 語彙 (複数可・カンマ区切り。再挑戦なら前回と同じタグを使うこと): $TAG_VOCAB"
read -rp "Tags: " TAGS

# tags が統制語彙に含まれているか軽くチェックする(警告のみ、入力は止めない)
IFS=',' read -ra TAG_ARRAY <<< "$TAGS"
for t in "${TAG_ARRAY[@]}"; do
  t_trimmed=$(echo "$t" | xargs)
  [ -z "$t_trimmed" ] && continue
  if ! grep -qw "$t_trimmed" <<< "$TAG_VOCAB"; then
    echo "  ⚠ '$t_trimmed' は語彙表にありません。README の語彙表に合わせるのを推奨します。"
  fi
done

read -rp "Needs review later? (y/n): " REVIEW
read -rp "Notes (任意): " NOTES
NOTES="${RETRY_PREFIX}${NOTES}"
read -rp "Explanation path/URL (任意。まだ無ければ空欄でOK): " EXPLANATION

DATE=$(date +%Y-%m-%d)

# CSV中のダブルクォートをエスケープ
TAGS_ESCAPED=$(echo "$TAGS" | sed 's/"/""/g')
NOTES_ESCAPED=$(echo "$NOTES" | sed 's/"/""/g')
EXPLANATION_ESCAPED=$(echo "$EXPLANATION" | sed 's/"/""/g')

echo "$DATE,$CONTEST,$PROBLEM,$RESULT,$TIME,\"$TAGS_ESCAPED\",$REVIEW,\"$NOTES_ESCAPED\",\"$EXPLANATION_ESCAPED\"" >> "$LOG_FILE"
echo "Logged to $LOG_FILE"
