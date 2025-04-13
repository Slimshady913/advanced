using System;

// Internal class with a Fetch method
public class InternalClass
{
    public string Fetch()
    {
        return "get user info";
    }
}

// External class with a Search method
public class ExternalClass
{
    public string Search()
    {
        return "get user info";
    }
}

// Adapter class to adapt ExternalClass to match InternalClass's interface
public class Adapter
{
    private readonly ExternalClass _external;

    public Adapter(ExternalClass external)
    {
        _external = external;
    }

    public string Fetch()
    {
        return _external.Search();
    }
}

// Main program
class Program
{
    static void Main(string[] args)
    {
        // Create an instance of ExternalClass
        ExternalClass external = new ExternalClass();

        // Use the Adapter to adapt ExternalClass to match InternalClass's interface
        Adapter adapter = new Adapter(external);

        // Call the Fetch method through the adapter
        Console.WriteLine(adapter.Fetch()); // Output: get user info
    }
}