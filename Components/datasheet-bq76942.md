**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

# **BQ76942 3-Series to 10-Series High Accuracy Battery Monitor and Protector for Li-Ion, Li- Polymer, and LiFePO4 Battery Packs** 

### **1 Features** 

- Battery monitoring capability for 3-series to 10series cells 

- Integrated charge pump for high-side NFET protection with optional autonomous recovery 

- • Extensive protection suite including voltage, temperature, current, and internal diagnostics 

- Two independent ADCs 

   - Support for simultaneous current and voltage sampling 

   - High-accuracy coulomb counter with input offset error < 1 µV (typical) 

   - High-accuracy cell voltage measurement < 10  mV (typical) 

- Wide-range current applications (±200-mV measurement range across sense resistor) 

- Integrated secondary chemical fuse drive protection 

- Autonomous or host-controlled cell balancing 

- Multiple power modes (typical battery pack operating range conditions) 

   - NORMAL mode: 286 µA 

   - Multiple SLEEP mode options: 24 µA to 41 µA 

   - Multiple DEEPSLEEP mode options: 9 µA to 10 µA 

   - SHUTDOWN Mode: 1 µA 

- High-voltage tolerance of 85 V on cell connect and select additional pins 

- Tolerant of random cell attach sequence on production line 

- Support for temperature sensing using internal sensor and up to nine external thermistors 

- Integrated one-time-programmable (OTP) memory programmable by customers on production line 

- Communication options include 400-kHz I<sup>2</sup> C, SPI, and HDQ one-wire interface 

- Dual programmable LDOs for external system usage 

- 48-pin TQFP package (PFB) 

### **2 Applications** 

- Cordless power tools and garden tools 

- Vacuum cleaners 

- E-bike, e-scooter, and LEV 

- Non-military drones 

- Other industrial battery pack (3-series–10-series) 

### **3 Description** 

The Texas Instruments BQ76942 is a highly integrated, high accuracy battery monitor and protector for 3-series to 10-series Li-ion, Li-polymer, and LiFePO4 battery packs. The device includes a high-accuracy monitoring system, a highly configurable protection subsystem, and support for autonomous or host-controlled cell balancing. Integration includes high-side charge-pump NFET drivers, dual programmable LDOs for external system use, and a host communication peripheral supporting 400-kHz I<sup>2</sup> C, SPI, and HDQ one-wire standards. The BQ76942 is available in a 48-pin TQFP package. 

**Device Information** 

|**PART NUMBER**<sup>(1)</sup>|**PACKAGE**|**BODY SIZE (NOM)**|
|---|---|---|
|BQ76942xx|PFB (48-pin)|7 mm × 7 mm|



- (1) See the _Device Comparison Table_ for information on the device family. For all available devices, see the orderable addendum at the end of the data sheet. 



<!-- Start of picture text -->
PACK+<br>CHG DSG<br>5V COMMUNICATIONS TRANSCEIVER COMM TO<br>SYSTEM<br>+<br>NC REGIN COMM<br>+ VC9 REG1<br>NC REG2 3.3V VDD<br>+ VC8 RST_SHUT<br>NC DDSG<br>MCU<br>+ VC7 DCHG<br>NC DFETOFF<br>+ VC6 CFETOFF<br>NC HDQ<br>+ VC5 SDA<br>NC SCL<br>+ VC4 ALERT<br>GND<br>+<br>+<br>+<br>PACK-<br>VC10 BAT CP1 CHG NC DSG PACK LD PCHG PDSG FUSE BREG<br>VC3 VC2 VC1 VC0 VSS SRP NC SRN TS1 TS2 TS3 REG18<br><!-- End of picture text -->

##### **Simplified Schematic** 

An IMPORTANT NOTICE at the end of this data sheet addresses availability, warranty, changes, use in safety-critical applications, intellectual property matters and other important disclaimers. PRODUCTION DATA. 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

### **Table of Contents** 

|**1 Features**............................................................................1<br>**2 Applications**.....................................................................1|10.6 Thermistor Temperature Measurement...................37<br>10.7 Factory Trim of Voltage ADC..................................38|
|---|---|
|<br>**3 Description**.......................................................................1|<br>10.8 Voltage Calibration (ADC Measurements)..............38|
|**4 Revision History**..............................................................3|10.9 Voltage Calibration (COV and CUV Protections)....39|
|**5 Device Comparison Table**...............................................4|10.10 Current Calibration................................................40|
|**6 Pin Configuration and Functions**...................................4|10.11 Temperature Calibration........................................40|
|**7 Specifications**..................................................................7<br>|**11 Primary and Secondary Protection Subsystems**......40<br>|
|7.1 Absolute Maximum Ratings .......................................7|11.1 Protections Overview..............................................40|
|<br>7.2 ESD Ratings ..............................................................8|11.2 Primary Protections.................................................41|
|7.3 Recommended Operating Conditions ........................8|11.3 Secondary Protections............................................41|
|7.4 Thermal Information BQ76942 .................................10|11.4 High-Side NFET Drivers..........................................42|
|7.5 Supply Current .........................................................10|11.5 Protection FETs Configuration and Control.............43|
|7.6 Digital I/O .................................................................11|11.6 Load Detect Functionality........................................44|
|7.7 LD Pin ......................................................................11|**12 Device Hardware Features**..........................................44|
|7.8 Precharge (PCHG) and Predischarge (PDSG)|12.1 Voltage References.................................................44|
|FET Drive ...................................................................11|12.2 ADC Multiplexer......................................................44|
|7.9 FUSE Pin Functionality ............................................12|12.3 LDOs.......................................................................45|
|7.10 REG18 LDO ...........................................................12<br>|12.4 Standalone Versus Host Interface..........................45<br>|
|7.11 REG0 Pre-regulator ...............................................12|12.5 Multifunction Pin Controls.......................................46|
|7.12 REG1 LDO .............................................................13|12.6 RST_SHUT Pin Operation......................................47|
|7.13 REG2 LDO .............................................................13|12.7 CFETOFF, DFETOFF, BOTHOFF Pin|
|7.14 Voltage References ................................................14|Functionality................................................................47|
|7.15 Coulomb Counter ...................................................14|12.8 ALERT Pin Operation.............................................47|
|7.16 Coulomb Counter Digital Filter (CC1) ....................14|12.9 DDSG and DCHG Pin Operation............................47|
|7.17 Current Measurement Digital Filter (CC2) .............15|12.10 Fuse Drive.............................................................48|
|7.18 Current Wake Detector ..........................................15|12.11 Cell Open Wire......................................................48|
|7.19 Analog-to-Digital Converter ....................................15|12.12 Low Frequency Oscillator.....................................49|
|7.20 Cell Balancing ........................................................17|12.13 High Frequency Oscillator.....................................49|
|7.21 Cell Open Wire Detector ........................................17<br>|**13 Device Functional Modes**...........................................49<br>|
|7.22 Internal Temperature Sensor .................................17|13.1 Overview.................................................................49|
|7.23 Thermistor Measurement .......................................17|13.2 NORMAL Mode.......................................................50|
|7.24 Internal Oscillators .................................................17|13.3 SLEEP Mode..........................................................50|
|7.25 High-Side NFET Drivers ........................................18|13.4 DEEPSLEEP Mode.................................................51|
|7.26 Comparator-Based Protection Subsystem .............19<br>|13.5 SHUTDOWN Mode.................................................51|
|7.27 Timing Requirements – I<sup>2</sup>C Interface, 100kHz<br>|13.6 CONFIG_UPDATE Mode........................................52<br>|
|Mode ..........................................................................21|**14 Serial Communications Interface**...............................53|
|7.28 Timing Requirements – I<sup>2</sup>C Interface, 400kHz|14.1 Serial Communications Overview...........................53|
|Mode ..........................................................................21|14.2 I<sup>2</sup>C Communications Subsystem............................53|
|7.29 Timing Requirements – HDQ Interface ..................22|14.3 SPI Communications Interface...............................54|
|7.30 Timing Requirements – SPI Interface ....................22|14.4 HDQ Communications Interface.............................60|
|7.31 Interface Timing Diagrams......................................23|**15 Cell Balancing**..............................................................62|
|7.32 Typical Characteristics............................................25|15.1 Cell Balancing Overview.........................................62|
|**8 Device Description**........................................................31|**16 Application and Implementation**................................63|
|<br>8.1 Overview...................................................................31|<br>16.1 Application Information...........................................63|
|8.2 BQ76942 Device Versions........................................31|16.2 Typical Applications................................................63|
|8.3 Functional Block Diagram.........................................32|16.3 Random Cell Connection Support..........................70|
|<br>8.4 Diagnostics...............................................................32|<br>16.4 Startup Timing.........................................................70|
|<br>**9 Device Configuration**....................................................33|<br>16.5 FET Driver Turn-Off................................................72|
|9.1 Commands and Subcommands................................33|16.6 Unused Pins............................................................74|
|9.2 Configuration Using OTP or Registers......................33|**17 Power Supply Requirements**......................................75|
|<br>9.3 Device Security.........................................................33|<br>**18 Layout**...........................................................................75|
|<br>9.4 Scratchpad Memory..................................................33|<br>18.1 Layout Guidelines...................................................75|
|**10 Measurement Subsystem**...........................................34<br>|18.2 Layout Example......................................................75<br>|
|10.1 Voltage Measurement.............................................34|**19 Device and Documentation Support**..........................78|
|<br>10.2 General Purpose ADCIN Functionality...................36|<br>19.1 Third-Party Products Disclaimer.............................78|
|10.3 Coulomb Counter and Digital Filters.......................36<br>|19.2 Documentation Support..........................................78<br>|
|10.4 Synchronized Voltage and Current Measurement..37|19.3 Support Resources.................................................78|
|<br>10.5 Internal Temperature Measurement........................37|<br>19.4 Trademarks.............................................................78|



Copyright © 2021 Texas Instruments Incorporated 

2 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

|19.5 Electrostatic Discharge Caution..............................78|**20 Mechanical, Packaging, Orderable Information**.......78|
|---|---|
|19.6 Glossary..................................................................78||



### **4 Revision History** 

|**C**|**hanges from Revision A(January 2021) to Revision B(December 2021)**|**Page**|
|---|---|---|
|•|Updated the_Absolute Maximum Ratings_,_Recommended Operating Conditions_,_ESD Ratings_, and|_Analog-to-_|
||_Digital Converter_tables........................................................................................................................|..............7|
|•|AddedCell 1 Voltage Validation During SLEEP Mode........................................................................|............36|
|•|Corrected voltage.................................................................................................................................|............36|
|•|Corrected the nominal value of VREF1 and the ADC counts calculations based on that value...........|............38|
|•|Updated simplified schematic. Denoted capacitors on sense resistor inputs to VSS as optional........|............63|
|•|UpdatedDocumentation Support........................................................................................................|............78|



|**C**|**hanges from Revision *(November 2020) to Revision A(January 2021)**|**Page**|
|---|---|---|
|•|UpdatedDescription.................................................................................................................|.........................1|
|•|Updated the BQ76942xy devices from PRODUCT PREVIEW to Production Data...................|.........................4|
|•|UpdatedSpecifications.............................................................................................................|.........................7|
|•|UpdatedTypical Characteristics...............................................................................................|.......................25|
|•|UpdatedVoltage Measurement................................................................................................<br>|.......................34<br>|
|•|UpdatedI<sup>2</sup>C Communications Subsystem................................................................................|.......................53|
|•|UpdatedSPI Communications Interface...................................................................................|.......................54|
|•|UpdatedSPI Protocol...............................................................................................................|.......................56|
|•|UpdatedHDQ Communications Interface................................................................................|.......................60|
|•|UpdatedDocumentation Support.............................................................................................|.......................78|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 3 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

### **5 Device Comparison Table** 

||**BQ76942 Device Family**|||
|---|---|---|---|
|**PART NUMBER**|**Communications Interface**|**CRC Enabled**|**REG1 LDO Default**|
|BQ76942|I<sup>2</sup>C|N|Disabled|
|BQ7694201|SPI|Y|Disabled|
|BQ7694202|I<sup>2</sup>C|Y|Enabled, set to 3.3 V|
|BQ7694203|SPI|Y|Enabled, set to 5 V|
|BQ7694204|SPI|Y|Enabled, set to 3.3 V|



### **6 Pin Configuration and Functions** 



<!-- Start of picture text -->
NC 1 36  REGIN<br>VC9 2 35  REG1<br>NC 3 34  REG2<br>VC8 4 33  RST_SHUT<br>NC 5 32  DDSG<br>VC7 6 31  DCHG<br>NC 7 30  DFETOFF<br>VC6 8 29  CFETOFF<br>NC 9 28  HDQ<br>VC5 10 27  SDA<br>NC 11 26  SCL<br>VC4 12 25  ALERT<br>Not to scale<br>VC10 BAT CP1 CHG NC DSG PACK LD PCHG PDSG FUSE BREG<br>48 47 46 45 44 43 42 41 40 39 38 37<br>13 14 15 16 17 18 19 20 21 22 23 24<br>VC3 VC2 VC1 VC0 VSS SRP NC SRN TS1 TS2 TS3 REG18<br><!-- End of picture text -->

**Figure 6-1. Pinout (top)** 

**Table 6-1. BQ76942 TQFP Package (PFB) Pin Functions** 

|**NO.**|**PIN**<br>**NAME**|**I/O**|**TYPE**|**DESCRIPTION**|
|---|---|---|---|---|
|1|NC|—|—|This pin is not connected to silicon.|
|2|VC9|I|IA|Sense voltage input pin for the ninth cell from the bottom of the stack, balance current<br>input for the ninth cell from the bottom of the stack, and return balance current for the tenth<br>cell from the bottom of the stack|
|3|NC|—|—|This pin is not connected to silicon.|



Copyright © 2021 Texas Instruments Incorporated 

4 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

**Table 6-1. BQ76942 TQFP Package (PFB) Pin Functions (continued)** 

|**NO.**|**PIN**<br>**NAME**|**I/O**|**TYPE**|**DESCRIPTION**|
|---|---|---|---|---|
|4|VC8|I|IA|Sense voltage input pin for the eighth cell from the bottom of the stack, balance current<br>input for the eighth cell from the bottom of the stack, and return balance current for the<br>ninth cell from the bottom of the stack|
|5|NC|—|—|This pin is not connected to silicon.|
|6|VC7|I|IA|Sense voltage input pin for the seventh cell from the bottom of the stack, balance current<br>input for the seventh cell from the bottom of the stack and return balance current for the<br>eighth cell from the bottom of the stack|
|7|NC|—|—|This pin is not connected to silicon.|
|8|VC6|I|IA|Sense voltage input pin for the sixth cell from the bottom of the stack, balance current input<br>for the sixth cell from the bottom of the stack, and return balance current for the seventh<br>cell from the bottom of the stack|
|9|NC|—|—|This pin is not connected to silicon.|
|10|VC5|I|IA|Sense voltage input pin for the fifth cell from the bottom of the stack, balance current input<br>for the fifth cell from the bottom of the stack, and return balance current for the sixth cell<br>from the bottom of the stack|
|11|NC|—|—|This pin is not connected to silicon.|
|12|VC4|I|IA|Sense voltage input pin for the fourth cell from the bottom of the stack, balance current<br>input for the fourth cell from the bottom of the stack, and return balance current for the fifth<br>cell from the bottom of the stack|
|13|VC3|I|IA|Sense voltage input pin for the third cell from the bottom of the stack, balance current input<br>for the third cell from the bottom of the stack, and return balance current for the fourth cell<br>from the bottom of the stack|
|14|VC2|I|IA|Sense voltage input pin for the second cell from the bottom of the stack, balance current<br>input for the second cell from the bottom of the stack, and return balance current for the<br>third cell from the bottom of the stack|
|15|VC1|I|IA|Sense voltage input pin for the first cell from the bottom of the stack, balance current input<br>for the first cell from the bottom of the stack, and return balance current for the second cell<br>from the bottom of the stack|
|16|VC0|I|IA|Sense voltage input pin for negative terminal of the first cell from the bottom of the stack,<br>and return balance current for first cell from the bottom of the stack|
|17|VSS|—|P|Device ground|
|18|SRP|I|IA|Analog input pin connected to the internal coulomb counter peripheral for integrating a<br>small voltage between SRP and SRN, where SRP is the top of the sense resistor. A<br>charging current generates a positive voltage at SRP relative to SRN.|
|19|NC|—|—|This pin is not connected to silicon.|
|20|SRN|I|IA|Analog input pin connected to the internal coulomb counter peripheral for integrating a<br>small voltage between SRP and SRN, where SRN is the bottom of the sense resistor. A<br>charging current generates a positive voltage at SRP relative to SRN.|
|21|TS1|I/O|OD, I/OA|Thermistor input, or general purpose ADC input|
|22|TS2|I/O|OD, I/OA|Thermistor input and functions as wakeup from SHUTDOWN, or general purpose ADC<br>input|
|23|TS3|I/O|OD, I/OA|Thermistor input, or general purpose ADC input|
|24|REG18|O|P|Internal 1.8 V-LDO output (only for internal use)|
|25|ALERT|I/O|I/OD, I/OA|Multifunction pin, can be ALERT output, or HDQ I/O, or thermistor input, or general<br>purpose ADC input, or general purpose digital output|
|26|SCL|I/O|I/OD|Multifunction pin, can be SCL or SPI_SCLK|
|27|SDA|I/O|I/OD|Multifunction pin, can be SDA or SPI_MISO|
|28|HDQ|I/O|I/OD, I/OA|Multifunction pin, can be HDQ I/O, or SPI_MOSI, or thermistor input, or general purpose<br>ADC input, or general purpose digital output|
|29|CFETOFF|I/O|I/OD, I/OA|Multifunction pin, can be CFETOFF, or SPI_CS, or thermistor input, or general purpose<br>ADC input, or general purpose digital output|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 5 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**Table 6-1. BQ76942 TQFP Package (PFB) Pin Functions (continued)** 

||**PIN**|**I/O**|**TYPE**|**DESCRIPTION**|
|---|---|---|---|---|
|**NO.**|**NAME**||||
|30|DFETOFF|I/O|I/OD, I/OA|Multifunction pin, can be DFETOFF or BOTHOFF, or thermistor input, or general purpose<br>ADC input, or general purpose digital output|
|31|DCHG|I/O|OD, I/OA|Multifunction pin, can be DCHG, or thermistor input, or general purpose ADC input, or<br>general purpose digital output|
|32|DDSG|I/O|OD, I/OA|Multifunction pin, can be DDSG, or thermistor input, or general purpose ADC input, or<br>general purpose digital output|
|33|RST_SHUT|I|ID|Digital input pin for reset or shutdown|
|34|REG2|O|P|Second LDO (REG2) output, which can be programmed for 1.8 V, 2.5 V, 3.0 V, 3.3 V, or<br>5.0 V|
|35|REG1|O|P|First LDO (REG1) output, which can be programmed for 1.8 V, 2.5 V, 3.0 V, 3.3 V, or 5.0 V|
|36|REGIN|I|IA|Input pin for REG1 and REG2 LDOs|
|37|BREG|O|OA|Base control signal for external preregulator transistor|
|38|FUSE|I/O|I/OA|Fuse sense and drive|
|39|PDSG|O|OA|Predischarge PFET control|
|40|PCHG|O|OA|Precharge PFET control|
|41|LD|I/O|I/OA|Load detect pin|
|42|PACK|I|IA|Pack sense input pin|
|43|DSG|O|OA|NMOS discharge FET drive output pin|
|44|NC|—|—|This pin is not connected to silicon.|
|45|CHG|O|OA|NMOS charge FET drive output pin|
|46|CP1|I/O|I/OA|Charge pump capacitor|
|47|BAT|I|P|Primary power supply input pin|
|48|VC10|I|IA|Sense voltage input pin for the tenth cell from the bottom of the stack, balance current<br>input for the tenth cell from the bottom of the stack, and top-of-stack measurement point|



Copyright © 2021 Texas Instruments Incorporated 

6 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **7 Specifications** 

#### **7.1 Absolute Maximum Ratings** 

over operating free-air temperature range (unless otherwise noted)<sup>(1)</sup> 

|**DESCRIPTION**|**PINS**|**MIN**|**MAX**|**UNIT**|
|---|---|---|---|---|
|Supply voltage range|BAT|VSS–0.3|VSS+85|V|
|Input voltage range, VIN|PACK, LD|VSS–0.3|VSS+85|V|
|Input voltage range, VIN|PACK, PCHG, PDSG, LD|the maximum<br>of VBAT–10 or<br>VLD–10|VSS+85|V|
|Input voltage range, VIN|REGIN|the maximum<br>of VSS–0.3 or<br>VBREG–5.5|the minimum<br>of VSS+6 or<br>VBAT+0.3 or<br>VBREG+0.3|V|
|Input voltage range, VIN|FUSE<sup>(2)</sup>|VSS–0.3|the minimum<br>of VSS+20 or<br>VBAT+0.3|V|
|Input voltage range, VIN|BREG|the maximum<br>of VSS–0.3 or<br>VREGIN–0.3|VREGIN+5.5|V|
|Input voltage range, VIN|REG1, REG2|VSS–0.3|minimum of<br>VSS+6<br>or VREGIN+0.3|V|
|Input voltage range, VIN|ALERT, SCL, SDA, HDQ, CFETOFF, DFETOFF,<br>DCHG, DDSG, RST_SHUT<sup>(3)</sup>|VSS–0.3|VSS+6|V|
|Input voltage range, VIN|TS1, TS2, TS3, ALERT, CFETOFF, DFETOFF, HDQ,<br>DCHG, DDSG (when used as thermistor or general<br>purpose ADC input)|VSS–0.3|VREG18+ 0.3|V|
|Input voltage range, VIN|SRP, SRN|VSS–0.3|VREG18+ 0.3|V|
|Input voltage range, VIN|VC10|maximum of<br>VSS–0.3 and<br>VC9–0.3|VSS+85|V|
|Input voltage range, VIN|VC9|maximum of<br>VSS–0.3 and<br>VC8–0.3|VSS+85|V|
|Input voltage range, VIN|VC8|maximum of<br>VSS–0.3 and<br>VC7–0.3|VSS+85|V|
|Input voltage range, VIN|VC7|maximum of<br>VSS–0.3 and<br>VC6–0.3|VSS+85|V|
|Input voltage range, VIN|VC6|maximum of<br>VSS–0.3 and<br>VC5–0.3|VSS+85|V|
|Input voltage range, VIN|VC5|maximum of<br>VSS–0.3 and<br>VC4–0.3|VSS+85|V|
|Input voltage range, VIN|VC4|maximum of<br>VSS–0.3 and<br>VC3–0.3|VSS+85|V|
|Input voltage range, VIN|VC3|maximum of<br>VSS–0.3 and<br>VC2–0.3|VSS+85|V|
|Input voltage range, VIN|VC2|maximum of<br>VSS–0.3 and<br>VC1–0.3|VSS+85|V|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 7 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

#### **7.1 Absolute Maximum Ratings (continued)** 

over operating free-air temperature range (unless otherwise noted)<sup>(1)</sup> 

|**DESCRIPTION**|**PINS**|**MIN**|**MAX**|**UNIT**|
|---|---|---|---|---|
|Input voltage range, VIN|VC1|maximum of<br>VSS–0.3 and<br>VC0–0.3|VSS+85|V|
|Input voltage range, VIN|VC0|VSS–0.3|VSS+6|V|
|Output voltage range, VO|CP1|VBAT–0.3|the minimum<br>of VSS+85 or<br>VBAT+15|V|
|Output voltage range, VO|CHG|VSS–0.3|VSS+85|V|
|Output voltage range, VO|DSG|VSS–0.3|VSS+85|V|
|Output voltage range, VO|REG1, REG2, TS2 (for wakeup function), ALERT,<br>CFETOFF, DFETOFF, HDQ, DCHG, DDSG, when<br>configured to drive a digital output|VSS–0.3|VSS+6|V|
|Output voltage range, VO|REG18|VSS–0.3|VSS+2|V|
|Maximum cell balancing current<br>through a single cell|VC0 – VC10||100|mA|
|Maximum VSS current, ISS|||75|mA|
|Functional temperature, TFUNC||–40|85|°C|
|Junction temperature, TJ||–55|150|°C|
|Storage temperature, TSTG||–55|150|°C|



- (1) Operation outside the _Absolute Maximum Ratings_ may cause permanent device damage. _Absolute Maximum Ratings_ do not imply functional operation of the device at these or any other conditions beyond those listed under _Recommended Operating Conditions_ . If outside the _Recommended Operating Conditions_ but within the _Absolute Maximum Ratings_ , the device may not be fully functional, and this may affect device reliability, functionality, performance, and shorten the device lifetime. 

- (2) The current allowed to flow into the FUSE pin must be limited (such as by using external series resistance) to 2 mA or less. 

- (3) When the ALERT, HDQ, CFETOFF, DFETOFF, DCHG, or DDSG pins are selected for thermistor input or general purpose ADC–input, their voltage is limited to VREG18 + 0.3 V. These pins can accept up to 6 V when configured for other uses, such as a digital input. 

#### **7.2 ESD Ratings** 

||||**VALUE**|**UNIT**|
|---|---|---|---|---|
|V(ESD)|Electrostatic discharge|Human body model (HBM), per ANSI/ESDA/<br>JEDEC JS-001, all pins<sup>(1)</sup>|±1000|V|
|V(ESD)|Electrostatic discharge|Charged device model (CDM), per ANSI/ESDA/<br>JEDEC JS-002, all pins<sup>(2)</sup>|±250|V|



- (1) JEDEC document JEP155 states that 500-V HBM allows safe manufacturing with a standard ESD control process. 

(2) JEDEC document JEP157 states that 250-V CDM allows safe manufacturing with a standard ESD control process. 

#### **7.3 Recommended Operating Conditions** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VBAT|Supply voltage|Voltage on BAT pin (normal<br>operation)|4.7||55|V|
|VBAT|Supply voltage<sup>(3)</sup>|Voltage on BAT pin (OTP<br>programming)|10||12|V|
|TOTP|OTP programming<br>temperature<sup>(3)</sup>||–40||45|°C|
|VPORA|Power-on reset|Rising threshold on BAT|3||4|V|
|VPORA_HYS|Power-on reset hysteresis|Device shuts down when BAT <<br>VPORA- VPORA_HYS||180||mV|



Copyright © 2021 Texas Instruments Incorporated 

