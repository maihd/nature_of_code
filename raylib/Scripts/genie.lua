local ROOT_DIR = path.getabsolute("..")
local THIRDPARTY_DIR = path.join(ROOT_DIR, "ThirdParty")

local function templateconfigs()
    configuration "Debug"
    do
        flags { "Symbols" }
    end

    configuration "Release"
    do
        flags { "Optimize" }
    end
    
    configuration "vs*"
    do
        defines { "_CRT_SECURE_NO_WARNINGS" }
    end

    configuration "x32"
    do
        libdirs { path.join(ROOT_DIR, "ThirdParty/Library/Win32") }
    end

    configuration "x64"
    do
        libdirs { path.join(ROOT_DIR, "ThirdParty/Library/Win64") }
    end

    configuration {}
end

local function template(name, projectPath, shouldHideConsole)
    project ("NatureOfCode_" .. name)
    do
        if not shouldHideConsole then
            kind "ConsoleApp"
        else 
            configuration "Debug"
            do
                kind "ConsoleApp"
            end

            configuration "Release"
            do
                kind "WindowedApp"
            end
            
            configuration {}
        end

        links {
            "NatureOfCode_Framework",
            "raylib_static",
            "winmm",
        }

        includedirs {
            path.join(ROOT_DIR, "Framework/Include"),
            path.join(ROOT_DIR, "ThirdParty/Include"),
        }

        files {
            path.join(ROOT_DIR, projectPath),
            path.join(ROOT_DIR, projectPath, "*.h"),
            path.join(ROOT_DIR, projectPath, "**/*.h"),
            path.join(ROOT_DIR, projectPath, "*.c"),
            path.join(ROOT_DIR, projectPath, "**/*.c"),
            path.join(ROOT_DIR, projectPath, "*.cpp"),
            path.join(ROOT_DIR, projectPath, "**/*.cpp"),
        }

        defines {
            "GRAPHICS_API_OPENGL_33",
            "PLATFORM_DESKTOP"
        }

        templateconfigs()
    end
end

local function chapter(folder)
    local root = path.join(ROOT_DIR, "Chapters")
    for _, file in pairs(os.matchfiles(path.join(root, folder, "*.c"))) do
        local name = file:gsub(root .. "/", ""):gsub("/", "_"):gsub(".c", "")
        template(name, file)
    end
end

solution "NatureOfCode_Raylib"
do
    local buildDir = path.join(ROOT_DIR, "Projects", string.upper(_ACTION))

    language "C"
    location (buildDir)
    targetdir (path.join(buildDir, "bin"))
    objdir (path.join(buildDir, "obj"))

    platforms { "x32", "x64" }
    configurations { "Debug", "Release" }

    flags {
        "NoPCH",
		"NoRTTI",
		"NoExceptions",
		"NoFramePointer",
    }

    configuration "Debug"
    do
        defines {
            "DEBUG"
        }
    end

    configuration "Release"
    do
        defines {
            "NDEBUG",
            "RELEASE"
        }
    end

    configuration {} 
end

project "NatureOfCode_Framework"
do
    kind "StaticLib"

    links {
    }

    includedirs { 
        path.join(ROOT_DIR, "Framework/Include"),
        path.join(ROOT_DIR, "ThirdParty/Include"),
    }

    files {
        path.join(ROOT_DIR, "Framework/Include/*.h"),
        path.join(ROOT_DIR, "Framework/Include/**/*.h"),
        path.join(ROOT_DIR, "Framework/Sources/*.c"),
        path.join(ROOT_DIR, "Framework/Sources/**/*.c"),
        path.join(ROOT_DIR, "Framework/Sources/*.cpp"),
        path.join(ROOT_DIR, "Framework/Sources/**/*.cpp"),

        path.join(THIRDPARTY_DIR, "Include/raylib.h"),
        path.join(THIRDPARTY_DIR, "Include/raymath.h"),
    }

    templateconfigs()
end

chapter "Introduction"