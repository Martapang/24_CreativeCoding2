#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Pomodoro Timer");
    ofSetWindowShape(1024, 768);

    titleFont.load("ELEPHNT.ttf", 35);

    pomodoroDuration = 25 * 60;  // Set Pomodoro duration to 25 minutes
    breakDuration = 5 * 60;  // Set break duration to 5 minutes
    currentTime = pomodoroDuration;  // Initialize current time with Pomodoro duration

    isPomodoro = true;  // Start with Pomodoro mode
    isRunning = false;  // Timer is not running initially
    isTimerScreen = false;  // Start on the start screen

    // Load the start screen video
    bgVideo.load("BG.mp4");

    mindfulnessBell.load("bellSound.mp3");  // Load the mindfulness bell sound

    bgVideo.setLoopState(OF_LOOP_NORMAL);  // Set the video to loop
    bgVideo.play();  // Play the start screen video
}

//--------------------------------------------------------------
void ofApp::update() {
    // the hue for the color shift
    hue += 0.05;
    if (hue > 255) hue = 0;

    // Update the timer if it's running
    if (isRunning && currentTime > 0) {
        currentTime--;
    }

    // Play the mindfulness bell when a Pomodoro or Break ends
    if (isRunning && currentTime == 0) {
        mindfulnessBell.play();
        isRunning = false;

        // Switch between Pomodoro and Break modes
        if (isPomodoro) {
            currentTime = breakDuration; // Switch to Break duration
            isPomodoro = false; // Switch mode to Break
        }
        else {
            currentTime = pomodoroDuration; // Switch back to Pomodoro duration
            isPomodoro = true; // Switch mode to Pomodoro
        }
    }

    if (!isTimerScreen) {
        bgVideo.update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (!isTimerScreen) {
        drawStartScreen(); // Show start screen with the video background
    }
    else {
        drawTimerScreen(); // Show timer screen with buttons and timer display
    }
}

//--------------------------------------------------------------
// Draw the Start Screen with a video background
void ofApp::drawStartScreen() {
    float screenAspect = (float)ofGetWidth() / ofGetHeight();
    float videoAspect = (float)bgVideo.getWidth() / bgVideo.getHeight();
    float videoWidth, videoHeight;

    if (screenAspect > videoAspect) {
        videoWidth = ofGetWidth();
        videoHeight = videoWidth / videoAspect;
    }
    else {
        videoHeight = ofGetHeight();
        videoWidth = videoHeight * videoAspect;
    }

    bgVideo.draw((ofGetWidth() - videoWidth) / 2, (ofGetHeight() - videoHeight) / 2, videoWidth, videoHeight);
}

//--------------------------------------------------------------
// Draw the Timer Screen
void ofApp::drawTimerScreen() {

    // Set the background color based on hue
    ofColor bgColor;
    bgColor.setHsb(hue, 100, 255);
    ofSetColor(bgColor);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());  // Draw the background to cover the entire window


    ofSetColor(255); // Set color for text and buttons

    // Center everything on the screen
    int centerX = ofGetWidth() / 2;
    int centerY = ofGetHeight() / 2;

    // Display whether it's Pomodoro or Break
    if (isPomodoro) {
        ofSetColor(0, 0, 0);
        titleFont.drawString("Working Time", centerX - 170, centerY - 200);
    }
    else {
        ofSetColor(0, 0, 0);
        titleFont.drawString("Break Time", centerX - 160, centerY - 200);

        // Draw "Skip Break" button only during the break
        int skipButtonWidth = 150;
        int skipButtonHeight = 50;
        int skipButtonX = centerX - skipButtonWidth / 2;
        int skipButtonY = centerY + 200;

        ofSetColor(255, 50, 0); // Red button color
        ofDrawRectangle(skipButtonX, skipButtonY, skipButtonWidth, skipButtonHeight); // Button shape
        ofSetColor(255);
        ofDrawBitmapString("Skip Break", skipButtonX + 30, skipButtonY + 30); // Button label
    }

    // Display the timer 
    int minutes = currentTime / 60;
    int seconds = currentTime % 60;
    std::string timeString = ofToString(minutes) + ":" + (seconds < 10 ? "0" : "") + ofToString(seconds);
    ofSetColor(0, 0, 0);
    titleFont.drawString("Time left: " + timeString, centerX - 200, centerY - 100);

    // Button dimensions and spacing
    int buttonWidth = 100;
    int buttonHeight = 40;
    int buttonSpacing = 20;

    int startX = centerX - (buttonWidth + buttonSpacing) * 1.5;
    int buttonY = centerY - buttonHeight / 2;

    // Draw buttons for controlling the timer
    ofSetColor(50, 240, 100); // Button color for Start
    ofDrawRectangle(startX, buttonY, buttonWidth, buttonHeight); // Start button

    ofSetColor(255, 255, 0); // Button color for Pause
    ofDrawRectangle(startX + buttonWidth + buttonSpacing, buttonY, buttonWidth, buttonHeight); // Pause button

    ofSetColor(255, 100, 100); // Button color for Reset
    ofDrawRectangle(startX + 2 * (buttonWidth + buttonSpacing), buttonY, buttonWidth, buttonHeight); // Reset button

    // Draw + and - buttons for adjusting Pomodoro and Break time
    int smallButtonSize = 40;

    // + and - buttons for Pomodoro
    ofSetColor(255); // Set color for + and - buttons
    ofDrawRectangle(centerX - 150 - smallButtonSize / 2, centerY + 50 - smallButtonSize / 2, smallButtonSize, smallButtonSize); // + Pomodoro
    ofDrawRectangle(centerX - 100 - smallButtonSize / 2, centerY + 50 - smallButtonSize / 2, smallButtonSize, smallButtonSize); // - Pomodoro

    // + and - buttons for Break
    ofDrawRectangle(centerX - 150 - smallButtonSize / 2, centerY + 100 - smallButtonSize / 2, smallButtonSize, smallButtonSize); // + Break
    ofDrawRectangle(centerX - 100 - smallButtonSize / 2, centerY + 100 - smallButtonSize / 2, smallButtonSize, smallButtonSize); // - Break

    // Draw text for buttons
    ofSetColor(0); // Set text color to black
    ofDrawBitmapString("Start", startX + buttonWidth / 2 - 20, buttonY + buttonHeight / 2 + 10);
    ofDrawBitmapString("Pause", startX + buttonWidth + buttonSpacing + buttonWidth / 2 - 20, buttonY + buttonHeight / 2 + 10);
    ofDrawBitmapString("Reset", startX + 2 * (buttonWidth + buttonSpacing) + buttonWidth / 2 - 20, buttonY + buttonHeight / 2 + 10);


    ofDrawBitmapString("+", centerX - 145 - smallButtonSize / 2 + 13, centerY + 46 + smallButtonSize / 2 - 10);
    ofDrawBitmapString("-", centerX - 100 - smallButtonSize / 2 + 13, centerY + 46 + smallButtonSize / 2 - 10);
    ofDrawBitmapString("+", centerX - 145 - smallButtonSize / 2 + 13, centerY + 96 + smallButtonSize / 2 - 10);
    ofDrawBitmapString("-", centerX - 100 - smallButtonSize / 2 + 13, centerY + 96 + smallButtonSize / 2 - 10);

    // Draw the timer settings

    ofDrawBitmapString("Pomodoro: " + ofToString(pomodoroDuration / 60) + " mins", centerX - 40, centerY + 55);
    ofDrawBitmapString("Break: " + ofToString(breakDuration / 60) + " mins", centerX - 40, centerY + 105);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    std::cout << "Mouse Pressed at: " << x << ", " << y << std::endl;

    // Handle start screen to timer screen switch
    if (!isTimerScreen) {
        isTimerScreen = true;
        bgVideo.stop();  // Stop the start screen video
        return;  // Exit to avoid further button processing
    }

    // Timer screen button handling
    int centerX = ofGetWidth() / 2;
    int centerY = ofGetHeight() / 2;

    int buttonWidth = 100;
    int buttonHeight = 40;
    int buttonSpacing = 20;

    int startX = centerX - (buttonWidth + buttonSpacing) * 1.5;
    int buttonY = centerY - buttonHeight / 2;

    // Start button
    if (x >= startX && x <= startX + buttonWidth && y >= buttonY && y <= buttonY + buttonHeight) {
        isRunning = true;
    }

    // Pause button
    if (x >= startX + buttonWidth + buttonSpacing && x <= startX + buttonWidth + buttonSpacing + buttonWidth &&
        y >= buttonY && y <= buttonY + buttonHeight) {
        isRunning = false;
    }

    // Reset button
    if (x >= startX + 2 * (buttonWidth + buttonSpacing) && x <= startX + 2 * (buttonWidth + buttonSpacing) + buttonWidth &&
        y >= buttonY && y <= buttonY + buttonHeight) {
        currentTime = pomodoroDuration;  // Reset to Pomodoro duration
        isRunning = false;
    }

    // Adjust Pomodoro and Break time
    int smallButtonSize = 40;

    // + Pomodoro
    if (x >= centerX - 150 - smallButtonSize / 2 && x <= centerX - 150 + smallButtonSize / 2 && y >= centerY + 50 - smallButtonSize / 2 && y <= centerY + 50 + smallButtonSize / 2) {
        pomodoroDuration += 25 * 60;  // Add 25 minutes
        if (isPomodoro && !isRunning) {
            currentTime = pomodoroDuration;
        }
    }

    // - Pomodoro
    if (x >= centerX - 100 - smallButtonSize / 2 && x <= centerX - 100 + smallButtonSize / 2 && y >= centerY + 50 - smallButtonSize / 2 && y <= centerY + 50 + smallButtonSize / 2) {
        pomodoroDuration = std::max(pomodoroDuration - 25 * 60, 25 * 60);  // Ensure minimum of 25 minutes
        if (isPomodoro && !isRunning) {
            currentTime = pomodoroDuration;
        }
    }

    // + Break
    if (x >= centerX - 150 - smallButtonSize / 2 && x <= centerX - 150 + smallButtonSize / 2 && y >= centerY + 100 - smallButtonSize / 2 && y <= centerY + 100 + smallButtonSize / 2) {
        breakDuration += 5 * 60;  // Add 5 minutes
        if (!isPomodoro && !isRunning) {
            currentTime = breakDuration;
        }
    }

    // - Break
    if (x >= centerX - 100 - smallButtonSize / 2 && x <= centerX - 100 + smallButtonSize / 2 && y >= centerY + 100 - smallButtonSize / 2 && y <= centerY + 100 + smallButtonSize / 2) {
        breakDuration = std::max(breakDuration - 5 * 60, 5 * 60);  // Ensure minimum of 5 minutes
        if (!isPomodoro && !isRunning) {
            currentTime = breakDuration;
        }
    }

    // Skip Break button logic
    if (!isPomodoro && x >= centerX - 75 && x <= centerX + 75 && y >= centerY + 200 && y <= centerY + 250) {
        isRunning = false;  // End the break early
        currentTime = pomodoroDuration;  // Reset to Pomodoro duration
        isPomodoro = true;  // Switch back to Pomodoro mode
    }
}



