#include <gui/screen1_screen/Screen1View.hpp>
#include <BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

#ifndef SIMULATOR
extern "C" {
#include "main.h"
}
#endif

extern int8_t current_position;
extern int8_t images_current_position;
extern Unicode::UnicodeChar coffee_names[2][50];
extern TIM_HandleTypeDef htim3;

typedef enum : uint16_t {
	MOCCA_REMAINING_TIME = 10,
	AMERICANO_REMAINING_TIME = 10,
	ESPRESSO_REMAINING_TIME = 10,
	LATTE_REMAINING_TIME = 10,
	HOT_WATER_REMAINING_TIME = 10
} Remaining_times;

typedef enum : uint8_t {
	WORKING_MODE, IDLE_MODE
} modes;
uint8_t flag_working = IDLE_MODE;
uint16_t time_remaining = 0;
uint16_t time_whole = 0;
uint16_t initial_progress_value = 0;
uint16_t max_progress_value = 0;
uint16_t previous_time_remaining = 0;
extern uint8_t coffee_count;

Screen1View::Screen1View() {

}

void Screen1View::setupScreen() {
	if (coffee_count > 0) {
		time_remaining = ESPRESSO_REMAINING_TIME;
		time_whole = ESPRESSO_REMAINING_TIME;
		imageProgress1.setBackground(
				touchgfx::Bitmap(BITMAP_ESPRESSO_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_ESPRESSO_ID);
		initial_progress_value = 30;
		imageProgress1.setValue(initial_progress_value);
		max_progress_value = 50;

		if (images_current_position == 2) {
			customtext.setVisible(true);
			customtext.invalidate();
			customtext.invalidateContent();
			Unicode::snprintf(customtextBuffer, sizeof(customtextBuffer),
					"%s", coffee_names[0]);
			customtext.setWildcard(customtextBuffer);
			customtext.invalidateContent();
		}
		else
		{
			customtext.setVisible(true);
			customtext.invalidate();
			customtext.invalidateContent();
			Unicode::snprintf(customtextBuffer, sizeof(customtextBuffer),
					"%s", coffee_names[1]);
			customtext.setWildcard(customtextBuffer);
			customtext.invalidateContent();
			customtext.invalidate();
		}

		textArea1.setVisible(1);
		textArea1.invalidate();
		textArea1.invalidateContent();
		Unicode::snprintf(remaining_time, 20, "%d", time_remaining);
		textArea1.setWildcard(remaining_time);
		textArea1.invalidateContent();
		make_coffee();
		HAL_TIM_Base_Start_IT(&htim3);
		flag_working = WORKING_MODE;
		__HAL_TIM_SET_COUNTER(&htim3, 0);
		return;
	}
	switch (current_position) {
	case 0:
		time_remaining = ESPRESSO_REMAINING_TIME;
		time_whole = ESPRESSO_REMAINING_TIME;
		customtext.setVisible(1);
		customtext.invalidate();
		imageProgress1.setBackground(
				touchgfx::Bitmap(BITMAP_ESPRESSO_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_ESPRESSO_ID);
		break;
	case 1:
		time_remaining = HOT_WATER_REMAINING_TIME;
		time_whole = HOT_WATER_REMAINING_TIME;
		hotwatertext.setVisible(1);
		hotwatertext.invalidate();
		imageProgress1.setBackground(
				touchgfx::Bitmap(BITMAP_HOT_WATER_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_HOT_WATER_ID);
		initial_progress_value = 20;
		imageProgress1.setValue(initial_progress_value);
		max_progress_value = 75;
		break;
	case 2:
		time_remaining = LATTE_REMAINING_TIME;
		time_whole = LATTE_REMAINING_TIME;
		lattetext.setVisible(1);
		lattetext.invalidate();
		imageProgress1.setBackground(touchgfx::Bitmap(BITMAP_LATTE_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_LATTE_ID);
		initial_progress_value = 5;
		imageProgress1.setValue(initial_progress_value);
		max_progress_value = 100;
		break;
	case 3:
		time_remaining = AMERICANO_REMAINING_TIME;
		time_whole = AMERICANO_REMAINING_TIME;
		americanotext.setVisible(1);
		americanotext.invalidate();
		imageProgress1.setBackground(
				touchgfx::Bitmap(BITMAP_AMERICANO_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_AMERICANO_ID);
		initial_progress_value = 20;
		imageProgress1.setValue(initial_progress_value);
		max_progress_value = 80;
		break;
	case 4:
		time_remaining = ESPRESSO_REMAINING_TIME;
		time_whole = ESPRESSO_REMAINING_TIME;
		espressotext.setVisible(1);
		espressotext.invalidate();
		imageProgress1.setBackground(
				touchgfx::Bitmap(BITMAP_ESPRESSO_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_ESPRESSO_ID);
		initial_progress_value = 30;
		imageProgress1.setValue(initial_progress_value);
		max_progress_value = 50;
		break;
	case 5:
		time_remaining = MOCCA_REMAINING_TIME;
		time_whole = MOCCA_REMAINING_TIME;
		moccatext.setVisible(1);
		moccatext.invalidate();
		imageProgress1.setBackground(
				touchgfx::Bitmap(BITMAP_MOCHACCINO_EMPTY_ID));
		imageProgress1.setBitmap(BITMAP_MOCHACCINO_ID);
		initial_progress_value = 30;
		imageProgress1.setValue(initial_progress_value);
		max_progress_value = 100;
		break;
	default:
		break;
	}
	customtext.setVisible(false);
	customtext.invalidate();
	textArea1.setVisible(1);
	textArea1.invalidate();
	textArea1.invalidateContent();
	Unicode::snprintf(remaining_time, 20, "%d", time_remaining);
	textArea1.setWildcard(remaining_time);
	textArea1.invalidateContent();
	make_coffee();
	HAL_TIM_Base_Start_IT(&htim3);
	flag_working = WORKING_MODE;
	__HAL_TIM_SET_COUNTER(&htim3, 0);
}

void Screen1View::tearDownScreen() {
	Screen1ViewBase::tearDownScreen();
}
int32_t count = 0;
int32_t count_2 = 0;

void Screen1View::make_coffee() {
	count++;
	if (time_remaining == previous_time_remaining)
		return;

	if ((int16_t) time_remaining < 0) {

		HAL_TIM_Base_Stop_IT(&htim3);
		flag_working = IDLE_MODE;
		application().gotoscreenScreenNoTransition();
		return;
	}
	textArea1.setVisible(1);
	textArea1.invalidate();
	textArea1.invalidateContent();
	Unicode::snprintf(remaining_time, 20, "%d", time_remaining);
	textArea1.setWildcard(remaining_time);
	textArea1.invalidateContent();

	float progress_value = initial_progress_value
			+ ((max_progress_value - initial_progress_value)
					/ (float) time_whole) * (time_whole - time_remaining);
	imageProgress1.setValue(progress_value);
	previous_time_remaining = time_remaining;
}

