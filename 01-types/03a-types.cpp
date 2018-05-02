#include <iostream>
#include <string>

int main()
{
   std::cout << "What is your name? ";
   using namespace std::string_literals;
   auto name = ""s;
   std::cin >> name;
   std::cout << "Hello, " << name << "!";

   std::cout << "How old are you? ";
   auto age = 0;
   std::cin >> age;
   std::cout << " You are " << age << " years old,";

   std::cout << "How tall are you? ";
   auto height = 0.0;
   std::cin >> height;
   std::cout << " and are " << height << "cm tall.\n";

   std::cout << "Are you having fun? (1 for 'yes', 0 for 'no'): ";
   auto fun = false;
   std::cin >> fun;
   std::cout << "You said that you are having fun: " << fun << ',';

   std::cout << "What is your favourite letter? ";
   auto letter = '\0';
   std::cin >> letter;
   std::cout << " and that your favourite letter is '" << letter << "'.\n";
}
