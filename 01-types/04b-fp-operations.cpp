#include "amcpp/facilities.hpp"
#include <cmath>
#include <iostream>

int main()
{
   std::cout << "How tall are you? ";
   auto height = []{
      if (auto result = 0.0; std::cin >> result) {
         return result;
      }

      amcpp::error("Unexpected input.");
   }();

   std::cout << "How heavy are you? ";
   auto const weight = []{
      if (auto result = 0.0; std::cin >> result) {
         return result;
      }

      amcpp::error("Unexpected input.");
   }();

   std::cout << "Floating-point operations:\n"
      "\tAddition (height + weight): " << (height + weight) << "\n"
      "\tSubtraction (height - weight): " << (height - weight) << "\n"
      "\tMultiplication (height * weight): " << (height * weight) << "\n"
      "\tDivision (height / weight): " << (height / weight) << "\n"
      "\tInverse (-height): " << -height << "\n"
      "\theight + weight * 4.2: " << (height + weight * 4.2) << "\n"
      "\t(height + weight) * 4.2: " << ((height + weight) * 4.2) << "\n"
      "\tRemainder: " << std::fmod(height, weight) << "\n"
      "\tRound to integer: " << std::rint(weight) << "\n"
      "\tsin(height): " << std::sin(height) << "\n"
      "\tcos(height): " << std::cos(height) << "\n"
      "\tsqrt(height): " << std::sqrt(height) << '\n';

   height = weight; // puts weight into height's box
   std::cout << "\tAssignment (height = weight): " << height << '\n';

   ++height; // same as `height = height + 1.0`
   std::cout << "\tIncrement (++height): " << height << '\n';

   --height; // same as `height = height - 1.0`
   std::cout << "\tDecrement (--height): " << height << '\n';

   height += weight; // same as `height = height + weight`
   std::cout << "\tCompound addition (height += weight): " << height << '\n';

   height -= weight; // same as `height = height - weight`
   std::cout << "\tCompound subtraction (height -= weight): " << height << '\n';

   height *= weight; // same as `height = height * weight`
   std::cout << "\tCompound multiplication (height *= weight): " << height << '\n';

   height /= weight; // same as `height = height / weight`
   std::cout << "\tCompound division (height /= weight): " << height << '\n';

   std::cout << "\tEqual to (height == weight): " << (height == weight) << "\n"
      "\tNot equal to (height != weight): " << (height != weight) << "\n"
      "\tLess-than (height < weight): " << (height < weight) << "\n"
      "\tLess-than-or-equal-to (height <= weight): " << (height <= weight) << "\n"
      "\tGreater-than-or-equal-to (height >= weight): " << (height >= weight) << "\n"
      "\tGreater-than (height > weight): " << (height > weight) << '\n';
}
