<p align="center">
  <img src=".github/assets/Logo_Animated.svg" alt="Fedoraware Logo" width="250" align="center">
  <br/>
  <a href="https://nightly.link/Fedoraware/Fedoraware/workflows/msbuild/main/Fedoraware.zip">
    <img src=".github/assets/download.png" alt="Download Button" width="400" height="auto" align="center">
  </a>
</p>

# Fedoraware - TF2 x64 Port

[![GitHub Repo stars](https://img.shields.io/github/stars/Fedoraware/Fedoraware)](/../../stargazers)

A free and open-source training software for Team Fortress 2, based on [SE-Owned](https://www.unknowncheats.me/forum/team-fortress-2-a/436430-seowned-featured-cheat.html).

**This is a port of Fedoraware for the 64-bit version of Team Fortress 2 (tf_win64.exe).**

## Notes

- Supports **x64** TF2 only (build configuration: `Release|x64` or `Debug|x64`)
- Uses MinHook for detouring (x64 compatible)
- Signatures have been updated for the x64 binary from reference implementations
- **Some signatures may need updating** when TF2 updates - run the pattern scanner against the latest binaries
- The source code is most likely **DETECTED**, use a proper VAC bypass
- Requires [dxlevel 90](https://docs.mastercomfig.com/latest/customization/launch_options/?h=#dxlevel-launch-options) or higher

## Building

1. Open `Fedoraware.sln` in Visual Studio 2022
2. Select `Release|x64` platform
3. Build

## Guide

- Use an injector like [Xenos](https://github.com/DarthTon/Xenos/releases) to inject the dll into TF2
- Read the [Fedoraware Documentation](https://fedoraware.github.io/Docs/) to learn more about features

## x64 Port Changes

- Updated all signatures to x64 patterns (from Amalgam reference)
- Replaced `DWORD` with `uintptr_t` for all address/pointer types
- Removed `__thiscall` calling convention (unified on x64)
- Added x64 platform configurations to vcxproj and solution
- Updated pattern scanning for 64-bit modules
- Fixed struct member offsets for x64 layout
- Updated interface resolution for x64

## Credits to

- [Rei](https://github.com/rei-2) (Amalgam reference for x64 signatures)
- [spook953](https://github.com/spook953)
- [Lak3](https://github.com/Lak3)
- [Baan](https://github.com/xxmyn)
- [lnx00](https://github.com/lnx00)
- [Johnathon Walnut](https://github.com/johnathon-walnut)
- [JAGNEmk](https://github.com/JAGNEmk)
- [r00t](https://github.com/l-r00t-l)
- [lykanfox](https://github.com/lykanfox)
- ...and all other contributors!
