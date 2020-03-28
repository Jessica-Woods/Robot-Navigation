#pragma once
#include <string>
#include <vector>
#include <chrono>

namespace util {
  namespace time { 
    std::chrono::system_clock::time_point fromString(
      std::string s,
      std::string fmt = "%Y-%m-%d %H:%M:%S"
    );

    std::string toString(
      std::chrono::system_clock::time_point t,
      std::string fmt = "%F %T"
    );
  }
}