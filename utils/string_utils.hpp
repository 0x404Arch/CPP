#pragma once

#include <string>
#include <vector>

namespace utils {
    // Remove spaces and remove special characters from a string
    std::string remove_spaces_special_chars(std::string& s);

    // Convert string into array of characters
    std::vector<char> s_arr (std::string& s);
}