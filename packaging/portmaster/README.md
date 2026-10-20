# Q2PRO native controller edition for PortMaster

Install `Q2PRO.sh` and merge the `q2pro` directory into your ports directory. Copy your legally obtained Quake II `baseq2/pak*.pak` files and `baseq2/players` directory into `q2pro/baseq2/`.

Controls: left stick moves, right stick aims, R2 fires, L2 jumps, A uses, B opens inventory, X/Y change weapon, and Start opens/backtracks menus.

Open `Options > Input Setup > Controller Setup` to change FPS aim speed, move speed, stick deadzone, response curve and vertical inversion. `Tinywhoop Setup` has Betaflight-style RC Rate, S Rate and RC Expo for roll, pitch and yaw, plus a hover-stick position and throttle softness. The settings are saved in Q2PRO's normal configuration file.

Choose `Tinywhoop` from the single-player difficulty menu to fly the campaign at medium difficulty (`skill 1`) with a small collision hull, inertia and wall bounces while keeping Quake II weapons. In this mode, left stick up/down controls throttle, left stick left/right controls yaw, and right stick controls pitch and roll. The FPV camera has zero angle offset and an OSD with an artificial horizon, live pitch-degree ladders, speed, altitude above the ground in game units and heading. Autofire is on by default and fires only when the crosshair aims at an enemy or destructible object; R2 still fires manually. Acro mode is on by default; turning it off in Tinywhoop Setup gives a self-leveling angle mode. Centered throttle cuts lift; around the configured hover-stick position the throttle response is softened to help hold altitude.
