#include "stdafx.h"
#include "..\PWServer\PWInventory.h"

// TIP: Keep the tests simple, aim for good coverage 
TEST(PWInventory, Foo) {
	PWInventory inventory{ { InventoryItem{ "Foo", 0 , 0 } } };
	EXPECT_EQ(inventory[0].name, "fixme");
}
