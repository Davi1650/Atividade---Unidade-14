    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "GildedRose.h"

    void test_init_item() {
        Item item;
        init_item(&item, "Test Item", 10, 20);

        if (strcmp(item.name, "Test Item") != 0) {
            printf("ERROR! function: test_init_item, expected name: 'Test Item', Actual result: '%s'\n", item.name);
        } else if (item.sellIn != 10) {
            printf("ERROR! function: test_init_item, expected sellIn: 10, Actual result: %d\n", item.sellIn);
        } else if (item.quality != 20) {
            printf("ERROR! function: test_init_item, expected quality: 20, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_init_item is working\n");
        }

        free(item.name);
    }




    void test_print_item() {
        Item item;
        char buffer[50];

        init_item(&item, "Test Item", 10, 20);
        print_item(buffer, &item);

        if (strcmp(buffer, "Test Item, 10, 20") != 0) {
            printf("ERROR! function: test_print_item, expected: 'Test Item, 10, 20', Actual result: '%s'\n", buffer);
        } else {
            printf("SUCCESS! function: test_print_item is working\n");
        }

        free(item.name);
    }




    void test_update_normal_item() {
        Item item;
        init_item(&item, "Normal Item", 10, 20);

        update_quality(&item, 1);

        if (item.quality != 19) {
            printf("ERROR! function: test_update_normal_item failed, expected quality: 19, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_normal_item is working\n");
        }

        // Negative sellIn
        item.sellIn = -1;
        update_quality(&item, 1);

        if (item.quality != 17) {
            printf("ERROR! function: test_update_normal_item failed after sellIn negative, expected quality: 17, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_normal_item is working after sellIn negative\n");
        }

        free(item.name);
    }



    void test_update_aged_brie() {
        Item item;
        init_item(&item, "Aged Brie", 10, 20);

        update_quality(&item, 1);

        if (item.quality != 21) {
            printf("ERROR! function: test_update_aged_brie failed, expected quality: 21, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_aged_brie is working\n");
        }

        // Negative sellIn
        item.sellIn = -1;
        update_quality(&item, 1);

        if (item.quality != 23) {
            printf("ERROR! function: test_update_aged_brie failed after sellIn negative, expected quality: 23, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_aged_brie is working after sellIn negative\n");
        }

        free(item.name);
    }



    void test_update_backstage_passes() {
        Item item;

        init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 10, 20);
        update_quality(&item, 1);
        if (item.quality != 22) {
            printf("ERROR! function: test_update_backstage_passes failed for sellIn = 10, expected quality: 22, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_backstage_passes is working for sellIn = 10\n");
        }

        init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 5, 20);
        update_quality(&item, 1);
        if (item.quality != 23) {
            printf("ERROR! function: test_update_backstage_passes failed for sellIn = 5, expected quality: 22, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_backstage_passes is working for sellIn = 5\n");
        }

        init_item(&item, "Backstage passes to a TAFKAL80ETC concert", 0, 20);
        update_quality(&item, 1);
        if (item.quality != 0) {
            printf("ERROR! function: test_update_backstage_passes failed for sellIn = 0, expected quality: 0, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_backstage_passes is working for sellIn = 0\n");
        }

        // Negative sellIn
        item.sellIn = -1;
        item.quality = 20;
        update_quality(&item, 1);
        if (item.quality != 0) {
            printf("ERROR! function: test_update_backstage_passes failed for sellIn negative, expected quality: 0, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_backstage_passes is working for sellIn negative\n");
        }

        free(item.name);
    }



    void test_update_sulfuras() {
        Item item;
        init_item(&item, "Sulfuras, Hand of Ragnaros", 0, 20);

        update_quality(&item, 1);

        if (item.quality != 20) {
            printf("ERROR! function: test_update_sulfuras failed, expected quality: 20, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_sulfuras is working\n");
        }

        // Negative sellIn
        item.sellIn = -1;
        update_quality(&item, 1);

        if (item.quality != 20) {
            printf("ERROR! function: test_update_sulfuras failed after sellIn negative, expected quality: 20, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_sulfuras is working after sellIn negative\n");
        }

        free(item.name);
    }



    void test_update_conjured_item() {
        Item item;
        init_item(&item, "Conjured Mana Cake", 10, 40);

        update_quality(&item, 1);

        if (item.quality != 38) {
            printf("ERROR! function: test_update_conjured_item failed, expected quality: 38, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_conjured_item is working\n");
        }

        // Negative sellIn
        item.sellIn = -1;
        update_quality(&item, 1);

        if (item.quality != 34) {
            printf("ERROR! function: test_update_conjured_item failed after sellIn negative, expected quality: 34, Actual result: %d\n", item.quality);
        } else {
            printf("SUCCESS! function: test_update_conjured_item is working after sellIn negative\n");
        }

        free(item.name);
    }


