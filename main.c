/*
 * File:   main.c
 * Author: Sergio
 *
 * Created on 2 de septiembre de 2014, 19:55
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ArrayMAX_Size 20

void bitodeci();
void bitohexa();
void bitoocta();
void decitobi();
void decitohexa();
void decitoocta();
void hexatobi();
void hexatodeci();
void hexatoocta();
void octatobi();
void octatodeci();
void octatohexa();

/*
 * Convierte un numero en una base dada
 * a sistema binario, octal, decimal o hexadecimal
 */
int main(int argc, char** argv) {
	int respuesta;
	char opcion;
	printf("Que desea convertir?\nEscriba:\n");
	do {
		printf("1     Para convertir de       Binario -> Octal\n"
						"2     Para convertir de       Binario -> Decimal\n"
						"3     Para convertir de       Binario -> Hexadecimal\n"
						"4     Para convertir de         Octal -> Binario\n"
						"5     Para convertir de         Octal -> Decimal\n"
						"6     Para convertir de         Octal -> Hexadecimal\n"
						"7     Para convertir de       Decimal -> Binario\n"
						"8     Para convertir de       Decimal -> Octal\n"
						"9     Para convertir de       Decimal -> Hexadecimal\n"
						"10    Para convertir de   Hexadecimal -> Binario\n"
						"11    Para convertir de   Hexadecimal -> Octal\n"
						"12    Para convertir de   Hexadecimal -> Decimal\n"
						"0     SALIR\n");
		scanf("%d", &respuesta);

		switch (respuesta) {
			case 1:
				bitoocta();
				break;
			case 2:
				bitodeci();
				break;
			case 3:
				bitohexa();
				break;
			case 4:
				octatobi();
				break;
			case 5:
				octatodeci();
				break;
			case 6:
				octatohexa();
				break;
			case 7:
				decitobi();
				break;
			case 8:
				decitoocta();
				break;
			case 9:
				decitohexa();
				break;
			case 10:
				hexatobi();
				break;
			case 11:
				hexatoocta();
				break;
			case 12:
				hexatodeci();
				break;
			case 0:
				opcion = 'n';
				break;
			default:
				break;
		}
		if (opcion != 110 && opcion != 78) {
			printf("\n\nDesea hacer otra operacion?\nS  ->  Si\nN  ->  Salir\n");
			scanf(" %c", &opcion);
		}
	} while (opcion != 110 && opcion != 78);
	return(EXIT_SUCCESS);
}

/*
 * CONVIERTE DE BINARIO A OCTAL
 */
void bitoocta() {
	int n, k = 1, resultado = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero binario:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema binario:\n");
	int binario[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf("%d", &binario[i]);
		// Manda error algun numero dado es mayor que 1 o menor que 0 y vuleve a pedir los numeros
		while (binario[i] < '0' || '1' < binario[i]) {//     && !isdigit(binario[i])
			printf("Escribe unicamente 1's y 0's.\nEscribe el digito de la posicion %d:\n", i);
			scanf("%d", &binario[i]);
		}
	}
	// Hace la operacion para cada digito del numero
	int m = n / 3;
	if (n % 3 != 0)
		m++;
	int octa[ArrayMAX_Size];
	for (int i = n - 1; i >= 0; i--) {
		resultado = resultado + (binario[i] * pow(2, potencia));
		if (n % 3 != 0 && i == 0)
			octa[m - k] = resultado;
		// Asigna el valor de la suma de los grupos de 3 del numero binario al numero octal
		if ((potencia + 1) % 3 == 0) {
			octa[m - k] = resultado;
			k++;
			resultado = 0;
			potencia = 0;
		} else
			potencia++;
	}
	printf("El resultado es:\n ");
	for (int i = 0; i < m; i++)
		printf("%d ", octa[i]);
}

/*
 * CONVIERTE DE BINARIO A DECIMAL
 */
void bitodeci() {
	int n, decimal = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero binario:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema binario:\n");
	int binario[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf("%d", &binario[i]);
		// Manda error algun numero dado es mayor que 1 o menor que 0 y vuleve a pedir los numeros
		while (binario[i] < '0' || '1' < binario[i]) {//     && !isdigit(binario[i])
			printf("Escribe unicamente 1's y 0's.\nEscribe el digito de la posicion %d:\n", i);
			scanf("%d", &binario[i]);
		}
	}
	// Hace la operacion para cada digito del numero
	for (int i = n - 1; i >= 0; i--) {
		decimal = decimal + (binario[i] * pow(2, potencia));
		potencia++;
	}
	printf("El resultado es:\n ");
	printf("%d", decimal);
}

