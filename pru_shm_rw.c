void ocp_init(void)
{
  /* enable ocp wide access */

  __asm__ __volatile__
  (
   " LBCO &r0, C4, 4, 4 \n"
   " CLR r0, r0, 4 \n"
   " SBCO &r0, C4, 4, 4 \n"
  );
}

void write_int(int index, int value)
{
	(*(volatile unsigned int *) (0x00012000 + 4 * index)) = value;	
}

int read_int(int index)
{	
  return (*(volatile unsigned int *) (0x00012000 + 4 * index));	
}
