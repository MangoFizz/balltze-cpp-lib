// SPDX-License-Identifier: GPL-3.0-only
// This file is auto-generated. DO NOT EDIT!

#ifndef BALLTZE_API__HEK__TAG_DEFINITION__DEVICE_LIGHT_FIXTURE_HPP
#define BALLTZE_API__HEK__TAG_DEFINITION__DEVICE_LIGHT_FIXTURE_HPP

#include "../../memory.hpp"
#include "../tag_file.hpp"
#include "enum.hpp"
#include "bitfield.hpp"

#pragma pack(push)
#pragma pack(1)

#include "device.hpp"

namespace Balltze::HEK::TagDefinitions { 
	struct DeviceLightFixture : public Device {
		PADDING(64);
	};
	static_assert(sizeof(DeviceLightFixture) == 720);

}

#pragma pack(pop)

#endif

