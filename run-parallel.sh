#!/bin/bash

function run_with_n_threads() {
	echo "$1 THREADS"
	for i in {1000000..10000000..500000}
	do
		gcc -DSIZE=$i -DOMP_NUM_THREADS=$1 parallel-merge-sort.c -fopenmp && echo "$i: $(./a.out)"
	done
}

echo 'PARALLEL'
run_with_n_threads 2
run_with_n_threads 4
run_with_n_threads 8
run_with_n_threads 16