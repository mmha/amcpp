#include "amcpp/facilities.hpp"
#include <iostream>

int main()
{
   std::cout << "What year is it? ";
   auto year = []{                                 // This is a way to initialise our variable
      if (auto result = 0; std::cin >> result) {   // without accidentally making it usable before
         return result;                            // it has the data that we want in it.
      }                                            //
                                                   // You will understand nearly everything in this
      amcpp::error("Unexpected input.");           // block by the end of 02-computation, and the
   }();                                            // rest by 05-calculator-project at the latest.

   std::cout << "How old are you? ";
   auto const age = []{
      if (auto result = 0; std::cin >> result) {
         return result;
      }

      amcpp::error("Unexpected input.");
   }();

   std::cout << "Integral operations:\n"
      "\tAddition (year + age): " << (year + age) << "\n"
      "\tSubtraction (year - age): " << (year - age) << "\n"
      "\tMultiplication (year * age): " << (year * age) << "\n"
      "\tIntegral division (year / age): " << (year / age) << "\n"
      "\tIntegral remainder (year % age): " << (year % age) << "\n"
      "\tInvert (-year): " << -year << "\n"
      "\tyear + age * 3: " << (year + age * 3) << "\n"
      "\t(year + age) * 3: " << ((year + age) * 3) << '\n';

   year = age; // puts age into year's box
   std::cout << "\tAssignment (year = age): " << year << '\n';

   ++year; // same as `year = year + 1`
   std::cout << "\tIncrement (++year): " << year << '\n';

   --year; // same as `year = year - 1`
   std::cout << "\tDecrement (--year): " << year << '\n';

   year += age; // same as `year = year + age`
   std::cout << "\tCompound addition (year += age): " << year << '\n';

   year -= age; // same as `year = year - age`
   std::cout << "\tCompound subtraction (year -= age): " << year << '\n';

   year *= age; // same as `year = year * age`
   std::cout << "\tCompound multiplication (year *= age): " << year << '\n';

   year /= age; // same as `year = year / age`
   std::cout << "\tCompound integral division (year /= age): " << year << '\n';

   year %= age; // same as `year = year % age`
   std::cout << "\tCompound integral modulo (year %= age): " << year << '\n';

   std::cout << "\tEqual to (year == age): " << (year == age) << "\n" // note: "==" not '='
      "\tNot equal to (year != age): " << (year != age) << "\n"
      "\tLess-than (year < age): " << (year < age) << "\n"
      "\tLess-than-or-equal-to (year <= age): " << (year <= age) << "\n"
      "\tGreater-than-or-equal-to (year >= age): " << (year >= age) << "\n"
      "\tGreater-than (year > age): " << (year > age) << '\n';
}
