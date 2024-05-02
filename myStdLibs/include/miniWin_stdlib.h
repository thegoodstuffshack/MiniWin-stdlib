// windows c only
//
// miniWin_stdlib.h
//

#ifndef __MINIWIN_STDLIB__
#define __MINIWIN_STDLIB__


// stdlib type definitions
#if _WIN64
	typedef unsigned long long size_t;
#else
	typedef unsigned int size_t;
#endif // _WIN64

typedef unsigned short wchar_t;

typedef struct DIV_T {
	int quot;
	int rem;
} div_t;

typedef struct LDIV_T {
	long quot;
	long rem;
} ldiv_t;

// stdlib macros

#define NULL ((void *)0)
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 0x7ffff
#define MB_CUR_MAX ___mb_cur_max_func(void)
int __cdecl ___mb_cur_max_func(void);


// stdlib functions

double atof(const char *str);
int atoi(const char *str);
long atol(const char *str);

double strtod(const char *str, char **ptr);
long strtol(const char *str, char **ptr, int num);
unsigned long strtoul(const char *str, char** ptr, int num);

void *calloc(size_t nUnits, size_t unitSize);
void free(void *pMem);
void *malloc(size_t size);
void *realloc(void *pMem, size_t size);

void abort(unsigned int exitCode);
int atexit(void (*function)(void));
void exit(unsigned int errorCode);

char *getenv(const char *envName);

int abs(int num);
long int labs(long int num);

div_t div(int numer, int denom);
ldiv_t ldiv(long numer, long denom);

int rand(void);


typedef int BOOL;
#define true 1
#define false 0

// Windows API Error Check
__declspec(dllimport) unsigned int __stdcall GetLastError();


#endif /* __MINIWIN_STDLIB__ */