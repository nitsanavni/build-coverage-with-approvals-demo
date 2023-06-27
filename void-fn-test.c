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

void feature_STROM_GRENZ() { Nerker1 = STROM_GRENZ; }

void feature_minus_37() {
  feature_STROM_GRENZ();
  WirkFall = 1;
}

void feature_limit_AnsprAufV() { AnsprAufV = 1; }
void feature_TY_GRENZ_1() { NImpuls = TY_GRENZ_1; }
void feature_TY_GRENZ_2() { NImpuls = TY_GRENZ_2; }
void feature_limit_PraeAufWirk() {
  AnsprAufV = 1;
  AnsprAufO = 1;
}
void feature_AUF_V() { RegDiff = 1; }
void feature_ZU_V() { RegDiff = -1; }
void feature_AUF_V_2() {
  feature_TY_GRENZ_1();
  RegDiff = 1;
  RegDiffSch = 1;
}
void feature_AUF_O_seems_to_be_unreachable() {
  feature_AUF_V_2();
  feature_STROM_GRENZ();
  feature_Zwsp_Band();
  AnsprBand = 2;
  RegDiff = 40;
  RegDiffSch = 40;
  AnsprAufV = 41;
}
void feature_StellIstRev() { StellIstRev = 1; }
void feature_StellIstRev_2() { StellIstRev = -1; }

static void (*features[])() = {
    null_feature,
    feature_AutoIbsOk_C_IBS_OK_and_stuff,
    feature_NImpuls_TOTZONE,
    feature_Zustang_0_STATE_WITHIN_DEADZONE,
    feature_Zwsp_Band,
    feature_STROM_GRENZ,
    feature_minus_37,
    feature_limit_AnsprAufV,
    feature_TY_GRENZ_1,
    feature_TY_GRENZ_2,
    feature_limit_PraeAufWirk,
    feature_ZU_V,
    feature_AUF_V,
    feature_AUF_V_2,
    feature_AUF_O_seems_to_be_unreachable,
    feature_StellIstRev,
    feature_StellIstRev_2,
};

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
  for (size_t i = 0; i < S(features); ++i) {
    run_feature(features[i]);
  }
}
