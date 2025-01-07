/*
 * This file uses the `inih` library.
 * License: BSD 3-Clause
 * Copyright (c) 2009 Ben Hoyt
 * See the LICENSE.txt file for more details.
 */


/*
 * MIT License
 *
 * Copyright (c) 2025 Mika Nokka
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdio.h>
#include "ini.h" 
typedef struct {
    int width;
    int height;
} config_t;

static int handler(void* user, const char* section, const char* name, const char* value) {
    config_t* pconfig = (config_t*)user;
    if (strcmp(section, "Window") == 0) {
        if (strcmp(name, "Width") == 0) {
            pconfig->width = atoi(value);
        } else if (strcmp(name, "Height") == 0) {
            pconfig->height = atoi(value);
        }
    }
    return 1; 
}

int main() {

    char FileName[] = "zgloom.conf";
    config_t config = {320, 200}; // Oletusarvot

    if (ini_parse(FileName, handler, &config) < 0) {
        printf("No config file found (%s). Using default values\n",FileName);
    } else {
        printf("Config file (%s) found\n",FileName);
    }
    printf("Window size set as: %dx%d\n", config.width, config.height);

    return 0;
}
