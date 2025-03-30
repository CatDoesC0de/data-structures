workspace "HelloWorld"

configurations {"Release"}

project "data-structures"
    kind "ConsoleApp"
    language "C++"
    location "build/%{prj.name}"

    files {"test/**.cpp" }
    includedirs {"vendor/doctest", "src/**" }

    targetdir "build/tests"
    objdir "build/%{prj.name}/bin-int/%{cfg.buildcfg}"