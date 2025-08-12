#include "NIC.h"
#include <iostream>
#include <cstring>

// Initialize static members
NIC* NIC::instance = nullptr;
bool NIC::instanceCreated = false;

// Private constructor
NIC::NIC() : manufacturer(""), macAddress(""), type("") {
    // Constructor is private, only called by getInstance()
}

// Destructor
NIC::~NIC() {
    // Clean up if this is the singleton instance
    if (instance == this) {
        instance = nullptr;
        instanceCreated = false;
    }
}

// Static method to get the single instance
NIC* NIC::getInstance() {
    if (!instanceCreated) {
        instance = new NIC();
        instanceCreated = true;
    }
    return instance;
}

// Initialize NIC data
void NIC::initializeNIC(const std::string& manufacturer, 
                       const std::string& macAddress, 
                       const std::string& type) {
    this->manufacturer = manufacturer;
    this->macAddress = macAddress;
    
    // Validate type - only allow Ethernet or Token Ring
    if (type == "Ethernet" || type == "Token Ring") {
        this->type = type;
    } else {
        this->type = "Unknown";
        std::cerr << "Warning: Invalid NIC type. Setting to 'Unknown'." << std::endl;
    }
}

// Getter methods
std::string NIC::getManufacturer() const {
    return manufacturer;
}

std::string NIC::getMACAddress() const {
    return macAddress;
}

std::string NIC::getType() const {
    return type;
}

// Display NIC information
void NIC::displayInfo() const {
    std::cout << "=== Network Interface Controller Information ===" << std::endl;
    std::cout << "Manufacturer: " << manufacturer << std::endl;
    std::cout << "MAC Address: " << macAddress << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "=============================================" << std::endl;
}

// Check if NIC is initialized
bool NIC::isInitialized() const {
    return !manufacturer.empty() && !macAddress.empty() && !type.empty();
}

// Reset instance (for testing purposes)
void NIC::resetInstance() {
    if (instance) {
        delete instance;
        instance = nullptr;
        instanceCreated = false;
    }
}