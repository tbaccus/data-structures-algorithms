#include <crtdbg.h>

#include "gtest/gtest.h"

// Adapted from: https://stackoverflow.com/a/70968385
class MemoryLeakDetector {
 public:
  MemoryLeakDetector() { _CrtMemCheckpoint(&memState_); }

  ~MemoryLeakDetector() {
    _CrtMemState stateNow, stateDiff;
    _CrtMemCheckpoint(&stateNow);
    int diffResult = _CrtMemDifference(&stateDiff, &memState_, &stateNow);
    if (diffResult) reportFailure(stateDiff.lSizes[1]);
  }

 private:
  void reportFailure(unsigned int unfreedBytes) {
    FAIL() << "Memory leak of " << unfreedBytes << " byte(s) detected.";
  }
  _CrtMemState memState_;
};