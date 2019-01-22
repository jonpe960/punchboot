CROSS_COMPILE = aarch64-elf-

ARCH_OUTPUT = elf64-littleaarch64
ARCH = aarch64

CFLAGS   += -march=armv8-a
CFLAGS   += -I arch/armv8a/include

ARCH_ASM_SRCS += arch/armv8a/entry.S
ARCH_C_SRCS += arch/armv8a/boot.c


arch_clean:
	@-rm -rf arch/armv8a/*.o
	@-rm -f arch/armv8a/*.gcno arch/armv8a/*.gcda
