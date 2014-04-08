#include <pios.h>

//libc_user_libc_v7em_fpv4_sp_d16_hard_t_le_eabi.a(user_libc.o): In function `__aeabi_read_tp':
//user_libc.c:(.text.libc.__aeabi_read_tp+0x4): undefined reference to `__tbss_start__'
volatile void* __tbss_start__;

// ---------------------------------------------------------
#if 0

typedef struct _hardfault_args_t {
  unsigned int r0;
  unsigned int r1;
  unsigned int r2;
  unsigned int r3;
  unsigned int r12;
  unsigned int lr;
  unsigned int pc;
  unsigned int psr;
} hardfault_args_t;

void hard_fault_handler_c (hardfault_args_t* hardfault_args)
{
   for(;;) {
   }
}

void HardFault_Handler(void) __attribute__((naked));
void HardFault_Handler(void)
{
    __asm("TST LR, #4\r\n"
        "ITE EQ\r\n"
        "MRSEQ R0, MSP\r\n"
        "MRSNE R0, PSP\r\n"
        "B hard_fault_handler_c");
}

#endif

// ---------------------------------------------------------

#ifndef HAVE_ROUNDF
float roundf (float x)
{
   float t;
   if (!isfinite (x))
     return (x);

   if (x >= 0.0) 
    {
      t = floorf (x);
      if (t - x <= -0.5)
	t += 1.0;
      return (t);
    } 
   else 
    {
      t = floorf (-x);
      if (t + x <= -0.5)
	t += 1.0;
      return (-t);
    }
}
#endif

#ifndef HAVE_FLOORF
long int lroundf (float x)
{
  return (long int) roundf (x);
}
#endif

