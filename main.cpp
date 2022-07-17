/**
 *
 *        .~~.   .~~.
 *        '. \ ' ' / .'
 *         .~ .~~~..~.
 *        : .~.'~'.~. :
 *       ~ (   ) (   ) ~
 *      ( : '~'.~.'~' : )
 *       ~ .~ (   ) ~. ~
 *        (  : '~' :  ) Raspberry Pi Pico Boilerplate
 *         '~ .~~~. ~'
 *             '~'
 */

#include "examples/blink.hpp"
#include "pico/stdlib.h"

int main() {
  stdio_init_all();
  if (cyw43_arch_init()) {
    printf("WiFi init failed");
    return -1;
  }

  examples::blink();
}