using System;

namespace FTPClientProject
{
    /// <summary>
    /// Network Interface Controller (NIC) class that represents the single network card on the machine.
    /// Implements singleton pattern to ensure only one instance can be created.
    /// </summary>
    public sealed class NIC
    {
        // Private static instance for singleton pattern
        private static readonly Lazy<NIC> _instance = new Lazy<NIC>(() => new NIC());
        
        // Private constructor to prevent external instantiation
        private NIC()
        {
            // Initialize with default values
            Manufacture = "Unknown";
            MacAddress = "00:00:00:00:00:00";
            Type = NetworkType.Ethernet;
        }
        
        /// <summary>
        /// Gets the single instance of the NIC class
        /// </summary>
        public static NIC Instance => _instance.Value;
        
        /// <summary>
        /// Gets or sets the manufacturer of the network card
        /// </summary>
        public string Manufacture { get; set; }
        
        /// <summary>
        /// Gets or sets the MAC address of the network card
        /// </summary>
        public string MacAddress { get; set; }
        
        /// <summary>
        /// Gets or sets the type of network connection
        /// </summary>
        public NetworkType Type { get; set; }
        
        /// <summary>
        /// Override ToString method to provide a readable representation of the NIC
        /// </summary>
        /// <returns>String representation of the NIC properties</returns>
        public override string ToString()
        {
            return $"NIC - Manufacturer: {Manufacture}, MAC: {MacAddress}, Type: {Type}";
        }
    }
    
    /// <summary>
    /// Enumeration for network connection types
    /// </summary>
    public enum NetworkType
    {
        /// <summary>
        /// Ethernet connection type
        /// </summary>
        Ethernet,
        
        /// <summary>
        /// Token Ring connection type
        /// </summary>
        TokenRing
    }
}