public class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void walk() {
        System.out.println(name + " is walking.");
    }

    public void run() {
        System.out.println(name + " is running.");
    }

    @Override
    protected void finalize() throws Throwable {
        System.out.println(name + " has been deleted.");
        super.finalize();
    }

    public static void main(String[] args) {
        Person p = new Person("철수", 20);
        p.walk();
        p.run();
        p = null; // Dereference the object
        System.gc(); // Suggest garbage collection

        // Overriding print function behavior
        System.out.println("print 함수가 삭제되었습니다.");
    }
}