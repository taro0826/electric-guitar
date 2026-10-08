#ifdef __cplusplus
extern "C" {
#endif

/* 下記の項目は組み立てたギターに合わせて変えること */

/* TODO: 距離センサーの測定範囲(音程に割り当てる距離の下限・上限)を定義する */

/* TODO: 発音とみなすフォースセンサーの押下しきい値を定義する */

/* TODO: スピーカーの音量を定義する */

#include "pbio/port.h"  

  extern void Guitar_Configure(pbio_port_id_t ultrasonic_sensor_port, pbio_port_id_t force_sensor_port);
  
#ifdef __cplusplus
}
#endif
