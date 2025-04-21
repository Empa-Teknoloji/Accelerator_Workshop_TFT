#ifndef KEYBOARDPRESENTER_HPP
#define KEYBOARDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class keyboardView;

class keyboardPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    keyboardPresenter(keyboardView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~keyboardPresenter() {}

private:
    keyboardPresenter();

    keyboardView& view;
};

#endif // KEYBOARDPRESENTER_HPP
