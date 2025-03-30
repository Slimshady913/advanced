using System;

namespace OperatorOverloadingExample
{
    // 간단한 2D 벡터 클래스 정의
    public class Vector2D
    {
        public double X { get; set; }
        public double Y { get; set; }

        // 생성자
        public Vector2D(double x, double y)
        {
            X = x;
            Y = y;
        }

        // + 연산자 오버로딩 (벡터 덧셈)
        public static Vector2D operator +(Vector2D v1, Vector2D v2)
        {
            return new Vector2D(v1.X + v2.X, v1.Y + v2.Y);
        }

        // - 연산자 오버로딩 (벡터 뺄셈)
        public static Vector2D operator -(Vector2D v1, Vector2D v2)
        {
            return new Vector2D(v1.X - v2.X, v1.Y - v2.Y);
        }

        // * 연산자 오버로딩 (스칼라 곱셈)
        public static Vector2D operator *(Vector2D v, double scalar)
        {
            return new Vector2D(v.X * scalar, v.Y * scalar);
        }

        // / 연산자 오버로딩 (스칼라 나눗셈)
        public static Vector2D operator /(Vector2D v, double scalar)
        {
            if (scalar == 0)
                throw new DivideByZeroException("스칼라 값은 0이 될 수 없습니다.");
            return new Vector2D(v.X / scalar, v.Y / scalar);
        }

        // 벡터를 문자열로 변환 (출력용)
        public override string ToString()
        {
            return $"({X}, {Y})";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // 두 벡터 생성
            Vector2D v1 = new Vector2D(3, 4);
            Vector2D v2 = new Vector2D(1, 2);

            // 연산자 오버로딩 테스트
            Vector2D addition = v1 + v2; // 벡터 덧셈
            Vector2D subtraction = v1 - v2; // 벡터 뺄셈
            Vector2D multiplication = v1 * 2; // 스칼라 곱셈
            Vector2D division = v1 / 2; // 스칼라 나눗셈

            // 결과 출력
            Console.WriteLine($"v1: {v1}");
            Console.WriteLine($"v2: {v2}");
            Console.WriteLine($"덧셈: {v1} + {v2} = {addition}");
            Console.WriteLine($"뺄셈: {v1} - {v2} = {subtraction}");
            Console.WriteLine($"스칼라 곱셈: {v1} * 2 = {multiplication}");
            Console.WriteLine($"스칼라 나눗셈: {v1} / 2 = {division}");
        }
    }
}