#pragma once

#include <random>
#include <map>
#include <string>
#include <ostream>
#include <sstream>

/// @return a random value in [lo, hi].
/// Uses std::default_random_engine.
/// Coding skill: static member
extern int randWithRange(int lo, int hi);

extern const int RK_MOD;

/// The base value for Rabin-Karp algorithm
extern const int RK_BASE;

/// RK_BASE to the power of PATTERN_LENGTH-1, modular RK_MOD.
extern const int RK_BASE_POW;

/// The length of the window for winnowing algorithm, or the *guarantee threshold*.
extern const int WINDOW_LENGTH;

/// The length of the patterns used by winnowing algorithm, or the *noise threshold*.
extern const int PATTERN_LENGTH;

/// Types of documents that can be handled, i.e. ".cpp"
extern const std::string TYPE[];

/// Size of TYPE.
extern const int TYPE_COUNT;
