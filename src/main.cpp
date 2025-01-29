#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include "PinMap_UNO.h";

#define GPS_BAUD 9600
 
SoftwareSerial ss(gpsRX, gpsTX);

TinyGPSPlus gps;

void displayInfo() // Display GPS information
{   
    if (gps.location.isValid())
        {
            long x = gps.location.lng()/15; //calculate the UTM adjustment for time below.
            //Serial.println(x);
            
            // Display GPS date information
            Serial.print("Date: ");
            Serial.print(gps.date.month());
            Serial.print("/");
            Serial.print(gps.date.day());
            Serial.print("/");
            Serial.print(gps.date.year());
    
            // Display GPS time information
            Serial.print("  | Time: ");
            Serial.print(gps.time.hour()+x); //Serial.print(gps.time.hour()); adjusted
            Serial.print(":");
            Serial.print(gps.time.minute());
            Serial.print(":");
            Serial.print(gps.time.second());
            Serial.print(".");
            Serial.print(gps.time.centisecond());
            
            // Display GPS location information
            Serial.print("  | Location: ");
            Serial.print(gps.location.lat(), 3); //, 6);
            Serial.print(", ");
            Serial.print(gps.location.lng(), 3); //, 6);
            Serial.print(", ");
            Serial.println(gps.altitude.meters(), 3); 
                   
        }
}

void setup()
    {   
        Serial.begin(9600);
        ss.begin(GPS_BAUD);
    }

void loop()
    {   
        while (ss.available() > 0)
        {
            char gpsData = ss.read();
    
            // Send the read byte of data to the encode() function
            if (gps.encode(gpsData))
            {
                // If parse successful, encode() function returns true, call displayInfo() function to display GPS information
                displayInfo();
                delay(1000);
            }
        }
    }
