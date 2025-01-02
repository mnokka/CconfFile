#include <stdio.h>
#include "ini.h" // INIH-kirjasto

typedef struct {
    int width;
    int height;
} config_t;

static int handler(void* user, const char* section, const char* name, const char* value) {
    config_t* pconfig = (config_t*)user;
    if (strcmp(section, "Window") == 0) {
        if (strcmp(name, "width") == 0) {
            pconfig->width = atoi(value);
        } else if (strcmp(name, "height") == 0) {
            pconfig->height = atoi(value);
        }
    }
    return 1; // Success
}

int main() {
    config_t config = {800, 600}; // Oletusarvot

    if (ini_parse("zgloom.conf", handler, &config) < 0) {
        printf("Konfiguraatiotiedostoa ei löytynyt. Käytetään oletusarvoja.\n");
    } else {
        printf("Ikkunakoko: %dx%d\n", config.width, config.height);
    }

    // Käytä config.width ja config.height ikkunan luonnissa
    return 0;
}
