using System;

namespace DesignPattern.Factory
{
    // Abstract base class
    public abstract class Animal
    {
        public abstract string Speak();
    }

    // Concrete class Dog
    public class Dog : Animal
    {
        public override string Speak()
        {
            return "Woof!";
        }
    }

    // Concrete class Cat
    public class Cat : Animal
    {
        public override string Speak()
        {
            return "Meow!";
        }
    }

    // Factory class
    public class AnimalFactory
    {
        public Animal CreateAnimal(string animalType)
        {
            if (animalType == "dog")
            {
                return new Dog();
            }
            else if (animalType == "cat")
            {
                return new Cat();
            }
            else
            {
                throw new ArgumentException("Invalid animal type");
            }
        }
    }

    // Example usage
    class Program
    {
        static void Main(string[] args)
        {
            AnimalFactory factory = new AnimalFactory();

            Animal dog = factory.CreateAnimal("dog");
            Console.WriteLine(dog.Speak()); // Output: Woof!

            Animal cat = factory.CreateAnimal("cat");
            Console.WriteLine(cat.Speak()); // Output: Meow!
        }
    }
}