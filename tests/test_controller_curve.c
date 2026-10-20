// SPDX-License-Identifier: GPL-2.0-or-later
#include "client/controller_curve.h"

#include <assert.h>
#include <math.h>

int main(void)
{
    const float neutral = 800.0f / 1400.0f;
    float previous = 0;
    int i;

    assert(IN_DroneThrottleCurve(0, 800, 0.6f, 0.8f) == 0);
    assert(fabsf(IN_DroneThrottleCurve(0.6f, 800, 0.6f, 0.8f) - neutral) < 0.0001f);
    assert(IN_DroneThrottleCurve(1, 800, 0.6f, 0.8f) == 1);
    assert(IN_DroneThrottleCurve(0.55f, 800, 0.6f, 0.8f) < neutral);
    assert(IN_DroneThrottleCurve(0.65f, 800, 0.6f, 0.8f) > neutral);
    assert(IN_DroneThrottleCurve(0.65f, 800, 0.6f, 0.8f) -
           IN_DroneThrottleCurve(0.55f, 800, 0.6f, 0.8f) < 0.06f);
    assert(fabsf(IN_DroneThrottleCurve(0.6f, 400, 0.6f, 0.8f) - 400.0f / 1400) < 0.0001f);
    for (i = 1; i <= 100; i++) {
        float current = IN_DroneThrottleCurve(i / 100.0f, 800, 0.6f, 0.8f);
        assert(current >= previous && current <= 1);
        previous = current;
    }
    return 0;
}
