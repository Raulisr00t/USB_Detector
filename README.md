# USB_Detector

A simple C program to detect USB drives connected to a Windows system by checking all logical drives and identifying removable media.

## Features
- Scans all logical drives (A: to Z:) on a Windows machine.
- Detects and displays connected USB drives.
- Notifies if no USB drives are found.

## How It Works
The program uses the `GetLogicalDrives()` function to get a bitmask representing the currently available drives on the system. It then checks each drive to determine whether it's a removable drive (such as a USB stick) using the `GetDriveTypeA()` function.

### Example Output
```
[>>] USB drive detected at E:
[>>] USB drive detected at F:\

```

If no USB drives are detected:
```
[!] No USB drives detected!
```

### Code
```c
#include <windows.h>
#include <stdio.h>

int main(void) {
    UINT drives = GetLogicalDrives();
    int usbDetected = 0;

    for (int i = 0; i < 26; i++) {
        if (drives & (1 << i)) {
            char drive[4];
            snprintf(drive, sizeof(drive), "%c:\\", 'A' + i);

            if (GetDriveTypeA(drive) == DRIVE_REMOVABLE) {
                printf("[>>] USB drive detected at %s\n", drive);
                usbDetected = 1;
            }
        }
    }

    if (!usbDetected) {
        printf("[!] No USB drives detected!\n");
        return 1;
    }

    return 0;
}
```

### Requirements
Operating System: Windows
Compiler: Any C compiler that supports the Windows API, such as GCC or Visual Studio's MSVC.

### Compilation
To compile the program using GCC (Mingw)
```powershell
gcc usb_detector.c -o usb_detector.exe
```

### Usage
Compile the program.
Run the executable in a command prompt:
```cmd
usb_detector.exe
```
## License
This project is licensed under the MIT License.
