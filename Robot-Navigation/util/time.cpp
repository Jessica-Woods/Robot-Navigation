#include "time.h"
#include <sstream>
#include <iomanip>
#include <ctime>


std::chrono::system_clock::time_point util::time::fromString(
  std::string s, 
  std::string fmt
) {
  struct std::tm tm;
  std::istringstream ss(s);
  ss >> std::get_time(&tm, fmt.c_str());
  std::time_t time = mktime(&tm);
  return std::chrono::system_clock::from_time_t(time);
}

std::string util::time::toString(
  std::chrono::system_clock::time_point t,
  std::string fmt
) {
  std::time_t time = std::chrono::system_clock::to_time_t(t);
  std::tm bt{};
  localtime_s(&bt, &time);
  char buf[64];
  return { buf, std::strftime(buf, sizeof(buf), fmt.c_str(), &bt) };
}
