/****************************************************************************
**
** Copyright (C) 2020 @scriptiot
**
**  EVM是一款通用化设计的虚拟机引擎，拥有语法解析前端接口、编译器、虚拟机和虚拟机扩展接口框架。
**  支持js、python、qml、lua等多种脚本语言，纯Ｃ开发，零依赖，内置REPL，支持主流 ROM > 40KB, RAM > 2KB的MCU;
**  自带垃圾回收（GC）先进的内存管理，采用最复杂的压缩算法，无内存碎片（大部分解释器都存在内存碎片）
**  Version	: 1.0
**  Email	: scriptiot@aliyun.com
**  Website	: https://github.com/scriptiot/evm
**            https://gitee.com/scriptiot/evm
**  Licence: Apache-2.0
****************************************************************************/

#include "evm_main.h"

#include <device.h>
#include <drivers/gpio.h>
#include <zephyr.h>







void main(void)
{
#if CONFIG_EVM_MODULE_LCD
    struct device * dev = device_get_binding("GPIOB");
    if( dev ) {
        gpio_pin_configure(dev, 15, GPIO_OUTPUT);
        gpio_pin_set(dev, 15, 1);
    }
#endif
    evm_main();
}
