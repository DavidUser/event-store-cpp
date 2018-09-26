#pragma once

#include <map>
#include <unordered_map>
#include <mutex>
#include <set>
#include "event.h"
#include "event_iterator.h"

namespace challenge {

using std::string;

class EventStore {
 public:
  friend class EventIterator;

  virtual ~EventStore() = default;

  void Insert(Event&&);
  void RemoveAll(const string& type);
  EventIterator Query(const string& type, const long& start, const long& end);

 private:
  std::unordered_map<std::string, std::map<long, Event>> storage;
  std::map<std::string, std::mutex> type_lock;
};

}  // namespace challenge
