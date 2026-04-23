#pragma once

#include <string>
#include <vector>

#include "timer.h"

namespace tomodoro {

class Parser {
 public:
  std::optional<Timer::Duration> parse(std::string input);

 private:
  std::vector<std::string> split(std::string input, const char delimiter);
};
}  // namespace tomodoro
