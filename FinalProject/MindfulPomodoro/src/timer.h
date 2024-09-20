#pragma once

class Timer {
public:
    Timer(int pomodoroDuration, int breakDuration);

    // Timer control functions
    void start();
    void pause();
    void reset();
    void skipBreak();

    // Update timer logic
    void update();

    // Getters for the timer values
    int getCurrentTime() const;
    bool isRunning() const;
    bool isPomodoro() const;

private:
    // Timer durations
    int pomodoroDuration;
    int breakDuration;

    // Current state
    int currentTime;
    bool running;
    bool inPomodoro;
};