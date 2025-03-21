#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 주문 클래스
class Order {
private:
    vector<string> items; // 주문 항목들

public:
    void addItem(const string& item) {
        // 주문 항목 추가
        items.push_back(item);
    }

    vector<string> getItems() const {
        // 주문 항목 가져오기
        return items;
    }
};

// 음식 클래스
class Food {
private:
    vector<string> items; // 음식 항목들

public:
    void addItem(const string& item) {
        // 음식 항목 추가
        items.push_back(item);
    }

    vector<string> getItems() const {
        // 음식 항목 가져오기
        return items;
    }
};

// 추상 종업원 클래스
class Worker {
protected:
    string name; // 이름
    float salary; // 월급

public:
    Worker(const string& name, float salary) : name(name), salary(salary) {}

    virtual ~Worker() {}

    virtual void receiveSalary(float amount) {
        // 월급 받기
        cout << name << "이(가) " << amount << "원의 월급을 받았습니다." << endl;
    }

    float getSalary() const {
        return salary;
    }

    string getName() const {
        return name;
    }
};

// 식당 주인 클래스
class RestaurantOwner {
private:
    float assets; // 자산

public:
    RestaurantOwner() : assets(0.0f) {}

    void receiveMoney(float amount) {
        // 돈 받기
        assets += amount;
        cout << "식당 주인이 " << amount << "원을 받았습니다. 현재 자산: " << assets << endl;
    }

    void paySalaries(const vector<Worker*>& workers) {
        // 종업원들에게 월급 지급
        for (Worker* worker : workers) {
            worker->receiveSalary(worker->getSalary());
            assets -= worker->getSalary();
        }
        cout << "모든 종업원들에게 월급을 지급했습니다. 남은 자산: " << assets << endl;
    }
};

// 요리 담당 클래스
class Cook : public Worker {
public:
    Cook(const string& name, float salary) : Worker(name, salary) {}

    Food prepareFood(const Order& order) {
        // 요리 준비
        Food food;
        for (const string& item : order.getItems()) {
            food.addItem(item);
        }
        cout << name << "이(가) 요리를 준비했습니다: ";
        for (const string& item : food.getItems()) {
            cout << item << " ";
        }
        cout << endl;
        return food;
    }
};

// 서빙 담당 클래스
class Server : public Worker {
public:
    Server(const string& name, float salary) : Worker(name, salary) {}

    Order takeOrder(const string& customerName) {
        // 주문 받기
        cout << name << "이(가) " << customerName << "의 주문을 받았습니다." << endl;
        return Order();
    }

    void deliverFood(const Food& food, const string& customerName) {
        // 음식 전달
        cout << name << "이(가) " << customerName << "에게 음식을 전달했습니다: ";
        for (const string& item : food.getItems()) {
            cout << item << " ";
        }
        cout << endl;
    }

    float receivePayment(const string& customerName, float amount) {
        // 결제 받기
        cout << name << "이(가) " << customerName << "에게서 " << amount << "원을 받았습니다." << endl;
        return amount;
    }

    Food requestFood(Cook& cook, const Order& order) {
        // 요리 요청
        cout << name << "이(가) " << cook.getName() << "에게 요리를 요청했습니다." << endl;
        return cook.prepareFood(order);
    }

    void transferMoney(RestaurantOwner& owner, float amount) {
        // 돈 전달
        owner.receiveMoney(amount); // 식당 주인에게 돈 전달
        cout << name << "이(가) 식당 주인에게 " << amount << "원을 전달했습니다." << endl;
    }
};

// 손님 클래스
class Customer {
private:
    string name; // 이름
    float money; // 소지금
    Order order; // 주문

public:
    Customer(const string& name, float money) : name(name), money(money) {}

    void placeOrder(Order& order, Server& server) {
        // 주문하기
        this->order = order;
        cout << name << "이(가) " << server.getName() << "에게 주문을 했습니다." << endl;
    }

    void makePayment(Server& server, float amount) {
        // 결제하기
        if (money >= amount) {
            money -= amount;
            cout << name << "이(가) " << server.getName() << "에게 " << amount << "원을 결제했습니다. 남은 소지금: " << money << endl;
        } else {
            cout << name << "이(가) " << amount << "원을 결제할 충분한 돈이 없습니다." << endl;
        }
    }

    string getName() const {
        return name;
    }

    Order getOrder() const {
        return order;
    }
};

// 식당 클래스
class Restaurant {
private:
    vector<Worker*> workers; // 종업원 목록
    vector<Customer*> customers; // 손님 목록

public:
    void addCustomer(Customer* customer) {
        // 손님 추가
        customers.push_back(customer);
    }

    void addWorker(Worker* worker) {
        // 종업원 추가
        workers.push_back(worker);
    }

    vector<Worker*> getWorkers() const {
        return workers;
    }
};

// 메인 함수
int main() {
    // 객체 생성
    RestaurantOwner owner;
    Restaurant restaurant;
    Cook cook("Chef", 3000);
    Server server("Waiter", 2000);
    Customer customer("Customer1", 100000);

    // 식당에 종업원과 손님 추가
    restaurant.addWorker(&cook);
    restaurant.addWorker(&server);
    restaurant.addCustomer(&customer);

    // 손님이 주문을 함
    Order customerOrder;
    customerOrder.addItem("Noodles");
    customerOrder.addItem("Sweet and Sour Pork");
    customer.placeOrder(customerOrder, server);

    // 서버가 요리사에게 요리를 요청함
    Food preparedFood = server.requestFood(cook, customerOrder);

    // 서버가 손님에게 음식을 전달함
    server.deliverFood(preparedFood, customer.getName());

    // 손님이 결제를 함
    customer.makePayment(server, 15000);

    // 서버가 식당 주인에게 돈을 전달함
    server.transferMoney(owner, 15000);

    // 식당 주인이 종업원들에게 월급을 지급함
    owner.paySalaries(restaurant.getWorkers());

    return 0;
}