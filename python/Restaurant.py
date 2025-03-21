from typing import List

class Restaurant:
    def __init__(self):
        self.workers: List['Worker'] = []  # 종업원 목록
        self.customers: List['Customer'] = []  # 손님 목록

    def add_customer(self, customer: 'Customer') -> None:
        # 손님 추가
        self.customers.append(customer)

    def add_worker(self, worker: 'Worker') -> None:
        # 종업원 추가
        self.workers.append(worker)


class RestaurantOwner:
    def __init__(self):
        self.assets: float = 0.0  # 자산

    def receive_money(self, amount: float) -> None:
        # 돈 받기
        self.assets += amount
        print(f"식당 주인이 {amount}원을 받았습니다. 현재 자산: {self.assets}")

    def pay_salaries(self, workers: List['Worker']) -> None:
        # 종업원들에게 월급 지급
        for worker in workers:
            worker.receive_salary(worker.salary)
            self.assets -= worker.salary
        print(f"모든 종업원들에게 월급을 지급했습니다. 남은 자산: {self.assets}")


class Worker:
    def __init__(self, name: str, salary: float):
        self.name = name  # 이름
        self.salary = salary  # 월급

    def receive_salary(self, amount: float) -> None:
        # 월급 받기
        print(f"{self.name}이(가) {amount}원의 월급을 받았습니다.")


class Cook(Worker):
    def prepare_food(self, order: 'Order') -> 'Food':
        # 요리 준비
        food = Food()
        for item in order.get_items():
            food.add_item(item)
        print(f"{self.name}이(가) 요리를 준비했습니다: {food.get_items()}")
        return food


class Server(Worker):
    def take_order(self, customer: 'Customer') -> 'Order':
        # 주문 받기
        print(f"{self.name}이(가) {customer.name}의 주문을 받았습니다.")
        return customer.order

    def deliver_food(self, food: 'Food', customer: 'Customer') -> None:
        # 음식 전달
        print(f"{self.name}이(가) {customer.name}에게 음식을 전달했습니다: {food.get_items()}")

    def receive_payment(self, customer: 'Customer') -> float:
        # 결제 받기
        amount = customer.payment_amount
        print(f"{self.name}이(가) {customer.name}에게서 {amount}원을 받았습니다.")
        return amount

    def request_food(self, cook: 'Cook', order: 'Order') -> 'Food':
        # 요리 요청
        print(f"{self.name}이(가) {cook.name}에게 요리를 요청했습니다.")
        return cook.prepare_food(order)

    def transfer_money(self, owner: 'RestaurantOwner', amount: float) -> None:
        # 돈 전달
        owner.receive_money(amount)
        print(f"{self.name}이(가) 식당 주인에게 {amount}원을 전달했습니다.")


class Customer:
    def __init__(self, name: str, money: float = 100000):
        self.name = name  # 이름
        self.money = money  # 소지금
        self.order: Order = Order()  # 주문
        self.payment_amount: float = 0.0  # 결제 금액

    def place_order(self, order: 'Order', server: 'Server') -> None:
        # 주문하기
        self.order = order
        print(f"{self.name}이(가) {server.name}에게 주문을 했습니다.")

    def make_payment(self, server: 'Server', amount: float) -> None:
        # 결제하기
        if self.money >= amount:
            self.money -= amount
            self.payment_amount = amount
            print(f"{self.name}이(가) {server.name}에게 {amount}원을 결제했습니다. 남은 소지금: {self.money}")
        else:
            print(f"{self.name}이(가) {amount}원을 결제할 충분한 돈이 없습니다.")


class Order:
    def __init__(self):
        self.items: List[str] = []  # 주문 항목들

    def add_item(self, item: str) -> None:
        # 주문 항목 추가
        self.items.append(item)

    def get_items(self) -> List[str]:
        # 주문 항목 가져오기
        return self.items


class Food:
    def __init__(self):
        self.items: List[str] = []  # 음식 항목들

    def add_item(self, item: str) -> None:
        # 음식 항목 추가
        self.items.append(item)

    def get_items(self) -> List[str]:
        # 음식 항목 가져오기
        return self.items


# 테스트 코드
if __name__ == "__main__":
    # 객체 생성
    owner = RestaurantOwner()
    restaurant = Restaurant()
    cook = Cook("Chef", 3000)
    server = Server("Waiter", 2000)
    customer = Customer("Customer1", 100000)

    # 식당에 종업원과 손님 추가
    restaurant.add_worker(cook)
    restaurant.add_worker(server)
    restaurant.add_customer(customer)

    # 손님이 주문을 함
    customer_order = Order()
    customer_order.add_item("Noodles")
    customer_order.add_item("Sweet and Sour Pork")
    customer.place_order(customer_order, server)

    # 서버가 요리사에게 요리를 요청함
    prepared_food = server.request_food(cook, customer_order)

    # 서버가 손님에게 음식을 전달함
    server.deliver_food(prepared_food, customer)

    # 손님이 결제를 함
    customer.make_payment(server, 15000)

    # 서버가 식당 주인에게 돈을 전달함
    server.transfer_money(owner, 15000)

    # 식당 주인이 종업원들에게 월급을 지급함
    owner.pay_salaries(restaurant.workers)