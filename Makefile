DIRSRC = ./src
DIRINC = ./inc
DIROBJ = ./obj
DIRBIN = ./bin
DIROUT = ./out

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -I$(DIRINC) -MP -MD
LDFLAGS = -lm

NAME = birdsong
SRCS = $(wildcard $(DIRSRC)/*.c)
OBJS = $(patsubst $(DIRSRC)/%.c,$(DIROBJ)/%.o,$(SRCS))
DEPS = $(patsubst $(DIRSRC)/%.c,$(DIROBJ)/%.d,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(DIRBIN)
	@$(CC) -o $(DIRBIN)/$(NAME) $^ $(LDFLAGS)
	@echo "Done!"

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	@mkdir -p $(DIROBJ)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJS) $(DEPS) $(DIRBIN)/$(NAME)
	@rmdir $(DIRBIN)
	@rmdir $(DIROBJ)

run:
	@$(DIRBIN)/$(NAME)

play:
	@vlc $(DIROUT)/audio.wav
