#pragma once
#include "map.h"

// Split a string by the separator and return the chunks
//
// Example: split("hello:world:2", ':') == vector("hello", "world", "2")
//
template <typename K, typename V1, typename V2>
bool util::map::intersecting(const std::map<K, V1>& a, const std::map<K, V2>& b) {
  for (auto pair : a) {
    if (b.find(pair.first) != b.end()) {
      return true;
    }
  }

  return false;
}

template<class T>
bool util::map::map_intersect(std::set<T> a, std::set<T> b) {
  auto first1 = a.begin();
  auto last1 = a.end();
  auto first2 = a.begin();
  auto last2 = a.end();

  while (first1 != last1 && first2 != last2) {
    if (*first1 < *first2) {
      ++first1;
      continue;
    }
    if (*first2 < *first1) {
      ++first2;
      continue;
    }
    return true;
  }
  return false;
}