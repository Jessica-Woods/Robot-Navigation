#pragma once
#include <map>
#include <functional>
#include <set>

namespace util {
  namespace map {
    // Split a string by the separator and return the chunks
    //
    // Example: split("hello:world:2", ':') == vector("hello", "world", "2")
    //
    template <typename K, typename V1, typename V2>
    bool intersecting(const std::map<K, V1>& a, const std::map<K, V2>& b);

    template<class T>
    bool map_intersect(std::set<T> a, std::set<T> b);
  }
}