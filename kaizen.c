#include <stdio.h>
#include <unistd.h>

int main() {
  int timePerCycle = 25;
  int cycle;
  printf("Enter the number of cycle you want to focus : ");
  scanf("%d", &cycle);
  printf("Enjoy your time ;)\n");
  for (int i = 1; i <= cycle; i++) {
    int breakTime = 5;
    if(i % 3 == 0) {
      breakTime *= 3;
    }
    printf("Focus time ^_^ ...\n");
    for(int j = 0 ; j < timePerCycle / 5 ; j++) {
      sleep(5 * 60);
      int timespend = (j + 1) * 5;
      if(timespend >= timePerCycle) break;
      printf("Time left : %d mins\n" , (timePerCycle - timespend));
    }
    printf("break time <0-0> ...\n");
    sleep(breakTime * 60);
  }
  return 0;
}
