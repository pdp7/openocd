Cypress Customized OpenOCD
===============

### Overview

The Open On-Chip Debugger (OpenOCD) is free software that provides debugging, in-system programming, and boundary-scan testing.

To work with ModusToolbox and Cypress devices and probes, Cypress has modified OpenOCD to support:
- Devices from PSoC 61/62/63/64 product lines and the corresponding kits
- Devices from PSoC 4000S, PSoC4100S, PSoC 4100S Plus and PSoC 4500 product lines  and the corresponding kits
- KitProg3 onboard programmer
- MiniProg4 standalone programmer

From the [release page](https://github.com/cypresssemiconductorco/openocd/releases), download and unpack the appropriate archive for your OS. You do not need the source code. 

If you want to update ModusToolbox to use this release, replace the contents of the  */ModusToolbox/tools_2.x/openocd* folder with the downloaded package from the release page. Otherwise just put the tool in any convenient location. 

Cypress is  working at merging these modifications into the official OpenOCD. In the mean time, these modifications are available in this repository only.

This software component is licensed under GNU General Public License v2

### FOSS usage

Cypress maintains a collection of [Free and Open Source Software]( https://www.cypress.com/documentation/software-and-drivers/modustoolbox-foss-packages) (FOSS) packages. It includes OpenOCD.

### More Information

[openOCD Release Notes](https://github.com/cypresssemiconductorco/openocd/blob/cypress/RELEASE.MD)

OpenOCD documentation in [HTML](http://openocd.org/doc/html/index.html) or [PDF](http://openocd.org/doc/pdf/openocd.pdf).

© Cypress Semiconductor Corporation, 2020.
