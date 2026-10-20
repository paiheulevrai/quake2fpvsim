// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef Q2PRO_DRONE_RATES_H
#define Q2PRO_DRONE_RATES_H

#include <math.h>

// Betaflight legacy rates: RC Rate, Super Rate and RC Expo.
static inline float IN_DroneRate(float stick, float rc_rate, float super_rate, float expo)
{
    float curved = stick * (1.0f - expo) + stick * stick * stick * expo;
    return 200.0f * rc_rate * curved / (1.0f - super_rate * fabsf(stick));
}

#endif
