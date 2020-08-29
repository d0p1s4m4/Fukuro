#!/bin/sh

check_cmd () {
    if ! command -v $1 > /dev/null
    then
        echo "$1 not found"
        exit
    fi
}

check_cmd "indent"

indent \
    -bad -bap \
    -bl -blf  -bli0 -bbo \
    -i4 \
    -l79 -lp \
    -ut -ts4 \
    -ppi1 -psl \
    -c33 -cd33 -cdb -nce -cli1 -cp33 \
    -di16 \
    -fc1 -fca \
    -npcs -nprs \
    -saf -sai -saw \
    -sc -nsob -nss \
    $@
