// #include "stdafx.h"
#include <gtest/gtest.h>
#include <PWInventory.h>

// TIP: Keep the tests simple, aim for good coverage 
TEST(PWInventory, FooBad) {
	PWInventory inventory{ { InventoryItem{ "Foo", 0 , 0 } } };
	EXPECT_EQ(inventory[0].name, "Foo");
}
TEST(PWInventory, FooGood) {
	PWInventory inventory{ { InventoryItem{ "Foo", 0 , 0 } } };
	EXPECT_EQ(inventory[0].name, "Foo");
}