8 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **7.3 Recommended Operating Conditions (continued)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**<br>|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VWAKEONLD|Wake on LD voltage|Rising edge on LD, with BAT already<br>in valid range|0.8|1.45|2.25|V|
|VWAKEONTS2|Wake on TS2 voltage|Falling edge on TS2, with BAT<br>already in valid range. TS2 will be<br>weakly driven with a 5 V level during<br>shutdown.|0.7||1.1|V|
|VIN|Input voltage range<sup>(3)</sup>|PACK, LD|0||55|V|
||||the||||
|VIN|Input voltage range<sup>(3)</sup>|PCHG, PDSG|maximum<br>of VBAT–9<br>or VLD–9||55|V|
|VIN|Input voltage range<sup>(3)</sup>|REG1, REG2, RST_SHUT, ALERT,<br>SCL, SDA, HDQ, CFETOFF,<br>DFETOFF, DCHG, DDSG, except<br>when the pin is being used for<br>general purpose ADC input or<br>thermistor measurement.|0||5.5|V|
|VIN|Input voltage range<sup>(3)</sup>|TS1, TS2, TS3, CFETOFF,<br>DFETOFF, DCHG, DDSG, ALERT,<br>HDQ, when the pin is configured<br>for general purpose ADC input or<br>thermistor measurement.|0||VREG18|V|
|VIN|Input voltage range<sup>(5)</sup>|SRP, SRN, SRP-SRN (while<br>measuring current)|–0.2||0.2|V|
|VIN|Input voltage range<sup>(3)</sup>|SRP, SRN (without measuring<br>current)|–0.2||0.75|V|
|VIN|Input voltage range<sup>(3)</sup> <sup>(4)</sup>|VVC(0)|–0.2||0.5|V|
|VIN|Input voltage range<sup>(5)</sup>|VVC(x),1 ≤ x ≤ 4|maximum<br>of VVC(x–1)<br>– 0.2 or<br>VSS–0.2||minimum<br>of VVC(x–<br>1)<sup>+5.5 or</sup><br>VSS+55|V|
|VIN|Input voltage range|VVC(x),x ≥ 5|maximum<br>of VVC(x–1)<br>– 0.2 or<br>VSS + 2.0||minimum<br>of VVC(x–1)<br>+ 5.5 or<br>VSS + 55|V|
|RC|External cell input resistance<sup>(3)</sup><br>(6)||20||100|Ω|
|RC|External cell input<br>capacitance<sup>(3)</sup> <sup>(6)</sup>||0.1|0.22|1|µF|
|VO|Output voltage range|LD|||55|V|
|VO|Output voltage range<sup>(5)</sup>|CHG, DSG, CP1|||70|V|
|TOPR|Operating temperature<sup>(5)</sup>||–40||85|°C|
|VCELL(ACC)|Cell voltage measurement<br>accuracy|2 V < VVC(x)- VVC(x-1)< 5 V, TA=<br>25°C, 1 ≤ x ≤ 10<sup>(1)</sup> <sup>(2)</sup>|–5||5|mV|
|VCELL(ACC)|Cell voltage measurement<br>accuracy<sup>(5)</sup>|2 V < VVC(x)- VVC(x-1)< 5 V, TA= 0°C<br>to 60°C, 1 ≤ x ≤ 10<sup>(1)</sup> <sup>(2)</sup>|–10||10|mV|
|VCELL(ACC)|Cell voltage measurement<br>accuracy<sup>(5)</sup>|–0.2 V < VVC(x)- VVC(x-1)< 5.5 V, TA<br>= -40°C to 85°C, 1 ≤ x ≤ 10<sup>(1)</sup> <sup>(2)</sup>|–15||15|mV|
|VSTACK(ACC)|Stack voltage (VC10 - VSS)<br>measurement accuracy<sup>(5)</sup>|0 V < VVC10- VVSS≤ 55 V, TA=<br>-40°C to 85°C<sup>(1)</sup>|–0.5||0.5|V|
|VPACK(ACC)|PACK pin voltage measurement<br>accuracy<sup>(5)</sup>|<br>0 V < VPACK- VVSS≤ 55 V, TA=<br>-40°C to 85°C<sup>(1)</sup>|–0.5||0.5|V|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 9 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

#### **7.3 Recommended Operating Conditions (continued)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VLD(ACC)|LD pin voltage measurement<br>accuracy<sup>(5)</sup>|0 V < VLD- VVSS≤ 55 V, TA= -40°C<br>to 85°C<sup>(1)</sup>|–0.5||0.5|V|



- (1) Cell voltage accuracy is specified after completion of board offset calibration 

- (2) While in SLEEP mode, it is important that the cell 1 voltage measurement be validated before being considered valid.  For further information and details, see **Cell 1 Voltage Validation during SLEEP Mode** . 

- (3) Specified by design 

- (4) Voltage on VC0 can extend higher (limited by absolute maximum specification) during cell balancing. 

- (5) Specified by characterization 

- (6) Values may need to be optimized during system design and evaluation for best performance 

#### **7.4 Thermal Information BQ76942** 

|||**BQ76942**||
|---|---|---|---|
||**THERMAL METRIC**<sup>(1)</sup>|**PFB (TQFP)**|**UNIT**|
|||**48 PINS**||
|RθJA|Junction-to-ambient thermal resistance|66.0|°C/W|
|RθJC(top)|Junction-to-case (top) thermal resistance|19.6|°C/W|
|RθJB|Junction-to-board thermal resistance|29.3|°C/W|
|ΨJT|Junction-to-top characterization parameter|0.8|°C/W|
|ΨJB|Junction-to-board characterization parameter|29.1|°C/W|



(1) For more information about traditional and new thermal metrics, see the Semiconductor and IC Package Thermal Metrics application report. 

#### **7.5 Supply Current** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|INORMAL|Normal Mode|Regular measurements and protections active,<br>REG1 = 3.3 V with no load, REG2 = OFF, CHG<br>= ON in 11 V overdrive mode, DSG = ON in 11 V<br>overdrive mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 0, no communication||286||µA|
|ISLEEP_1|SLEEP Mode|Periodic protections and monitoring, no pack<br>current, REG1 = OFF, REG2 = OFF, CHG =<br>OFF, DSG = ON in 11 V overdrive mode, no<br>communication,**Power:Sleep:Voltage Time**= 5<br>s||41||µA|
|ISLEEP_2|SLEEP Mode|Periodic protections and monitoring, no pack<br>current, REG1 = OFF, REG2 = OFF, CHG<br>= OFF, DSG = source follower mode, no<br>communication,**Power:Sleep:Voltage Time**= 5<br>s||24||µA|
|IDEEPSLEEP_1|DEEPSLEEP Mode|No monitoring or protections, REG1 = 3.3 V<br>with no load, REG2 = OFF, LFO = ON, no<br>communication||10.7||µA|
|IDEEPSLEEP_2|DEEPSLEEP Mode|No monitoring or protections, REG1 = 3.3 V<br>with no load, REG2 = OFF, LFO = OFF, no<br>communication||9.2||µA|
|ISHUTDOWN|SHUTDOWN Mode|All blocks powered down, with the exception<br>of the TS2 wakeup circuit, no monitoring or<br>protections, no communication||1|3.1|µA|



Copyright © 2021 Texas Instruments Incorporated 

10 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **7.6 Digital I/O** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VIH|High-level input|ALERT (configured as HDQ), SCL, SDA,<br>HDQ, CFETOFF, DFETOFF, RST_SHUT|0.66 x<br>VREG18||5.5|V|
|VIL|Low-level input|ALERT (configured as HDQ), SCL, SDA,<br>HDQ, CFETOFF, DFETOFF, RST_SHUT|||0.33 x<br>VREG18|V|
|VOH|Output voltage high, TS2|TS2 during SHUTDOWN mode, VBAT> 6<br>V|4.5||6|V|
|VOH|Output voltage high, TS2 low voltage|TS2 during SHUTDOWN mode, 4.7 V ≤<br>VBAT≤ 6 V|3||6|V|
|VOH|Output voltage high, 5 V case|ALERT, SDA (configured as SPI_MISO),<br>CFETOFF (configured as GPO),<br>DFETOFF (configured as GPO), DCHG,<br>DDSG pins driving from REG1, VREG1set<br>to 5 V nominal setting, VBAT> 8 V, IOH=<br>5.0 mA, 10 pF load|0.9 x<br>VREG1||VREG1|V|
|VOL|Output voltage low, 5 V case|ALERT, SCL, SDA, HDQ, DCHG,<br>DDSG, CFETOFF (configured as GPO),<br>DFETOFF (configured as GPO), pins<br>driving from REG1, VREG1set to 5 V<br>nominal setting, VBAT> 8 V, IOL= -5 mA,<br>10 pF load|||0.77|V|
|ROH|Output weak high resistance|TS2 during SHUTDOWN mode||4600||kΩ|
|CIN|Input capacitance<sup>(1)</sup>|ALERT, SCL, SDA, HDQ, CFETOFF,<br>DFETOFF, DCHG, DDSG, REGIN, TS1,<br>TS2, TS3||2||pF|
|ILKG|Input leakage current|ALERT, SCL, SDA, HDQ, CFETOFF,<br>DFETOFF, DCHG, DDSG, REGIN, device<br>in SHUTDOWN mode|||1|µA|



(1) Specified by design 

#### **7.7 LD Pin** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|I(PULLUP)|Internal pullup current from BAT pin to LD<br>pin, used for load detect functionality|VBAT≥ 4.7 V, VLD= VSS|35|100|172|µA|
|RPD|Internal pulldown resistance on LD pin in<br>SHUTDOWN mode|VBAT≥ 4.7 V||80||kΩ|



#### **7.8 Precharge (PCHG) and Predischarge (PDSG) FET Drive** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|V(PCHG_ON)|Output voltage, PCHG on|max(VPACK, VBAT)- VPCHG, VPACK≥ 8 V,<br>VBAT≥ 4.7 V|7.5|8.4|9.7|V|
|V(PCHG_ON)|Output voltage, PCHG on|VPACK- VPCHG, 4.7 V ≤ VPACK< 8 V, VBAT<br>≥ 4.7 V, VPACK> VBAT|VPACK–<br>0.5 V||VPACK|V|
|V(PDSG_ON)|Output voltage, PDSG on|max(VLD, VBAT) - VPDSG, VBAT≥ 8 V|7.47|8.4|9.7|V|
|V(PDSG_ON)|Output voltage, PDSG on|VBAT- VPDSG, 4.7 V ≤ VBAT< 8 V, VBAT><br>VLD|VBAT–<br>0.5 V||VBAT|V|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 11 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|I(PULLDOWN)|Current sink capability, PCHG and<br>PDSG|PCHG and PDSG enabled, VBAT= 37.0 V||30||µA|



#### **7.9 FUSE Pin Functionality** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|V(OH)|Output voltage high (when driving fuse)|VBAT≥ 8 V, CL= 1 nF, 5 kΩ load.|6|7|9|V|
|V(OH)|Output voltage high (when driving fuse)|4.7 V ≤ VBAT< 8 V, CL= 1 nF, 5 kΩ load.|VBAT–<br>1.75|||V|
|V(IH)|High-level input (for fuse detection)|Current into device pin must be limited to<br>maximum 2 mA|2||12|V|
|V(IL)|Low-level input (for fuse detection)||||0.7|V|
|t(RISE)|Output rise time (when driving fuse)|VBAT≥ 8 V, CL= 1 nF, RSERIES= 100<br>Ω, V(OH)= 10% to 90% of final settled<br>voltage||0.5||µs|



#### **7.10 REG18 LDO** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|CREG18|External capacitor, REG18 to VSS<sup>(1)</sup>||1.8|2.2|22|µF|
|VREG18|Regulator voltage||1.6|1.8|2|V|
|ΔVO(TEMP)|Regulator output over temperature|ΔVREG18vs (VREG18at 25°C), IREG18= 1<br>mA, VBAT= 37.0 V||±0.15||%|
|ΔVO(LINE)|Line regulation|ΔVREG18vs (VREG18at 25°C, VBAT= 37.0<br>V), IREG18= 1 mA, as VBATvaries across<br>specified range|–0.6||0.5|%|
|ΔVO(LOAD)|Load regulation|ΔVREG18vs (VREG18, VBAT= 37.0 V),<br>IREG18= 0 mA to 1 mA, at 25°C|–1.5||1.5|%|
|ISC|Regulator short-circuit current limit|VREG18= 0 V|3||14|mA|



(1) Specified by design 

#### **7.11 REG0 Pre-regulator** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VBREG_HDRM|Pre-regulator control voltage<br>headroom ( min(VBAT- VBREG) )|VBAT≥ 4.7 V||1.5|1.9|V|
|VREGIN_INT|Pre-regulator voltage, when<br>generated using BREG|VBAT> 8 V, although specific requirement<br>depends on external device selected|5|5.5|5.8|V|
|VREGIN_EXT|Pre-regulator voltage when using<br>externally supplied REGIN<sup>(3)</sup>|See requirements based on settings of<br>REG1 and REG2|||5.5|V|
|ΔVO(TEMP)|Regulator output over temperature|ΔVREGINvs VREGINat 25°C, IREGIN= 50<br>mA, VBAT> 8 V||±0.05||%|
|IMax|Maximum current driven out from<br>BREG|Under short circuit conditions (VREGIN= 0<br>V)|2.5|3.33||mA|
|CEXT|External capacitor REGIN to VSS<sup>(2)</sup><br>(3)||15|22|27|nF|



Copyright © 2021 Texas Instruments Incorporated 

12 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|CBREG|External capacitor BREG to VSS<sup>(3)</sup>||||150|pF|



- (1) Supported output current is limited for VSTACK < 5.5 V. VREGIN limited to 2.5 V below VBAT. 

- (2) Capacitance should be above 7 nF after consideration for aging and derating. 

(3) Specified by design 

#### **7.12 REG1 LDO** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VREG1_1.8|Regulator voltage (nominal 1.8V setting)|VREGIN≥ 3.0 V, IREG1= 0 mA to 45 mA|1.6|1.84|2|V|
|VREG1_2.5|Regulator voltage (nominal 2.5V setting)|VREGIN≥ 3.5 V, IREG1= 0 mA to 45 mA|2.25|2.55|2.75|V|
|VREG1_3.0|Regulator voltage (nominal 3.0V setting)|VREGIN≥ 3.8 V, IREG1= 0 mA to 45 mA|2.7|3.05|3.3|V|
|VREG1_3.3|Regulator voltage (nominal 3.3V setting)|VREGIN≥ 4.1 V, IREG1= 0 mA to 45 mA|3.0|3.36|3.6|V|
|VREG1_5.0|Regulator voltage (nominal 5.0V setting)|VREGIN≥ 5.0 V, IREG1= 0 mA to 45 mA|4.5|5.19|5.5|V|
|ΔVO(TEMP)|Regulator output over temperature|ΔVREG1vs (VREG1at 25°C, IREG1=<br>20 mA, VREGIN= 5.5 V, VREG1set to<br>nominal 3.3 V setting)||±0.25||%|
|ΔVO(LINE)|Line regulation|ΔVREG1vs (VREG1at 25°C, VREGIN=<br>5.5 V, IREG1= 20 mA), as VREGINvaries<br>from 5 V to 6 V, VREG1set to nominal<br>3.3 V setting|–1||1|%|
|ISC|Regulator short-circuit current limit|VREG1= 0 V|47||80|mA|
|CEXT|External capacitor REG1 to VSS<sup>(1)</sup>||1|||µF|



(1) Specified by design 

#### **7.13 REG2 LDO** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VREG2_1.8|Regulator voltage (nominal 1.8V setting)|VREGIN≥ 3.0 V, IREG2= 0 mA to 45 mA|1.6|1.84|2|V|
|VREG2_2.5|Regulator voltage (nominal 2.5V setting)|VREGIN≥ 3.5 V, IREG2= 0 mA to 45 mA|2.25|2.55|2.75|V|
|VREG2_3.0|Regulator voltage (nominal 3.0V setting)|VREGIN≥ 3.8 V, IREG2= 0 mA to 45 mA|2.7|3.06|3.3|V|
|VREG2_3.3|Regulator voltage (nominal 3.3V setting)|VREGIN≥ 4.1 V, IREG2= 0 mA to 45 mA|3.0|3.38|3.6|V|
|VREG2_5.0|Regulator voltage (nominal 5.0V setting)|VREGIN≥ 5.0 V, IREG2= 0 mA to 45 mA|4.5|5.23|5.5|V|
|ΔVO(TEMP)|Regulator output over temperature|ΔVREG2vs (VREG2at 25°C, IREG2=<br>20 mA, VREGIN= 5.5 V, VREG2set to<br>nominal 3.3 V setting)||±0.25||%|
|ΔVO(LINE)|Line regulation|ΔVREG2vs (VREG2at 25°C, VREGIN=<br>5.5 V, IREG2= 20 mA), as VREGINvaries<br>from 5 V to 6 V, VREG2set to nominal<br>3.3 V setting|–1||1|%|
|ISC|Regulator short-circuit current limit|VREG2= 0 V|47||80|mA|
|CEXT|External capacitor REG2 to VSS<sup>(1)</sup>||1|||µF|



(1) Specified by design 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 13 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

#### **7.14 Voltage References** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|**VOLTAGE R**|**EFERENCE 1**||||||
|V(REF1)|Internal reference voltage<sup>(1)</sup>|TA= 25°C|1.210|1.212|1.214|V|
|V(REF1DRIFT)|Internal reference voltage drift<sup>(1)</sup> <sup>(3)</sup>|TA= -10°C to 60°C||±10||PPM/°C|
|V(REF1DRIFT)|Internal reference voltage drift<sup>(1)</sup> <sup>(3)</sup>|TA= -40°C to 85°C||±10||PPM/°C|
|**VOLTAGE R**|**EFERENCE 2**||||||
|V(REF2)|Internal reference voltage<sup>(2)</sup>|TA= 25°C|1.23|1.24|1.25|V|
|V(REF2DRIFT)|Internal reference voltage drift<sup>(2)</sup> <sup>(3)</sup>|TA= -10°C to 60°C||±20||PPM/°C|
|V(REF2DRIFT)|Internal reference voltage drift<sup>(2)</sup> <sup>(3)</sup>|TA= -40°C to 85°C||±50||PPM/°C|



- (1) V(REF1) is used for the ADC reference. Its effective value is determined through indirect measurement using the ADC and measuring the differential voltage on VC1 - VC0. 

- (2) V(REF2) is used for the LDO, coulomb counter, and current measurement 

- (3) Specified by characterization 

#### **7.15 Coulomb Counter** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

|**PAR**|**AMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|V(CC_IN)|Input voltage range<br>for measurements<sup>(3)</sup>|VSRP- VSRN|–0.2||0.2|V|
|V(CC_IN)|Input voltage range<br>for measurements<sup>(3)</sup>|VSRP, VSRN|–0.2||0.2|V|
|B(CC_INL)|Integral nonlinearity<sup>(2) </sup>|16-bit, best fit over input voltage range||±5.2|±22.3|LSB<sup>(1)</sup>|
|B(CC_DNL)|Differential<br>nonlinearity<sup>(2)</sup>|16-bit, no missing codes||±0.1||LSB<sup>(1)</sup>|
|V(CC_OFF)|Offset error|16-bit, uncalibrated|–1||1|LSB<sup>(1)</sup>|
|V(CC_OFF_DRIFT)|Offset error drift<sup>(2)</sup>|16-bit, post-calibration|–0.03||0.03|LSB/°C<sup>(1)</sup>|
|B(CC_GAIN)|Gain<sup>(2)</sup>|16-bit, over ideal input voltage range|130845|131454|132335|LSB/V<sup>(1)</sup>|
|R(CC_IN)|Effective input<br>resistance<sup>(3)</sup>|||2||MΩ|



- (1) 1 LSB (16-bit mode, using CC1 filter) = VREF2 / (5 x 2<sup>N-1</sup> ) ≈ 1.24 / (5 x 2<sup>15</sup> ) = 7.6µV 

- (2) Specified by characterization 

- (3) Specified by design 

#### **7.16 Coulomb Counter Digital Filter (CC1)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|t(CC1_CONV_FAST)|Conversion-time|Single conversion (when operating from<br>LFO in 262.144kHz mode)||250||ms|
|t(CC1_CONV_SLOW)|Conversion-time|Single conversion (when operating from<br>LFO in 32.768kHz mode)||4||s|
|B(CC1_RSL)|Code stability<sup>(1)</sup> <sup>(2)</sup>|Single conversion|14.3|||bits|



- (1) Code stability is defined as the resolution such that the data exhibits 3-sigma variation within ±1-LSB. 

- (2) Specified by a combination of design and production test 

Copyright © 2021 Texas Instruments Incorporated 

14 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

###### **www.ti.com** 

#### **7.17 Current Measurement Digital Filter (CC2)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|t(CC2_CONV)|Conversion-time|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 0||2.93||ms|
|t(CC2_CONV_FAST)|Conversion-time in fast mode|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 1||1.46||ms|
|B(CC2_RES)|Code stability<sup>(1)</sup> <sup>(2)</sup>|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 0|14|15||bits|
|B(CC2_RES_FAST)|Code stability in fast mode<sup>(1)</sup>|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 1||13.5||bits|



(1) Code stability is defined as the resolution such that the data exhibits 3-sigma variation within ±1-LSB. 

(2) Specified by characterization 

#### **7.18 Current Wake Detector** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|VWAKE_THR|Wakeup voltage threshold error<sup>(1)</sup>|TA= 25°C, VWAKE= VSRP– VSRN, setting<br>between ±0.5 mV and ±5 mV.  Measured<br>using averaged data to remove effects of<br>noise.|–200||200|µV|
|VWAKE_THR|Wakeup voltage threshold error<sup>(1)</sup>|TA= 25°C, VWAKE= VSRP– VSRN,<br>setting beyond ±5 mV.  Measured using<br>averaged data to remove effects of noise.|–5||5|% of<br>setting|
|tWAKE|Measurement interval<sup>(1)</sup>|||12||ms|



(1) Specified by design 

#### **7.19 Analog-to-Digital Converter** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

|**PAR**|**AMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|V(ADC_IN_CELLS)|Input voltage range<br>(differential cell input<br>mode)<sup>(4)</sup>|Internal reference (Vref = VREF1)|–0.2||5.5|V|
|V(ADC_IN)|Input voltage range<br>(ADCIN measurement<br>mode)<sup>(5)</sup>|Internal reference (Vref = VREF1), applicable<br>to ADCIN measurements using the TS1, TS2,<br>TS3, ALERT, CFETOFF, DFETOFF, HDQ,<br>DCHG, and DDSG pins|–0.2||VREG18|V|
|V(ADC_IN_TS)|Input voltage range<br>(external thermistor<br>measurement mode)<br>(6)|Regulator reference (Vref = VREG18),<br>applicable to external thermistor<br>measurements using the TS1, TS2, TS3,<br>ALERT, CFETOFF, DFETOFF, HDQ, DCHG,<br>and DDSG pins|–0.2||VREG18|V|
|V(ADC_IN_DIV)|Input voltage range<br>(divider measurement<br>mode)<sup>(7)</sup>|Internal reference (Vref = VREF1), applicable<br>to divider measurements using the VC10,<br>PACK, and LD pins relative to VSS.|–0.2||55|V|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 15 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

#### **7.19 Analog-to-Digital Converter (continued)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

|**PARA**|**METER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
||Integral nonlinearity<br>|16-bit, best fit over -0.1 V to 5.5 V|–6.6||6.6|LSB<sup>(4)</sup>|
|B(ADC_INL)|(when using VREF1<br>and differential cell<br>voltage measurement<br>mode at VC10 - VC9)<br>(3)|16-bit, best fit over -0.2 V to 0.2 V|–4||4|LSB<sup>(4)</sup>|
|B(ADC_DNL)|Differential<br>nonlinearity|16-bit, no missing codes, using differential<br>cell voltage measurement at VC10-VC9||±0.12||LSB<sup>(4)</sup>|
|B(ADC_OFF_CELL)|Differential cell offset<br>error|16-bit, uncalibrated, using VC10 - VC9|–2.75||3.5|LSB<sup>(4)</sup>|
|B(ADC_OFF)|ADCIN offset error|16-bit, uncalibrated, using ADCIN mode on<br>TS1 pin||0.53||LSB<sup>(5)</sup>|
|B(ADC_OFF_DIV)|Divider offset error|16-bit, uncalibrated, using divider mode on<br>PACK pin||0.17||LSB<sup>(7)</sup>|
|B(ADC_OFF_DRIFT_CELL)|Differential cell offset<br>error drift<sup>(3)</sup>|Offset error measured 16-bit, post calibration,<br>using VC10 - VC9.  Drift measured as<br>change in offset over operating temperature<br>range as compared to offset at 30°C.||0.004|0.07|LSB/°C<sup>(4)</sup>|
|B(ADC_GAIN)|Gain|Gain measured 16-bit, over ideal input<br>voltage range, differential cell input mode on<br>VC10 - VC9, uncalibrated.|5385|5406|5427|LSB/V<sup>(4)</sup>|
|B(ADC_GAIN_DRIFT)|Gain drift<sup>(3)</sup>|Gain measured 16-bit, over ideal input<br>voltage range, differential cell input mode<br>on VC10 - VC9, uncalibrated.  Drift value<br>measured as change in gain over operating<br>temperature range, compared to gain at<br>30°C.|–0.25|0.025|0.25|LSB/V/<br>°C<sup>(4)</sup>|
|R(ADC_IN_CELL)|Effective input<br>resistance<sup>(2)</sup>|Differential cell input mode on VC10 - VC9<sup>(8)</sup>|3.0|||MΩ|
|R(ADC_IN_LD)|Effective input<br>resistance|Divider measurement on LD pin (only active<br>while the LD pin is being measured)||2||MΩ|
|R(ADC_IN_DIV)|Effective input<br>resistance|Divider measurement on VC10 and PACK<br>pins (only active while the pin is being<br>measured)||600||kΩ|
|B(ADC_RES)|Code stability<sup>(1)</sup> <sup>(3)</sup>|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 0|13.5|15||bits|
|B(ADC_RES_FAST)|Code stability in fast<br>mode<sup>(1)</sup>|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 1||14||bits|
|t(ADC_CONV)|Conversion-time|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 0||2.93||ms|
|t(ADC_CONV_FAST)|Conversion-time in<br>fast mode|Single conversion, in NORMAL<br>mode,**Settings:Configuration:Power**<br>**Config[FASTADC]**= 1||1.46||ms|



- (1) Code stability is defined as the resolution such that the data exhibits 3-sigma variation within ±1-LSB. 

(2) Specified by design 

- (3) Specified by characterization 

- (4) The 16-bit LSB size of the differential cell voltage measurement is given by 1 LSB = 5 x VREF1 / 2<sup>N-1</sup> ≈ 5 x 1.212 V / 2<sup>15</sup> = 185 µV 

- (5) The 16-bit LSB size of the ADCIN voltage measurement is given by 1 LSB = 5 / 3 x VREF1 / 2<sup>N-1</sup> ≈ 5 / 3 x 1.212 V / 2<sup>15</sup> = 62 µV 

- (6) The LSB size of the external thermistor voltage measurement when reported in 32-bit format is given by 1 LSB = 5 / 3 x VREG18 / 2<sup>N-1</sup> ≈ 5 / 3 x 1.8 V / 2<sup>23</sup> = 358 nV 

- (7) The 16-bit LSB size of the divider voltage measurement is given by 1 LSB = 425 / 3 x VREF1 / 2<sup>N-1</sup> ≈ 425 / 3 x 1.212 / 2<sup>15</sup> = 5.24 mV 

Copyright © 2021 Texas Instruments Incorporated 

16 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

- (8) Average effective differential input resistance with device operating in NORMAL mode, cell balancing disabled, three or more thermistors in use, and a 5 V differential voltage applied. 

#### **7.20 Cell Balancing** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|R(CB)|Internal cell balancing resistance<sup>(1)</sup>|RDS(ON)for internal FET switch at VVC(n)-<br>VVC(n-1)= 1.5V, 1 ≤ n ≤ 10, VBAT≥ 4.7 V|15|28|46|Ω|



- (1) Cell balancing must be controlled to limit the current based on the absolute maximum allowed current, and to avoid exceeding the recommended device operating temperature. This can be accomplished by appropriate sizing of the offchip cell input resistors and limiting the number of cells that can be balanced simultaneously. 

#### **7.21 Cell Open Wire Detector** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|I(OW)|Internal cell open wire check current from<br>VCx pin to VSS, 1 ≤ x ≤ 10|VCx > VSS + 0.8 V, 1 ≤ x ≤ 4; VCx > VSS<br>+ 2.8 V, 5 ≤ x ≤ 10|22|54|95|µA|



