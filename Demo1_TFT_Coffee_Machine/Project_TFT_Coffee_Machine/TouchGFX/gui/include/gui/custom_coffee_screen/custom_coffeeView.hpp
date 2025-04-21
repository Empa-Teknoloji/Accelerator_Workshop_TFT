#ifndef CUSTOM_COFFEEVIEW_HPP
#define CUSTOM_COFFEEVIEW_HPP

#include <gui_generated/custom_coffee_screen/custom_coffeeViewBase.hpp>
#include <gui/custom_coffee_screen/custom_coffeePresenter.hpp>

class custom_coffeeView : public custom_coffeeViewBase
{
public:
    custom_coffeeView();
    virtual ~custom_coffeeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void no_coffee_button_pressed();
    virtual void cancel_button_pressed();
    virtual void adjust_slider1(int value);
    virtual void adjust_slider2(int value);
    virtual void adjust_slider3(int value);
    virtual void enter_name_pressed();
    virtual void save_button_pressed();
    virtual void left_button_pressed();
    virtual void right_button_pressed();
protected:
};

#endif // CUSTOM_COFFEEVIEW_HPP
