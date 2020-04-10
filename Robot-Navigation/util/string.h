#pragma once
#include <vector>
#include <string>
#include <iostream>

namespace util {
  namespace string {
    // Split a string by the separator and return the chunks
    //
    // Example: split("hello:world:2", ':') == vector("hello", "world", "2")
    //
    std::vector<std::string> split(std::string str, char separator);

    // Remove all leading and trailing whitespace from a string
    //
    // Example: trim("  this is my string   ") == "this is my string"
    //
    // Solution from: https://stackoverflow.com/a/217605
    std::string& trim(std::string& s);

    // Remove all leading whitespace from a string
    //
    // Example: trim("  this is my string   ") == "this is my string   "
    //
    // Solution from: https://stackoverflow.com/a/217605
    void ltrim(std::string& s);

    // Remove all leading whitespace from a string
    //
    // Example: trim("  this is my string   ") == "  this is my string"
    //
    // Solution from: https://stackoverflow.com/a/217605
    void rtrim(std::string& s);

    std::string readInput();

    std::tuple<std::string, std::string> split_first(std::string str, std::string separator);
    
    std::vector<int> numbers(std::string s);
  }
}