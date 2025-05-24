#include "InventorySystem.h"

// Item Implementation
Item::Item(std::string name, int quantity, float price)
    : name(std::move(name)), quantity(quantity), price(price) {}

std::string Item::get_name() const { return name; }
int Item::get_quantity() const { return quantity; }
float Item::get_price() const { return price; }

void Item::set_quantity(int new_quantity) { quantity = new_quantity; }

bool Item::is_match(const std::string& other) const {
    return name == other;
}

// Inventory Implementation
void Inventory::display_item(const Item& item) const {
    std::cout << "\nItem name: " << item.get_name();
    std::cout << "\nQuantity: " << item.get_quantity();
    std::cout << "\nPrice: " << item.get_price() << "\n";
}

void Inventory::add_item() {
    std::string name;
    int quantity;
    float price;

    std::cin.ignore();
    std::cout << "\nEnter item name: ";
    std::getline(std::cin, name);
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;

    items.push_back(std::make_unique<Item>(name, quantity, price));
}

void Inventory::sell_item() {
    std::string item_to_check;
    std::cin.ignore();
    std::cout << "\nEnter item name: ";
    std::getline(std::cin, item_to_check);

    auto it = std::find_if(items.begin(), items.end(),
        [&item_to_check](const auto& item) {
            return item->is_match(item_to_check);
        });

    if (it != items.end()) {
        remove_item(it - items.begin());
    } else {
        std::cout << "\nThis item is not in your Inventory\n";
    }
}

void Inventory::remove_item(int item_index) {
    int input_quantity;
    Item* item = items[item_index].get();
    std::cout << "\nEnter number of items to sell: ";
    std::cin >> input_quantity;

    int quantity = item->get_quantity();
    if (input_quantity <= 0) {
        std::cout << "\nInvalid quantity entered.\n";
        return;
    }

    if (input_quantity <= quantity) {
        float money_earned = item->get_price() * input_quantity;
        int new_quantity = quantity - input_quantity;
        item->set_quantity(new_quantity);
        
        std::cout << "\nItems sold";
        std::cout << "\nMoney received: " << money_earned << "\n";
        total_money += money_earned;

        if (new_quantity <= 0) {
            items.erase(items.begin() + item_index);
            std::cout << "Item completely removed from inventory.\n";
        }
    } else {
        std::cout << "\nCannot sell more items than you have.\n";
    }
}

void Inventory::list_items() const {
    if (items.empty()) {
        std::cout << "\nInventory empty.\n";
        return;
    }

    for (const auto& item : items) {
        display_item(*item);
    }
}

float Inventory::get_total_money() const { return total_money; }
int Inventory::get_item_count() const { return items.size(); }