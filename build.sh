#!/bin/bash

gcc main.c helpers.c -o main -ggdb -O0 -lnotcurses -lnotcurses-core -D_XOPEN_SOURCE=600
