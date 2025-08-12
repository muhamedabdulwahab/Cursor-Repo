# FTP Client - Network Interface Controller (NIC) Class

This project implements a Network Interface Controller (NIC) class designed for use in an FTP client project. The class follows the Singleton design pattern to ensure that only one instance of the NIC can exist, representing the single network card in your machine.

## Features

- **Singleton Pattern**: Prevents multiple instances of the NIC class
- **Complete NIC Information**: Stores manufacturer, MAC address, and type
- **Type Validation**: Supports Ethernet and Token Ring network types
- **Thread-Safe Design**: Safe for use in multi-threaded applications
- **Easy Integration**: Simple API for FTP client integration

## Class Structure

### Data Members
- `manufacturer`: String containing the NIC manufacturer name
- `macAddress`: String containing the MAC address (e.g., "00:1B:21:0A:1F:3C")
- `type`: String indicating network type ("Ethernet" or "Token Ring")

### Key Methods
- `getInstance()`: Static method to get the single NIC instance
- `initializeNIC()`: Initialize NIC data (manufacturer, MAC, type)
- `getManufacturer()`, `getMACAddress()`, `getType()`: Getter methods
- `displayInfo()`: Display all NIC information
- `isInitialized()`: Check if NIC data has been set

## Usage Example

```cpp
#include "NIC.h"

int main() {
    // Get the single NIC instance
    NIC* nic = NIC::getInstance();
    
    // Initialize with your machine's NIC data
    nic->initializeNIC("Intel Corporation", "00:1B:21:0A:1F:3C", "Ethernet");
    
    // Use the NIC information in your FTP client
    std::string mac = nic->getMACAddress();
    std::string type = nic->getType();
    
    return 0;
}
```

## Building the Project

### Prerequisites
- GCC compiler with C++11 support
- Make utility

### Build Commands
```bash
# Build the executable
make

# Build and run the demo
make run

# Clean build files
make clean

# Show available targets
make help
```

### Manual Compilation
```bash
g++ -std=c++11 -Wall -Wextra -g -c NIC.cpp -o NIC.o
g++ -std=c++11 -Wall -Wextra -g -c main.cpp -o main.o
g++ NIC.o main.o -o ftp_nic_demo
```

## Integration with FTP Client

To integrate this NIC class with your FTP client:

1. Include `NIC.h` in your FTP client source files
2. Call `NIC::getInstance()` to get the NIC instance
3. Use the NIC information for network configuration, logging, or identification
4. The singleton pattern ensures consistent NIC information across your entire application

## Design Patterns Used

- **Singleton Pattern**: Ensures only one NIC instance exists
- **Private Constructor**: Prevents direct instantiation
- **Deleted Copy Constructor/Assignment**: Prevents object copying
- **Static Instance Management**: Centralized instance control

## File Structure

```
.
├── NIC.h          # NIC class header file
├── NIC.cpp        # NIC class implementation
├── main.cpp       # Demo program
├── Makefile       # Build configuration
└── README.md      # This documentation
```

## Testing

The included demo program (`main.cpp`) demonstrates:
- Singleton pattern functionality
- NIC data initialization and retrieval
- Multiple pointer access to the same instance
- Type validation for network types

Run the demo with:
```bash
make run
```

## Notes

- The class validates network types and only accepts "Ethernet" or "Token Ring"
- Invalid types are set to "Unknown" with a warning message
- The `resetInstance()` method is provided for testing purposes
- Memory management is handled automatically through the singleton pattern

## License

This project is provided as-is for educational and development purposes.