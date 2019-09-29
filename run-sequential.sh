#!/bin/bash

echo 'SEQUENTIAL'
for i in {1000000..10000000..500000}
do
	gcc -DSIZE=$i sequential-merge-sort.c -fopenmp && echo "$i: $(./a.out)"
done