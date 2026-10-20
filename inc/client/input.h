/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#pragma once

//
// input.h -- external (non-keyboard) input devices
//

void IN_Frame(void);
void IN_Activate(void);
void IN_WarpMouse(int x, int y);

typedef enum {
    IN_CONTROLLER_ATTACK,
    IN_CONTROLLER_JUMP,
    IN_CONTROLLER_USE,
    IN_CONTROLLER_INVENTORY,
    IN_CONTROLLER_WEAPON_NEXT,
    IN_CONTROLLER_WEAPON_PREV
} in_controller_button_t;

typedef enum {
    IN_CONTROLLER_LEFT_X,
    IN_CONTROLLER_LEFT_Y,
    IN_CONTROLLER_RIGHT_X,
    IN_CONTROLLER_RIGHT_Y
} in_controller_axis_t;

void IN_ControllerAxis(in_controller_axis_t axis, float value);
void IN_ControllerButton(in_controller_button_t button, bool down, unsigned time);
void IN_ControllerReset(unsigned time);