/*
 * CONVIERTE DE BINARIO A HEXADECIMAL
 */
void bitohexa() {
	int n, resultado = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero binario:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema binario:\n");
	int binario[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf("%d", &binario[i]);
		// Manda error algun numero dado es mayor que 1 o menor que 0 y vuleve a pedir los numeros
		while (binario[i] < '0' || '1' < binario[i]) {//     && !isdigit(binario[i])
			printf("Escribe unicamente 1's y 0's.\nEscribe el digito de la posicion %d:\n", i);
			scanf("%d", &binario[i]);
		}
	}
	// Hace la operacion para cada digito del numero
	int m = n / 4, k = 1;
	if (n % 4 != 0)
		m = m + 1;
	int hexa[ArrayMAX_Size];
	for (int i = n - 1; i >= 0; i--) {
		resultado = resultado + (binario[i] * pow(2, potencia));
		if ((n % 4 != 0) && (i == 0))
			hexa[m - k] = resultado;
		// Asigna el valor de la suma de los grupos de 3 del numero binario al numero hexadecimal
		if ((potencia + 1) % 4 == 0) {
			hexa[m - k] = resultado;
			k++;
			resultado = 0;
			potencia = 0;
		} else
			potencia++;
	}
	printf("El resultado es:\n ");
	for (int i = 0; i < m; i++) {
		if (hexa[i] > 9) {
			hexa[i] = hexa[i] + 55;
			printf("%c ", hexa[i]);
		} else
			printf("%d ", hexa[i]);
	}
}

/*
 * CONVIERTE DE OCTAL A BINARIO
 */
void octatobi() {
	int n;
	printf("Escribe la cantidad de digitos del numero octal:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema octal:\n");
	/*
		int oct;
		scanf("%o", &oct); // usar: %o para numeros octales o %x para hexadecimales
		printf("%x\n", oct);
	 */
	int octal[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf("%d", &octal[i]);
		// Manda error algun numero dado es mayor que 7 o menor que 0 y vuleve a pedir el numero
		while (octal[i] < 0 || 7 < octal[i]) {
			printf("Escribe unicamente digitos del 0 al 7\nEscribe el digito de la posicion %d:\n", i);
			scanf("%d", &octal[i]);
		}
	}
	// Hace la operacion para cada digito del numero
	int m = n * 3, k = 0;
	int binario[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		for (int j = k + 2; j >= k; j--) {
			binario[j] = octal[i] % 2;
			octal[i] = octal[i] / 2;
		}
		k = k + 3;
	}
	printf("El resultado es:\n ");
	for (int i = 0; i < m; i++)
		printf("%d ", binario[i]);
}

/*
 * CONVIERTE DE OCTAL A DECIMAL
 */
void octatodeci() {
	int n, decimal = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero octal:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema octal:\n");
	int octal[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf("%d", &octal[i]);
		// Manda error algun numero dado es mayor que 7 o menor que 0 y vuleve a pedir el numero
		while (octal[i] < 0 || 7 < octal[i]) {
			printf("Escribe unicamente digitos del 0 al 7\nEscribe el digito de la posicion %d:\n", i);
			scanf("%d", &octal[i]);
		}
	}
	// Hace la operacion para cada digito del numero
	for (int i = n - 1; i >= 0; i--) {
		decimal = decimal + (octal[i] * pow(8, potencia));
		potencia++;
	}
	printf("El resultado es:\n %d", decimal);
}

/*
CONVIERTE DE OCTAL A HEXADECIMAL
 */
