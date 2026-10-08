# electric-guitar

[RasPike-ART](https://github.com/ETrobocon/RasPike-ART) を使って、LEGO® SPIKE™ Prime で組み立てた「エレキギター」を演奏するためのプログラムを開発するリポジトリです。

## 概要

SPIKE Prime の部品で組み立てたギター型の楽器を、Raspberry Pi 上で動くプログラムから制御します。

- **左手（音程）**: 距離センサー（超音波センサー）で、弦を押さえるパーツとセンサーの距離を測定し、その距離に応じて音程を決めます。
- **右手（発音）**: フォースセンサー（圧力センサー）を押して、音を出すタイミングと長さ（間）を調整します。
- **音の出力**: SPIKE ハブの内蔵スピーカーから音を鳴らします。

## システム構成

```mermaid
flowchart LR
    subgraph RPi["Raspberry Pi 4"]
        App["本リポジトリのプログラム<br/>（RasPike-ART）"]
    end
    subgraph Hub["SPIKE Prime ハブ"]
        Lib["libraspike-art<br/>（SPIKE-RT）"]
        Speaker["内蔵スピーカー"]
    end
    Dist["距離センサー<br/>（音程）"]
    Force["フォースセンサー<br/>（発音タイミング）"]
    App <-- "USB" --> Lib
    Dist --> Lib
    Force --> Lib
    Lib --> Speaker
```

RasPike-ART は、Raspberry Pi 側の EV3RT 互換環境（TOPPERS/ASP3 ベース）と、SPIKE 側の受信ソフトウェア [libraspike-art](https://github.com/ETrobocon/libraspike-art)（SPIKE-RT 製）で構成されています。Raspberry Pi 側のプログラムから SPIKE-RT と同じ API でセンサーやハブのスピーカーを利用できます。

### 使用機材

| 機材 | 用途 |
| --- | --- |
| Raspberry Pi 4（Raspberry Pi OS 64bit） | プログラムの実行環境 |
| LEGO SPIKE Prime ハブ | センサー接続、音の出力（内蔵スピーカー） |
| LEGO SPIKE 距離センサー | 弦を押さえるパーツまでの距離の測定（音程） |
| LEGO SPIKE フォースセンサー | 発音のタイミング・長さの入力 |
| USB ケーブル | Raspberry Pi と SPIKE の接続（**充電専用ケーブルは不可**） |

### ポート割り当て

| ポート | デバイス |
| --- | --- |
| TBD | 距離センサー |
| TBD | フォースセンサー |

※ 組み立て後に確定します。

## 開発環境のセットアップ

詳細は [RasPike-ART の README](https://github.com/ETrobocon/RasPike-ART) を参照してください。概要は以下のとおりです。

1. Raspberry Pi 上で RasPike-ART を取得します（`--recursive` を忘れずに）。

   ```bash
   git clone --recursive https://github.com/ETrobocon/RasPike-ART.git
   cd RasPike-ART/sdk/workspace
   ```

2. SPIKE への書き込み環境をセットアップします（初回のみ）。

   ```bash
   make -f ../common/Makefile.raspike-art setup_spike_env
   ```

3. SPIKE を DFU モードにして、SPIKE 側のプログラムを書き込みます。

   ```bash
   make -f ../common/Makefile.raspike-art update_spike
   ```

## ビルドと実行

> 本リポジトリのプログラムは現在開発中です。ディレクトリ構成やビルド手順は実装に合わせて更新します。

RasPike-ART では `sdk/workspace` 配下のアプリケーションを次のようにビルド・実行します。

```bash
make img=<アプリケーション名>
make start
```

実行手順:

1. SPIKE のセンターボタンを押して電源を入れ、「∞」マークが表示された状態にします。
2. Raspberry Pi 側で `make start` を実行します。
3. 停止するときは `Ctrl+C` を押し、SPIKE のセンターボタンを長押しして電源を切ります。

## ロードマップ

- [ ] ギター本体の組み立て
- [ ] ポート割り当ての確定
- [ ] 距離センサーの値と音程の対応づけ（キャリブレーション）
- [ ] フォースセンサーによる発音制御
- [ ] 内蔵スピーカーでの演奏

## 謝辞・参考

- [ETrobocon/RasPike-ART](https://github.com/ETrobocon/RasPike-ART) — Raspberry Pi 用 SPIKE 制御開発環境
- [ETrobocon/libraspike-art](https://github.com/ETrobocon/libraspike-art) — SPIKE 側の受信ソフトウェア
- [20+ Amazing LEGO SPIKE Robots You Can Actually Build（Prof. Bricks）](https://youtu.be/C_P3nNl0XQo?t=530) — SPIKE で作れるギターの紹介
- [SPIKEGuitar building instructions（Coder Shah）](https://www.youtube.com/watch?v=HkK7VRdXLWE) — SPIKE Prime 基本セット（45678）で作るギターの組み立て手順。Daniele Benedettelli 氏設計の LEGO MINDSTORMS EV3 ギターがベースになっています。

LEGO、SPIKE、MINDSTORMS は LEGO Group の商標です。本リポジトリは LEGO Group とは関係ありません。
