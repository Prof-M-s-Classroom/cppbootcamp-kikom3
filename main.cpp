#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor
    Robot(string n, string m, int bL): name(n), model(m), batteryLife(bL) {}

    // Getter Methods
    string getName() {
        return name;
    }
    string getModel() {
        return model;
    }
    int getBatteryLife() {
        return batteryLife;
    }
    // Setter Methods
    void setName(string n) {
        name = n;
    }

    void setModel(string m) {
        model = m;
    }

    void setBatteryLife(int bL) {
        batteryLife = bL;
    }

    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
    void modifyRobotByValue(Robot r) {
        r.setName("David");
        r.setModel("T-100");
        r.setBatteryLife(200);
        std::cout << "Using pass by value we get " << r.getModel() << " " << r.getName() << " " <<  r.getBatteryLife() << "%" << endl;
    }


// Step 3: Function to modify robot (pass by reference)
    void modifyRobotByReference(Robot &r) {
        r.setName("New Robot");
        r.setModel("T-200");
        r.setBatteryLife(100);
        std::cout << "Using pass by reference we get " << r.getModel() << " " << r.getName() << " " <<  r.getBatteryLife() << "%" << endl;
    }

// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot newRobot("John", "T-500", 50);



    // Step 6: Use pointers to access Robot object
    Robot* carPtr = &newRobot;
    cout << "Updated Battery Life (using pointer): " << carPtr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    modifyRobotByValue(newRobot);

    cout << "After modifyRobotByValue, Battery Life: " << newRobot.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)
    modifyRobotByReference(newRobot);
    cout << "After modifyRobotByReference, Battery Life: " << newRobot.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.showFleet();

    Fleet<string> myFleet2(1);
    myFleet2.addRobot("david");
    myFleet2.showFleet();
    return 0;

    // did and tested on another file before getting from classroom so I pasted what I did there on here
}