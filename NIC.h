#ifndef NIC_H
#define NIC_H

#include <string>

class NIC {
private:
    // Private constructor to prevent direct instantiation
    NIC();
    
    // Private copy constructor and assignment operator to prevent copying
    NIC(const NIC&) = delete;
    NIC& operator=(const NIC&) = delete;
    
    // Static instance pointer
    static NIC* instance;
    
    // NIC data members
    std::string manufacturer;
    std::string macAddress;
    std::string type; // "Ethernet" or "Token Ring"
    
    // Flag to track if instance has been created
    static bool instanceCreated;

public:
    // Public destructor
    ~NIC();
    
    // Static method to get the single instance
    static NIC* getInstance();
    
    // Method to initialize NIC data (should be called once)
    void initializeNIC(const std::string& manufacturer, 
                      const std::string& macAddress, 
                      const std::string& type);
    
    // Getters for NIC information
    std::string getManufacturer() const;
    std::string getMACAddress() const;
    std::string getType() const;
    
    // Method to display NIC information
    void displayInfo() const;
    
    // Method to check if NIC is initialized
    bool isInitialized() const;
    
    // Method to reset instance (for testing purposes)
    static void resetInstance();
};

#endif // NIC_H