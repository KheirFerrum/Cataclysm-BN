#pragma once
#ifndef CATA_SRC_ITEMINFO_QUERY_H
#define CATA_SRC_ITEMINFO_QUERY_H

#include <cstddef>
#include <bitset>
#include <string>
#include <vector>

enum class iteminfo_parts : size_t {
    BASE_CATEGORY = 0,
    BASE_MOD_SRC,
    BASE_ID,
    BASE_PRICE,
    BASE_BARTER,
    BASE_VOLUME,
    BASE_WEIGHT,
    BASE_RIGIDITY,
    BASE_DAMAGE,
    BASE_TOHIT,
    BASE_MOVES,
    BASE_REQUIREMENTS,
    BASE_MATERIAL,
    BASE_CONTENTS,
    BASE_AMOUNT,
    BASE_DEBUG,

    WEAPON_CATEGORY,

    MED_JOY,
    MED_PORTIONS,
    MED_STIMULATION,
    MED_QUENCH,

    FOOD_NUTRITION,
    FOOD_QUENCH,
    FOOD_JOY,
    FOOD_PORTIONS,
    FOOD_SMELL,
    FOOD_VITAMINS,
    FOOD_VIT_EFFECTS,
    FOOD_CANNIBALISM,
    FOOD_TAINT,
    FOOD_POISON,
    FOOD_HALLUCINOGENIC,
    FOOD_ROT,
    FOOD_ROT_STORAGE,

    MAGAZINE_CAPACITY,
    MAGAZINE_RELOAD,

    AMMO_REMAINING_OR_TYPES,
    AMMO_DAMAGE_VALUE,
    AMMO_DAMAGE_PROPORTIONAL,
    AMMO_DAMAGE_AP,
    AMMO_DAMAGE_AP_PROPORTIONAL,
    AMMO_DAMAGE_RANGE,
    AMMO_DAMAGE_DISPERSION,
    AMMO_DAMAGE_RECOIL,
    AMMO_SHAPE,
    AMMO_FX_RECYCLED,
    AMMO_FX_BLACKPOWDER,
    AMMO_FX_CANTMISSFIRE,
    AMMO_FX_INCENDIARY,

    DESCRIPTION_AUX_GUNMOD_HEADER,

    GUN_USEDSKILL,
    GUN_CAPACITY,
    GUN_TYPE,
    GUN_MAGAZINE,

    AMMO_REMAINING,
    AMMO_UPSCOST,

    GUN_DEFAULT_AMMO,
    GUN_MAX_RANGE,
    GUN_AIMING_STATS,
    GUN_DAMAGE,
    GUN_DAMAGE_LOADEDAMMO,
    GUN_DAMAGE_TOTAL,
    GUN_DAMAGEMULT,
    GUN_DAMAGEMULT_AMMO,
    GUN_DAMAGEMULT_TOTAL,
    GUN_ARMORPIERCE,
    GUN_ARMORPIERCE_LOADEDAMMO,
    GUN_ARMORPIERCE_TOTAL,
    GUN_ARMORMULT,
    GUN_ARMORMULT_LOADEDAMMO,
    GUN_ARMORMULT_TOTAL,
    GUN_DISPERSION,
    GUN_DISPERSION_LOADEDAMMO,
    GUN_DISPERSION_TOTAL,
    GUN_DISPERSION_SIGHT,

    GUN_RECOIL,
    GUN_RECOIL_BIPOD,

    GUN_RECOIL_PERCENTAGE,
    GUN_RECOIL_PERCENTAGE_BIPOD,

    GUN_BURST_PENALTY,
    GUN_RELOAD_TIME,

    GUN_FIRE_MODES,
    GUN_ALLOWED_MAGAZINES,

    DESCRIPTION_GUN_MODS,
    DESCRIPTION_GUN_CASINGS,

    DESCRIPTION_GUNMOD,
    DESCRIPTION_GUNMOD_REACH,

    GUNMOD_DISPERSION,
    GUNMOD_DISPERSION_SIGHT,
    GUNMOD_AIMSPEED,
    GUNMOD_DAMAGE,
    GUNMOD_ARMORPIERCE,
    GUNMOD_HANDLING,
    GUNMOD_RANGE,
    GUNMOD_AMMO,
    GUNMOD_RELOAD,
    GUNMOD_STRENGTH,

    GUNMOD_ADD_MOD,

    GUNMOD_USEDON,
    GUNMOD_EXCLUSION,
    GUNMOD_LOCATION,
    GUNMOD_BLACKLIST_MOD,

