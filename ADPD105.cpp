/*
 FILENAME:	ADPD105.cpp
 AUTHOR:	Orlando S. Hoilett
 EMAIL:
 VERSION:


 DESCRIPTION


 A FEW INSTRUCTIONS


 UPDATES


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


#include "ADPD105.h"




void write(uint8_t addr, uint8_t data)
{
    Wire.beginTransmission(ADPD105_addr);
    Wire.write(addr);
    Wire.write(data);
    Wire.endTransmission();
    delay(1);
}





//void setFSample(uint16_t freq)
//@param                freq: the sampling frequency desired by the user
//
//This method sets the sampling frequency by
//
//Please see "Table 34. ADC Registers" in the datasheet for more information.
//Also, please see page 22 section "ADJUSTABLE SAMPLING FREQUENCY" as well.
//
void setFSample(float freq) const
{
    data = MCLK / (freq*4);
}


void enableExtSync() const
{
/*
 
 Page 22 "External Sync for Sampling "
 
 1. Write 0x1 to Register 0x10 to enter program mode.
 
 2. Write the appropriate value to Register 0x4F, Bits[3:2] to
 select whether the GPIO0 pin or the GPIO1 pin specifies
 when the next sample cycle occurs. Also, enable the
 appropriate input buffer using Register 0x4F, Bit 1, for the
 GPIO0 pin, or Register 0x4F, Bit 5, for the GPIO1 pin.
 
 3. Write 0x4000 to Register 0x38.
 
 4. Write 0x2 to Register 0x10 to start the sampling operations.
 
 5. Apply the external sync signal on the selected pin at the
 desired rate; sampling occurs at that rate. As with normal
 sampling operations, read the data using the FIFO or the
 data registers.
 
 */
}



void enableExtMCLK() const
{
    /*
     
     Page 22 "Providing an External 32kHz Clock"
     
     1. Drive the GPIO1 pin to a valid logic level or with the
     desired 32 kHz clock prior to enabling the GPIO1 pin as an
     input. Do not leave the pin floating prior to enabling it.
     
     2. Write 01 to Register 0x4F, Bits[6:5] to enable the GPIO1 pin as
     an input.
     
     3. Write 10 to Register 0x4B, Bits[8:7] to configure the devices to
     use an external 32 kHz clock. This setting disables the
     internal 32 kHz clock and enables the external 32 kHz clock.
     
     4. Write 0x1 to Register 0x10 to enter program mode.
     
     5. Write additional control registers in any order while the
     devices are in program mode to configure the devices as
     required.
     
     6. Write 0x2 to Register 0x10 to start the normal sampling
     operation.
     
     */
}










