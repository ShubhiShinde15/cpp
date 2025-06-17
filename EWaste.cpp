#include <iostream>
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
    const int MAX_ITEMS = 100;
    ElectronicItem* items[MAX_ITEMS];
    int count = 0;
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
                if (count < MAX_ITEMS) {
                    items[count] = new HomeAppliance();
                    items[count]->input();
                    count++;
                } else {
                    cout << "Item limit reached!" << endl;
                }
                break;
            }
            case 2: {
                if (count < MAX_ITEMS) {
                    items[count] = new MobileDevice();
                    items[count]->input();
                    count++;
                } else {
                    cout << "Item limit reached!" << endl;
                }
                break;
            }
            case 3: {
                cout << "\n--- All Electronic Items ---\n";
                for (int i = 0; i < count; i++) {
                    items[i]->display();
                }
                break;
            }
            case 4: {
                cout << "\n--- Mobile Devices with Battery > 3000 mAh ---\n";
                for (int i = 0; i < count; i++) {
                    MobileDevice* md = dynamic_cast<MobileDevice*>(items[i]);
                    if (md && md->getBatteryCapacity() > 3000) {
                        md->display();
                    }
                }
                break;
            }
            case 5: {
                int haCount = 0;
                for (int i = 0; i < count; i++) {
                    HomeAppliance* ha = dynamic_cast<HomeAppliance*>(items[i]);
                    if (ha && ha->getRecyclablePlasticPercent() > 70) {
                        haCount++;
                    }
                }
                cout << "Home Appliances with >70% recyclable plastic: " << haCount << endl;
                break;
            }
            case 6: {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    for (int i = 0; i < count; i++) {
        delete items[i];
    }

    return 0;
}
