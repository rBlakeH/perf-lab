//-*-c++-*-
#ifndef _rtdsc_h_
#define _rtdsc_h_

//
// Inline function to read the CPU clock
//
inline
unsigned long long int rdtscll(void)
{
   unsigned long long ret;
   __asm__ volatile("rdtsc" : "=A" (ret));
   return ret;
}

#endif
