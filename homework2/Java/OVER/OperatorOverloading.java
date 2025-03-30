// 자바에서는 연산자 오버로딩을 지원하지 않음
class OperatorOverloading {
    private double real; // 실수부
    private double imaginary; // 허수부

    // 생성자
    public OperatorOverloading(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    // 두 복소수를 더하는 메서드 (덧셈 연산자 오버로딩처럼 동작)
    public OperatorOverloading add(OperatorOverloading other) {
        return new OperatorOverloading(this.real + other.real, this.imaginary + other.imaginary);
    }

    // 두 복소수를 빼는 메서드 (뺄셈 연산자 오버로딩처럼 동작)
    public OperatorOverloading subtract(OperatorOverloading other) {
        return new OperatorOverloading(this.real - other.real, this.imaginary - other.imaginary);
    }

    // 두 복소수를 곱하는 메서드 (곱셈 연산자 오버로딩처럼 동작)
    public OperatorOverloading multiply(OperatorOverloading other) {
        double newReal = this.real * other.real - this.imaginary * other.imaginary;
        double newImaginary = this.real * other.imaginary + this.imaginary * other.real;
        return new OperatorOverloading(newReal, newImaginary);
    }

    // 두 복소수를 나누는 메서드 (나눗셈 연산자 오버로딩처럼 동작)
    public OperatorOverloading divide(OperatorOverloading other) {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double newReal = (this.real * other.real + this.imaginary * other.imaginary) / denominator;
        double newImaginary = (this.imaginary * other.real - this.real * other.imaginary) / denominator;
        return new OperatorOverloading(newReal, newImaginary);
    }

    // 복소수의 문자열 표현을 반환하는 메서드
    @Override
    public String toString() {
        return String.format("%.2f + %.2fi", real, imaginary);
    }

    // 메인 메서드
    public static void main(String[] args) {
        // 두 복소수 생성
        OperatorOverloading num1 = new OperatorOverloading(4, 5);
        OperatorOverloading num2 = new OperatorOverloading(2, -3);

        System.out.println("첫 번째 복소수: " + num1);
        System.out.println("두 번째 복소수: " + num2);

        // 덧셈
        OperatorOverloading sum = num1.add(num2);
        System.out.println("\n[덧셈]");
        System.out.println(num1 + " + " + num2 + " = " + sum);

        // 뺄셈
        OperatorOverloading difference = num1.subtract(num2);
        System.out.println("\n[뺄셈]");
        System.out.println(num1 + " - " + num2 + " = " + difference);

        // 곱셈
        OperatorOverloading product = num1.multiply(num2);
        System.out.println("\n[곱셈]");
        System.out.println(num1 + " * " + num2 + " = " + product);

        // 나눗셈
        OperatorOverloading quotient = num1.divide(num2);
        System.out.println("\n[나눗셈]");
        System.out.println(num1 + " / " + num2 + " = " + quotient);
    }
}