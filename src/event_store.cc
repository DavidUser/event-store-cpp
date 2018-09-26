#include "../include/event_store.h"
#include <iostream>

namespace challenge {

void EventStore::Insert(Event&& event) {
  this->storage[event.type].emplace(event.timestamp, event);
}

void EventStore::RemoveAll(const string& type) {
  std::lock_guard<std::mutex> lock(type_lock[type]);
  this->storage.erase(type);
}

EventIterator EventStore::Query(const string& type, const long& start,
                                const long& end) {
  auto& events = this->storage[type];
  return {events, events.lower_bound(start), events.upper_bound(end),
          type_lock[type]};
}

}  // namespace challenge
