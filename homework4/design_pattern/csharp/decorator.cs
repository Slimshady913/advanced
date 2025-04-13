using System;

public class Coffee
{
    public virtual int Cost()
    {
        return 5;
    }
}

public class CoffeeDecorator : Coffee
{
    protected Coffee _coffee;

    public CoffeeDecorator(Coffee coffee)
    {
        _coffee = coffee;
    }

    public override int Cost()
    {
        return _coffee.Cost();
    }
}

public class MilkDecorator : CoffeeDecorator
{
    public MilkDecorator(Coffee coffee) : base(coffee) { }

    public override int Cost()
    {
        return _coffee.Cost() + 2;
    }
}

public class SugarDecorator : CoffeeDecorator
{
    public SugarDecorator(Coffee coffee) : base(coffee) { }

    public override int Cost()
    {
        return _coffee.Cost() + 1;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Coffee coffee = new Coffee();
        Console.WriteLine(coffee.Cost()); // 5

        Coffee coffeeWithMilk = new MilkDecorator(coffee);
        Console.WriteLine(coffeeWithMilk.Cost()); // 7

        Coffee coffeeWithSugar = new SugarDecorator(coffee);
        Console.WriteLine(coffeeWithSugar.Cost()); // 6

        Coffee coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
        Console.WriteLine(coffeeWithMilkAndSugar.Cost()); // 8
    }
}