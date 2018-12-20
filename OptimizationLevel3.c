#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <math.h>
#include <immintrin.h>
#include <x86intrin.h>


#define ALIGN __attribute__ ((aligned (32)))

double ALIGN a[1024 * 1024];
double ALIGN b[1024 * 1024];
double ALIGN c[1024 * 1024];
double ALIGN c1[1024 * 1024];


// ZHEN XIN TAN RUAN
// OPTIMIZATION LEVEL 3 -O3 MATRIX OPERATION



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */

// 1) DEFAULT IMPLEMENTATION OF DGEMM - COMPLETE*


void dgemm(int n)
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            double cij = 0;
            for(k=0; k<n; k++)
                cij = cij + a[i*n+k] * b[k*n+j];
            c1[i*n+j] = cij;
        }
    }
}



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


// 2) DEFAULT IMPLEMENTATION OF INTRINSIC - COMPLETE*

void dgemm_intrin(int n)   

{
    int i,j,k;
    for(i=0; i<n; i+=1)
    {
        for(j=0; j<n; j+=4)
        {
            __m256d c4  = _mm256_load_pd(&c[i * n+j]);
            for(k=0; k<n; k++)
            {
                __m256d a4 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b4 = _mm256_load_pd(&b[k*n+j]);
                c4 = _mm256_add_pd(c4, _mm256_mul_pd(a4, b4));
            }
            _mm256_store_pd(&c[i*n+j], c4);
        }
    }
}


/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


// 3) DEFAULT IMPLEMENTATION OF UNROLLING - COMPLETE*

void dgemm_unrolling(int n)

