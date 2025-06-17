#pragma once

#include "adapters/lvgl/Button.h"
#include "adapters/lvgl/FlexContainer.h"
#include "adapters/lvgl/Image.h"
#include "adapters/lvgl/SimpleLabel.h"
#ifdef COMMON_DEMO_APP
#include "entities/ui/weather_screen/elements/LocationLabel.h"
#include "entities/ui/weather_screen/elements/TimeZoneLabel.h"
#include "entities/ui/weather_screen/elements/WifiLabel.h"
#else
#include "entities/weather_screen/elements/LocationLabel.h"
#include "entities/weather_screen/elements/TimeZoneLabel.h"
#include "entities/weather_screen/elements/WifiLabel.h"
#endif
#include <esp_log.h>

class WifiScreenHeader
{
    WifiLabel              wifiLabel;
    LocationLabel          location;
    TimeZoneLabel          timeLabel;
    TimeZoneLabel          dateLabel;
    FlexContainer          header;
    FlexContainer          wifiInfoContainer;
    FlexContainer          locationContainer;
    FlexContainer          configButtonContainer;
    Image                  backIcon;
    Image                  wifiIcon;
    Button                 button;
    static constexpr char* Tag = "wifiScreenHeader";
    static void            configButtonCallback(lv_event_t* e, void* context);

public:
    void create(lv_obj_t* parent);

    void updateRSSI(int8_t rssi);

    void setSSID(char* newSSID);

    void setCity(char* city)
    {
        location.setCity(city);
    }

    void setCountry(char* country)
    {
        location.setCountry(country);
    }

    void setCurrentTime(uint32_t timestamp)
    {
        timeLabel.setCurrentTime(timestamp);
        dateLabel.setCurrentDate(timestamp);
    }
};