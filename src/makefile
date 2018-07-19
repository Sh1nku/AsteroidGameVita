TARGET		:= Asteroid_Game
SOURCES		:= .

INCLUDES	:= include

LIBS = -lvitaGL -lvita2d -lbox2d -lSceLibKernel_stub -lScePvf_stub \
	-lSceAppMgr_stub -lSceAppUtil_stub -lScePgf_stub -lSceCtrl_stub \
	-ljpeg -lfreetype -lc -lSceCommonDialog_stub -lpng16 -lm -lz \
	-lSceGxm_stub -lSceDisplay_stub -lSceSysmodule_stub \

CFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
CPPFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
BINFILES := $(foreach dir,$(DATA), $(wildcard $(dir)/*.bin))
OBJS     := $(addsuffix .o,$(BINFILES)) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CXX      = $(PREFIX)-g++
CFLAGS  = -g -Wl,-q -O3
CXXFLAGS  = $(CFLAGS) -fno-exceptions -std=gnu++11 -fpermissive
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

$(TARGET).vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=ANDY00001 "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
	-a textures/ship.png=textures/ship.png $@

eboot.bin: $(TARGET).velf
	vita-make-fself -s $< eboot.bin

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf *.velf *.elf *.vpk $(OBJS) param.sfo eboot.bin
