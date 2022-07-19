#ifndef PICO_BP_EXAMPLE_BLINK_
#define PICO_BP_EXAMPLE_BLINK_

#ifdef BP_WIFI
#include "pico/cyw43_arch.h"
#endif
#include "pico/stdlib.h"
#include "pico/printf.h"
#include "version.hpp"

namespace examples {
[[noreturn]] static void blink(bool use_uart = false) {
#ifndef BP_WIFI
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
#endif

  while (true) {
#ifdef BP_WIFI
      cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
      sleep_ms(250);
      cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
      sleep_ms(250);

#endif
#ifndef BP_WIFI
      gpio_put(LED_PIN, 1);
      sleep_ms(250);
      gpio_put(LED_PIN, 0);
      sleep_ms(250);
#endif
    if (use_uart) {
      printf("%s Hello World!\n", PROJECT_NAME);
    }
  }
}
}// namespace examples

#endif//PICO_BP_EXAMPLE_BLINK_
