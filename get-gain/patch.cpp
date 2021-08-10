
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_ADS1115` class instance
        auto sensor = getValue<input_DEV>(ctx);
        adsGain_t gain = sensor->getGain();

        if (gain==GAIN_TWOTHIRDS) {
            emitValue<output_Gain>(ctx, 0.67);
        }
        else if (gain==GAIN_ONE) {
            emitValue<output_Gain>(ctx, 1);
        }
        else if (gain==GAIN_TWO) {
            emitValue<output_Gain>(ctx, 2);
        }
        else if (gain=GAIN_FOUR) {
            emitValue<output_Gain>(ctx, 4);
        }
        else if (gain=GAIN_EIGHT) {
            emitValue<output_Gain>(ctx, 8);
        }
        else if (gain==GAIN_SIXTEEN) {
            emitValue<output_Gain>(ctx, 16);
        }
        emitValue<output_Done>(ctx, 1);
    }
}
