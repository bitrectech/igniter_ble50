#include "include/igniter_gpio_controller.h"
#include "driver/gpio.h"

//初始化引脚
void set_gpio(int output_gpio) {

    int GPIO_OUTPUT_PIN_SEL = (1ULL << output_gpio);

    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
}