{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            double cij = 0;
            for(k=0; k<n; k+=64)
            {
                double s1 = a[i*n+k] * b[k*n+j];
                double s2 = a[i*n+(k+1)] * b[(k+1)*n+j];
                double s3 = a[i*n+(k+2)] * b[(k+2)*n+j];
                double s4 = a[i*n+(k+3)] * b[(k+3)*n+j];
                
                double s5 = a[i*n+(k+4)] * b[(k+4)*n+j];
                double s6 = a[i*n+(k+5)] * b[(k+5)*n+j];
                double s7 = a[i*n+(k+6)] * b[(k+6)*n+j];
                double s8 = a[i*n+(k+7)] * b[(k+7)*n+j];
                
                double s9 = a[i*n+(k+8)] * b[(k+8)*n+j];
                double s10 = a[i*n+(k+9)] * b[(k+9)*n+j];
                double s11 = a[i*n+(k+10)] * b[(k+10)*n+j];
                double s12 = a[i*n+(k+11)] * b[(k+11)*n+j];
                double s13 = a[i*n+(k+12)] * b[(k+12)*n+j];
                double s14 = a[i*n+(k+13)] * b[(k+13)*n+j];
                double s15 = a[i*n+(k+14)] * b[(k+14)*n+j];
                double s16 = a[i*n+(k+15)] * b[(k+15)*n+j];
                
                double s17 = a[i*n+(k+16)] * b[(k+16)*n+j];
                double s18 = a[i*n+(k+17)] * b[(k+17)*n+j];
                double s19 = a[i*n+(k+18)] * b[(k+18)*n+j];
                double s20 = a[i*n+(k+19)] * b[(k+19)*n+j];
                double s21 = a[i*n+(k+20)] * b[(k+20)*n+j];
                double s22 = a[i*n+(k+21)] * b[(k+21)*n+j];
                double s23 = a[i*n+(k+22)] * b[(k+22)*n+j];
                double s24 = a[i*n+(k+23)] * b[(k+23)*n+j];
                double s25 = a[i*n+(k+24)] * b[(k+24)*n+j];
                double s26 = a[i*n+(k+25)] * b[(k+25)*n+j];
                double s27 = a[i*n+(k+26)] * b[(k+26)*n+j];
                double s28 = a[i*n+(k+27)] * b[(k+27)*n+j];
                double s29 = a[i*n+(k+28)] * b[(k+28)*n+j];
                double s30 = a[i*n+(k+29)] * b[(k+29)*n+j];
                double s31 = a[i*n+(k+30)] * b[(k+30)*n+j];
                double s32 = a[i*n+(k+31)] * b[(k+31)*n+j];
                
                double s33 = a[i*n+(k+32)] * b[(k+32)*n+j];
                double s34 = a[i*n+(k+33)] * b[(k+33)*n+j];
                double s35 = a[i*n+(k+34)] * b[(k+34)*n+j];
                double s36 = a[i*n+(k+35)] * b[(k+35)*n+j];
                double s37 = a[i*n+(k+36)] * b[(k+36)*n+j];
                double s38 = a[i*n+(k+37)] * b[(k+37)*n+j];
                double s39 = a[i*n+(k+38)] * b[(k+38)*n+j];
                double s40 = a[i*n+(k+39)] * b[(k+39)*n+j];
                double s41 = a[i*n+(k+40)] * b[(k+40)*n+j];
                double s42 = a[i*n+(k+41)] * b[(k+41)*n+j];
                double s43 = a[i*n+(k+42)] * b[(k+42)*n+j];
                double s44 = a[i*n+(k+43)] * b[(k+43)*n+j];
                double s45 = a[i*n+(k+44)] * b[(k+44)*n+j];
                double s46 = a[i*n+(k+45)] * b[(k+45)*n+j];
                double s47 = a[i*n+(k+46)] * b[(k+46)*n+j];
                double s48 = a[i*n+(k+47)] * b[(k+47)*n+j];
                double s49 = a[i*n+(k+48)] * b[(k+48)*n+j];
                double s50 = a[i*n+(k+49)] * b[(k+49)*n+j];
                double s51 = a[i*n+(k+50)] * b[(k+50)*n+j];
                double s52 = a[i*n+(k+51)] * b[(k+51)*n+j];
                double s53 = a[i*n+(k+52)] * b[(k+52)*n+j];
                double s54 = a[i*n+(k+53)] * b[(k+53)*n+j];
                double s55 = a[i*n+(k+54)] * b[(k+54)*n+j];
                double s56 = a[i*n+(k+55)] * b[(k+55)*n+j];
                double s57 = a[i*n+(k+56)] * b[(k+56)*n+j];
                double s58 = a[i*n+(k+57)] * b[(k+57)*n+j];
                double s59 = a[i*n+(k+58)] * b[(k+58)*n+j];
                double s60 = a[i*n+(k+59)] * b[(k+59)*n+j];
                double s61 = a[i*n+(k+60)] * b[(k+60)*n+j];
                double s62 = a[i*n+(k+61)] * b[(k+61)*n+j];
                double s63 = a[i*n+(k+62)] * b[(k+62)*n+j];
                double s64 = a[i*n+(k+63)] * b[(k+63)*n+j];
                
                cij += s1 + s2 + s3 + s4 +s5 + s6+ s7 + s8 +s9 + s10 + s11 +
                s12 +s13 + s14 + s15 +s16 + s17 + s18 + s19 +s20 + s21 + s22 +
                s23 + s24 + s25 + s26 + s27 + s28 + s29 + s30 + s31 + s32 +
                s33 + s34 + s35 + s36 + s37 + s38 + s39 + s40 + s41 + s42 +
                s43 + s44 + s45 + s46 + s47 + s48 + s49 + s50 + s51 + s52 +
                s53 + s54 + s55 + s56 + s57 + s58 + s59 + s60 + s61 + s62 + s63 + s64;
                
                
                
                
            }
            c[i*n+j] = cij;
        }
    }
}



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


// 4) DEFAULT IMPLEMENTATION OF BLOCK / COMPLETE*

#define BLOCK_SIZESS 64

void do_block(int n, int si, int sj, int sk, double *a, double *b, double *c) 
{
    int i, j, k;
    for (i=si; i<si+BLOCK_SIZESS; i++)
        for (j=sj; j<sj+BLOCK_SIZESS; j++) {
            double cij = c[i*n+j];
            for (k=sk; k<sk+BLOCK_SIZESS; k++)
                cij += a[i*n+k] * b[k*n+j];
            c[i*n+j] = cij;
        }
}


void dgemm_blocking(int n)
{
    int i, j, k;
    for(i=0; i<n; i+=BLOCK_SIZESS)
        for(j=0; j<n; j+=BLOCK_SIZESS) {
            c[i*n+j] = 0;
            for(k=0; k<n; k+=BLOCK_SIZESS)
                do_block(n, i, j, k, a, b, c);
        }
}



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */

// 5) OPTIMIZATION INTRINSIC + BLOCK (AVX + BLOCKED) - COMPLETE*

#define BLOCK_SIZE 64

void do_block_intrinsic (int n, int si, int sj, int sk, double *a, double *b, double *c )

