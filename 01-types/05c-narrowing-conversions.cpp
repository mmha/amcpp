#include <gsl/gsl>
#include <iostream>

int main()
{
   auto i = 97;
   std::cout << "i == " << i << '\n';
   auto c = gsl::narrow_cast<char>(i);
   std::cout << "c == " << c << '\n';
   i = -927;
   std::cout << "i == " << i << '\n';
   c = gsl::narrow_cast<char>(i);
   std::cout << "c == " << c << '\n';

   auto const d = 42.847;
   std::cout << "d == " << d << '\n';
   i = gsl::narrow_cast<int>(d);
   std::cout << "i == " << i << '\n';
   c = gsl::narrow_cast<char>(d);
   std::cout << "c == " << c << '\n';

   auto b = gsl::narrow_cast<bool>(i);
   std::cout << "b == " << b << '\n';
   b = gsl::narrow_cast<bool>(0);
   std::cout << "b == " << b << '\n';
}
