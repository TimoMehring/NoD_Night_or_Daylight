#include "audio.h"
#include "raylib.h"

Audio LoadAudio(){
    Audio audio;
    audio.birds = LoadMusicStream("assets/birdswater.wav");
    audio.nightwater = LoadMusicStream("assets/nightwater.wav");
    audio.vulcan = LoadMusicStream("assets/vulcan_sound.wav");
    return audio;
}

void PlayAudio(Audio& audio, Daytime currentDayTime,State currentState){
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
    if(currentState == State::ThemeVulcan){
        StopMusicStream(audio.nightwater);
        StopMusicStream(audio.birds);
        if(!IsMusicStreamPlaying(audio.vulcan)){
            PlayMusicStream(audio.vulcan);
        }
        UpdateMusicStream(audio.vulcan);


    }
}

void UnlaodAudio(Audio& audio){
    UnloadMusicStream(audio.birds);
    UnloadMusicStream(audio.nightwater);
    UnloadMusicStream(audio.vulcan);
}