{
    int i,j,k;
    for(i=si; i<si+BLOCK_SIZE; i++)
    {
        for(j=sj; j<sj+BLOCK_SIZE; j+=4)
        {
            __m256d c4  = _mm256_load_pd(&c[i * n+j]);
            for(k=sk; k<sk+BLOCK_SIZE; k++)
            {
                __m256d a4 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b4 = _mm256_load_pd(&b[k*n+j]);
                c4 = _mm256_add_pd(c4, _mm256_mul_pd(a4, b4));
            }
            _mm256_store_pd(&c[i*n+j], c4);
        }
    }
}


void dgemm_blocking_intrinsic (int n)

{
    int si,sj, sk;
    for (si=0; si<n; si+=BLOCK_SIZE)
        for (sj=0; sj<n; sj+=BLOCK_SIZE)
            
        {
            c[si*n+sj] = 0;
            
            for (sk=0; sk<n; sk+=BLOCK_SIZE)
                do_block_intrinsic (n,si,sj,sk,a,b,c);
        }
}


/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


// 6) IMPLEMENTATION OF BLOCK + UNROLLING + INTRINSIC ( AVX + Unroll + Blocked + Intrinsic)  - COMPLETE

#define BLOCK_SIZES 128

void do_block_AVX(int n, int si, int sj, int sk, double *a, double *b, double *c) 