    ARMOR_BODYPARTS,
    ARMOR_LAYER,
    ARMOR_COVERAGE,
    ARMOR_WARMTH,
    ARMOR_ENCUMBRANCE,
    ARMOR_STORAGE,
    ARMOR_PROTECTION,

    BOOK_SUMMARY,
    BOOK_REQUIREMENTS_BEGINNER,
    BOOK_SKILLRANGE_MAX,
    BOOK_SKILLRANGE_MIN,
    BOOK_REQUIREMENTS_INT,
    BOOK_MORALECHANGE,
    BOOK_TIMEPERCHAPTER,
    BOOK_NUMUNREADCHAPTERS,

    DESCRIPTION_BOOK_RECIPES,
    DESCRIPTION_BOOK_ADDITIONAL_RECIPES,

    BOOK_UNREAD,

    CONTAINER_DETAILS,

    BATTERY_ENERGY,

    TOOL_ENERGYDRAW,
    TOOL_ENERGY,
    TOOL_BATTERIES,
    TOOL_CHARGEUSAGE,
    TOOL_CHARGES,
    TOOL_MAGAZINE_CURRENT,
    TOOL_MAGAZINE_COMPATIBLE,
    TOOL_CAPACITY,

    DESCRIPTION_COMPONENTS_MADEFROM,
    DESCRIPTION_COMPONENTS_DISASSEMBLE,

    QUALITIES,
    QUALITIES_CONTAINED,

    DESCRIPTION,
    DESCRIPTION_TECHNIQUES,
    DESCRIPTION_GUNMOD_ADDREACHATTACK,
    DESCRIPTION_MELEEDMG,
    DESCRIPTION_MELEEDMG_CRIT,
    DESCRIPTION_MELEEDMG_BASH,
    DESCRIPTION_MELEEDMG_CUT,
    DESCRIPTION_MELEEDMG_PIERCE,
    DESCRIPTION_MELEEDMG_MOVES,
    DESCRIPTION_APPLICABLEMARTIALARTS,
    DESCRIPTION_USE_METHODS,
    DESCRIPTION_REPAIREDWITH,

    DESCRIPTION_CONDUCTIVITY,
    DESCRIPTION_FLAGS,
    DESCRIPTION_FLAGS_HELMETCOMPAT,
    DESCRIPTION_FLAGS_FITS,
    DESCRIPTION_FLAGS_VARSIZE,
    DESCRIPTION_FLAGS_SIDED,
    DESCRIPTION_FLAGS_POWERARMOR,
    DESCRIPTION_FLAGS_POWERARMOR_RADIATIONHINT,
    DESCRIPTION_IRRADIATION,

    DESCRIPTION_BIONIC_ARMOR_INTERFACE,
    DESCRIPTION_RECHARGE_UPSMODDED,
    DESCRIPTION_RECHARGE_NORELOAD,
    DESCRIPTION_RECHARGE_UPSCAPABLE,

    DESCRIPTION_RADIO_ACTIVATION,
    DESCRIPTION_RADIO_ACTIVATION_CHANNEL,
    DESCRIPTION_RADIO_ACTIVATION_PROC,

    DESCRIPTION_CBM_SLOTS,

    DESCRIPTION_TWOHANDED,
    DESCRIPTION_GUNMOD_DISABLESSIGHTS,
    DESCRIPTION_GUNMOD_CONSUMABLE,
    DESCRIPTION_RADIOACTIVITY_DAMAGED,
    DESCRIPTION_RADIOACTIVITY_ALWAYS,

    DESCRIPTION_BREWABLE_DURATION,
    DESCRIPTION_BREWABLE_PRODUCTS,

    DESCRIPTION_FAULTS,

    DESCRIPTION_HOLSTERS,

    DESCRIPTION_ACTIVATABLE_TRANSFORMATION,

    DESCRIPTION_NOTES,

    DESCRIPTION_CONTENTS,

    DESCRIPTION_APPLICABLE_RECIPES,

    DESCRIPTION_MED_ADDICTING,

    // element count tracker
    NUM_VALUES
};

using iteminfo_query_base = std::bitset < static_cast<size_t>( iteminfo_parts::NUM_VALUES ) >;

class iteminfo_query
{
    private:
        iteminfo_query_base parts;
    public:
        iteminfo_query( const iteminfo_query_base &values );
        iteminfo_query( const std::string &bits );
        iteminfo_query( const std::vector<iteminfo_parts> &set_bits );

        bool test( const iteminfo_parts &value ) const;

        static const iteminfo_query all;
        static const iteminfo_query no_text;
        static const iteminfo_query any_flags;
        static const iteminfo_query no_conditions;
};

#endif // CATA_SRC_ITEMINFO_QUERY_H
