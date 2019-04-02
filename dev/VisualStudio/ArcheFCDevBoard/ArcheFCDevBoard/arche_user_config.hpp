#pragma once
#ifndef ARCHE_USER_CONFIG_HPP
#define ARCHE_USER_CONFIG_HPP

/* C++ Includes */
#include <cstdlib>

static constexpr uint32_t BOOTLOADER_EXPECTED_RGN_SIZE = 64 * 1024;

static constexpr uint32_t BOOTLOADER_START_ADDR = 0x08000000;
static constexpr uint32_t BOOTLOADER_END_ADDR   = 0x0800FFFF;
static constexpr uint32_t BOOTLOADER_RGN_SIZE   = BOOTLOADER_END_ADDR - BOOTLOADER_START_ADDR + 1;

static constexpr uint32_t SYSTEM_IMAGE_START_ADDR = 0x08010000;
static constexpr uint32_t SYSTEM_IMAGE_END_ADDR   = 0x0807FFFF;
static constexpr uint32_t SYSTEM_IMAGE_SIZE       = SYSTEM_IMAGE_END_ADDR - SYSTEM_IMAGE_START_ADDR + 1;


/*------------------------------------------------
Comment to disable the heartbeat functionality
------------------------------------------------*/
#define ARCHE_HEARTBEAT_ENABLED
#ifdef ARCHE_HEARTBEAT_ENABLED

#include <Chimera/interface.hpp>

static constexpr uint8_t USER_HEARTBEAT_GPIO_PIN              = 8;
static constexpr Chimera::GPIO::Port USER_HEARTBEAT_GPIO_PORT = Chimera::GPIO::Port::PORTC;

#endif /* ARCHE_HEARTBEAT_ENABLED */


#endif /* !ARCHE_USER_CONFIG_HPP */
