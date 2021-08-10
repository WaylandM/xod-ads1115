
// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/adafruit/Adafruit_ADS1X15"

//Include C++ libraries
#include <Adafruit_ADS1X15.h>
#include <Wire.h>

node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_ADS1115*;
    }

    // Create an object of class Adafruit_ADS1115
    Adafruit_ADS1115 sensor = Adafruit_ADS1115();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto wire = getValue<input_I2C>(ctx);
        auto addr = getValue<input_ADDR>(ctx);
        
        // Try to initialize sensor
        if (!sensor.begin(addr, wire)) {
            raiseError(ctx);
            return;
        }
        emitValue<output_DEV>(ctx, &sensor);
    }
}
