#!/bin/bash

start=$(date +%s)
make clean
make
echo "===== build done ====="
echo

./out

echo
echo "===== test finish ====="
end=$(date +%s)
elapse=$[ $end - $start ]
echo elapse $elapse s