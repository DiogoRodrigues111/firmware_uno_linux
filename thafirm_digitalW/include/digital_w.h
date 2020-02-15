/* =======================================
 * digital_w.h
 *
 * Created: 2/7/2020 1:22:44 PM
 *  Author: Diogo Rodrigues Roessler
 * ====================================== */ 

#ifndef DIGITAL_W_H_
#define DIGITAL_W_H_

//----------------- Enums -------------------------------------------
enum _BOOLEAN {
	FALSE =0,
	TRUE  =1
} BOOL;
typedef enum _BOOLEAN BOOLEAN;

//----------------- Typedefs ----------------------------------------
typedef unsigned char UChar;
typedef unsigned int UInt;
typedef void VOID;
typedef double DOUBLE;
typedef UChar BYTE;
typedef UInt UINT;
typedef unsigned long ULONG;

//----------------- Defines ----------------------------------------

// Define uma entrada para um parametro
#define IN

// Input de parametros com valor especificado.
#define __In__				// Sem Implementa��o ainda

// Input & Output de parametros com valor especificado.
#define __In_out__			// Sem Implementa��o ainda

// Input & Output & OPTIONAL de parametros com valor especificado.
#define __In_Out_Op__		// Sem Implementa��o ainda

// Define um parametro Opcional, sem necessidade de aten��o
#define OPTIONAL			// Sem Implementa��o ainda

// Define Uma Sa�da para um parametro
#define OUT					// Valor default

// Output de parametros com valor especificado.
#define __Out__				// Sem Implementa��o ainda

// Define NULL como 0
#define NULL				0

// Define __FASTBACK como API
#define __FASTBACK		

// Define uma contante para trabalhar com Atmel Studio em Microsoft Windows
#define __WINDOWS_ATMEL_IDE	

// Define uma constante para trabalhar com API para LINUX OS
#define __LINUX__

// Define uma constante para trabalhar com rotinas Universais
#define __UNIVERSAL_PROCEDURE__	

// return keyword
#define RETURN				return

// La�o for modificado
#define FOR					for

// volatile keyword
#define VOLATILE			volatile

// Flags of hardware pins
//  + LED TX
//		+ Porque 0x15 ? � o TX LED de alguma forma est� como 0x15 e n�o GPIO1
#define _LED_TX_FLAGS		0x15

// LED L: � o LED normal por default
#define _LED_L_FLAGS		0x20

// Recebe a variavel
#define _volatile_flags(P)	(*(VOLATILE UINT *) (P))

// Obt�m o resultado da vari�vel TX mais o seu Flags
#define _added_volatile(P)	_volatile_flags((P) + _LED_L_FLAGS)

// Obt�m o resultado da vari�vel RX mais o seu Flags
#define _add_vol_for_tx(P)	_volatile_flags((P) + _LED_TX_FLAGS)

// Add o resultado da var��vel ao _DDR_ com o valor do pin em assembler
// Inicializa os componentes do LED. TX, L, RX(Se necess�rio).
#define _DDR_				_added_volatile(0x04)

// Add o resulatado da vari�vel ao _PORTB_ com o valor do pin em assembler
#define _PORTB_				_added_volatile(0x05)	// 23 funciona tbm

// Obt�m o resultado do TX LED
// \Declarada em _LED_TX_FLAGS.
// O valor tem que ser identico, caso contr�rio n�o funciona corretamente
#define _PORT_TX_			_add_vol_for_tx(_LED_TX_FLAGS)

// Cria uma vari�vel constante normal que recebe o valor da porta _DDR_ ja criado
#define ddr					_DDR_

// Cria uma vari�vel constante normal que recebe o valor da porta _PORTB_ ja criado
#define port				_PORTB_	// PORTB, PORT5

// Cria uma vari�vel constante normal que recebe o valor da porta _PORT_RX_ ja criada
#define PORT_TX				_PORT_TX_

// Cria uma definição para linux em Arduino Uno
/* Se estiver rodando em Windows então está constante recebe 0(ZERO) */
#define IS_LINUX_FOR_ARDUINO_UNO	1

// Cria uma definição para Windows em Arduino Uno
/* Como estamos rorando em Linux então a definição tem que ser 0 (ZERO),
   Para Windows.
   Caso fose Windows então seria necessário definir Windows como 1(UM).
   E então o trecho do código a seguir. */
#define IS_WINDOWS_FOR_ARDUINO_UNO	0
	
//----------------- Functions ----------------------------------------

// DigitalWrite() do Arduino - Re-Escrito
UINT __UNIVERSAL_PROCEDURE__ _digital_w(IN UINT pin,
						   				IN UINT mode);
// Delay milisegundos
// For Windows, com Atmel Studio 8 ou maior
BOOLEAN __WINDOWS_ATMEL_IDE delay_ms(IN ULONG _ms);

// Universal rotina, fora do Microsoft Windows IDE Atmel Studio 8
BOOLEAN __UNIVERSAL_PROCEDURE__ delay_ms_linux_(unsigned long _ms);

//----------------- Structs -------------------------------------------

// Struct p/ delay
typedef struct _DELAY {
	UINT sec;
} DELAY, *PDELAY;
typedef DELAY *PDELAY;

// Struct para alternar as luzes do LED como Movimenta��o de m�sica.
struct _HAVE_FUN_LED {
	UINT HardwareFlags;
};
typedef struct _HAVE_FUN_LED *PHAVE_FUN;

#endif /* DIGITAL_W_H_ */