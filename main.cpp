#include "NIC.h"
#include <iostream>

int main() {
    std::cout << "FTP Client - Network Interface Controller Demo" << std::endl;
    std::cout << "=============================================" << std::endl;
    
    // Get the single instance of NIC
    NIC* nic1 = NIC::getInstance();
    
    // Initialize the NIC with data
    nic1->initializeNIC("Intel Corporation", "00:1B:21:0A:1F:3C", "Ethernet");
    
    // Display NIC information
    nic1->displayInfo();
    
    // Try to get another instance (should return the same instance)
    NIC* nic2 = NIC::getInstance();
    
    std::cout << "\nChecking if both pointers point to the same instance:" << std::endl;
    std::cout << "nic1 address: " << nic1 << std::endl;
    std::cout << "nic2 address: " << nic2 << std::endl;
    std::cout << "Are they the same? " << (nic1 == nic2 ? "Yes" : "No") << std::endl;
    
    // Try to change the type to Token Ring
    nic2->initializeNIC("Intel Corporation", "00:1B:21:0A:1F:3C", "Token Ring");
    
    std::cout << "\nAfter changing type to Token Ring:" << std::endl;
    nic1->displayInfo();
    
    // Demonstrate that both pointers access the same data
    std::cout << "\nAccessing data through nic1:" << std::endl;
    std::cout << "Type: " << nic1->getType() << std::endl;
    
    std::cout << "\nAccessing data through nic2:" << std::endl;
    std::cout << "Type: " << nic2->getType() << std::endl;
    
    // Check if NIC is properly initialized
    std::cout << "\nIs NIC initialized? " << (nic1->isInitialized() ? "Yes" : "No") << std::endl;
    
    return 0;
}