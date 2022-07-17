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

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() {
  stdio_init_all();
  if (cyw43_arch_init()) {
    printf("WiFi init failed");
    return -1;
  }
}