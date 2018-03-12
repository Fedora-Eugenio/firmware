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
#include "Bit5.h"
#include "Bit6.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
unsigned char estado = ESPERAR;
unsigned char CodError;
unsigned int  Ultrasonido;
unsigned int  EjeX;
unsigned int  EjeY;
unsigned int  EjeZ;
unsigned int  Gatillo;
unsigned int  Foto1;
unsigned int  Foto2;
unsigned int  Foto3;
unsigned int  Foto4;
unsigned int  Foto5;
unsigned int Enviados = 2;		// Esta variable no aporta nada más sino el número de elementos del arreglo a enviar.

unsigned char cTrama[9]={0xF2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; 	


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
   			//Se reciben las señales de los sensores analógicos y se guardan en las variables correspondientes
   			AD1_MeasureChan(TRUE, 1);
   			   			CodError =  AD1_GetChanValue16(1, &EjeX);
   			AD1_MeasureChan(TRUE, 0);
   			CodError =  AD1_GetChanValue16(0, &Ultrasonido);
   			
   			AD1_MeasureChan(TRUE, 2);
   			CodError =  AD1_GetChanValue16(2, &EjeY);
   			AD1_MeasureChan(TRUE, 3);
   			CodError =  AD1_GetChanValue16(3, &EjeZ);
   			
   			//Se reciben las señales de los sensores digitales y se guardan en las variables correspondientes
   			Gatillo = Bit1_GetVal();
   			Foto1 = Bit2_GetVal();
   			Foto2 = Bit3_GetVal();
   			Foto3 = Bit4_GetVal();
   			Foto4 = Bit5_GetVal();
   			Foto5 = Bit6_GetVal();
   			
   			//Protocolo de comunicación
            //Canal 1
   			cTrama[1]= (Ultrasonido >> 11) & (0x1F);
   			Gatillo = (Gatillo << 4); 
   			Foto1 = (Foto1 << 2);
   			cTrama[1]= cTrama[1] | Gatillo | Foto1;
   			cTrama[2]= (Ultrasonido >> 4) & (0x7F);
   			
   			//Canal 2
   			cTrama[3]= (EjeX >> 11) & (0x1F);
   			Foto2 = (Foto2 << 4); 
   			Foto3 = (Foto3 << 2);
   			cTrama[3]= cTrama[3] | Foto2 | Foto3;
   			cTrama[4]= (EjeX >> 4) & (0x7F);
   			
   			//Canal 3
   			cTrama[5]= (EjeY >> 11) & (0x1F);
   			Foto4 = (Foto4 << 4); 
   			Foto5 = (Foto5 << 2);
   			cTrama[5]= cTrama[5] | Foto4 | Foto5;
   			cTrama[6]= (EjeY >> 4) & (0x7F);
   			
   			//Canal 4
   			cTrama[7]= (EjeZ >> 11) & (0x1F);
   			cTrama[8]= (EjeZ >> 4) & (0x7F);
   
   			estado = ENVIAR;
   			break;
   	
   		case ENVIAR:
   			
   			CodError = AS1_SendBlock(cTrama,9,&Enviados); 
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
