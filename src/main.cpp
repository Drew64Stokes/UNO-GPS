#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include "PinMap_UNO.h"

#define S_BAUD 9600     // adjust as required
#define GPS_BAUD 9600   // adjust as required     
 
SoftwareSerial ss(gpsRX, gpsTX);

TinyGPSPlus myGPS;

void displayInfo() // Display GPS information
{   
    if (myGPS.location.isValid())
        {
            // local = Longitude divided by 15. 
            // This number can be added to myGPS.time.hour to adjust to local time as below
            // from https://dhirajpatra.medium.com/how-to-calculate-local-time-from-latitude-and-longitude-d990f30fdd52#:~:text=*%20Divide%20the%20longitude%20by%2015,%2D12%20%3C%20offset%20%3C%2012.
            long local = myGPS.location.lng()/15; 
            
            // Display GPS date information
            Serial.print("Date: ");
            Serial.print(myGPS.date.month());
            Serial.print("/");
            Serial.print(myGPS.date.day());
            Serial.print("/");
            Serial.print(myGPS.date.year());
    
            // Display GPS time information
            Serial.print("  | Time: ");
         // Serial.print(myGPS.time.hour());        // DREW original
            Serial.print(myGPS.time.hour()+local);  // adjusted
            Serial.print(":");
            Serial.print(myGPS.time.minute());
            Serial.print(":");
            Serial.print(myGPS.time.second());
            Serial.print(".");
            Serial.print(myGPS.time.centisecond());
            
            // Display GPS location information
            Serial.print("  | Location: ");
            Serial.print(myGPS.location.lat(), 3); //, 6);
            Serial.print(", ");
            Serial.print(myGPS.location.lng(), 3); //, 6);
            Serial.print(", ");
            Serial.println(myGPS.altitude.meters(), 3); 
                   
        }
}

void setup()
    {   
        Serial.begin(S_BAUD);
        ss.begin(GPS_BAUD);
    }

void loop()
    {   
        while (ss.available() > 0)
        {
            char gpsData = ss.read();
    
            // Send the read byte of data to the encode() function
            if (myGPS.encode(gpsData))
            {
                // If parse successful, encode() function returns true, call displayInfo() function to display GPS information
                displayInfo();
                delay(1000); //FIXME this does not really need to be here. Comment, delete or leave as needed.
            }
        }
    }


//BUG Example
//FIXME Example
//TODO Example
//IDEA Example
//TEST Example
//TESTED Example
//DREW Example
//FUTURE Example