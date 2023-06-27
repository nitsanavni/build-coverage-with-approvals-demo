#include <stdio.h>

#include "./jenny.h"
#include "./src/sample.h"

#define S(array) (sizeof(array) / sizeof((array)[0]))
#define E(array) (array + S(array))

void print_em_globals() {
  printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", AnsprAufO,
         AnsprAufV, AnsprBand, AnsprHyst, AnsprZuO, AnsprZuV, AutoIbsOk,
         BinSteuer, Nerker1, NImpuls, NRegFkt, RegDiff, RegDiffSch, RegMode,
         SollwertRev, StellFwd, StellIstRev, WirkFall);
}

int main() {
  // before
  print_em_globals();
  // do we want to print the private variables too?

  theFunctionToTest();

  // after
  print_em_globals();
}
