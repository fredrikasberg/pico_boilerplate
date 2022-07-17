#ifndef PICO_BP_EXAMPLE_BLINK_
#define PICO_BP_EXAMPLE_BLINK_

#include "pico/cyw43_arch.h"

namespace examples {
[[noreturn]] static void blink() {
  while (true) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(250);
  }
}
}// namespace examples

#endif//PICO_BP_EXAMPLE_BLINK_
