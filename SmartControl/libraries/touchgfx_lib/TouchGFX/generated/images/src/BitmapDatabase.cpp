// 4.16.0 0x6ea97eed
// Generated by imageconverter. Please, do not edit!

#include <BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_lights_blue[]; // BITMAP_LIGHTS_BLUE_ID = 0, Size: 100x100 pixels
extern const unsigned char image_lights_yellow[]; // BITMAP_LIGHTS_YELLOW_ID = 1, Size: 100x100 pixels
extern const unsigned char image_main_background[]; // BITMAP_MAIN_BACKGROUND_ID = 2, Size: 1024x600 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] =
{
    { image_lights_blue, 0, 100, 100, 15, 15, 70, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 70, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_lights_yellow, 0, 100, 100, 1, 1, 98, (uint8_t)(touchgfx::Bitmap::ARGB8888) >> 3, 98, (uint8_t)(touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_main_background, 0, 1024, 600, 0, 0, 1024, (uint8_t)(touchgfx::Bitmap::RGB888) >> 3, 600, (uint8_t)(touchgfx::Bitmap::RGB888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
}