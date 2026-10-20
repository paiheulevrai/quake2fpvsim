// SPDX-License-Identifier: GPL-2.0-or-later
#include "client/drone_rates.h"
#include <assert.h>

int main(void)
{
    assert(fabsf(IN_DroneRate(0.0f, 0.65f, 0.78f, 0.10f)) < 0.001f);
    assert(fabsf(IN_DroneRate(1.0f, 0.65f, 0.78f, 0.10f) - 590.91f) < 0.02f);
    assert(fabsf(IN_DroneRate(1.0f, 0.65f, 0.74f, 0.10f) - 500.0f) < 0.01f);
    assert(fabsf(IN_DroneRate(1.0f, 0.55f, 0.74f, 0.10f) - 423.08f) < 0.02f);
    assert(IN_DroneRate(0.5f, 0.65f, 0.78f, 0.10f) <
           IN_DroneRate(0.5f, 0.65f, 0.78f, 0.0f));
    assert(IN_DroneRate(-0.5f, 0.65f, 0.78f, 0.10f) ==
           -IN_DroneRate(0.5f, 0.65f, 0.78f, 0.10f));
    return 0;
}
