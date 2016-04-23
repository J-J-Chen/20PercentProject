#include "Button.h"

#include <cmath>

Button::Button(int xCenter, int yCenter, int fullHeight, int fullWidth) {
	centerX = xCenter;
	centerY = yCenter;
	height = fullHeight;
	width = fullWidth;
	radius = 0;
	enabled = true;
}

Button::Button(int xCenter, int yCenter, int radius1) {
	centerX = xCenter;
	centerY = yCenter;
	height = 0;
	width = 0;
	radius = radius1;
	enabled = true;
}

bool Button::IsEnabled() {
	return enabled;
}

void Button::SetEnable(bool enable) {
	enabled = enable;
}

bool Button::HasBeenClicked(int x, int y) {
	return (((x >= centerX - width / 2) && (x <= centerX + width / 2) && (y >= centerY - height / 2) && (y <= centerY + height / 2)) || DistanceCalc(x, y) > radius);
}

double Button::DistanceCalc(int x, int y) {
	return sqrt(pow(centerX - x, 2) + pow(centerY - y, 2));
}