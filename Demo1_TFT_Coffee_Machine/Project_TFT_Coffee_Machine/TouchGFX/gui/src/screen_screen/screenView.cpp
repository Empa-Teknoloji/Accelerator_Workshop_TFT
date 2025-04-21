#include <gui/screen_screen/screenView.hpp>
#include <BitmapDatabase.hpp>
// Y coordinates
int32_t position1_y = 70;

// X coordinates
int32_t positions_x[] = { -800, -667, -467, -267, -130, 117, 358, 500, 650, 800,1000};
int8_t current_position = 3;

int32_t animation_delay = 10;
screenView::screenView() {
}

void screenView::setupScreen() {
	button1.setAlpha(current_position == 5 ? 100 : 255);
	button2.setAlpha(current_position == 0 ? 100 : 255);

	image1.setXY(positions_x[(current_position + 0)], position1_y);
	image1.setBitmap(Bitmap(BITMAP_MOCHACCINO_ID));
	moccatext.setVisible(current_position == 5 );

	image2.setXY(positions_x[(current_position + 1)], position1_y);
	image2.setBitmap(Bitmap(BITMAP_ESPRESSO_ID));
	espressotext.setVisible(current_position == 4);

	image3.setXY(positions_x[(current_position + 2)], position1_y);
	image3.setBitmap(Bitmap(BITMAP_AMERICANO_ID));
	americanotext.setVisible(current_position == 3);

	image4.setXY(positions_x[(current_position + 3)], position1_y);
	image4.setBitmap(Bitmap(BITMAP_LATTE_ID));
	lattetext.setVisible(current_position == 2);

	image5.setXY(positions_x[(current_position + 4)], position1_y);
	image5.setBitmap(Bitmap(BITMAP_HOT_WATER_ID));
	hotwatertext.setVisible(current_position == 1);

	image6.setXY(positions_x[(current_position + 5)], position1_y);
	image6.setBitmap(Bitmap(BITMAP_ESPRESSO_ID));
	customtext.setVisible(current_position == 0);

	selectionbutton.setVisible(current_position != 0) ;
	selectionbutton.invalidate();
	custombutton.setVisible(current_position == 0);
	custombutton.invalidate();

	infobutton.setVisible(true);
	infobutton.invalidate();
	button1.setVisible(true);
	button1.invalidate();
	button2.setVisible(true);
	button2.invalidate();
}

void screenView::tearDownScreen() {
	screenViewBase::tearDownScreen();
}

void screenView::left_button_pressed(void) {
	current_position = (current_position + 1);
	if (current_position > 5)
	{
		current_position = 5;
		return;
	}

	button1.setAlpha(current_position == 5 ? 100 : 255);
	button2.setAlpha(current_position == 0 ? 100 : 255);
	image1.clearMoveAnimationEndedAction();
	image1.setMoveAnimationDelay(animation_delay);
	image1.startMoveAnimation(positions_x[(current_position + 0)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image2.clearMoveAnimationEndedAction();
	image2.setMoveAnimationDelay(animation_delay);
	image2.startMoveAnimation(positions_x[(current_position + 1)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);


	image3.clearMoveAnimationEndedAction();
	image3.setMoveAnimationDelay(animation_delay);
	image3.startMoveAnimation(positions_x[(current_position + 2)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image4.clearMoveAnimationEndedAction();
	image4.setMoveAnimationDelay(animation_delay);
	image4.startMoveAnimation(positions_x[(current_position + 3)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);


	image5.clearMoveAnimationEndedAction();
	image5.setMoveAnimationDelay(animation_delay);
	image5.startMoveAnimation(positions_x[(current_position + 4)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image6.clearMoveAnimationEndedAction();
	image6.setMoveAnimationDelay(animation_delay);
	image6.startMoveAnimation(positions_x[(current_position + 5)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);


	moccatext.setVisible(current_position == 5);
	moccatext.invalidate();
	espressotext.setVisible(current_position == 4);
	espressotext.invalidate();
	americanotext.setVisible(current_position == 3);
	americanotext.invalidate();
	lattetext.setVisible(current_position == 2);
	lattetext.invalidate();
	hotwatertext.setVisible(current_position == 1);
	hotwatertext.invalidate();
	customtext.setVisible(current_position == 0);
	customtext.invalidate();

	selectionbutton.setVisible(current_position != 0) ;
	selectionbutton.invalidate();
	custombutton.setVisible(current_position == 0);
	custombutton.invalidate();
}

void screenView::right_click_pressed(void) {
	current_position = (current_position - 1);
	if (current_position < 0)
	{
		current_position = 0;
		return;
	}
	button1.setAlpha(current_position == 5 ? 100 : 255);
	button2.setAlpha(current_position == 0 ? 100 : 255);
	image1.clearMoveAnimationEndedAction();
	image1.setMoveAnimationDelay(animation_delay);
	image1.startMoveAnimation(positions_x[(current_position + 0)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image2.clearMoveAnimationEndedAction();
	image2.setMoveAnimationDelay(animation_delay);
	image2.startMoveAnimation(positions_x[(current_position + 1)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image3.clearMoveAnimationEndedAction();
	image3.setMoveAnimationDelay(animation_delay);
	image3.startMoveAnimation(positions_x[(current_position + 2)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image4.clearMoveAnimationEndedAction();
	image4.setMoveAnimationDelay(animation_delay);
	image4.startMoveAnimation(positions_x[(current_position + 3)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image5.clearMoveAnimationEndedAction();
	image5.setMoveAnimationDelay(animation_delay);
	image5.startMoveAnimation(positions_x[(current_position + 4)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	image6.clearMoveAnimationEndedAction();
	image6.setMoveAnimationDelay(animation_delay);
	image6.startMoveAnimation(positions_x[(current_position + 5)], position1_y,
			animation_delay, touchgfx::EasingEquations::linearEaseIn,
			touchgfx::EasingEquations::linearEaseIn);

	moccatext.setVisible(current_position == 5);
	moccatext.invalidate();
	espressotext.setVisible(current_position == 4);
	espressotext.invalidate();
	americanotext.setVisible(current_position == 3);
	americanotext.invalidate();
	lattetext.setVisible(current_position == 2);
	lattetext.invalidate();
	hotwatertext.setVisible(current_position == 1);
	hotwatertext.invalidate();
	customtext.setVisible(current_position == 0);
	customtext.invalidate();

	selectionbutton.setVisible(current_position != 0) ;
	selectionbutton.invalidate();
	custombutton.setVisible(current_position == 0);
	custombutton.invalidate();
}
