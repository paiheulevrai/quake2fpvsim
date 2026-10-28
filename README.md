# Quake II FPV Sim

Fly through Quake II as a small FPV drone. This fork of [Q2PRO](https://github.com/actionquake/q2pro) adds a **Tinywhoop** single-player mode with controller flight, an FPV on-screen display, and target-aware autofire. The Quake II weapons and campaign remain in place.

https://www.youtube.com/watch?v=Q_iBFeudtIM

## What is in the FPV mode?

- **Drone flight:** throttle, yaw, pitch and roll; a small collision hull; inertia and wall bounces. Acro mode is enabled by default, with an optional self-leveling angle mode.
- **Betaflight-style rates:** separate RC Rate, S Rate and RC Expo for roll, pitch and yaw. Hover-stick position and throttle softness are adjustable. Throttle uses the full stick range.
- **FPV camera and OSD:** fixed 0° camera tilt, an artificial horizon that moves with pitch and roll, working degree ladders on both sides, heading, speed and altitude above the surface below (in game units).
- **Target-aware autofire:** enabled by default. The gun fires when the crosshair points at a living enemy or destructible object. RT still fires manually at any time.
- **Medium difficulty:** Tinywhoop starts the single-player game at `skill 1`.

## Controls

| Xbox controller | Tinywhoop action |
| --- | --- |
| Left stick up/down | Throttle |
| Left stick left/right | Yaw |
| Right stick up/down | Pitch |
| Right stick left/right | Roll |
| RT | Manual fire |
| LT | Jump |
| A | Use |
| B | Inventory |
| X / Y | Previous / next weapon |
| Start | Menu |

Open **Options → Input Setup → Controller Setup → Tinywhoop Setup** to tune flight rates, hover point, acro mode, autofire and the OSD. The controller must appear to SDL as a GameController. DJI controllers may work if SDL recognizes their mapping; Xbox controllers are the tested option.

## Play on Windows

1. Build the project as described below or obtain a build of this fork.
2. Put `q2pro.exe` beside a `baseq2/` directory containing this fork's `gamex86_64.dll` and `q2pro.menu`.
3. Copy `pak*.pak` and, if needed, `players/` from a legally obtained Quake II installation or demo into `baseq2/`.
4. Put the required SDL2 and zlib runtime DLLs beside `q2pro.exe`, start the game, then choose **Solo → Tinywhoop**.

The repository contains source code and packaging scripts. **Quake II game data, maps, player models and demo archives are not included.** The local Windows validation ZIP is a development artifact and is not committed.

## Build

Q2PRO uses [Meson](https://mesonbuild.com/). On Windows, use an MSYS2 MinGW-w64 environment with a C compiler, Meson, Ninja, SDL2 and zlib:

```sh
meson setup build/windows -Dsystem-wide=false -Dsdl2=enabled \
  -Dx11=disabled -Dwayland=disabled -Dlibcurl=disabled \
  -Dopenal=disabled -Davcodec=disabled
meson compile -C build/windows
```

The outputs are `build/windows/q2pro.exe` and `build/windows/gamex86_64.dll`. Copy `src/client/ui/q2pro.menu` to `baseq2/q2pro.menu`. See [INSTALL.md](INSTALL.md) for the upstream build details and [the PortMaster notes](packaging/portmaster/README.md) for the ARM64 package.

## License and game data

The code in this fork is **GNU GPL-2.0-or-later**, as declared by the upstream Q2PRO project and the source headers. The complete license text is in [LICENSE](LICENSE). This repository keeps the upstream source history and notices.

The GPL covers the source code; it does **not** grant permission to redistribute Quake II's original game data. id Software's [Quake II source release](https://github.com/id-Software/Quake-2) explicitly distinguishes the GPL source from the copyrighted data files. Provide your own game data when playing or distributing a build.
