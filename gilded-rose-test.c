#include <stdio.h>

#include "./jenny.h"
#include "./src/gilded-rose.h"

#define S(array) (sizeof(array) / sizeof((array)[0]))
#define E(array) (array + S(array))

int main() {
  Item item;

  const char *names[] = {"name", "Aged Brie",
                         "Backstage passes to a TAFKAL80ETC concert",
                         "Sulfuras, Hand of Ragnaros"};
  int sellIns[] = {0, -1, 12, 1, 11, 6};
  int qualities[] = {0, 1, 2, 49, 50, 51};

  //   for (const char **name = names; name < E(names); name++) {
  //     for (int *sellIn = sellIns; sellIn < E(sellIns); sellIn++) {
  //       for (int *quality = qualities; quality < E(qualities); quality++) {
  //         init_item(&item, *name, *sellIn, *quality);

  //         printf("%s %d %d -> ", item.name, item.sellIn, item.quality);

  //         update_quality(&item, 1);

  //         printf("%d %d\n", item.sellIn, item.quality);
  //       }
  //     }
  //   }

  for (const int(*j)[3] = jenny; j < E(jenny); j++) {
    Item item;
    init_item(&item, names[(*j)[0]], sellIns[(*j)[1]], qualities[(*j)[2]]);

    printf("%s %d %d -> ", item.name, item.sellIn, item.quality);
    update_quality(&item, 1);
    printf("%d %d\n", item.sellIn, item.quality);
  }
}
