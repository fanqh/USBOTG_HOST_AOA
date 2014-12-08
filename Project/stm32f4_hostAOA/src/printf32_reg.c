#include "stdio.h"
#include "usb_core.h"



void printfpdev_reg(USB_OTG_CORE_HANDLE* pdev)
{
	uint32_t  i ;
	uint32_t  *temp, size;

	size = sizeof(USB_OTG_GREGS)/4;




temp = (uint32_t*)pdev->regs.INEP_REGS;

temp += 76;
*temp =  0;
 
temp ++;
*temp = 0;

	temp = (uint32_t*)pdev->regs.OUTEP_REGS;

	temp += 61;
	*temp = 0;
	temp++;
	*temp = 0;

temp = (uint32_t*)pdev->regs.HC_REGS;

temp += 46;
*temp = 0;
temp++;
*temp = 0;





	printf("GREGS:\r\n");
	
	temp = (uint32_t*)pdev->regs.GREGS;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}
#if 1
	printf("DREGS\r\n");
	size = sizeof(USB_OTG_DREGS)/4;
	temp = (uint32_t*)pdev->regs.DREGS;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}

	printf("HREGS\r\n");
	size = sizeof(USB_OTG_HREGS)/4;
	temp = (uint32_t*)pdev->regs.HREGS;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}


	printf("HPRT0\r\n");
	size = sizeof(uint32_t)/4;
	temp = (uint32_t*)pdev->regs.HPRT0;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}

	printf("PCGCCTL\r\n");
	size = sizeof(uint32_t)/4;
	temp = (uint32_t*)pdev->regs.PCGCCTL;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}


	printf("INEP_REGS\r\n");
	size = sizeof(USB_OTG_INEPREGS)/4 * USB_OTG_MAX_TX_FIFOS ;
	temp = (uint32_t*)pdev->regs.INEP_REGS;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}


		printf("OUTEP_REGS\r\n");
	size = sizeof(USB_OTG_OUTEPREGS)/4 * USB_OTG_MAX_TX_FIFOS ;
	temp = (uint32_t*)pdev->regs.OUTEP_REGS;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}

	printf("HC_REGS\r\n");
	size = sizeof(USB_OTG_HC_REGS)/4 * USB_OTG_MAX_TX_FIFOS ;
	temp = (uint32_t*)pdev->regs.HC_REGS;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}


		printf("DFIFO\r\n");
	size = sizeof(uint32_t)/4 * USB_OTG_MAX_TX_FIFOS;
	temp = (uint32_t*)pdev->regs.DFIFO;
	for(i=0;i<size; i++)
	{
		printf("i = %d,   value= 0x%X\r\n", i, *temp);
		temp++;
	}

#endif
	

}


