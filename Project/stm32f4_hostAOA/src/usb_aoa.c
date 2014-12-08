 /* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"
#include "usbh_usr.h"
#include "usbh_msc_core.h"
#include "usbh_adk_core.h"

USBH_Status USB_AOA_Send(USB_OTG_CORE_HANDLE *pdev, uint8_t *buff, uint16_t len)
{
	memcpy(ADK_Machine.outbuff, buff, len);
	ADK_Machine.outSize = len;
	ADK_Machine.state = ADK_SEND_DATA;
	return USBH_OK;
}


