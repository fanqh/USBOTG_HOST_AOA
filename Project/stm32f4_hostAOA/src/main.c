/**
  ******************************************************************************
  * @file    main.c
  * @author  MCD Application Team
  * @version V2.1.0
  * @date    19-March-2012
  * @brief   USB host MSC class demo main file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"
#include "usbh_usr.h"
#include "usbh_msc_core.h"
#include "usbh_adk_core.h"
#include "usart.h"


/** @addtogroup USBH_USER
* @{
*/

/** @defgroup USBH_USR_MAIN
* @brief This file is the MSC demo main file
* @{
*/ 

/** @defgroup USBH_USR_MAIN_Private_TypesDefinitions
* @{
*/ 
/**
* @}
*/ 

/** @defgroup USBH_USR_MAIN_Private_Defines
* @{
*/ 
/**
* @}
*/ 


/** @defgroup USBH_USR_MAIN_Private_Macros
* @{
*/ 
/**
* @}
*/ 


/** @defgroup USBH_USR_MAIN_Private_Variables
* @{
*/
#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */
__ALIGN_BEGIN USB_OTG_CORE_HANDLE      USB_OTG_Core __ALIGN_END;

#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */
__ALIGN_BEGIN USBH_HOST                USB_Host __ALIGN_END;
/**
* @}
*/ 


/** @defgroup USBH_USR_MAIN_Private_FunctionPrototypes
* @{
*/ 
/**
* @}
*/ 


/** @defgroup USBH_USR_MAIN_Private_Functions
* @{
*/ 

/**
* @brief  Main routine for MSC class application
* @param  None
* @retval int
*/

static uint32_t test = 0;

int main(void)
{
  __IO uint32_t i = 0;

    uint8_t msg[64];
    uint16_t len;
  
  /*!< At this stage the microcontroller clock setting is already configured, 
  this is done through SystemInit() function which is called from startup
  file (startup_stm32fxxx_xx.s) before to branch to application main.
  To reconfigure the default setting of SystemInit() function, refer to
  system_stm32fxxx.c file
  */  
  
  /* Init Host Library */

  USART_Configuration();
  


  USBH_Init(&USB_OTG_Core, 
#ifdef USE_USB_OTG_FS  
            USB_OTG_FS_CORE_ID,
#else 
            USB_OTG_HS_CORE_ID,
#endif 
            &USB_Host,
            &USBH_ADK_cb, 
            &USR_cb);

  /* Init ADK Library */
 USBH_ADK_Init("actnova", "HelloADK", "HelloADK for for STM32F4", "1.0", "www.actnova.com",  "1234567");
//USBH_ADK_Init("ammlab.org", "HelloADK", "HelloADK for GR-SAKURA for STM32F4", "1.0", "https://play.google.com/store/apps/details?id=org.ammlab.android.helloadk",  "1234567");		
//   USART_Configuration();
  while (1)
  {
 
    /* Host Task handler */
   USBH_Process(&USB_OTG_Core, &USB_Host);

    /* Accessory Mode enabled */
   if( USBH_ADK_getStatus() == ADK_IDLE) 
   {

	    len = USBH_ADK_read(&USB_OTG_Core, msg, sizeof(msg));
		if(len>0)
		{
			USBH_ADK_ClearCount(&USB_OTG_Core);
			for(i = 0; i< len; i++)
			{
				printf("%X ",msg[i]);
	
			}
			printf("\r\n");
		}
  }
//  USB_OTG_BSP_mDelay(10);

 //  USBH_ADK_write(&USB_OTG_Core, "something ",1);   
   
   test++;
   if(test >= 10000)
   {
   		test = 0;
   		//printf("device is working\r\n");
   } 
  }
}


#ifdef USE_FULL_ASSERT
/**
* @brief  assert_failed
*         Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  File: pointer to the source file name
* @param  Line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  
  /* Infinite loop */
  while (1)
  {}
}
#endif




void reset_usb(void)
{


  USBH_Init(&USB_OTG_Core, 
#ifdef USE_USB_OTG_FS  
            USB_OTG_FS_CORE_ID,
#else 
            USB_OTG_HS_CORE_ID,
#endif 
            &USB_Host,
            &USBH_ADK_cb, 
            &USR_cb);

	USBH_ADK_Init("actnova", "HelloADK", "HelloADK for for STM32F4", "1.0", "www.actnova.com",  "1234567");
}

/**
* @}
*/ 

/**
* @}
*/ 

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