#### **7.22 Internal Temperature Sensor** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|V(TEMP)|Internal temperature sensor voltage drift|ΔVBEmeasurement||0.410||mV/°C|



#### **7.23 Thermistor Measurement** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

|**PAR**|**AMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|R|Internal pullup<br>|Setting for nominal 18-kΩ|14.4|18.3|21.6|kΩ|
|(TS_PU)|resistance<sup>(1)</sup>|Setting for nominal 180-kΩ|140|178|216|kΩ|
|R(TS_PAD)|Internal pad<br>resistance<sup>(2)</sup>|||526||Ω|
|R|Internal pullup<br>resistance chane|Change over -40°C/+85°C vs value at 25°C<br>for nominal 18-kΩ||±200||Ω|
|(TS_PU_DRIFT)|g<br>over temperature|Change over -40°C/+85°C vs value at 25°C<br>for nominal 180-kΩ||±2000||Ω|



- (1) The internal pullup resistance includes only the resistance between the REG18 pin and the point where the voltage is sensed by the ADC. 

- (2) The internal pad resistance includes the resistance between the point where the voltage is sensed by the ADC and the pin where an external thermistor is attached (which includes the TS1, TS2, TS3, ALERT, CFETOFF, DFETOFF, HDQ, DCHG, and DDSG pins) 

#### **7.24 Internal Oscillators** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

|**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|
|**High-frequency Oscillator**||||||
|fHFO<br>Operating frequency|||16.78||MHz|



Copyright © 2021 Texas Instruments Incorporated 

17 

_Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|f|Frequency error<sup>(2)</sup>|TA= –20°C to +70°C, includes frequency<br>drift|–3.0|±0.25|3.0|%|
|HFO(ERR)||TA= –40°C to +85°C, includes frequency<br>drift|–4.0|±0.25|4.0|%|
|f|Start-u time<sup>(1)</sup>|TA= –20°C to +85°C, at power-up from<br>SHUTDOWN or exiting DEEPSLEEP<br>mode, oscillator frequency within ±3% of<br>nominal|||4.3|ms|
|HFO(SU)|p|TA= –20°C to +85°C, cases other than<br>power-up from SHUTDOWN or exiting<br>DEEPSLEEP mode, oscillator frequency<br>within ±3% of nominal|||135|µs|
|**Low-freq**|**uency Oscillator**||||||
|f|Oeratin freuenc|Full-speed setting||262.144||kHz|
|LFO|pg qy|Low speed setting||32.768||kHz|
|f|F<sup>(2)</sup>|TA= –20°C to +70°C, includes frequency<br>drift|–1.5|±0.25|1.5|%|
|LFO(ERR)|requency error|TA= –40°C to +85°C, includes frequency<br>drift|–2.5|±0.25|2.5|%|
|fLFO(FAIL)|Failure detection frequency|Detects oscillator failure if the LFO<br>frequency falls below this level.|8.5|12|18|kHz|



(1) Specified by design 

(2) Specified by a combination of design and production test 

#### **7.25 High-Side NFET Drivers** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

|**PAR**|**AMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|V(FETON_HI)|CHG pin voltage<br>with respect to BAT,<br>DSG pin voltage with<br>respect to BAT, 8<br>V ≤ VBAT≤ 55 V,<br>VLD≤ VDSG <sup>(1)</sup>|CHG/DSG CL= 20 nF, charge pump high<br>overdrive setting|10|11|13|V|
|V(FETON_HI_LOBAT)|CHG pin voltage<br>with respect to BAT,<br>DSG pin voltage with<br>respect to BAT, 4.7<br>V ≤ VBAT< 8 V, VLD≤<br>VDSG <sup>(1)</sup>|CHG/DSG CL= 20 nF, charge pump high<br>overdrive setting|8|11|13|V|
|V(FETON_LO)|CHG pin voltage<br>with respect to BAT,<br>DSG pin voltage with<br>respect to BAT, 8<br>V ≤ VBAT≤ 55 V,<br>VLD≤ VDSG <sup>(1)</sup>|CHG/DSG CL= 20 nF, charge pump low<br>overdrive setting|4.5|5.7|7|V|
|V(FETON_LO_LOBAT)|CHG pin voltage<br>with respect to BAT,<br>DSG pin voltage with<br>respect to BAT, 4.7<br>V ≤ VBAT< 8 V, VLD≤<br>VDSG <sup>(1)</sup>|CHG/DSG CL= 20 nF, charge pump low<br>overdrive setting|3.5|5|7|V|
|V(SRCFOL_FETON)|DSG on voltage with<br>respect to BAT|CHG/DSG CL= 20 nF, source follower mode||0||V|



Copyright © 2021 Texas Instruments Incorporated 

18 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PA**|**RAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|---|
|V(CHGFETOFF)||CHG off voltage with<br>respect to BAT|CHG/DSG CL= 20 nF, steady state value|||0.4|V|
|V(DSGFETOFF)||DSG off voltage with<br>respect to LD|CHG/DSG CL= 20 nF, steady state value|||0.7|V|
|t(FET_ON)||CHG and DSG rise<br>time|CHG/DSG CL= 20 nF, RGATE= 100 Ω, 0.5<br>V to 4 V gate-source overdrive, charge pump<br>mode<sup>(3)</sup> <sup>(4)</sup>||21|40|µs|
|t(CHGFETOFF)||CHG fall time to BAT|CHG CL= 20 nF, RGATE= 100 Ω, 90% to<br>10% of V(FETON) <sup>(4)</sup>||46|65|µs|
|t(DSGFETOFF)||DSG fall time to LD|DSG CL= 20 nF, RGATE= 100 Ω, 90% to 10%<br>of V(FETON) <sup>(4)</sup>||2|20|µs|
|t(CP_START)||Charge pump start up<br>time|CL= 20 nF, C(CP1)= 470 nF, 10% to 90% of<br>V(FETON)|||100|ms|
|C(CP1)||Charge pump<br>capacitor<sup>(2)</sup>||100|470|2200|nF|



- (1) When the DSG driver is enabled, the CHG driver is disabled, and a voltage is applied at the LD pin such that VLD > VDSG, the voltage at DSG will rise to ≈ VLD - 0.7 V 

- (2) Specified by design 

- (3) Specified by characterization 

(4) RGATE can be optimized during design and system evaluation for best performance.  A larger value may be desired to avoid an overly fast FET turn off, which can result in a large voltage transient due to cell and harness inductance. 

#### **7.26 Comparator-Based Protection Subsystem** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**<br>**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|
|V(OVP)|Overvoltage detection range|Nominal setting (50.6 mV steps)|1.012 V<br>to 5.566<br>V in 50.6<br>mV steps||V|
|||TA= +25°C, nominal setting between<br>1.012 V and 5.566 V<sup>(1)</sup>|±2||mV|
|||TA= +25°C, nominal setting between<br>3.036 V and 5.06 V<sup>(1)</sup>|–10|10|mV|
|V|Overvoltage detection voltage<br>|TA= –10°C to +60°C, nominal setting<br>between 1.012 V and 5.566 V<sup>(1)</sup>|±3||mV|
|(OVP_ACC)|threshold accuracy<sup>(3)</sup>|TA= –10°C to +60°C, nominal setting<br>between 3.036 V and 5.06 V<sup>(1)</sup>|–15|15|mV|
|||TA= –40°C to +85°C, nominal setting<br>between 1.012 V and 5.566 V<sup>(1)</sup>|±5||mV|
|||TA= –40°C to +85°C, nominal setting<br>between 3.036 V and 5.06 V<sup>(1)</sup>|–25|25|mV|
|V(OVP_DLY)|Overvoltage detection delay<sup>(2)</sup>|Nominal setting (3.3 ms steps)|10 ms to<br>6753 ms<br>in 3.3 ms<br>steps||ms|
|V(UVP)|Undervoltage detection range|Nominal setting (50.6 mV steps)|1.012 V<br>to 4.048<br>V in 50.6<br>mV steps||V|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 19 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**<br>**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|
|||TA= +25°C, nominal setting between<br>1.012 V and 4.048 V<sup>(1)</sup>|±1.3||mV|
|||TA= +25°C, nominal setting between<br>1.518 V and 3.542 V<sup>(1)</sup>|–10|10|mV|
|V|Undervoltage detection voltage<br>|TA= –10°C to +60°C, nominal setting<br>between 1.012 V and 4.048 V<sup>(1)</sup>|±1.4||mV|
|(UVP_ACC)|threshold accuracy<sup>(3)</sup>|TA= –10°C to +60°C, nominal setting<br>between 1.518 V and 3.542 V<sup>(1)</sup>|–15|15|mV|
|||TA= –40°C to +85°C, nominal setting<br>between 1.012 V and 4.048 V<sup>(1)</sup>|±1.6||mV|
|||TA= –40°C to +85°C, nominal setting<br>between 1.518 V and 3.542 V<sup>(1)</sup>|–25|25|mV|
|V(UVP_DLY)|Undervoltage detection delay<sup>(2)</sup>|Nominal setting (3.3 ms steps)|10 ms to<br>6753 ms<br>in 3.3 ms<br>steps||ms|
|V(SCD)|Short circuit in discharge voltage<br>threshold range|Nominal settings, threshold based on<br>VSRP- VSRN|–10,<br>–20,<br>–40,<br>–60,<br>–80,<br>–100,<br>–125,<br>–150,<br>–175,<br>–200,<br>–250,<br>–300,<br>–350,<br>–400,<br>–450,<br>–500||mV|
|V|Short circuit in discharge voltage<br>|TA= –40°C to +85°C, V(SCD)settings ≤<br>–20 mV|–15|15|% of<br>nominal<br>threshold|
|(SCD_ACC)|threshold detection accuracy<sup>(3)</sup>|TA= –40°C to +85°C, V(SCD)settings ><br>–20 mV|–35|35|% of<br>nominal<br>threshold|
|||Fastest setting (with 3 mV on VSRN–<br>VSRP)|8||µs|
|V(SCDDLY)|Short circuit in discharge detection<br>|Fastest setting (with 25 mV on VSRN–<br>VSRP)|600||ns|
|_|delay|Nominal setting (15 µs steps)|15 µs to<br>450 µs in<br>15 µs<br>steps||µs|
|V(OCC)|Overcurrent in charge (OCC) voltage<br>threshold range|Nominal settings, threshold based on<br>VSRP– VSRN|4 mV to<br>124 mV<br>in 2 mV<br>steps||mV|
|V(OCD)|Overcurrent in discharge (OCD1,<br>OCD2) voltage threshold ranges|Nominal settings, thresholds based on<br>VSRP– VSRN|–4 mV to<br>–200 mV<br>in 2 mV<br>steps||mV|



Copyright © 2021 Texas Instruments Incorporated 

20 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
||||Setting| < 20 mV|–2||2.65|mV|
|V|Overcurrent (OCC, OCD1, OCD2)<br>detection voltage threshold||Setting| = 20 mV ~ 56 mV|–4||4|mV|
|(OC_ACC)|<br>accuracy<sup>(3)</sup>||Setting| = 56 mV ~ 100 mV|–5||5|mV|
||||Setting| > 100 mV|–7||5|mV|
|V(OC_DLY)|Overcurrent (OCC, OCD1, OCD2)<br>detection delay (independent delay<br>setting for each protection)|Nominal setting (3.3 ms steps)||10 ms to<br>425 ms<br>in 3.3 ms<br>steps||ms|



- (1) Measured by fault triggered using 100 ms detection delay. 

(2) Cell balancing not active. Timing of overvoltage and undervoltage protection checks is modified when cell balancing is in progress. 

(3) Specified by a combination of characterization and production test 

#### **7.27 Timing Requirements – I**<sup>**2**</sup> **C Interface, 100kHz Mode** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|fSCL|Clock operating frequency<sup>(1)</sup>|SCL duty cycle = 50%|||100|kHz|
|tHD:STA|START condition hold time<sup>(1)</sup>||4.0|||µs|
|tLOW|Low period of the SCL clock<sup>(1)</sup>||4.7|||µs|
|tHIGH|High period of the SCL clock<sup>(1)</sup>||4.0|||µs|
|tSU:STA|Setup repeated START<sup>(1)</sup>||4.7|||µs|
|tHD:DAT|Data hold time (SDA input)<sup>(1)</sup>||0|||ns|
|tSU:DAT|Data setup time (SDA input)<sup>(1)</sup>||250|||ns|
|tr|Clock rise time<sup>(1)</sup>|10% to 90%|||1000|ns|
|tf|Clock fall time<sup>(1)</sup>|90% to 10%|||300|ns|
|tSU:STO|Setup time STOP condition<sup>(1)</sup>||4.0|||µs|
|tBUF|Bus free time STOP to START<sup>(1)</sup>||4.7|||µs|
|tRST|I<sup>2</sup>C bus reset<sup>(1)</sup>|Bus interface is reset if SCL is detected<br>low for this duration|1.9||2.1|s|
|RPULLUP|Pullup resistor<sup>(2)</sup>|Pullup voltage rail ≤ 5 V|1.5|||kΩ|



- (1) Specified by design 

- (2) Specified by characterization 

#### **7.28 Timing Requirements – I**<sup>**2**</sup> **C Interface, 400kHz Mode** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|fSCL|Clock operating frequency<sup>(1)</sup>|SCL duty cycle = 50%|||400|kHz|
|tHD:STA|START condition hold time<sup>(1)</sup>||0.6|||µs|
|tLOW|Low period of the SCL clock<sup>(1)</sup>||1.3|||µs|
|tHIGH|High period of the SCL clock<sup>(1)</sup>||600|||ns|
|tSU:STA|Setup repeated START<sup>(1)</sup>||600|||ns|
|tHD:DAT|Data hold time (SDA input)<sup>(1)</sup>||0|||ns|
|tSU:DAT|Data setup time (SDA input)<sup>(1)</sup>||100|||ns|
|tr|Clock rise time<sup>(1)</sup>|10% to 90%|||300|ns|
|tf|Clock fall time<sup>(1)</sup>|90% to 10%|||300|ns|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 21 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

#### **7.28 Timing Requirements – I**<sup>**2**</sup> **C Interface, 400kHz Mode (continued)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|tSU:STO|Setup time STOP condition<sup>(1)</sup>||0.6|||µs|
|tBUF|Bus free time STOP to START<sup>(1)</sup>||1.3|||µs|
|tRST|I<sup>2</sup>C bus reset<sup>(1)</sup>|Bus interface is reset if SCL is detected<br>low for this duration|1.9||2.1|s|
|RPULLUP|Pullup resistor<sup>(2)</sup>|Pullup voltage rail ≤ 5 V|1.5|||kΩ|



- (1) Specified by design 

(2) Specified by characterization 

#### **7.29 Timing Requirements – HDQ Interface** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted) 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|tB|Break Time<sup>(1)</sup>||190|||µs|
|tBR|Break Recovery Time<sup>(1)</sup>||40|||µs|
|tHW1|Host Write 1 Time<sup>(1)</sup>|Host drives HDQ|0.5||50|µs|
|tHW0|Host Write 0 Time<sup>(1)</sup>|Host drives HDQ|86||145|µs|
|tCYCH|Cycle Time, Host to device<sup>(1)</sup>|Device drives HDQ|190|||µs|
|tCYCD|Cycle Time, device to Host<sup>(1)</sup>|Device drives HDQ|190|205|250|µs|
|tDW1|Device Write 1 Time<sup>(1)</sup>|Device drives HDQ|32||50|µs|
|tDW0|Device Write 0 Time<sup>(1)</sup>|Device drives HDQ|80||145|µs|
|tRSPS|Device Response Time<sup>(1)</sup> <sup>(3)</sup>|Device drives HDQ|190|||µs|
|tTRND|Host Turn Around Time<sup>(1)</sup>|Host drives HDQ after device drives HDQ|210|||µs|
|tRISE|HDQ Line Rising Time to Logic 1<sup>(1)</sup>||||1.8|µs|
|tRST|HDQ Bus Reset<sup>(1)</sup>|Host holds bus low to initiate device<br>interface reset|1.9||2.1|s|
|RPULLUP|Pullup Resistor<sup>(2)</sup>|Pullup voltage rail ≤ 5 V|1.5|||kΩ|



- (1) Specified by design 

(2) Specified by characterization 

(3) Response time may vary due to internal device processing 

#### **7.30 Timing Requirements – SPI Interface** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted).  All values specified with SPI pin filtering enabled. 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|tSCK|SPI clock period<sup>(1)</sup>||500<sup>(4)</sup>|||ns|
|tLEAD|Enable lead-time<sup>(1)</sup>||625|||ns|
|tLAG|Enable lag time<sup>(1)</sup>||50|||ns|
|tTD|Sequential transfer delay<sup>(2)</sup>|||50||µs|
|tSU|Data setup time<sup>(1)</sup> <sup>(5)</sup>||50|||ns|
|tHI|Data hold time (inputs)<sup>(1)</sup> <sup>(5)</sup>||50|||ns|
|tHO|Data hold time (outputs)<sup>(1)</sup>||0|||ns|
|tA|Responder access time<sup>(1)</sup>||||500|ns|
|tDIS|Responder DOUT disable time<sup>(1)</sup>||||450|ns|
|tV|Data valid<sup>(1)</sup>||||235<sup>(4)</sup>|ns|



Copyright © 2021 Texas Instruments Incorporated 

22 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **7.30 Timing Requirements – SPI Interface (continued)** 

Typical values stated where TA = 25°C and VBAT = 55.0 V, min/max values stated where TA = -40°C to 85°C and VBAT = 4.7 V to 55 V (unless otherwise noted).  All values specified with SPI pin filtering enabled. 

||**PARAMETER**|**TEST CONDITIONS**|**MIN**|**TYP**|**MAX**|**UNIT**|
|---|---|---|---|---|---|---|
|tR|Rise time<sup>(1)</sup>|Up to 25pF load|||30|ns|
|tF|Fall time<sup>(1)</sup>|Up to 25pF load|||30|ns|
|tRST|SPI bus reset<sup>(1)</sup>|Bus interface is reset if SPI_CS<br>is low and SPI_SCLK is detected<br>unchanged for this duration|1.9||2.1|s|



- (1) Specified by design 

- (2) See later discussion in datasheet for more details 

- (3) Specified by characterization 

- (4) This assumes 15 ns setup time on the SPI controller for MISO.  If additional setup time is required, the clock period should be extended accordingly. 

- (5) When SPI pin filtering is enabled, pulses on input pins of duration below 200 ns may be filtered out. 

#### **7.31 Interface Timing Diagrams** 



<!-- Start of picture text -->
SDA<br>tBUF<br>tf tLOW tHD;STA tr<br>tr tf tSP<br>SCL<br>tHD;STA tSU;STA tSU;STO<br>tHIGH<br>tHD;DAT tSU;DAT<br>START REPEATED STOP START<br>START<br>Figure 7-1. I 2 C Communications Interface Timing<br>SPI_CS<br>t TD<br>S<br>tLEAD t SCK tLAG<br>tR tF<br>tsckl<br>SPI_SCLK tsckh<br>tHO tV<br>tDIS<br>SPI_MISO MSB OUT BITN-2«�%,71 LS B O U T<br>tA<br>tSU tHI<br>SPI_MOSI<br>M SB IN BITN-2«�%,71 LSB IN<br><!-- End of picture text -->

**Figure 7-2. SPI Communications Interface Timing** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 23 

Product Folder Links: _BQ76942_ 

**BQ76942** 



<!-- Start of picture text -->
SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 www.ti.com<br>1.2 V<br>t(B) t(BR) t(RISE)<br>(a) Break and Break Recovery (b) HDQ Line Rise Time<br>T(HW1) T(DW1)<br>T(HW0) T(DW0)<br>T(CYCH) T(CYCD)<br>(c) HDQ Host Transmitted Bit (d) Device Transmitted Bit<br>1-bit<br>Break 7-bit address 7-bit address<br>R/W<br>t(RSPS)<br>(e) Device to HDQ Host Response<br>t(RST)<br>(f) HDQ Reset<br>a. HDQ Breaking<br>b. Rise time of HDQ line<br>c. HDQ Host to Device communication<br>d. Device to HDQ Host communication<br>e. Device to HDQ Host response format<br>f.  HDQ Host to Device<br><!-- End of picture text -->

**Figure 7-3. HDQ Communications Interface Timing** 

Copyright © 2021 Texas Instruments Incorporated 

24 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **7.32 Typical Characteristics** 



**Figure 7-4. Cell Voltage Measurement Error at 25°C Across Input Range** 



**Figure 7-6. Cell Voltage Measurement Error vs. Temperature with Cell Voltage = 2.5 V** 



**Figure 7-8. Cell Voltage Measurement Error vs. Temperature with Cell Voltage = 4.5 V** 



**Figure 7-5. Cell Voltage Measurement Error vs. Temperature with Cell Voltage = 1.5 V** 



**Figure 7-7. Cell Voltage Measurement Error vs. Temperature with Cell Voltage = 3.5 V** 



**Figure 7-9. Cell Voltage Measurement Error vs. Temperature with Cell Voltage = 5.5 V** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 25 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
www.ti.com<br><!-- End of picture text -->





<!-- Start of picture text -->
Error in measurement of differential voltage between SRP and<br>SRN pins.<br><!-- End of picture text -->



**Figure 7-11. Internal Voltage References vs. Temperature (VREF1 and VREF2)** 

**Figure 7-10. Current Measurement Error vs. Temperature** 



**Figure 7-12. Internal Temperature Sensor (Delta VBE) Voltage vs. Temperature** 

LFO measured in full speed mode (262 kHz) **Figure 7-13. Low Frequency Oscillator (LFO) Accuracy vs. Temperature** 

Copyright © 2021 Texas Instruments Incorporated 

26 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
Figure 7-14. High Frequency Oscillator (HFO)  Figure 7-15. Overcurrent in Discharge Protection 1<br>Accuracy vs. Temperature (OCD1) Threshold vs. Temperature<br>Figure 7-16. Overcurrent in Charge Protection  Figure 7-17. Cell Balancing Resistance vs.<br>(OCC) Threshold vs. Temperature Temperature<br><!-- End of picture text -->

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 27 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
www.ti.com<br><!-- End of picture text -->



This test uses a resistor divider across the VCx pins to enable one common voltage to be scaled across the cell inputs. The top of the string is swept and captured as the cell voltage. 



**Figure 7-19. REG1 Voltage vs. Load at 25°C** 



<!-- Start of picture text -->
Figure 7-18. Cell Balancing Resistance vs. Cell<br>Common-Mode Voltage at 25°C<br><!-- End of picture text -->



<!-- Start of picture text -->
Figure 7-20. REG2 Voltage vs. Load at 25°C Figure 7-21. Thermistor Pullup Resistance vs.<br>Temperature (18-kΩ Setting)<br><!-- End of picture text -->

Copyright © 2021 Texas Instruments Incorporated 

28 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

###### **www.ti.com** 



**Figure 7-22. Thermistor Pullup Resistance vs. Temperature (180-kΩ Setting)** 



Error calculated as percentage of nominal gain across ±200mV input range 

**Figure 7-23. Coulomb Counter Gain Error vs. Temperature** 



**Figure 7-24. LD Wake Voltage vs. Temperature** 



<!-- Start of picture text -->
1.835<br>1.83 BAT=4.7V, 0mA BAT=4.7V, 1mA<br>BAT=8V, 0mA BAT=8V, 1mA<br>1.825 BAT=10V, 0mA BAT=10V, 1mA<br>BAT=20V, 0mA BAT=20V, 1mA<br>1.82 BAT=25.9V, 0mA BAT=25.9V, 1mA<br>1.815 BAT=40V, 0mA BAT=40V, 1mA<br>BAT=60V, 0mA BAT=60V, 1mA<br>1.81<br>1.805<br>1.8<br>1.795<br>1.79<br>1.785<br>1.78<br>-40 -20 0 20 40 60 80 100<br>Temp (°C)<br>Voltage (V)<br><!-- End of picture text -->

**Figure 7-26. REG18 Voltage vs. Temperature, across BAT Levels** 

**Figure 7-25. REG18 Voltage vs. Temperature, with No Load** 





<!-- Start of picture text -->
Measurements taken using external BJT<br><!-- End of picture text -->

**Figure 7-27. REGIN Voltage vs. BAT Voltage** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 29 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
www.ti.com<br><!-- End of picture text -->





<!-- Start of picture text -->
Figure 7-28. BAT Current in NORMAL Mode vs.<br>Temperature<br><!-- End of picture text -->





<!-- Start of picture text -->
Figure 7-29. BAT Current in SHUTDOWN Mode vs.<br>Temperature<br><!-- End of picture text -->



<!-- Start of picture text -->
Figure 7-30. BAT Current in SLEEP2 (SRC  Figure 7-31. BAT Current in DEEPSLEEP2 (No<br>Follower) Mode vs. Temperature LFO) Mode vs. Temperature<br><!-- End of picture text -->

Copyright © 2021 Texas Instruments Incorporated 

30 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **8 Device Description** 

#### **8.1 Overview** 

The BQ76942 product is a highly integrated, accurate battery monitor and protector for 3-series to 10-series Li-ion, Li-polymer, and LiFePO4 battery packs. A high accuracy voltage, current, and temperature measurement accuracy provides data for host-based algorithms and control. A feature-rich and highly configurable protection subsystem provides a wide set of protections that can be triggered and recovered completely autonomously by the device or under full control of a host processor. The integrated charge pump with high-side protection NFET drivers enables host communication with the device even when FETs are off by preserving the ground connection to the pack. Dual programmable LDOs are included for external system use, with each independently programmable to voltages of 1.8 V, 2.5 V, 3.0 V, 3.3 V, and 5.0 V, capable of providing up to 45 mA each. 

The BQ76942 device includes one-time-programmable (OTP) memory for customers to setup device operation on their own production line. Multiple communications interfaces are supported, including 400-kHz I<sup>2</sup> C, SPI, and HDQ one-wire standards. Multiple digital control and status data are available through several multifunction pins on the device, including an interrupt to the host processor, and independent controls for host override of each high-side protection NFET. Three dedicated pins are provided for temperature measurement using external thermistors. Additionally, multifunction pins can be programmed to use additional thermistors, with the device supporting a total of up to nine thermistors. An internal die temperature measurement is also provided. 

#### **8.2 BQ76942 Device Versions** 

The BQ76942 device family includes several versions with differing default settings programmed during factory test. These different settings, which may include having a different default communications interface or a different setting for the REG1 LDO, are described in the _Device Comparison Table_ . 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 31 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **8.3 Functional Block Diagram** 



