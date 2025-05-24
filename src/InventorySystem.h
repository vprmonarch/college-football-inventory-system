#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>
#include <limits>

class Item {
private:
    std::string name;
    int quantity;
    float price;

public:
    Item(std::string name, int quantity, float price);
    
    // Getters
    std::string get_name() const;
    int get_quantity() const;
    float get_price() const;
    
    // Setters
    void set_quantity(int new_quantity);
    
    // Utilities
    bool is_match(const std::string& other) const;
};

class Inventory {
private:
    std::vector<std::unique_ptr<Item>> items;
    float total_money = 0;
    
    void display_item(const Item& item) const;

public:
    // Core functionality
    void add_item();
    void sell_item();
    void remove_item(int item_index);
    void list_items() const;
    
    // Getters
    float get_total_money() const;
    int get_item_count() const;
};