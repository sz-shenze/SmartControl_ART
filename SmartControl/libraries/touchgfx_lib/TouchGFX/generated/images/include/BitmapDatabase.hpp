// Generated by imageconverter. Please, do not edit!

#ifndef BITMAPDATABASE_HPP
#define BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_LIGHTS_BLUE_ID = 0;
const uint16_t BITMAP_LIGHTS_YELLOW_ID = 1;
const uint16_t BITMAP_MAIN_BACKGROUND_ID = 2;

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
}

#endif
