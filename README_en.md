# <font face="Black italic"> __igniterBLE50__ </font>

[![Ble5](https://img.shields.io/badge/%E6%94%AF%e6%8C%81-ble5-blue)](ble5)
[![chip](https://img.shields.io/badge/chip-esp32__c3-blue)](CHIP)
[![distance](https://img.shields.io/badge/_theoretical_distance_300m-brightgreen)](distance)
[![license](https://img.shields.io/badge/license-glpv3-orange)](license)
[![Version](https://img.shields.io/badge/version-1.0.0-color=green?style=flat)](Version)
[![standard-readme
Compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/richardlitt/standard-readme)

<img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/app/src/main/res/drawable-nodpi/logosoft.png"
    width="100" alt="logo" />

Android Bluetooth Remote ignition device, applied to the model rocket ignition operation, this is the Bluetooth source
code based on ESP32-C3 (architecture is RISCV32). Android end principle source code [Click
here](https://github.com/bitrefactor/igniterBiu)

Other languages ​​[English](https://github.com/bitrefactor/igniter_ble50/)

<html>
<table style="margin-left: auto; margin-right: auto;">
    <tr>
        <td>
            <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.jpg" width="200"
                alt="serial_port_display" />
        </td>
        <td>
            <img src="https://cdn.jsdelivr.net/gh/bitrefactor/igniter_ble50/.image/oscilloscope_display.jpg" Width="200"
                alt="oscilloscope_display" />
        </td>
        <td>
            <img src="https://cdn.jsdelivr.net/gh/bitrefactor/ient_ble50/.image/actual_effect.jpg" width="200"
                alt="actual_effect" />
        </td>
    </tr>
</table>

</html>

## content
  - [content](#content)
  - [Permissions](#Permissions)
  - [Design original intention](#design-original-intention)
  - [Install](#install)
  - [Usage](#usage)
  - [Principle](#principle)
  - [License](#license)

## Permissions


## Design original intention

When the model rocket is ignition, in order to ensure safety, it is usually guaranteed to have sufficient safety
distances and model rockets, and wired deployment is more cumbersome. Offline is the best choice. Why not choose WiFi?
Using WiFi situations, the mobile phone is connected to the client to connect the ignition device, which will cause the
mobile phone to be limited; while the phone is used as a hotspot, the ignition device ends the network operation is more
cumbersome; why choose Bluetooth? Bluetooth low-power versions 5 supports connections within 300m, and the connection is
relatively simple.

## Install

## Usage


## Principle

## License

[GNU General Public License V3.0] (../ License)