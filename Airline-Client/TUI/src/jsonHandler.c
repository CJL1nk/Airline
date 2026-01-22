#include "jsonHandler.h"

cJSON* getJson(const char* fileName) {

    FILE *fptr;

    fptr = fopen(fileName, "r");

    char* buf = (char*)malloc(512); // Hard coded number for testing purposes

    if (fptr == NULL) {
        printf("Error opening file!\\n");
        exit(1);
    }

    int _ = fread(buf, sizeof(char), 512, fptr); // Remove warning

    printf("%s", buf);

    cJSON* json = cJSON_Parse(buf);

    return json;
}