### Cypress OpenOCD v4.1.0 Release Notes

Please refer to the README.md for a complete description of the Cypress customized version of OpenOCD.

### New Features

- Delivers fixes for various defects

### Known Issues

| ID                                | Known Issue                       | Workaround                          | 
|-----------------------------------|-----------------------------------|-----------------------------------|
|  PROGTOOLS-1425 | A “JTAG-DP STICKY ERROR” message may appear in the IDE when connected via the JTAG interface of a MiniProg4 probe in CMSIS-DAP HID mode.  |  You can safely ignore this error, or switch the MiniProg4 to CMSIS-DAP bulk mode. | 
| PROGTOOLS-1429  | JTAG performance on MiniProg4 may be significantly slower than SWD.  |  Use the SWD interface if JTAG performance is not acceptable. |
|  PROGTOOLS-1869 | In Linux OS, with KitProg3 in CMSIS-DAP HID mode, a debug session in ModusToolbox can be destroyed if you use the Firmware Loader --device-list command while debugging. This is limitation of hidapi library used on Linux. MacOS and Windows OSs are not impacted. | If you have a debug session running, don't use the firmware loader tool.  |



### More information

-   [openOCD
    README.md](https://github.com/cypresssemiconductorco/openocd/blob/cypress/README.MD)
    
-   [openOCD User Guide](https://www.cypress.com/file/495061/download)

-   [ModusToolbox Software Environment, Quick Start Guide, Documentation, and
    Videos](https://www.cypress.com/products/modustoolbox-software-environment)

-   [ModusToolbox Device Configurator Tool
    Guide](https://www.cypress.com/ModusToolboxDeviceConfig)

-   [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)

© Cypress Semiconductor Corporation, 2020.
