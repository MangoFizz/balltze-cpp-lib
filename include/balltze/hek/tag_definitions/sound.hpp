// SPDX-License-Identifier: GPL-3.0-only
// This file is auto-generated. DO NOT EDIT!

#ifndef BALLTZE_API__HEK__TAG_DEFINITION__SOUND_HPP
#define BALLTZE_API__HEK__TAG_DEFINITION__SOUND_HPP

#include "../../memory.hpp"
#include "../tag_file.hpp"
#include "enum.hpp"
#include "bitfield.hpp"

namespace Balltze::HEK::TagDefinitions { 
	enum SoundFormat : std::uint16_t {
		SOUND_FORMAT_16_BIT_PCM = 0,
		SOUND_FORMAT_XBOX_ADPCM,
		SOUND_FORMAT_IMA_ADPCM,
		SOUND_FORMAT_OGG_VORBIS,
	};

	enum SoundClass : std::uint16_t {
		SOUND_CLASS_PROJECTILE_IMPACT = 0,
		SOUND_CLASS_PROJECTILE_DETONATION,
		SOUND_CLASS_UNUSED,
		SOUND_CLASS_UNUSED1,
		SOUND_CLASS_WEAPON_FIRE,
		SOUND_CLASS_WEAPON_READY,
		SOUND_CLASS_WEAPON_RELOAD,
		SOUND_CLASS_WEAPON_EMPTY,
		SOUND_CLASS_WEAPON_CHARGE,
		SOUND_CLASS_WEAPON_OVERHEAT,
		SOUND_CLASS_WEAPON_IDLE,
		SOUND_CLASS_UNUSED2,
		SOUND_CLASS_UNUSED3,
		SOUND_CLASS_OBJECT_IMPACTS,
		SOUND_CLASS_PARTICLE_IMPACTS,
		SOUND_CLASS_SLOW_PARTICLE_IMPACTS,
		SOUND_CLASS_UNUSED4,
		SOUND_CLASS_UNUSED5,
		SOUND_CLASS_UNIT_FOOTSTEPS,
		SOUND_CLASS_UNIT_DIALOG,
		SOUND_CLASS_UNUSED6,
		SOUND_CLASS_UNUSED7,
		SOUND_CLASS_VEHICLE_COLLISION,
		SOUND_CLASS_VEHICLE_ENGINE,
		SOUND_CLASS_UNUSED8,
		SOUND_CLASS_UNUSED9,
		SOUND_CLASS_DEVICE_DOOR,
		SOUND_CLASS_DEVICE_FORCE_FIELD,
		SOUND_CLASS_DEVICE_MACHINERY,
		SOUND_CLASS_DEVICE_NATURE,
		SOUND_CLASS_DEVICE_COMPUTERS,
		SOUND_CLASS_UNUSED10,
		SOUND_CLASS_MUSIC,
		SOUND_CLASS_AMBIENT_NATURE,
		SOUND_CLASS_AMBIENT_MACHINERY,
		SOUND_CLASS_AMBIENT_COMPUTERS,
		SOUND_CLASS_UNUSED11,
		SOUND_CLASS_UNUSED12,
		SOUND_CLASS_UNUSED13,
		SOUND_CLASS_FIRST_PERSON_DAMAGE,
		SOUND_CLASS_UNUSED14,
		SOUND_CLASS_UNUSED15,
		SOUND_CLASS_UNUSED16,
		SOUND_CLASS_UNUSED17,
		SOUND_CLASS_SCRIPTED_DIALOG_PLAYER,
		SOUND_CLASS_SCRIPTED_EFFECT,
		SOUND_CLASS_SCRIPTED_DIALOG_OTHER,
		SOUND_CLASS_SCRIPTED_DIALOG_FORCE_UNSPATIALIZED,
		SOUND_CLASS_UNUSED18,
		SOUND_CLASS_UNUSED19,
		SOUND_CLASS_GAME_EVENT,
	};

	enum SoundSampleRate : std::uint16_t {
		SOUND_SAMPLE_RATE_22050__HZ = 0,
		SOUND_SAMPLE_RATE_44100__HZ,
	};

	enum SoundChannelCount : std::uint16_t {
		SOUND_CHANNEL_COUNT_MONO = 0,
		SOUND_CHANNEL_COUNT_STEREO,
	};

	struct SoundFlags {
		std::uint32_t fit_to_adpcm_blocksize : 1;
		std::uint32_t split_long_sound_into_permutations : 1;
		std::uint32_t thirsty_grunt : 1;
	};
	static_assert(sizeof(SoundFlags) == sizeof(std::uint32_t));

	struct SoundPermutation {
		TagString name;
		Fraction skip_fraction;
		Fraction gain;
		Memory::BigEndian<SoundFormat> format;
		Index next_permutation_index;
		TagHandle unknown_tag_id;
		Memory::BigEndian<std::uint32_t> samples_pointer;
		TagHandle sound_tag_id_0;
		Memory::BigEndian<std::uint32_t> buffer_size;
		TagHandle sound_tag_id_1;
		TagDataOffset samples;
		TagDataOffset mouth_data;
		TagDataOffset subtitle_data;
	};
	static_assert(sizeof(SoundPermutation) == 124);

	struct SoundPitchRange {
		TagString name;
		Memory::BigEndian<float> natural_pitch;
		Memory::BigEndian<float> bend_bounds[2];
		Memory::BigEndian<std::uint16_t> actual_permutation_count;
		PADDING(2);
		Memory::BigEndian<float> playback_rate;
		Memory::BigEndian<std::uint32_t> unknown_ffffffff_0;
		Memory::BigEndian<std::uint32_t> unknown_ffffffff_1;
		TagReflexive<SoundPermutation> permutations;
	};
	static_assert(sizeof(SoundPitchRange) == 72);

	struct Sound {
		Memory::BigEndian<SoundFlags> flags;
		Memory::BigEndian<SoundClass> sound_class;
		Memory::BigEndian<SoundSampleRate> sample_rate;
		Memory::BigEndian<float> minimum_distance;
		Memory::BigEndian<float> maximum_distance;
		Fraction skip_fraction;
		Memory::BigEndian<float> random_pitch_bounds[2];
		Angle inner_cone_angle;
		Angle outer_cone_angle;
		Fraction outer_cone_gain;
		Memory::BigEndian<float> random_gain_modifier;
		Memory::BigEndian<float> maximum_bend_per_second;
		PADDING(12);
		Memory::BigEndian<float> zero_skip_fraction_modifier;
		Memory::BigEndian<float> zero_gain_modifier;
		Memory::BigEndian<float> zero_pitch_modifier;
		PADDING(12);
		Memory::BigEndian<float> one_skip_fraction_modifier;
		Memory::BigEndian<float> one_gain_modifier;
		Memory::BigEndian<float> one_pitch_modifier;
		PADDING(12);
		Memory::BigEndian<SoundChannelCount> channel_count;
		Memory::BigEndian<SoundFormat> format;
		TagDependency promotion_sound;
		Memory::BigEndian<std::uint16_t> promotion_count;
		PADDING(2);
		Memory::BigEndian<std::uint32_t> longest_permutation_length;
		PADDING(8);
		Memory::BigEndian<std::uint32_t> unknown_ffffffff_0;
		Memory::BigEndian<std::uint32_t> unknown_ffffffff_1;
		TagReflexive<SoundPitchRange> pitch_ranges;
	};
	static_assert(sizeof(Sound) == 164);

}

#endif

