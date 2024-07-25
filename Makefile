CC = gcc
FILES = source\logger\logger.c source\server\server.c source\logger\enums\color.c -o build\multi-server.exe
INCLUDES = -I"thirdparty\libcyaml\include"

all:
	$(CC) source\main.c $(INCLUDES) $(FILES)