#include <gtest/gtest.h>
#include <PWInventory.h>

// TIP: Keep the tests simple, aim for good coverage 
// TEST(PWInventory, FooBad) {
// 	PWInventory inventory{ { InventoryItem{ "Foo", 0 , 0 } } };
// 	EXPECT_EQ(inventory[0].name, "Bar");
// }
#include "gtest/gtest.h"
#include "PWInventory.h"

TEST(PWInventoryTest, SaveAndLoadTest) {
    PWInventory inventory;
    inventory.items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});
    inventory.items.push_back(InventoryItem{"White Monstera", 4, 80});
    inventory.items.push_back(InventoryItem{"Gardening Workshop", 10, 10});
    inventory.items.push_back(InventoryItem{"Somename", 8, 0});

    inventory.Save("test.json");

    PWInventory loadedInventory;
    loadedInventory.Load("test.json");

    ASSERT_EQ(inventory.Count(), loadedInventory.Count());

    for (int i = 0; i < inventory.Count(); i++) {
        EXPECT_EQ(inventory[i].name, loadedInventory[i].name);
        EXPECT_EQ(inventory[i].sellBy, loadedInventory[i].sellBy);
        EXPECT_EQ(inventory[i].value, loadedInventory[i].value);
    }
}

TEST(PWInventoryTest, UpdateQualityTest) {
    PWInventory inventory;
    inventory.items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});
    inventory.items.push_back(InventoryItem{"White Monstera", 4, 80});
    inventory.items.push_back(InventoryItem{"Gardening Workshop", 10, 10});
    inventory.items.push_back(InventoryItem{"Somename", 8, 0});

    inventory.UpdateQuality();

    EXPECT_EQ(inventory[0].name, "Polka Dot Begonia");
    EXPECT_EQ(inventory[0].sellBy, 3);
    EXPECT_EQ(inventory[0].value, 31);

    EXPECT_EQ(inventory[1].name, "White Monstera");
    EXPECT_EQ(inventory[1].sellBy, 4);
    EXPECT_EQ(inventory[1].value, 80);

    EXPECT_EQ(inventory[2].name, "Gardening Workshop");
    EXPECT_EQ(inventory[2].sellBy, 9);
    EXPECT_EQ(inventory[2].value, 12);

    EXPECT_EQ(inventory[3].name, "Somename");
    EXPECT_EQ(inventory[3].sellBy, 7);
    EXPECT_EQ(inventory[3].value, 0);
}

TEST(PWInventoryTest, OutOfRangeTest) {
    PWInventory inventory;
    inventory.items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});

    EXPECT_THROW(inventory[1], PWException);
}