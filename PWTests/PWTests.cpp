#include <gtest/gtest.h>
#include <PWInventory.h>

// TIP: Keep the tests simple, aim for good coverage 
TEST(PWInventory, checkIfLowCostPothosExistInInventory) {

	PWInventory inventory{ { InventoryItem{ "Low-Cost Pothos", 0 , 0 } } };
	EXPECT_EQ(inventory[0].name, "Low-Cost Pothos");

}

TEST(PWInventory, checkIfLowCostPothosDontExistInInventory) {

	PWInventory inventory{ { InventoryItem{ "Low-Cost Pothoss", 0 , 0 } } };
	EXPECT_NE(inventory[0].name, "Low-Cost Pothos");

}

TEST(PWInventory, checkIfLowCostPothosIsOkFor8Days) {

	PWInventory inventory{ { InventoryItem{ "Low-Cost Pothos", 10 , 80 } } };
	const int dayAmount{8};

	const std::string expectedFlowerName{ "Low-Cost Pothos" };
	const int expectedSellBy{2};
	const int expectedValue{2};

	for (int day{0}; day < dayAmount; ++day)
	{
		inventory.UpdateQuality();
	}

	EXPECT_EQ(inventory[0].name, expectedFlowerName);
	EXPECT_EQ(inventory[0].sellBy, expectedSellBy);
	EXPECT_EQ(inventory[0].value, expectedValue);

}


