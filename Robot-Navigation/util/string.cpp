#include "string.h"
#include <tuple>
#include <algorithm>

std::vector<std::string> util::string::split(std::string str, char separator) {
  std::vector<std::string> result;
  std::string chunk = "";

  for (char c : str) {
    if (c != separator) {
      chunk.push_back(c);
    } else {
      result.push_back(chunk);
      chunk.clear();
    }
  }

  result.push_back(chunk);
  return result;
}

std::tuple<std::string, std::string> util::string::split_first(std::string str, std::string separator) {
  auto separatorIndex = str.find(separator);
  if (separatorIndex != std::string::npos) {
    auto startIndex = separatorIndex > 0 ? separatorIndex : 0;
    auto endIndex = separatorIndex + separator.length();

    auto firstChunk = str.substr(0, startIndex);
    auto secondChunk = str.substr(endIndex);

    return std::make_tuple(firstChunk, secondChunk);
  } else {
    return std::make_tuple(str, "");
  }
}

// trim from start (in place)
void util::string::ltrim(std::string& s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
    return !std::isspace(ch);
    }));
}

// trim from end (in place)
void util::string::rtrim(std::string& s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
    return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
std::string& util::string::trim(std::string& s) {
  util::string::ltrim(s);
  util::string::rtrim(s);
  return s;
}

// reads and cleans all input
std::string util::string::readInput() {
  std::string s;
  std::string result;
  std::getline(std::cin, s);
  for (auto cha : s) {
    result += std::tolower(cha);
  }

  return result;
}

std::vector<int> util::string::numbers(std::string s) {
  std::vector<int> result;
  std::string digits = "";

  for (char c : s) {
    if (isdigit(c)) {
      digits.push_back(c);
    }
    else if(digits != "") {
      result.push_back(std::stoi(digits));
      digits.clear();
    }
  }

  if(digits != "") { result.push_back(std::stoi(digits)); }
  return result;
}