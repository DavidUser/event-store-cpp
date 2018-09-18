#include <iterator>
#include "event_store.h"

namespace challenge {

class EventIterator : public std::iterator_traits<Event> {
 public:
  EventIterator(EventStore&);
  virtual ~EventIterator() = default;

  void remove();

 private:
  EventStore& store;
};

}  // namespace challenge
