#include "examples/blink.hpp"
#include "pico/stdlib.h"

int main() {
  stdio_init_all();
  if (pico_board_type() == PicoWireless) {
    if (cyw43_arch_init()) {
      printf("WiFi init failed");
      return -1;
    }
  }

  examples::blink(true);
}