#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Generate seamless, original tinywhoop motor loops for the PortMaster ZIP."""

import math
import sys
import wave
from pathlib import Path


destination = Path(sys.argv[1])
destination.mkdir(parents=True, exist_ok=True)
rate = 22050

for name, frequency in (("idle", 170), ("mid", 250), ("high", 340)):
    samples = bytearray()
    for frame in range(rate):
        phase = 2 * math.pi * frequency * frame / rate
        flutter = 1 + 0.12 * math.sin(2 * math.pi * 17 * frame / rate)
        value = flutter * (0.52 * math.sin(phase) + 0.26 * math.sin(2 * phase) + 0.12 * math.sin(4 * phase))
        samples.append(max(0, min(255, round(128 + 95 * value))))
    with wave.open(str(destination / f"motor_{name}.wav"), "wb") as output:
        output.setnchannels(1)
        output.setsampwidth(1)
        output.setframerate(rate)
        output.writeframes(samples)
