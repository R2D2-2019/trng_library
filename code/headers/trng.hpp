#pragma once

#include <hwlib.hpp>

namespace r2d2 {
    /**
     * @brief 
     * A hardware true random number generator implementation for the sam3x8e
     * The hardware generates a new random number every 84 clock ticks.
     * 
     * All credits go to llib (https://github.com/mijgame/llib)
     * 
     */
    class trng_c {
    protected:
        constexpr static uint32_t trng_key = 0x524e47;

    public:
        constexpr static uint32_t instance_id = ID_TRNG;
        constexpr static uint32_t irqn = static_cast<uint32_t>(TRNG_IRQn);

        /**
         * @brief This init's the trng on the due
         * 
         */
        static void init() {
            // Enable clock
            PMC->PMC_PCER1 = 1U << (instance_id - 32);

            // Enable trng
            TRNG->TRNG_CR =
                TRNG_CR_KEY(trng_key) | (uint32_t(0x01) & TRNG_CR_ENABLE);
        }

        /**
         * @brief This enable's the interrupts for the trng
         * this doesnt setup the nvic controller
         * 
         */
        static void enable_interrupt() {
            TRNG->TRNG_IER = TRNG_IER_DATRDY;
        }

        /**
         * @brief This disables the interrupts for the trng
         * this doesnt change the nvic controller
         * 
         */
        static void disable_interrupt() {
            TRNG->TRNG_IDR = TRNG_IDR_DATRDY;
        }

        /**
         * @brief Returns if there is a new random number available.
         * 
         * @return true 
         * @return false 
         */
        static bool value_available() {
            // return if new data is in the TRNG_IMR register
            // this register is cleared after a read
            return TRNG->TRNG_ISR & TRNG_ISR_DATRDY;
        }

        /**
         * @brief Returns the random number
         * 
         * @return uint32_t 
         */
        static uint32_t get() {
            // return the 32bit random number
            return TRNG->TRNG_ODATA;
        }
    };
} // namespace r2d2