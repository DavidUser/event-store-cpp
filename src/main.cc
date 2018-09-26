#include <iostream>
#include <mutex>
#include <thread>
#include "../include/event_store.h"

namespace challenge {

std::ostream& operator<<(std::ostream& out, const Event& event) {
  return std::cout << event.type << " at " << event.timestamp << " epoch time.";
}

}  // namespace challenge

int main(void) {
  std::cout << "This is the event store challenge written in modern C++"
            << std::endl;

  using namespace challenge;

  const auto magnitude = 1;

  EventStore store;

  for (long timestamp = 1; timestamp < 10 * magnitude; ++timestamp)
    store.Insert({"break", timestamp});

  for (long timestamp = 5 * magnitude; timestamp < 15 * magnitude; ++timestamp)
    store.Insert({"start", timestamp});

  std::cout << "Removing the even elements on: " << std::endl;
  std::thread remove_even([&store]() {
    EventIterator middle_even = store.Query("break", 3 * magnitude, 7 * magnitude);
    while (middle_even.moveNext()) {
      std::cout << middle_even.current() << std::endl;
      if (middle_even.current().timestamp % 2 == 0) middle_even.remove();
    }
  });

  std::thread list_all([&store]() {
    EventIterator rest = store.Query("break", 0, 10 * magnitude);
    while (rest.moveNext()) std::cout << "rest " << rest.current() << std::endl;
    store.RemoveAll("break");
  });


  std::thread list_all_start([&store]() {
    EventIterator rest = store.Query("start", 0, 10 * magnitude);
    while (rest.moveNext()) std::cout << "rest " << rest.current() << std::endl;
  });

  remove_even.join();
  list_all.join();
  list_all_start.join();

  return 0;
}