{
    int i, j, k;
    for (i=si; i<si+BLOCK_SIZES; i++)
        for (j=sj; j<sj+BLOCK_SIZES; j+=BLOCK_SIZES) {
            
            __m256d c41  = _mm256_load_pd(&c[i*n+j]);
            __m256d c42  = _mm256_load_pd(&c[i*n+(j+4)]);
            
            
            
            __m256d c43  = _mm256_load_pd(&c[i*n+(j+8)]);
            __m256d c44  = _mm256_load_pd(&c[i*n+(j+12)]);
            
            
            __m256d c45  = _mm256_load_pd(&c[i*n+(j+16)]);
            __m256d c46  = _mm256_load_pd(&c[i*n+(j+20)]);
            __m256d c47  = _mm256_load_pd(&c[i*n+(j+24)]);
            __m256d c48  = _mm256_load_pd(&c[i*n+(j+28)]);
            
            
            
            __m256d c49  = _mm256_load_pd(&c[i*n+(j+32)]);
            __m256d c50  = _mm256_load_pd(&c[i*n+(j+36)]);
            __m256d c51  = _mm256_load_pd(&c[i*n+(j+40)]);
            __m256d c52  = _mm256_load_pd(&c[i*n+(j+44)]);
            __m256d c53  = _mm256_load_pd(&c[i*n+(j+48)]);
            __m256d c54  = _mm256_load_pd(&c[i*n+(j+52)]);
            __m256d c55  = _mm256_load_pd(&c[i*n+(j+56)]);
            __m256d c56  = _mm256_load_pd(&c[i*n+(j+60)]);
            
            
            
            
            __m256d c57  = _mm256_load_pd(&c[i*n+(j+64)]);
            __m256d c58  = _mm256_load_pd(&c[i*n+(j+68)]);
            __m256d c59  = _mm256_load_pd(&c[i*n+(j+72)]);
            __m256d c60  = _mm256_load_pd(&c[i*n+(j+76)]);
            __m256d c61  = _mm256_load_pd(&c[i*n+(j+80)]);
            __m256d c62  = _mm256_load_pd(&c[i*n+(j+84)]);
            __m256d c63  = _mm256_load_pd(&c[i*n+(j+88)]);
            __m256d c64  = _mm256_load_pd(&c[i*n+(j+92)]);
            __m256d c65  = _mm256_load_pd(&c[i*n+(j+96)]);
            __m256d c66  = _mm256_load_pd(&c[i*n+(j+100)]);
            __m256d c67  = _mm256_load_pd(&c[i*n+(j+104)]);
            __m256d c68  = _mm256_load_pd(&c[i*n+(j+108)]);
            __m256d c69  = _mm256_load_pd(&c[i*n+(j+112)]);
            __m256d c70  = _mm256_load_pd(&c[i*n+(j+116)]);
            __m256d c71  = _mm256_load_pd(&c[i*n+(j+120)]);
            __m256d c72  = _mm256_load_pd(&c[i*n+(j+124)]);
            
            
            
            for (k=sk; k<sk+BLOCK_SIZES; k+=1){
                
                __m256d a1 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b1 = _mm256_load_pd(&b[k*n+j]);
                c41 = _mm256_add_pd(c41, _mm256_mul_pd(a1, b1));
                
                __m256d a2 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b2 = _mm256_load_pd(&b[k*n+(j+4)]);
                c42 = _mm256_add_pd(c42, _mm256_mul_pd(a2, b2));
                
                
                
                
                __m256d a3 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b3 = _mm256_load_pd(&b[k*n+(j+8)]);
                c43 = _mm256_add_pd(c43, _mm256_mul_pd(a3, b3));
                
                __m256d a4 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b4 = _mm256_load_pd(&b[k*n+(j+12)]);
                c44 = _mm256_add_pd(c44, _mm256_mul_pd(a4, b4));
                
                
                
                
                
                __m256d a5 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b5 = _mm256_load_pd(&b[k*n+(j+16)]);
                c45 = _mm256_add_pd(c45, _mm256_mul_pd(a5, b5));
                
                __m256d a6 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b6 = _mm256_load_pd(&b[k*n+(j+20)]);
                c46 = _mm256_add_pd(c46, _mm256_mul_pd(a6, b6));
                
                __m256d a7 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b7 = _mm256_load_pd(&b[k*n+(j+24)]);
                c47 = _mm256_add_pd(c47, _mm256_mul_pd(a7, b7));
                
                __m256d a8 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b8 = _mm256_load_pd(&b[k*n+(j+28)]);
                c48 = _mm256_add_pd(c48, _mm256_mul_pd(a8, b8));
                
                
                
                
                
                __m256d a9 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b9 = _mm256_load_pd(&b[k*n+(j+32)]);
                c49 = _mm256_add_pd(c49, _mm256_mul_pd(a9, b9));
                
                __m256d a10 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b10 = _mm256_load_pd(&b[k*n+(j+36)]);
                c50 = _mm256_add_pd(c50, _mm256_mul_pd(a10, b10));
                
                __m256d a11 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b11 = _mm256_load_pd(&b[k*n+(j+40)]);
                c51 = _mm256_add_pd(c51, _mm256_mul_pd(a11, b11));
                
                __m256d a12 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b12 = _mm256_load_pd(&b[k*n+(j+44)]);
                c52 = _mm256_add_pd(c52, _mm256_mul_pd(a12, b12));
                
                __m256d a13 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b13 = _mm256_load_pd(&b[k*n+(j+48)]);
                c53 = _mm256_add_pd(c53, _mm256_mul_pd(a13, b13));
                
                __m256d a14 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b14 = _mm256_load_pd(&b[k*n+(j+52)]);
                c54 = _mm256_add_pd(c54, _mm256_mul_pd(a14, b14));
                
                __m256d a15 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b15 = _mm256_load_pd(&b[k*n+(j+56)]);
                c55 = _mm256_add_pd(c55, _mm256_mul_pd(a15, b15));
                
                __m256d a16 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b16 = _mm256_load_pd(&b[k*n+(j+60)]);
                c56= _mm256_add_pd(c56, _mm256_mul_pd(a16, b16));
                
                
                
                
                
                __m256d a17 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b17 = _mm256_load_pd(&b[k*n+(j+64)]);
                c57 = _mm256_add_pd(c57, _mm256_mul_pd(a17, b17));
                
                __m256d a18 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b18 = _mm256_load_pd(&b[k*n+(j+68)]);
                c58 = _mm256_add_pd(c58, _mm256_mul_pd(a18, b18));
                
                __m256d a19 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b19 = _mm256_load_pd(&b[k*n+(j+72)]);
                c59 = _mm256_add_pd(c59, _mm256_mul_pd(a19, b19));
                
                __m256d a20 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b20 = _mm256_load_pd(&b[k*n+(j+76)]);
                c60= _mm256_add_pd(c60, _mm256_mul_pd(a20, b20));
                
                __m256d a21 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b21 = _mm256_load_pd(&b[k*n+(j+80)]);
                c61 = _mm256_add_pd(c61, _mm256_mul_pd(a21, b21));
                
                __m256d a22 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b22 = _mm256_load_pd(&b[k*n+(j+84)]);
                c62 = _mm256_add_pd(c62, _mm256_mul_pd(a22, b22));
                
                __m256d a23 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b23 = _mm256_load_pd(&b[k*n+(j+88)]);
                c63 = _mm256_add_pd(c63, _mm256_mul_pd(a23, b23));
                
                __m256d a24 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b24 = _mm256_load_pd(&b[k*n+(j+92)]);
                c64= _mm256_add_pd(c64, _mm256_mul_pd(a24, b24));
                
                __m256d a25 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b25 = _mm256_load_pd(&b[k*n+(j+96)]);
                c65 = _mm256_add_pd(c65, _mm256_mul_pd(a25, b25));
                
                __m256d a26 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b26 = _mm256_load_pd(&b[k*n+(j+100)]);
                c66 = _mm256_add_pd(c66, _mm256_mul_pd(a26, b26));
                
                __m256d a27 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b27 = _mm256_load_pd(&b[k*n+(j+104)]);
                c67 = _mm256_add_pd(c67, _mm256_mul_pd(a27, b27));
                
                __m256d a28 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b28 = _mm256_load_pd(&b[k*n+(j+108)]);
                c68 = _mm256_add_pd(c68, _mm256_mul_pd(a28, b28));
                
                __m256d a29 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b29 = _mm256_load_pd(&b[k*n+(j+112)]);
                c69 = _mm256_add_pd(c69, _mm256_mul_pd(a29, b29));
                
                __m256d a30 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b30 = _mm256_load_pd(&b[k*n+(j+116)]);
                c70 = _mm256_add_pd(c70, _mm256_mul_pd(a30, b30));
                
                __m256d a31 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b31 = _mm256_load_pd(&b[k*n+(j+120)]);
                c71 = _mm256_add_pd(c71, _mm256_mul_pd(a31, b31));
                
                __m256d a32 = _mm256_broadcast_sd(&a[i*n+k]);
                __m256d b32 = _mm256_load_pd(&b[k*n+(j+124)]);
                c72 = _mm256_add_pd(c72, _mm256_mul_pd(a32, b32));
                
                
                
                
            }
            
            _mm256_store_pd(&c[i*n+j], c41);
            _mm256_store_pd(&c[i*n+(j+4)], c42);
            
            
            _mm256_store_pd(&c[i*n+(j+8)], c43);
            _mm256_store_pd(&c[i*n+(j+12)], c44);
            
            
            
            _mm256_store_pd(&c[i*n+(j+16)], c45);
            _mm256_store_pd(&c[i*n+(j+20)], c46);
            _mm256_store_pd(&c[i*n+(j+24)], c47);
            _mm256_store_pd(&c[i*n+(j+28)], c48);
            
            
            
            _mm256_store_pd(&c[i*n+(j+32)], c49);
            _mm256_store_pd(&c[i*n+(j+36)], c50);
            _mm256_store_pd(&c[i*n+(j+40)], c51);
            _mm256_store_pd(&c[i*n+(j+44)], c52);
            _mm256_store_pd(&c[i*n+(j+48)], c53);
            _mm256_store_pd(&c[i*n+(j+52)], c54);
            _mm256_store_pd(&c[i*n+(j+56)], c55);
            _mm256_store_pd(&c[i*n+(j+60)], c56);
            
            
            
            
            _mm256_store_pd(&c[i*n+(j+64)], c57);
            _mm256_store_pd(&c[i*n+(j+68)], c58);
            _mm256_store_pd(&c[i*n+(j+72)], c59);
            _mm256_store_pd(&c[i*n+(j+76)], c60);
            _mm256_store_pd(&c[i*n+(j+80)], c61);
            _mm256_store_pd(&c[i*n+(j+84)], c62);
            _mm256_store_pd(&c[i*n+(j+88)], c63);
            _mm256_store_pd(&c[i*n+(j+92)], c64);
            _mm256_store_pd(&c[i*n+(j+96)], c65);
            _mm256_store_pd(&c[i*n+(j+100)], c66);
            _mm256_store_pd(&c[i*n+(j+104)], c67);
            _mm256_store_pd(&c[i*n+(j+108)], c68);
            _mm256_store_pd(&c[i*n+(j+112)], c69);
            _mm256_store_pd(&c[i*n+(j+116)], c70);
            _mm256_store_pd(&c[i*n+(j+120)], c71);
            _mm256_store_pd(&c[i*n+(j+124)], c72);
            
            
        }
}


