using System;

class Calculator
{
    private double result;

    public Calculator()
    {
        result = 0;
    }

    public Calculator Add(double value)
    {
        result += value;
        return this; // Return itself for method chaining
    }

    public Calculator Subtract(double value)
    {
        result -= value;
        return this; // Return itself for method chaining
    }

    public Calculator Multiply(double value)
    {
        result *= value;
        return this; // Return itself for method chaining
    }

    public Calculator Divide(double value)
    {
        if (value != 0)
        {
            result /= value;
        }
        return this; // Return itself for method chaining
    }

    public double GetResult()
    {
        return result;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Calculator calc = new Calculator();
        double result = calc.Add(5)
                            .Multiply(2)
                            .Subtract(3)
                            .Divide(2)
                            .GetResult();
        Console.WriteLine(result);
    }
}