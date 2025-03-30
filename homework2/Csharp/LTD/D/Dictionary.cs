using System;
using System.Collections.Generic;

namespace LTD.D
{
    class DictionaryExample
    {
        static void Main(string[] args)
        {
            // Dictionary 선언
            Dictionary<int, string> students = new Dictionary<int, string>();

            // 데이터 추가
            students.Add(1, "Alice");
            students.Add(2, "Bob");
            students.Add(3, "Charlie");

            // 데이터 출력
            Console.WriteLine("학생 목록:");
            foreach (var student in students)
            {
                Console.WriteLine($"ID: {student.Key}, Name: {student.Value}");
            }

            // 특정 키로 값 검색
            if (students.TryGetValue(2, out string name))
            {
                Console.WriteLine($"\nID 2의 학생 이름: {name}");
            }

            // 데이터 삭제
            students.Remove(3);
            Console.WriteLine("\nID 3 삭제 후 학생 목록:");
            foreach (var student in students)
            {
                Console.WriteLine($"ID: {student.Key}, Name: {student.Value}");
            }
        }
    }
}