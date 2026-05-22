
#include <lvgl.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "ui/ui.h"               // UI export từ EEZ Studio

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST); // Software SPI

// LVGL v9 flush callback

void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) {
    uint16_t w = area->x2 - area->x1 + 1;
    uint16_t h = area->y2 - area->y1 + 1;
    tft.startWrite();
    tft.drawRGBBitmap(area->x1, area->y1, (uint16_t *)px_map, w, h);
    tft.endWrite();
    lv_display_flush_ready(disp);
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    tft.init(240, 320);
    tft.setRotation(0);
    tft.fillScreen(ST77XX_BLACK);

    lv_init();

    // Tạo buffer cho LVGL
    static lv_color_t buf1[240 * 10];
    lv_display_t *disp = lv_display_create(240, 320);
    lv_display_set_flush_cb(disp, my_disp_flush);
    lv_display_set_buffers(disp, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    // --- Load EEZ UI ---
    ui_init();

}

uint32_t lastTick = 0;

void loop() {
   uint32_t now = millis();
  lv_tick_inc(now - lastTick);
  lastTick = now;

  lv_timer_handler();
  ui_tick(); // EEZ Flow update

  delay(1); // giảm delay để UI mượt hơn
}
