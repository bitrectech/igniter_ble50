 # <font face="Black Italic">__igniter_ble50__</font>

[![BLE5](https://img.shields.io/badge/%E6%94%AF%E6%8C%81-BLE5-blue)](BLE5)
[![chip](https://img.shields.io/badge/chip-esp32__c3-blue)](chip)
[![distance](https://img.shields.io/badge/BLE5理论距离-300M-BrightGreen?style=flat)](distance)
[![license](https://img.shields.io/badge/License-GLPv3-orange)](LICENSE)
[![version](https://img.shields.io/badge/Version-1.0.0-color=Green?style=flat)](version)
[![standard-readme
compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/Igniter.png?raw=true" width="60" alt="logo" /> 


安卓蓝牙远程点火装置,应用于模型火箭的点火操作,这是蓝牙端源码，基于ESP32-C3(架构为riscv32)。

安卓端原理源码[点击这里](https://github.com/bitrefactor/igniterBiu)

切换语言语言 [English](https://github.com/bitrefactor/igniter_ble50/blob/master/README_en.md)

<html>
    <table style="margin-left: auto; margin-right: auto;">
        <tr>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/serial_port_display.png" width="200" alt="serial_port_display" />
            </td>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/oscilloscope_display.png" width="200" alt="oscilloscope_display" />
            </td>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/actual_effect.png" width="200" alt="actual_effect" />
            </td>
        </tr>
    </table>
</html>

## 目录
  - [目录](#目录)
  - [设计初衷](#设计初衷)
  - [原理](#原理)
  - [制作](#制作)
  - [用法](#用法)
  - [许可证](#许可证)


## 设计初衷

模型火箭的点火时,为了保障安全,通常要保证和模型火箭有足够的安全距离,并且有线部署比较繁琐。离线为最佳的选择。为什么不选择wifi？使用wifi的情境下，手机作为客户端连接点火装置,这样会导致手机的网络受限；而手机作为热点，点火装置端配网操作比较繁琐；为什么选择蓝牙？蓝牙低功耗版本5支持300m以内的连接，连接比较简易。

## 原理

#### 利用蓝牙通信+N沟道MOS实现小电流控制大电流实现控制镍铬合金加热引燃火柴; VIEW->原理图

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/IgniterBLE50_Principle.png" width="400" alt="IgniterBLE50_Principle" />

```
1.为什么无法点不燃火柴？
答：镍铬合金通过的电流太小，无法让镍铬合金加热到火柴的燃点。

2.如何断开和手机端的连接？
答：只需要按下开发板上的reset按键即可。
```
## 制作

1.准备材料\
&nbsp;  esp32-c3-mini-1开发板\*1；\
&nbsp;  5\*7洞洞板\*1；\
&nbsp;  鳄鱼夹\*2(红黑)；\
&nbsp;  A2SHB(N沟道mos管)；\
&nbsp;  电池（3.7v）\*1+充电板;\
&nbsp;  镍铬合金0.1mm一卷；\
&nbsp;  杜邦线若干；\
&nbsp;  24AWG电线；

&nbsp; __物料图：__

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/material_science.png" width="800" alt="material_science.png" />

2.点火头制作 \
&nbsp; 截取2-3cm的镍铬合金缠绕在火柴上，用透明胶或者热熔胶固定。
&nbsp; 

3.电路焊接 \
&nbsp; 按照原理图焊接，注意在点火线路中使用24AWG的电线以保证电流足够可以使镍铬合金加热至火柴的燃点。

4.开发环境 \
&nbsp; 开发环境以来于 __ESP-IDF__ ,所以先搭建环境，参考[《乐鑫 ESP-IDF VS Code 插件快速操作指南》](https://zhuanlan.zhihu.com/p/345381824)

5.下载编译 

```
git clone https://github.com/bitrefactor/igniter_ble50.git
```

6.按照官方教程进行编译下载即可。

## 用法 
1.在安卓APP中连接到设备；点击Fire按钮，设备接收到"fire"单词，就会触发1秒钟的开启mos电流

2.代码说明
``` c
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
    set_gpio(GPIO_OUTPUT_IO_0);  //初始化输出管脚 GPIO_OUTPUT_IO_0定义为18
    set_lifecycle(write_event_monitor); //回调函数传入蓝牙的生命周期事件
}

```

## 许可证

[GNU General Public License v3.0 ](../LICENSE)

