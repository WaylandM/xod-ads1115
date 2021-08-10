
node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_ADS1115` class instance
        auto sensor = getValue<input_DEV>(ctx);
        auto gain = getValue<input_Gain>(ctx);

        if (gain==0.67) {
            sensor->setGain(GAIN_TWOTHIRDS);
            emitValue<output_Done>(ctx, 1);
        }
        else if (gain==1) {
            sensor->setGain(GAIN_ONE);
            emitValue<output_Done>(ctx, 1);
        }
        else if (gain==2) {
            sensor->setGain(GAIN_TWO);
            emitValue<output_Done>(ctx, 1);
        }
        else if (gain==4) {
            sensor->setGain(GAIN_FOUR);
            emitValue<output_Done>(ctx, 1);
        }
        else if (gain==8) {
            sensor->setGain(GAIN_EIGHT);
            emitValue<output_Done>(ctx, 1);
        }
        else if (gain==16) {
            sensor->setGain(GAIN_SIXTEEN);
            emitValue<output_Done>(ctx, 1);
        }
    }
}
