#pragma once

#include "SGF_ArduinoQ.h"

namespace SGFHardwarePresets::Profiles {

struct UnoQIli9341_320x240 {
  using DisplayBus = SPIArduinoQDisplayBus;
  using Display = FastILI9341;
  using DisplayBusConfig = SPIArduinoQDisplayBus::Config;

  static constexpr SGFHardware::BoardMeta meta = {
    "unoq-ili9341-320x240",
    "ArduinoQ",
    "ILI9341-320x240"
  };

  static DisplayBusConfig makeDisplayBusConfig() {
    return {
      DEVICE_DT_GET(DT_NODELABEL(spi2)),
      10,
      9,
      8,
      D6
    };
  }

  static Display makeDisplay(DisplayBus& bus) {
    return Display(bus);
  }

  static SGFHardware::HardwareProfile hardwareProfile() {
    return {
      meta,
      {
        24000000u,
        IScreen::Rotation::Landscape,
        255u
      },
      {
        2,
        3,
        D5,
        D7,
        D4
      }
    };
  }
};

}  // namespace SGFHardwarePresets::Profiles
