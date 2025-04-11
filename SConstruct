env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["src/"])
env.Append(LINKFLAGS=["User32.lib"])


sources = Glob("src/*.cpp")


library = env.SharedLibrary(
    "game/bin/window_utls{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

Default(library)