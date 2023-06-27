#include <stdio.h>

#include "./jenny.h"
#include "./src/sample.h"

#define S(array) (sizeof(array) / sizeof((array)[0]))
#define E(array) (array + S(array))

void set_globals(int _AnsprAufO, int _AnsprAufV, int _AnsprBand, int _AnsprHyst,
                 int _AnsprZuO, int _AnsprZuV, unsigned int _AutoIbsOk,
                 unsigned int _BinSteuer, int _Nerker1, unsigned int _NImpuls,
                 unsigned int _NRegFkt, int _RegDiff, int _RegDiffSch,
                 unsigned int _RegMode, int _SollwertRev, int _StellFwd,
                 int _StellIstRev, int _WirkFall) {
  AnsprAufO = _AnsprAufO;
  AnsprAufV = _AnsprAufV;
  AnsprBand = _AnsprBand;
  AnsprHyst = _AnsprHyst;
  AnsprZuO = _AnsprZuO;
  AnsprZuV = _AnsprZuV;
  AutoIbsOk = _AutoIbsOk;
  BinSteuer = _BinSteuer;
  Nerker1 = _Nerker1;
  NImpuls = _NImpuls;
  NRegFkt = _NRegFkt;
  RegDiff = _RegDiff;
  RegDiffSch = _RegDiffSch;
  RegMode = _RegMode;
  SollwertRev = _SollwertRev;
  StellFwd = _StellFwd;
  StellIstRev = _StellIstRev;
  WirkFall = _WirkFall;
}

void reset_globals() {
  set_globals(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void print_em_globals() {
  printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", AnsprAufO,
         AnsprAufV, AnsprBand, AnsprHyst, AnsprZuO, AnsprZuV, AutoIbsOk,
         BinSteuer, Nerker1, NImpuls, NRegFkt, RegDiff, RegDiffSch, RegMode,
         SollwertRev, StellFwd, StellIstRev, WirkFall);
}

void feature_NImpuls_TOTZONE() { NImpuls = TOTZONE; }

void feature_AutoIbsOk_C_IBS_OK_and_stuff() {
  AutoIbsOk = C_IBS_OK;
  RegMode = N_AUTOMATIK;
  BinSteuer = BO_REGLER;
}

void reset_internals() { set_internals(0, 0, 0, 0); }

void feature_Zustang_0_STATE_WITHIN_DEADZONE() {
  set_internals(0, 0, STATE_WITHIN_DEADZONE, 0);
}

void feature_Zwsp_Band() {
  feature_Zustang_0_STATE_WITHIN_DEADZONE();
  AnsprZuO = 1;
  SollwertRev = 2;
}

void feature_RegDiff_lt_AnsprZuO() { AnsprZuO = 1; };

void null_feature(){};

void feature_STROM_GRENZ() {
  Nerker1 = STROM_GRENZ;
}

void run_feature(void (*feature_func)()) {
  reset_globals();
  reset_internals();
  feature_func();

  print_privates();
  print_em_globals();
  theFunctionToTest();
  print_privates();
  print_em_globals();
}

int main() {
  // array of function pointers
  void (*features[])() = {
      null_feature,
      feature_AutoIbsOk_C_IBS_OK_and_stuff,
      feature_NImpuls_TOTZONE,
      feature_Zustang_0_STATE_WITHIN_DEADZONE,
      feature_Zwsp_Band,
      feature_STROM_GRENZ,
  };

  for (size_t i = 0; i < S(features); ++i) {
    run_feature(features[i]);
  }

  return 0;
}
