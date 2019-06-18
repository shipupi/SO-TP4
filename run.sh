#!/bin/bash

make
# ./server&
#docker exec -it 56d65a05977e bash


#port="$(lsof | grep 'LISTEN' | awk '{print $9}' |  sed 's/[^0-9]*//g')"
./client