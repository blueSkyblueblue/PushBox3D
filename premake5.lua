workspace "PushBox3D"
    architecture "x64"
    startproject "PushBox3D"
    configurations { "debug", "release" }

project "PushBox3D"
    location "PushBox3D"
    kind "ConsoleApp"
    language "C++"
    
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}/%{prj.name}"
    objdir "%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}/%{prj.name}"
    
    defines
    {
        "GLFW_INCLUDE_NONE"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/glm",
        "%{prj.name}/vendor/stb_image",
        "%{wks.location}/deps/GLFW/include",
        "%{wks.location}/deps/Glad/include"
    }

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/**.hpp",
        "%{prj.name}/vendor/glm/**.hpp",
        "%{prj.name}/vendor/stb_image/**.h",
        "%{prj.name}/vendor/stb_image/**.cpp"
    }

    removefiles
    {
        "%{prj.name}/vendor/glm/**.cpp",
    }

    libdirs
    {
        "%{wks.location}/deps/GLFW/lib",
        "%{wks.location}/deps/Glad/lib",
    }

    links
    {
        "GLAD_s.lib",
        "GLFW_s.lib",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "off"
        systemversion "latest"

    filter "configurations:debug"
        symbols "on"
        optimize "off"

    filter "configurations:release"
        symbols "off"
        optimize "on"

