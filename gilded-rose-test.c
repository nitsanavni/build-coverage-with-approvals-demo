#include <stdio.h>

#include "./src/gilded-rose.h"

int main() {
  Item item;

  init_item(&item, "name", 0, 0);

  printf("%s %d %d -> ", item.name, item.sellIn, item.quality);

  update_quality(&item, 1);

  printf("%d %d\n", item.sellIn, item.quality);
}
