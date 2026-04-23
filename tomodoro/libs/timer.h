#pragma once

namespace tomodoro {

class Timer {
 public:
  struct Duration {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
  };

  void run(const Duration& duration);
};

}  // namespace tomodoro