<!-- Start of picture text -->
a2<br>35 o z228<br>{+ i, {+t} Ht<br>en [11]<br>Pack C} Charger rota [I rsiaocinaro<br>ve| veer<br>vos SE ee<br>vet [}<br>veo TI RSCNIGPO<br>tsowae1s3 FRFh{I Digtal core Tl ancinicroALERTHDOTS!<br>{ ] SDA/SPI_MISO-<br>{]<br>aa<br>vea_f ° : m veo =!TIRsr_stur——<br>ve3 5g vcB [reste]<br>i Fuse, Load Detect<br>fa OTP,<br>[Coulomb Counter&|<br>ver vcs Waksup<br>4 dt<br>B 3 2<br><!-- End of picture text -->

#### **8.4 Diagnostics** 

The BQ76942 device includes a suite of diagnostic tests which can be used by the system to improve robustness of operation. These include comparisons between the two voltage references integrated within the device, a hardware monitor of the LFO frequency, memory checks at power-up or reset, an internal watchdog on the embedded processor, and more. These are described in detail in the _BQ76942 Technical Reference Manual_ . 

Copyright © 2021 Texas Instruments Incorporated 

32 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **9 Device Configuration** 

#### **9.1 Commands and Subcommands** 

The BQ76942 device includes support for direct commands and subcommands. The direct commands are accessed using a 7-bit command address that is sent from a host through the device serial communications interface and either triggers an action, or provides a data value to be written to the device, or instructs the device to report data back to the host. Subcommands are additional commands that are accessed indirectly using the 7-bit command address space and provide the capability for block data transfers. For more information on the commands and subcommands supported by the device, refer to the _BQ76942 Technical Reference Manual_ . 

#### **9.2 Configuration Using OTP or Registers** 

The BQ76942 device includes registers, with values which are stored in the RAM and can be loaded automatically from one-time programmable (OTP) memory. At initial power-up, the device loads OTP settings into registers, which are used by the device firmware during operation. The recommended procedure is for the customer to write settings into OTP on the manufacturing line, in which case the device will use these settings whenever it is powered up. Alternatively, the host processor can initialize registers after power-up, without using the OTP memory, but the registers will need to be reinitialized after each power cycle of the device. Register values are preserved while the device is in NORMAL, SLEEP, or DEEPSLEEP modes. If the device enters SHUTDOWN mode, all register memory is cleared, and the device will return to the default parameters (or the OTP configuration if that has been programmed) when powered again. See the _BQ76942 Technical Reference Manual_ for more details. 

#### **9.3 Device Security** 

The BQ76942 device includes three security modes: SEALED, UNSEALED, and FULLACCESS, which can be used to limit the ability to view or change settings. 

- In SEALED mode, most data and status can be read using commands and subcommands, but only selected settings can be changed. Data memory settings cannot be changed directly. 

- UNSEALED mode includes SEALED functionality, and also adds the ability to execute additional subcommands, and read and write data memory. 

- FULLACCESS mode allows capability to read and modify all device settings, including writing OTP memory. 

Selected settings in the device can be modified while the device is in operation through supported commands and subcommands, but in order to modify all settings, the device must enter CONFIG_UPDATE mode (see _CONFIG_UPDATE Mode_ ), which stops device operation while settings are being updated. After the update is completed, operation is restarted using the new settings. CONFIG_UPDATE mode is only available in FULLACCESS mode. 

The BQ76942 device implements a key-access scheme to transition among SEALED, UNSEALED, and FULLACCESS modes. Each transition requires that a unique set of keys be sent to the device through subcommands. Refer to the _BQ76942 Technical Reference Manual_ for more details. 

The device provides additional checks which can be used to optimize system robustness, including subcommands which calculate the digital signature of the integrated instruction ROM and data ROM. These signatures should never change for a particular product. If these were to change, it would indicate an error, either that the ROM had been corrupted, or the readback of the ROM or calculation of the signature experienced an error. An additional subcommand calculates a digital signature for the static configuration data (which excludes calibration values) and compares it to a stored value, returning a flag if the result does not match. 

#### **9.4 Scratchpad Memory** 

The BQ76942 device integrates a 32-byte scratchpad memory which can be used by the customer for storing manufacturing data, such as serial numbers, production or test dates, and so forth. The scratchpad data can be written into OTP memory on the customer production line. This data can only be written while in FULLACCESS mode, although it can be read in all modes. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 33 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **10 Measurement Subsystem** 

#### **10.1 Voltage Measurement** 

The BQ76942 device integrates a voltage ADC that is multiplexed between measurements of cell voltages, an internal temperature sensor, and up to nine external thermistors, as well as performs measurements of the voltage at the VC10 pin, the PACK pin, the LD pin, the internal REG18 LDO voltage, and the VSS rail (for diagnostic purposes). The BQ76942 device supports measurements of individual differential cell voltages in a series configuration, ranging from 3-series cells to 10-series cells. Each cell voltage measurement is a differential measurement of the voltage between two adjacent cell input pins, such as VC1–VC0, VC2–VC1, and so forth. The cell voltage measurements are processed based on trim and calibration corrections, and then reported in a 16-bit resolution using units of 1 mV. The raw 24-bit digital output of the ADC is also available for readout using 32-bit subcommands. The cell voltage measurements can support a recommended voltage range from –0.2 V to 5.5 V. The voltage ADC saturates at a level of 5 × VREF1 (approximately 6.06 V) when measuring cell voltages, although for the best performance, it is recommended to stay at a maximum input of 5.5 V. 

##### **10.1.1 Voltage Measurement Schedule** 

The BQ76942 device's voltage measurements are taken in a measurement loop that consists of multiple measurement slots. All 10 cell voltages are measured on each loop, then one slot is used for one of the VC10 or PACK or LD pin voltages, one slot is used for internal temperature or VREF or VSS measurement, then up to three slots are used to measure thermistors or multifunction pin voltages (ADCIN functionality). Over the course of three loops, a full set of measurements is completed. One measurement loop consists of either 12 (if no thermistors or ADCIN are enabled), 13 (if one thermistor or ADCIN is enabled), 14 (if two thermistors or ADCIN are enabled), or 15 (if three or more thermistors or ADCIN are enabled) measurement slots. 

The speed of a measurement loop can be controlled by settings. Each voltage measurement (slot) takes 3 ms (or 1.5 ms depending on setting), so a typical measurement loop with 15 slots per loop takes 45 ms (or 22.5 ms depending on setting). If measurement data is not required as quickly, the timing for the measurement loop can be programmed to slower speeds, which injects idle slots in each loop after the measurement slots. Using slower loop cycle time will reduce the power dissipation of the device when in NORMAL mode. 

##### **10.1.2 Usage of VC Pins for Cells Versus Interconnect** 

If the BQ76942 device is used in a system with fewer than 10-series cells, the additional cell inputs can be used to improve measurement performance. For example, a long connection may exist between two cells in a pack, such that there may be significant interconnect resistance between the cells, such as shown in Figure 10-1 between CELL-A and CELL-B. By connecting VC7 close to the positive terminal of CELL-B, and connecting VC8 close to the negative terminal of CELL-A, more accurate cell voltage measurements are obtained for CELL-A and CELL-B, since the I·R voltage across the interconnect resistance between the cells is not included in either cell voltage measurement. Because the device reports the voltage across the interconnect resistance and the synchronized current, the resistance of the interconnect between CELL-A and CELL-B can also be calculated and monitored during operation. It is recommended to include the series resistance and bypass capacitor on cell inputs connected in this manner, as shown below. 

##### **Note** 

It is important that the differential input for each cell input not fall below –0.3 V (the absolute maximum data sheet limit), with the recommended minimum voltage of –0.2 V. Therefore, it is important that the I·R voltage drop across the interconnect resistance not cause a violation of this requirement. 

Copyright © 2021 Texas Instruments Incorporated 

34 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
I<br>�<br>�� NC<br>vc9 ���<br>�<br>������ CELL-A �� NC<br>VvCc8& ���<br>�� NC<br>VC7 ���<br>������ �<br>CELL-B �� NC<br>VC6 ���<br>�<br>T T �� NC<br>���<br>Figure 10-1. Using Cell Input Pins for Interconnect Measurement<br>a&<br>� g ao<br>�� NC<br>��� vco<br>�<br>������ CELL-A �� NC<br>��� vcs<br>�� NC<br>��� vCc7<br>������ �<br>CELL-B �� NC<br>��� VCc6<br>�<br>T T �� NC<br>���� ���<br>���� ���<br><!-- End of picture text -->

**Figure 10-1. Using Cell Input Pins for Interconnect Measurement** 

If this connection across an interconnect is not needed (or it is preferred to avoid the extra resistor and capacitor), then unused cell input pins should be shorted to adjacent cell input pins, as shown in Figure 10-2 for VC8. 

**Figure 10-2. Terminating an Unused Cell Input Pin** 

A configuration register is used to specify which cell inputs are used for actual cells. The device uses this information to disable cell voltage protections associated with inputs that are used to measure interconnect or 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 35 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

are not used at all. Voltage measurements for all inputs are reported in a 16-bit format (in units of mV), as well as 32-bit format (in units of raw ADC counts), irrespective of whether they are used for cells or not. 

##### **10.1.3 Cell 1 Voltage Validation During SLEEP Mode** 

In rare cases, an invalid _Cell 1 Voltage()_ reading has been observed to occur in some devices taken during SLEEP mode. 

While the device is in SLEEP mode, each result obtained from reading the _Cell 1 Voltage()_ must be validated before it can be considered valid. During SLEEP mode, current is below programmable thresholds, so the pack is typically not being charged or discharged with any significant level of current. Thus, the cell voltages will generally not be changing significantly. 

In order to determine if a measurement of _Cell 1 Voltage()_ taken during SLEEP mode is valid, it is necessary to compare each measurement to measurements taken before and after the particular measurement. It is important that these three readings represent three **_separate measurements_** for the _Cell 1 Voltage()_ . If the reading is significantly different from the separate readings taken before and after, then that reading is considered invalid and should be discarded. 

In order to ensure the three measurements read from the device are truly **_separate measurements_** , the host can read the measurements at intervals exceeding **_Power:Sleep:Voltage Time_** while the device is in SLEEP mode. This is necessary to avoid the host reading an existing measurement multiple times, before a new measurement has been taken and is available for readout. 

An invalid _Cell 1 Voltage()_ reading may result in an SUV PF Alert being set but does not result in an SUV PF status fault if the SUV Delay is set to 1 second or longer. It also does not trigger a Cell Undervoltage (CUV) Protection alert or status fault, since this protection uses a comparator for its detection. If a reading reported by _Cell 1 Voltage()_ is below the **_Protections:CUV:Threshold_** level and the CUV protection is enabled, but the CUV Alert is not triggered, this also can be used as an indication the reading is invalid. 

This validation process is necessary to ensure that valid _Cell 1 Voltage()_ results are measured. 

#### **10.2 General Purpose ADCIN Functionality** 

Several multifunction pins on the BQ76942 device can be used for general purpose ADC input (ADCIN) measurement, if not being used for other purposes. This includes the TS1, TS2, TS3, CFETOFF, DFETOFF, HDQ, DCHG, DDSG, and ALERT pins. When used for ADCIN functionality, the internal bandgap reference is used by the ADC, and the input range of the ADC is limited to the REG18 pin voltage. The digital fullscale range of the ADC is effectively 1.6667 × VREF1, which is approximately 2.02 V during normal operation. 

The BQ76942 device also reports the raw ADC counts when a measurement is taken using the TS1 pin. This data can be used during manufacturing to better calibrate the ADCIN functionality. 

#### **10.3 Coulomb Counter and Digital Filters** 

The BQ76942 device monitors pack current using a low-side sense resistor that connects to the SRP and SRN pins through an external RC filter, which should be connected such that a charging current will create a positive voltage on SRP relative to SRN. The differential voltage between SRP and SRN is digitized by an integrated coulomb counter ADC, which can digitize voltages over a ±200 mV range and uses multiple digital filters to provide optimized measurement of the instantaneous, averaged, and integrated current. The device supports a wide range of sense resistor values, with a larger value providing better resolution for the digitized result. The maximum value of sense resistor should be limited to ensure the differential voltage remains within the ±200-mV range for system operation when current measurement is desired. For example, a system with maximum discharge current of 200 A during normal operation (not a fault condition) should limit the sense resistor to 1 mΩ or below. 

The SRP and SRN pins can also support higher positive voltages relative to VSS, such as may occur during overcurrent or short circuit in discharge conditions, without damage to the device, although the current is not accurately digitized in this case. For example, a system with a 1-mΩ sense resistor and the Short Circuit in Discharge protection threshold programmed to a 500 mV level would trigger an SCD protection fault when a discharge current of 500 A was detected. 

Copyright © 2021 Texas Instruments Incorporated 

36 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

Multiple digitized current values are available for readout over the serial communications interface, including two using separate hardware digital filters, CC1 and CC2, as well as a firmware filter CC3. 

The CC1 filter generates a 16-bit current measurement that is used for charge integration and other decision purposes, with one output generated every 250 ms when the device is operating in NORMAL mode. 

The CC2 filter generates a 24-bit current measurement that is used for current reporting, with one output every 3 ms when the device is operating in NORMAL mode (which can be reduced to one output every 1.5 ms based on setting, with reduced measurement resolution). It is reported in 16-bit format, and the 24-bit CC2 data is also available as raw coulomb counter ADC counts, provided in 32-bit format (with the data contained in the lower 24 bits and the upper 8 bits sign-extended). 

The CC3 filter output is an average of a programmable number of CC2 current samples (up to 255), based on configuration setting. The CC3 output is reported in 32-bit format. 

The integrated passed charge is available as a 64-bit value, which includes the upper 32 bits of accumulated charge as the integer portion, the lower 32 bits of accumulated charge as the fractional portion, and a 32-bit accumulated time over which the charge has been integrated in units of seconds. The accumulated charge integration and timer can be reset by a command from the host over the digital communications interface. 

#### **10.4 Synchronized Voltage and Current Measurement** 

While the cell voltages are digitized sequentially using a single muxed ADC during normal operation, the current is digitized continuously by the dedicated coulomb counter ADC. The current is measured synchronously with each cell voltage measurement, and can be used for individual cell impedance analysis. The ongoing periodic current measurements can be read out through the digital communication interface, while the measurements taken that were synchronized with particular cell voltage measurements are stored paired with the associated cell voltage measurement for separate readout. These values can be read using a block subcommand, which ensures the synchronously aligned voltage and current data are read out together. 

#### **10.5 Internal Temperature Measurement** 

The BQ76942 device integrates the capability to measure its internal die temperature by digitizing the difference in internal transistor base-emitter voltages (deltaVBE). This voltage is measured periodically as part of the measurement loop and is processed to provide a reported temperature value available through the digital communications interface. This internal temperature measurement can be used for cell or FET temperature protections and logic based on configuration settings. 

#### **10.6 Thermistor Temperature Measurement** 

The BQ76942 device includes an on-chip temperature measurement and can support up to nine external thermistors on multifunction pins (TS1, TS2, TS3, CFETOFF, DFETOFF, ALERT, HDQ, DCHG, and DDSG). The device includes an internal pullup resistor to bias a thermistor during measurement. 

The internal pullup resistor has two options that can set the pullup resistor to either 18-kΩ or 180-kΩ (or none at all). The 18-kΩ option is intended for use with thermistors such as the Semitec 103-AT, which has 10-kΩ resistance at room temperature. The 180-kΩ option is intended for use with higher resistance thermistors such as the Semitec 204AP-2, which has 200-kΩ resistance at room temperature. The resistor values are measured during factory production and stored within the device for use during temperature calculation. The individual pin configuration registers determine which pin is used for a thermistor measurement, what value of pullup resistor is used, as well as whether the thermistor measurement is used for a cell or FET temperature reading. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 37 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
REG18 (§1.8V)<br>VREF1<br>§162 NŸ�<br>§18 NŸ� reference<br>input Voltage<br>ADC<br>T T T T T T T T T<br>S S S S S S S S S<br>Figure 10-3. External Thermistor Biasing<br>Ÿ�500 § Ÿ�500 § Ÿ�500 § Ÿ�500 § Ÿ�500 § Ÿ�500 § Ÿ�500 § Ÿ�500 § Ÿ�500 §<br>ALERT Pin TS1 Pin TS2 Pin TS3 Pin HDQ Pin DCHG Pin DDSG Pin<br>CFETOFF Pin DFETOFF Pin<br><!-- End of picture text -->

To provide a high precision temperature result, the device uses the same 1.8 V LDO voltage for the ADC reference as is used for biasing the thermistor pullup resistor, thereby implementing a ratiometric measurement that removes the error contribution from the LDO voltage level. The device processes the digitized thermistor voltage to calculate the temperature based on multiorder polynomials, which can be programmed by the user based on the specific thermistor selected. 

#### **10.7 Factory Trim of Voltage ADC** 

The BQ76942 device includes factory trim for the cell voltage ADC measurements in order to optimize the voltage measurement performance even if no further calibration is performed by the customer. Calibration can be performed by the customer on the production line to further optimize the performance in the system. The trim information is used to correct the raw ADC readings before they are reported as 16-bit voltage values. The 32-bit ADC voltage data, which is generated in units of ADC counts, is modified before reporting by subtracting a stored offset trim value. The resulting reported data does not include any further correction (such as for gain), therefore the customer will need to process them before use. 

The device includes a factory gain trim for the voltage measurements performed using the general purpose ADC input capability on the multifunction pins as well as the TS1, TS2, and TS3 pins. It also includes factory gain trim on the voltage measurements of the PACK pin, the LD pin, and the top-of-stack (VC10) pin. 

#### **10.8 Voltage Calibration (ADC Measurements)** 

The BQ76942 device includes optional capability for the customer to calibrate each cell voltage gain and the gain for the stack voltage, the PACK pin voltage, and the LD pin voltage individually, and multifunction pin general ADC measurements. An offset calibration value **_Calibration:Vcell Offset:Vcell Offset_** is included for use with the cell voltage measurements, and **_Calibration:Vdiv Offset:Vdiv Offset_** is used with the TOS (stack), PACK, and LD voltage measurements. The cell voltage gains determined during calibration are written in **_Calibration:Voltage:Cell 1 Gain – Cell 10 Gain_** , where **_Cell 1 Gain_** is used for the measurement of VC1VC0, **_Cell 2 Gain_** is used for the measurement of VC2-VC1, and so forth. Similarly, the calibration voltage gain for the TOS voltage should be written in **_Calibration:Voltage:TOS Gain_** , the PACK pin voltage gain in **_Calibration:Voltage:Pack Gain_** , the LD pin voltage gain in **_Calibration:Voltage:LD Gain_** , and multifunction pin general purpose ADCIN measurement gain in **_Calibration:Voltage:ADC Gain_** . 

Copyright © 2021 Texas Instruments Incorporated 

38 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

If values for the calibration gain configuration are not written, the BQ76942 device uses factory trim or default values for the respective gain values. When a calibration gain configuration value is written, the device uses that in place of any factory trim or default gain. The raw ADC measurement data (in units of counts) is corrected by first subtracting a stored offset trim value, then the gain is applied, then the **_Calibration:Vcell Offset:Vcell Offset_** (for cell voltage measurements) or the **_Calibration:Vdiv Offset:Vdiv Offset_** (for TOS, PACK, or LD voltage measurements) is subtracted before the final voltage value is reported. 

The factory trim values for the Cell Gain parameters can be read from the Cell Gain data memory registers while in FULLACCESS mode but not in CONFIG_UPDATE mode, if the data memory values have not been overwritten. While in CONFIG_UPDATE mode, the Cell Gain values read back either all zeros, if they have not been overwritten, or the values written to these registers. Upon exiting CONFIG_UPDATE mode, readback of the Cell Gain parameters provides the values presently used in operation. 

See the _BQ76942 Technical Reference Manual_ for further details. 

The effective fullscale digital range of the cell measurement is 5 × VREF1, and the effective fullscale digital range of the ADCIN measurement is 1.667 × VREF1, although the voltages applied for these measurements should be limited based on the specifications in _Specifications_ . Using a value for VREF1 of 1.212 V, the nominal gain for the cell measurements is 12120, while the nominal gain for the ADCIN measurements is 4040. The reported voltages are calculated as: 

_Cell # Voltage()_ = **_Calibration:Voltage:Cell # Gain_** × (16-bit ADC counts) / 65536 – **_Calibration:Vcell Offset:Vcell Offset_** _Stack Voltage()_ = **_Calibration:Voltage:TOS Gain_** × (16-bit ADC counts) / 65536 – **_Calibration:Vdiv Offset:Vdiv Offset_** _PACK Pin Voltage()_ = **_Calibration:Voltage:Pack Gain_** × (16-bit ADC counts) / 65536 – **_Calibration:Vdiv Offset:Vdiv Offset_** _LD Pin Voltage()_ = **_Calibration:Voltage:LD Gain_** × (16-bit ADC counts) / 65536 – **_Calibration:Vdiv Offset:Vdiv Offset_** ADCIN Voltage = **_Calibration:Voltage:ADC Gain_** × (16-bit ADC counts) / 65536 

##### **Note** 

_Cell # Voltage()_ and **_Calibration:Vcell Offset:Vcell Offset_** have units of mV. The divider voltages ( _Stack Voltage()_ , _PACK Pin Voltage()_ , and _LD Pin Voltage()_ ) and **_Calibration:Vdiv Offset:Vdiv Offset_** have units of userV. 

#### **10.9 Voltage Calibration (COV and CUV Protections)** 

The BQ76942 device includes optional capability for the customer to calibrate the COV (cell overvoltage) and CUV (cell undervoltage) protection thresholds on the production line, in order to improve threshold accuracy in system or to realize a threshold between the preset thresholds available from the device. 

This calibration is performed while the device is in CONFIG_UPDATE mode. To calibrate the COV threshold, an external voltage is first applied between VC10 and VC9 that is equal to the desired COV threshold. Next, the _CAL_COV()_ subcommand is sent by the host, which causes the BQ76942 device to perform a search for the appropriate calibration coefficients to realize a COV threshold at or close to the applied voltage level. When this search is completed, the resulting calibration coefficient is returned by the subcommand and automatically written into the **_Protections:COV:COV Threshold Override_** configuration parameter. If this parameter is nonzero, the device will not use its factory trim settings but will instead use this value. 

The CUV threshold is calibrated similarly, an external voltage is applied between VC10 and VC9 equal to the desired CUV threshold. Next, while in CONFIG_UPDATE mode, the _CAL_CUV()_ subcommand is sent by the host, which causes the BQ76942 device to perform a search for the appropriate calibration coefficients to realize a CUV threshold at or close to the applied voltage level. When this search is completed, the resulting calibration coefficient is returned by the subcommand and automatically written into the **_Protections:CUV:CUV Threshold Override_** configuration parameter. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 39 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **10.10 Current Calibration** 

The BQ76942 device coulomb counter ADC measures the differential voltage between the SRP and SRN pins to calculate the system current. The device includes the optional capability for the customer to calibrate the coulomb counter offset and current gain on the production line. 

The **_Calibration:Current Offset:CC Offset_** configuration register contains an offset value in units of 32-bit coulomb counter ADC counts / **_Calibration:Current Offset:Coulomb Counter Offset Samples_** . The value of **_Calibration:Current Offset:CC Offset_** / **_Calibration:Current Offset:Coulomb Counter Offset Samples_** is subtracted from the raw coulomb counter ADC counts, then the result is multiplied by **_Calibration:Current:CC Gain_** and scaled to provide the final result in units of userA. 

The BQ76942 device uses the **_Calibration:Current:CC Gain_** and **_Calibration:Current:Capacity Gain_** configuration values to convert from the ADC value to current. The **_CC Gain_** reflects the value of the sense resistor used in the system, while the **_Capacity Gain_** is simply the **_CC Gain_** multiplied by 298261.6178. 

The **_CC Gain_** and **_Capacity Gain_** are encoded using a 32-bit IEEE-754 floating point format. The effective value of the sense resistor is given by: 

**_CC Gain_** = 7.4768 / (Rsense in mΩ) 

#### **10.11 Temperature Calibration** 

The BQ76942 device enables the customer to calibrate the internal as well as external temperature measurements on the production line, by storing an offset value that is added to the calculated measurement before reporting. A separate offset for each temperature measurement can be stored in the configuration registers shown below. 

**Table 10-1. Temperature Calibration Settings** 

|**Section**|**Subsection**|**Register Description**|**Comment**|**Units**|
|---|---|---|---|---|
|Calibration|Temperature|Internal Temp Offset||0.1 K|
|Calibration|Temperature|CFETOFF Temp Offset|CFETOFF pin thermistor|0.1 K|
|Calibration|Temperature|DFETOFF Temp Offset|DFETOFF pin thermistor|0.1 K|
|Calibration|Temperature|ALERT Temp Offset|ALERT pin thermistor|0.1 K|
|Calibration|Temperature|TS1 Temp Offset|TS1 pin thermistor|0.1 K|
|Calibration|Temperature|TS2 Temp Offset|TS2 pin thermistor|0.1 K|
|Calibration|Temperature|TS3 Temp Offset|TS3 pin thermistor|0.1 K|
|Calibration|Temperature|HDQ Temp Offset|HDQ pin thermistor|0.1 K|
|Calibration|Temperature|DCHG Temp Offset|DCHG pin thermistor|0.1 K|
|Calibration|Temperature|DDSG Temp Offset|DDSG pin thermistor|0.1 K|



### **11 Primary and Secondary Protection Subsystems** 

#### **11.1 Protections Overview** 

An extensive protection subsystem is integrated within the BQ76942 device, which can monitor a variety of parameters, initiate protective actions, and autonomously recover based on conditions. The device also includes a wide range of flexibility, such that the device can be configured to monitor and initiate protective action, but with recovery controlled by the host processor, or such that the device only monitors and alerts the host processor whenever conditions warrant protective action, but with action and recovery fully controlled by the host processor. 

The primary protection subsystem includes a suite of individual protections that can be individually enabled and configured, including cell undervoltage and overvoltage, overcurrent in charge, three separate overcurrent in discharge protections, short circuit current in discharge, cell overtemperature and undertemperature in charge and discharge, FET overtemperature, a host processor communication watchdog timeout, and PRECHARGE mode timeout. The cell undervoltage and overvoltage, overcurrent in charge, overcurrent in discharge 1 and 2, 

Copyright © 2021 Texas Instruments Incorporated 

40 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

and short circuit in discharge protections are based on comparator thresholds, while the remaining protections (such as those involving temperature, host watchdog, and precharging) are based on firmware on the internal controller. 

The device integrates NFET drivers for high-side CHG and DSG protection FETs, which can be configured in a series or parallel configuration. An integrated charge pump generates a voltage that is driven onto the NFET gates based on a host command or the on-chip protection subsystem settings. Support is also included for high-side PFETs used to implement a precharge and predischarge functionality. 

The secondary protection suite within the BQ76942 device can react to more serious faults and take action to permanently disable the pack by initiating a Permanent Fail (PF). The secondary safety provides protection against safety cell undervoltage and overvoltage, safety overcurrent in charge and discharge, safety overtemperature for cells and FETs, excessive cell voltage imbalance, internal memory faults, and internal diagnostic failures. 

When a Permanent Fail occurs, the BQ76942 device can be configured either to simply provide a flag, to indefinitely disable the protection FETs, or to assert the FUSE pin to permanently disable the pack. The FUSE pin can be used to blow an in-line fuse and can monitor if a separate secondary protector IC has attempted to blow the fuse. 

#### **11.2 Primary Protections** 

The BQ76942 device integrates a broad suite of protections for battery management and provides the capability to enable individual protections, as well as to select which protections will result in autonomous control of the FETs. See the _BQ76942 Technical Reference Manual_ for detailed descriptions of each protection function. 

The primary protection features include: 

- Cell Undervoltage Protection 

- Cell Overvoltage Protection 

- Cell Overvoltage Latch Protection 

- Overcurrent in Charge Protection 

- Overcurrent in Discharge Protection (Three Tiers) 

- Overcurrent in Discharge Latch Protection 

- Short Circuit in Discharge Protection 

- Short Circuit in Discharge Latch Protection 

- Undertemperature in Charge Protection 

- Undertemperature in Discharge Protection 

- Internal Undertemperature Protection 

- Overtemperature in Charge Protection 

- Overtemperature in Discharge Protection 

- Internal Overtemperature Protection 

- FET Overtemperature Protection 

- Precharge Timeout Protection 

- Host Watchdog Fault Protection 

#### **11.3 Secondary Protections** 

The BQ76942 device integrates a suite of secondary protection checks on battery operation and status that can trigger a permanent fail (PF) if conditions are considered so serious that the pack should be permanently disabled. The various PF checks can be enabled individually based on configuration settings, along with associated thresholds and delays for most checks. When a permanent fail has occurred, the BQ76942 device can be configured to either simply provide a flag, or to indefinitely disable the protection FETs, or to assert the FUSE pin to permanently disable the pack. The FUSE pin can be used to blow an in-line fuse and also can monitor if a separate secondary protector IC has attempted to blow the fuse. 

Since the device stores permanent fail status in RAM, that status would be lost when the device resets. To mitigate this, the device can write permanent fail status to OTP based on configuration setting. OTP programming may be delayed in low-voltage and high-temperature conditions until OTP programming can reliably be accomplished. 

Copyright © 2021 Texas Instruments Incorporated 

41 

_Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

Normally, a permanent fail causes the FETs to remain off indefinitely and the fuse may be blown. In that situation, no further action would be taken on further monitoring operations, and charging would no longer be possible. To avoid rapidly draining the battery, the device may be configured to enter DEEPSLEEP mode when a permanent fail occurs. Entrance to DEEPSLEEP mode will still be delayed until after fuse blow and OTP programming are completed, if those options are enabled. 

When a permanent fail occurs, the device may be configured to either turn the REG1 and REG2 LDOs off, or to leave them in their present state. Once disabled, they may still be reenabled through command. 

The permanent fail checks incorporate a programmable delay, to avoid triggering a PF fault on an intermittent condition or measurement. When the threshold is first detected as being met or exceeded by an enabled PF check, the device will set a PF Alert signal, which can be monitored using commands and can also trigger an interrupt on the ALERT pin. 

##### **Note** 

The device only evaluates the conditions for permanent fail at one-second intervals while in NORMAL and SLEEP modes. It does not continuously compare measurements to the permanent fail fault thresholds between intervals. Thus, it is possible for a condition to trigger a PF Alert if detected over threshold, but even if the condition drops back below threshold briefly between the one second interval checks, the PF Alert would not be cleared until it was detected below threshold at a periodic check. 

For more details on the permanent fail checks implemented in the BQ76942, refer to the _BQ76942 Technical Reference Manual_ . The secondary protection features include: 

- Safety Cell Undervoltage Permanent Fail 

- Safety Cell Overvoltage Permanent Fail 

- Safety Overcurrent in Charge Permanent Fail 

- Safety Overcurrent in Discharge Permanent Fail 

- Safety Overtemperature Permanent Fail 

- Safety Overtemperature FET Permanent Fail 

- Copper Deposition Permanent Fail 

- Short Circuit in Discharge Latch Permanent Fail 

- Voltage Imbalance Active Permanent Fail 

- Voltage Imbalance at Rest Permanent Fail 

- Second Level Protector Permanent Fail 

- Discharge FET Permanent Fail 

- Charge FET Permanent Fail 

- OTP Memory Permanent Fail 

- Data ROM Permanent Fail 

- Instruction ROM Permanent Fail 

- Internal LFO Permanent Fail 

- Internal Voltage Reference Permanent Fail 

- Internal VSS Measurement Permanent Fail 

- Internal Stuck Hardware Mux Permanent Fail 

- Commanded Permanent Fail 

- Top of Stack Versus Cell Sum Permanent Fail 

#### **11.4 High-Side NFET Drivers** 

The BQ76942 device includes an integrated charge pump and high-side NFET drivers for driving CHG and DSG protection FETs. The charge pump uses an external capacitor connected between the BAT and CP1 pins that is charged to an overdrive voltage when the charge pump is enabled. Due to the time required for the charge pump to bring the overdrive voltage on the external CP1 pin to full voltage, it is recommended to leave the charge pump powered whenever it may be needed quickly to drive the CHG or DSG FETs. 

The DSG FET driver includes a special option (denoted source follower mode) to drive the DSG FET with the BAT pin voltage during SLEEP mode. This capability is included to provide low power in SLEEP mode, when 

Copyright © 2021 Texas Instruments Incorporated 

42 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

there is no significant charge or discharge current flowing. It is recommended to keep the charge pump enabled even when the source follower mode is enabled, so whenever a discharge current is detected, the device can quickly transition to driving the DSG FET using the charge pump voltage. The source-follower mode is enabled using a configuration setting and is not intended to be used when significant charging or discharging current is flowing, since the FET will exhibit a large drain-source voltage and may undergo excessive heating. 

The overdrive level of the charge pump voltage can be set to 5.5 V or 11 V based on configuration setting. In general, the 5.5-V setting results in lower power dissipation when a FET is being driven, while the higher 11-V overdrive reduces the on-resistance of the FET. If a FET exhibits significant gate leakage current when driven at the higher overdrive level, this can result in a higher device current for the charge pump to support this. In this case, using the lower overdrive level can reduce the leakage current and thus the device current. 

The BQ76942 device supports a system with FETs in a series or parallel configuration, where the parallel configuration includes a separate path for the charger connection versus the discharge (load) connection. The control logic for the device operates slightly differently in these two cases, which is set based on the configuration setting. 

The FET drivers in the BQ76942 device can be controlled in several different manner, depending on customer requirements: 

###### **Fully autonomous** 

The BQ76942 device can detect protection faults and autonomously disable the FETs, monitor for a recovery condition, and autonomously reenable the FETs without requiring any host processor involvement. 

###### **Partially autonomous** 

The BQ76942 device can detect protection faults and autonomously disable the FETs. When the host receives an interrupt and recognizes the fault, the host can send commands across the digital communications interface to keep the FETs off until the host decides to release them. 

Alternatively, the host can assert the CFETOFF or DFETOFF pins to keep the FETs off. As long as these pins are asserted, the FETs are blocked from being reenabled. When these pins are deasserted, the BQ76942 will reenable the FETs if nothing is blocking them being reenabled (such as fault conditions still present, or the CFETOFF or DFETOFF pins are asserted). 

###### **Manual control** 

The BQ76942 device can detect protection faults and provide an interrupt to a host processor over the ALERT pin. The host processor can read the status information of the fault over the communication bus (if desired) and can quickly force the CHG or DSG FETs off by driving the CFETOFF or DFETOFF pins from the host processor, or commands over the digital communications interface. 

When the host decides to allow the FETs to turn on again, it writes the appropriate command or deasserts the CFETOFF and DFETOFF pins, and the BQ76942 device will reenable the FETs if nothing is blocking them being reenabled. 

If the device is in series FET configuration and a single FET is on, it is possible for current to flow through the off-FET body diode. This current can damage the FET if high enough for a long enough time. In this case, when the BQ76942 device is autonomously controlling the FETs, if a current is detected above a programmable threshold, the device will automatically turn on the off-FET to prevent further damage. 

#### **11.5 Protection FETs Configuration and Control** 

##### **11.5.1 FET Configuration** 

The BQ76942 device supports both a series configuration and a parallel configuration for the protection FETs in the system, as well as a system that does not use one or both FETs. When a series FET configuration is used, the BQ76942 device provides body diode protection for the case when one FET is off and one FET is on. 

If the CHG FET is off, the DSG or PDSG FET is on, and a discharge current greater in magnitude than a programmable threshold (that is, a significant discharging current) is detected, the device will turn on the CHG 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 43 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

FET to avoid current flowing through the CHG FET body diode and damaging the FET. When the current rises above the threshold (that is, less discharge current flowing), the CHG FET will be turned off again if the reasons for its turn-off are still present. 

If the DSG FET is off, the CHG or PCHG FET is on, and a current in excess of a programmable threshold (that is, a significant charging current) is detected, the device will turn on the DSG FET to avoid current flowing through the DSG FET body diode and damaging the FET. When the current falls below the threshold (that is, less charging current flowing), the DSG FET will be turned off again if the reasons for its turn-off are still present. 

When a parallel configuration is used, the body diode protection is disabled. 

##### **11.5.2 PRECHARGE and PREDISCHARGE Modes** 

The BQ76942 device includes precharge functionality, which can be used to reduce the charging current for an undervoltage battery by charging using a high-side PCHG PFET (driven from the PCHG pin) with a series resistor until the battery reaches a programmable voltage level. When the minimum cell voltage is less than a programmable threshold, the PCHG FET is used for charging. 

The device also supports predischarge functionality, which can be used to reduce inrush current when the load is initially powered, by first enabling a high-side PDSG PFET (driven from the PDSG pin) with a series resistor, which allows the load to slowly charge. If PREDISCHARGE mode is enabled, whenever the DSG FET is turned on to power the load, the device will first enable the PDSG FET, then transition to turn on the DSG FET and turn off the PDSG FET. 

The PCHG and PDSG drivers are limited in the current they can sink while enabled. As such, it is recommended to use 1 MΩ or larger resistance across the FET gate-source. 

#### **11.6 Load Detect Functionality** 

When a Short Circuit in Discharge Latch or Overcurrent in Discharge Latch protection fault has occurred and the DSG FET is off, the device can be configured to recover when load removal is detected. This feature is useful if the system has a removable pack, such that the user can remove the pack from the system when a fault occurs, or if the effective system load that remains on the battery pack is higher than ~20-kΩ when the DSG FET is disabled. The device will periodically enable a current source out the LD pin and will recover the fault if a voltage is detected at the LD pin above a 4-V level. If a low-impedance load is still present on the pack, the voltage the device measures on the LD pin is generally below 4 V, preventing recovery based on Load Detect. If the pack was removed from the system and the effective load is high, such that the current source generates a voltage on the LD pin above a 4-V level, then the device can recover from the fault. 

##### **Note** 

Typically, a 10-kΩ resistor is connected between the PACK+ terminal and the LD pin, this resistance should be comprehended when considering the load impedance. The Load Detect current is enabled for a programmable time duration, then is disabled for another programmable time duration, with this sequence repeating until the load has been detected as removed or it times out. 

### **12 Device Hardware Features** 

#### **12.1 Voltage References** 

The BQ76942 device includes two voltage references, VREF1 and VREF2, with VREF1 used by the voltage ADC for most measurements except external thermistors. The integrated 1.8-V LDO, internal oscillators, and integrated coulomb counter ADC use VREF2. The value of VREF2 can be measured indirectly by the voltage ADC's measurement of the REG18 LDO voltage while using VREF1 for diagnostic purposes. 

#### **12.2 ADC Multiplexer** 

The ADC multiplexer connects various signals to the voltage ADC, including the individual differential cell voltage pins, the on-chip temperature sensor, the biased thermistor pins, the REG18 LDO voltage, the VSS pin voltage, and internal dividers connected to the VC10, PACK, and LD pins. 

Copyright © 2021 Texas Instruments Incorporated 

44 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **12.3 LDOs** 

The BQ76942 device contains an integrated 1.8-V LDO (REG18) that provides a regulated 1.8-V supply voltage for the device's internal circuitry and digital logic. This regulator uses an external capacitor connected to the REG18 pin, which should only be used for internal circuitry. 

The device also integrates two separately programmable LDOs (REG1 and REG2) for external circuitry, such as a host processor or external transceiver circuitry, which can be programmed to independent output voltages. The REG1 and REG2 LDOs take their input from the REGIN pin, with this voltage either provided externally or generated by an on-chip preregulator (referred to as REG0). The REG1 and REG2 LDOs can provide an output current of up to 45 mA each. 

##### **12.3.1 Preregulator Control** 

The REG1 and REG2 LDOs take their input from the REGIN pin, which should be approximately 5.5 V. This REGIN pin voltage can be supplied externally (such as by a separate DC/DC converter) or using the integrated voltage preregulator (referring to as REG0), which drives the base of an external NPN BJT (using the BREG pin) to provide the 5.5 V REGIN pin voltage. When the preregulator is being used, special care should be taken to ensure the device retains sufficient voltage on its BAT pin per the _Specifications_ . 

##### **Note** 

- The system designer should ensure the external BJT can tolerate the peak power that may be dissipated in it under maximum load expected on REG1 and REG2. If the maximum stack voltage is 50 V, then the BJT experiences a collector-emitter voltage of approximately 45 V; thereby, dissipating 4.05 W if REG1 and REG2 are both used to support a 45-mA load. 

- There is a diode connection between the REGIN pin (anode) and the BAT pin (cathode), so the voltage on REGIN should not exceed the voltage on BAT. 

##### **12.3.2 REG1 and REG2 LDO Controls** 

The REG1 and REG2 LDOs in the BQ76942 device are for customer use, and their output voltages can be programmed independently to 1.8 V, 2.5 V, 3.0 V, 3.3 V, or 5.0 V. The REG1 and REG2 LDOs and the REG0 preregulator are disabled by default in the BQ76942 device. While in SHUTDOWN mode, the REG1 and REG2 pins have ≈10-MΩ resistances to VSS, to discharge any output capacitance. While in other power modes, when REG1 and REG2 are powered down, they are pulled to VSS with an internal resistance of ≈2.5-kΩ. If pullup resistors for serial communications are connected to the REG1 voltage output, the REG1 voltage can be overdriven from an external voltage supply on the manufacturing line, to allow communications with the device. The BQ76942 device can then be programmed to enable REG0 and REG1 with the desired configuration, and this setting can be programmed into OTP memory. Thus, at each later power-up, the device will autonomously load the OTP settings and enable the LDO as configured, without requiring communications first. 

#### **12.4 Standalone Versus Host Interface** 

The BQ76942 device can be configured to operate in a completely standalone mode, without any host processor in the system, or together with a host processor. If in standalone mode, the device can monitor conditions, control FETs and an in-line fuse based on threshold settings, and recover FETs when conditions allow, all without requiring any interaction with an external processor. If a host processor is present, the device can still be configured to operate fully autonomously, while the host processor can read measurements and exercise control as desired. In addition, the device can be configured for manual host control, such that the device can monitor and provide a flag when a protection alert or fault has occurred, but will rely on the host to disable FETs. 

The host processor can interface with the BQ76942 device through a serial bus as well as selected pin controls. Serial bus communication through I<sup>2</sup> C (supporting speeds up to 400 kHz), SPI or HDQ is available, with the serial bus configured for I<sup>2</sup> C by default in the BQ76942, while the default communications mode may differ 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 45 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

for other versions of the device. The pin controls available include RST_SHUT, ALERT, CFETOFF, DFETOFF, DDSG, and DCHG, which are described in detail below. 

#### **12.5 Multifunction Pin Controls** 

The BQ76942 device provides flexibility regarding the multifunction pins on the device, which includes the TS1, TS2, TS3, CFETOFF, DFETOFF, ALERT, HDQ, DCHG, and DDSG pins. Several of the pins can be used as active-high outputs with configurable output level. The digital output driver for these pins can be configured to drive an output powered from the REG1 LDO or from the internal REG18 LDO, and thus when asserted active-high will drive out the voltage of the selected LDO. 

Note: the REG18 LDO is not capable of driving high current levels, so it is recommended to only use this LDO to provide a digital output if it will be driving a very high resistance (such as > 1 MΩ) or light capacitive load. Otherwise the REG1 should be powered and used to drive the output signal. 

The options supported on each pin include: 

###### **ALERT** 

Alarm interrupt output HDQ communications 

###### **CFETOFF** 

Input to control the CHG FET (that is, CFETOFF functionality) 

**DFETOFF** Input to control the DSG FET (that is, DFETOFF functionality) Input to control both the DSG and CHG FETs (that is, BOTHOFF functionality) **HDQ** HDQ communications SPI MOSI pin 

###### **DCHG** 

DCHG functionality—a logic-level output corresponding to a fault that would normally cause the CHG driver to be disabled **DDSG** DDSG functionality—a logic-level output corresponding to a fault that would normally cause the DSG driver to be disabled **ALERT, CFETOFF, DFETOFF, HDQ, DCHG, and DDSG** General purpose digital output Can be driven high or low by command. Can be configured for an active-high output to be driven from the REG1 LDO or the REG18 LDO. Can be configured to have a weak pull-down to VSS or weak pullup to REG1 enabled continuously. **ALERT, CFETOFF, DFETOFF, TS1, TS2, TS3, HDQ, DCHG, and DDSG** 

Thermistor temperature measurement A thermistor can be attached between the pin and VSS. 

###### ADCIN 

The pin can be used for general purpose ADC measurement. 

Copyright © 2021 Texas Instruments Incorporated 

46 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **12.6 RST_SHUT Pin Operation** 

The RST_SHUT pin provides a simple way to reset or shutdown the BQ76942 device without needing to use serial bus communication. During normal operation, the RST_SHUT pin should be driven low. When the pin is driven high, the device will immediately reset most of the digital logic, including that associated with the serial communications bus. However, it does not reset the logic that holds the state of the protection FETs and FUSE, these remain as they were before the pin was driven high. If the pin continues to be driven high for 1 second, the device will then transition into SHUTDOWN mode, which involves disabling external protection FETs, and powering off the internal oscillators, the REG18 LDO, the on-chip preregulator, and the REG1 and REG2 LDOs. 

#### **12.7 CFETOFF, DFETOFF, BOTHOFF Pin Functionality** 

The BQ76942 device includes two pins (CFETOFF and DFETOFF) that can be used to disable the protection FET drivers quickly, without going through the host serial communications interface. When the selected pin is asserted, the device disables the respective protection FET. 

##### **Note** 

When the selected pin is deasserted, the respective FET is only enabled if there are no other items blocking them from being reenabled, such as if the host also sent a command to disable the FETs using the serial communications interface after setting the selected pin. The CFETOFF and DFETOFF <u>pins can be used for other functions if the FET turnoff feature is not required.</u> 

The CFETOFF pin can be used optionally to disable the CHG and PCHG FETs, and the DFETOFF pin can be used optionally to disable the DSG and PDSG FETs. The device also includes the option to configure the DFETOFF pin as BOTHOFF functionality, such that if that pin is asserted, the CHG, PCHG, DSG, and PDSG FETs will be disabled. This allows the CFETOFF pin to be used for an additional thermistor in the system, while still providing pin control to disable the FETs. 

The CFETOFF or BOTHOFF functionality disables both the CHG FET and the PCHG FET when asserted. 

The DFETOFF or BOTHOFF functionality disables both the DSG FET and the PDSG FET when asserted. 

#### **12.8 ALERT Pin Operation** 

The ALERT pin is a multifunction pin that can be configured either as ALERT (to provide an interrupt to a host processor), a thermistor input, a general purpose ADC input, a general purpose digital output, or an HDQ serial communication interface. The pin can be configured as active-high, active-low, or open-drain to accommodate different system design preferences. When configured as the HDQ interface pin, the pin will operate in open-drain mode. 

When the pin is configured to drive an active high output, the output voltage is driven from either the REG18 1.8-V LDO or the REG1 LDO (which can be programmed from 1.8 V to 5.0 V). 

##### **Note** 

If a DC or significant transient current may be driven by this pin, then the output should be configured to drive using the REG1 LDO, not the REG18 LDO. 

The BQ76942 device includes functionality to generate an alarm signal at the ALERT pin, which can be used as an interrupt to a host processor. When used for the alarm function, the pin can be programmed to drive the signal as an active-low or hi-Z signal, an active-high or low signal, or an active-low or high signal (that is, inverted polarity). The alarm function within the BQ76942 device includes a programmable mask to allow the customer to decide which of many flags or events can trigger an alarm. 

#### **12.9 DDSG and DCHG Pin Operation** 

The BQ76942 device includes two multifunction pins, DDSG and DCHG, which can be configured as logic-level outputs to provide a fault-related signal to a host processor or external circuitry (that is, DDSG and DCHG functionality), as a thermistor input, a general purpose ADC input, or a general purpose digital output. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 47 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

When used as digital outputs, the pins can be configured to drive an active high output, with the output voltage driven from either the REG18 1.8-V LDO or the REG1 LDO (which can be programmed from 1.8 V to 5.0 V). 

##### **Note** 

If a DC or significant transient current can be driven by a pin, then the output should be configured to drive using the REG1 LDO, not the REG18 LDO. 

When the pins are configured for DDSG and DCHG functionality, they provide signals related to protection faults that (on the DCHG pin) would normally cause the CHG driver to be disabled or (on the DDSG pin) would normally cause the DSG driver to be disabled. These signals can be used to control external protection circuitry, if the integrated high-side NFET drivers will not be used in the system. They can also be used as interrupts in manual FET control mode for the host processor to decide whether to disable the FETs through commands or using the CFETOFF and DFETOFF pins. 

#### **12.10 Fuse Drive** 

The FUSE pin on the BQ76942 device can be used to blow a chemical fuse in the presence of a permanent fail (PF), as well as to detect if an external secondary protector in the system has detected a fault and is attempting to blow the fuse itself. The pin is intended to drive the gate of an NFET, which can be combined with the drive from an external secondary protector, as shown in Figure 12-1. When the FUSE pin is not asserted by the BQ76942 device, it remains in a high-impedance state and detects a voltage applied at the pin by a secondary protector. The device can be configured to generate a PF if it detects a high signal at the FUSE pin. 

The device can be configured to blow the fuse when a PF occurs. In this case, the device only attempts to blow the fuse if the stack voltage is above a programmed threshold, based on a system configuration with the fuse placed between the top of stack and the high-side protection FETs. If instead the fuse is placed between the FETs and the PACK+ connector, then the device instead bases its decision on the PACK pin voltage (based on configuration setting). This voltage threshold check is disregarded under certain cases, as described in the _BQ76942 Technical Reference Manual_ . 



<!-- Start of picture text -->
����<br>������<br>������ ������ �<br>��<br>���<br>���������� �<br>��<br>���������<br>���<br>���� ��� ���<br><!-- End of picture text -->

**Figure 12-1. FUSE Pin Operation** 

#### **12.11 Cell Open Wire** 

The BQ76942 device supports detection of a broken connection between a cell in the pack and the cell attachment to the PCB containing the BQ76942 device. Without this check, the voltage at the cell input pin of the BQ76942 device may persist for some time on the board-level capacitor, leading to incorrect voltage readings. The Cell Open Wire detection in the BQ76942 device operates by enabling a small current source from each cell to VSS at programmable intervals. If a cell input pin is floating due to an open wire condition, this current 

Copyright © 2021 Texas Instruments Incorporated 

48 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

discharges the capacitance, causing the voltage at the pin to slowly drop. This drop in voltage eventually triggers a protection fault on that particular cell and the cell above it. Eventually, the voltage drops low enough to trigger a permanent fail on the particular cell and on the cell above it. 

The Cell Open Wire current will be enabled at a periodic interval set by configuration register. The current source is enabled once every interval for a duration of the ADC measurement time (which is 3 ms by default). This provides programmability in the average current drawn from ≈0.65 nA to ≈165 nA, based on the typical current level of 55 µA. 

**Note** 

The Cell Open Wire check can create a cell imbalance, so the settings should be selected appropriately. 

#### **12.12 Low Frequency Oscillator** 

The low frequency oscillator (LFO) in the BQ76942 device operates continuously while in NORMAL and SLEEP modes, and can be configured to remain powered or shutdown (except when needed) during DEEPSLEEP mode. The LFO runs at ≈262.144 kHz during NORMAL mode, and reduces to ≈32.768 kHz in SLEEP or DEEPSLEEP modes. The LFO is trimmed during manufacturing to meet the specified accuracy across temperature. 

#### **12.13 High Frequency Oscillator** 

The high frequency oscillator (HFO) in the BQ76942 device operates at 16.78 MHz and is frequency locked to the LFO. The HFO powers up as needed for internal logic functions. 

### **13 Device Functional Modes** 

#### **13.1 Overview** 

This device supports four functional modes to support optimized features and power dissipation, with the device able to transition between modes either autonomously or controlled by a host processor. 

- NORMAL mode: In this mode, the device performs frequent measurements of system current, cell voltages, internal and thermistor temperature, and various other voltages, operates protections as configured, and provides data and status updates. 

- SLEEP mode: In this mode, the DSG FET is enabled, the CHG FET can optionally be disabled, and the device performs measurements, calculations, and data updates in adjustable time intervals. Battery protections are still enabled. Between the measurement intervals, the device is operating in a reduced power stage to minimize total average current consumption. 

- DEEPSLEEP mode: In this mode, the CHG, PCHG, DSG, and PDSG FETs are disabled, all battery protections are disabled, and no current or voltage measurements are taken. The REG1 and REG2 LDOs can be kept powered, in order to maintain power to external circuitry, such as a host processor. 

- SHUTDOWN mode: The device is completely disabled (including the internal, REG1, and REG2 LDOs), the CHG, PCHG, DSG, and PDSG FETs are all disabled, all battery protections are disabled, and no measurements are taken. This is the lowest power state of the device, which may be used for shipment or long-term storage. All register settings are lost when in SHUTDOWN mode. 

The device also includes a CONFIG_UPDATE mode, which is used for parameter updates. Transitioning between functional modes is shown below. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 49 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
SHUTDOWN MODE<br>Charger detect on<br>TS2 pulldown detect on<br>Very low VBAT Shutdown signal by<br>RST_SHUT pin or<br>low VBAT  or high<br>temp<br>Charger  Shutdown signal by<br>detection or TS2  RST_SHUT pin or<br>pulldown  command or low<br>detection VBAT or high temp SLEEP MODE<br>DEEPSLEEP MODE REG18, REG1, REG2 on<br>REG18, REG1, REG2 on Comparator protections on<br>LFO on Periodic ADC protections on<br>Current wake detector on<br>DEEPSLEEP()<br>command twice<br>EXIT_DEEPSLEEP()  command or reset<br>signal by RST_SHUT pin or charger<br>detected<br>NORMAL MODE<br>Monitoring on Low current<br>Protection on<br>REG18, REG1, REG2 on<br>DEEPSLEEP()  command<br>twice, or Permanent Fail SLEEP_DISABLE()  command or fault or fault recovery<br>or current detected or charger detected or reset signal<br>by RST_SHUT pin<br>Reset signal by RST_SHUT<br>Blue = programmable pin<br><!-- End of picture text -->

**Figure 13-1. Device Functional Modes** 

#### **13.2 NORMAL Mode** 

NORMAL mode is the highest performance mode of the device, in which the device regularly measures voltage, current, and temperature, the LFO (low frequency oscillator) is operating, and the internal processor powers up (as needed) for data processing and control. Full battery protections operate based on device configuration settings. System current is measured at intervals of 3 ms, with cell voltages measured at intervals of 45 ms or slower, depending on configuration. The device also provides a configuration bit that causes the conversion speed for both voltages and CC2 current to be doubled, with a reduction in measurement resolution. 

The device is generally in NORMAL mode when any active charging or discharging is underway. When the _CC1 Current()_ measurement falls below a programmable current threshold, the system is considered in relax mode, and the BQ76942 device can autonomously transition into SLEEP mode, depending on configuration. 

#### **13.3 SLEEP Mode** 

SLEEP mode is a reduced functionality state that can be optionally used to reduce power dissipation when there is little or no system load current or charging in progress, but still provides voltage at the battery pack terminals to keep the system active. At initial powerup, a configuration bit determines whether the device can enter SLEEP mode. After initialization, SLEEP mode can be allowed or disallowed using subcommands. Status bits are provided to indicate whether the device is presently allowed to enter SLEEP mode or not, and whether it is presently in SLEEP mode or not. 

When the magnitude of the CC1 Current measurement falls below a programmable current threshold, the system is considered in relax mode, and the BQ76942 device autonomously transitions into SLEEP mode, if settings permit. During SLEEP mode, comparator-based protections operate the same as during NORMAL mode. ADC-based current, voltage, and temperature measurements are taken at programmable intervals. All temperature protections use the ADC measurements taken at these intervals, so they will update at a reduced rate during SLEEP mode. 

The BQ76942 device exits SLEEP mode if a protection fault occurs, current begins flowing, a charger is attached, if forced by a subcommand, or if the RST_SHUT pin is asserted for < 1 s. When exiting based on current flow, the device quickly enables the FETs (if the CHG FET was off or the DSG FET was in source- 

Copyright © 2021 Texas Instruments Incorporated 

50 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

follower mode), but the standard measurement loop does not restart until the next 1-s boundary occurs within the device timing. Therefore, new data may not be available for up to ≈1 s after the device exits SLEEP mode. 

The coulomb counter ADC operates in a reduced power and speed mode to monitor current during SLEEP mode. The current is measured every 12 ms and, if it exceeds a programmable threshold in magnitude, the device quickly transitions back to NORMAL mode. In addition to this check, if CC1 Current measurement taken at each programmed interval exceeds this threshold, the device exits SLEEP mode. 

The device monitors the PACK pin voltage and the top-of-stack voltage at each programmed measurement interval. If the PACK pin voltage is higher than the top-of-stack voltage by more than a programmable delta and the top-of-stack voltage is less than a programmed threshold, the device exits SLEEP mode. The BQ76942 device also includes a hysteresis on the SLEEP mode entrance to avoid the device quickly entering and exiting SLEEP mode based on a dynamic load. After transitioning to NORMAL mode, the device will not enter SLEEP mode again for a number of seconds given by the hysteresis setting. 

During SLEEP mode, the DSG FET can be driven either using the charge pump or in source-follower mode (as described in _High-side NFET Drivers_ ). The CHG FET can be disabled or driven using the charge pump, based on the configuration setting. 

#### **13.4 DEEPSLEEP Mode** 

The BQ76942 device integrates a DEEPSLEEP mode, which is a low-power mode that allows the REG1 and REG2 LDOs to remain powered, but disables other subsystems. In this mode, the protection FETs are disabled, so no voltage is provided at the battery pack terminals. All protections are disabled, and all voltage, current, and temperature measurements are disabled. 

DEEPSLEEP mode can be entered by sending a subcommand over the serial communications interface. The device exits DEEPSLEEP mode returns to NORMAL mode if directed by a subcommand, or if the RST_SHUT pin is asserted for < 1-s, or if a charger is attached (which is detected by the voltage on the LD pin rising from below VWAKEONLD to exceed it). In addition, if the BAT pin voltage falls below VPORA – VPORA_HYS, the device transitions to SHUTDOWN mode. 

When the device exits DEEPSLEEP mode, it first completes a full measurement loop and evaluates conditions relative to enabled protections to ensure that conditions are acceptable to proceed to NORMAL mode. This may take ≈250 ms plus the time for the measurement loop to complete. 

The REG1 and REG2 LDOs maintain their power state when entering DEEPSLEEP mode based on the configuration setting. The device also provides the ability to keep the LFO running while in DEEPSLEEP mode, which enables a faster responsiveness to communications and transition back to NORMAL mode, but consumes additional power. 

Other than sending a subcommand to exit DEEPSLEEP mode, communications with the device over the serial interface do not cause it to exit DEEPSLEEP mode; however, since no measurements are taken while in DEEPSLEEP mode, there is no new information available for readout. 

#### **13.5 SHUTDOWN Mode** 

SHUTDOWN mode is the lowest power mode of the BQ76942 device, which can be used for shipping or long-term storage. In this mode, the device loses all register state information, the internal logic is powered down, the protection FETs are all disabled, so no voltage is provided at the battery pack terminals. All protections are disabled, all voltage, current, and temperature measurements are disabled, and no communications are supported. When the device exits SHUTDOWN, it will boot and read parameters stored in OTP (if that has been written). If the OTP has not been written, the device will power up with default settings, and then settings can be changed by the host writing device registers. 

Entering SHUTDOWN mode involves a sequence of steps. The sequence can be initiated manually through the serial communications interface. The device can also be configured to enter SHUTDOWN mode automatically based on the top of stack voltage or the minimum cell voltage. If the top-of-stack voltage falls below a programmed stack voltage threshold, or if the minimum cell voltage falls below a programmed cell voltage threshold, the SHUTDOWN mode sequence is automatically initiated. The shutdown based on cell voltage does not apply to cell input pins being used to measure interconnect. 

Copyright © 2021 Texas Instruments Incorporated 

51 

_Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

While the BQ76942 device is in NORMAL mode or SLEEP mode, the device can also be configured to enter SHUTDOWN mode if the internal temperature measurement exceeds a programmed temperature threshold for a programmed delay. 

When the SHUTDOWN mode sequence has been initiated by subcommand or the RST_SHUT pin driven high for 1-sec, the device will wait for a delay then disable the protection FETs. After the delay from when the sequence begins, the device will enter SHUTDOWN mode. However, if the voltage on the LD pin is still above the VWAKEONLD level, shutdown will be delayed until the voltage on LD falls below that level. 

While the device is in SHUTDOWN mode, a ≈5-V voltage is provided at the TS2 pin with high source impedance. If the TS2 pin is pulled low (such as by a switch to VSS) or if a voltage is applied at the LD pin above VWAKEONLD (such as when a charger is attached in series FET configuration), the device will exit SHUTDOWN mode. 

##### **Note** 

If a thermistor is attached from the TS2 pin to VSS, this may prevent the device from fully entering SHUTDOWN mode. 

As a countermeasure to avoid an unintentional wake from SHUTDOWN mode when putting the BQ76942 device into long-term storage, the device can be configured to automatically reenter SHUTDOWN mode after a programmed number of minutes. 

The BQ76942 device performs periodic memory integrity checks and will force a watchdog reset if any corruption is detected. To avoid a cycle of resets in the case of a memory fault, the device will enter SHUTDOWN mode rather than resetting if a memory error is detected within a programmed number of seconds after a watchdog reset has occurred. 

When the device is wakened from SHUTDOWN, it generally requires approximately 200 ms–300 ms for the internal circuitry to power up, load settings from OTP memory, perform initial measurements, evaluate those relative to enabled protections, then to enable FETs if conditions allow. This can be much longer depending on settings. 

The BQ76942 device integrates a hardware overtemperature detection circuit, which determines when the die temperature passes an excessive temperature of approximately 120°C. If this detector triggers, the device automatically begins the sequence to enter SHUTDOWN (if this functionality is enabled through configuration). 

#### **13.6 CONFIG_UPDATE Mode** 

The BQ76942 device uses a special CONFIG_UPDATE mode to make changes to the data memory settings. If changes were made to the data memory settings while the firmware was in normal operation, it could result in unexpected operation or consequences if settings used by the firmware changed in the midst of operation. When changes to the data memory settings are needed (which generally should only be done on the customer manufacturing line or in an offline condition), the host should put the device into CONFIG_UPDATE mode, modify settings as required, then exit CONFIG_UPDATE mode. See the _BQ76942 Technical Reference Manual_ for more details. 

When in CONFIG_UPDATE mode, the device stops normal firmware operation and stops all measurements and protection monitoring. The host can then make changes to data memory settings (either writing registers directly into RAM, or instructing the device to program the RAM data into OTP). After changes are complete, the host then exits CONFIG_UPDATE mode, at which point the device restarts normal firmware operation using the new data memory settings. 

Copyright © 2021 Texas Instruments Incorporated 

52 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **14 Serial Communications Interface** 

#### **14.1 Serial Communications Overview** 

The BQ76942 device integrates three serial communication interfaces—an I<sup>2</sup> C bus, which supports 100 kHz and 400 kHz modes with an optional CRC check, an SPI bus with an optional CRC check, and a single-wire HDQ interface. The BQ76942 device is configured default in I<sup>2</sup> C mode, while other versions of the device may have a different default configuration (such as the BQ7694201 device, which by default is configured in SPI mode with CRC enabled). The communication mode can be changed by programming either the register or OTP configuration. The customer can program the device's integrated OTP on the manufacturing line to set the desired communications speed and protocol to be used at power up in operation. 

#### **14.2 I**<sup>**2**</sup> **C Communications Subsystem** 

The I<sup>2</sup> C serial communications interface in the BQ76942 device acts as a responder device and supports rates up to 400 kHz with an optional CRC check. If the OTP is not programmed, the BQ76942 device will initially power up by default in 400 kHz I<sup>2</sup> C mode, although other versions of the device may initially power up in a different mode (as shown in the _Device Comparison Table_ ). The OTP setting can be programmed on the manufacturing line, then when the device powers up, it automatically enters the selected mode per OTP setting. The host can also change the I<sup>2</sup> C speed setting while in CONFIG_UPDATE mode, then the new speed setting will take effect upon exit of CONFIG_UPDATE mode. Alternatively, the host can use the _SWAP_TO_I2C()_ subcommand to change the communications interface to I<sup>2</sup> C immediately. 

The I<sup>2</sup> C device address (as an 8-bit value including responder address and R/W bit) is set by default as 0x10 (write), 0x11 (read), which can be changed by configuration setting. 

The communications interface includes programmable timeout capability, this should only be used if the bus will be operating at 100 kHz or 400 kHz. If this is enabled with the device set to 100 kHz mode, then the device will reset the communications interface logic if a clock is detected low longer than a tTIMEOUT of 25 ms to 35 ms, or if the cumulative clock low responder extend time exceeds ≈25 ms, or if the cumulative clock low controller extend time exceeds 10 ms. If the timeouts are enabled with the device set to 400 kHz mode, then the device will reset the communications interface logic if a clock is detected low longer than tTIMEOUT of 5 ms to 20 ms. The bus also includes a long-term timeout if the SCL pin is detected low for more than 2 seconds, which applies whether or not the timeouts above are enabled. 

An I<sup>2</sup> C write transaction is shown in I<sup>2</sup> C Write. Block writes are allowed by sending additional data bytes before the Stop. The I<sup>2</sup> C logic will auto-increment the register address after each data byte. 

When enabled, the CRC is calculated as follows: 

- In a single-byte write transaction, the CRC is calculated over the responder address, register address, and data. 

- In a block write transaction, the CRC for the first data byte is calculated over the responder address, register address, and data. The CRC for subsequent data bytes is calculated over the data byte only. 

The CRC polynomial is x<sup>8</sup> + x<sup>2</sup> + x + 1, and the initial value is 0. 

When the responder detects an invalid CRC, the I<sup>2</sup> C responder will NACK the CRC, which causes the I<sup>2</sup> C responder to go to an idle state. 



<!-- Start of picture text -->
SCL<br>SDA A7 A6 ... A1 R/W ACK R7 R6 ... R0 ACK D7 D6 ... D0 ACK C7 C6 ... C0 ACK<br>Start ResponderAddress RegisterAddress Data (optional)CRC Stop<br><!-- End of picture text -->

**Figure 14-1. I**<sup>**2**</sup> **C Write** 

I<sup>2</sup> C Read with Repeated Start shows a read transaction using a Repeated Start. 

Copyright © 2021 Texas Instruments Incorporated 

53 

_Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 



<!-- Start of picture text -->
BQ76942<br>SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 www.ti.com<br>SCL<br>SDA A7 A6 ... A1 R/W ACK R7 R6 ... R0 ACK A7 A6 ... A1 R/W ACK<br>Start Responder Register Responder<br>Address Address Address<br>Repeated<br>Start<br>D7 D6 ... D0 ACK C7 C6 ... C0 NACK<br>Drives DataResponder RDrives CRCespsonder Stop<br>(optional) Controller<br>Drives NACK<br><!-- End of picture text -->



<!-- Start of picture text -->
www.ti.com<br><!-- End of picture text -->

**Figure 14-2. I**<sup>**2**</sup> **C Read with Repeated Start** 

I<sup>2</sup> C Read without Repeated Start shows a read transaction where a Repeated Start is not used, for example if not available in hardware. For a block read, the controller ACK’s each data byte except the last and continues to clock the interface. The I<sup>2</sup> C block will auto-increment the register address after each data byte. 

When enabled, the CRC for a read transaction is calculated as follows: 

- In a single-byte read transaction, the CRC is calculated beginning at the first start, so will include the responder address, the register address, then the responder address with read bit set, then the data byte. 

- In a block read transaction, the CRC for the first data byte is calculated beginning at the first start and will include the responder address, the register address, then the responder address with read bit set, then the data byte. The CRC resets after each data byte and after each stop. The CRC for subsequent data bytes is calculated over the data byte only. 

The CRC polynomial is x<sup>8</sup> + x<sup>2</sup> + x + 1, and the initial value is 0. 

When the controller detects an invalid CRC, the I<sup>2</sup> C controller will NACK the CRC, which causes the I<sup>2</sup> C responder to go to an idle state. 



<!-- Start of picture text -->
SCL<br>SDA A7 A6 ... A1 R/W ACK R7 R6 ... R0 ACK A7 A6 ... A1 R/W ACK<br>Start ResponderAddress RegisterAddress Stop Start ResponderAddress<br>D7 D6 ... D0 ACK C7 C6 ... C0 NACK<br>Drives DataResponder Drives CRCResponder Stop<br>(optional) Controller<br>Drives NACK<br><!-- End of picture text -->

**Figure 14-3. I**<sup>**2**</sup> **C Read without Repeated Start** 

#### **14.3 SPI Communications Interface** 

The SPI interface in the BQ76942 device operates as a responder-only interface with an optional CRC check. If the OTP has not been programmed, the BQ76942 device will initially power up by default in 400 kHz I<sup>2</sup> C mode, while other device versions will initially powerup by default in SPI mode with CRC enabled, as described in the _Device Comparison Table_ . The OTP setting to select SPI mode can be programmed into the BQ76942 on the manufacturing line, then when the device powers up, it enters SPI mode automatically. The host can also change the serial communication setting while in CONFIG_UPDATE mode, although the device will not immediately change communication mode upon exit of CONFIG_UPDATE mode, in order to avoid losing communications during evaluation or production. The host can reset the device or write the _SWAP_TO_SPI()_ subcommand to change the communications interface to SPI immediately. 

Copyright © 2021 Texas Instruments Incorporated 

54 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

The SPI interface logic operates with clock polarity (CPOL) = 0 and clock phase (CPHA) = 0, as shown in the figure below. 



<!-- Start of picture text -->
SPI_CS<br>SPI_SCLK<br>CYCLE # 1 2 3 4 5 6 7 8<br>SPI_MISO 1 2 3 4 5 6 7 8<br>SPI_MOSI 1 2 3 4 5 6 7 8<br><!-- End of picture text -->

**Figure 14-4. SPI with CPOL = 0 and CPHA = 0** 

The device also includes an optional 8-bit CRC using polynomial x<sup>8</sup> +x<sup>2</sup> +x+1. The interface must use 16-bit transactions if CRC is not enabled, and must use 24-bit transactions when CRC is enabled. CRC mode is enabled or disabled based on the setting of **_Settings:Configuration:Comm Type_** . Based on configuration settings, the logic will: 

(a) only work with CRC, will not accept data without valid CRC, or 

(b) will only accept transactions without CRC (so the host must only clock 16-bits per transaction, the device will detect an error if more or less clocks are sent). 

If the host performs a write with CRC and the CRC is not correct, then the incoming data is not transferred to the incoming buffer, and the outgoing buffer (used for the next transaction) is also reset to 0xFFFF. This transaction is considered invalid. On the next transaction, the CRC (if clocked out) will be 0xAA, so the 0xFFFFAA will indicate to the controller that a CRC error was detected. 

The internal oscillator in the BQ76942 device may not be running when the host initiates a transaction (for example, this can occur if the device is in SLEEP mode). If this occurs, the interface will drive out 0xFFFF on SPI_MISO for the first 16 bits clocked out. It will also drive out 0xFF for the third (CRC) byte as well, if CRC is enabled. So the 0xFFFF or 0xFFFFFF will indicate to the controller that the internal oscillator is not ready yet. 

The device will automatically wake the internal oscillator at a falling edge of SPI_CS, but it may take up to 50 µs to stabilize and be available for use to the SPI interface logic (this stabilization time may be longer depending on the state of the device, such as waking from DEEPSLEEP2 mode, in which the LFO is powered off). The address 0x7F used in the device is defined in such a manner that there should be no valid transaction to write 0xFF into this address. Thus the two-byte pattern 0xFFFF should never occur as a valid sequence in the first two bytes of a transaction (that is, it is only used as a flag that something is wrong, similar to an I<sup>2</sup> C NACK). 

Due to the delay in the HFO powering up if initially off, the device includes a programmable hysteresis to cause the HFO to stay powered for a programmable number of seconds after it is wakened by a falling edge on SPI_CS. This hysteresis is controlled by the **_Settings:Configuration:Comm Idle Time_** configuration setting, which can be set from 0 to 255 seconds (while in SPI mode, the device will use a minimum hysteresis of 1 second even if the value is set to 0). The host can set this to a longer time (up to 255 seconds) and maintain regular communications within this time window, causing the HFO to stay powered, so the device can respond quickly to SPI transactions. However, keeping the HFO running continuously will cause the device to consume additional supply current beyond what it would consume if the HFO were only powered when needed (the HDO draws ≈ 30 µA when powered). To avoid this extra supply current, the host can send an initial, unnecessary SPI transaction to cause the HFO to waken, and retry this until a valid response is returned on SPI_MISO. At this point, the host can begin sending the intended SPI transactions. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 55 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

If an excessive number of SPI transactions occur over a long period of time, the device may experience a watchdog fault. It is recommended to limit the frequency of SPI transactions by providing approximately 50 μs from the end of one transaction to the start of a new transaction. 

The device includes ability to detect a frozen or disconnected SPI bus condition, and it will then reset the bus logic. This condition is recognized when the SPI_CS is low and the SPI_SCLK is static and not changing for a two second timeout. 

Depending on the version of the device being used, the SPI_MISO pin may be configured by default to use the REG18 LDO for its output drive, which results in a 1.8-V signal level. This may cause communications errors if the host processor operates with a higher voltage, such as 3.3 V or 5 V. The SPI_MISO pin can be programmed to instead use the REG1 LDO for its output drive by setting the **_Settings:Configuration:SPI Configuration[MISO_REG1]_** data memory configuration bit. This bit should only be set if the REG1 LDO is powered. After this bit has been modified, it is necessary to send the _SWAP_TO_SPI()_ or _SWAP_COMM_MODE()_ subcommands for the device to use the new value. 

The device includes optional pin filtering on the SPI input pins, which implements a filter with approximately 200 ns delay on each input pin. This filtering is enabled by default but can be disabled by clearing the **_Settings:Configuration:SPI Configuration[FILT]_** data memory configuration bit. 

##### **14.3.1 SPI Protocol** 

The first byte of a SPI transaction consists of an R/W bit (R = 0, W = 1), followed by a 7-bit address, MSB-first. If the controller (host) is writing, then the second byte will be the data to be written. If the controller is reading, then the second byte sent on SPI_MOSI is ignored (except for CRC calculation). 

If CRC is enabled, then the controller must send as the third byte the 8-bit CRC code, which is calculated over the first two bytes. If the CRC is correct, then the values clocked in will be put into the incoming buffer. If the CRC is not correct, then the outgoing buffer will be set to 0xFFFF, and the outgoing CRC will be set to 0xAA (these are clocked out on the next transaction). 

During this transaction, the logic will clock out the contents of the outgoing buffer. If the outgoing buffer has not been updated since the last transaction, then the logic will clock out 0xFFFF, and if the CRC is clocked, it will clock out 0x00 for the CRC (if enabled). Thus the 0xFFFF00 will indicate to the controller that the outgoing buffer was not updated by the internal logic before the transaction occurred. This can occur when the device did not have sufficient time to update the buffer between consecutive transactions. 

When the internal logic takes the write-data from the interface logic and processes it, it also causes the R/W bit, address, and data to be copied into the outgoing buffer. On the next transaction, this data is clocked back to the controller. 

When the controller is initiating a read, the internal logic will put the R/W bit and address into the outgoing buffer, along with the data requested. The interface will compute the CRC on the two bytes in the outgoing buffer and clock that back to the controller if CRC is enabled (with the exceptions associated with 0xFFFF as noted above). A diagram of three transaction sequences with and without CRC are shown below, assuming CPOL=0. 

Copyright © 2021 Texas Instruments Incorporated 

56 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
SPI_CS<br>SPI_SCLK<br>SPI_MOSI<br>R/W bit & 7-bit  8-bit write  8-bit CRC<br>address # 1 data # 1 (for previous<br>two bytes)<br>SPI_MISO<br>Previous R/W bit  Previous 8-bit  8-bit CRC<br>& 7-bit address write or read data (for previous<br>two bytes)<br>Figure 14-5. SPI Transaction #1 Using CRC<br>SPI_CS<br>SPI_SCLK<br>SPI_MOSI<br>R/W bit & 7-bit  8-bit write data  8-bit CRC (for<br>address # 2 # 2 (or don’t  previous two<br>care if read) bytes)<br>SPI_MISO<br>R/W bit & 7-bit  8-bit write  8-bit CRC<br>address # 1 data # 1 (for previous<br>two bytes)<br><!-- End of picture text -->

**Figure 14-6. SPI Transaction #2 Using CRC** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 57 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
SPI_CS<br>SPI_SCLK<br>SPI_MOSI<br>R/W bit & 7-bit  8-bit write data  8-bit CRC<br>address # 3 # 3 (or don’t  (for previous<br>care if read) two bytes)<br>SPI_MISO<br>R/W bit & 7-bit  8-bit write or  8-bit CRC<br>address # 2 read data # 2 (for previous<br>two bytes)<br>Figure 14-7. SPI Transaction #3 Using CRC<br>SPI_CS<br>SPI_SCLK<br>SPI_MOSI<br>R/W bit & 7-bit  8-bit write<br>address # 1 data # 1<br>SPI_MISO<br>Previous R/W bit  Previous 8-bit<br>& 7-bit address write or read<br>data<br><!-- End of picture text -->

**Figure 14-8. SPI Transaction #1 Without CRC** 

Copyright © 2021 Texas Instruments Incorporated 

58 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
SPI_CS<br>SPI_SCLK<br>SPI_MOSI<br>R/W bit & 7-bit  8-bit write data<br>address # 2 # 2 (or don’t<br>care if read)<br>SPI_MISO<br>R/W bit & 7-bit  8-bit write<br>address # 1 data # 1<br><!-- End of picture text -->

**Figure 14-9. SPI Transaction #2 Without CRC** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 59 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
SPI_CS<br><!-- End of picture text -->



<!-- Start of picture text -->
SPI_SCLK<br>SPI_MOSI<br>R/W bit & 7-bit  8-bit write data<br>address # 3 # 3 (or don’t<br>care if read)<br>SPI_MISO<br>R/W bit & 7-bit  8-bit write or<br>address # 2 read data # 2<br><!-- End of picture text -->

**Figure 14-10. SPI Transaction #3 Without CRC** 

The time required for the device to process commands and subcommands will differ based on the specifics of each. The direct commands generally will complete within 50 μs, while subcommands can take longer, with different subcommands requiring different duration to complete. For example, when a particular subcommand is sent, the device requires approximately 200 μs to load the 32-byte data into the internal subcommand buffer. If the host provides sufficient time for this load to complete before beginning to read the buffer (readback from addresses 0x40 to 0x5F), the device will respond with valid data, rather than 0xFFFF00. When data has already been loaded into the subcommand buffer, this data can be read back with approximately 50 μs interval between SPI transactions. The _BQ76942 Technical Reference Manual_ provides more details on the approximate time duration required for specific commands and subcommands. 

The host software should incorporate a scheme to retry transactions that may not be successful. For example, if the device returns 0xFFFFFF on SPI_MISO, then the internal clock is not powered, and the transaction needs to be retried. Similarly, if the device returns 0xFFFFAA on a transaction, this indicates the previous transaction encountered a CRC error, and so the previous transaction must be retried. As described above, if the device returns 0xFFFF00, then the previous transaction had not completed when the present transaction was sent, which may mean the previous transaction should be retried, or needs more time to complete. 

#### **14.4 HDQ Communications Interface** 

The HDQ interface is an asynchronous return-to-one protocol where a processor communicates with the BQ76942 device using a single-wire connection to the ALERT pin or the HDQ pin, depending on configuration. Both the controller (host device) and responder (BQ76942) drive the HDQ interface using an open-drain driver with a pullup resistor from the HDQ interface to a supply voltage required on the circuit board. The BQ76942 device can be changed from the default communication mode to HDQ communication mode by setting the **_Settings:Configuration:Comm Type_** configuration register or by sending a subcommand (at which point the device switches to HDQ mode immediately). 

Copyright © 2021 Texas Instruments Incorporated 

60 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

##### **Note** 

The _SWAP_COMM_MODE()_ subcommand immediately changes the communications interface to that selected by the **_Comm Type_** configuration, while the _SWAP_TO_HDQ()_ subcommand immediately changes the interface to HDQ using the ALERT pin. 

With HDQ, the least significant bit (LSB) of a data byte (command) or word (data) is transmitted first. 

The 8-bit command code consists of two fields: the 7-bit HDQ command code (bits 0–6) and the 1-bit R/W field (MSB Bit 7). The R/W field directs the device to do one of the following: 

- Accept the next 8 bits as data from the host to the device, or 

- Output 8 bits of data from the device to the host in response to the 7-bit command. 

The HDQ peripheral on the BQ76942 device can transmit and receive data as an HDQ responder only. 

The return-to-one data bit frame of HDQ consists of the following sections: 

1. The first section is used to start the transmission by the host sending a Break (the host drives the HDQ interface to a logic-low state for a time t(B)) followed by a Break Recovery (the host releases the HDQ interface for a time t(BR)). 

2. The next section is for host command transmission, where the host transmits 8 bits by driving the HDQ interface for 8 T(CYCH) time slots. For each time slot, the HDQ line is driven low for a time T(HW0) (host writing a "0") or T(HW1) (host writing a "1"). The HDQ pin is then released and remains high to complete each T(CYCH) time slot. 

3. The next section is for data transmission where the host (if a write was initiated) or device (if a read was initiated) transmits 8 bits by driving the HDQ interface for 8 T(CYCH) (if host is driving) or T(CYCD) (if device is driving) time slots. The HDQ line is driven low for a time T(HW0) (host writing a "0"), T(HW1) (host writing a "1"), T(DW0) (device writing a "0"), or T(DW1) (device writing a "1"). The HDQ pin is then released and remains high to complete the time slot. The HDQ interface does not auto-increment, so a separate transaction must be sent for each byte to be transferred. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 61 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **15 Cell Balancing** 

#### **15.1 Cell Balancing Overview** 

The BQ76942 device supports passive cell balancing by bypassing the current of a selected cell during charging or at rest, using either integrated bypass switches between cells, or external bypass FET switches. The device incorporates a voltage-based balancing algorithm which can optionally autonomously balance cells without requiring any interaction with a host processor. Or if preferred, balancing can be entirely controlled manually from a host processor. For autonomous balancing, the device will only balance non-adjacent cells in use (it does not consider inputs used to measure interconnect as cells in use). In order to avoid excessive power dissipation within the BQ76942 device, the maximum number of cells allowed to balance simultaneously can be limited by configuration setting. For host-controlled balancing, adjacent as well as non-adjacent cells can be balanced. Host-controlled balancing can be controlled using specific subcommands sent by the host. The device also returns status information regarding how long cells have been balanced through subcommands. 

When host-controlled balancing is initiated using subcommands, the device starts a timer and will continue balancing until the timer reaches a programmed value, or a new balancing subcommand is issued (which resets the timer). This is included as a precaution, in case the host processor initiated balancing but then stopped communication with the BQ76942 device, so that balancing would not continue indefinitely. 

The BQ76942 device can automatically balance cells using a voltage-based algorithm based on environmental and system conditions. Several settings are provided to control when balancing is allowed, which are described in detail in the _BQ76942 Technical Reference Manual_ . 

Due to the current that flows into the cell input pins on the BQ76942 device while balancing is active, the measurement of cell voltages and evaluation of cell voltage protections by the device is modified during balancing. Balancing is temporarily disabled during the regular measurement loop while the actively balanced cell is being measured by the ADC, as well as when the cells immediately adjacent to the active cell are being measured. Similarly, balancing on the top cell is disabled while the stack voltage measurement is underway. This occurs on every measurement loop, and so can result in significant reduction in the average balancing current that flows. In order to help alleviate this, additional configuration bits are provided which cause the device to slow the measurement loop speed when cell balancing is active. The BQ76942 device will insert current-only measurements after each voltage and temperature scan loop to slow down voltage measurements and thereby increase the average balancing current. 

The device includes an internal die temperature check, to disable balancing if the die temperature exceeds a programmable threshold. However, the customer should still carefully analyze the thermal effect of the balancing on the device in system. Based on the planned ambient temperature of the device during operation and the thermal properties of the package, the maximum power should be calculated that can be dissipated within the device and still ensure operation remains within the recommended operating temperature range. The cell balancing configuration can then be determined such that the device power remains below this level by limiting the maximum number of cells that can be balanced simultaneously, or by reducing the balancing current of each cell by appropriate selection of the external resistance in series with each cell. 

Copyright © 2021 Texas Instruments Incorporated 

62 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **16 Application and Implementation** 

##### **Note** 

Information in the following applications sections is not part of the TI component specification, and TI does not warrant its accuracy or completeness. TI’s customers are responsible for determining suitability of components for their purposes. Customers should validate and test their design implementation to confirm system functionality. 

#### **16.1 Application Information** 

The BQ76942 device can be used with 3-series to 10-series battery packs, supporting a top-of-stack voltage ranging from 5 V up to 55 V. To design and implement a comprehensive set of parameters for a specific battery pack, during development the user can utilize Battery Management Studio (BQSTUDIO), which is a graphical user-interface tool installed on a PC. Using BQSTUDIO, the device can be configured for specific application requirements during development once the system parameters, such as fault trigger thresholds for protection, enable or disable of certain features for operation, configuration of cells, and more are known. This results in a "golden image" of settings, which can then be programmed into the device registers or OTP memory. 

#### **16.2 Typical Applications** 

Figure 16-1 shows a simplified application schematic for a 10-series battery pack, using the BQ76942 together with an external secondary protector, a host microcontroller, and a communications transceiver. This configuration uses CHG and DSG FETs in series, together with high-side PFET devices used to implement precharge and predischarge functionality. See the following implementation considerations: 

- The external NPN BJT used for the REGIN preregulator can be configured with its collector routed either to the cell battery stack or the middle of the protection FETs. 

- A diode is recommended in the drain circuit of the external NPN BJT, which avoids reverse current flow from the BREG pin through the BJT base to collector in the event of a pack short circuit. This diode can be a Schottky diode if low voltage pack operation is needed; otherwise, a conventional diode can be used. 

- A series diode is recommended at the BAT pin, together with a capacitor from the pin to VSS. These components enable the device to continue operating for a short time when a pack short circuit occurs, which may cause the PACK+ and top-of-stack voltages to drop to approximately 0 V. In this case, the diode prevents the BAT pin from being pulled low with the stack, and the device will continue to operate, drawing current from the capacitor. Generally, operation is only required for a short time until the device detects the short circuit event and disables the DSG FET. A Schottky diode can be used if low voltage pack operation is needed; otherwise, a conventional diode can be used. 

- The diode in the BAT connection and the diode in the BJT collector should not be shared, because the REG0 circuit might discharge the capacitor on BAT too quickly during a short circuit event. 

- The recommended voltage range on the VC0 to VC4 pins extends to –0.2 V. This can be used, for example, to measure a differential voltage that extends slightly below ground, such as the voltage across a second sense resistor in parallel with that connected to the SRP and SRN pins. 

- If a system does not use high-side protection FETs, then the PACK pin can be connected through a series 10-kΩ resistor to the top of the stack. The LD pin can be connected to VSS. In this case, the LD pin can also be controlled separately to wake the device from SHUTDOWN mode, such as through external circuitry that holds the LD pin at the voltage of VSS while the device stays in SHUTDOWN, and to be driven above a voltage of VWAKEONLD to wake from SHUTDOWN. 

- TI recommends using 100-Ω resistors in series with the SRP and SRN pins, and a 100 nF capacitor with optional 100-pF differential filter capacitance between the pins for filtering. The routing of these components, together with the sense resistor, to the pins should be minimized and fully symmetric, with all components recommended to stay on the same side of the PCB with the device. Optional 0.1-μF filter capacitors can be added for additional noise filtering at each sense input pin to VSS. 

- Due to thermistors often being attached to cells and possibly needing long wires to connect back to the device, it may be helpful to add a capacitor from the thermistor pin to the device VSS. However, it is important 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 63 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

to not use too large of a value of capacitor, since this will affect the settling time when the thermistor is biased and measured periodically. A rule of thumb is to keep the time constant of the circuit < 5% of the measurement time. When **_Settings:Configuration:Power Config[FASTADC]_** = 0, the measurement time is approximately 3 ms, and with **_[FASTADC]_** = 1, the measurement time is halved to approximately 1.5 ms. When using the 18-kΩ pullup resistor with the thermistor, the time constant is generally less than (18 kΩ) × C, so a capacitor less than 4 nF is recommended. When using the 180-kΩ pullup resistor, the capacitor should be less than 400 pF. 

- The integrated charge pump generates a voltage on the CP1 capacitor, requiring approximately 60 ms to charge up to approximately 11 V when first enabled using the recommended 470-nF capacitor value. When the CHG or DSG drivers are enabled, charge redistribution occurs from the CP1 capacitor to the CHG and DSG capacitive FET loads. This generally results in a brief drop in the voltage on CP1, which is then replenished by the charge pump. If the FET capacitive loading is large, such that at FET turn-on the voltage on CP1 drops below an acceptable level for the application, then the value of the CP1 capacitor can be increased. This has the drawback of requiring a longer startup time for the voltage on CP1 when the charge pump is first powered on, and so should be evaluated to ensure it is acceptable in the system. For example, if the CHG and DSG FETs are enabled simultaneously and their combined gate capacitance is approximately 400 nF, then changing CP1 to a value of 2200 nF results in the 11-V charge pump level dropping to approximately 9 V before being restored to the 11-V level by the charge pump. 

Copyright © 2021 Texas Instruments Incorporated 

64 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 



<!-- Start of picture text -->
BQ76942<br>www.ti.com SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021<br>PCHG PDSG<br>SECONDARY<br>FUSE<br>PROTECTOR<br>PACK+<br>5V COMMUNICATIONS<br>TRANSCEIVER COMM TO<br>SYSTEM<br>+<br>NC REGIN COMM<br>VC9 REG1<br>+ NC REG2 3.3V VDD<br>VC8 RST_SHUT GPIO<br>+<br>NC DDSG DSG  Logic Out<br>MCU<br>VC7 DCHG CHG  Logic Out<br>+ NC DFETOFF GPIO<br>VC6 CFETOFF GPIO<br>+<br>NC HDQ<br>VC5 SDA SDA<br>+ NC SCL SCL<br>VC4 ALERT INT<br>+<br>GND<br>TS<br>+<br>+<br>TS<br>+<br>PACK-<br>PCHG PDSG FUSE<br>VC10 BAT CP1 CHG NC DSG PACK LD PCHG PDSG FUSE BREG<br>VC3 VC2 VC1 VC0 VSS SRP NC SRN TS1 TS2 TS3 REG18<br><!-- End of picture text -->

**Figure 16-1. BQ76942 10-Series Cell Typical Implementation (Simplified Schematic)** 

##### **16.2.1 Design Requirements (Example)** 

**Table 16-1. BQ76942 Design Requirements** 

|**DESIGN PARAMETER**|**EXAMPLE VALUE**|
|---|---|
|Minimum system operating voltage|25 V|
|Cell minimum operating voltage|2.5 V|
|Series cell count|10|
|Sense resistor|1 mΩ|
|Number of thermistors|3 (using TS1, TS2, and TS3 pins, all for cells)|
|Charge voltage|42.5 V|
|Maximum charge current|8.0 A|
|Peak discharge current|20.0 A|
|Configuration settings|programmed in OTP during customer production|
|Protection subsystem configuration|Series FET configuration, device monitors, disables FETs upon fault, recovers autonomously|



Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 65 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

|**Table 16-1.**|**BQ76942 Design Requirements(continued)**|
|---|---|
|**DESIGN PARAMETER**|**EXAMPLE VALUE**|
|OV protection threshold|4.30 V|
|OV protection delay|500 ms|
|OV protection recovery hysteresis|100 mV|
|UV protection threshold|2.5 V|
|UV protection delay|20 ms|
|UV protection recovery hysteresis|100 mV|
|SCD protection threshold|80 mV (corresponding to a nominal 80 A, based on a 1-mΩ sense resistor)|
|SCD protection delay|50 µs|
|OCD1 protection threshold|68 mV (corresponding to a nominal 68 A, based on a 1-mΩ sense resistor)|
|OCD1 protection delay|10 ms|
|OCD2 protection threshold|56 mV (corresponding to a nominal 56 A, based on a 1-mΩ sense resistor)|
|OCD2 protection delay|80 ms|
|OCD3 protection threshold|28 mV (corresponding to a nominal 28 A, based on a 1-mΩ sense resistor)|
|OCD3 protection delay|160 ms|
|OCC protection threshold|8 mV (corresponding to a nominal 8 A, based on a 1-mΩ sense resistor)|
|OCC protection delay|160 ms|
|OTD protection threshold|60°C|
|OTD protection delay|2 s|
|OTC protection threshold|45°C|
|OTC protection delay|2 s|
|UTD protection threshold|–20°C|
|UTD protection delay|10 s|
|UTC protection threshold|0°C|
|UTC protection delay|5 s|
|Host watchdog timeout protection delay|5 s|
|CFETOFF pin functionality|Use as CFETOFF, polarity = normally high, driven low to disable FET|
|DFETOFF pin functionality|Use as DFETOFF, polarity = normally high, driven low to disable FET|
|ALERT pin functionality|Use as ALERT interrupt pin, polarity = driven low when active, hi-Z otherwise|
|REG1 LDO Usage|Use for 3.3-V output|
|Cell balancing|Enabled when imbalance exceeds 100 mV|



##### **16.2.2 Detailed Design Procedure** 

- Determine the number of series cells. 

   - This value depends on the cell chemistry and the load requirements of the system. For example, to support a minimum battery voltage of 25 V using Li-CO2 type cells with a cell minimum voltage of 2.5 V, 10-series cells should be used. 

      - For the correct cell connections, see _Usage of VC Pins for Cells Versus Interconnect_ . 

- Protection FET selection and configuration 

   - The BQ76942 device is designed for use with high-side NFET protection (low-side protection NFETs can be used by leveraging the DCHG / DDSG signals). 

   - The configuration should be selected for series Versus parallel FETs, which may lead to different FET selection for charge Versus discharge direction. 

   - These FETs should be rated for the maximum: 

      - Voltage, which should be approximately 5 V (DC) to 10 V (peak) per series cell. 

      - Current, which should be calculated based on both the maximum DC current and the maximum transient current with some margin. 

Copyright © 2021 Texas Instruments Incorporated 

66 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

      - Power dissipation, which can be a factor of the RDS(ON) rating of the FET, the FET package, and the PCB design. 

   - The overdrive level of the BQ76942 device charge pump should be selected based on RDS(ON) requirements for the protection FETs and their voltage handling requirements. If the FETs are selected with a maximum gate-to-source voltage of 15 V, then the 11-V overdrive mode within the BQ76942 device can be used. If the FETs are not specified to withstand this level, or there is a concern over gate leakage current on the FETs, the lower overdrive level of 5.5 V can be selected. 

- Sense resistor selection 

   - The resistance value should be selected to maximize the input range of the coulomb counter but not exceed the absolute maximum ratings, and avoid excessive heat generation within the resistor. 

      - Using the normal maximum charge or discharge current, the sense resistor = 200 mV / 20.0 A = 10 mΩ maximum. 

      - However, considering a short circuit discharge current of 80 A, the recommended maximum SRP, SRN voltage of ≈0.75 V, and the maximum SCD threshold of 500 mV, the sense resistor should be below 500 mV / 80 A = 6.25-mΩ maximum. 

   - Further tolerance analysis (value tolerance, temperature variation, and so on) and PCB design margin should also be considered, so a sense resistor of 1 mΩ is suitable with a 50-ppm temperature coefficient and power rating of 1 W. 

- The REG1 is selected to provide the supply for an external host processor, with output voltage selected for 3.3 V. 

   - The NPN BJT used for the REG0 preregulator should be selected to support the maximum collector-toemitter voltage of the maximum charging voltage of 42.5 V. The gain of the BJT should be chosen so it can provide the required maximum output current with a base current level that can be provided from the BQ76942 device. 

   - The BJT should support the maximum current expected from the REG1 (maximum of 45 mA, with short circuit current limit of up to ≈80 mA). 

   - A diode can optionally be included in the collector circuit of the BJT, in order to avoid reverse current flow from BREG through the base-collector junction of the BJT to PACK+ during a pack short circuit event. This diode can be seen in Figure 16-1 at D2. 

   - A large resistor (such as 10 MΩ) is recommended from BREG to VSS to avoid any unintended leakage current that may occur during SHUTDOWN mode. 

##### **16.2.3 Application Performance Plot** 

Figure 16-2 shows the error in measured temperature using an external Semitec 103-AT thermistor, the default temperature polynomial, and the internal 18-kΩ pullup resistor. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 67 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
www.ti.com<br><!-- End of picture text -->





<!-- Start of picture text -->
Measurements are taken using a Semitec 103-AT thermistor, the default temperature polynomial, and the 18-kΩ internal pullup<br>resistor.<br><!-- End of picture text -->

**Figure 16-2. Thermistor Temperature Error** 

##### **16.2.4 Calibration Process** 

The BQ76942 device includes the ability for the user to calibrate the current, voltage, and temperature measurements on the customer production line. Detailed procedures are included in the _BQ76942 Technical Reference Manual_ . The device provides capability to calibrate individual cell voltage measurements, stack voltage, PACK pin voltage, LD pin voltage, current measurement, and individual temperature measurements. 

##### **16.2.5 Design Example** 

Figure 16-3 and Figure 16-4 show a full schematic of a basic monitor circuit based on the BQ76942 for a 7-series battery pack. _Layout Example_ shows the board layout for this design. 

Copyright © 2021 Texas Instruments Incorporated 

68 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
7P D1 R1 TP1BAT<br>100V 100 C11uF C2100pF C30.47uF TP2 CD<br>U1<br>VSS VSS<br>46 CP1 CHG 45 CHG CHG 100V D2<br>7PNC6P5P4P3P2P1P1N J139502-1009123456789 TP7 TP3BAT+ R520.0R620.0R720.0R920.0R1020.020.0R220.0R320.0 R11 VSS C13220nFC422C622C1022000nFnFnF C522C9220nFC11220nFC12220nF0nF SRPSRN VSSRT1 TP6 TP9TS1VSSTS2RT2TP8 47481012131415161819202223242111246835791 BATVC10VC9VC8VC7VC6VC5VC4VC3VC2VC1VC0SRPNCSRNTS1TS2TS3NCNCNCNCNCNCREG18 RST_SHUTDFETOFFCFETOFFALERTREGINDCHGPCHGDDSGPDSGBREGREG2PACKFUSEREG1HDQDSGSDAVSSSCLNCLD 444342414039383736353433323130292827262517 REGDSGPACKFUSELDR121.0k1.0kR131 R81.0kC71uFDSGPACKLDFUSEREGINBREGVSS C822nF TP4TP5 VSS1 R4150Q1FCX495TA VSS C22REG1uF 1<br>REG18<br>BQ76942PFBR VSS External I2C Connection<br>C142.2uF R1410k R1510k J2<br>4<br>VSSTS2 321 SDASCLPACK-<br>BAT- TP11SRP SRNTP12 TP10 U2 U3 E1 E2PGND<br>C16 J3<br>1<br>100pF 2<br>C17 PEC02SAAN<br>Net-TieNT1 TP13GND TP14GND TP15GND TP16GND R160.1uF R17 PGND<br>100 100<br>VSS VSS VSS VSS WAKE<br>VSS<br>R18<br>10k<br>TP17BAT- R19<br>0.001 PGND VSS<br>Figure 16-3. BQ76942 7-Series Cell Schematic Diagram—Monitor<br>7P<br>TP18<br>C18 C19<br>D3<br>Red 0.1uF 0.1uF<br>FUSE<br>R20<br>3.9k<br>FUSE<br>R213.9k TP19 Q2 Q3<br>D416V 10MR22 1,2,3 7,85,6, 5,6,7,8 1,2,3 10MR23 16VD5 10MR24 16VD6 C200.1uF<br>FUSE R250 10kR26 Q4 C210.1uF PACK+ 43 43 PACK+PACK+<br>TP20 TP21 2 2 PACK-<br>R275.1k TP22 E3 1 1 PACK-<br>FUSEPIN J4 Output<br>1 Q5 R28<br>PMV213SN,215 5.1k<br>D7<br>CHG 100V<br>R2920k C220.1uF TP23 PGND<br>D8 PGND<br>10V R30 R31<br>5.1k 7.50k<br>CHG CD DSG<br>VSS R325.1k PACK LD TP24<br>TP25 TP26<br>PGND<br>TP27 D9<br>100V R33 R34<br>PACK<br>5.1k 5.1k<br>R35 R36<br>DSG LD 5.1k 5.1k<br>24,<br>3<br>° t<br>° t<br>1 1<br>2 2<br>4 4<br>3<br>2<br><!-- End of picture text -->

**Figure 16-4. BQ76942 7-Series Cell Schematic Diagram—Additional Circuitry** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 69 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **16.3 Random Cell Connection Support** 

The BQ76942 device supports a random connection sequence of cells to the device during pack manufacturing. For example, cell 7 in a 10-cell stack might be first connected at the input terminals leading to pins VC7 and VC6, then cell 4 may next be connected at the input terminals leading to pins VC4 and VC3, and so on. It is not necessary to connect the negative terminal of cell 1 first at VC0. As another example, consider a cell stack that is already assembled and cells already interconnected to each other, then the stack is connected to the PCB through a connector plugged in or soldered to the PCB. In this case, the sequence order in which the connections are made to the PCB can be random in time; they do not need to be controlled in a certain sequence. 

There are, however, some restrictions to how the cells are connected during manufacturing: 

- IMPORTANT: The cells in a stack **_cannot_** be connected to **_any_** VC pin on the device randomly, such as the lowest cell (cell 1) connected to VC9, while the top cell (cell 10) is connected to VC4, and so on. It is important that the cells in the stack be connected in ascending pin order, with the lowest cell (cell 1) connected between VC1 and VC0, the next higher voltage cell (cell 2) connected between VC2 and VC1, and so on. 

- The random cell connection support is possible due to high voltage tolerance on pins VC1–VC10. 

##### **Note** 

VC0 has a lower voltage tolerance. This is because VC0 should be connected through the seriescell input resistor to the VSS pin on the PCB, before any cells are attached to the PCB. Thus, the VC0 pin voltage is expected to remain close to the VSS pin voltage during cell attach. If VC0 is not connected through the series resistor to VSS on the PCB, then cells cannot be connected in random sequence. 

- Each of the VC1–VC10 pins includes a diode between the pin and the adjacent lower cell input pin (that is, between VC10 and VC9, between VC9 and VC8, and so on), which is reverse-biased in normal operation. This means an upper cell input pin should not be driven to a low voltage while a lower cell input pin is driven to a higher voltage, since this would forward bias these diodes. During cell attach, the cell input terminals should generally be floating before they are connected to the appropriate cell. It is expected that transient current will flow briefly when each cell is attached, but the cell voltages quickly stabilize to a state without DC current flowing through the diodes. However, if a large capacitance is included between a cell input pin and another terminal (such as VSS or another cell input pin), the transient current may become excessive and lead to device heating. Therefore, it is recommended to limit capacitances applied at each cell input pin to the values recommended in the specifications. 

#### **16.4 Startup Timing** 

At initial power up of the BQ76942 from a SHUTDOWN state, the device will progress through a sequence of events before entering NORMAL mode operation. These are described below for an example configuration, with approximate timing shown for the cases when **_[FASTADC]_** = 0 and **_[FASTADC]_** = 1. 

##### **Note** 

When the device is configured for autonomous FET control (that is, **_[FET_EN]_** = 1), the decision to enable FETs is only evaluated every 250 ms while in NORMAL mode, which is why the FETs are not enabled until approximately 280 ms after the wakeup event, even though the data was available earlier. 

Copyright © 2021 Texas Instruments Incorporated 

70 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

||**Table 16-2. Startup Seq  **<br>|**uence and Timing**<br>||
|---|---|---|---|
|**Step**|**Comment**|**FASTADC Setting**|**Time (relative to wakeup event)**|
|Wakeup event|Either the TS2 pin is pulled<br>low, or the LD pin is pulled<br>up, triggering the device to exit<br>SHUTDOWN mode.|0, 1|0|
|REG1 powered|This was measured with the OTP<br>programmed to autonomously<br>power the REG1 LDO.|0, 1|20 ms|
|INITSTART asserted|This was measured with the<br>OTP programmed to provide the<br>INITSTART bit in the Alarm signal<br>on the ALERT pin.|0, 1|22 ms|
||This was measured with the|0|69 ms|
|INITCOMP and ADSCAN<br>asserted|OTP programmed to provide the<br>INITCOMP and ADSCAN bits in<br>the Alarm signal on the ALERT<br>pin.|1|47 ms|
||This was measured with the<br>|0|164 ms|
|FULLSCAN asserted|OTP programmed to provide the<br>FULLSCAN bit in the Alarm<br>signal on the ALERT pin.|1|97 ms|
||This was measured with the OTP<br>|0|282 ms|
|FETs enabled|programmed to autonomously<br>enable FETs.|1|283 ms|



Figure 16-5 shows an example of an oscilloscope plot of a startup sequence with the device configured in OTP with **_[FASTADC]_** = 1, **_[FET_EN]_** = 1 for autonomous FET control, setup to use three thermistors, and providing the _[INITCOMP]_ flag on the ALERT pin. The TS2 pin is pulled low to initiate device wakeup from SHUTDOWN. 



<!-- Start of picture text -->
CLEAR AUTO. SINGLE Default Memory<br>H $ 50.00m:<br>g 134<br>Fj<br>3<br>he<br>OTT aeTY<br>g<br>3<br>3<br>Ey 3.40-"aenne<br>. a<i<br>(7EEKOMNsca ros REX] 2 cA. EEK ros ERGO] ScaL >  EEX ros EEKINm re<br><!-- End of picture text -->

**Figure 16-5. Startup Sequence Using** **_[FASTADC]_ = 1, with the** **_[INITCOMP]_ Flag Displayed on the ALERT Pin.** 

Copyright © 2021 Texas Instruments Incorporated 

71 

_Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

#### **16.5 FET Driver Turn-Off** 

The high-side CHG and DSG FET drivers operate differently when they are triggered to turn off their respective FET. The CHG driver includes an internal switch which discharges the CHG pin toward the BAT pin level. The DSG FET driver will discharge the DSG pin toward the LD pin level, but it includes a more complex structure than just a switch, to support a faster turn off. 

When the DSG driver is triggered to turn off, the device will initially begin discharging the DSG pin toward VSS. However, since the PACK+ terminal may not fall to a voltage near VSS quickly, the DSG FET gate should not be driven significantly below PACK+, otherwise the DSG FET may be damaged due to excessive negative gate-source voltage. Thus, the device monitors the voltage on the LD pin (which is connected to PACK+ through an external series resistor) and will stop the discharge when the DSG pin voltage drops below the LD pin voltage. When the discharge has stopped, the DSG pin voltage may relax back above the LD pin voltage, at which point the device will again discharge the DSG pin toward VSS, until the DSG gate voltage again falls below the LD pin voltage. This repeats in a series of pulses which over time discharge the DSG gate to the voltage of the LD pin. This pulsing continues for approximately 100 to 200 μs, after which the driver remains in a high impedance state if within approximately 500 mV of the voltage of the LD pin. The external resistor between the DSG gate and source then discharges the remaining FET VGS voltage so the FET remains off. 

The external series gate resistor between the DSG pin and the DSG FET gate is used to adjust the speed of the turn-off transient. A low resistance (such as 100 Ω) will provide a fast turn-off during a short circuit event, but this may result in an overly large inductive spike at the top of stack when the FET is disabled. A larger resistor value (such as 1 kΩ or 4.7 kΩ) will reduce this speed and the corresponding inductive spike level. 

Oscilloscope captures of DSG driver turn-off are shown below, with the DSG pin driving the gate of a CSD19536KCS NFET, which has a typical Ciss of 9250 pF. Figure 16-6 shows the signals when using a 1-kΩ series gate resistor between the DSG pin and the FET gate, and a light load on PACK+, such that the voltage on PACK+ drops slowly as the FET is disabled. The pulsing on the DSG pin can be seen lasting for approximately 170 μs. 



<!-- Start of picture text -->
Tek Run Trig?<br>Eolaeto :t || Rgate 1k<br>¥ €{ ohm and<br>bse ¢ | Schottky<br>PAC! 1 + 1 Light load on<br>sepa t | PACK+<br>BAT+ anne ath ARRAS Eta<br>Ln, t |<br>t<br>+|<br>7hen,<br>tee |<br>Chi’5.00V[@ip 5.00 _Mld0.0us) Al Ch3 \ 29.0)<br>ch3[_5.00V Cha 5.00V_ 4 Aug 2020<br>[10.00% 17:08:39<br><!-- End of picture text -->

**Figure 16-6. Moderate Speed DSG FET Turn-Off, Using a 1-kΩ Series Gate Resistor, and a Light Load on PACK+** 

A zoomed-in version of the pulsing generated by the DSG pin is shown in Figure 16-7, this time with PACK+ shorted to the top of stack. 

Copyright © 2021 Texas Instruments Incorporated 

72 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
Tek Run Trig?<br>t |<br>secipanpeeaan° el . tr | Rgate 1k<br>pss tana teanlendmlnaniy| a gmschothyhi<br>\ \ \ \ PACK+<br>PACK+\<br>\ \ \ | | Gomtedto<br>BAT+ |<br>'<br>t<br>£|<br>t|<br>i<br>i|<br>}|<br>+ |<br>Chi!ch3[_5.00V_(Ch4|_5.00V 5.00V ip) 3.00 V M[40ons| Al Ch31 29.0V 4 Aug 2020<br>(10.00 % 17:17:01<br><!-- End of picture text -->

**Figure 16-7. Zoomed-In View of the Pulsing on the DSG Pin During FET Turn-Off** 

A slower turn-off case is shown in Figure 16-8, using a 4.7-kΩ series gate resistor, and the PACK+ connector shorted to the top of stack. 



<!-- Start of picture text -->
Tek Run Trig?<br>gate U + |<br>a : | Rgate 4.7k<br>i t «ohm<br>ny t | PACK+<br>‘ 2 | shortedto<br>4 PACK+ | BAT+<br>— cnet meetin<br>na<br>DSG + {<br>£<br>t |<br>+<br>t|<br>t|<br>t |<br>Chilch3|_  5.00V5.00 V ch4|ip) 3.005.00  VV _M[20.0us|Al Ch3\ 29.0V 4 Aug 2020<br>(10.00 % 17:30:40<br><!-- End of picture text -->

**Figure 16-8. A Slower Turn-Off Case Using a 4.7-kΩ Series Gate Resistor, and the PACK+ Connector Shorted to the Top of the Stack** 

A fast turn-off case is shown in Figure 16-9, in which a 100-Ω series gate resistor is used between the DSG pin and the FET gate. 

Copyright © 2021 Texas Instruments Incorporated 

73 

_Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** 

**www.ti.com** 

SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 



<!-- Start of picture text -->
Tek Run Trig?<br>gate.“ t | Rgate 100<br>++ 4 ohmhi<br>t | PACK+<br>T | shortedto<br>_ PACK+ t | BAT+<br>— aes<br>t<br>i|<br>t|<br>Z |<br>t<br>t |<br>+ |<br>Chilch3|_  5.00V5.00 V ch4|ip) 3.005.00  VV _M[20.0us|Al Ch3\ 29.0V 4 Aug 2020<br>(10.00 % 17:35:15<br><!-- End of picture text -->

**Figure 16-9. A Fast Turn-Off Case with a 100-Ω Series Gate Resistor** 

#### **16.6 Unused Pins** 

Some device pins may not be needed in a particular application. The manner in which each should be terminated in this case is described below. 

**Table 16-3. Terminating Unused Pins** 

|**Pin**|**Name**|**Recommendation**|
|---|---|---|
|2, 4, 6, 8,<br>10, 12–<br>16, 48|VC0 – VC10|Cell inputs 1, 2, and 10 should always be connected to actual cells with cells connected between VC1 and<br>VC0, between VC2 and VC1, and VC10 and VC9. VC0 should be connected through a resistor and capacitor<br>on the pcb to pin 17 (VSS). Pins related to any unused cells (which may be cell 3–cell 9) can be connected to<br>the cell stack to measure interconnect resistance or provide a Kelvin-connection to actual cells, in which case<br>they should include a series resistor and parallel capacitor in similar fashion to pins connected to actual cells<br>(see_Usage of VC Pins for Cells Versus Interconnect_). Another option is to short unused VC pins directly to an<br>adjacent VC pin. All VC pins should be connected to either an adjacent VC pin, an actual cell (through R and C),<br>or stack interconnect resistance (through R and C).|
|18, 20|SRP, SRN|If not used, these pins should be connected to pin 17 (VSS).|
|1, 3, 5, 7,<br>9, 11, 19,<br>44|NC|These pins are not connected to silicon. They can be left floating or connected to an adjacent pin or connected<br>to VSS.|
|21, 23,<br>25, 28,<br>29, 30,<br>31, 32|TS1, TS3,<br>ALERT, HDQ,<br>CFETOFF,<br>DFETOFF,<br>DCHG, DDSG|If not used, these pins can be left floating or connected to pin 17 (VSS). Any of these pins (except for TS1 and<br>TS3) may be configured with the internal weak pulldown resistance enabled during operation, although this is<br>not necessary.|
|22|TS2|If the device is intended to enter SHUTDOWN mode, the TS2 pin should be left floating. If SHUTDOWN mode is<br>not used in the application and the TS2 pin is not used for a thermistor or ADCIN measurement, the TS2 pin can<br>be left floating or connected to pin 17 (VSS).|
|33|RST_SHUT|If not used, this pin should be connected to pin 17 (VSS).|
|34, 35|REG1, REG2|If not used, these pins can be left floating or connected to pin 17 (VSS).|
|36|REGIN|If not used, this pin should be connected to pin 17 (VSS).|
|37|BREG|If this pin is not used and pin 36 (REGIN) is also not used, both pins should be connected to pin 17 (VSS). If this<br>pin is not used but pin 36 is used (such as driven from an external source), then this pin should be connected to<br>pin 36 (REGIN).|
|38|FUSE|If not used, this pin can be left floating or connected to pin 17 (VSS).|
|39|PDSG|If not used, this pin should be left floating.|



Copyright © 2021 Texas Instruments Incorporated 

74 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

###### **www.ti.com** 

**Table 16-3. Terminating Unused Pins (continued)** 

|**Pin**|**Name**|**Recommendation**|
|---|---|---|
|40|PCHG|If not used, this pin should be left floating.|
|41|LD|If the DSG driver is not used, this pin can be connected through a series resistor to the PACK+ connector or can<br>be connected to pin 17 (VSS).|
|43|DSG|If not used, this pin should be left floating.|
|45|CHG|If not used, this pin should be left floating.|
|46|CP1|If not used, this pin should be connected to pin 47 (BAT). Note: If the charge pump is enabled with CP1<br>connected to BAT, the device consumes an additional ≈200 µA.|



### **17 Power Supply Requirements** 

The BQ76942 device draws its supply current from the BAT pin, which is typically connected to the top of stack point through a series diode, to protect against any fault within the device resulting in unintended charging of the pack. A series resistor and capacitor is included to lowpass filter fast variations on the stack voltage. During a short circuit event, the stack voltage may be momentarily pulled to a very low voltage before the protection FETs are disabled. In this case, the charge on the BAT pin capacitor will temporarily support the BQ76942 device supply current, to avoid the device losing power. 

### **18 Layout** 

#### **18.1 Layout Guidelines** 

- The quality of the Kelvin connections at the sense resistor is critical. The sense resistor must have a temperature coefficient no greater than 50 ppm in order to minimize current measurement drift with temperature. Choose the value of the sense resistor to correspond to the available overcurrent and shortcircuit ranges of the BQ76942 device. Parallel resistors can be used as long as good Kelvin sensing is ensured. The device is designed to support a 1-mΩ sense resistor. 

- In reference to the system circuitry, the following features require attention for component placement and layout: Differential Low-Pass Filter, and I<sup>2</sup> C communication. 

- The BQ76942 device uses an integrating delta-sigma ADC for current measurements. For best performance, 100-Ω resistors should be included from the sense resistor terminals to the SRP and SRN inputs of the device, with a 0.1-μF filter capacitor placed across the SRP and SRN pins. Optional 0.1-µF filter capacitors can be added for additional noise filtering at each sense input pin to ground. All filter components should be placed as close as possible to the device, rather than close to the sense resistor, and the traces from the sense resistor routed in parallel to the filter circuit. A ground plane can also be included around the filter network to add additional noise immunity. 

- The BQ76942 device internal REG18 LDO requires an external decoupling capacitor, which should be placed as close to the REG18 pin as possible, with minimized trace inductance, and connected to a ground plane electrically connected to VSS. 

- The I<sup>2</sup> C clock and data pins have integrated ESD protection circuits; however, adding a Zener diode and series resistor on each pin provides more robust ESD performance. 

#### **18.2 Layout Example** 

An example circuit layout using the BQ76942 device in a 7-series cell design is described below. The design implements the schematic shown in Figure 16-3 and Figure 16-4, and uses a 2.5-inch × 2.75-inch 2-layer circuit card assembly, with cell connections on the left edge, and pack connections along the top edge of the board. Wide trace areas are used, reducing voltage drops on the high current paths. 

The board layout, which is shown in Figure 18-1 and Figure 18-2, includes spark gaps with the reference designator prefix _E_ . These spark gaps are fabricated with the board, and no component is installed. 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 75 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
/ \\ 1.PENID RG / \<br>ING a2 23 oo 2ewn O OO WX)<br>\iS SSSA cDa. Ti)Rag|Z) ep6 3.4,PACK+PACK+ ooo Ft or? ‘NS~—_SY]<br>~ E3<br>i i er<br>oO e co DEM ooo TP2t c20 Cat<br>8. |i + EAE Ir" 2<br>Q©) =:= 8 Ths Te1e . foo<br>_ <-> Bay O pack+ U2)<br>©| = |Io© pea wees! al.PR34 ri4f) J 7+ ©<br>® > —TP20 | | Lees Ris J i =O)<br>"| TP3 e “f is aa<br>OQ}Pa a ve TEXASINSTRUMENTS a Oe<br>O 2 ae. 8 Ty, et 12 Tp23 tp27<br>@)=-~! RZ F= ‘| ° lS isis cl&—* ° ©© OO°O© CHG.OODSG<br>~ | [ 6 Wwe rie<br>O} RS a c2 ]<br>O TP? — ac . jm "1<br>—~ R10 d* =Oy te 05, ca c3 [|] pat31 ic£2 f&o<br>©) ©) 58 Re ah ut * 5) Gye & FUSEPIN<br>a en F&Oroel| +38Ss e DS. ©.-O2) © 1P22O<br>2© Shi ft) Gals n mini b TP19<br>< ©«s2 a oes B 2 a= mh 6)<br>av Gime I rey? 24 = ra_ 2 |!<br>Feo >\z Rif 5) R39|<i aDt—} ° les= =<br>rise © 22 ORR: © |) Lg ole ber 8 i ©<br>8(© coog£©@ +Soege9 EAS *oa oli1g Tp4<br>(Gy rT 26) Toa mimim § a<br>ZKOS H©) tes 212© [6] Sa | ON<br>WSs \ © fa a oe / \<br>KOS i=— a we Te a Se! ee HG)<br>NS Juss © mis f J [Oo [l-ts2 tps er 6 it }<br>SSS Ris —zJ3 TP1OOO aeTPS SE©) ys. SSSf<br><!-- End of picture text -->

**Figure 18-1. BQ76942 Example Board Layout—Top Layer** 

Copyright © 2021 Texas Instruments Incorporated 

76 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 



<!-- Start of picture text -->
— J4 NN<br>{ \ 1. PGND ~~ f \<br>INS SNF a2 a3 p2 2.PGND ) © © 2) INS<br>\ } eo 3, PACK+ \ |<br>. A he 4, PACK+ cae Ny SS<br>—— eoo fF ——<br>Jt E3<br>- = ° pd — | |<br>= o ce bm coo Tp21 c20 Cai<br>[O} g or: 27... © J2<br>o| OE A A TpLs oo ©<br>= Sag wo OlPAcKS ee ey<br>=A es<br>OQ}= | =& (Vinee©~ R24 | SS;PR34aS Ri4— =] cue*3 “©=<br>|le= rp. > RIS )<br>Z ) ~ ° D7 — BE: ee | (6<br>im ‘ é Jo<br>é ) vi TEXASINSTRUMENTS<br>©)= eee? @ @ RI TP1. TP2 TP23 TP27<br>©) Lrpe a27 Caria a SIE ONO) CHGLOILODSG<br>©) Rg lee LIJLILILear “] R30<br>So TP? se a8 ». allie r e<br>RIOf iv =2 6 ca c4 ca Weed)na ae8O (ee8a<br>(>| BAT- Soa Riu= G ul * R28 ut ee<br>© +4 © BO, |; § [es BN | | ruseenn<br>| x ot « G 3 e | ©)}\\©) 22.©<br>a2O , 46 ymn¢4 a \o78 > TP19<br>tn 8 [ | ine & Al ra O<br>NOMSO po a lo = FUSE<br>Foe $P12 OZ yea R33 SL, tight E<br>pe Meare el BOS R7E 8 ° 4<br>cman ie) Godage & pees 7 TP4<br><<= @)= aeTes RT2(pore a Fron 3, JL 2 PRAWN_<br>SOQ) ©) Lies i =~] /<br>RYSS = — ee * 4p14 BS C8 R \<br>\<br>KW Juss tis [ J] |O [| Ts2 ts © “Ge 0S i 1 }<br>os } Rig OO: (@) = ©) uss /<br>J3 sotpto ©) TPS a "“ La<br><!-- End of picture text -->

