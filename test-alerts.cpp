#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("CheckForBreachType_inferBreachWithValueBelowLowerlimit_expectTOO_LOW")
{
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("CheckForBreachType_inferBreachWithValueAboveUpperlimit_expectTOO_HIGH")
{
  REQUIRE(inferBreach(45, 20, 30) == TOO_HIGH);
}

TEST_CASE("CheckForBreachType_inferBreachWithValueWithinLowerAndUpperlimit_expectNORMAL")
{
  REQUIRE(inferBreach(75, 50, 100) == NORMAL);
}

TEST_CASE("CheckForBreachType_inferBreachWithValueEqualstoLowerLimit_expectNORMAL")
{
  REQUIRE(inferBreach(50, 50, 100) == NORMAL);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsPassiveAndTempBelowLowerLimit_expectTOO_LOW")
{
	  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -10) == TOO_LOW);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsPassiveAndTempAboveUpperLimit_expectTOO_HIGH")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 50) == TOO_HIGH);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsPassiveAndTempWithinLimits_expectNORMAL")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 20) == NORMAL);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsHiActiveAndTempBelowLowerLimit_expectTOO_LOW")
{
	  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -10) == TOO_LOW);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsHiActiveAndTempAboveUpperLimit_expectTOO_HIGH")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 100) == TOO_HIGH);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsHiActiveAndTempWithinLimits_expectNORMAL")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40) == NORMAL);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsMedActiveAndTempBelowLowerLimit_expectTOO_LOW")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsMedActiveAndTempAboveUpperLimit_expectTOO_HIGH")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 75) == TOO_HIGH);
}

TEST_CASE("CheckForBreachType_ClassifyTemperatureBreachWithCoolingTypeAsMedActiveAndTempWithinLimits_expectNORMAL")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}

BatteryCharacter batterychar[3] = { {PASSIVE_COOLING,"window"}, {HI_ACTIVE_COOLING,"fan"}, {MED_ACTIVE_COOLING,"liquidCooling"} };
TEST_CASE("Test case for checking and Alert to controller") {
  checkAndAlert(TO_CONTROLLER, batterychar[0], 10);
}

TEST_CASE("Test case for checking breachType as Normal and Alert by sending Email") {
  checkAndAlert(TO_EMAIL, batterychar[1], 20);
}

TEST_CASE("Test case for checking breachType as Low and Alert by sending Email") {
  checkAndAlert(TO_EMAIL, batterychar[1], -5);
}

TEST_CASE("Test case for checking breachType as High and Alert by sending Email") {
  checkAndAlert(TO_EMAIL, batterychar[1], 75);
}



