#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;
  int coolingLimits[][2] = {
    {0, 35},      // PASSIVE_COOLING
    {0, 45},      // HI_ACTIVE_COOLING
    {0, 40}       // MED_ACTIVE_COOLING
  };
  if(coolingType < 3) {
    int coolingIndex = static_cast<int>(coolingType);
    lowerLimit = coolingLimits[coolingIndex][0];
    upperLimit = coolingLimits[coolingIndex][1];
  }
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );
  if(alertTarget == TO_CONTROLLER) {
    sendToController(breachType);
  }
  else if(alertTarget == TO_EMAIL) {
    sendToEmail(breachType);
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  if(breachType == TOO_LOW) {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
  }
  else if(breachType == TOO_HIGH) {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
  }
}
