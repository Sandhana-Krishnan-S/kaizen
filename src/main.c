#include <stdio.h>
#include "timer.h"

int main() {
  TimerConfig config;
  config.cycles_before_long = 3;
  config.short_break = 5;
  config.long_break = 15;
  config.focus_minutes = 25;

  printf("Enter the number of cycle : ");
  scanf("%d" , &config.max_cycle);

  TimerState state;
  timer_init(&config, &state);
  while (timer_tick(&config, &state)) {
    if(state.is_focus) {
      printf("Focus : %d\n" , state.remaining);
    } else {
      printf("Break\n");
    }
  }
  return 0;
}
