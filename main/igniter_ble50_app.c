#include "driver/gpio.h"
#include "esp_gatts_api.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "include/igniter_ble_lifecycle.h"
#include "include/igniter_gpio_controller.h"

#define GPIO_OUTPUT_IO_0 18

#define IGNITION_CMD "fire"

const char *hex2string(const void *buffer, uint16_t buff_len) {
    char temp_buffer[16 + 3];
    char char_buffer[16 + 1];
    const char *ptr_line;
    int bytes_cur_line;
    do {
        if (buff_len > 16) {
            bytes_cur_line = 16;
        } else {
            bytes_cur_line = buff_len;
        }
        if (!esp_ptr_byte_accessible(buffer)) {
            // use memcpy to get around alignment issue
            memcpy(temp_buffer, buffer, (bytes_cur_line + 3) / 4 * 4);
            ptr_line = temp_buffer;
        } else {
            ptr_line = buffer;
        }
        for (int i = 0; i < bytes_cur_line; i++) {
            sprintf(char_buffer + i, "%c", ptr_line[i]);
        }
        buffer += bytes_cur_line;
        buff_len -= bytes_cur_line;
    } while (buff_len);
    return ptr_line;
}

void write_event_monitor(esp_ble_gatts_cb_param_t *param) {
    const char *ptr_line = hex2string(param->write.value,param->write.len);
    //解析指令
    if (strcmp(ptr_line, IGNITION_CMD) == 0) {
        ESP_LOGI(GATTS_TABLE_TAG, "FIRE_CMD:%s", ptr_line);
        gpio_set_level(GPIO_OUTPUT_IO_0, 1);
        vTaskDelay(300);
        gpio_set_level(GPIO_OUTPUT_IO_0, 0);
    }else {
        ESP_LOGI(GATTS_TABLE_TAG, "CMD:%s", ptr_line);
    }
}

void app_main(void) {
    set_gpio(GPIO_OUTPUT_IO_0);
    set_lifecycle(write_event_monitor);
}
