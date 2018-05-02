#include <iostream>

int main()
{
   int i = 97;
   std::cout << "i == " << i << '\n';
   char c = i;
   std::cout << "c == " << c << '\n';
   i = -927;
   std::cout << "i == " << i << '\n';
   c = i;
   std::cout << "c == " << c << '\n';

   double const d = 42.847;
   std::cout << "d == " << d << '\n';
   i = d;
   std::cout << "i == " << i << '\n';
   c = d;
   std::cout << "c == " << c << '\n';

   bool b = i;
   std::cout << "b == " << b << '\n';
   b = 0;
   std::cout << "b == " << b << '\n';
}
