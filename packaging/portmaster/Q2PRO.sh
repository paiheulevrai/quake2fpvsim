#!/bin/bash
# SPDX-License-Identifier: GPL-2.0-or-later

XDG_DATA_HOME=${XDG_DATA_HOME:-$HOME/.local/share}
if [ -d /opt/system/Tools/PortMaster ]; then
    controlfolder=/opt/system/Tools/PortMaster
elif [ -d /opt/tools/PortMaster ]; then
    controlfolder=/opt/tools/PortMaster
elif [ -d "$XDG_DATA_HOME/PortMaster" ]; then
    controlfolder="$XDG_DATA_HOME/PortMaster"
else
    controlfolder=/roms/ports/PortMaster
fi

source "$controlfolder/control.txt"
[ -f "$controlfolder/mod_${CFW_NAME}.txt" ] && source "$controlfolder/mod_${CFW_NAME}.txt"
get_controls

GAMEDIR="/$directory/ports/q2pro"
cd "$GAMEDIR" || exit 1
exec > >(tee "$GAMEDIR/log.txt") 2>&1

# PortMaster supplies the per-device SDL mapping.  Do not start GPTOKEYB:
# Q2PRO consumes both sticks and all gameplay buttons through SDL directly.
export SDL_GAMECONTROLLERCONFIG="$sdl_controllerconfig"
export HOTKEY=guide

pm_platform_helper "$GAMEDIR/q2pro_glsl"
./q2pro_glsl
pm_finish
