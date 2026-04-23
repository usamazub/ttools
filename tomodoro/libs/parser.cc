#include "parser.h"

namespace tomodoro {

std::optional<Timer::Duration> Parser::parse(std::string input) {
  // Currently we only support ':' as delimiter
  std::vector<std::string> inputs = split(input, /*delimiter=*/':');

  if (inputs.size() == 0 || inputs.size() > 3) {
    return std::nullopt;
  }

  // We need to parse 3 kind of inputs
  // 1. HH:MM:SS
  // 2. MM:SS
  // 3. MM
  try {
    int hours = inputs.size() == 3 ? std::stoi(inputs.front()) : 0;
    int minutes =
        inputs.size() == 3 ? std::stoi(inputs[1]) : std::stoi(inputs.front());
    int seconds = inputs.size() > 1 ? std::stoi(inputs.back()) : 0;

    if (hours < 0 || minutes < 0 || seconds < 0) {
      return std::nullopt;
    }

    return Timer::Duration{
        .hours = hours, .minutes = minutes, .seconds = seconds};
  } catch (...) {
    return std::nullopt;
  }
}

std::vector<std::string> Parser::split(std::string input,
                                       const char delimiter) {
  std::vector<std::string> results;

  size_t pos = 0;
  std::string text;

  while ((pos = input.find(delimiter)) != std::string::npos) {
    text = input.substr(0, pos);
    results.push_back(text);
    input.erase(0, pos + 1);
  }

  results.push_back(input);

  return results;
}

}  // namespace tomodoro
