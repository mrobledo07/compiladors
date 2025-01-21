#!/bin/bash

make clean
make
mkdir -p example_files/output_files
mkdir -p example_files/stdout_files
input="example_files/input_files"
output="example_files/output_files"
stdout_output="example_files/stdout_files"
for i in {1..18}; do
    ./bin/compiler $input/input_file$i.txt $output/output_file$i.txt > $stdout_output/stdout_file$i.txt
done