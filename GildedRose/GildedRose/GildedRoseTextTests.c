#include <stdio.h>
#include "GildedRose.h"

int print_item_test(Item *item)
{
    return printf("%s, %d, %d\n", item->name, item->sellIn, item->quality);
}

int main()
{
    Item items[10];
    int last = 0;
    int day;
    int index;

    init_item(items + last++, "+5 Dexterity Vest", 10, 20);
    init_item(items + last++, "Aged Brie", 2, 0);
    init_item(items + last++, "Elixir of the Mongoose", 5, 70);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", 0, 80);
    init_item(items + last++, "Sulfuras, Hand of Ragnaros", -1, 80);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 15, 20);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 10, 49);
    init_item(items + last++, "Backstage passes to a TAFKAL80ETC concert", 5, 49);
    init_item(items + last++, "Conjured Mana Cake", 3, 6);
    init_item(items + last++, "Conjured Mana Gems", 10, 40);

    puts("OMGHAI!");

    for (day = 0; day <= 30; day++)
    {
        printf("-------- day %d --------\n", day);
        printf("name, sellIn, quality\n");
        for(index = 0; index < last; index++) {
            print_item_test(items + index);
        }

        printf("\n");

        update_quality(items, last);
    }




    //Unit tests
    test_update_normal_item();
    test_update_aged_brie();
    test_update_backstage_passes();
    test_update_sulfuras();
    test_update_conjured_item();


    return 0;
}
