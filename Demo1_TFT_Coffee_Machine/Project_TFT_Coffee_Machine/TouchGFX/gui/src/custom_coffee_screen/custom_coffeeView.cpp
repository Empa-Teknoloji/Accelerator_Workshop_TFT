#include <gui/custom_coffee_screen/custom_coffeeView.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <BitmapDatabase.hpp>

uint8_t coffee_count = 0;
uint8_t keyboard_pressed = 0;
uint16_t slider1_last_value = 50;
uint16_t slider2_last_value = 50;
uint16_t slider3_last_value = 50;
int32_t images_positions_x[9] = { -610, -410, -210, -110, 110, 360, 510, 660,
		810 };
int32_t images_positions_y = 70;
int8_t images_current_position = 2;
int32_t texts_positions_x[9] = { -1000, -900, -216, -144, 107, 365, 463, 700,
		800 };
uint8_t texts_positions_y = 160;
int8_t texts_current_position = 2;
int32_t animation_delay_custom_coffee = 10;
#define COFFEE_SIZE_SMALL_MAX   33
#define COFFEE_SIZE_MEDIUM_MAX  66
#define COFFEE_SIZE_LARGE_MAX   100


typedef enum {
	COFFEE_SIZE_SMALL = 0, COFFEE_SIZE_MEDIUM = 50, COFFEE_SIZE_LARGE = 100
} CoffeeSize;

int8_t current_position_custom_coffee = 3;
CoffeeSize coffee_size = COFFEE_SIZE_MEDIUM;
CoffeeSize coffee_size_1 = COFFEE_SIZE_MEDIUM;
CoffeeSize coffee_size_2 = COFFEE_SIZE_MEDIUM;
CoffeeSize coffee_size_3 = COFFEE_SIZE_MEDIUM;

Unicode::UnicodeChar coffee_names[2][50];

void setWidgetsVisible(touchgfx::Drawable *widgets[], size_t count,
		bool visible);
void setSliderWithClassification(touchgfx::Slider &slider, int value,
		CoffeeSize &outSize);
extern Unicode::UnicodeChar global_keyboard_buffer[30];

custom_coffeeView::custom_coffeeView() {

	if (coffee_count != 0) {
		touchgfx::Drawable *show[] = { &custom_coffee_back, &image8,
				&textArea1, &no_custom_coffee_text, &no_coffee_button,
				&box2, &make_custom_coffee };
		setWidgetsVisible(show, sizeof(show) / sizeof(show[0]), true);

		touchgfx::Drawable *hide[] = { &slider1, &slider2, &slider3, &textArea2,
				&textArea3, &textArea4, &enter_name_button, &textArea9,
				&textArea7, &cancel_button, &save_button, &textArea10,
				&textArea11, &box5, &box4, &box3, &no_coffee_text_1, &no_coffee_text_2 };
		setWidgetsVisible(hide, sizeof(hide) / sizeof(hide[0]), false);
		switch (coffee_count) {
		case 1:
			Unicode::snprintf(coffee_nameBuffer, sizeof(coffee_nameBuffer),
					"%s", coffee_names[0]);
			coffee_name.setWildcard(coffee_nameBuffer);
			coffee_name.invalidate();
			image3.setVisible(true);
			image3.invalidate();
			coffee_name.setVisible(true);
			coffee_name.invalidate();
			break;
		case 2:
			Unicode::snprintf(coffee_nameBuffer, sizeof(coffee_nameBuffer),
					"%s", coffee_names[0]);
			coffee_name.setWildcard(coffee_nameBuffer);
			coffee_name.invalidate();
			Unicode::snprintf(coffee_name_2Buffer, sizeof(coffee_name_2Buffer),
					"%s", coffee_names[1]);
			coffee_name_2.setWildcard(coffee_name_2Buffer);
			coffee_name_2.invalidate();

			//Maximum 2 customcoffee
			no_coffee_button.setVisible(false);
			no_coffee_button.invalidate();
			no_custom_coffee_text.setVisible(false);
			no_custom_coffee_text.invalidate();
			box2.setVisible(false);
			box2.invalidate();

			coffee_name.setWildcard(coffee_nameBuffer);
			coffee_name.invalidate();
			image3.setVisible(true);
			image3.invalidate();
			coffee_name.setVisible(true);
			coffee_name.invalidate();
			image4.setVisible(true);
			image4.invalidate();
			coffee_name_3.setVisible(true);
			coffee_name_3.invalidate();
			image2.setVisible(true);
			image2.invalidate();
			button2.setVisible(true);
			button2.invalidate();

		default:
			break;
		}
	}
	if (keyboard_pressed == 1) {
		Unicode::UnicodeChar *name = global_keyboard_buffer;
		custom_coffee_back.setVisible(false);
		custom_coffee_back.invalidate();
		image8.setVisible(false);
		image8.invalidate();
		if (Unicode::strlen(name) > 0) {
			Unicode::snprintf(textArea9Buffer, sizeof(textArea9Buffer), ": %s",
					name);
			textArea9.setWildcard(textArea9Buffer);
			textArea9.invalidate();
			textArea9.resizeToCurrentText();
			textArea9.invalidate();
		}

		keyboard_pressed = 0;
		touchgfx::Drawable *hide[] = { &textArea1, &no_coffee_text_1,
				&no_coffee_text_2, &no_custom_coffee_text, &no_coffee_button,
				&box2, &image3, &coffee_name };
		setWidgetsVisible(hide, sizeof(hide) / sizeof(hide[0]), false);

		touchgfx::Drawable *show[] = { &slider1, &slider2, &slider3, &textArea2,
				&textArea3, &textArea4, &enter_name_button, &textArea9,
				&textArea7, &cancel_button, &save_button, &textArea10,
				&textArea11, &box5, &box4, &box3 };
		setWidgetsVisible(show, sizeof(show) / sizeof(show[0]), true);
		setSliderWithClassification(slider1, slider1_last_value, coffee_size_1);
		setSliderWithClassification(slider2, slider2_last_value, coffee_size_2);
		setSliderWithClassification(slider3, slider3_last_value, coffee_size_3);
	}
}

