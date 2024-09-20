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

    bool isTimerScreen; // Flag for checking if timer screen is active
    bool isRunning; // Flag for checking if the timer is running
    bool isPomodoro; // Flag for checking if it's Pomodoro or Break

    int currentTime; // Current time in seconds
    int pomodoroDuration; // Pomodoro duration in seconds
    int breakDuration; // Break duration in seconds

    void drawStartScreen(); // Draw the start screen
    void drawTimerScreen(); // Draw the timer screen

    float hue; // Variable for hue (if used in any color adjustments)
    ofTrueTypeFont titleFont;
};
