#include "string_utils.hpp"

#include <string>
#include <algorithm> 
#include <cctype>

namespace utils {
    // Remove spaces and remove special characters from a string
    std::string remove_spaces_special_chars(std::string& s) {
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !std::isalnum(c);
        }),
        s.end());
    }

    // Convert string into array of characters
    std::vector<char> s_arr (std::string& s) {

    }
}