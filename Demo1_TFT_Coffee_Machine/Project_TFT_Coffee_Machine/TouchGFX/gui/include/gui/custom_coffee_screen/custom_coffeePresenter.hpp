#ifndef CUSTOM_COFFEEPRESENTER_HPP
#define CUSTOM_COFFEEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class custom_coffeeView;

class custom_coffeePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    custom_coffeePresenter(custom_coffeeView& v);

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

    virtual ~custom_coffeePresenter() {}

private:
    custom_coffeePresenter();

    custom_coffeeView& view;
};

#endif // CUSTOM_COFFEEPRESENTER_HPP
