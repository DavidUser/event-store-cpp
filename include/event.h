#include <chrono>
#include <string>

namespace challenge {

struct Event {
  std::string type;
  std::chrono::system_clock::time_point timestamp;
};

}  // namespace challenge
