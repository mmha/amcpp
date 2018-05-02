#include "amcpp/facilities.hpp"
#include <iostream>
#include <string>

int main()
{
   std::cout << "What is your name? ";
   using namespace std::string_literals;
   if (auto name = ""s; std::cin >> name) {
      std::cout << "Hello, " << name << "!\n";
   }
   else {
      amcpp::error("Unable to process input.");
   }

   std::cout << "How old are you? ";
   if (auto age = 0; std::cin >> age) {
      std::cout << "You are " << age << " years old\n";
   }
   else {
      amcpp::error("Unable to process input.");
   }

   std::cout << "How tall are you? ";
   if (auto height = 0.0; std::cin >> height) {
      std::cout << "You are " << height << "cm tall.\n";
   }
   else {
      amcpp::error("Unable to process input.");
   }

   std::cout << "Are you having fun? (1 for 'yes', 0 for 'no'): ";
   if (auto fun = false; std::cin >> fun) {
      std::cout << "You said that you are having fun: " << fun << '\n';
   }
   else {
      amcpp::error("Unable to process input.");
   }

   std::cout << "What is your favourite letter? ";
   if (auto letter = '\0'; std::cin >> letter) {
      std::cout << "Your favourite letter is '" << letter << "'.\n";
   }
   else {
      amcpp::error("Unable to process input.");
   }
}
