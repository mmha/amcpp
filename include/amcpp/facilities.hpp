#ifndef AMCPP_FACILITIES_HPP
#define AMCPP_FACILITIES_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <string_view>

namespace amcpp {
   /// @brief Writes something to the character error stream and exits the program.
   /// @param error_message The message written to the error stream.
   /// @note This function terminates the program.
   ///
   [[noreturn]] void error(std::string_view const error_message) noexcept
   {
      std::cerr << error_message << '\n';
      std::exit(1);
   }

   /// @brief Returns zero with the correct sign and size for the container's size.
   /// @tparam Rng The range to set zero from.
   /// @param rng The object to get the size from.
   ///
   template <typename Rng>
   constexpr auto zero(Rng&& rng) noexcept
   {
      return decltype(std::size(rng)){};
   }

   /// @brief Appropriately handles the character input's state.
   ///
   /// If the input state is eof, goodbit is set, and the input is returned as a T.
   /// If the input state is bad, the program terminates.
   /// If the input state is fail, an exception is thrown.
   ///
   /// @tparam T The type of the object to return.
   /// @param t The object to return.
   /// @return t
   /// @note This function terminates if goodbit or eofbit are not set.
   ///
   template <typename T>
   T handle_failbit(T const& t)
   {
      if (std::cin.eof()) {
         std::cin.clear(std::ios_base::goodbit);
         return t;
      }
      else if (std::cin.bad()) {
         error("Non-recoverable error");
      }
      else if (std::cin.fail()) {
         throw std::runtime_error{"Bad input"};
      }
   }

   /// @brief Used to determine 
   enum class get_input_as {
      line,
      space
   };

   /// @brief Reads input from the character input as a T.
   /// @tparam T The type the of the object the character input should write to.
   /// @tparam get_input_as Used to determine if string input should be delimited by spaces or by
   /// lines.
   /// @return An object of type T, initialised with data from the character input.
   /// @note An exception is thrown if the data is not properly formatted.
   /// @note The program terminates if a non-recoverable error occurs.
   ///
   template <typename T, get_input_as = get_input_as::line>
   T from_cin()
   {
      if (auto t = T{}; std::cin >> t) {
         return t;
      }
      else {
         amcpp::handle_failbit(t);
      }
   }

   /// @brief Reads input from the character input as a std::string, where the input is delimited by
   /// the newline character.
   /// @ref from_cin
   ///
   template <>
   inline std::string from_cin<std::string, get_input_as::line>()
   {
      if (auto s = std::string{}; std::getline(std::cin, s)) {
         return s;
      }
      else {
         amcpp::handle_failbit(s);
      }
   }

   /// @ref See en.cppreference.com/cpp/algorithm/copy
   ///
   template <typename Rng, typename O>
   auto copy(Rng&& rng, O d_first)
   {
      using std::cbegin, std::cend;
      return std::copy(cbegin(rng), cend(rng), d_first);
   }

   /// @ref See en.cppreference.com/cpp/algorithm/copy
   ///
   template <typename Rng, typename O>
   auto copy_n(Rng&& rng, decltype(rng.size()) count, O d_first)
   {
      using std::cbegin;
      return std::copy_n(cbegin(rng), count, d_first);
   }
}

#endif // AMCPP_FACILITIES_HPP
