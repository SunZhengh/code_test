#!/bin/bash
###
 # @Author: hox 1510214118@qq.com
 # @Date: 2023-07-09 11:10:19
 # @LastEditors: hox 1510214118@qq.com
 # @LastEditTime: 2023-07-09 11:44:46
 # @FilePath: \code_test\huawei\05_num_game\build.sh
 # @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
### 

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

make clean