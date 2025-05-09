/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen2ViewBase::Screen2ViewBase() :
    flexButtonCallback(this, &Screen2ViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 320, 240);
    box1.setColor(touchgfx::Color::getColorFromRGB(241, 226, 184));
    add(box1);

    qrCode1.setXY(75, 37);
    qrCode1.setBuffers(qrBuffer_qrCode1, qrScratchBuffer_qrCode1);
    qrCode1.setQRCodeVersion(3);
    qrCode1.setScale(7);
    qrCode1.convertStringToQRCode("github.com/kirbilal/stm32g0b1re_touchgfx");
    add(qrCode1);

    Image3.setXY(7, 7);
    Image3.setBitmap(touchgfx::Bitmap(BITMAP_BACK1_ID));
    add(Image3);

    backbutton.setBoxWithBorderPosition(0, 0, 40, 40);
    backbutton.setBorderSize(5);
    backbutton.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    backbutton.setAlpha(0);
    backbutton.setAction(flexButtonCallback);
    backbutton.setPosition(7, 7, 40, 40);
    add(backbutton);

    textArea1.setXY(75, 7);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9TUO));
    add(textArea1);
}

Screen2ViewBase::~Screen2ViewBase()
{

}

void Screen2ViewBase::setupScreen()
{

}

void Screen2ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &backbutton)
    {
        //Interaction1
        //When backbutton clicked change screen to screen
        //Go to screen with no screen transition
        application().gotoscreenScreenNoTransition();
    }
}
