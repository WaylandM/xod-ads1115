
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_ADS1115` class instance
        auto sensor = getValue<input_DEV>(ctx);
        auto dr = getValue<input_Rate>(ctx);

        if (dr==8) {
            sensor->setDataRate(RATE_ADS1115_8SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==16) {
            sensor->setDataRate(RATE_ADS1115_16SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==32) {
            sensor->setDataRate(RATE_ADS1115_32SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==64) {
            sensor->setDataRate(RATE_ADS1115_64SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==128) {
            sensor->setDataRate(RATE_ADS1115_128SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==250) {
            sensor->setDataRate(RATE_ADS1115_250SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==475) {
            sensor->setDataRate(RATE_ADS1115_475SPS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (dr==860) {
            sensor->setDataRate(RATE_ADS1115_860SPS);
            emitValue<output_Done>(ctx, 1);
        }
    }
}
