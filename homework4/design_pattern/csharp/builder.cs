using System;

public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string Address { get; set; }
}

public class PersonBuilder
{
    private readonly Person _person;

    public PersonBuilder()
    {
        _person = new Person();
    }

    public PersonBuilder WithName(string name)
    {
        _person.Name = name;
        return this; // Return itself for method chaining
    }

    public PersonBuilder WithAge(int age)
    {
        _person.Age = age;
        return this; // Return itself for method chaining
    }

    public PersonBuilder WithAddress(string address)
    {
        _person.Address = address;
        return this; // Return itself for method chaining
    }

    public Person Build()
    {
        return _person;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Person person = new PersonBuilder()
            .WithName("홍길동")
            .WithAge(20)
            .WithAddress("양산시 부산대학로")
            .Build();

        Console.WriteLine($"Name: {person.Name}, Age: {person.Age}, Address: {person.Address}");
    }
}