#include "audio.h"
#include "raylib.h"

Audio LoadAudio(){
    Audio audio;
    audio.birds = LoadMusicStream("assets/birds.wav");
    audio.nightwater = LoadMusicStream("assets/nightwater.wav");
    return audio;
}

void PlayAudio(Audio& audio, Daytime currentDayTime){
    if(currentDayTime == Daytime::Morning || currentDayTime == Daytime::Daylight){
        StopMusicStream(audio.nightwater);
        if(!IsMusicStreamPlaying(audio.birds)){
            PlayMusicStream(audio.birds);
        }
        UpdateMusicStream(audio.birds);
    }else if(currentDayTime == Daytime::Night){ 
        StopMusicStream(audio.birds);
        if(!IsMusicStreamPlaying(audio.nightwater)){
            PlayMusicStream(audio.nightwater);
        }
        UpdateMusicStream(audio.nightwater);

    }
}
