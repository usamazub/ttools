#include <cstdio>

#include "libs/parser.h"
#include "libs/timer.h"

using namespace ::tomodoro;

namespace {

constexpr int DEFAULT_HOURS = 0;
constexpr int DEFAULT_MINUTES = 10;
constexpr int DEFAULT_SECONDS = 0;

}  // namespace

int main(int argc, char* argv[]) {
  Parser parser = Parser();
  Timer timer = Timer();
  std::optional<Timer::Duration> duration = std::nullopt;

  if (argc >= 2) {
    duration = parser.parse(argv[1]);
  }

  if (duration.has_value()) {
    timer.run(duration.value());
  } else {
    printf(
        "The input is empty or not correct, it should be H:M:S, M:S, or M."
        "Using default duration instead (%d minutes)).\n",
        DEFAULT_MINUTES);
    fflush(stdout);

    duration = Timer::Duration{.hours = DEFAULT_HOURS,
                               .minutes = DEFAULT_MINUTES,
                               .seconds = DEFAULT_SECONDS};
    timer.run(duration.value());
  }

  return 0;
}