void dgemm_blocking_AVX (int n)

{
    
    for ( int sj = 0; sj < n; sj += BLOCK_SIZES )
        for ( int si = 0; si < n; si += BLOCK_SIZES )
            for ( int sk = 0; sk < n; sk += BLOCK_SIZES )
                do_block_AVX(n, si, sj, sk, a, b, c);
    
}

/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */



// 7) OPTIMIZATION DGEMM USING AVX *** DIDNT WORK *******


void dgemm_AVX(int n)

{
    
    int i,j,k;
    
    for (i = 0; i < n; i+=4 )
        for (j = 0; j < n; j++ ) {
            __m256d c0 = _mm256_load_pd(c1+i+j*n);
            for(k = 0; k < n; k++ )
                c0 = _mm256_add_pd(c0,
                                   _mm256_mul_pd(_mm256_load_pd(a+i+k*n),
                                                 _mm256_broadcast_sd(b+k+j*n)));
            _mm256_store_pd(c1+i+j*n, c0);
            
        }
}



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


// 8) OPTIMIZATION UNROLLING  (AVX + Unroll)  ** DIDNT WORK ******


#define UNROLL (32)

void dgemm_unroll (int n)

{
    for ( int i = 0; i < n; i+=UNROLL*4 )
        for ( int j = 0; j < n; j++ ) {
            __m256d c1[4];
            for ( int x = 0; x < UNROLL; x++ )
                c1[x] = _mm256_load_pd(c+i+x*4+j*n);
            
            for( int k = 0; k < n; k++ )
            {
                __m256d b4 = _mm256_broadcast_sd(b+k+j*n);
                for (int x = 0; x < UNROLL; x++)
                    c1[x] = _mm256_add_pd(c1[x],
                                          _mm256_mul_pd(_mm256_load_pd(a+n*k+x*4+i), b4));
            }
            for ( int x = 0; x < UNROLL; x++ )
                _mm256_store_pd(c+i+x*4+j*n, c1[x]);
            
            
        }
}



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */



