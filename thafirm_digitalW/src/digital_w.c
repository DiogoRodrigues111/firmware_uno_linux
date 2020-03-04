/* =======================================
 * digital_w.c
 *
 * Created: 2/7/2020 1:22:20 PM
 *  Author: Diogo Rodrigues Roessler
 * ======================================= */
#include <stdlib.h>
#include "digital_w.h"

/* Rotina Re-escrita do Core do Arduino Board 
   Equivale ao digitalWrite() */
UINT __UNIVERSAL_PROCEDURE__ _digital_w (IN UINT pin, IN UINT mode)
/*
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
	\RETURN:
		+ O Pino � igual ao ddr or port para acionar a fu��o � necessario,
		+ passar a port ou a porta correspondente.
	\COMMENT:
		+ Porque o mode � menor ou igual a unsigned char ou 0xFF (255) ?
			+ A fun��o chama o mode por ultimo. Ent�o caso o 0xFF n�o seja 0x00
			+ ent�o ele � acionado por como TRUE (1 POSITIVO) ou FALSE (0 NEGATIVO)
	\RETURN:
		+ As iniciais das portas como port_b e ddr_b logo j� s�o passadas por,
			+ pin e mode. Para ter certeza de que os valores ser�o os mesmo.
		+ Caso se deseja utilizar outra porta, o que se deve fazer � definir,
			+ uma nova #define com os respectivos valores. E ent�o � chamada,
			+ a fun��o inv�s de port_b no valor do pin, � possivel passar,
			+ por exemplo: port_c, port_a, etc...
--------------------------------------------------------------------------------
*/
{
	ddr		= pin;
	port	= mode;
	PORT_TX = mode;
	
	if(pin == ddr) {
		RETURN TRUE;
	} else {
		RETURN FALSE;
	}
	
	if(mode == 0xFF) {
		RETURN TRUE;
	} else {
		RETURN FALSE;
	}

	return FALSE;
}

/* Delay para operar sobre a plataforma Microsoft Windows Em Atmel Studio 8 */
BOOLEAN __WINDOWS_ATMEL_IDE delay_ms (IN ULONG _ms)
/*
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
 + \RETURN:
    + Funciona somente em Microsoft Windows On Atmel Studio 8
--------------------------------------------------------------------------------
 + \COMMENT:
 	+ Porque a convers�o de _delay->sec est� recebendo em minutos ?
		+ � porque 60 Segundos tem Um minuto ent�o, Um minuto � igual a 1 segundo.

 	+ Porque _ms = ((volatile unsigned int) _delay->sec / 1000) recebe Um segundo
		+ Ele é dividido por Um milisegundos que seguinifica Um segundo, que � o
	   		+ que queremos Um segundo e nada mais.
--------------------------------------------------------------------------------
*/
{	/* Code for Microsoft Windows IDE Atmel Studio 8 */

	PDELAY _delay = malloc(sizeof(PDELAY));
	UINT i,j;
	
	_delay->sec = 60000;
	_ms = ((VOLATILE UINT) _delay->sec / 1000);
	
	for(i=0; i < _ms; i++)
		for(j=0; j < _delay->sec; j++);

	free(_delay);

	RETURN FALSE;
}

/* Delay para operar em linux, ou pela IDE Visual Studio Code */
BOOLEAN __UNIVERSAL_PROCEDURE__ delay_ms_linux_(unsigned long _ms)
/* 
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
	\COMMENT:
		+ Codigo universal para delay em milisegundos.
		+ Serve tanto para Linux e IDEs como para Windows e IDEs.
--------------------------------------------------------------------------------
	\RETURN:
		+  Testado em Linux, Microsoft Visual Studio Code com o PIO (PlatformIO)
--------------------------------------------------------------------------------
*/
{
	PDELAY _delay;
	unsigned int i,j, total;

	_delay = malloc(sizeof(PDELAY));
	_delay->sec = 60000;
	total = ((volatile unsigned long int)_delay->sec / _ms);

	for(i=0; i < _ms; i++)
		for(j=0; j < total /6; j++) {
			total++;
		}

	free(_delay);
	
	return TRUE;
}

// Universal rotina para imprimir os dados escritos em formato ANSICII
BOOLEAN __UNIVERSAL_PROCEDURE__ Printf_s ( IN WCHAR _menssage )
/* 
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
	\COMMENT:
		+ Codigo universal para imprimir uma menssagem.
		+ Serve tanto para Linux e IDEs como para Windows e IDEs.
--------------------------------------------------------------------------------
	\RETURN:
		+  Testado em Linux, Microsoft Visual Studio Code com o PIO (PlatformIO)
--------------------------------------------------------------------------------
*/
{
	return FALSE;
}

// Universal rotina para obter em numeros o tamanho de uma string
INT __UNIVERSAL_PROCEDURE__ Strlen_s ( IN SIZE _len )
/* 
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
	\COMMENT:
		+ Codigo universal para obter o tamanho de uma WCHAR string.
		+ Serve tanto para Linux e IDEs como para Windows e IDEs.
--------------------------------------------------------------------------------
	\RETURN:
		+  Testado em Linux, Microsoft Visual Studio Code com o PIO (PlatformIO)
--------------------------------------------------------------------------------
*/
{
	return 0;
}

/* Array variaveis maneiras de fazer isto de várias maneiras */
static unsigned int ObtemValue[IS_LINUX_FOR_ARDUINO_UNO] = {
	[0 ... IS_LINUX_FOR_ARDUINO_UNO -1] = !IS_WINDOWS_FOR_ARDUINO_UNO
};

/* Imiita as funcionalidades real do kernel, mais para que serve ? */
static const struct _STRING_FORMAT StringFormat = {
	.string 	= "DIOGO",
	.string_len = 5
};

/* Imiita as funcionalidades real do kernel, mais para que serve ? */
VOID __UNIVERSAL_PROCEDURE__ ImitaKernel()
/* 
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
	\COMMENT
		Tenta mesclar está função em um arquivo C++ para a obtenção de uma
			string
	\RETURN
		Está função serve somente em C++, sem exeção.
		Pelo fato de que printf do C não funciona e não tem Serial Port em C.
--------------------------------------------------------------------------------
*/
{

}

/* Imiita as funcionalidades real do kernel para LED, mais para que serve ? */
static const struct _HAVE_FUN_LED HaveFunWithLed = {
	.HardwareFlags = 0xFF
};

/* Imiita as funcionalidades real do kernel para LED, mais para que serve ? */
VOID __UNIVERSAL_PROCEDURE__ ImitaKernelForLed()
/*
--------------------------------------------------------------------------------
\COMMENT: Perguntas e Respostas.
\RETURN: Funcionamento do sistema 
--------------------------------------------------------------------------------
	\COMMENT
		Tenta mesclar do kernel com o Led.
	\RETURN
		Função do Led.
--------------------------------------------------------------------------------
*/
{

}