/* ###################################################################
**     Filename    : main.c
**     Project     : CL1
**     Processor   : MC9S08QE128CLK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-01-17, 14:31, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bit1.h"
#include "TI1.h"
#include "AS1.h"
#include "AD1.h"
#include "Bit2.h"
#include "Bit3.h"
#include "Bit4.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
unsigned char estado = ESPERAR;
unsigned char CodError;
unsigned int  Medida1;
unsigned int  Medida2;
unsigned int  D1;
unsigned int  D2;
unsigned int  D3;
unsigned int  D4;
unsigned int Enviados = 2;		// Esta variable no aporta nada más sino el número de elementos del arreglo a enviar.

typedef union{
unsigned char u8[2];
unsigned int u16;
}AMPLITUD;

volatile AMPLITUD iADC;
unsigned char cTrama[5]={0xF2,0x00,0x00,0x00,0x00}; 	


void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
   PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
   for(;;){

   	switch (estado){
   		
   		case ESPERAR:
   			break;
   			
   		case MEDIR:
   			//CodError = AD1_Measure(TRUE);
   			//CodError = AD1_GetValue16(&Medida); //1111 1111 1111 0000
   			AD1_MeasureChan(TRUE, 0);
   			CodError =  AD1_GetChanValue16(0, &Medida1);
   			AD1_MeasureChan(TRUE, 1);
   			CodError =  AD1_GetChanValue16(1, &Medida2);
   			D1 = Bit1_GetVal();
   			D2 = Bit2_GetVal();
   			D3 = Bit3_GetVal();
   			D4 = Bit4_GetVal();
   			//Protocolo de comunicación
   			
   			cTrama[1]= (Medida1 >> 11) & (0x1F);
   			D1 = (D1 << 4); 
   			D2 = (D2 << 2);
   			cTrama[1]= cTrama[1] | D1 | D2;
   			cTrama[2]= (Medida1 >> 4) & (0x7F);
   			
   			cTrama[3]= (Medida2 >> 11) & (0x1F);
   			D3 = (D3 << 4); 
   			D4 = (D4 << 2);
   			cTrama[3]= cTrama[3] | D3 | D4;
   			cTrama[4]= (Medida2 >> 4) & (0x7F);
   
   			estado = ENVIAR;
   			break;
   	
   		case ENVIAR:
   			
   			CodError = AS1_SendBlock(cTrama,5,&Enviados); //El arreglo con la medición está en iADC.u8 (notar que es un apuntador)
   			estado = ESPERAR;
   			
   			break;
   			
   		default:
   			break;
   	
   	}
 }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
