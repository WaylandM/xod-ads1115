
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_ADS1115` class instance
        auto sensor = getValue<input_DEV>(ctx);
        uint16_t dr = sensor->getDataRate();

        if (dr==RATE_ADS1115_8SPS) {
            emitValue<output_Rate>(ctx, 8);
        }
        else if (dr==RATE_ADS1115_16SPS) {
            emitValue<output_Rate>(ctx, 16);
        }
        else if (dr==RATE_ADS1115_32SPS) {
            emitValue<output_Rate>(ctx, 32);
        }
        else if (dr==RATE_ADS1115_64SPS) {
            emitValue<output_Rate>(ctx, 64);
        }
        else if (dr==RATE_ADS1115_128SPS) {
            emitValue<output_Rate>(ctx, 128);
        }
        else if (dr==RATE_ADS1115_250SPS) {
            emitValue<output_Rate>(ctx, 250);
        }
        else if (dr==RATE_ADS1115_475SPS) {
            emitValue<output_Rate>(ctx, 475);
        }
        else if (dr==RATE_ADS1115_860SPS) {
            emitValue<output_Rate>(ctx, 860);
        }
        emitValue<output_Done>(ctx, 1);
    }
}
