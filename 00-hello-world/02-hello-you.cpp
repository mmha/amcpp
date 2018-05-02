#include <iostream>
#include <string>

int main()
{
   using namespace std::string_literals;
   auto name = ""s;

   std::cout << "What is your name? ";
   std::cin >> name;

   std::cout << "Hello, " << name << "!\n";
}
