/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"

Screen1ViewBase::Screen1ViewBase()
{

    __background.setPosition(0, 0, 1024, 600);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    box_main_background.setPosition(0, 0, 1024, 600);
    box_main_background.setColor(touchgfx::Color::getColorFrom24BitRGB(46, 37, 37));

    image_main_background.setXY(0, 0);
    image_main_background.setBitmap(touchgfx::Bitmap(BITMAP_MAIN_BACKGROUND_ID));

    add(__background);
    add(box_main_background);
    add(image_main_background);
}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::action1()
{

}
