#pragma once

#include "SGF_ESP32.h"

#ifndef SGF_ESP32_ST7789_240X240_SPI_HZ
#define SGF_ESP32_ST7789_240X240_SPI_HZ 40000000u
#endif

#ifndef SGF_ESP32_ST7789_240X240_USE_DMA_BUS
#define SGF_ESP32_ST7789_240X240_USE_DMA_BUS 0
#endif

namespace SGFHardwarePresets::Profiles {

struct Esp32St7789_240x240 {
#if SGF_ESP32_ST7789_240X240_USE_DMA_BUS
  using DisplayBus = SPIESP32DisplayBusDMA;
#else
  using DisplayBus = SPIESP32DisplayBus;
#endif
  using Display = FastST7789;
  using DisplayBusConfig = DisplayBus::Config;
  using PanelConfig = FastST7789::PanelConfig;
  using RenderTarget = IRenderTarget;
  using Screen = IScreen;

  struct Runtime {
    SGFHardware::HardwareProfile profile;
    DisplayBus displayBus;
    Display display;

    Runtime()
      : profile(Esp32St7789_240x240::hardwareProfile()),
        displayBus(Esp32St7789_240x240::makeDisplayBusConfig()),
        display(Esp32St7789_240x240::makeDisplay(displayBus)) {}

    RenderTarget& renderTarget() { return display; }
    Screen& screen() { return display; }
  };

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
    PanelConfig config = FastST7789::makePanelConfig(
      240,
      240,
      FastST7789::offset(0, 0),
      FastST7789::offset(0, 0),
      FastST7789::offset(0, 0),
      FastST7789::offset(0, 0));
    config.colorOrder = 0;
    config.invertColors = true;
    return config;
  }

  static Display makeDisplay(DisplayBus& bus) {
    return Display(bus, makePanelConfig());
  }

  static Runtime makeRuntime() {
    return Runtime();
  }

  static SGFHardware::HardwareProfile hardwareProfile() {
    return {
      meta,
      {
        SGF_ESP32_ST7789_240X240_SPI_HZ,
        ScreenRotation::PortraitFlip,
        255u,
        240u,
        240u
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
