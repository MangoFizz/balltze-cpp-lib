// SPDX-License-Identifier: GPL-3.0-only
// This file is auto-generated. DO NOT EDIT!

#ifndef BALLTZE_API__HEK__TAG_DEFINITION__PARTICLE_SYSTEM_HPP
#define BALLTZE_API__HEK__TAG_DEFINITION__PARTICLE_SYSTEM_HPP

#include "../../memory.hpp"
#include "../tag_file.hpp"
#include "enum.hpp"
#include "bitfield.hpp"

#pragma pack(push)
#pragma pack(1)

#include "particle.hpp"

namespace Balltze::HEK::TagDefinitions { 
	enum ParticleSystemParticleCreationPhysics : std::uint16_t {
		PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_DEFAULT = 0,
		PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_EXPLOSION,
		PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_JET,
	};

	enum ParticleSystemParticleUpdatePhysics : std::uint16_t {
		PARTICLE_SYSTEM_PARTICLE_UPDATE_PHYSICS_DEFAULT = 0,
	};

	enum ParticleSystemComplexSpriteRenderModes : std::uint16_t {
		PARTICLE_SYSTEM_COMPLEX_SPRITE_RENDER_MODES_SIMPLE = 0,
		PARTICLE_SYSTEM_COMPLEX_SPRITE_RENDER_MODES_ROTATIONAL,
	};

	enum ParticleSystemSystemUpdatePhysics : std::uint16_t {
		PARTICLE_SYSTEM_SYSTEM_UPDATE_PHYSICS_DEFAULT = 0,
		PARTICLE_SYSTEM_SYSTEM_UPDATE_PHYSICS_EXPLOSION,
	};

	struct ParticleSystemTypeFlags {
		std::uint32_t type_states_loop : 1;
		std::uint32_t forward_backward : 1;
		std::uint32_t particle_states_loop : 1;
		std::uint32_t forward_backward_1 : 1;
		std::uint32_t particles_die_in_water : 1;
		std::uint32_t particles_die_in_air : 1;
		std::uint32_t particles_die_on_ground : 1;
		std::uint32_t rotational_sprites_animate_sideways : 1;
		std::uint32_t disabled : 1;
		std::uint32_t tint_by_effect_color : 1;
		std::uint32_t initial_count_scales_with_effect : 1;
		std::uint32_t minimum_count_scales_with_effect : 1;
		std::uint32_t creation_rate_scales_with_effect : 1;
		std::uint32_t scale_scales_with_effect : 1;
		std::uint32_t animation_rate_scales_with_effect : 1;
		std::uint32_t rotation_rate_scales_with_effect : 1;
		std::uint32_t do_not_draw_in_first_person : 1;
		std::uint32_t do_not_draw_in_third_person : 1;
	};
	static_assert(sizeof(ParticleSystemTypeFlags) == sizeof(std::uint32_t));

	struct ParticleSystemPhysicsConstant {
		Memory::BigEndian<float> k;
	};
	static_assert(sizeof(ParticleSystemPhysicsConstant) == 4);

	struct ParticleSystemTypeStates {
		TagString name;
		Memory::BigEndian<float> duration_bounds[2];
		Memory::BigEndian<float> transition_time_bounds[2];
		PADDING(4);
		Memory::BigEndian<float> scale_multiplier;
		Memory::BigEndian<float> animation_rate_multiplier;
		Memory::BigEndian<float> rotation_rate_multiplier;
		ColorARGB color_multiplier;
		Memory::BigEndian<float> radius_multiplier;
		Memory::BigEndian<float> minimum_particle_count;
		Memory::BigEndian<float> particle_creation_rate;
		PADDING(84);
		Memory::BigEndian<ParticleSystemParticleCreationPhysics> particle_creation_physics;
		Memory::BigEndian<ParticleSystemParticleUpdatePhysics> particle_update_physics;
		TagBlock<ParticleSystemPhysicsConstant> physics_constants;
	};
	static_assert(sizeof(ParticleSystemTypeStates) == 192);

