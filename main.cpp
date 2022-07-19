#include "examples/blink.hpp"
#include "pico/stdlib.h"

int main() {
  stdio_init_all();
#ifdef WIFI
  if (cyw43_arch_init()) {
    printf("WiFi init failed");
    return -1;
  }
#endif

  examples::blink(true);
}