void custom_coffeeView::setupScreen() {
	custom_coffeeViewBase::setupScreen();
}

void custom_coffeeView::tearDownScreen() {
	custom_coffeeViewBase::tearDownScreen();
}

void custom_coffeeView::no_coffee_button_pressed() {

	touchgfx::Drawable *hide[] = { &textArea1, &no_coffee_text_1,
			&no_coffee_text_2, &no_custom_coffee_text, &no_coffee_button, &box2,
			&image1, &image2, &coffee_name, &button1, &button2, &image3,
			&image4, &image5, &image6, &image7, &custom_coffee_back, &image8 };
	setWidgetsVisible(hide, sizeof(hide) / sizeof(hide[0]), false);

	touchgfx::Drawable *show[] = { &slider1, &slider2, &slider3, &textArea2,
			&textArea3, &textArea4, &enter_name_button, &textArea9, &textArea7,
			&cancel_button, &save_button, &textArea10, &textArea11, &box5,
			&box4, &box3 };
	setWidgetsVisible(show, sizeof(show) / sizeof(show[0]), true);

	slider1.setValue(50);
	slider1.invalidate();
	slider2.setValue(50);
	slider2.invalidate();
	slider3.setValue(50);
	slider3.invalidate();
	Unicode::UnicodeChar *name = global_keyboard_buffer;
	Unicode::snprintf(textArea9Buffer, sizeof(textArea9Buffer), "", name);
	textArea9.setWildcard(textArea9Buffer);
	textArea9.invalidate();
	textArea9.resizeToCurrentText();
	textArea9.invalidate();
}

void custom_coffeeView::cancel_button_pressed() {

	touchgfx::Drawable *hide[] = { &slider1, &slider2, &slider3, &textArea2,
			&textArea3, &textArea4, &enter_name_button, &textArea9, &textArea7,
			&cancel_button, &save_button, &textArea10, &textArea11, &box5,
			&box4, &box3 };
	setWidgetsVisible(hide, sizeof(hide) / sizeof(hide[0]), false);

	if (coffee_count == 0) {
		touchgfx::Drawable *show[] = { &textArea1, &no_coffee_text_1,
				&no_coffee_text_2, &no_custom_coffee_text, &no_coffee_button,
				&box2, &custom_coffee_back, &image8 };
		setWidgetsVisible(show, sizeof(show) / sizeof(show[0]), true);
	} else {
		touchgfx::Drawable *show[] = { &image3, &image4, &image5, &image6,
				&image7, &textArea1, &coffee_name, &button1, &button2, &image1,
				&image2, &no_coffee_button, &box2, &no_custom_coffee_text,
		&custom_coffee_back, &image8};
		setWidgetsVisible(show, sizeof(show) / sizeof(show[0]), true);
	}
}

