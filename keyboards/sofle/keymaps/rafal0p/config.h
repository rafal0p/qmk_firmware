#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define TAPPING_TOGGLE 3
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif

#define COMBO_COUNT 8
#define COMBO_ONLY_FROM_LAYER 0
