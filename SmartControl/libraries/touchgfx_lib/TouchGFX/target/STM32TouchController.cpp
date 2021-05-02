/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include <rtthread.h>

#ifdef __cplusplus
extern "C"{
#endif

#include "ft5426.h"

#ifdef __cplusplus
}
#endif

rt_device_t touch;
struct rt_touch_data *read_data;



#ifdef PKG_USING_GT9147
#include "gt9147.h"
static rt_device_t  dev = RT_NULL;
static struct       rt_touch_data *read_data = NULL;
static struct       rt_touch_info info;


int gt9147_init(void)
{
    void *id;
    dev = rt_device_find("gt");
    if (dev == RT_NULL)
    {
        rt_kprintf("can't find device gt\n");
        return -1;
    }

    if (rt_device_open(dev, RT_DEVICE_FLAG_INT_RX) != RT_EOK)
    {
        rt_kprintf("open device failed!");
        return -1;
    }
    read_data = (struct rt_touch_data *)rt_malloc(sizeof(struct rt_touch_data) * info.point_num);
    id = rt_malloc(sizeof(rt_uint8_t) * 8);
    rt_device_control(dev, RT_TOUCH_CTRL_GET_ID, id);
    rt_uint8_t * read_id = (rt_uint8_t *)id;
    rt_kprintf("id = %c %c %c %c \n", read_id[0], read_id[1], read_id[2], read_id[3]);

    rt_device_control(dev, RT_TOUCH_CTRL_GET_INFO, &info);
    rt_kprintf("range_x = %d \n", info.range_x);
    rt_kprintf("range_y = %d \n", info.range_y);
    rt_kprintf("point_num = %d \n", info.point_num);

    rt_free(id);

    return 0;
}
#endif

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */

    struct rt_touch_config cfg;

    cfg.dev_name = (char *)("i2c1");
    rt_hw_ft5426_init("touch", &cfg);

    touch = rt_device_find("touch");
    rt_device_open(touch, RT_DEVICE_FLAG_RDONLY);

    struct rt_touch_info info;
    rt_device_control(touch, RT_TOUCH_CTRL_GET_INFO, &info);

    read_data = (struct rt_touch_data *)rt_calloc(1, sizeof(struct rt_touch_data));


#ifdef PKG_USING_GT9147
    gt9147_init();
#endif
}

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
    /**
     * By default sampleTouch returns false,
     * return true if a touch has been detected, otherwise false.
     *
     * Coordinates are passed to the caller by reference by x and y.
     *
     * This function is called by the TouchGFX framework.
     * By default sampleTouch is called every tick, this can be adjusted by HAL::setTouchSampleRate(int8_t);
     *
     */

    if(touch == RT_NULL)
        return false;
    
    rt_device_read(touch, 0, read_data, 1);

    if ((read_data->event == RT_TOUCH_EVENT_DOWN)|| (read_data->event == RT_TOUCH_EVENT_MOVE))
    {
//        rt_kprintf("down x: %03d y: %03d", read_data->x_coordinate, read_data->y_coordinate);
//        rt_kprintf(" t: %d\n", read_data->timestamp);
        //x和y为传回给touchGFX的位置。
        y = read_data->x_coordinate;
        x = read_data->y_coordinate;
        return true;

    }
    else
    {
        return false;
    }


    #ifdef PKG_USING_GT9147
    rt_device_read(dev, 0, read_data, info.point_num);
    if (read_data[0].event == RT_TOUCH_EVENT_DOWN || read_data[0].event == RT_TOUCH_EVENT_MOVE)
    {
        x = 800 - read_data[0].x_coordinate;
        y = 480 - read_data[0].y_coordinate;
        return true;
    }
    else
    #endif
    {
        return false;
    }
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