// 9) IMPLEMENTATION OF BLOCK + UNROLLING ( AVX + Unroll + Blocked) ** DIDNT WORK ******

#define UNROLLING (4)
#define BLOCK 32

void do_block_unroll (int n, int si, int sj, int sk, double *a, double *b, double *c)

{
    
    for ( int i = si; i < si+BLOCK; i+=UNROLLING*4 )
        for ( int j = sj; j < sj+BLOCK; j++ ) {
            __m256d c4[4];
            for ( int x = 0; x < UNROLLING; x++ )
                c4[x] = _mm256_load_pd(c+i+x*4+j*n);
            for( int k = sk; k < sk+BLOCK; k++ )
            {
                __m256d b4 = _mm256_broadcast_sd(b+k+j*n );
                for ( int x = 0; x < UNROLLING; x++)
                    c4[x] = _mm256_add_pd(c4[x],
                                          _mm256_mul_pd(_mm256_load_pd(a+n*k+x*4+i), b4 ));
            }
            for ( int x = 0; x < UNROLLING; x++ )
                _mm256_store_pd(c+i+x*4+j*n, c4[x]);
        }
}



void dgemm_blocking_unroll(int n)

{
    
    for ( int sj = 0; sj < n; sj += BLOCK )
        for ( int si = 0; si < n; si += BLOCK )
            for ( int sk = 0; sk < n; sk += BLOCK )
                do_block_unroll(n, si, sj, sk, a, b, c);
    
}


/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


// 10 ) IMPLEMENTATION OF BLOCK + UNROLLING - COMPLETE*

#define BLOCKS 32

