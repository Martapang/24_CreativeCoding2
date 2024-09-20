#pragma once
#include "ofMain.h"

class Button {
public:
    Button(float x, float y, float width, float height, std::string label, ofColor color);

    void draw();
    bool isClicked(int mouseX, int mouseY);
    void setLabel(std::string label);
    void setPosition(float x, float y);
    void setColor(ofColor color);

private:
    float x, y;
    float width, height;
    std::string label;
    ofColor color;
};