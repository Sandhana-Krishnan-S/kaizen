#include <unistd.h>
#include "timer.h"

void timer_init(TimerConfig *config, TimerState *state) {
  state->is_focus = 1;
  state->cycle = 1;
  state->remaining = config->focus_minutes * 60;
}

int timer_tick(TimerConfig *config, TimerState *state) {
  if (state->remaining > 0) {
    sleep(1);
    state->remaining -= 1;
    return 1;
  }
  if (state->is_focus) {
    if (state->cycle % config->cycles_before_long == 0) {
      state->remaining = config->long_break * 60;
    } else { 
      state->remaining = config->short_break * 60;
    }
    state->is_focus = 0;
  } else {
    state->cycle++;
    if (state->cycle > config->max_cycle) {
      return 0;
    }
    state->is_focus = 1;
    state->remaining = config->focus_minutes * 60;
  }
  return 1;
}