void do_block_unrolling (int n, int si, int sj, int sk, double *a, double *b, double *c)
{
    
    int i, j ,k;
    for (i = si; i < si+BLOCKS; i++)
        for (j=sj; j<sj+BLOCKS; j++) {
            
            double cij = c[i*n+j];
            for (k=sk; k<sk+BLOCKS;k+=32) {
                
                
                cij += a[i*n+k] * b[k*n+j];
                cij += a[i*n+(k+1)] * b[(k+1)*n+j];
                cij += a[i*n+(k+2)] * b[(k+2)*n+j];
                cij += a[i*n+(k+3)] * b[(k+3)*n+j];
                
                cij += a[i*n+(k+4)] * b[(k+4)*n+j];
                cij += a[i*n+(k+5)] * b[(k+5)*n+j];
                cij += a[i*n+(k+6)] * b[(k+6)*n+j];
                cij += a[i*n+(k+7)] * b[(k+7)*n+j];
                
                cij += a[i*n+(k+8)] * b[(k+8)*n+j];
                cij += a[i*n+(k+9)] * b[(k+9)*n+j];
                cij += a[i*n+(k+10)] * b[(k+10)*n+j];
                cij += a[i*n+(k+11)] * b[(k+11)*n+j];
                cij += a[i*n+(k+12)] * b[(k+12)*n+j];
                cij += a[i*n+(k+13)] * b[(k+13)*n+j];
                cij += a[i*n+(k+14)] * b[(k+14)*n+j];
                cij += a[i*n+(k+15)] * b[(k+15)*n+j];
                
                cij += a[i*n+(k+16)] * b[(k+16)*n+j];
                cij += a[i*n+(k+17)] * b[(k+17)*n+j];
                cij += a[i*n+(k+18)] * b[(k+18)*n+j];
                cij += a[i*n+(k+19)] * b[(k+19)*n+j];
                cij += a[i*n+(k+20)] * b[(k+20)*n+j];
                cij += a[i*n+(k+21)] * b[(k+21)*n+j];
                cij += a[i*n+(k+22)] * b[(k+22)*n+j];
                cij += a[i*n+(k+23)] * b[(k+23)*n+j];
                cij += a[i*n+(k+24)] * b[(k+24)*n+j];
                cij += a[i*n+(k+25)] * b[(k+25)*n+j];
                cij += a[i*n+(k+26)] * b[(k+26)*n+j];
                cij += a[i*n+(k+27)] * b[(k+27)*n+j];
                cij += a[i*n+(k+28)] * b[(k+28)*n+j];
                cij += a[i*n+(k+29)] * b[(k+29)*n+j];
                cij += a[i*n+(k+30)] * b[(k+30)*n+j];
                cij += a[i*n+(k+31)] * b[(k+31)*n+j];
                
            }
            
            c[i*n+j] = cij;
            
        }
    
}

void dgemm_blocking_unrolling(int n)

{
    for ( int sj = 0; sj < n; sj += BLOCKS )
        for ( int si = 0; si < n; si += BLOCKS )
            for ( int sk = 0; sk < n; sk += BLOCKS )
                do_block_unrolling(n, si, sj, sk, a, b, c);
    
}



/* ---------------------------------------------------------------------------------------------------------
 --------------------------------------------------------------------------------------------------------- */


/* Implement this function with multiple optimization techniques. */

void optimized_dgemm(int n)

{
    
    
    // ALL THE METHODS/ FUNCTION THAT WERE USED FOR THE ASSIGMENT
    
    //dgemm_blocking(n);
    //dgemm_unrolling(n);
    //dgemm_intrin(n);
    //dgemm_blocking_intrinsic (n);
    //dgemm_blocking_unrolling(n);
    dgemm_blocking_AVX(n);
    
    
}

int main(int argc, char** argv)

{
    int i, j;
    time_t t;
    struct timeval start, end;
    double elapsed_time;
    
    int check_correctness = 0;
    int correct = 1;
    
    if(argc > 1)
    {
        if(strcmp(argv[1], "corr") == 0)
        {
            check_correctness = 1;
        }
    }
    
    /* Initialize random number generator */
    srand((unsigned) time(&t));
    
    /* Populate the arrays with random values */
    for(i=0; i<1024; i++)
    {
        for(j=0; j<1024; j++)
        {
            a[i*1024+j] = (double)rand() / (RAND_MAX + 1.0);
            b[i*1024+j] = (double)rand() / (RAND_MAX + 1.0);
            c[i*1024+j] = 0.0;
            c1[i*1024+j] = 0.0;
        }
    }
    
    
    gettimeofday(&start, NULL);
    
    /* Call you optimized function optimized_dgemm */
    optimized_dgemm(1024);
    
    gettimeofday(&end, NULL);
    
    /* For TA use only */
    
    if(check_correctness)
    {
        dgemm(1024);
        for(i=0; (i<1024) && correct ; i++)
        {
            for(j=0; (j<1024) && correct; j++)
            {
                if(fabs(c[i*1024+j]-c1[i*1024+j]) >= 0.0000001)
                {
                    printf("%f != %f\n", c[i*1024+j], c1[i*1024+j]);
                    correct = 0;
                }
            }
        }
        
        if(correct)
            printf("Result is correct!\n");
        else
            printf("Result is incorrect!\n");
    }
    
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0;
    
    printf("dgemm finished in %f milliseconds.\n", elapsed_time);
}
