#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "alert.h"

TEST_CASE("Test breach level") {
  BatteryCharacter batteryChar;
  batteryChar.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 40) == TOO_HIGH);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, -1) == TOO_LOW);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 20) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 0) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 35) == NORMAL);
  
  batteryChar.coolingType = HI_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 50) == TOO_HIGH);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, -5) == TOO_LOW);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 25) == NORMAL);
  REQUIRE(checkAndAlert(TO_EMAIL, batteryChar, 45) == NORMAL);
    
}

