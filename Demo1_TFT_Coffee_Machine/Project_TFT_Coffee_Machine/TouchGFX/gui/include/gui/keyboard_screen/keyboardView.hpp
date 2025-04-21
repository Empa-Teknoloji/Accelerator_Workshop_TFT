#ifndef KEYBOARDVIEW_HPP
#define KEYBOARDVIEW_HPP

#include <gui_generated/keyboard_screen/keyboardViewBase.hpp>
#include <gui/keyboard_screen/keyboardPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>
class keyboardView : public keyboardViewBase
{
public:
    keyboardView();
    virtual ~keyboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    CustomKeyboard keyboard;
};

#endif // KEYBOARDVIEW_HPP
