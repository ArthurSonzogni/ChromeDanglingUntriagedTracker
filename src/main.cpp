#include <iostream>
#include <string_view>
#include "parser.hpp"

int main(int argument_count, char** argument_values) {
  const std::string_view last_hash =
      (argument_count > 1) ? argument_values[1] : "";

  TrackDanglingUntriaged(last_hash, [](const CommitReport& commit) {
    std::cout << commit.timestamp << "\t"
              << commit.hash << "\t"
              << commit.added << "\t"
              << commit.removed << "\t"
              << commit.added_test << "\t"
              << commit.removed_test << "\t"
              << commit.author << "\t"
              << commit.title << "\n";
  });

  return 0;
}
