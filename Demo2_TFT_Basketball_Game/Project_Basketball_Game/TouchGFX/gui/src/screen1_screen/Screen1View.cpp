#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <cmath>

namespace {
    const float GRAVITY = 0.4f;
    const float FRICTION = 0.98f;
    const float BOUNCE_FACTOR = 0.7f;
    const float VELOCITY_FACTOR =0.8f;
    const int16_t INITIAL_COUNTDOWN = 30;
    const int16_t BASKET_RADIUS_X = 15;
    const int16_t BASKET_RADIUS_Y = 15;
    const int16_t POTA_CEMBER_MERKEZ_X = 238;
    const int16_t POTA_CEMBER_MERKEZ_Y = 110;
    const int16_t SCREEN_WIDTH=320;
    const int16_t SCREEN_HIGH=240;
    const touchgfx::Rect POTA_TAHTA_RECT(265, 70, 3, 50);
    const touchgfx::Rect POTA_CEMBER_ON_UCU(215, 110, 1, 1);
    const int16_t RESTART_LOCATION_X=160;
    const int16_t RESTART_LOCATION_Y=100;

}

Screen1View::Screen1View() :
    isDragging(false),
    isFalling(true),
    velocityX(0),
    velocityY(0),
    prevDragX(0),
    prevDragY(0),
    countdownTime(INITIAL_COUNTDOWN),
    isCountdownActive(true),
    basketCount(0),
    hasScored(false),
    wasDragged(false),
	isMenuOpen(false)
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    setupGameState();

    screen1.setVisible(false);
    screen2.setVisible(false);
    BackButton.setVisible(false);

}


void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleClickEvent(const touchgfx::ClickEvent& event)
{
    int16_t touchX = event.getX();
    int16_t touchY = event.getY();

    if (isMenuOpen)
    {
        if (BackButton.getRect().intersect(touchX, touchY))
        {
            goBack();
        }
        if (screen1.getRect().intersect(touchX, touchY))
        {
            application().gotoScreen1ScreenSlideTransitionWest();
            return;
        }
        if (screen2.getRect().intersect(touchX, touchY))
        {
            application().gotoScreen2ScreenSlideTransitionEast();
            return;
        }
        return;
    }

    if (event.getType() == touchgfx::ClickEvent::PRESSED)
        {
            if (MenuButton.getRect().intersect(touchX, touchY))
            {
                openMenu();
                return;
            }

        }

    if (!isCountdownActive)
    {
        handleButtonClick(event);
        return;
    }

    switch (event.getType())
    {
        case touchgfx::ClickEvent::PRESSED:
            handleTopPress(event);
            break;
        case touchgfx::ClickEvent::RELEASED:
            handleTopRelease();
            break;
        default:
            break;
    }
}


void Screen1View::handleDragEvent(const touchgfx::DragEvent& event)
{
    if (!isCountdownActive || !isDragging)
    {
        return;
    }

    updateTopPosition(event.getDeltaX(), event.getDeltaY());
}

void Screen1View::handleTickEvent()
{
    if (!isCountdownActive) return;

    if (isFalling)
    {
        int16_t currentX = topImage.getX();
        int16_t currentY = topImage.getY();

        int16_t topCenterX = currentX + (topImage.getWidth() / 2);
        int16_t topCenterY = currentY + (topImage.getHeight() / 2);

        velocityY += GRAVITY;

        int16_t newX = currentX + velocityX;
        int16_t newY = currentY + velocityY;

        checkCollisionWithBackboard(topCenterX, topCenterY, newX, newY);
        checkCollisionWithRim(topCenterX, topCenterY, newX, newY);
        checkIfScored(topCenterX, topCenterY);
        handleBoundaries(newX, newY);

        velocityX *= FRICTION;

        if (newX != currentX || newY != currentY)
        {
            touchgfx::Rect dirtyRect(currentX, currentY,
                                      topImage.getWidth(), topImage.getHeight());
            dirtyRect.expandToFit(touchgfx::Rect(newX, newY,
                                      topImage.getWidth(), topImage.getHeight()));

            topImage.setXY(newX, newY);
            invalidateRect(dirtyRect);
        }
    }

    updateCountdown();
}

