#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "msj_es.h"
#include "funciones.h"
#include "estados.h"
#include "menus_func.h"

int main (void)
{
	int muestreo, precision, menu, funcion, opcion_fin_muestreo
	float ti, tf, delta_t;
	E_ESTADO estado = ST_MAIN_MENU;

	while(estado){
		switch (estado){

			case ST_EXIT_FAILURE:
				return EXIT_FAILURE;

			case ST_MAIN_MENU:
				imprimir_menu_principal();
				if (scanf("%d",&menu))
				{
					fprintf(stderr, "%s", MSG_ERROR);
					estado = ST_EXIT_FAILURE;
				}else if (menu == OPTION_EXIT)
				{
					estado = ST_EXIT
				}else{
					estado = ST_ASK_PARAM;
				}
				break;

			case ST_ASK_PARAM:
				pedir_tiempo_inicial(&ti);
				pedir_tiempo_final(&ti,&tf);
				pedir_muestreo(&muestreo);
				delta_t = (tf - ti)/muestreo;
				pedir_precision(&precision);
				printf ("%s\n \n %f \n %f \n %d \n %d \n \n %s", MSG_CONFIR1, ti, tf, muestreo, precision, MSG_CONFIR2);	
				scanf ("%d", &confirmacion);
				if (confirmacion)
				{
					estado = ST_FUNC_MENU
				}
				break;

			case ST_FUNC_MENU:
				imprimir_menu_funciones();
				scanf ("%d", &funcion);
				switch (funcion){
					case OPTION_EXIT:
						estado = ST_MAIN_MENU;
						break;
					case OPTION_FST:
						senoidal (muestreo, precision, ti, delta_t);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					case OPTION_SND:
						muestrear_log_10 (&ti, & tf, &delta_t, muestreo, precision);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					case OPTION_TRD:
						muestrear_log_lineal(&ti, &tf, &delta_t, int muestreo, int precision);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					case OPTION_4TH:
						expon (muestreo, precision, ti, delta_t);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					case OPTION_5TH:
						escalon (muestreo, precision, ti, delta_t);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					case OPTION_6TH:
						mrua (muestreo, precision, ti, delta_t);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					case OPTION_7TH:
						parh (muestreo, precision, ti, delta_t);
						estado = ST_SMPLE_ENDING_MENU;
						break;
					default: 	
						printf("%s\n", MSG_NUEVO_INGRESO);			
				}
				break;

			case ST_SMPLE_ENDING_MENU:
				imprimir_menu_finalizado_muestreo();
				scanf("%d", &opcion_fin_muestreo);
				switch(opcion_fin_muestreo){
					case OPTION_EXIT:
						estado = ST_EXIT;
						break;
					case OPTION_FST:
						estado = ST_ASK_PARAM;
						break;
					case OPTION_SND:
						estado = ST_FUNC_MENU;
						break;
					default: printf("%s\n", MSG_NUEVO_INGRESO);
				}
		}
	}
	return EXIT_SUCCESS;
