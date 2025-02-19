# ARM Cortex-A9 Embedded OS

This repository contains a simple operating system designed for the ARM Cortex-A9 processor. The goal of this project is to develop a minimal yet functional OS for embedded systems, focusing on essential features such as task scheduling, memory management, and inter-process communication.

## Features
- Cooperative multitasking (currently implemented)
- Preemptive scheduler (in development)
- Basic memory management
- Inter-process communication (IPC)
- ARM Cortex-A9 specific optimizations
- Simple file system (planned)
- Device drivers (ongoing development)
- Drivers for UART, Timers, GIC Interrupt Controller

## Getting Started

### Prerequisites
To build and run this OS, you will need:
- **ARM toolchain:** `arm-none-eabi-gcc`
- **QEMU (for emulation):** `qemu-system-arm`
- A Cortex-A9 based development board (if testing on real hardware)

### Building the OS
Run the following command to compile the OS:
```sh
make
```

### Running in QEMU
To test the OS using QEMU:
```sh
start
```

## Project Structure
```
ARM-Cortex-A9-Embedded-OS/
├── src/            # Source code for kernel and drivers
├── include/        # Header files
├── boot/           # Bootloader and startup code
├── docs/           # Documentation and design notes
├── scripts/        # Build and test scripts
├── Makefile        # Build system
└── README.md       # This file
```

## Contributing
Contributions are welcome! Feel free to submit issues, feature requests, or pull requests.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any inquiries, reach out To varentrung@gmail.com
