using System;
using System.Collections.Generic;

namespace LTD.L
{
    public class ListExample
    {
        public static void Main(string[] args)
        {
            // Create a list of integers
            List<int> numbers = new List<int>();

            // Add elements to the list
            numbers.Add(10);
            numbers.Add(20);
            numbers.Add(30);

            // Display the elements in the list
            Console.WriteLine("List elements:");
            foreach (int number in numbers)
            {
                Console.WriteLine(number);
            }

            // Insert an element at a specific index
            numbers.Insert(1, 15);
            Console.WriteLine("\nAfter inserting 15 at index 1:");
            foreach (int number in numbers)
            {
                Console.WriteLine(number);
            }

            // Remove an element from the list
            numbers.Remove(20);
            Console.WriteLine("\nAfter removing 20:");
            foreach (int number in numbers)
            {
                Console.WriteLine(number);
            }

            // Access an element by index
            Console.WriteLine($"\nElement at index 2: {numbers[2]}");

            // Count the number of elements in the list
            Console.WriteLine($"\nTotal elements in the list: {numbers.Count}");
        }
    }
}