#pragma once

#include "adapters/lvgl/LabelBase.h"

class SmallTimestampLabel : LabelBase
{
    static constexpr uint8_t TextLen = 20;
    char                     text[TextLen];

public:
    void create(lv_obj_t* parent, const lv_font_t* font, lv_align_t align = LV_ALIGN_CENTER,
                lv_coord_t xOffs = 0, lv_coord_t yOffs = 0)
    {
        lock();
        LabelBase::create(parent, text, sizeof(text), align, xOffs, yOffs, font, false);
        appendText("...", true);
        unlock();
    }

    void set(uint32_t timestamp)
    {
        lock();
        clean(false);
        if (timestamp != 0)
        {
            time_t     timestampStruct = timestamp;
            struct tm* timeInfo        = localtime(&timestampStruct);
            strftime(text, sizeof(text), "%H:%M", timeInfo);
            if (strcmp(text, "00:00") == 0)
            {
                strftime(text, sizeof(text), "%d/%m, %H:%M", timeInfo);
            }
        } else
            snprintf(text, sizeof(text), "...");
        updateOnScreen();
        unlock();
    }
};