void custom_coffeeView::enter_name_pressed() {
	keyboard_pressed = 1;
	static_cast<FrontendApplication*>(Application::getInstance())->gotokeyboardScreenNoTransition();
}

void custom_coffeeView::save_button_pressed() {
	Unicode::UnicodeChar *name = global_keyboard_buffer;
	Unicode::snprintf(coffee_names[coffee_count], sizeof(50), "%s", name);
	if (Unicode::strlen(name) > 0) {

		touchgfx::Drawable *hide[] = { &no_coffee_text_1, &no_coffee_text_2,
				&slider1, &textArea2, &textArea3, &textArea4, &textArea7,
				&slider2, &slider3, &box3, &textArea9, &box4, &box5,
				&textArea10, &textArea11, &enter_name_button,
				&enter_name_button, &cancel_button, &save_button };
		setWidgetsVisible(hide, sizeof(hide) / sizeof(hide[0]), false);

		touchgfx::Drawable *show[] = { &image3, &image4, &image5, &image6,
				&image7, &textArea1, &coffee_name, &button1, &button2, &image1,
				&image2, &no_coffee_button, &box2, &no_custom_coffee_text,
				&custom_coffee_back, &image8, &make_custom_coffee};
		setWidgetsVisible(show, sizeof(show) / sizeof(show[0]), true);

		coffee_count = coffee_count + 1;
		switch (coffee_count) {
		case 1:
			button1.setVisible(false);
			button1.invalidate();
			button2.setVisible(false);
			button2.invalidate();
			image1.setVisible(false);
			image1.invalidate();
			image2.setVisible(false);
			image2.invalidate();
			Unicode::strncpy(coffee_names[0], name, 49);
			coffee_names[0][49] = '\0';
			Unicode::snprintf(coffee_nameBuffer, sizeof(coffee_nameBuffer),
					"%s", name);
			Unicode::snprintf(coffee_nameBuffer, sizeof(coffee_nameBuffer),
					"%s", name);
			coffee_name.setWildcard(coffee_nameBuffer);
			coffee_name.invalidate();

			break;
		case 2:
			button1.setVisible(false);
			button1.invalidate();
			image1.setVisible(false);
			image1.invalidate();
			Unicode::snprintf(coffee_name_2Buffer, sizeof(coffee_name_2Buffer),
					"%s", name);
			coffee_name_3.setWildcard(coffee_name_2Buffer);
			coffee_name_3.invalidate();

			//Maximum 2 customcoffee
			no_coffee_button.setVisible(false);
			no_coffee_button.invalidate();
			no_custom_coffee_text.setVisible(false);
			no_custom_coffee_text.invalidate();
			box2.setVisible(false);
			box2.invalidate();
		default:
			break;
		}
	}
}

void custom_coffeeView::left_button_pressed() {
	images_current_position = (images_current_position + 1);
	texts_current_position = (texts_current_position + 1);

	if (images_current_position > 4) {
		images_current_position = 4;
		texts_current_position = 4;
		return;
	}

	switch (coffee_count) {
	case 1:
		return;
	case 2:
		button2.setVisible(true);
		button2.invalidate();
		image2.setVisible(true);
		image2.invalidate();
		button1.setVisible(false);
		button1.invalidate();
		image1.setVisible(false);
		image1.invalidate();

		image3.clearMoveAnimationEndedAction();
		image3.setMoveAnimationDelay(animation_delay_custom_coffee);
		image3.startMoveAnimation(images_positions_x[4], images_positions_y,
				animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);
		coffee_name.clearMoveAnimationEndedAction();
		coffee_name.setMoveAnimationDelay(animation_delay_custom_coffee);
		coffee_name.startMoveAnimation(texts_positions_x[4], texts_positions_y,
				animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);

		image4.clearMoveAnimationEndedAction();
		image4.setMoveAnimationDelay(animation_delay_custom_coffee);
		image4.startMoveAnimation(images_positions_x[3], images_positions_y,
				animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);
		coffee_name_3.clearMoveAnimationEndedAction();
		coffee_name_3.setMoveAnimationDelay(animation_delay_custom_coffee);
		coffee_name_3.startMoveAnimation(texts_positions_x[3],
				texts_positions_y, animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);
		return;
	default:
		break;
	}
}

