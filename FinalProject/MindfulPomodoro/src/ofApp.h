#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);

private:
    ofVideoPlayer bgVideo; // Video for start screen
    ofSoundPlayer mindfulnessBell; // Sound for mindfulness bell

    bool isTimerScreen; 
    bool isRunning;
    bool isPomodoro; 

    int currentTime; 
    int pomodoroDuration; 
    int breakDuration;

    void drawStartScreen(); // Draw the start screen
    void drawTimerScreen(); // Draw the timer screen

    float hue;
    ofTrueTypeFont titleFont;
};
