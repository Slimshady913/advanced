// tuple example
#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore

int main ()
{
    std::tuple<int,char> foo (10,'x');
    auto bar = std::make_tuple ("test", 3.1, 14, 'y');

    std::cout << "Initial foo: (" << std::get<0>(foo) << ", " << std::get<1>(foo) << ")\n";
    std::cout << "Initial bar: (\"" << std::get<0>(bar) << "\", " << std::get<1>(bar) 
                        << ", " << std::get<2>(bar) << ", " << std::get<3>(bar) << ")\n";

    std::get<2>(bar) = 100;  // access element
    std::cout << "After modifying bar[2]: (\"" << std::get<0>(bar) << "\", " 
                        << std::get<1>(bar) << ", " << std::get<2>(bar) << ", " 
                        << std::get<3>(bar) << ")\n";

    int myint; char mychar;

    std::tie (myint, mychar) = foo;  // unpack elements
    std::cout << "Unpacked foo into myint: " << myint << ", mychar: " << mychar << "\n";

    std::tie (std::ignore, std::ignore, myint, mychar) = bar;  // unpack (with ignore)
    std::cout << "Unpacked bar into myint: " << myint << ", mychar: " << mychar << "\n";

    mychar = std::get<3>(bar);
    std::cout << "Updated mychar from bar[3]: " << mychar << "\n";

    std::get<0>(foo) = std::get<2>(bar);
    std::get<1>(foo) = mychar;
    std::cout << "Updated foo: (" << std::get<0>(foo) << ", " << std::get<1>(foo) << ")\n";

    std::cout << "foo contains: ";
    std::cout << std::get<0>(foo) << ' ';
    std::cout << std::get<1>(foo) << '\n';

    return 0;
}