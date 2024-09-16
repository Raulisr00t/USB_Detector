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
