#include "audio.h"
#include "raylib.h"

Audio LoadAudio(){
    Audio audio;
    audio.birds = LoadMusicStream("assets/birds.wav");
    return audio;
}

void PlayAudio(Audio& audio, Daytime currentDayTime){
    if(currentDayTime == Daytime::Morning || currentDayTime == Daytime::Daylight){
        if(!IsMusicStreamPlaying(audio.birds)){
            PlayMusicStream(audio.birds);
        }
        UpdateMusicStream(audio.birds);
    }else{
        StopMusicStream(audio.birds);
    }
}
