#ifndef PICO_BP_EXAMPLE_BLINK_
#define PICO_BP_EXAMPLE_BLINK_

#include "pico/cyw43_arch.h"
#include "version.hpp"

namespace examples {
[[noreturn]] static void blink(bool use_uart = false) {
  while (true) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    sleep_ms(250);
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
    sleep_ms(250);
    if (use_uart) {
      printf("%s Hello World!\n", PROJECT_NAME);
    }
  }
}
}// namespace examples

#endif//PICO_BP_EXAMPLE_BLINK_
