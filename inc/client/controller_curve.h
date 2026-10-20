// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "shared/shared.h"

static inline float IN_DroneThrottleCurve(float stick, float gravity, float hover, float expo)
{
    float hover_thrust = Q_clipf(gravity / 1400.0f, 0, 1);
    float t, base, span;

    stick = Q_clipf(stick, 0, 1);
    hover = Q_clipf(hover, 0.3f, 0.8f);
    expo = Q_clipf(expo, 0, 1);
    if (stick < hover) {
        t = stick / hover;
        base = 0;
        span = hover_thrust;
    } else {
        t = (stick - hover) / (1 - hover);
        base = hover_thrust;
        span = 1 - hover_thrust;
    }

    // Smooth around hover while retaining the full motor range.
    return base + span * (t + expo * t * (1 - t) * (2 * t - 1));
}
