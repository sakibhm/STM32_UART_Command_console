## PROJECT = UART Based Command Shell(no HAL)

A simple UART based command shell, that accepts commands from user and 
change Underlying Hardware.

## Features

- UART Communication 
- Command parsing
- Echo support(typed characters are displayed back in real-time)
- Modular structure (separate header & source files for maintainability)
- Backspace handling removes the last character from input buffer
  and update the terminal accordingly


## Working

1.UART receives character and stores inside a buffer
2.when ENTER is pressed 
  - command is parsed using "strcmp"
  - corresponding function is then executed

## Supported Commands

led on -> "Turns on the built-in LED"
led off-> "Turns off the LED"
help   -> "shows list & description of all commands"

## Hardware used

- STM32F446RE(NUCLEO BOARD)
- FT232RL(USB to TTL Serial Converter)
-

## Software & tools

Bare-metal C
VS Code integrated with WSL
GCC ARM toolchain
Termianl PuTTY/Tera Term
Git & GitHUb

## future improvement
Extend this shell to have a scheduler