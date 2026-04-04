arm-none-eabi-as -mcpu=cortex-m4 -mthumb startup.s -o startup.o

arm-none-eabi-gcc -c *.c -mcpu=cortex-m4 -mthumb

arm-none-eabi-gcc *.o -mcpu=cortex-m4 -mthumb -T linker.ld -o main.elf -nostartfiles -Wl,--gc-sections -lc -lgcc -lnosys

arm-none-eabi-objcopy -O binary main.elf main.bin

st-flash write main.bin 0x08000000