#include "daytime.h"
#include "raylib.h"
#include "ctime"

int GetCurrentHour(){
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
     
    return localTime->tm_hour;

}