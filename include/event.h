#pragma once

#include <string>

namespace challenge {

struct Event {
  std::string type;
  long timestamp = -1;
};

}  // namespace challenge
