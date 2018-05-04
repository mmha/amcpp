#include "amcpp/facilities.hpp"
#include <iostream>
#include <iterator>
#include <string>

int main()
{
   using namespace std::string_literals;
   std::cout << "What is your name? ";
   auto name = []{
      if (auto result = ""s; std::cin >> result) {
         return result;
      }

      amcpp::error("Unexpected input.");
   }();

   std::cout << "What is your quest? ";
   auto const quest = []{
      if (auto result = ""s; std::cin >> result) {
         return result;
      }

      amcpp::error("Unexpected input.");
   }();

   std::cout << "String operations:\n"
      "\tConcatenation (name + quest): " << (name + quest) << '\n';

   name.clear(); // erases the contents of name
   std::cout << "\tname.clear(): " << name << '\n';

   std::cout << "\tIs empty: " << std::empty(name) << '\n';

   name = quest; // puts quest into name's box
   std::cout << "\tAssignment (name = quest): " << name << '\n';

   name += quest; // same as `name = name + quest`
   std::cout << "\tCompound concatenation: " << name << '\n';

   constexpr auto position = 4;
   std::cout << "\tFifth character:\n"
      "\t\tname[position]: " << name[position] << "\n"
      "\t\tquest[position]: " << quest[position] << '\n';

   std::cout << "Choose a new letter: ";
   if (!(std::cin >> name[position])) {
      amcpp::error("Unexpected input.");
   }

   std::cout << "\tFifth character:\n"
      "\t\tname[position]: " << name[position] << "\n"
      "\t\tquest[position]: " << quest[position] << '\n';

   std::cout << "\tEqual to (name == quest): " << (name == quest) << "\n" // note: "==" not '='
      "\tNot equal to (name != quest): " << (name != quest) << "\n"
      "\tLess-than (name < quest): " << (name < quest) << "\n"
      "\tLess-than-or-equal-to (name <= quest): " << (name <= quest) << "\n"
      "\tGreater-than-or-equal-to (name >= quest): " << (name >= quest) << "\n"
      "\tGreater-than (name > quest): " << (name > quest) << '\n';
}
