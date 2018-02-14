/*
 FILENAME:	ADPD105.h
 AUTHOR:	Orlando S. Hoilett
 EMAIL:


 Please see .cpp file for extended descriptions, instructions, and version updates
 
 
 DISCLAIMER

 The MIT License (MIT)

 (C) Copyright 6/22/17 by authors

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.


*/



#ifndef ADPD105_h
#define ADPD105_h


#include <stdio.h>
#include “Arduino.h”


const uint8_t ADPD105_addr = 0x64;

const uint8_t ADDR_REG = 0x0D;


//LFCSP Input onfigurations
const uint16_t SLOTA_PD_SEL = 0x14;
/*
 0x0: inputs are floating in Time Slot A.
 0x1: all PDx pins (PD1 to PD8) are connected during Time Slot A.
 0x4: PD5 to PD8 are connected during Time Slot A.
 0x5: PD1 to PD4 are connected during Time Slot A.
 Other: reserved.
*/

const uint16_t SLOTB_PD_SEL = 0x14;
/*
 0x0: inputs are floating in Time Slot B.
 0x1: all PDx pins (PD1 to PD8) are connected during Time Slot B.
 0x4: PD5 to PD8 are connected during Time Slot B.
 0x5: PD1 to PD4 are connected during Time Slot B.
 Other: reserved.
*/



//WLCSP Input Configurations
//0x14 [11:8] SLOTB_PD_SEL
const uint16_t SLOTB_PD_SEL = 0x14;
/*
 0x0: inputs are floating in Time Slot B.
 0x1: PD1-2 is connected to Channel 1; PD3-4 is connected to Channel 2 during Time Slot B.
 0x5: PD1-2 is connected to Channel 1 and Channel 2; PD3-4 is connected to Channel 3
 and Channel 4 during Time Slot B.
 Other: reserved.
 */


//[7:4] SLOTA_PD_SEL
const uint16_t SLOTA_PD_SEL = 0x14;
/*
 0x0: inputs are floating in Time Slot A.
 0x1: PD1-2 is connected to Channel 1; PD3-4 is connected to Channel 2 during Time Slot A.
 0x5: PD1-2 is connected to Channel 1 and Channel 2; PD3-4 is connected to Channel 3
 and Channel 4 during Time Slot A.
 Other: reserved.
 */


const uint16_t AFE_OFFSET_A_REG = 0x39;
const uint16_t AFE_OFFSET_B_REG = 0x3B;


const uint16_t FSAMPLE = 0x12; //Default = 0x0028, R/W, two-byte word
const uint16_t MODE_REG = 0x10;
const uint8_t STANDBY = 0x0000; //two-bytes
const uint8_t PROG = 0x0001; //two-bytes
const uint8_t NORM = 0x0002; //two-bytes

const uint16_t NUM_AVG_REG = 0x15; //R/W


const uint16_t MCLK = 32000;





class ADPD105
{
private:


public:

	//Default Constructor
	ADPD105();
    
    void write(uint8_t addr, uint8_t data);
    
    void setFSample(uint16_t freq);
    
    void enableExtSync() const;

    
};



#endif /* ADPD105_h */
