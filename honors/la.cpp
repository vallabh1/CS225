#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <random>
#include "la.h"
#include<iostream>

void matmulseq(double *A, double *B, double *C, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C[loc(i,j,n)] = 0.0;
		}
			
	}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					C[loc(i,j,n)]+= A[loc(i,k,n)] * B[loc(k,j,n)];
				}
				
			}
			
		}
}

void prefixomp(double *a, double *b, int n){
	// int sum;
	// #pragma omp parallel for
	// 	for(int i = 0; i<n; i++){
	// 	sum = 0;
	// 	for(int j = 0; j<=i; j++){
	// 			sum += a[j];
	// 	}
	// 	b[i] = sum;	
	// 	}		
    // int num_threads = omp_get_max_threads();
    int chunk_size = n / 8;
    // double partial_sum[8] = {0};

    // Parallelize the outer loop using a for loop
    #pragma omp parallel for
    for (int t = 0; t < 8; ++t) {
        int thread_id = t;
        int start = thread_id * chunk_size;
        int end = (thread_id == 8 - 1) ? n : (start + chunk_size);
        

        // Calculate prefix sum for the assigned sub-array using omp for
        // #pragma omp parallel for reduction(+:local_sum)
        for (int i = start; i < end; ++i) {
            if(i == start){
				b[i] = a[i];
			}
			else{
				b[i] = b[i-1] + a[i];
				// partial_sum[t] = b[i-1] + a[i];
			}
				
			 
			

    //          // Store the prefix sum in the output array
        }
	}
	// 	// std::cout<<partial_sum[t]<<std::endl;
		

    //     // Store the last element of the sub-array for later processing
    //     // if (thread_id == num_threads - 1) {
    //     //     partial_sum = b[end];
    //     // }
    


	// double partials[7] = {0};
	// for(int y = 1; y < 8; ++y){
	// 	partials[y-1] = b[(y*chunk_size)-1];
		
	// 	std::cout<<partials[y-1]<<std::endl;
	// }
	

    // Calculate prefix sum for the last elements array using omp for
    // #pragma omp parallel for
    // for (int i = 0; i < n; ++i) {
    //     b[i] += partial_sum;
    // }
	// #pragma omp parallel for
	for (int x = 1; x < 8; ++x) {
        int start1 = x * chunk_size;
        int end1 = (x == 8 - 1) ? n : (start1 + chunk_size);
		for (int i = start1; i < end1; ++i){
			b[i] += b[start1-1];
		}
	}



}
