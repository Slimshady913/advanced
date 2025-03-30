using System;

class Program
{
    static void Main(string[] args)
    {
        // ValueTuple 생성
        var person = ("Alice", 30, "Engineer");

        // ValueTuple 값 출력
        Console.WriteLine("=== ValueTuple Example ===");
        Console.WriteLine($"Name: {person.Item1}");
        Console.WriteLine($"Age: {person.Item2}");
        Console.WriteLine($"Profession: {person.Item3}");

        // ValueTuple 반환 메서드 예시
        var result = GetPersonInfo();
        Console.WriteLine("\n=== Returned ValueTuple ===");
        Console.WriteLine($"Name: {result.Name}, Age: {result.Age}, Profession: {result.Profession}");

        // Nested ValueTuple 예시
        var nestedTuple = ("John", (40, "Manager"));
        Console.WriteLine("\n=== Nested ValueTuple ===");
        Console.WriteLine($"Name: {nestedTuple.Item1}");
        Console.WriteLine($"Age: {nestedTuple.Item2.Item1}");
        Console.WriteLine($"Profession: {nestedTuple.Item2.Item2}");

        // ValueTuple 비교
        var anotherPerson = ("Alice", 30, "Engineer");
        Console.WriteLine("\n=== ValueTuple Comparison ===");
        Console.WriteLine($"Are 'person' and 'anotherPerson' equal? {person.Equals(anotherPerson)}");
    }

    static (string Name, int Age, string Profession) GetPersonInfo()
    {
        return ("Bob", 25, "Designer");
    }
}
