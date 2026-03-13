#pragma once

#include "SGF_ArduinoQ.h"

namespace SGFHardwarePresets::Profiles {

struct UnoQIli9341_320x240 {
  using DisplayBus = SPIArduinoQDisplayBus;
  using Display = FastILI9341;
  using DisplayBusConfig = SPIArduinoQDisplayBus::Config;
  using RenderTarget = IRenderTarget;
  using Screen = IScreen;

  struct Runtime {
    SGFHardware::HardwareProfile profile;
    DisplayBus displayBus;
    Display display;

    Runtime()
      : profile(UnoQIli9341_320x240::hardwareProfile()),
        displayBus(UnoQIli9341_320x240::makeDisplayBusConfig()),
        display(UnoQIli9341_320x240::makeDisplay(displayBus)) {}

    RenderTarget& renderTarget() { return display; }
    Screen& screen() { return display; }
  };

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

  static Runtime makeRuntime() {
    return Runtime();
  }

  static SGFHardware::HardwareProfile hardwareProfile() {
    return {
      meta,
      {
        24000000u,
        ScreenRotation::Landscape,
        255u,
        320u,
        240u
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
