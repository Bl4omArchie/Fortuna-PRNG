# Compilateurs
CC = gcc

# Dossiers
SRCDIR = src
INCDIR = includes
BUILDDIR = build

TARGET = fortuna.o

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Options de compilation
CFLAGS = -I$(INCDIR)
LDFLAGS = -lssl -lcrypto

# Règles de construction
all: $(BUILDDIR) $(TARGET)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET): $(OBJS)
	$(CC) main.c -o $(TARGET) $(OBJS) $(LDFLAGS)


clean:
	rm -rf $(BUILDDIR) $(TARGET) .vscode/ *.o

.PHONY: all clean