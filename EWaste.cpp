#include <iostream>
#include <vector>

using namespace std;

class ElectronicItem {
protected:
    string itemName;
    float weight;
    string originCity;

public:
    virtual void input() {
        cout << "Enter item name: ";
        cin >> itemName;
        cout << "Enter weight (in kg): ";
        cin >> weight;
        cout << "Enter origin city: ";
        cin >> originCity;
    }

    virtual void display() const {
        cout << "Item Name: " << itemName << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Origin City: " << originCity << endl;
    }

    virtual ~ElectronicItem() {}  
};


class HomeAppliance : public ElectronicItem {
    float powerRating;
    float recyclablePlasticPercent;

public:
    void input() override {
        ElectronicItem::input();
        cout << "Enter power rating (Watts): ";
        cin >> powerRating;
        cout << "Enter recyclable plastic percentage: ";
        cin >> recyclablePlasticPercent;
    }

    void display() const override {
        cout << "\n[Home Appliance]\n";
        ElectronicItem::display();
        cout << "Power Rating: " << powerRating << " W" << endl;
        cout << "Recyclable Plastic: " << recyclablePlasticPercent << "%" << endl;
    }

    float getRecyclablePlasticPercent() const {
        return recyclablePlasticPercent;
    }
};


class MobileDevice : public ElectronicItem {
    int batteryCapacity;
    bool hasScreenCrack;

public:
    void input() override {
        ElectronicItem::input();
        cout << "Enter battery capacity (mAh): ";
        cin >> batteryCapacity;
        cout << "Has screen crack? (1 for Yes, 0 for No): ";
        cin >> hasScreenCrack;
    }

    void display() const override {
        cout << "\n[Mobile Device]\n";
        ElectronicItem::display();
        cout << "Battery Capacity: " << batteryCapacity << " mAh" << endl;
        cout << "Screen Crack: " << (hasScreenCrack ? "Yes" : "No") << endl;
    }

    int getBatteryCapacity() const {
        return batteryCapacity;
    }
};


int main() {
    vector<ElectronicItem*> items;
    int choice;

    do {
        cout << "\n----- E-Waste Recycling Tracker -----\n";
        cout << "1. Add Home Appliance\n";
        cout << "2. Add Mobile Device\n";
        cout << "3. Display All Items\n";
        cout << "4. List Mobile Devices with Battery > 3000 mAh\n";
        cout << "5. Count Home Appliances with >70% Recyclable Plastic\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                ElectronicItem* item = new HomeAppliance();
                item->input();
                items.push_back(item);
                break;
            }
            case 2: {
                ElectronicItem* item = new MobileDevice();
                item->input();
                items.push_back(item);
                break;
            }
            case 3: {
                cout << "\n--- All Electronic Items ---\n";
                for (auto* item : items) {
                    item->display();
                }
                break;
            }
            case 4: {
                cout << "\n--- Mobile Devices with Battery > 3000 mAh ---\n";
                for (auto* item : items) {
                    MobileDevice* md = dynamic_cast<MobileDevice*>(item);
                    if (md && md->getBatteryCapacity() > 3000) {
                        md->display();
                    }
                }
                break;
            }
            case 5: {
                int count = 0;
                for (auto* item : items) {
                    HomeAppliance* ha = dynamic_cast<HomeAppliance*>(item);
                    if (ha && ha->getRecyclablePlasticPercent() > 70) {
                        count++;
                    }
                }
                cout << "Count of Home Appliances with >70% recyclable plastic: " << count << endl;
                break;
            }
            case 6: {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

   
    for (auto* item : items) {
        delete item;
    }

    return 0;
}
