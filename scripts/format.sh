#!/bin/sh

check_cmd () {
    if ! command -v $1 > /dev/null
    then
        echo "$1 not found"
        exit
    fi
}

check_cmd "dos2unix"
check_cmd "indent"

dos2unix $@

indent \
    -bad -bap \
    -bl -blf  -bli0 -bbo \
    -i4 \
    -l79 -lp \
    -ut -ts4 \
    -ppi1 -psl \
    -c33 -cd33 -cdb -nce -cli1 -cp33 -ncs \
    -di16 \
    -fc1 -fca \
    -npcs -nprs \
    -saf -sai -saw \
    -sc -nsob -nss \
    -T int8_t -T uint8_t -T int16_t -T uint16_t \
    -T int32_t -T uint32_t -T int64_t -T uint64_t \
    $@
