#!/bin/bash

g++ main.c helpers.c stopwatch.c -o main -ggdb -O0 -lnotcurses -lnotcurses-core
