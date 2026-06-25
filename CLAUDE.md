# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an **Unreal Engine 5.6 editor module** (MyEditor) — a plugin/standalone editor project, not a game runtime. The module is currently minimal: it defines a single `MyEditor` module with no custom code beyond the default `IMPLEMENT_PRIMARY_GAME_MODULE` scaffold. It has a `Runtime` loading phase but is intended for editor use.

- **Engine version**: 5.6
- **Project type**: Editor module / plugin
- **Single module**: `MyEditor` in `Source/MyEditor/`
- **Dependencies**: Core, CoreUObject, Engine, InputCore, EnhancedInput

## Build & Run Commands

### Build the Editor
```bash
# Using Unreal Build Tool (UBT) - from project root
D:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat MyEditorEditor Win64 Development -Project="%CD%\MyEditor.uproject" -WaitMutex -FromMsBuild
```

### Generate Project Files
If the `.uproject` or `.sln` is out of sync with source:
```bash
D:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\GenerateProjectFiles.bat -Project="%CD%\MyEditor.uproject" -ProjectFiles
```

### Run the Editor
```bash
D:\Program Files\Epic Games\UE_5.6\Engine\Binaries\Win64\UnrealEditor.exe MyEditor.uproject
```

### Build via Visual Studio
Open `MyEditor.sln` and build the `MyEditorEditor` target in the `Development` configuration.

## Architecture

```
MyEditor/
├── MyEditor.uproject          # Project manifest; defines modules and plugins
├── Source/
│   └── MyEditor/
│       ├── MyEditor.Target.cs       # Build target for game/editor executable
│       ├── MyEditorEditor.Target.cs # Build target for editor-only code
│       ├── MyEditor.Build.cs        # Module build rules (UBT)
│       ├── MyEditor.h               # Minimal module header
│       └── MyEditor.cpp             # IMPLEMENT_PRIMARY_GAME_MODULE entry point
├── Config/                    # Default*.ini config files (editor/user overrides go in Saved/)
├── Content/                   # (Currently empty) Asset storage
├── Saved/                     # Runtime-generated config, logs, crash reports
├── Intermediate/              # Build artifacts (project files, object files)
├── Binaries/                 # Compiled DLLs and binaries
└── MyEditor.sln               # Visual Studio solution
```

### Key Build Files
- `MyEditor.Build.cs` — Controls module dependencies, PCH usage, and compilation flags via Unreal Build Tool.
- `MyEditor.Target.cs` — Defines the `MyEditor` target (standalone game/editor process).
- `MyEditorEditor.Target.cs` — Defines the `MyEditorEditor` target (editor-only compilation).

### Config Layering
Unreal uses layered INI files. `Config/Default*.ini` are defaults; user/editor overrides live in `Saved/Config/Windows/`. Do not edit files in `Saved/` directly.

## Important Conventions

- **Enhanced Input**: The project references `EnhancedInput` and `EnhancedPlayerInput` by default. If adding input handling, use the Enhanced Input System (not legacy `InputComponent`).
- **Slate UI**: The build cs has commented-out Slate dependencies. Uncomment to enable Slate UI code.
- **Module loading phase**: Currently `LoadingPhase: "Default"`. For editor-specific initialization order, consider `PostEngineInit`.
- **Single module structure**: All production code lives in `Source/MyEditor/`. As the project grows, consider subfolders (e.g., `Source/MyEditor/Public/`, `Private/`) following UE conventions.
