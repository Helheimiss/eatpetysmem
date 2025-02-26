CC ?= gcc
ARCH ?= 32


SRC = ./src/main.c ./src/eatpetysmem.c ./src/thr_func.c ./src/winshake.c
CFLAGS = -O3 -s -g0 -pthread -mwindows -fomit-frame-pointer -fdata-sections -ffunction-sections -Wl,--gc-sections


ifeq ($(ARCH), 64)
    CFLAGS += -m64
    TARGET = ./bin/eatpetysmemx64.exe
else ifeq ($(ARCH), 32)
    CFLAGS += -m32
    TARGET = ./bin/eatpetysmemx86.exe
else
    $(error Unknown architecture use ARCH=64 or ARCH=32: $(ARCH))
endif


all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)


clean:
	rm -f ./bin/*