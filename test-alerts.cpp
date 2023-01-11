#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "alert.h"

TEST_CASE("infers the breach according to limits") {
  BatteryCharacter batteryChar;
  batteryChar.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryChar, 50) == TOO_HIGH)
}
