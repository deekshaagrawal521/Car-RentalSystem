#include <iostream>
#include <vector>
#include <string>

class Car {
public:
    int carId;
    std::string name;
    std::string model;
    double price;
    double mileage;
    bool available;

    Car(int id, const std::string& carName, const std::string& carModel, double carPrice, double carMileage)
        : carId(id), name(carName), model(carModel), price(carPrice), mileage(carMileage), available(true) {}

    std::string getDetails() const {
        return "Car ID: " + std::to_string(carId) + "\nName: " + name + "\nModel: " + model +
               "\nPrice: $" + std::to_string(price) + "\nMileage: " + std::to_string(mileage) + " km/l\n";
    }
};

class Customer {
public:
    int customerId;
    std::string name;
    std::string phoneNumber;
    std::string address;

    Customer(int id, const std::string& customerName, const std::string& phone, const std::string& addr)
        : customerId(id), name(customerName), phoneNumber(phone), address(addr) {}

    std::string getDetails() const {
        return "Customer ID: " + std::to_string(customerId) + "\nName: " + name +
               "\nPhone Number: " + phoneNumber + "\nAddress: " + address + "\n";
    }
};

class CarRentalSystem {
private:
    std::vector<Car> cars;
    std::vector<Customer> customers;

public:
    void addCar(int id, const std::string& name, const std::string& model, double price, double mileage) {
        cars.emplace_back(id, name, model, price, mileage);
    }

    void addCustomer(int id, const std::string& name, const std::string& phone, const std::string& address) {
        customers.emplace_back(id, name, phone, address);
    }

    void rentCar(int carId, int customerId) {
        for (auto& car : cars) {
            if (car.carId == carId && car.available) {
                car.available = false;
                std::cout << "Car rented successfully!\n";
                return;
            }
        }
        std::cout << "Car not available for rent.\n";
    }

    void returnCar(int carId) {
        for (auto& car : cars) {
            if (car.carId == carId && !car.available) {
                car.available = true;
                std::cout << "Car returned successfully!\n";
                return;
            }
        }
        std::cout << "Invalid car ID or the car is not rented.\n";
    }

    void displayAvailableCars() const {
        std::cout << "Available Cars:\n";
        for (const auto& car : cars) {
            if (car.available) {
                std::cout << car.getDetails();
                std::cout << "------------------------\n";
            }
        }
    }

    std::string getCustomerDetails(int customerId) const {
        for (const auto& customer : customers) {
            if (customer.customerId == customerId) {
                return customer.getDetails();
            }
        }
        return "Customer not found.\n";
    }
};

int main() {
    CarRentalSystem rentalSystem;

    int carId, customerId;
    std::string carName, carModel, customerName, phone, address;

    // Adding cars to the system
    std::cout << "Enter Car ID: ";
    std::cin >> carId;
    std::cout << "Enter Car Name: ";
    std::cin.ignore();
    std::getline(std::cin, carName);
    std::cout << "Enter Car Model: ";
    std::getline(std::cin, carModel);
    double carPrice, carMileage;
    std::cout << "Enter Car Price: ";
    std::cin >> carPrice;
    std::cout << "Enter Car Mileage: ";
    std::cin >> carMileage;
    rentalSystem.addCar(carId, carName, carModel, carPrice, carMileage);

    // Adding customers to the system
    std::cout << "Enter Customer ID: ";
    std::cin >> customerId;
    std::cout << "Enter Customer Name: ";
    std::cin.ignore();
    std::getline(std::cin, customerName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone);
    std::cout << "Enter Address: ";
    std::getline(std::cin, address);
    rentalSystem.addCustomer(customerId, customerName, phone, address);

    // Renting a car to a customer
    std::cout << "Enter Car ID to rent: ";
    std::cin >> carId;
    std::cout << "Enter Customer ID: ";
    std::cin >> customerId;
    rentalSystem.rentCar(carId, customerId);

    // Displaying available cars
    rentalSystem.displayAvailableCars();

    // Returning a rented car
    std::cout << "Enter Car ID to return: ";
    std::cin >> carId;
    rentalSystem.returnCar(carId);

    // Displaying available cars after returning
    rentalSystem.displayAvailableCars();

    // Displaying customer details
    std::cout << "Enter Customer ID to display details: ";
    std::cin >> customerId;
    std::cout << rentalSystem.getCustomerDetails(customerId) << std::endl;

    return 0;
}
