#pragma once

#include "SGF_ESP32.h"

namespace SGFHardwarePresets::Profiles {

struct Esp32St7789_240x240 {
  using DisplayBus = SPIESP32DisplayBus;
  using Display = FastST7789;
  using DisplayBusConfig = SPIESP32DisplayBus::Config;
  using PanelConfig = FastST7789::PanelConfig;

  static constexpr SGFHardware::BoardMeta meta = {
    "esp32-st7789-240x240",
    "ESP32",
    "ST7789-240x240"
  };

  static DisplayBusConfig makeDisplayBusConfig() {
    return {
      &SPI,
      18,
      SPIESP32DisplayBus::PIN_UNUSED,
      23,
      SPIESP32DisplayBus::PIN_UNUSED,
      2,
      4,
      32,
      SPI_MODE3
    };
  }

  static PanelConfig makePanelConfig() {
    return FastST7789::makePanelConfig(
      240,
      240,
      FastST7789::offset(0, 0),
      FastST7789::offset(0, 0),
      FastST7789::offset(0, 0),
      FastST7789::offset(0, 0));
  }

  static Display makeDisplay(DisplayBus& bus) {
    return Display(bus, makePanelConfig());
  }

  static SGFHardware::HardwareProfile hardwareProfile() {
    return {
      meta,
      {
        40000000u,
        IScreen::Rotation::PortraitFlip,
        255u
      },
      {
        34,
        5,
        33,
        35,
        22
      }
    };
  }
};

}  // namespace SGFHardwarePresets::Profiles
