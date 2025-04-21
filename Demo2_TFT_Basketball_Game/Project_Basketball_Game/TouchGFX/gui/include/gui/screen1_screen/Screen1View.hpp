#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Widget.hpp> // Widget sınıfını dahil edin

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	virtual void handleClickEvent(const touchgfx::ClickEvent& event);
	virtual void handleDragEvent(const touchgfx::DragEvent& event);
	virtual void handleTickEvent();
	virtual void updateCountdownText();
	virtual void updateBasketCounter();
	virtual void setupGameState();
	virtual void handleButtonClick(const touchgfx::ClickEvent& event);
	virtual void handleTopPress(const touchgfx::ClickEvent& event);
	virtual void handleTopRelease();
	virtual void restart();
	virtual void updateCounter(Unicode::UnicodeChar* buffer, size_t bufferSize, int value, touchgfx::TextArea& textArea);
	virtual void updateTopPosition(int16_t deltaX, int16_t deltaY);
	virtual int16_t clamp(int16_t value, int16_t min, int16_t max);
	virtual void checkCollisionWithBackboard(int16_t topCenterX, int16_t topCenterY, int16_t& newX, int16_t& newY);
	virtual void checkCollisionWithRim(int16_t topCenterX, int16_t topCenterY, int16_t& newX, int16_t& newY);
	virtual void checkIfScored(int16_t topCenterX, int16_t topCenterY);
	virtual void handleBoundaries(int16_t& newX, int16_t& newY);
	virtual void updateCountdown();
	virtual void openMenu();
	virtual void goBack();





protected:
	bool isDragging;        // Top sürükleniyor mu?
	bool isFalling;         // Top düşüyor mu?
	float velocityX;        // X eksenindeki hız
	float velocityY;        // Y eksenindeki hız
	int16_t prevDragX;      // Son sürükleme X noktası
	int16_t prevDragY;      // Son sürükleme Y noktası
	int16_t countdownTime;  // Geri sayım süresi (saniye cinsinden)
	bool isCountdownActive; // Geri sayım aktif mi?
	int16_t basketCount;    // Basket sayacı
	bool hasScored;         // Top çemberden geçti mi?
	bool wasDragged;        // Top daha önce sürüklendi mi?
	bool isMenuOpen;


};

#endif // SCREEN1VIEW_HPP
