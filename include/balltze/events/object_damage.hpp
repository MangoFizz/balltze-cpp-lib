// SPDX-License-Identifier: GPL-3.0-only

#ifndef BALLTZE_API__EVENTS__OBJECT_DAMAGE_HPP
#define BALLTZE_API__EVENTS__OBJECT_DAMAGE_HPP

#include <cstdint>
#include <string>
#include "../event.hpp"

namespace Balltze::Event {
    struct ObjectDamageEventContext {
        const Engine::ObjectHandle object;
        const Engine::TagHandle damage_effect;
        const float multiplier;
        const Engine::PlayerHandle causer_player;
        const Engine::ObjectHandle causer_object;

        ObjectDamageEventContext(Engine::ObjectHandle object, Engine::TagHandle damage_effect, float multiplier, Engine::PlayerHandle causer_player, Engine::ObjectHandle causer_object) : object(object), damage_effect(damage_effect), multiplier(multiplier), causer_player(causer_player), causer_object(causer_object) {}
    };

    class ObjectDamageEvent : public EventData<ObjectDamageEvent> {
    public:
        ObjectDamageEventContext context;

        bool cancellable() const {
            return true;
        }

        ObjectDamageEvent(EventTime time, const ObjectDamageEventContext &context) : EventData(time), context(context) {}
    };
}

#endif
