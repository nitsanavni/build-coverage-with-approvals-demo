#include <stdio.h>

#include "./jenny.h"
#include "./src/sample.h"

#define S(array) (sizeof(array) / sizeof((array)[0]))
#define E(array) (array + S(array))

int main() {
  printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
         AnsprAufO, AnsprAufV, AnsprBand, AnsprHyst, AnsprZuO, AnsprZuV,
         AutoIbsOk, BinSteuer, Nerker1, NImpuls, NRegFkt, RegDiff, RegDiffSch,
         RegMode, SollwertRev, StellFwd, StellIstRev, WirkFall);
}
