#include "app.h"
#include <stdio.h>
#include "Guitar.h"

/* センサーポートの定義(組み立て後に実際の接続に合わせて変更すること) */
static const pbio_port_id_t
  ultrasonic_sensor_port = PBIO_PORT_ID_A, /* 距離センサー(音程) */
  force_sensor_port      = PBIO_PORT_ID_B; /* フォースセンサー(発音) */

/* メインタスク(起動時にのみ関数コールされる) */
void main_task(intptr_t unused) {

  /* Guitarに構成を渡す */
  Guitar_Configure(ultrasonic_sensor_port, force_sensor_port);

  /* TODO: 必要であれば、ここで演奏開始の合図を待つ(ハブのボタン押下など) */

  printf("Start Guitar!!\n");

  /* ギタータスクの起動 */
  sta_cyc(GUITAR_TASK_CYC);

  /* タスク終了 */
  ext_tsk();
}
