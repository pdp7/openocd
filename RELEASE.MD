### Cypress OpenOCD v4.0.0 Release Notes

Please refer to the README.md for a complete description of the Cypress customized version of OpenOCD.

### New Features

- Adds support of PSoC64-2M and PSoC64-512K production MCUs
Note: openOCD v4.0.0.907 does not support pre-production versions of PSoC64 MCUs. If you would like to continue to work with pre-production versions, please use the previous releases of openOCD
- Adds support of external memory on CYW9P62S1-43012EVB-01 kit 
- Increases performance of erase operation
- Delivers fixes for various defects

### Known Issues

| ID                                | Known Issue                       | Workaround                          | 
|-----------------------------------|-----------------------------------|-----------------------------------|
|  PROGTOOLS-1425 | A “JTAG-DP STICKY ERROR” message may appear in the IDE when connected via the JTAG interface of a MiniProg4 probe in CMSIS-DAP HID mode.  |  You can safely ignore this error, or switch the MiniProg4 to CMSIS-DAP bulk mode. | 
| PROGTOOLS-1429  | JTAG performance on MiniProg4 may be significantly slower than SWD.  |  Use the SWD interface if JTAG performance is not acceptable. |



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
