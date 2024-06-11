#include <gtest/gtest.h>
#include <PWInventory.h>
#include <PWServer.h>



TEST(PWInventoryTest, SaveAndLoadTest) {
    std::vector<InventoryItem> items;
    items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});
    items.push_back(InventoryItem{"White Monstera", 4, 80});
    items.push_back(InventoryItem{"Gardening Workshop", 10, 10});
    items.push_back(InventoryItem{"Somename", 8, 0});
	PWInventory inventory;
	inventory.Load(items);
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
	std::vector<InventoryItem> items;

    items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});
    items.push_back(InventoryItem{"White Monstera", 4, 80});
    items.push_back(InventoryItem{"Gardening Workshop", 10, 10});
    items.push_back(InventoryItem{"Somename", 8, 0});
	inventory.Load(items);

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
	std::vector<InventoryItem> items;

    items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});
	inventory.Load(items);

    EXPECT_THROW(inventory[1], PWException);
}


TEST(PWServerTest, Start) {
    std::vector<InventoryItem> items;
    items.push_back(InventoryItem{"Polka Dot Begonia", 4, 30});
    items.push_back(InventoryItem{"White Monstera", 4, 80});
    items.push_back(InventoryItem{"Gardening Workshop", 10, 10});
    items.push_back(InventoryItem{"Somename", 8, 0});
	PWInventory inventory;
	inventory.Load(items);
    inventory.Save("test.json");

    PWServer server("test.json", "test.json");
	server.Start();
}