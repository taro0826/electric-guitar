---
name: create-pull-request
description: このリポジトリでPull Requestを作成するときのルール。作業ブランチの変更をPRにするときに使う。
---

# PRを作成する

## ルール

- **タイトル**: 接頭辞・接尾辞を付けず、言い切りの用言止めにする。
  - 開発者の作業（「〜を実装する」「〜を開発する」）ではなく、その変更で何が達成されるかを書く。
  - 例: 「フォースセンサーを押している間だけ音が鳴る」
- **本文**: [.github/pull_request_template.md](../../../.github/pull_request_template.md) の構成で書く。
  - `{PR名}` はタイトルに置き換える。
  - 各項目の説明文は内容に置き換える。
  - 冒頭の「※」の注意書きと、使わない項目は削除する。
  - 関連するissueがあれば「目的」の末尾に `#<番号>` を書く。なければ書かなくてよい。
- **ビルド確認**: PRを出す前に、Raspberry Piの `sdk/workspace` で `make img=electric-guitar` が通ることを確認する。確認できなかった場合は「動作確認方法」にそう書く。
- **ラベル**: 付けない。
- **担当者**: 自分（`@me`）にする。
- **レビュアー**: 指定された開発者にする。空欄にしない。
  - 指定がない場合は自分にしたいが、GitHubではPRの作成者をレビュアーにできない。そのため、作成前にユーザーにレビュアーを確認する。

## 手順

```bash
git push -u origin HEAD
gh pr create --base main --title "<タイトル>" --body-file <本文ファイル> --assignee @me --reviewer <レビュアー>
```
