
#if defined(__x86_64__)
    #define PASSARO_ARCH "x86_64"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTX64.EFI"

#elif defined(__i386__)
    #define PASSARO_ARCH "x86"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTIA32.EFI"

#elif defined(__aarch64__)
    #define PASSARO_ARCH "ARM64"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTAA64.EFI"

#elif defined(__arm__)
    #define PASSARO_ARCH "ARM"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTARM.EFI"

#elif defined(__riscv) && (__riscv_xlen == 64)
    #define PASSARO_ARCH "RISC-V 64"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTRISCV64.EFI"

#elif defined(__riscv) && (__riscv_xlen == 32)
    #define PASSARO_ARCH "RISC-V 32"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTRISCV32.EFI"

#elif defined(__loongarch64)
    #define PASSARO_ARCH "LoongArch64"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTLOONGARCH64.EFI"

#elif defined(__loongarch__)
    #define PASSARO_ARCH "LoongArch32"
    #define BOOT_FILE L"\\EFI\\BOOT\\BOOTLOONGARCH32.EFI"

#else
    #error "Arquitetura nao suportada pelo PassaroOS"
#endif
