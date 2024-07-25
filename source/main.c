#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "server\server.h"

int main() {
    setlocale(LC_ALL, "");

    server* server = server_create("test", 7777);
    server_run(server);

    server_destroy(server);

    return 0;
}