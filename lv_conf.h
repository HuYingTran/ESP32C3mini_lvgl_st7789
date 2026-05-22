/* Minimal LVGL configuration for ESP32 + ST7789 */
#ifndef LV_CONF_H
#define LV_CONF_H

#define LV_COLOR_DEPTH          16
#define LV_HOR_RES_MAX          240
#define LV_VER_RES_MAX          320
#define LV_TICK_CUSTOM          0
#define LV_MEM_CUSTOM           0
#define LV_USE_LOG              1
#define LV_USE_LABEL            1
#define LV_USE_BTN              1
#define LV_USE_DISPLAY_BUF      1
#define LV_USE_DRAW_SW          1
#define LV_USE_THEME_DEFAULT    1
#define LV_USE_FS_STDIO         0
#define LV_USE_FS_POSIX         0
#define LV_USE_FS_WIN32         0
#define LV_USE_FS_FATFS         0
#define LV_USE_FS_LITTLEFS      0

#endif // LV_CONF_H
