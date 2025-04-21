#include <gui/common/CustomKeyboard.hpp>
#include <string.h>
#include <touchgfx/Color.hpp>
#include <gui_generated/screen_screen/screenViewBase.hpp>
Unicode::UnicodeChar global_keyboard_buffer[18];
CustomKeyboard::CustomKeyboard() : keyboard(),
    modeBtnTextArea(),
    capslockPressed(this, &CustomKeyboard::capslockPressedHandler),
    backspacePressed(this, &CustomKeyboard::backspacePressedHandler),
    hidePressed(this, &CustomKeyboard::hidePressedHandler),
    keyPressed(this, &CustomKeyboard::keyPressedhandler),
	enterPressed(this,&CustomKeyboard::enterPressedhandler),
    alphaKeys(true),
    uppercaseKeys(false),
    firstCharacterEntry(false)
{
    //Set the callbacks for the callback areas of the keyboard and set its layout.
    layout.callbackAreaArray[0].callback = &capslockPressed;
    layout.callbackAreaArray[1].callback = &backspacePressed;
    layout.callbackAreaArray[2].callback = &hidePressed;
    layout.callbackAreaArray[3].callback = &enterPressed;
    keyboard.setLayout(&layout);
    keyboard.setKeyListener(keyPressed);
    keyboard.setPosition(0, 0, 320, 240);
    keyboard.setTextIndentation();
    //Allocate the buffer associated with keyboard.
    memset(buffer, 0, sizeof(buffer));
    keyboard.setBuffer(buffer, BUFFER_SIZE);

    uppercaseKeys = true;
    firstCharacterEntry = true;

//    modeBtnTextArea.setPosition(3, 122, 35, 25);
//    modeBtnTextArea.setColor(Color::getColorFromRGB(0xFF, 0xFF, 0xFF));

    setKeyMappingList();

    add(keyboard);
//    add(modeBtnTextArea);
}

void CustomKeyboard::setKeyMappingList()
{
    if (alphaKeys)
    {
        modeBtnTextArea.setTypedText(TypedText(T_ALPHAMODE));
        if (uppercaseKeys)
        {
            keyboard.setKeymappingList(&keyMappingListAlphaUpper);
        }
        else
        {
            keyboard.setKeymappingList(&keyMappingListAlphaLower);
        }
    }
    else
    {
        modeBtnTextArea.setTypedText(TypedText(T_NUMMODE));
        if (uppercaseKeys)
        {
            keyboard.setKeymappingList(&keyMappingListNumUpper);
        }
        else
        {
            keyboard.setKeymappingList(&keyMappingListNumLower);
        }
    }
}

void CustomKeyboard::backspacePressedHandler()
{
    uint16_t pos = keyboard.getBufferPosition();
    if (pos > 0)
    {
        //Delete the previous entry in the buffer and decrement the position.
        buffer[pos - 1] = 0;
        keyboard.setBufferPosition(pos - 1);

        //Change keymappings if we have reached the first position.
        if (1 == pos)
        {
            firstCharacterEntry = true;
            uppercaseKeys = true;
            setKeyMappingList();
        }
    }
}

void CustomKeyboard::capslockPressedHandler()
{
    uppercaseKeys = !uppercaseKeys;
    setKeyMappingList();
}

void CustomKeyboard::hidePressedHandler()
{
	keyboard.setVisible(false);
	keyboard.invalidate();
	clearBuffer();
	static_cast<FrontendApplication*>(Application::getInstance())->gotocustom_coffeeScreenNoTransition();
}

void CustomKeyboard::keyPressedhandler(Unicode::UnicodeChar keyChar)
{
    // After the first keypress, the keyboard will shift to lowercase.
    if (firstCharacterEntry && keyChar != 0)
    {
        firstCharacterEntry = false;
        uppercaseKeys = false;
        setKeyMappingList();
    }
}

void CustomKeyboard::enterPressedhandler()
{
	Unicode::UnicodeChar* buffer = getBuffer();
	    Unicode::strncpy(global_keyboard_buffer, buffer, 30);
		static_cast<FrontendApplication*>(Application::getInstance())->gotocustom_coffeeScreenNoTransition();

}

void CustomKeyboard::setTouchable(bool touch)
{
    Container::setTouchable(touch);
    keyboard.setTouchable(touch);
}

Unicode:: UnicodeChar* CustomKeyboard::getBuffer ()
{
	return keyboard.getBuffer();
}

void CustomKeyboard::clearBuffer ()
{
	memset(buffer, 0, BUFFER_SIZE+1);
	keyboard.setBufferPosition(0);
    firstCharacterEntry = true;
    uppercaseKeys = true;
    setKeyMappingList();
}
