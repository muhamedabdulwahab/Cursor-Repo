using System;

namespace FTPClientProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("FTP Client Project - NIC Class Demo");
            Console.WriteLine("==================================");
            
            // Get the single instance of NIC
            NIC nic1 = NIC.Instance;
            
            // Set NIC properties
            nic1.Manufacture = "Intel Corporation";
            nic1.MacAddress = "00:1B:21:3C:4D:5E";
            nic1.Type = NetworkType.Ethernet;
            
            Console.WriteLine("NIC Instance 1:");
            Console.WriteLine(nic1.ToString());
            Console.WriteLine();
            
            // Try to get another instance (will be the same object)
            NIC nic2 = NIC.Instance;
            
            Console.WriteLine("NIC Instance 2 (same object):");
            Console.WriteLine(nic2.ToString());
            Console.WriteLine();
            
            // Verify they are the same instance
            Console.WriteLine($"Are nic1 and nic2 the same instance? {ReferenceEquals(nic1, nic2)}");
            
            // Change a property on nic2 and see it reflected in nic1
            nic2.Type = NetworkType.TokenRing;
            Console.WriteLine($"After changing nic2.Type to TokenRing:");
            Console.WriteLine($"nic1.Type: {nic1.Type}");
            Console.WriteLine($"nic2.Type: {nic2.Type}");
            
            Console.WriteLine("\nPress any key to exit...");
            Console.ReadKey();
        }
    }
}