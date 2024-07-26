CC = gcc
FILES = source\logger\logger.c source\server\server.c source\logger\enums\color.c source\utilities.c
INCLUDES = -I"thirdparty\libcyaml\include"

all:
	$(CC) source\main.c $(INCLUDES) $(FILES) -o build\multi-server.exe