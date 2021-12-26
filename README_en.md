# <font face="Black italic"> __igniter_ble50__ </font>

[![Ble5](https://img.shields.io/badge/Support-ble5-blue)](ble5)
[![chip](https://img.shields.io/badge/chip-esp32__c3-blue)](CHIP)
[![distance](https://img.shields.io/badge/_theoretical_distance_300m-brightgreen)](distance)
[![license](https://img.shields.io/badge/license-glpv3-orange)](license)
[![Version](https://img.shields.io/badge/version-1.0.0-color=green?style=flat)](Version)
[![standard-readme
compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/Igniter.png?raw=true" width="60" alt="logo" />


Android Bluetooth Remote ignition device, applied to the model rocket ignition operation, this is the Bluetooth source
code based on ESP32-C3 (architecture is RISCV32). Android end principle source code [Click
here](https://github.com/bitrefactor/igniterBiu)

Languages ​​[简体中文](https://github.com/bitrefactor/igniter_ble50/)

<html>
<table style="margin-left: auto; margin-right: auto;">
    <tr>
        <td>
            <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/serial_port_display.png" width="200"
                alt="serial_port_display" />
        </td>
        <td>
            <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/oscilloscope_display.png" width="200"
                alt="oscilloscope_display" />
        </td>
        <td>
            <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/actual_effect.png" width="200"
                alt="actual_effect" />
        </td>
    </tr>
</table>

</html>

## Table of Contents
- [Background](#Background)
- [Principle](#Principle)
- [BuildUP](#BuildUP)
- [Usage](#Usage)
- [license](#license)

## Background

When the model rocket is ignition, in order to ensure safety, it is usually guaranteed to have sufficient safety
distances and model rockets, and wired deployment is more cumbersome. Offline is the best choice. Why not choose WiFi?
Using WiFi situations, the mobile phone is connected to the client to connect the ignition device, which will cause the
mobile phone to be limited; while the phone is used as a hotspot, the ignition device ends the network operation is more
cumbersome; why choose Bluetooth? Bluetooth low-power versions 5 supports connections within 300m, and the connection is
relatively simple.

## Principle

#### Using Bluetooth communication + N-channel MOS to achieve small current control large current to control
nickel-chromium alloy heating ignition match; VIEW-> schematic

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/IgniterBLE50_Principle.png" width="400"
    alt="IgniterBLE50_Principle" />

```
1. Why can't you burn a match?
A: The current of nickel-chromium alloy is too small, and the nickel-chrome alloy is not heated to the burning point of
matches.

2. How to disconnect and the mobile phone connection?
A: I only need to press the RESET button on the development board.
```

## BuildUP

1.Preparing materials\
&nbsp; ESP32-C3-mini-1 development board \* 1; \
&nbsp; 5 \* 7 cave board \* 1; \
&nbsp; Crocodile Clip \* 2 (Red Black); \
&nbsp; A2SHB (N-channel MOS tube); \
&nbsp; Battery (3.7V) \* 1+ charging board; \
&nbsp; Nickel-chrome alloy 0.1mm a volume; \
&nbsp; DuPont lines; \
&nbsp; 24AWG wire;

&nbsp; __Material Diagram:__

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/material_science.png" width="800"
    alt="matial_science.png" />

2. ignite the head to make \
&nbsp; Nickel-chromium alloy intercept 2-3 cm is wound on matches, and secured with transparent glue or hot melt
adhesive.
&nbsp;

3. Circuit welding \
&nbsp; Welding according to the schematic, pay attention to the use of 24AWG wires in the ignition line to ensure that the current is sufficient to heat the nickel-chromium alloy to the combustion point of the match.

4. Development Environment \
& nbsp; Since the development environment, the __esp-idf__, so build the environment first, refer to [" Espressif ESP-IDF VS
Code Plug-in Fast Operation Guide"](https://zhuanlan.zhihu.com/p/345381824)

5. Download compilation

```
git clone https://github.com/bitrefactor/igniter_ble50.git
```

6. Compile and download according to the official tutorial.

## Usage

1. Connect to the device in the Android APP; click the Fire button, the device receives "fire" words, trigger 1 second to open MOS current

2. Code description
```c

#define GPIO_OUTPUT_IO_0 18

#define IGNITION_CMD "fire"

···

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
    set_gpio(GPIO_OUTPUT_IO_0);  //Initialization Output Pin GPIO_OUTPUT_IO_0 is defined as 18
    set_lifecycle(write_event_monitor); //Tune Function Incoming Bluetooth Lifecycle Event
}

```
## License

[GNU General Public License V3.0](../License)