**Figure 18-2. BQ76942 Example Board Layout—Bottom Layer** 

Copyright © 2021 Texas Instruments Incorporated 

_Submit Document Feedback_ 77 

Product Folder Links: _BQ76942_ 

**BQ76942** SLUSE14B – DECEMBER 2020 – REVISED DECEMBER 2021 

**www.ti.com** 

### **19 Device and Documentation Support** 

#### **19.1 Third-Party Products Disclaimer** 

TI'S PUBLICATION OF INFORMATION REGARDING THIRD-PARTY PRODUCTS OR SERVICES DOES NOT CONSTITUTE AN ENDORSEMENT REGARDING THE SUITABILITY OF SUCH PRODUCTS OR SERVICES OR A WARRANTY, REPRESENTATION OR ENDORSEMENT OF SUCH PRODUCTS OR SERVICES, EITHER ALONE OR IN COMBINATION WITH ANY TI PRODUCT OR SERVICE. 

#### **19.2 Documentation Support** 

For additional information, see the following related documents: 

- _BQ76942 Technical Reference Manual_ 

- _BQ76942 Evaluation Module User's Guide_ 

- _Using Low-Side FETs with the BQ769x2 Battery Monitor Family_ 

- _Cell Balancing with BQ769x2 Battery Monitors_ 

