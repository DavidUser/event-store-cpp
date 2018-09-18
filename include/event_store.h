#pragma once

#include <chrono>
#include <iterator>
#include "event.h"

namespace challenge {

using std::chrono::system_clock;
using std::string;

class EventStore {
 public:
  EventStore() = default;
  virtual ~EventStore() = default;

  void Insert(Event&&);
  void RemoveAll(const string& type);
  EventIterator Query(const string& type,
                                    const system_clock::time_point& start,
                                    const system_clock::time_point& end);
};

}  // namespace challenge
