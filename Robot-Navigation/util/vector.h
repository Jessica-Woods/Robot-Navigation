#pragma once
#include <vector>
#include <string>

namespace util {
  namespace vector {
    // Takes a vector of std::string/s and concats it into one string separated by the separator
    //
    // Example: unsplit(vector("hello", "world", "2"), ":") == "hello:world:2"
    //
    std::string unsplit(std::vector<std::string> vec, std::string separator);
  }
}