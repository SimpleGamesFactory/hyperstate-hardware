#pragma once

#include "SGF.h"

#define SGF_HW_PRESET_UNOQ_ILI9341_320X240 1
#define SGF_HW_PRESET_ESP32_ST7789_240X240 2

#ifndef SGF_HW_PRESET
#error "SGF_HW_PRESET must be defined before including SGFHardwarePresets.h"
#elif SGF_HW_PRESET == SGF_HW_PRESET_UNOQ_ILI9341_320X240
#include "SGFHardwarePresets/Profiles/UnoQIli9341_320x240.h"
using SGFHardwareProfile = SGFHardwarePresets::Profiles::UnoQIli9341_320x240;
#elif SGF_HW_PRESET == SGF_HW_PRESET_ESP32_ST7789_240X240
#include "SGFHardwarePresets/Profiles/Esp32St7789_240x240.h"
using SGFHardwareProfile = SGFHardwarePresets::Profiles::Esp32St7789_240x240;
#else
#error "Unsupported SGF_HW_PRESET"
#endif