void custom_coffeeView::right_button_pressed() {
	images_current_position = (images_current_position - 1);
	texts_current_position = (texts_current_position - 1);

	if (images_current_position < 0) {
		images_current_position = 0;
		texts_current_position = 0;
		return;
	}
	switch (coffee_count) {
	case 1:
		return;
	case 2:
		button2.setVisible(false);
		button2.invalidate();
		image2.setVisible(false);
		image2.invalidate();
		button1.setVisible(true);
		button1.invalidate();
		image1.setVisible(true);
		image1.invalidate();


		image4.clearMoveAnimationEndedAction();
		image4.setMoveAnimationDelay(animation_delay_custom_coffee);
		image4.startMoveAnimation(images_positions_x[4], images_positions_y,
				animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);
		coffee_name_3.clearMoveAnimationEndedAction();
		coffee_name_3.setMoveAnimationDelay(animation_delay_custom_coffee);
		coffee_name_3.startMoveAnimation(texts_positions_x[4],
				texts_positions_y, animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);

		image3.clearMoveAnimationEndedAction();
		image3.setMoveAnimationDelay(animation_delay_custom_coffee);
		image3.startMoveAnimation(images_positions_x[5], images_positions_y,
				animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);
		coffee_name.clearMoveAnimationEndedAction();
		coffee_name.setMoveAnimationDelay(animation_delay_custom_coffee);
		coffee_name.startMoveAnimation(texts_positions_x[5], texts_positions_y,
				animation_delay_custom_coffee,
				touchgfx::EasingEquations::linearEaseIn,
				touchgfx::EasingEquations::linearEaseIn);
		return;
	default:
		break;
	}
}

void custom_coffeeView::adjust_slider1(int value) {
	slider1_last_value = value;
	if (value <= COFFEE_SIZE_SMALL_MAX) {
		slider1.setValue(0);
		slider1.invalidate();
		coffee_size = COFFEE_SIZE_SMALL;
	} else if (value <= COFFEE_SIZE_MEDIUM_MAX) {
		slider1.setValue(50);
		slider1.invalidate();
		coffee_size = COFFEE_SIZE_MEDIUM;
	} else
		slider1.setValue(100);
	slider1.invalidate();
	coffee_size = COFFEE_SIZE_LARGE;
}

void custom_coffeeView::adjust_slider2(int value) {
	slider2_last_value = value;
	if (value <= COFFEE_SIZE_SMALL_MAX) {
		slider2.setValue(0);
		slider2.invalidate();
		coffee_size = COFFEE_SIZE_SMALL;
	} else if (value <= COFFEE_SIZE_MEDIUM_MAX) {
		slider2.setValue(50);
		slider2.invalidate();
		coffee_size = COFFEE_SIZE_MEDIUM;
	} else {
		slider2.setValue(100);
		slider2.invalidate();
		coffee_size = COFFEE_SIZE_LARGE;
	}

}

void custom_coffeeView::adjust_slider3(int value) {
	slider3_last_value = value;
	if (value <= COFFEE_SIZE_SMALL_MAX) {
		slider3.setValue(0);
		slider3.invalidate();
		coffee_size = COFFEE_SIZE_SMALL;
	} else if (value <= COFFEE_SIZE_MEDIUM_MAX) {
		slider3.setValue(50);
		slider3.invalidate();
		coffee_size = COFFEE_SIZE_MEDIUM;
	} else {
		slider3.setValue(100);
		slider3.invalidate();
		coffee_size = COFFEE_SIZE_LARGE;
	}

}

void setWidgetsVisible(touchgfx::Drawable *widgets[], size_t count,
		bool visible) {
	for (size_t i = 0; i < count; ++i) {
		widgets[i]->setVisible(visible);
		widgets[i]->invalidate();
	}
}

CoffeeSize getCoffeeSize(int value) {
	if (value <= COFFEE_SIZE_SMALL_MAX) {
		return COFFEE_SIZE_SMALL;
	} else if (value <= COFFEE_SIZE_MEDIUM_MAX) {
		return COFFEE_SIZE_MEDIUM;
	} else {
		return COFFEE_SIZE_LARGE;
	}
}

void setSliderWithClassification(touchgfx::Slider &slider, int value,
		CoffeeSize &outSize) {

	slider.setValue(getCoffeeSize(value));
	slider.invalidate();
	outSize = getCoffeeSize(value);
}
