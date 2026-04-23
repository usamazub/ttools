#include "timer.h"

#include <chrono>
#include <cstdio>
#include <thread>

namespace tomodoro {

void Timer::run(const Duration& duration) {
  int total_seconds =
      duration.hours * 3600 + duration.minutes * 60 + duration.seconds;

  while (total_seconds >= 0) {
    int hours = total_seconds / 3600;
    int minutes = (total_seconds - 3600 * hours) / 60;
    int seconds = total_seconds % 60;

    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (hours >= 100) {
      std::printf("\r%03d:%02d:%02d", hours, minutes, seconds);
    } else {
      std::printf("\r%02d:%02d:%02d", hours, minutes, seconds);
    }
    fflush(stdout);

    --total_seconds;
  }
  printf("\n");

#if defined(__APPLE__)
  std::system("say \"Time's up\"");
#else
  printf("Time's up\n");
#endif
}

}  // namespace tomodoro
