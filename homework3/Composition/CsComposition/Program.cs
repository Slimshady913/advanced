using System;

namespace Composition
{
    // WalkMethod 인터페이스 정의
    interface IWalkMethod
    {
        int Walk();
    }

    // WalkToSchool 클래스가 IWalkMethod를 구현
    class WalkToSchool : IWalkMethod
    {
        private int Distance { get; }

        public WalkToSchool(int distance)
        {
            Distance = distance;
        }

        public int Walk()
        {
            Console.WriteLine($"Walking to school, distance: {Distance} km");
            return Distance;
        }
    }

    // WalkHome 클래스가 IWalkMethod를 구현
    class WalkHome : IWalkMethod
    {
        private int Distance { get; }

        public WalkHome(int distance)
        {
            Distance = distance;
        }

        public int Walk()
        {
            Console.WriteLine($"Walking home, distance: {Distance} km");
            return Distance;
        }
    }

    // Person 클래스
    class Person
    {
        private string Name { get; }
        private IWalkMethod WalkMethod { get; }

        public Person(string name, IWalkMethod walkMethod)
        {
            Name = name;
            WalkMethod = walkMethod;
        }

        public void Walk()
        {
            Console.WriteLine($"{Name} is walking...");
            WalkMethod.Walk();
        }
    }

    // Main 함수
    class Program
    {
        static void Main(string[] args)
        {
            var john = new Person("John", new WalkToSchool(2));
            john.Walk();

            var jane = new Person("Jane", new WalkHome(3));
            jane.Walk();
        }
    }
}