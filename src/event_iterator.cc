#include "../include/event_iterator.h"
#include <iostream>

namespace challenge {

bool EventIterator::moveNext() const {
  if (!current_it) return (current_it = begin) != end;
  return ++current_it.value() != end;
}

Event& EventIterator::current() const {
  return current_it.value()->second;
}

void EventIterator::remove() {
  std::lock_guard<std::mutex> type_lock(lock);
  if (current_it != end) current_it = store.erase(*current_it);
  --*current_it;
}

}  // namespace challenge
