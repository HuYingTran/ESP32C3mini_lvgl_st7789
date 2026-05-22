
#include <lvgl.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

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

    // Example LVGL widget: label with border
    lv_obj_t *cont = lv_obj_create(lv_screen_active());

        lv_obj_set_size(cont, 220, 100); // Tăng kích thước widget
        lv_obj_set_style_border_width(cont, 4, 0);
        lv_obj_set_style_border_color(cont, lv_palette_main(LV_PALETTE_BLUE), 0);
        lv_obj_set_style_pad_all(cont, 20, 0); // Padding lớn hơn

    lv_obj_t *label = lv_label_create(cont);
    lv_label_set_text(label, "Hello LVGL!");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_28, 0); // Tăng size chữ
    lv_obj_center(label);

    lv_obj_center(cont);
}

void loop() {
    lv_timer_handler();
    delay(5);
}
