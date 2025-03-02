# eatpetysmem

to compile, use make or gcc
before compiling, check if the bin directory exists.


flags for makefile compilation:

    CC=(gcc or other)
    ARCH=(32 or 64)
    OS=(WIN or UNIX)
    INFO=(INFO)


compilation example:

    make:
        unix:
            make ARCH=32 OS=UNIX INFO=INFO
        windows
            make ARCH=64 OS=WIN INFO=INFO