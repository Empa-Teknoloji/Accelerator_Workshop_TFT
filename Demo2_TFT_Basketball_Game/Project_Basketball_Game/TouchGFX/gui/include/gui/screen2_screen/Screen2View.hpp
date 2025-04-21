#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Widget.hpp>

class Screen2View : public Screen2ViewBase
{
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	virtual void handleClickEvent(const touchgfx::ClickEvent& event);
	virtual void handleDragEvent(const touchgfx::DragEvent& event);
	virtual void handleTickEvent();
    virtual void setupGameState();
    virtual void updateScoreDisplay();
    virtual void goBack();
	virtual void openMenu();
	virtual void handleButtonClick(const touchgfx::ClickEvent& event);
	virtual void handleTopPress(const touchgfx::ClickEvent& event);
	virtual void handleTopRelease();
	virtual void updateCounter(Unicode::UnicodeChar* buffer, size_t bufferSize, int value, touchgfx::TextArea& textArea);
	virtual void restart();
	virtual void updateTopPosition(int16_t deltaX, int16_t deltaY);
	virtual int16_t clamp(int16_t value, int16_t min, int16_t max);
	virtual void checkCollisionWithBackboard(int16_t topCenterX, int16_t topCenterY, int16_t& newX, int16_t& newY);
	virtual void checkCollisionWithRim(int16_t topCenterX, int16_t topCenterY, int16_t& newX, int16_t& newY);
	virtual void checkIfScored(int16_t topCenterX, int16_t topCenterY);
	virtual void handleBoundaries(int16_t& newX, int16_t& newY);
	virtual void switchPlayer();

protected:
    int score1;
    int score2;
	bool isDragging;        // Top sürükleniyor mu?
	bool isFalling;         // Top düşüyor mu?
	float velocityX;        // X eksenindeki hız
	float velocityY;        // Y eksenindeki hız
	int16_t prevDragX;      // Son sürükleme X noktası
	int16_t prevDragY;      // Son sürükleme Y noktası
	bool hasScored;         // Top çemberden geçti mi?
	bool wasDragged;        // Top daha önce sürüklendi mi?
	bool isMenuOpen;
    int currentPlayer;
    int16_t playerSwitchTimeout;
    bool isWaitingForSwitch;
    bool isInputBlocked;
    bool wasOverMiddle;



};

#endif // SCREEN2VIEW_HPP
