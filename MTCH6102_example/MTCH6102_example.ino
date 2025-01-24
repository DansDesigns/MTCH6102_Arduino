/*
      MTCH6102 example
      reverse-engineered from: https://github.com/theapi/touch_timer/tree/master

      NEEDS MODIFICATION
  
  
 */

#include <Wire.h>

#define ADDR 0x25	// I2C Address


// ~~~~~~~~~~~~~~~~~~~~~~~~ read register ~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char readRegister(unsigned char addr_reg) {
    byte error;
    Wire.beginTransmission(ADDR);
    Wire.write(addr_reg); // register to read
    error = Wire.endTransmission();
   // Serial.print(millis());
//Serial.print("  end transmit: ");
    //Serial.println(error,HEX); 

    Wire.requestFrom(ADDR, 1); // read a byte

    while (Wire.available()) {
        return Wire.read();
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~ write data to register ~~~~~~~~~~~~~~~~~~~~~~~~
unsigned char writeRegister(unsigned char addr_reg, unsigned char dta) {
    Wire.beginTransmission(ADDR);
    Wire.write(addr_reg); // register to read
    Wire.write(dta);
    Wire.endTransmission();
}

void setup() {
 byte data;

   //I2c.begin();
  
  Wire.begin();
  Serial.begin(115200);

  delay(500);

  // the operating mode (MODE)
  data = readRegister(0x05);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

//~~~~~~~~~~~~~~~~~~~~~~~~ Mode Selection: (0x05) ~~~~~~~~~~~~~~~~~~~~~~~~

/*
    MODE<3:0>: Touch Decoding mode bits
Binary 	     = Mode			=	Normal Number	=	Hex
	0000 = Standby				0			0x00
	0001 = Gesture				1			0x01
	0010 = Touch only			2			0x02
	0011 = Full (touch and gesture)		3			0x03

    Convert last bit below, to binary above
*/

  // Set mode to Touch only
  //writeRegister(0x05, 0x02);

  // Set mode to Gesture only
  //writeRegister(0x05, 0x01);

  // Set mode to Full Gesture + Touch (Default Mode)
  //writeRegister(0x05, 0x03);

//~~~~~~~~~~~~~~~~~~~~~~~~ Read Mode: (0x05) ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x05);
  Serial.print("MODE: ");
  Serial.println(data,BIN);

//~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x20 NUMBEROFXCHANNELS ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x20);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

//~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x21 NUMBEROFYCHANNELS ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x21);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);

//~~~~~~~~~~~~~~~~~~~~~~~~ Write Registers 0x20, 0x21 ~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~ Set no. Channels X & Y to 0x07 & 0x06 (Default 0x09, 0x06) ~~~~~~~~~~~~~~~~~~~~~~~~
  writeRegister(0x20, 0x07);
  writeRegister(0x21, 0x06);

//~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x20 NUMBEROFXCHANNELS ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x20);
  Serial.print("NUMBEROFXCHANNELS: ");
  Serial.println(data);

//~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x21 NUMBEROFYCHANNELS ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x21);
  Serial.print("NUMBEROFYCHANNELS: ");
  Serial.println(data);
}



void loop() {
  byte data;

/*
// ~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x10 TOUCHSTATE ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x10);
  Serial.print("TOUCHSTATE: ");
  Serial.println(data,BIN);

// ~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x11 Touch X ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x11);
  Serial.print("TOUCHX: ");
  Serial.println(data,BIN);

// ~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x21  Touch Y ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x12);
  Serial.print("TOUCHY: ");
  Serial.println(data,BIN);

// ~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x13 TOUCHLSB ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x13);
  Serial.print("TOUCHLSB: ");
  Serial.println(data,BIN);
*/

// ~~~~~~~~~~~~~~~~~~~~~~~~ Read Register 0x14 GESTURESTATE ~~~~~~~~~~~~~~~~~~~~~~~~
  data = readRegister(0x14);
  Serial.print("GESTURESTATE: ");
  Serial.println(data);

/* ~~~~~~~~~~~~~~~~~~~~~~~~ 0x14 GESTURESTATE ~~~~~~~~~~~~~~~~~~~~~~~~

     GESTURESTATE<7:0>:
	0x00 No Gesture Present
	0x10 Single Click
	0x11 Click and Hold
	0x20 Double Click
	0x31 Down Swipe
	0x32 Down Swipe and Hold
	0x41 Right Swipe
	0x42 Right Swipe and Hold
	0x51 Up Swipe
	0x52 Up Swipe and Hold
	0x61 Left Swipe
	0x62 Left Swipe and Hold
	
	When a gesture is performed, the gesture ID will be placed in GESTURESTATE, and the GES bit of the
	TOUCHSTATE register will be set. Both of these items are cleared after reading the GESTURESTATE	register.
*/



// ~~~~~~~~~~~~~~~~~~~~~~~~ Read All Registers 0x80 -> 0x8E ~~~~~~~~~~~~~~~~~~~~~~~~
/*
  Serial.print("SENSORVALUE_RX <i>: ");
  for (byte i = 0x80; i < 0x8E; i++) {
     data = readRegister(i);
     
     //Serial.print(i, HEX);
    //Serial.print(" = ");
    Serial.print(data,BIN);
    Serial.print(", ");
  }
  Serial.println();
*/

/*
    data = readRegister(0x80);
    Serial.print("SENSORVALUE<RX0>: ");
    Serial.println(data,BIN);
    data = readRegister(0x8D);
    Serial.print("SENSORVALUE<RX13>: ");
    Serial.println(data,BIN);
    data = readRegister(0x86);
    Serial.print("SENSORVALUE<RX6>: ");
    Serial.println(data,BIN);
*/
    delay(500);
}
