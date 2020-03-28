#include "vector.h"

std::string util::vector::unsplit(std::vector<std::string> vec, std::string separator) {
  if(vec.empty()) { return ""; }

  std::string result;
  
  for (auto it = vec.begin(); it != vec.end() - 1; ++it) {
    result += *it;
    result += separator;
  }

  // Append the last element without a separator
  result += *(vec.end() - 1);

  return result;
}