	struct ParticleSystemTypeParticleState {
		TagString name;
		Memory::BigEndian<float> duration_bounds[2];
		Memory::BigEndian<float> transition_time_bounds[2];
		TagDependency bitmaps;
		Index sequence_index;
		PADDING(2);
		PADDING(4);
		Memory::BigEndian<float> scale[2];
		Memory::BigEndian<float> animation_rate[2];
		Angle rotation_rate[2];
		ColorARGB color_1;
		ColorARGB color_2;
		Memory::BigEndian<float> radius_multiplier;
		TagDependency point_physics;
		PADDING(36);
		PADDING(36);
		Memory::BigEndian<std::uint32_t> unknown_int;
		Memory::BigEndian<ParticleShaderFlags> shader_flags;
		Memory::BigEndian<FramebufferBlendFunction> framebuffer_blend_function;
		Memory::BigEndian<FramebufferFadeMode> framebuffer_fade_mode;
		Memory::BigEndian<IsUnfilteredFlag> map_flags;
		PADDING(28);
		TagDependency secondary_map_bitmap;
		Memory::BigEndian<ParticleAnchor> anchor;
		Memory::BigEndian<IsUnfilteredFlag> flags;
		Memory::BigEndian<FunctionOut> u_animation_source;
		Memory::BigEndian<WaveFunction> u_animation_function;
		Memory::BigEndian<float> u_animation_period;
		Memory::BigEndian<float> u_animation_phase;
		Memory::BigEndian<float> u_animation_scale;
		Memory::BigEndian<FunctionOut> v_animation_source;
		Memory::BigEndian<WaveFunction> v_animation_function;
		Memory::BigEndian<float> v_animation_period;
		Memory::BigEndian<float> v_animation_phase;
		Memory::BigEndian<float> v_animation_scale;
		Memory::BigEndian<FunctionOut> rotation_animation_source;
		Memory::BigEndian<WaveFunction> rotation_animation_function;
		Memory::BigEndian<float> rotation_animation_period;
		Memory::BigEndian<float> rotation_animation_phase;
		Memory::BigEndian<float> rotation_animation_scale;
		Point2D rotation_animation_center;
		PADDING(4);
		Memory::BigEndian<float> zsprite_radius_scale;
		PADDING(20);
		TagBlock<ParticleSystemPhysicsConstant> physics_constants;
	};
	static_assert(sizeof(ParticleSystemTypeParticleState) == 376);

	struct ParticleSystemType {
		TagString name;
		Memory::BigEndian<ParticleSystemTypeFlags> flags;
		Memory::BigEndian<std::uint16_t> initial_particle_count;
		PADDING(2);
		Memory::BigEndian<ParticleSystemComplexSpriteRenderModes> complex_sprite_render_modes;
		PADDING(2);
		Memory::BigEndian<float> radius;
		PADDING(36);
		Memory::BigEndian<ParticleSystemParticleCreationPhysics> particle_creation_physics;
		PADDING(2);
		Memory::BigEndian<IsUnusedFlag> physics_flags;
		TagBlock<ParticleSystemPhysicsConstant> physics_constants;
		TagBlock<ParticleSystemTypeStates> states;
		TagBlock<ParticleSystemTypeParticleState> particle_states;
	};
	static_assert(sizeof(ParticleSystemType) == 128);

	struct ParticleSystem {
		PADDING(4);
		PADDING(52);
		TagDependency point_physics;
		Memory::BigEndian<ParticleSystemSystemUpdatePhysics> system_update_physics;
		PADDING(2);
		Memory::BigEndian<IsUnusedFlag> physics_flags;
		TagBlock<ParticleSystemPhysicsConstant> physics_constants;
		TagBlock<ParticleSystemType> particle_types;
	};
	static_assert(sizeof(ParticleSystem) == 104);

}

#pragma pack(pop)

#endif