void octatohexa() {
	int n, decimal = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero octal:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema octal:\n");
	int octal[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf("%d", &octal[i]);
		// Manda error algun numero dado es mayor que 7 o menor que 0 y vuleve a pedir el numero
		while (octal[i] < 0 || 7 < octal[i]) {
			printf("Escribe unicamente digitos del 0 al 7\nEscribe el digito de la posicion %d:\n", i);
			scanf("%d", &octal[i]);
		}
	}
	// Hace la operacion para cada digito del numero
	for (int i = n - 1; i >= 0; i--) {
		decimal = decimal + (octal[i] * pow(8, potencia));
		potencia++;
	}
	// Define la longitud del número hexadecimal
	if (decimal > 0 && decimal <= 255)
		n = 2;
	else if (decimal > 255 && decimal <= 65535)
		n = 4;
	else if (decimal > 65535 && decimal <= 16777215)
		n = 6;
	else if (decimal > 255 && decimal <= 1023)
		n = 8;
	else
		n = 10;
	// Hace la conversión
	int hexa[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		hexa[i] = decimal % 16;
		decimal = decimal / 16;
	}
	printf("El resultado es:\n ");
	for (int i = n - 1; i >= 0; i--) {
		if (hexa[i] > 9) {
			hexa[i] = hexa[i] + 55;
			printf("%c ", hexa[i]);
		} else
			printf("%d ", hexa[i]);
	}
}

/*
 * CONVIERTE DE DECIMAL A BINARIO
 */
void decitobi() {
	int decimal, n;
	printf("Escribe el numero en sistema decimal:\n");
	scanf("%d", &decimal);
	// Revisa errores
	/*
		while (isalpha(decimal) || ispunct(decimal)) {
			printf("Escribe unicamente numeros enteros.\n");
			scanf("%d", &decimal);
		}
	 */
	// Define la longitud del número binario
	if (0 < decimal && decimal <= 15)
		n = 4;
	else if (15 < decimal && decimal <= 63)
		n = 6;
	else if (63 < decimal && decimal <= 255)
		n = 8;
	else if (255 < decimal && decimal <= 1023)
		n = 10;
	else
		n = 20;
	// Hace la conversión
	int binario[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		binario[i] = decimal % 2;
		decimal = decimal / 2;
	}
	printf("El resultado es:\n ");
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", binario[i]);
}

/*
 * CONVIERTE DE DECIMAL A OCTAL
 */
void decitoocta() {
	int decimal, n;
	printf("Escribe el numero en sistema decimal:\n");
	scanf("%d", &decimal);
	// Revisa errores
	/*
		while (isalpha(decimal) || ispunct(decimal)) {
			printf("Escribe unicamente numeros enteros.\n");
			scanf("%d", &decimal);
		}
	 */
	// Define la longitud del número octal
	if (0 < decimal && decimal <= 63)
		n = 2;
	else if (63 < decimal && decimal <= 4095)
		n = 4;
	else if (4095 < decimal && decimal <= 262143)
		n = 6;
	else if (262143 < decimal && decimal <= 16777215)
		n = 8;
	else
		n = 10;
	// Hace la conversión
	int octal[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		octal[i] = decimal % 8;
		decimal = decimal / 8;
	}
	printf("El resultado es:\n ");
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", octal[i]);
}

/*
 * CONVIERTE DE DECIMAL A HEXADECIMAL
 */
void decitohexa() {
	int decimal, n;
	printf("Escribe el numero en sistema decimal:\n");
	scanf("%d", &decimal);
	// Revisa errores
	/*
		while (isalpha(decimal) || ispunct(decimal)) {
			printf("Escribe unicamente numeros enteros.\n");
			scanf("%d", &decimal);
		}
	 */
	// Define la longitud del número hexadecimal
	if (0 < decimal && decimal <= 255)
		n = 2;
	else if (255 < decimal && decimal <= 65535)
		n = 4;
	else if (65535 < decimal && decimal <= 16777215)
		n = 6;
	else if (16777215 < decimal)
		n = 8;
	else
		n = 10;
	// Hace la conversión
	int hexa[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		hexa[i] = decimal % 16;
		decimal = decimal / 16;
	}
	printf("El resultado es:\n ");
	for (int i = n - 1; i >= 0; i--) {
		if (hexa[i] > 9) {
			hexa[i] = hexa[i] + 55;
			printf("%c ", hexa[i]);
		} else
			printf("%d ", hexa[i]);
	}
}

/*
 * CONVIERTE DE HEXADECIMAL A BINARIO
 */
