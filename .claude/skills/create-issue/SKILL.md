---
name: create-issue
description: このリポジトリでGitHub issueを作成するときのルール。issueの起票・タスクの登録を頼まれたときに使う。
---

# issueを作成する

## ルール

- **タイトル**: 言い切りの用言止めにする（例: 「距離に応じて音程が変わる」）。
- **本文**: [.github/ISSUE_TEMPLATE/default.md](../../../.github/ISSUE_TEMPLATE/default.md) の構成で、しっかり書く。
  - 先頭の `---` で囲まれた部分（GitHub用の設定）は本文に含めない。
  - `{issue名}` はタイトルに置き換える。
  - 各項目の説明文は内容に置き換える。
  - 冒頭の「※」の注意書きと、使わない（Opt.）項目は削除する。
- **ラベル**: 既存のラベルから適切なものを選ぶ（`gh label list`）。該当がなければ付けない。
- **マイルストーン**: 既存のマイルストーンから適切なものを選ぶ（`gh api repos/{owner}/{repo}/milestones`）。該当がなければ付けない。
- **担当者**: 指定がなければ自分（`@me`）にする。

## 手順

```bash
gh issue create --title "<タイトル>" --body-file <本文ファイル> --label "<ラベル>" --milestone "<マイルストーン>" --assignee @me
```
