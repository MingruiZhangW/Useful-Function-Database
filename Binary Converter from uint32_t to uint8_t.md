Here is the standard way to do it - nice and concise:

        void inttolitend(uint32_t x, uint8_t *lit_int) {
            lit_int[0] = (uint8_t)(x >>  0);
            lit_int[1] = (uint8_t)(x >>  8);
            lit_int[2] = (uint8_t)(x >> 16);
            lit_int[3] = (uint8_t)(x >> 24);
        }
Or using arithmetic similar to your question:

        void inttolitend(uint32_t x, uint8_t *lit_int) {
            lit_int[0] = (uint8_t)(x % 256);
            lit_int[1] = (uint8_t)(x / 256 % 256);
            lit_int[2] = (uint8_t)(x / 256 / 256 % 256);
            lit_int[3] = (uint8_t)(x / 256 / 256 / 256 % 256);
        }
Addendum:

The reverse conversion - idiomatic:

        uint32_t litendtoint(uint8_t *lit_int) {
            return (uint32_t)lit_int[0] <<  0
                 | (uint32_t)lit_int[1] <<  8
                 | (uint32_t)lit_int[2] << 16
                 | (uint32_t)lit_int[3] << 24;
        }
Or using arithmetic similar to your question:

        uint32_t litendtoint(uint8_t *lit_int) {
            return (uint32_t)lit_int[0]
                 + (uint32_t)lit_int[1] * 256
                 + (uint32_t)lit_int[2] * 256 * 256
                 + (uint32_t)lit_int[3] * 256 * 256 * 256;
        }
