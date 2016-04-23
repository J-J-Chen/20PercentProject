#pragma once

class Button {
public:
	Button(int centerX, int centerY, int height, int width);
	Button(int centerX, int centerY, int radius);
	bool HasBeenClicked(int x, int y);
	bool IsEnabled();
	void SetEnable(bool enable);

private:
	int centerX;
	int centerY;
	int height;
	int width;
	int radius;
	bool enabled;
	double DistanceCalc(int x, int y);
};
