#pragma once
#include "Button.h"
#include <vector>

class ButtonManager {
public:
	void Add(Button button) {
		buttons.insert(buttons.end(), button);
	}

	static Button Clicked(int x, int y) {
		for (unsigned i = 0; i < buttons.size(); i++) {
			if (buttons[i].HasBeenClicked(x, y)) {
				asdf = buttons[i];
			}
		}
		return asdf;
	}

private:
	static std::vector<Button> buttons;
	static Button asdf;
};
