#include <stdio.h>

#include "./src/gilded-rose.h"

int main() {
  Item item;
  init_item(&item, "name", 0, 0);
  printf("hello %s %d %d!\n", item.name, item.sellIn, item.quality);
}
