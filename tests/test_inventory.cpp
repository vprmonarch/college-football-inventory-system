#include "InventorySystem.h"
#include <gtest/gtest.h>

TEST(InventoryTest, AddAndRemoveItems) {
    Inventory inv;
    
    // Test adding items
    inv.add_item(); // Would need mock input for automated testing
    ASSERT_EQ(inv.get_item_count(), 1);
    
    // Test item removal
    inv.remove_item(0); // Would need mock input
    ASSERT_EQ(inv.get_item_count(), 0);
}

TEST(InventoryTest, SellItems) {
    Inventory inv;
    // Would need mock input/output for complete testing
}

// Add more tests as needed