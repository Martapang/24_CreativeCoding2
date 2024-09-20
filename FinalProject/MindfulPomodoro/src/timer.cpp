
#include "timer.h"

// Constructor to initialize the timer durations and set default values
Timer::Timer(int pomodoroDuration, int breakDuration)
    : pomodoroDuration(pomodoroDuration), breakDuration(breakDuration), currentTime(pomodoroDuration), running(false), inPomodoro(true) {}

// Start the timer
void Timer::start() {
    running = true;
}

// Pause the timer
void Timer::pause() {
    running = false;
}

// Reset the timer to the current mode (Pomodoro or Break)
void Timer::reset() {
    currentTime = inPomodoro ? pomodoroDuration : breakDuration;
    running = false;
}

// Skip the break and return to Pomodoro
void Timer::skipBreak() {
    if (!inPomodoro) {
        inPomodoro = true;
        currentTime = pomodoroDuration;
        running = false;
    }
}


void Timer::update() {
    if (running && currentTime > 0) {
        currentTime--;
    }

    if (running && currentTime == 0) {
        running = false;
        inPomodoro = !inPomodoro; // Toggle between Pomodoro and Break
        currentTime = inPomodoro ? pomodoroDuration : breakDuration;
    }
}

// Get the current time in the timer
int Timer::getCurrentTime() const {
    return currentTime;
}

// Check if the timer is running
bool Timer::isRunning() const {
    return running;
}

// Check if it's currently in Pomodoro mode
bool Timer::isPomodoro() const {
    return inPomodoro;
}
