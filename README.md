 # <font face="Black Italic">__igniter_ble50__</font>

[![BLE5](https://img.shields.io/badge/%E6%94%AF%E6%8C%81-BLE5-blue)](BLE5)
[![chip](https://img.shields.io/badge/chip-esp32__c3-blue)](chip)
[![distance](https://img.shields.io/badge/BLE5理论距离-300M-BrightGreen?style=flat)](distance)
[![license](https://img.shields.io/badge/License-GLPv3-orange)](LICENSE)
[![version](https://img.shields.io/badge/Version-1.0.0-color=Green?style=flat)](version)
[![standard-readme
compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

<img src="https://github.com/bitrefactor/igniter_ble50/blob/master/.image/Igniter.png?raw=true" width="60" alt="logo" /> 


安卓蓝牙远程点火装置,应用于模型火箭的点火操作,这是蓝牙端源码，基于ESP32-C3(架构为riscv32)。安卓端原理源码[点击这里](https://github.com/bitrefactor/igniterBiu)

其他语言 [English](https://github.com/bitrefactor/igniter_ble50/blob/master/README_en.md)

<html>
    <table style="margin-left: auto; margin-right: auto;">
        <tr>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/serial_port_display.jpg" width="200" alt="serial_port_display" />
            </td>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/oscilloscope_display.jpg" width="200" alt="oscilloscope_display" />
            </td>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/actual_effect.jpg" width="200" alt="actual_effect" />
            </td>
        </tr>
    </table>
</html>

## 目录
  - [目录](#目录)
  - [权限](#权限)
  - [设计初衷](#设计初衷)
  - [安装](#安装)
  - [用法](#用法)
  - [原理](#原理)
  - [许可证](#许可证)

## 权限

#### 定位权限、蓝牙权限说明

## 设计初衷

模型火箭的点火时,为了保障安全,通常要保证和模型火箭有足够的安全距离,并且有线部署比较繁琐。离线为最佳的选择。为什么不选择wifi？使用wifi的情境下，手机作为客户端连接点火装置,这样会导致手机的网络受限；而手机作为热点，点火装置端配网操作比较繁琐；为什么选择蓝牙？蓝牙低功耗版本5支持300m以内的连接，连接比较简易。

## 安装
## 用法


## 原理

## 许可证

[GNU General Public License v3.0 ](../LICENSE)

