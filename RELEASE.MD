### Cypress OpenOCD v3.0.0 Release Notes

Please refer to the README.md for a complete description of the Cypress customized version of OpenOCD.

### New Features

- Adds support of PSoC 4000S, PSoC4100S, PSoC 4100S Plus and PSoC 4500 product lines  and the corresponding kits
- Addresses various bugs and enhancements
- Syncs with openOCD main branch  

### Known Issues

| ID                                | Known Issue                       | Workaround                          | 
|-----------------------------------|-----------------------------------|-----------------------------------|
|  PROGTOOLS-1425 | A “JTAG-DP STICKY ERROR” message may appear in the IDE when connected via the JTAG interface of a MiniProg4 probe in CMSIS-DAP HID mode.  |  You can safely ignore this error, or switch the MiniProg4 to CMSIS-DAP bulk mode. | 
|  PROGTOOLS-1469 |  In the Eclipse IDE, the JTAG debug launch configuration may fail for the MiniProg4. You may see the “JTAG-DP-STICKY ERROR” message. | Use SWD instead of JTAG.  |
| PROGTOOLS-1429  | JTAG performance on MiniProg4 may be significantly slower than SWD.  |  There is no workaround except using the SWD interface if JTAG performance is not acceptable. |



### More information

-   [openOCD
    README.md](https://github.com/cypresssemiconductorco/openocd/blob/cypress/README.MD)
    
-   [openOCD User Guide](https://www.cypress.com/file/495061/download)

-   [ModusToolbox Software Environment, Quick Start Guide, Documentation, and
    Videos](https://www.cypress.com/products/modustoolbox-software-environment)

-   [ModusToolbox Device Configurator Tool
    Guide](https://www.cypress.com/ModusToolboxDeviceConfig)

-   [Cypress Semiconductor](http://www.cypress.com)

© Cypress Semiconductor Corporation, 2020.
