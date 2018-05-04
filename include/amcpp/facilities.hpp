#ifndef AMCPP_FACILITIES_HPP
#define AMCPP_FACILITIES_HPP

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <string_view>

namespace amcpp {
   /// @brief Writes something to the character error stream and exits the program.
   /// @param error_message The message written to the error stream.
   /// @note This function terminates the program.
   ///
   [[noreturn]] void error(std::string_view const error_message) noexcept // TODO(cjdb): move this to a source file
   {
      std::cerr << error_message << '\n';
      std::exit(EXIT_FAILURE);
   }

   /// @brief Returns zero with the correct sign and size for the container's size.
   /// @tparam Rng The range to set zero from.
   /// @param rng The object to get the size from.
   ///
   template <typename Rng>
   [[nodiscard]] constexpr auto zero(Rng&& rng) noexcept
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
   void handle_failbit() // TODO(cjdb): move this to a source file.
   {
      if (std::cin.eof()) {
         std::cin.clear(std::ios_base::goodbit);
      }
      else if (std::cin.bad()) {
         error("Non-recoverable error");
      }
      else if (std::cin.fail()) {
         throw std::runtime_error{"Bad input"};
      }
   }

   /// @brief Used to determine whether getline should be used, or if the get-from operator is
   ///        preferred.
   enum class get_input_as {
      line,
      space
   };

   /// @brief Determines if T is a string type or not.
   /// @tparam T The type to inspect.
   /// @return true if T is a string type, false otherwise.
   ///
   template <typename T>
   constexpr auto is_string_v = false;

   /// @brief Specialisation for is_string_v for std::basic_string types.
   ///
   /// Always returns true.
   /// @tparam Char The string's character type.
   /// @tparam Traits The string's traits type.
   /// @ref See is_string_v.
   ///
   template <typename Char, typename Traits>
   constexpr auto is_string_v<std::basic_string<Char, Traits>> = true;

   /// @brief Reads input from the character input as a T.
   /// @tparam T The type the of the object the character input should write to.
   /// @tparam get_input_as Used to determine if string input should be delimited by spaces or by
   ///                      lines. Ignored if T is not a string type.
   /// @return An object of type T, initialised with data from the character input.
   /// @note An exception is thrown if the data is not properly formatted.
   /// @note The program terminates if a non-recoverable error occurs.
   ///
   template <typename T, get_input_as type = get_input_as::line>
   [[nodiscard]] T from_cin()
   {
      auto t = T{};
      if constexpr (is_string_v<T> && type == get_input_as::line) {
         std::getline(std::cin, t);
      }
      else {
         std::cin >> t;
      }

      if (not std::cin) {
         handle_failbit();
      }

      return t;
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
