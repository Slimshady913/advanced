using System;

namespace Week3
{
    class Person
    {
        public string Name { get; private set; }
        public int Age { get; private set; }

        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }

        ~Person()
        {
            Console.WriteLine($"{Name}이(가) 소멸되었습니다.");
        }

        public void Walk()
        {
            Console.WriteLine($"{Name}이(가) 걷는다.");
        }

        public void Run()
        {
            Console.WriteLine($"{Name}이(가) 뜁니다.");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person p = new Person("철수", 20);
            p.Walk();
            p.Run();
            p = null;
            GC.Collect();
            GC.WaitForPendingFinalizers();
            Console.WriteLine("print 함수가 삭제되었습니다.");
        }
    }
}