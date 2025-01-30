#ifndef PinMap_UNO_H
    #define PinMap_UNO_H

        // LEFT SIDE                     
        // ?
        // 5v       *** GPS 5V
        // RES
        // 3.3V
        // 5V
        // GND      *** GPS GND
        // GND
        // VIN

        // Analog pin A0 or Digital pin 14 
        // Analog pin A1 or Digital pin 15 
        // Analog pin A2 or Digital pin 16 
        // Analog pin A3 or Digital pin 17 
        const int gpsTX = 18;   // Analog pin A4 or Digital pin 18  *** GPS RX
        const int gpsRX = 19;   // Analog pin A5 or Digital pin 19  *** GPS TX

        // RIGHT SIDE
        // Digital pin 20 (SDA)
        // Digital pin 21 (SCL)
        // AREF
        // GND
        // Digital pin 13 (PWM) is also LED_BUILTIN.
        // Digital pin 12 (PWM)
        // Digital pin 11 (PWM)
        // Digital pin 10 (PWM)
        // Digital pin 09 (PWM)
        // Digital pin 08 (PWM)
        // Digital pin 07 (PWM)
        // Digital pin 06 (PWM)
        // Digital pin 05 (PWM)
        // Digital pin 04 (PWM) 
        //const int gpsTX = 3;  // Digital pin 03 (PWM) // this goes to RX on the module // Mega/UNO
        //const int gpsRX = 2;  // Digital pin 02 (PWM) // this goes to TX on the module // Mega/UNO

        //SYSTEM SERIAL       // Digital pin 01 (TX0)
        //SYSTEM SERIAL       // Digital pin 00 (RX0)


#endif