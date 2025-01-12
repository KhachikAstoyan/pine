CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c17 -DVERSION=\"0.0.0\"
SOURCES = $(shell find src -type f -name '*.c')

BUILD_DIR = build
TARGET = $(BUILD_DIR)/editor

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p $(BUILD_DIR)
	$(CC) ${CFLAGS} $^ -o $@

clean:
	rm -rf $(BUILD_DIR)	

