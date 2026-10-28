// SPDX-License-Identifier: GPL-2.0-or-later
#include "shared/shared.h"
#include "common/pmove.h"

#include <assert.h>

static bool wall;

static trace_t test_trace(const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end)
{
    trace_t result = {0};
    float fraction;
    int i;

    (void)mins;
    (void)maxs;
    result.fraction = 1;
    VectorCopy(end, result.endpos);
    if (!wall || end[0] <= 10)
        return result;
    if (start[0] >= 10) {
        result.allsolid = true;
        result.fraction = 0;
        return result;
    }
    fraction = (10 - start[0]) / (end[0] - start[0]);
    result.fraction = fraction;
    for (i = 0; i < 3; i++)
        result.endpos[i] = start[i] + fraction * (end[i] - start[i]);
    result.plane.normal[0] = -1;
    result.ent = (struct edict_s *)1;
    return result;
}

static int test_contents(const vec3_t point)
{
    (void)point;
    return 0;
}

static pmove_old_t new_drone(void)
{
    pmove_old_t move = {0};
    move.s.pm_type = PM_DRONE;
    move.s.gravity = 800;
    move.cmd.msec = 100;
    move.trace = test_trace;
    move.pointcontents = test_contents;
    return move;
}

int main(void)
{
    pmoveParams_t params;
    pmove_old_t move;

    PmoveInit(&params);
    move = new_drone();
    PmoveOld(&move, &params);
    assert(move.s.velocity[2] < 0); // zero throttle lets the drone fall
    assert(move.viewheight == 0 && move.mins[0] == -8 && move.maxs[0] == 8);

    move = new_drone();
    move.cmd.upmove = 80; // 40% throttle climbs at a 6:1 thrust ratio
    PmoveOld(&move, &params);
    assert(move.s.velocity[2] > 0);

    move = new_drone();
    move.cmd.upmove = 200;
    PmoveOld(&move, &params);
    assert(move.s.velocity[2] > 0); // full throttle climbs

    move = new_drone();
    move.cmd.upmove = 200;
    move.cmd.angles[PITCH] = ANGLE2SHORT(60);
    PmoveOld(&move, &params);
    assert(move.s.velocity[0] > 0 && move.s.velocity[2] > 0);

    move = new_drone();
    move.cmd.angles[PITCH] = ANGLE2SHORT(135);
    PmoveOld(&move, &params);
    assert(move.viewangles[PITCH] > 130); // Acro can flip past vertical

    move = new_drone();
    move.s.pm_flags = PMF_TIME_TELEPORT;
    move.s.pm_time = 0;
    move.cmd.angles[PITCH] = ANGLE2SHORT(45);
    PmoveOld(&move, &params);
    assert(!(move.s.pm_flags & PMF_TIME_TELEPORT));
    PmoveOld(&move, &params);
    assert(move.viewangles[PITCH] > 40); // spawn teleport cannot freeze acro input

    wall = true;
    move = new_drone();
    move.s.velocity[0] = COORD2SHORT(200);
    PmoveOld(&move, &params);
    assert(move.s.velocity[0] < 0); // impact reverses direction
    assert(SHORT2COORD(move.s.origin[0]) < 10);
    return 0;
}