void hexatobi() {
	int n;
	printf("Escribe la cantidad de digitos del numero hexadecimal:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema hexadecimal:\n");
	char hexa[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf(" %c", &hexa[i]);
		// Manda error algun numero dado es mayor que 1 o menor que 0 y vuleve a pedir los numeros
		while (!isxdigit(hexa[i])) {
			printf("Escribe unicamente digitos de 0 a f.\nEscribe el digito de la posicion %d:\n", i);
			scanf(" %c", &hexa[i]);
		}

		if (isalpha(hexa[i])) {//if (isalpha()) {switch} else {}      int numero = hexa[i]
			if (isupper(hexa[i]))
				hexa[i] = hexa[i] - 55;
			else if (islower(hexa[i]))
				hexa[i] = hexa[i] - 87;
		} else
			hexa[i] = hexa[i] - 48;
	}
	// Hace la operacion para cada digito del numero
	int m = n * 4, k = 0;
	int binario[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		for (int j = k + 3; j >= k; j--) {
			binario[j] = hexa[i] % 2;
			hexa[i] = hexa[i] / 2;
		}
		k = k + 4;
	}
	printf("El resultado es:\n ");
	for (int i = 0; i < m; i++)
		printf("%d ", binario[i]);
}

/*
CONVIERTE DE HEXADECIMAL A OCTAL
 */
void hexatoocta() {
	int n, m, decimal = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero hexadecimal:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema hexadecimal:\n");
	char hexa[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf(" %c", &hexa[i]);
		// Manda error algun numero dado es mayor que 1 o menor que 0 y vuleve a pedir los numeros
		while (!isxdigit(hexa[i])) {
			printf("Escribe unicamente digitos de 0 a f.\nEscribe el digito de la posicion %d:\n", i);
			scanf(" %c", &hexa[i]);
		}

		if (isalpha(hexa[i])) {//if (isalpha()) {switch} else {}      int numero = hexa[i]
			if (isupper(hexa[i]))
				hexa[i] = hexa[i] - 55;
			else if (islower(hexa[i]))
				hexa[i] = hexa[i] - 87;
		} else
			hexa[i] = hexa[i] - 48;
	}
	// Hace la operacion para cada digito del numero
	for (int i = n - 1; i >= 0; i--) {
		decimal = decimal + (hexa[i] * pow(16, potencia));
		potencia++;
	}
	// Define la longitud del número octal
	if (0 < decimal && decimal <= 63)
		m = 2;
	else if (63 < decimal && decimal <= 4095)
		m = 4;
	else if (4095 < decimal && decimal <= 262143)
		m = 6;
	else if (262143 < decimal && decimal <= 16777215)
		m = 8;
	else
		m = 10;
	// Hace la conversión
	int octal[ArrayMAX_Size];
	for (int i = 0; i < m; i++) {
		octal[i] = decimal % 8;
		decimal = decimal / 8;
	}
	printf("El resultado es:\n ");
	for (int i = m - 1; i >= 0; i--)
		printf("%d ", octal[i]);
}

/*
 * CONVIERTE DE HEXADECIMAL A DECIMAL
 */
void hexatodeci() {
	int n, decimal = 0, potencia = 0;
	printf("Escribe la cantidad de digitos del numero hexadecimal:\n");
	scanf("%d", &n);
	printf("Escribe el numero en sistema hexadecimal:\n");
	char hexa[ArrayMAX_Size];
	for (int i = 0; i < n; i++) {
		scanf(" %c", &hexa[i]);
		// Manda error algun numero dado es mayor que 1 o menor que 0 y vuleve a pedir los numeros
		while (!isxdigit(hexa[i])) {
			printf("Escribe unicamente digitos de 0 a f.\nEscribe el digito de la posicion %d:\n", i);
			scanf(" %c", &hexa[i]);
		}

		if (isalpha(hexa[i])) {//if (isalpha()) {switch} else {}      int numero = hexa[i]
			if (isupper(hexa[i]))
				hexa[i] = hexa[i] - 55;
			else if (islower(hexa[i]))
				hexa[i] = hexa[i] - 87;
		} else
			hexa[i] = hexa[i] - 48;
	}
	// Hace la operacion para cada digito del numero
	for (int i = n - 1; i >= 0; i--) {
		decimal = decimal + (hexa[i] * pow(16, potencia));
		potencia++;
	}
	printf("El resultado es:\n %d", decimal);
}