#!/bin/bash

printf "Architecture : "
uname -srvm

printf "Nombre de processeurs : "
nproc --all