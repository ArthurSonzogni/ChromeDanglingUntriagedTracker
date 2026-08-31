// Copyright 2021 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
//
// This file content was copied from:
// https://github.com/ArthurSonzogni/git-tui

#ifndef CHROME_DANGLING_UNTRIAGED_TRACKER_PARSER_HPP
#define CHROME_DANGLING_UNTRIAGED_TRACKER_PARSER_HPP

#include <functional>
#include <string>
#include <string_view>

struct CommitReport {
  std::string hash;
  std::string timestamp;
  std::string author;
  std::string title;
  int added = 0;
  int removed = 0;
  int added_test = 0;
  int removed_test = 0;

  constexpr bool is_empty() const {
    return added == 0 && removed == 0 && added_test == 0 && removed_test == 0;
  }
};

void TrackDanglingUntriaged(
    std::string_view last_hash,
    const std::function<void(const CommitReport&)>& on_commit);

#endif  // CHROME_DANGLING_UNTRIAGED_TRACKER_PARSER_HPP
