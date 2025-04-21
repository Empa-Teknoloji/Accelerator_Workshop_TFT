#include <gui/keyboard_screen/keyboardView.hpp>

keyboardView::keyboardView()
{
	keyboard.setPosition(0, 0, 320, 240);
	add(keyboard);
}

void keyboardView::setupScreen()
{
    keyboardViewBase::setupScreen();
}

void keyboardView::tearDownScreen()
{
    keyboardViewBase::tearDownScreen();
}
