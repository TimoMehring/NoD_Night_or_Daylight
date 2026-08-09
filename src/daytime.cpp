#include "daytime.h"
#include "raylib.h"
#include "ctime"

int GetCurrentHour(){
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
     
    return localTime->tm_hour;

}

Daytime CheckDayTime(int currentHour){
    if(currentHour >= 6 && currentHour < 10){
        return Daytime::Morning;
    }
    else if(currentHour >= 10 && currentHour < 22){
        return Daytime::Daylight;
    }
    else{
        return Daytime::Night;
    }
}