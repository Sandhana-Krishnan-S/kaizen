#ifndef TIMER_H
#define TIMER_H

// Timer config
typedef struct {
    int focus_minutes;   // default: 25
    int short_break;     // default: 5
    int long_break;      // default: 15
    int cycles_before_long; // default: 3
    int max_cycle; //default: 2 
} TimerConfig;

// Timer state
typedef struct {
    int cycle;       // current cycle number
    int remaining;   // seconds left
    int is_focus;    // 1 = focus, 0 = break
} TimerState;

void timer_init(TimerConfig *config, TimerState *state);
int timer_tick(TimerConfig *config, TimerState *state);

#endif
