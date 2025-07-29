#!/usr/bin/env python

from glob import glob
from pathlib import Path
import os

env = SConscript("godot-cpp/SConstruct")

env.Append(
    CPPPATH=["src/"],
    LINKFLAGS=["User32.lib"]
)

sources = Glob("src/*.cpp")

(extension_path,) = glob("project/addons/window-utils/*.gdextension")

addon_path = Path(extension_path).parent

project_name = Path(extension_path).stem

library = env.SharedLibrary(
    "build{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

debug_or_release = "release" if env["target"] == "template_release" else "debug"
if env["platform"] == "macos":
    library = env.SharedLibrary(
        "{0}/bin/lib{1}.{2}.{3}.framework/{1}.{2}.{3}".format(
            addon_path,
            project_name,
            env["platform"],
            debug_or_release,
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "{}/bin/lib{}.{}.{}.{}{}".format(
            addon_path,
            project_name,
            env["platform"],
            debug_or_release,
            env["arch"],
            env["SHLIBSUFFIX"],
        ),
        source=sources,
    )


Default(library)