#include "action_layer.h"
#include <stdio.h>

#define L_BASE 0
#define L_NUM (1 << 1)
#define L_SYM (1 << 2)
#define L_NAV (1 << 3)
#define L_GAME (1 << 4)
#define L_ADJUST_TRI (L_NUM | L_SYM| L_NAV)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Base");
    break;
  case L_NUM:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Number");
    break;
  case L_SYM:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbol");
    break;
  case L_NAV:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Nav");
    break;
  case L_GAME:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}
