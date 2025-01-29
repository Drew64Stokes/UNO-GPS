#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include "PinMap_UNO.h"

#define GPS_BAUD 9600
 
SoftwareSerial ss(gpsRX, gpsTX);

TinyGPSPlus gps;

void displayInfo() // Display GPS information
{   
    if (gps.location.isValid())
        {
            // local = Longitude divided by 15. 
            // This number can be added to gps.time.hour to adjust to local time as below
            // https://dhirajpatra.medium.com/how-to-calculate-local-time-from-latitude-and-longitude-d990f30fdd52#:~:text=*%20Divide%20the%20longitude%20by%2015,%2D12%20%3C%20offset%20%3C%2012.
            long local = gps.location.lng()/15; 
            
            // Display GPS date information
            Serial.print("Date: ");
            Serial.print(gps.date.month());
            Serial.print("/");
            Serial.print(gps.date.day());
            Serial.print("/");
            Serial.print(gps.date.year());
    
            // Display GPS time information
            Serial.print("  | Time: ");
            Serial.print(gps.time.hour()+local); //Serial.print(gps.time.hour()); adjusted
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
                delay(1000); //FIXME this does not really need to be here. Comment or delete.
            }
        }
    }