void Screen1View::checkCollisionWithBackboard(int16_t topCenterX, int16_t topCenterY, int16_t& newX, int16_t& newY)
{
    if (!topImage.getRect().intersect(POTA_TAHTA_RECT)) return;

    if (topCenterY <= POTA_TAHTA_RECT.y)
    {
        velocityY = -velocityY * BOUNCE_FACTOR;
        newY = POTA_TAHTA_RECT.y - topImage.getHeight();
    }
    else if (topCenterX <= POTA_TAHTA_RECT.x)
    {
        velocityX = -velocityX * BOUNCE_FACTOR;
        newX = POTA_TAHTA_RECT.x - topImage.getWidth();
    }
    else if (topCenterX >= POTA_TAHTA_RECT.right())
    {
        velocityX = -velocityX * BOUNCE_FACTOR;
        newX = POTA_TAHTA_RECT.right();
    }
}

void Screen1View::checkCollisionWithRim(int16_t topCenterX, int16_t topCenterY, int16_t& newX, int16_t& newY)
{
    if (!topImage.getRect().intersect(POTA_CEMBER_ON_UCU)) return;

    if (topCenterY <= POTA_CEMBER_ON_UCU.y)
    {
        velocityY = -velocityY * BOUNCE_FACTOR;
        newY = POTA_CEMBER_ON_UCU.y - topImage.getHeight();
    }
    else if (topCenterX <= POTA_CEMBER_ON_UCU.x)
    {
        velocityX = -velocityX * BOUNCE_FACTOR;
        newX = POTA_CEMBER_ON_UCU.x - topImage.getWidth();
    }
    else if (topCenterX >= POTA_CEMBER_ON_UCU.right())
    {
        velocityX = -velocityX * BOUNCE_FACTOR;
        newX = POTA_CEMBER_ON_UCU.right();
    }
}

void Screen1View::checkIfScored(int16_t topCenterX, int16_t topCenterY)
{
    bool isInBasket = abs(topCenterX - POTA_CEMBER_MERKEZ_X) < BASKET_RADIUS_X && abs(topCenterY - POTA_CEMBER_MERKEZ_Y) < BASKET_RADIUS_Y;

    if (isInBasket && !hasScored)
    {
        hasScored = true;
        basketCount++;
        Unicode::snprintf(basketCounterBuffer, BASKETCOUNTER_SIZE, "%d", basketCount);
        basketCounter.invalidate();
    }
    else if (!isInBasket)
    {
        hasScored = false;
    }
}

void Screen1View::handleBoundaries(int16_t& newX, int16_t& newY)
{
    if (newY + topImage.getHeight() >= SCREEN_HIGH)
    {
        newY = SCREEN_HIGH - topImage.getHeight();
        velocityY = -velocityY * BOUNCE_FACTOR;
        if (fabs(velocityY) < 2.0f) velocityY = 0;
        if (fabs(velocityX) < 0.5f) velocityX = 0;
        if (velocityX == 0 && velocityY == 0) isFalling = false;
    }
    if (newY < 0)
    {
        newY = 0;
        velocityY = -velocityY * BOUNCE_FACTOR;
    }
    if (newX < 0)
    {
        newX = 0;
        velocityX = -velocityX * BOUNCE_FACTOR;
    }
    if (newX + topImage.getWidth() > SCREEN_WIDTH)
    {
        newX = SCREEN_WIDTH - topImage.getWidth();
        velocityX = -velocityX * BOUNCE_FACTOR;
    }
}

void Screen1View::updateCountdown()
{
    if (!isCountdownActive || countdownTime <= 0) return;
    static uint16_t tickCount = 0;
    tickCount++;
    if (tickCount % 60 == 0)
    {
        countdownTime--;
        Unicode::snprintf(counterBuffer, COUNTER_SIZE, "%d", countdownTime);
        counter.invalidate();
        if (countdownTime == 0)
        {
            isCountdownActive = false;
            restartButton.setVisible(true);
            restartButton.invalidate();
        }
    }
}

void Screen1View::setupGameState()
{
    updateCountdownText();
    updateBasketCounter();
    restartButton.setVisible(false);
    restartButton.invalidate();
}

