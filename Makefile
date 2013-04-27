vpath %.cpp framework/
vpath %.cpp game/
vpath %.o obj/

BIN=mBot
CXX=g++

SDL=`sdl-config --libs --cflags`
LINKLIB=-l SDL_image -l SDL_ttf -l SDL_mixer
OBJDIR=obj


# search frameworks files for all the cpp files
framework = $(shell cd framework; ls *.cpp )
frameworkobjs = $(patsubst %,$(OBJDIR)/%,$(framework:.cpp=.o))
game = $(shell cd game; ls *.cpp ; for F in `ls -d */` ; do cd $$F; ls *.cpp ;cd ..; done)
gameobjs = $(patsubst %,$(OBJDIR)/%,$(game:.cpp=.o))



main=obj/main.o

all: $(BIN)



$(BIN) : $(main) $(frameworkobjs) $(worldobjs) $(gameobjs)
	$(CXX) -o $(BIN) $(OBJDIR)/* $(LINKLIB) $(SDL)

$(OBJDIR)/%.o : %.cpp
	$(CXX) -c -o $@ $^

obj/main.o : main.cpp 
	$(CXX) -c -o $@ $^

clean:
	rm obj/*.o
	rm $(BIN)

remake:
	make clean
	make all

debug:
	@echo $(world)
.PHONY: clean remake debug
