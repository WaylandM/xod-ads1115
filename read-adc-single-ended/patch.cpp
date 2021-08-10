node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_ADS1115` class instance
        auto sensor = getValue<input_DEV>(ctx);
        uint8_t chl = getValue<input_CHL>(ctx);
        emitValue<output_Value>(ctx, sensor->readADC_SingleEnded(chl));
        emitValue<output_Done>(ctx, 1);
    }
}
