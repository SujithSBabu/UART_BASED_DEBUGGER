**UART Mini Debugger – Bare-Metal Memory & Register Inspector**

This project is a UART-based mini debugger built entirely with bare-metal C, designed to inspect core CPU registers, memory regions,and peripheral register states (like GPIOA & USART2) 
during a halted system state.It mimics how real embedded debugging tools (e.g., SEGGER RTT, Lauterbach Trace32) provide developers insights into system internals useful for fault analysis, bootloader development, 
or run time debugging.

**Project Overview**
Instead of using any HAL or CMSIS libraries, this project:
1)Uses manual register access to inspect MSP, PSP, and CONTROL registers
2)Provides UART command interface (>, m, c, 1, 2, 3, etc.)
3)Supports memory dump of:
  ->First 16 bytes of SRAM1
  ->GPIOA peripheral registers
  ->USART2 peripheral registers
4)Implements interrupt-based resume trigger to restart halted system via UART input

**Hardware Requirements**
STM32F407 DISC Board (or compatible Cortex-M MCU)
UART connected via USB–Serial converter (e.g., CP2102)
Virtual Terminal emulator (e.g., PuTTY or Tera Term)

**Software Requirements**
Language: C (bare-metal)
Toolchain: STM32CubeIDE
Version Control: Git
