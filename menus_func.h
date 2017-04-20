#ifndef MENUS_FUNC__H
#define MENUS_FUNC__H

void imprimir_menu_principal(void)
void pedir_tiempo_inicial(float * ti)
void pedir_tiempo_final(float* ti, float* tf)
void pedir_muestreo(int* muestreo)
void pedir_precision(int* precision);
void imprimir_menu_funciones();
void muestrear_log_10 (float* ti, float* tf, int muestreo, int precision);
void muestrear_log_lineal(float* ti, float* tf, float* delta_t, int muestreo, int precision)
void imprimir_menu_finalizado_muestreo(void)



void imprimir_menu_principal(void){
	printf("%s %s\n", SYMBOL_FST_OPTION, MSG_MAIN_MANU_FST_OPTION);
	printf("%s %s\n", SYMBOL_EXIT_MENU_OPTION, MSG_MAIN_MANU_EXIT_OPTION);
}

void pedir_tiempo_inicial(float * ti){
	printf("%s\n", MSG_PARAM_TI);								
	scanf("%f", &ti);
}

void pedir_tiempo_final(float* ti, float* tf){
	do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);
			scanf ("%f", tf);
		}while (*tf<=*ti);
}
void pedir_muestreo(int* muestreo){
	do
	{
		printf("%s\n", MSG_PARAM_MUEST);		
		scanf("%d", muestreo);
	}while (*muestreo <= MIN_CANT_SAMPLE_VALUE);
}

void pedir_precision(int* precision){
	do
	{
		printf("%s\n", MSG_PARAM_PRES);				
		scanf("%d", &precision);
	}
	while (precision <= MIN_PRECIS_VALUE);
}
void imprimir_menu_funciones(void){
	printf("%s\n", MSG_ASK_OPTION_FUNC_MENU);
	printf("%s %s\n", SYMBOL_FST_OPTION, MSG_FUNC_MENU_FST_OPTION );
	printf("%s %s\n", SYMBOL_SND_OPTION, MSG_FUNC_MENU_SND_OPTION);
	printf("%s %s\n", SYMBOL_TRD_OPTION, MSG_FUNC_MENU_TRD_OPTION);
	printf("%s %s\n", SYMBOL_4TH_OPTION, MSG_FUNC_MENU_4TH_OPTION);
	printf("%s %s\n", SYMBOL_5TH_OPTION. MSG_FUNC_MENU_5TH_OPTION);
	printf("%s %s\n", SYMBOL_6TH_OPTION, MSG_FUNC_MENU_6TH_OPTION);
	printf("%s %s\n", SYMBOL_7TH_OPTION, MSG_FUNC_MENU_7TH_OPTION);
	printf("%s %s\n", SYMBOL_EXIT_MENU_OPTION, MSG_FUNC_MENU_EXIT_OPTION);
}




void muestrear_log_10 (float* ti, float* tf, float* delta_t, int muestreo, int precision){
	while (*ti <= 0)
	{
		printf ("%s\n", MSG_TIEMPO_INICIAL_INVALIDO);	
		scanf ("%f", ti);
		do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);		
			scanf ("%f", tf);
		}
		while (*tf <= *ti);

		*delta_t = (*tf - *ti)/muestreo;
	}
	log_10 (muestreo, precision, *ti, delta_t);
} 


void muestrear_log_lineal(float* ti, float* tf, float* delta_t, int muestreo, int precision){
	while (*ti <= 0)
	{
		printf ("%s\n", MSG_TIEMPO_INICIAL_INVALIDO);				
		scanf ("%f", ti);
		do
		{
			printf ("%s\n", MSG_TIEMPO_FINAL_INVALID);		
			scanf ("%f", tf);
		}
		while (*tf <= *ti);

		*delta_t = (*tf - *ti)/muestreo;
	};

		loglineal (muestreo, precision, *ti, *delta_t);
}

void imprimir_menu_finalizado_muestreo(void){
	printf("\n \n \n %s\n", MSG_SAMPLE_ENDING);
	printf("%s %s\n", SYMBOL_FST_OPTION, MSG_SAMPLE_ENDING_FST_OPTION);
	printf("%s %s\n", SYMBOL_SND_OPTION, MSG_SAMPLE_ENDING_SND_OPTION);
	printf("%s %s\n", SYMBOL_EXIT_MENU_OPTION, MSG_SAMPLE_ENDING_EXIT_OPTION);
}


#endif