- _Multiple FETs with the BQ769x2 Battery Monitors_ 

- _BQ769x2 Software Development Guide_ 

- _BQ769x2 Calibration and OTP Programming Guide_ 

- _Pin Equivalent Diagrams for the BQ76952, BQ76942, and BQ769142_ 

- A glossary that defines terms, acronyms, and definitions can be found at _TI Glossary_ . 

Additional documents can be found in the product folder at _BQ76942 Technical documentation_ . 

##### **19.2.1 Receiving Notification of Documentation Updates** 

To receive notification of documentation updates, navigate to the device product folder on ti.com. Click on _Subscribe to updates_ to register and receive a weekly digest of any product information that has changed. For change details, review the revision history included in any revised document. 

#### **19.3 Support Resources** 

TI E2E<sup>™</sup> support forums are an engineer's go-to source for fast, verified answers and design help — straight from the experts. Search existing answers or ask your own question to get the quick design help you need. 

Linked content is provided "AS IS" by the respective contributors. They do not constitute TI specifications and do not necessarily reflect TI's views; see TI's Terms of Use. 

#### **19.4 Trademarks** 

TI E2E<sup>™</sup> is a trademark of Texas Instruments. 

All trademarks are the property of their respective owners. 

#### **19.5 Electrostatic Discharge Caution** 



