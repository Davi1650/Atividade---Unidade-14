#include <string.h>
#include "GildedRose.h"
#include <stdio.h>

Item*
init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);

    return item;
}

extern char* print_item(char* buffer, Item* item)
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}


void update_normal_item(Item* item) {
    if (item->quality > 0) {
        item->quality--;
    }
    if (item->sellIn < 0) {
        if (item->quality > 0) {
            item->quality--;
        }
    }
}

void update_aged_brie(Item* item) {
    if (item->quality < 50) {
        item->quality++;
    }
    if (item->sellIn < 0) {
        if (item->quality < 50) {
            item->quality++;
        }
    }
}

void update_backstage_passes(Item* item) {
    if (item->sellIn > 10) {
        if (item->quality < 50) {
            item->quality++;
        }
    } else if (item->sellIn > 5) {
        if (item->quality < 49) {
            item->quality += 2;
        }
    } else if (item->sellIn > 0) {
        if (item->quality < 48) {
            item->quality += 3;
        }
    } else {
        item->quality = 0;
    }
}


void update_sulfuras(Item* item) {

}


void update_conjured_item(Item* item) {
    if (item->quality > 0) {
        item->quality -= 2;
    }
    if (item->sellIn < 0) {
        if (item->quality > 0) {
            item->quality -= 2;
        }
    }
}



void update_quality(Item items[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(items[i].name, "Aged Brie") == 0) {
            update_aged_brie(&items[i]);
        } else if (strstr(items[i].name, "Backstage passes") != NULL) {
            update_backstage_passes(&items[i]);
        } else if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros") == 0) {
            update_sulfuras(&items[i]);
        } else if (strstr(items[i].name, "Conjured") != NULL) {
            update_conjured_item(&items[i]);
        }else {
            update_normal_item(&items[i]);
        }

        if (strcmp(items[i].name, "Sulfuras, Hand of Ragnaros") != 0) {
            items[i].sellIn--;
        }
    }
}


