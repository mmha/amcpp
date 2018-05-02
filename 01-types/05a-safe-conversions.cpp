#include <iostream>

int main()
{
   bool const b = true;
   std::cout << "b == " << b << '\n';
   char c = b;
   std::cout << "c == " << c << '\n';
   int i = b;
   std::cout << "i == " << i << '\n';
   double d = b;
   std::cout << "d == " << d << '\n';

   c = 'a';
   std::cout << "c == " << c << '\n';
   i = c;
   std::cout << "i == " << i << '\n';
   d = c;
   std::cout << "d == " << d << '\n';

   i = 42;
   std::cout << "i == " << i << '\n';
   d = i;
   std::cout << "d == " << d << '\n';
}
