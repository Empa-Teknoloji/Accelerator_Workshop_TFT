/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/custom_coffee_screen/custom_coffeeViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

custom_coffeeViewBase::custom_coffeeViewBase() :
    flexButtonCallback(this, &custom_coffeeViewBase::flexButtonCallbackHandler),
    sliderValueConfirmedCallback(this, &custom_coffeeViewBase::sliderValueConfirmedCallbackHandler),
    buttonCallback(this, &custom_coffeeViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(241, 226, 184));
    add(box1);

    textArea1.setPosition(51, 2, 218, 37);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CWNJ));
    add(textArea1);

    no_coffee_text_1.setXY(51, 76);
    no_coffee_text_1.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    no_coffee_text_1.setLinespacing(0);
    no_coffee_text_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0O2D));
    add(no_coffee_text_1);

    no_coffee_text_2.setXY(51, 107);
    no_coffee_text_2.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    no_coffee_text_2.setLinespacing(0);
    no_coffee_text_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4HTE));
    add(no_coffee_text_2);

    box2.setPosition(51, 184, 236, 50);
    box2.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    add(box2);

    no_custom_coffee_text.setXY(68, 197);
    no_custom_coffee_text.setColor(touchgfx::Color::getColorFromRGB(241, 226, 184));
    no_custom_coffee_text.setLinespacing(0);
    no_custom_coffee_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2LM6));
    add(no_custom_coffee_text);

    no_coffee_button.setBoxWithBorderPosition(0, 0, 236, 50);
    no_coffee_button.setBorderSize(5);
    no_coffee_button.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    no_coffee_button.setAlpha(0);
    no_coffee_button.setAction(flexButtonCallback);
    no_coffee_button.setPosition(51, 184, 236, 50);
    add(no_coffee_button);

    slider1.setXY(133, 130);
    slider1.setBitmaps(touchgfx::Bitmap(BITMAP_EMPTY_BAR_ID), touchgfx::Bitmap(BITMAP_WATER_BAR_ID), touchgfx::Bitmap(BITMAP_INDICATOR_ID));
    slider1.setupHorizontalSlider(0, 6, 0, 0, 154);
    slider1.setValueRange(0, 100);
    slider1.setValue(50);
    slider1.setVisible(false);
    slider1.setStopValueCallback(sliderValueConfirmedCallback);
    add(slider1);

    textArea2.setXY(6, 97);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea2.setLinespacing(0);
    textArea2Buffer[0] = 0;
    textArea2.setWildcard(textArea2Buffer);
    textArea2.resizeToCurrentText();
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J9QH));
    textArea2.setVisible(false);
    add(textArea2);

    textArea3.setXY(6, 135);
    textArea3.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea3.setLinespacing(0);
    textArea3Buffer[0] = 0;
    textArea3.setWildcard(textArea3Buffer);
    textArea3.resizeToCurrentText();
    textArea3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BIT3));
    textArea3.setVisible(false);
    add(textArea3);

    textArea4.setXY(6, 173);
    textArea4.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea4.setLinespacing(0);
    textArea4Buffer[0] = 0;
    textArea4.setWildcard(textArea4Buffer);
    textArea4.resizeToCurrentText();
    textArea4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O3WF));
    textArea4.setVisible(false);
    add(textArea4);

    textArea7.setXY(68, 8);
    textArea7.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea7.setLinespacing(0);
    textArea7.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H5EN));
    textArea7.setVisible(false);
    add(textArea7);

    slider2.setXY(133, 92);
    slider2.setBitmaps(touchgfx::Bitmap(BITMAP_EMPTY_BAR_ID), touchgfx::Bitmap(BITMAP_ESPRESSO_BAR_ID), touchgfx::Bitmap(BITMAP_INDICATOR_ID));
    slider2.setupHorizontalSlider(0, 6, 0, 0, 154);
    slider2.setValueRange(0, 100);
    slider2.setValue(50);
    slider2.setVisible(false);
    slider2.setStopValueCallback(sliderValueConfirmedCallback);
    add(slider2);

    slider3.setXY(133, 168);
    slider3.setBitmaps(touchgfx::Bitmap(BITMAP_EMPTY_BAR_ID), touchgfx::Bitmap(BITMAP_MILK_BAR_ID), touchgfx::Bitmap(BITMAP_INDICATOR_ID));
    slider3.setupHorizontalSlider(0, 6, 0, 0, 154);
    slider3.setValueRange(0, 100);
    slider3.setValue(50);
    slider3.setVisible(false);
    slider3.setStopValueCallback(sliderValueConfirmedCallback);
    add(slider3);

    box3.setPosition(13, 43, 243, 31);
    box3.setColor(touchgfx::Color::getColorFromRGB(245, 236, 233));
    box3.setVisible(false);
    add(box3);

    textArea9.setXY(21, 46);
    textArea9.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea9.setLinespacing(0);
    textArea9Buffer[0] = 0;
    textArea9.setWildcard(textArea9Buffer);
    textArea9.resizeToCurrentText();
    textArea9.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JYTL));
    textArea9.setVisible(false);
    add(textArea9);

    box4.setPosition(175, 210, 130, 26);
    box4.setColor(touchgfx::Color::getColorFromRGB(245, 236, 233));
    box4.setVisible(false);
    add(box4);

    box5.setPosition(15, 210, 130, 26);
    box5.setColor(touchgfx::Color::getColorFromRGB(245, 236, 233));
    box5.setVisible(false);
    add(box5);

    textArea10.setXY(57, 215);
    textArea10.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea10.setLinespacing(0);
    textArea10.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NKT5));
    textArea10.setVisible(false);
    add(textArea10);

    textArea11.setXY(223, 215);
    textArea11.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    textArea11.setLinespacing(0);
    textArea11.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J8TD));
    textArea11.setVisible(false);
    add(textArea11);

    enter_name_button.setBoxWithBorderPosition(0, 0, 243, 31);
    enter_name_button.setBorderSize(5);
    enter_name_button.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    enter_name_button.setAlpha(0);
    enter_name_button.setVisible(false);
    enter_name_button.setAction(flexButtonCallback);
    enter_name_button.setPosition(13, 43, 243, 31);
    add(enter_name_button);

    save_button.setBoxWithBorderPosition(0, 0, 130, 26);
    save_button.setBorderSize(5);
    save_button.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    save_button.setAlpha(0);
    save_button.setVisible(false);
    save_button.setAction(flexButtonCallback);
    save_button.setPosition(175, 210, 130, 26);
    add(save_button);

    cancel_button.setBoxWithBorderPosition(0, 0, 130, 26);
    cancel_button.setBorderSize(5);
    cancel_button.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    cancel_button.setAlpha(0);
    cancel_button.setVisible(false);
    cancel_button.setAction(flexButtonCallback);
    cancel_button.setPosition(15, 210, 130, 26);
    add(cancel_button);

    flexButton1.setBoxWithBorderPosition(0, 0, 243, 31);
    flexButton1.setBorderSize(5);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1.setVisible(false);
    flexButton1.setAction(flexButtonCallback);
    flexButton1.setPosition(13, 43, 243, 31);
    add(flexButton1);

    coffee_name.setPosition(107, 145, 106, 24);
    coffee_name.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    coffee_name.setLinespacing(0);
    coffee_nameBuffer[0] = 0;
    coffee_name.setWildcard(coffee_nameBuffer);
    coffee_name.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H6YA));
    coffee_name.setVisible(false);
    add(coffee_name);

    button1.setXY(20, 102);
    button1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID));
    button1.setVisible(false);
    button1.setAction(buttonCallback);
    add(button1);

    image1.setXY(13, 95);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_LEFT_50_50_543024_SVG_ID));
    image1.setVisible(false);
    add(image1);

    button2.setXY(264, 102);
    button2.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_DISABLED_ID));
    button2.setVisible(false);
    button2.setAction(buttonCallback);
    add(button2);

    image2.setXY(259, 95);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_HARDWARE_KEYBOARD_ARROW_RIGHT_50_50_543024_SVG_ID));
    image2.setVisible(false);
    add(image2);

    coffee_name_2.setPosition(-216, 145, 106, 24);
    coffee_name_2.setColor(touchgfx::Color::getColorFromRGB(84, 48, 36));
    coffee_name_2.setLinespacing(0);
    coffee_name_2Buffer[0] = 0;
    coffee_name_2.setWildcard(coffee_name_2Buffer);
    coffee_name_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_22OT));
    add(coffee_name_2);

    coffee_name_3.setPosition(-144, 145, 106, 24);
    coffee_name_3.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    coffee_name_3.setLinespacing(0);
    coffee_name_3Buffer[0] = 0;
    coffee_name_3.setWildcard(coffee_name_3Buffer);
    coffee_name_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_P1MO));
    add(coffee_name_3);

    coffee_name_4.setPosition(365, 145, 106, 24);
    coffee_name_4.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    coffee_name_4.setLinespacing(0);
    coffee_name_4Buffer[0] = 0;
    coffee_name_4.setWildcard(coffee_name_4Buffer);
    coffee_name_4.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HHHP));
    add(coffee_name_4);

    coffee_name_5.setPosition(463, 145, 106, 24);
    coffee_name_5.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    coffee_name_5.setLinespacing(0);
    coffee_name_5Buffer[0] = 0;
    coffee_name_5.setWildcard(coffee_name_5Buffer);
    coffee_name_5.setTypedText(touchgfx::TypedText(T___SINGLEUSE_890P));
    add(coffee_name_5);

    image3.setXY(110, 70);
    image3.setBitmap(touchgfx::Bitmap(BITMAP_ESPRESSO_ID));
    image3.setVisible(false);
    add(image3);

    image4.setXY(-110, 70);
    image4.setBitmap(touchgfx::Bitmap(BITMAP_ESPRESSO_ID));
    add(image4);

    image5.setXY(-210, 70);
    image5.setBitmap(touchgfx::Bitmap(BITMAP_ESPRESSO_ID));
    add(image5);

    image6.setXY(360, 70);
    image6.setBitmap(touchgfx::Bitmap(BITMAP_ESPRESSO_ID));
    add(image6);

    image7.setXY(510, 70);
    image7.setBitmap(touchgfx::Bitmap(BITMAP_ESPRESSO_ID));
    add(image7);

    image8.setXY(0, 0);
    image8.setBitmap(touchgfx::Bitmap(BITMAP_BACK1_ID));
    add(image8);

    custom_coffee_back.setBoxWithBorderPosition(0, 0, 40, 40);
    custom_coffee_back.setBorderSize(5);
    custom_coffee_back.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    custom_coffee_back.setAlpha(0);
    custom_coffee_back.setAction(flexButtonCallback);
    custom_coffee_back.setPosition(0, 0, 40, 40);
    add(custom_coffee_back);

    make_custom_coffee.setBoxWithBorderPosition(0, 0, 100, 100);
    make_custom_coffee.setBorderSize(5);
    make_custom_coffee.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    make_custom_coffee.setAlpha(0);
    make_custom_coffee.setVisible(false);
    make_custom_coffee.setAction(flexButtonCallback);
    make_custom_coffee.setPosition(110, 70, 100, 100);
    add(make_custom_coffee);
}

