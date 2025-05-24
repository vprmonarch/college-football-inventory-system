#include "InventorySystem.h"
#include <iostream>

int main() {
    Inventory inventory_system;
    std::cout << "Welcome to the inventory management system!";

    while (true) {
        std::cout << "\n\nMENU\n"
                  << "1. Add new item\n"
                  << "2. Sell item\n"
                  << "3. List items\n"
                  << "4. Show total money\n"
                  << "5. Exit\n\n"
                  << "Enter your choice: ";
        
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                inventory_system.add_item();
                break;
            case 2:
                inventory_system.sell_item();
                break;
            case 3:
                inventory_system.list_items();
                break;
            case 4:
                std::cout << "\nTotal money: $" << inventory_system.get_total_money() << "\n";
                break;
            case 5:
                return 0;
            default:
                std::cout << "\nInvalid choice entered\n";
                break;
        }
    }
}