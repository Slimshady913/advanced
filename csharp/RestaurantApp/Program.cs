using System;
using System.Collections.Generic;

namespace RestaurantApp
{
    // 식당 클래스
    public class Restaurant
    {
        private List<Worker> workers = new List<Worker>(); // 종업원 목록
        private List<Customer> customers = new List<Customer>(); // 손님 목록

        public void AddCustomer(Customer customer)
        {
            // 손님 추가
            customers.Add(customer);
        }

        public void AddWorker(Worker worker)
        {
            // 종업원 추가
            workers.Add(worker);
        }
    }

    // 식당 주인 클래스
    public class RestaurantOwner
    {
        private float assets = 0.0f; // 자산

        public void ReceiveMoney(float amount)
        {
            // 돈 받기
            assets += amount;
            Console.WriteLine($"식당 주인이 {amount}원을 받았습니다. 현재 자산: {assets}");
        }

        public void PaySalaries(List<Worker> workers)
        {
            // 종업원들에게 월급 지급
            foreach (var worker in workers)
            {
                worker.ReceiveSalary(worker.Salary);
                assets -= worker.Salary;
            }
            Console.WriteLine($"모든 종업원들에게 월급을 지급했습니다. 남은 자산: {assets}");
        }
    }

    // 추상 종업원 클래스
    public abstract class Worker
    {
        public string Name { get; private set; } // 이름
        public float Salary { get; private set; } // 월급

        public Worker(string name, float salary)
        {
            Name = name;
            Salary = salary;
        }

        public virtual void ReceiveSalary(float amount)
        {
            // 월급 받기
            Console.WriteLine($"{Name}이(가) {amount}원의 월급을 받았습니다.");
        }
    }

    // 요리 담당 클래스
    public class Cook : Worker
    {
        public Cook(string name, float salary) : base(name, salary) { }

        public Food PrepareFood(Order order)
        {
            // 요리 준비
            Food food = new Food();
            foreach (var item in order.GetItems())
            {
                food.AddItem(item);
            }
            Console.WriteLine($"{Name}이(가) 요리를 준비했습니다: {string.Join(", ", food.GetItems())}");
            return food;
        }
    }

    // 서빙 담당 클래스
    public class Server : Worker
    {
        public Server(string name, float salary) : base(name, salary) { }

        public Order TakeOrder(Customer customer)
        {
            // 주문 받기
            Console.WriteLine($"{Name}이(가) {customer.Name}의 주문을 받았습니다.");
            return customer.Order;
        }

        public void DeliverFood(Food food, Customer customer)
        {
            // 음식 전달
            Console.WriteLine($"{Name}이(가) {customer.Name}에게 음식을 전달했습니다: {string.Join(", ", food.GetItems())}");
        }

        public float ReceivePayment(Customer customer)
        {
            // 결제 받기
            float amount = customer.PaymentAmount;
            Console.WriteLine($"{Name}이(가) {customer.Name}에게서 {amount}원을 받았습니다.");
            return amount;
        }

        public Food RequestFood(Cook cook, Order order)
        {
            // 요리 요청
            Console.WriteLine($"{Name}이(가) {cook.Name}에게 요리를 요청했습니다.");
            return cook.PrepareFood(order);
        }

        public void TransferMoney(RestaurantOwner owner, float amount)
        {
            // 돈 전달
            owner.ReceiveMoney(amount);
            Console.WriteLine($"{Name}이(가) 식당 주인에게 {amount}원을 전달했습니다.");
        }
    }

    // 손님 클래스
    public class Customer
    {
        public string Name { get; private set; } // 이름
        public float Money { get; private set; } // 소지금
        public Order Order { get; private set; } = new Order(); // 주문
        public float PaymentAmount { get; private set; } // 결제 금액

        public Customer(string name, float money)
        {
            Name = name;
            Money = money;
        }

        public void PlaceOrder(Order order, Server server)
        {
            // 주문하기
            Order = order;
            Console.WriteLine($"{Name}이(가) {server.Name}에게 주문을 했습니다.");
        }

        public void MakePayment(Server server, float amount)
        {
            // 결제하기
            if (Money >= amount)
            {
                Money -= amount;
                PaymentAmount = amount;
                Console.WriteLine($"{Name}이(가) {server.Name}에게 {amount}원을 결제했습니다. 남은 소지금: {Money}");
            }
            else
            {
                Console.WriteLine($"{Name}이(가) {amount}원을 결제할 충분한 돈이 없습니다.");
            }
        }
    }

    // 주문 클래스
    public class Order
    {
        private List<string> items = new List<string>(); // 주문 항목들

        public void AddItem(string item)
        {
            // 주문 항목 추가
            items.Add(item);
        }

        public List<string> GetItems()
        {
            // 주문 항목 가져오기
            return items;
        }
    }

    // 음식 클래스
    public class Food
    {
        private List<string> items = new List<string>(); // 음식 항목들

        public void AddItem(string item)
        {
            // 음식 항목 추가
            items.Add(item);
        }

        public List<string> GetItems()
        {
            // 음식 항목 가져오기
            return items;
        }
    }

    // 메인 프로그램
    public class Program
    {
        public static void Main(string[] args)
        {
            // 객체 생성
            RestaurantOwner owner = new RestaurantOwner();
            Restaurant restaurant = new Restaurant();
            Cook cook = new Cook("Chef", 3000);
            Server server = new Server("Waiter", 2000);
            Customer customer = new Customer("Customer1", 100000);

            // 식당에 종업원과 손님 추가
            restaurant.AddWorker(cook);
            restaurant.AddWorker(server);
            restaurant.AddCustomer(customer);

            // 손님이 주문을 함
            Order customerOrder = new Order();
            customerOrder.AddItem("Noodles");
            customerOrder.AddItem("Sweet and Sour Pork");
            customer.PlaceOrder(customerOrder, server);

            // 서버가 요리사에게 요리를 요청함
            Food preparedFood = server.RequestFood(cook, customerOrder);

            // 서버가 손님에게 음식을 전달함
            server.DeliverFood(preparedFood, customer);

            // 손님이 결제를 함
            customer.MakePayment(server, 15000);

            // 서버가 식당 주인에게 돈을 전달함
            server.TransferMoney(owner, 15000);

            // 식당 주인이 종업원들에게 월급을 지급함
            owner.PaySalaries(new List<Worker> { cook, server });
        }
    }
}