// SPDX-License-Identifier: GPL-3.0-only

#ifndef BALLTZE_API__ENGINE__SCRIPT_HPP
#define BALLTZE_API__ENGINE__SCRIPT_HPP

#include <cstdint>
#include "../memory.hpp"

namespace Balltze::Engine {
    enum HscDataType : std::uint16_t {
        HSC_DATA_TYPE_PASSTHROUGH = 3,
        HSC_DATA_TYPE_VOID,
        HSC_DATA_TYPE_BOOLEAN,
        HSC_DATA_TYPE_REAL,
        HSC_DATA_TYPE_SHORT,
        HSC_DATA_TYPE_LONG,
        HSC_DATA_TYPE_STRING,
        HSC_DATA_TYPE_TRIGGER_VOLUME = 11,
        HSC_DATA_TYPE_CUTSCENE_FLAG,
        HSC_DATA_TYPE_CUTSCENE_CAMERA_POINT,
        HSC_DATA_TYPE_CUTSCENE_TITLE,
        HSC_DATA_TYPE_CUTSCENE_RECORDING,
        HSC_DATA_TYPE_DEVICE_GROUP,
        HSC_DATA_TYPE_AI,
        HSC_DATA_TYPE_AI_COMMAND_LIST,
        HSC_DATA_TYPE_STARTING_PROFILE,
        HSC_DATA_TYPE_CONVERSATION,
        HSC_DATA_TYPE_NAVPOINT,
        HSC_DATA_TYPE_HUD_MESSAGE,
        HSC_DATA_TYPE_OBJECT_LIST,
        HSC_DATA_TYPE_SOUND,
        HSC_DATA_TYPE_EFFECT,
        HSC_DATA_TYPE_DAMAGE,
        HSC_DATA_TYPE_LOOPING_SOUND,
        HSC_DATA_TYPE_ANIMATION_GRAPH,
        HSC_DATA_TYPE_ACTOR_VARIANT,
        HSC_DATA_TYPE_OBJECT_DEFINITION = 31,
        HSC_DATA_TYPE_GAME_DIFFICULTY,
        HSC_DATA_TYPE_TEAM,
        HSC_DATA_TYPE_AI_DEFAULT_STATE,
        HSC_DATA_TYPE_ACTOR_TYPE,
        HSC_DATA_TYPE_HUD_CORNER,
        HSC_DATA_TYPE_OBJECT,
        HSC_DATA_TYPE_UNIT,
        HSC_DATA_TYPE_VEHICLE,
        HSC_DATA_TYPE_DEVICE,
        HSC_DATA_TYPE_SCENERY,
        HSC_DATA_TYPE_OBJECT_NAME
    };

    struct HscFunctionEntry {
        /** Return type of function */
        HscDataType return_type;

        /** Name of the function */
        const char *name;

        /** Console command function */
        void *console_function;

        /** Script function */
        void *script_function;

        /** Help message */
        const char *help_message;

        /** Help parameters */
        const char *help_parameters;

        PADDING(0x2);

        /** Number of parameters */
        std::uint16_t parameter_count;

        HscDataType *parameters() noexcept {
            return (parameter_count > 0) ? reinterpret_cast<HscDataType *>(this + 1) : nullptr;
        }
    };
    static_assert(sizeof(HscFunctionEntry) == 0x1C);
}

#endif
