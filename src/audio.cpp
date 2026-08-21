#include "audio.h"
#include "raylib.h"

Audio LoadAudio(){
    Audio audio;
    audio.birds = LoadMusicStream("assets/birdswater.wav");
    audio.nightwater = LoadMusicStream("assets/nightwater.wav");
    audio.vulcan = LoadMusicStream("assets/vulcan_sound.wav");
    audio.forrest = LoadMusicStream("assets/forrest.wav");
    audio.startscreen = LoadMusicStream("assets/startscreen_song.wav");
    audio.button = LoadSound("assets/button_sound.wav");
    return audio;
}

void PlayAudio(Audio& audio, Daytime currentDayTime,State currentState){
    if(currentState == State::Startscreen){
        StopMusicStream(audio.nightwater);
        StopMusicStream(audio.birds);
        StopMusicStream(audio.vulcan);
        StopMusicStream(audio.forrest);

        if(!IsMusicStreamPlaying(audio.startscreen)){
            PlayMusicStream(audio.startscreen);
        }
        UpdateMusicStream(audio.startscreen);
    }
    else if(currentState == State::ThemeVulcan){
        StopMusicStream(audio.nightwater);
        StopMusicStream(audio.birds);
        StopMusicStream(audio.forrest);
        if(!IsMusicStreamPlaying(audio.vulcan)){
            PlayMusicStream(audio.vulcan);
        }
        UpdateMusicStream(audio.vulcan);
    }
    else if(currentState == State::ThemeForrest){
        StopMusicStream(audio.nightwater);
        StopMusicStream(audio.birds);
        StopMusicStream(audio.vulcan);
        if(!IsMusicStreamPlaying(audio.forrest)){
            PlayMusicStream(audio.forrest);
        }
        UpdateMusicStream(audio.forrest);
    }
    else if(currentDayTime == Daytime::Morning || currentDayTime == Daytime::Daylight){
        StopMusicStream(audio.nightwater);
        StopMusicStream(audio.vulcan);
        StopMusicStream(audio.forrest);
        if(!IsMusicStreamPlaying(audio.birds)){
            PlayMusicStream(audio.birds);
        }
        UpdateMusicStream(audio.birds);
    }
    else if(currentDayTime == Daytime::Night){ 
        StopMusicStream(audio.birds);
        StopMusicStream(audio.vulcan);
        StopMusicStream(audio.forrest);
        if(!IsMusicStreamPlaying(audio.nightwater)){
            PlayMusicStream(audio.nightwater);
        }
        UpdateMusicStream(audio.nightwater);

    }
}

void UnlaodAudio(Audio& audio){
    UnloadMusicStream(audio.birds);
    UnloadMusicStream(audio.nightwater);
    UnloadMusicStream(audio.vulcan);
    UnloadMusicStream(audio.forrest);
    UnloadMusicStream(audio.startscreen);
    UnloadSound(audio.button);
}