custom_coffeeViewBase::~custom_coffeeViewBase()
{

}

void custom_coffeeViewBase::setupScreen()
{

}

void custom_coffeeViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &no_coffee_button)
    {
        //Interaction1
        //When no_coffee_button clicked call virtual function
        //Call no_coffee_button_pressed
        no_coffee_button_pressed();
    }
    if (&src == &enter_name_button)
    {
        //Interaction2
        //When enter_name_button clicked call virtual function
        //Call enter_name_pressed
        enter_name_pressed();
    }
    if (&src == &save_button)
    {
        //Interaction3
        //When save_button clicked call virtual function
        //Call save_button_pressed
        save_button_pressed();
    }
    if (&src == &cancel_button)
    {
        //Interaction4
        //When cancel_button clicked call virtual function
        //Call cancel_button_pressed
        cancel_button_pressed();
    }
    if (&src == &flexButton1)
    {
        //Interaction11
        //When flexButton1 clicked change screen to keyboard
        //Go to keyboard with no screen transition
        application().gotokeyboardScreenNoTransition();
    }
    if (&src == &custom_coffee_back)
    {
        //Interaction14
        //When custom_coffee_back clicked change screen to screen
        //Go to screen with no screen transition
        application().gotoscreenScreenNoTransition();
    }
    if (&src == &make_custom_coffee)
    {
        //Interaction15
        //When make_custom_coffee clicked change screen to Screen1
        //Go to Screen1 with no screen transition
        application().gotoScreen1ScreenNoTransition();
    }
}

void custom_coffeeViewBase::sliderValueConfirmedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider2)
    {
        //Interaction6
        //When slider2 value confirmed call virtual function
        //Call adjust_slider2
        adjust_slider2(value);
    }
    if (&src == &slider1)
    {
        //Interaction7
        //When slider1 value confirmed call virtual function
        //Call adjust_slider1
        adjust_slider1(value);
    }
    if (&src == &slider3)
    {
        //Interaction8
        //When slider3 value confirmed call virtual function
        //Call adjust_slider3
        adjust_slider3(value);
    }
}

void custom_coffeeViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &button1)
    {
        //Interaction12
        //When button1 clicked call virtual function
        //Call left_button_pressed
        left_button_pressed();
    }
    if (&src == &button2)
    {
        //Interaction13
        //When button2 clicked call virtual function
        //Call right_button_pressed
        right_button_pressed();
    }
}
