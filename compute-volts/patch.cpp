node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        // Get a pointer to the `Adafruit_ADS1115` class instance
        auto sensor = getValue<input_DEV>(ctx);
        int16_t raw = getValue<input_ADC>(ctx);

        emitValue<output_Value>(ctx, sensor->computeVolts(raw);
        emitValue<output_Done>(ctx, 1);

    }
}
