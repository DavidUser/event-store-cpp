#pragma once

#include <atomic>
#include <iterator>
#include <map>
#include <mutex>
#include <optional>
#include "event.h"

namespace challenge {

class EventIterator {
 public:
  EventIterator(std::map<long, Event>& store,
                std::map<long, Event>::iterator begin,
                std::map<long, Event>::iterator end, std::mutex& lock)
      : store(store), begin(begin), end(end), lock(lock) {}
  virtual ~EventIterator() = default;

  bool moveNext() const;
  Event& current() const;
  void remove();

 private:
  std::map<long, Event>& store;
  const std::map<long, Event>::iterator begin, end;
  mutable std::optional<std::map<long, Event>::iterator> current_it;
  std::mutex& lock;
};

}  // namespace challenge