void Screen1View::updateCountdownText()
{
    Unicode::snprintf(counterBuffer, COUNTER_SIZE, "%d", countdownTime);
    counter.invalidate();
}

void Screen1View::updateBasketCounter()
{
    Unicode::snprintf(basketCounterBuffer, BASKETCOUNTER_SIZE, "%d", basketCount);
    basketCounter.invalidate();
}

void Screen1View::handleButtonClick(const touchgfx::ClickEvent& event)
{
    if (event.getType() == touchgfx::ClickEvent::PRESSED)
    {
        int16_t touchX = event.getX();
        int16_t touchY = event.getY();
        touchgfx::Rect buttonRect = restartButton.getRect();

        if (buttonRect.intersect(touchX, touchY))
        {
            restart();
        }
    }
}

void Screen1View::handleTopPress(const touchgfx::ClickEvent& event)
{
    int16_t touchX = event.getX();
    int16_t touchY = event.getY();
    touchgfx::Rect topRect = topImage.getRect();

    if (topRect.intersect(touchX, touchY))
    {
        isDragging = true;
        isFalling = false;
        velocityX = 0;
        velocityY = 0;
        prevDragX = topImage.getX();
        prevDragY = topImage.getY();
        wasDragged = false;
    }
}

void Screen1View::handleTopRelease()
{
    if (!isDragging)
        return;

    isDragging = false;

    if (!wasDragged)
    {
        isFalling = true;
        velocityX = 0;
        velocityY = 0;
        return;
    }

    isFalling = true;
    velocityX = (topImage.getX() - prevDragX) * VELOCITY_FACTOR ;
    velocityY = (topImage.getY() - prevDragY) * VELOCITY_FACTOR ;

    if (fabs(velocityX) < 1.0f) velocityX = 0;
    if (fabs(velocityY) < 1.0f) velocityY = 0;
}

void Screen1View::restart()
{
    countdownTime = INITIAL_COUNTDOWN;
    isCountdownActive = true;
    basketCount = 0;

    updateCounter(basketCounterBuffer, BASKETCOUNTER_SIZE, basketCount, basketCounter);
    updateCounter(counterBuffer, COUNTER_SIZE, countdownTime, counter);

    velocityX=0;
	velocityY=0;

    isFalling = true;
	topImage.invalidate();
    topImage.setXY(RESTART_LOCATION_X, RESTART_LOCATION_Y);
    topImage.invalidate();

    restartButton.setVisible(false);
    restartButton.invalidate();
}

void Screen1View::updateCounter(Unicode::UnicodeChar* buffer, size_t bufferSize, int value, touchgfx::TextArea& textArea)
{
    Unicode::snprintf(buffer, bufferSize, "%d", value);
    textArea.invalidate();
}

void Screen1View::updateTopPosition(int16_t deltaX, int16_t deltaY)
{
    int16_t newX = topImage.getX() + deltaX;
    int16_t newY = topImage.getY() + deltaY;

    newX = clamp(newX, 0, SCREEN_WIDTH - topImage.getWidth());
    newY = clamp(newY, 0, SCREEN_HIGH - topImage.getHeight());

    prevDragX = topImage.getX();
    prevDragY = topImage.getY();
    wasDragged = true;

    topImage.invalidate();
    topImage.setXY(newX, newY);
    topImage.invalidate();
}

int16_t Screen1View::clamp(int16_t value, int16_t min, int16_t max)
{
    return (value < min) ? min : (value > max) ? max : value;
}

void Screen1View::openMenu()
{
    isMenuOpen = true;

    screen1.setVisible(true);
    screen2.setVisible(true);
    BackButton.setVisible(true);

    MenuButton.setTouchable(false);
    restartButton.setTouchable(false);

    if (!restartButton.isVisible()) {
        isCountdownActive = false;
    }

    invalidate();
}

void Screen1View::goBack()
{
    isMenuOpen = false;

    screen1.setVisible(false);
    screen2.setVisible(false);
    BackButton.setVisible(false);

    MenuButton.setTouchable(true);
    restartButton.setTouchable(true);

    if (!restartButton.isVisible()) {
        isCountdownActive = true;
    }

    invalidate();
}
