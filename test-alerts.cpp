#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to lower limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to upper limits") {
  REQUIRE(inferBreach(45, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to normal") {
  REQUIRE(inferBreach(75, 50, 100) == NORMAL);
}

TEST_CASE("infers the breach according to equal limits") {
  REQUIRE(inferBreach(50, 50, 100) == NORMAL);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling TOO_LOW temperature") {
	  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -10) == TOO_LOW);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for Passive Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
}

TEST_CASE("Classify Temperature Breach for HiActive Cooling TOO_LOW temperature") {
	  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -10) == TOO_LOW);
}

TEST_CASE("Classify Temperature Breach for HiActive Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 100) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for HiActive Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}

TEST_CASE("Classify Temperature Breach for MediumActive Cooling TOO_LOW temperature") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("Classify Temperature Breach for MediumActive Cooling TOO_HIGH temperature") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 75) == TOO_HIGH);
}

TEST_CASE("Classify Temperature Breach for MediumActive Cooling NORMAL temperature") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}

BatteryCharacter batterychar[3] = { {PASSIVE_COOLING,"window"}, {HI_ACTIVE_COOLING,"fan"}, {MED_ACTIVE_COOLING,"liquidCooling"} };
TEST_CASE("Test case for checking and Alert to controller") {
  checkAndAlert(TO_CONTROLLER, batterychar[0], 10);
}

TEST_CASE("Test case for checking and Alert by sending Email") {
  checkAndAlert(TO_EMAIL, batterychar[1], 20);
}



