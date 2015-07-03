EXECUTABLE=hanoi

CC=gcc 
CFLAGS=-Wall -std=c89
LDFLAGS=-lm

SOURCEDIR=src
DISTDIR=dist

SOURCES=$(wildcard $(SOURCEDIR)/*.c)

all: $(SOURCES) $(EXECUTABLE)

clean: 
	@rm $(DISTDIR) -rf
	@mkdir $(DISTDIR)

run: all
	@$(DISTDIR)/$(EXECUTABLE) 3

$(EXECUTABLE): $(SOURCES)
	@$(CC) $(LDFLAGS) -o $(DISTDIR)/$@ $(SOURCES)
