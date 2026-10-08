#include "app.h"
#include "Guitar.h"
#include <stdio.h>

#include "spike/pup/ultrasonicsensor.h"
#include "spike/pup/forcesensor.h"
#include "spike/hub/speaker.h"

static pup_device_t *fg_ultrasonic_sensor;
static pup_device_t *fg_force_sensor;

void Guitar_Configure(pbio_port_id_t ultrasonic_sensor_port, pbio_port_id_t force_sensor_port)
{

  /* センサー入力ポートの設定 */
  fg_ultrasonic_sensor = pup_ultrasonic_sensor_get_device(ultrasonic_sensor_port);
  fg_force_sensor      = pup_force_sensor_get_device(force_sensor_port);

  /* TODO: ここでスピーカーの音量を設定する(hub_speaker_set_volume) */

}


/* ギタータスク(10msec周期で関数コールされる) */
void guitar_task(intptr_t unused) {

    /* TODO: ここで距離センサーから、弦を押さえているパーツまでの距離を取得する
             (pup_ultrasonic_sensor_distance) */

    /* TODO: ここで取得した距離を音程(周波数)に変換する
             (speaker.h の NOTE_C4 などの定義が利用できる) */

    /* TODO: ここでフォースセンサーの押下状態を取得する
             (pup_force_sensor_touched / pup_force_sensor_pressed / pup_force_sensor_force) */

    /* TODO: ここで押下されていれば、内蔵スピーカーから音を鳴らす
             (hub_speaker_play_tone) */

    /* TODO: ここで離されていれば、音を止める
             (hub_speaker_stop) */

    /* タスク終了 */
    ext_tsk();
}