This integrated circuit can be damaged by ESD. Texas Instruments recommends that all integrated circuits be handled with appropriate precautions. Failure to observe proper handling and installation procedures can cause damage. 

ESD damage can range from subtle performance degradation to complete device failure. Precision integrated circuits may be more susceptible to damage because very small parametric changes could cause the device not to meet its published specifications. 

#### **19.6 Glossary** 

TI Glossary This glossary lists and explains terms, acronyms, and definitions. 

### **20 Mechanical, Packaging, Orderable Information** 

The following pages include mechanical, packaging, and orderable information. This information is the most current data available for the designated devices. This data is subject to change without notice and revision of this document. For browser-based versions of this data sheet, refer to the left-hand navigation. 

Copyright © 2021 Texas Instruments Incorporated 

78 _Submit Document Feedback_ 

Product Folder Links: _BQ76942_ 

**PACKAGE OPTION ADDENDUM** 

www.ti.com 

31-Oct-2025 

#### **PACKAGING INFORMATION** 

|**Orderable part number**|**Status**<br>(1)|**Material type**<br>(2)|**Package | Pins**|**Package qty | Carrier**|**RoHS**<br>(3)|**Lead finish/**<br>**Ball material**<br>(4)|**MSL rating/**<br>**Peak reflow**<br>(5)|**Op temp (°C)**|**Part marking**<br>(6)|
|---|---|---|---|---|---|---|---|---|---|
|BQ7694201PFBR|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694201|
|BQ7694201PFBR.A|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694201|
|BQ7694202PFBR|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694202|
|BQ7694202PFBR.A|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694202|
|BQ7694203PFBR|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694203|
|BQ7694203PFBR.A|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694203|
|BQ7694204PFBR|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694204|
|BQ7694204PFBR.A|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ7694204|
|BQ76942PFBR|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ76942|
|BQ76942PFBR.A|Active|Production|TQFP(PFB) |48|1000|LARGE T&R|Yes|NIPDAU|Level-2-260C-1 YEAR|-40 to 85|BQ76942|



> **(1) Status:** For more details on status, see our product life cycle. 

> **(2) Material type:** When designated, preproduction parts are prototypes/experimental devices, and are not yet approved or released for full production. Testing and final process, including without limitation quality assurance, reliability performance testing, and/or process qualification, may not yet be complete, and this item is subject to further changes or possible discontinuation. If available for ordering, purchases will be subject to an additional waiver at checkout, and are intended for early internal evaluation purposes only. These items are sold without warranties of any kind. 

> **(3) RoHS values:** Yes, No, RoHS Exempt. See the TI RoHS Statement for additional information and value definition. 

> **(4) Lead finish/Ball material:** Parts may have multiple material finish options. Finish options are separated by a vertical ruled line. Lead finish/Ball material values may wrap to two lines if the finish value exceeds the maximum column width. 

> **(5) MSL rating/Peak reflow:** The moisture sensitivity level ratings and peak solder (reflow) temperatures. In the event that a part has multiple moisture sensitivity ratings, only the lowest level per JEDEC standards is shown. Refer to the shipping label for the actual reflow temperature that will be used to mount the part to the printed circuit board. 

> **(6) Part marking:** There may be an additional marking, which relates to the logo, the lot trace code information, or the environmental category of the part. 

Multiple part markings will be inside parentheses. Only one part marking contained in parentheses and separated by a "~" will appear on a part. If a line is indented then it is a continuation of the previous line and the two combined represent the entire part marking for that device. 

**Important Information and Disclaimer:** The information provided on this page represents TI's knowledge and belief as of the date that it is provided. TI bases its knowledge and belief on information provided by third parties, and makes no representation or warranty as to the accuracy of such information. Efforts are underway to better integrate information from third parties. TI has taken and continues to take reasonable steps to provide representative 

Addendum-Page 1 

**PACKAGE OPTION ADDENDUM** 

www.ti.com 

31-Oct-2025 

and accurate information but may not have conducted destructive testing or chemical analysis on incoming materials and chemicals. TI and TI suppliers consider certain information to be proprietary, and thus CAS numbers and other limited information may not be available for release. 

In no event shall TI's liability arising out of such information exceed the total purchase price of the TI part(s) at issue in this document sold by TI to Customer on an annual basis. 

Addendum-Page 2 

www.ti.com 

2-Dec-2021 

## **PACKAGE MATERIALS INFORMATION** 

#### **TAPE AND REEL INFORMATION** 



<!-- Start of picture text -->
REEL DIMENSIONS TAPE DIMENSIONS<br>\ / je KO[> 6Pt OO FOS f<br>Re Wo u<br>(+) Diameter Cavitycl FlAO he?<br>| Bo | Dimension designed to accommodate the component length _|<br>—_L Lry. Reel Width (W1)<br>QUADRANT ASSIGNMENTS FOR PIN 1 ORIENTATION IN TAPE<br>DO 00000000 G Sprocket Holes<br>[| Q3ar! a 4e]| | a 3r!| a4a || — User Direction >of Feed<br>Jo<br>Pocket Quadrants<br><!-- End of picture text -->

*All dimensions are nominal 

|**Device**<br>|**Package**<br>**Type**|**Package**<br>**Drawing**|**Pins**|**SPQ**|**Reel**<br>**Diameter**<br>**(mm)**|**Reel**<br>**Width**<br>**W1(mm)**|**A0**<br>**(mm)**|**B0**<br>**(mm)**|**K0**<br>**(mm)**|**P1**<br>**(mm)**|**W**<br>**(mm)**|**Pin1**<br>**Quadrant**|
|---|---|---|---|---|---|---|---|---|---|---|---|---|
|BQ7694201PFBR<br>~~po~~<br>|TQFP|PFB|48|1000|330.0|16.4|9.6|9.6|1.5|12.0|16.0|Q2|
|BQ7694202PFBR<br><br>~~po~~<br>|TQFP|PFB|48|1000|330.0|16.4|9.6|9.6|1.5|12.0|16.0|Q2|
|BQ7694203PFBR<br><br>~~po~~<br>|TQFP|PFB|48|1000|330.0|16.4|9.6|9.6|1.5|12.0|16.0|Q2|
|BQ7694204PFBR<br><br>~~po~~<br>|TQFP<br><br>|PFB<br><br>|48<br>|1000<br>|330.0<br>|16.4<br>|9.6<br>|9.6<br>|1.5<br>|12.0<br>|16.0<br>|Q2<br>|
|BQ76942PFBR<br><br>~~es~~|TQFP<br><br>~~es~~|PFB<br><br>~~es~~|48<br>|1000<br>|330.0<br>|16.4<br>|9.6<br>|9.6<br>|1.5<br>|12.0<br>|16.0<br>|Q2<br>|



Pack Materials-Page 1 

www.ti.com 

2-Dec-2021 

## **PACKAGE MATERIALS INFORMATION** 



<!-- Start of picture text -->
TAPE AND REEL BOX DIMENSIONS<br>O74<br>aan<br>/ oo~<<br>ee1 SS SKa S<br>L — YA_ at<br>WN ~ a ~ *<br>~ SN a<br>—_.a<br><!-- End of picture text -->

*All dimensions are nominal 

|**Device**<br>~~a~~<br>|**Package Type**<br>~~es~~<br>|**Package Drawing**<br><br>~~e~~|**Pins**<br>|**SPQ**|**Length (mm)**|**Width (mm)**|**Height (mm)**|
|---|---|---|---|---|---|---|---|
|BQ7694201PFBR<br><br>~~po~~<br>|TQFP<br><br><br>|PFB<br><br>|48<br>|1000|336.6|336.6|31.8|
|BQ7694202PFBR<br><br>**~~p~~**~~o~~|TQFP<br><br>|PFB<br>|48<br>|1000<br>|336.6<br>|336.6<br>|31.8<br>|
|BQ7694203PFBR<br><br><br>|TQFP<br><br><br>|PFB<br><br><br>|48<br><br><br>|1000<br><br><br>|336.6<br><br><br><br>|336.6<br><br><br><br>|31.8<br><br><br><br>|
|BQ7694204PFBR<br><br>|TQFP<br><br>|PFB<br><br>|48<br><br>|1000<br><br>|336.6<br><br><br>|336.6<br><br><br><br>|31.8<br><br><br><br>|
|BQ76942PFBR<br>|TQFP<br>|PFB<br>|48<br>|1000<br>|336.6<br><br>|336.6<br><br><br>|31.8<br><br><br>|



Pack Materials-Page 2 

**PACKAGE OUTLINE** 

**PFB0048A** 

**TQFP - 1.2 mm max height** 



**PLASTIC QUAD FLATPACK** 



<!-- Start of picture text -->
7.2<br>B<br>6.8<br>NOTE 3<br>48 37<br>PIN 1 ID<br>1 36<br>7.2 9.2<br>6.8 8.8  TYP<br>NOTE 3<br>12<br>25<br>13 24<br>A<br>td,oe 44X  0.5 48X  0.27 0.17<br>0.08 C A B<br>4X  5.5<br>a a n<br>1.2 MAX<br>C<br>SEATING PLANE<br>(0.13) S EE DETAIL A 0.08<br>TYP<br>0.25<br>GAGE PLANE (1)<br>0.75<br>0.05 MIN<br>0 | -7 epee 0.45<br>DETAIL  AA 16<br>TYPICAL<br>4215157/A   03/2024<br><!-- End of picture text -->

###### NOTES: 

1. All linear dimensions are in millimeters. Any dimensions in parenthesis are for reference only. Dimensioning and tolerancing per ASME Y14.5M. 

2. This drawing is subject to change without notice. 

3. Reference JEDEC registration MS-026. 

~~<u>WP eS</u>~~ www.ti.com ~~vents~~ 

**EXAMPLE BOARD LAYOUT** 

**PFB0048A** 

**TQFP - 1.2 mm max height** 

###### PLASTIC QUAD FLATPACK 



<!-- Start of picture text -->
SYMM<br>48 37 S EE DETAILS<br>48X (1.35)<br>1<br>36<br>48X (0.25)<br>SYMM<br>(8.5)<br>44X (0.5)<br>12 25<br>(R0.05) TYP<br>13 24<br>(8.5)<br>LAND PATTERN EXAMPLE<br>EXPOSED METAL SHOWN<br>SCALE:8X<br>0.05 MAX 0.05 MIN<br>ALL AROUND ALL AROUND<br>M ETAL S OLDER MASK<br>OPENING<br>EXPOSED META L<br>EXPOSED META L<br>M ETAL UNDER<br>S OLDER MASK SOLDER MASK<br>OPENING<br>NON SOLDER MASK SOLDER MASK<br>DEFINED DEFINED<br>SOLDER MASK DETAILS<br>4215157/A   03/2024<br><!-- End of picture text -->

NOTES: (continued) 

4. Publication IPC-7351 may have alternate designs. 

5. Solder mask tolerances between and around signal pads can vary based on board fabrication site. 

www.ti.com 

**EXAMPLE STENCIL DESIGN** 

**PFB0048A** 

**TQFP - 1.2 mm max height** 

PLASTIC QUAD FLATPACK 



<!-- Start of picture text -->
SYMM<br>48 37<br>48X (1.35)<br>1<br>36<br>48X (0.25)<br>SYMM<br>(8.5)<br>44X (0.5)<br>12 25<br>(R0.05) TYP<br>13 24<br>(8.5)<br>SOLDER PASTE EXAMPLE<br>SCALE:8X<br>4215157/A   03/2024<br><!-- End of picture text -->

NOTES: (continued) 

6. Laser cutting apertures with trapezoidal walls and rounded corners may offer better paste release. IPC-7525 may have alternate design recommendations. 

> 7. Board assembly site may have different recommendations for stencil design. 

www.ti.com 

### **IMPORTANT NOTICE AND DISCLAIMER** 

TI PROVIDES TECHNICAL AND RELIABILITY DATA (INCLUDING DATASHEETS), DESIGN RESOURCES (INCLUDING REFERENCE DESIGNS), APPLICATION OR OTHER DESIGN ADVICE, WEB TOOLS, SAFETY INFORMATION, AND OTHER RESOURCES “AS IS” AND WITH ALL FAULTS, AND DISCLAIMS ALL WARRANTIES, EXPRESS AND IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY RIGHTS. 

These resources are intended for skilled developers designing with TI products. You are solely responsible for (1) selecting the appropriate TI products for your application, (2) designing, validating and testing your application, and (3) ensuring your application meets applicable standards, and any other safety, security, regulatory or other requirements. 

These resources are subject to change without notice. TI grants you permission to use these resources only for development of an application that uses the TI products described in the resource. Other reproduction and display of these resources is prohibited. No license is granted to any other TI intellectual property right or to any third party intellectual property right. TI disclaims responsibility for, and you fully indemnify TI and its representatives against any claims, damages, costs, losses, and liabilities arising out of your use of these resources. TI’s products are provided subject to TI’s Terms of Sale, TI’s General Quality Guidelines, or other applicable terms available either on ti.com or provided in conjunction with such TI products. TI’s provision of these resources does not expand or otherwise alter TI’s applicable warranties or warranty disclaimers for TI products. Unless TI explicitly designates a product as custom or customer-specified, TI products are standard, catalog, general purpose devices. 

TI objects to and rejects any additional or different terms you may propose. 

Copyright © 2025, Texas Instruments Incorporated Last updated 10/2025 

