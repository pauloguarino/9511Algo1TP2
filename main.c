#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "msj_es.h"
#include "funciones.h"

int main (void)
{
	int muestreo, precision, menu, funcion, reasignar = 1, confirmacion = 0, seguir = 1;
	float ti, tf, delta_t;

	while (1)
	{
		printf ("%s",MSG_MENU_PRINCIPAL);							
		if (scanf ("%d", &menu) != 1 )
		{
			fprintf(stderr, "%s", MSG_ERROR);
			return EXIT_FAILURE;
		};

		if (menu == 0) break;
		while (1)
		{
			switch (reasignar)
			{
				case 0: printf("%s", MSG_SEGUIR);
						scanf("%d", &seguir);

						if(seguir == 0) return EXIT_SUCCESS;

						printf("%s %f \n %f \n %d \n %d \n \n %s", MSG_REASIG1, ti, tf, muestreo, precision, MSG_REASIG2);
						scanf("%d", &confirmacion);

						if(confirmacion == 1) break;

				case 1:	do
						{
							printf("%s", MSG_PARAM_TI);								
							scanf("%f", &ti);

							do
								{
									printf ("%s", MSG_TIEMPO_FINAL_INVALID);
									scanf ("%f", &tf);
								}
							while (tf<=ti);

							do
								{
									printf("%s", MSG_PARAM_MUEST);		
									scanf("%d", &muestreo);
								}
							while (muestreo <= 0);

							delta_t = (tf - ti)/muestreo;

							do
								{
									printf("%s", MSG_PARAM_PRES);				
									scanf("%d", &precision);
								}
							while (precision <= 0);

							printf ("%s \n %f \n %f \n %d \n %d \n \n %s", MSG_CONFIR1, ti, tf, muestreo, precision, MSG_CONFIR2);	
							scanf ("%d", &confirmacion);

						}
						while (confirmacion != 1);

				default: reasignar = 1;
			};

			printf("%s", MSG_FUNCIONES);	
			scanf ("%d", &funcion);

			if (funcion==0) break;

			switch (funcion)
			{
				case 1: senoidal (muestreo, precision, ti, delta_t);
						break;

				case 2: while (ti <= 0)
						{
							printf ("%s", MSG_TIEMPO_INICIAL_INVALIDO);	
							scanf ("%f", &ti);
							do
								{
									printf ("%s", MSG_TIEMPO_FINAL_INVALID);		
									scanf ("%f", &tf);
								}
							while (tf <= ti);

						delta_t = (tf - ti)/muestreo;
						};

						log_10 (muestreo, precision, ti, delta_t);
						break;

				case 3: while (ti <= 0)
						{
							printf ("%s", MSG_TIEMPO_INICIAL_INVALIDO);				
							scanf ("%f", &ti);
							do
								{
									printf ("%s", MSG_TIEMPO_FINAL_INVALID);		
									scanf ("%f", &tf);
								}
							while (tf <= ti);

						delta_t = (tf - ti)/muestreo;
						};

						loglineal (muestreo, precision, ti, delta_t);
						break;

				case 4: expon (muestreo, precision, ti, delta_t);
						break;

				case 5: escalon (muestreo, precision, ti, delta_t);
						break;

				case 6: mrua (muestreo, precision, ti, delta_t);
						break;

				case 7: parh (muestreo, precision, ti, delta_t);
						break;

				default: 	printf("%s", MSG_NUEVO_INGRESO);						
							reasignar = 2;

			};

			if ( reasignar == 1) reasignar = 0;
			confirmacion = 0;
		};
	};
	return EXIT_SUCCESS;
}

void senoidal (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float freq,Amp,phi,fseno,time;

	printf("%s\n",MSG_SENOIDAL_DESCRIP);

	printf("%s\n",MSG_SENOIDAL_AMP);
	scanf("%f",&Amp);

	printf("%s\n",MSG_SENOIDAL_FREQ);
	scanf("%f",&freq);

	printf("%s\n",MSG_SENOIDAL_PHI);
	scanf("%f",&phi);

	printf("%s", MSG_XFX);

	for (i=0; i<muestreo ; i++) 
	{
		time=ti+(i*delta_t);
		fseno=Amp*(sin((6.28*freq*time)+phi));

		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fseno);
	}
}

void loglineal (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float time,floglineal;

	printf("%s\n",MSG_LOGLINEAL_DESCRIP);

	printf("%s", MSG_XFX);

	for(i=0; i<muestreo ; i++)
	{
		time=ti+(i*delta_t);
		floglineal=time*(log10(time));
		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,floglineal);
	}
}

void log_10 (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float time,flog_10;

	printf("%s\n",MSG_LOG10_DESCRIP);

	for(i=0; i<muestreo ; i++)
	{
		time=ti+(i*delta_t);
		flog_10=log10(time);
		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,flog_10);
	}
}

void mrua (int muestreo,int precision,float ti,float delta_t)
{
	int i;
	float time,fmrua,ac,vi,posin;

	printf("%s\n",MSG_MRUA_DESCRIP );

	printf("%s\n ",MSG_MRUA_ACEL );
	scanf("%f",&ac);

	printf("%s\n" ,MSG_MRUA_VEL_INI);
	scanf("%f",&vi);

	printf("%s\n",MSG_MRUA_POS_INI );
	scanf("%f",&posin);

	printf("%s", MSG_XFX);

	for (i=0;i<muestreo;i++)
	{
	        time=ti+delta_t*i;
	        fmrua=posin+vi*time+(pow(time,2))*ac;
	        printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fmrua);
	}
}

void  expon (int muestreo, int precision, float ti,float delta_t)
{	int i;
	float fexpon,time,k1,k2;

	printf("%s\n",MSG_EXP_DESCRIP);

	printf("%s\n",MSG_PARAM_EXP_CONST_UNO);
	scanf("%f",&k1);

	printf("%s\n",MSG_PARAM_EXP_CONST_DOS);
	scanf("%f",&k2);

	printf("%s", MSG_XFX);

	for(i=0;i<muestreo;i++)
	{
		time=ti+i*delta_t;
		fexpon=k1*exp(k2*time);

		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,fexpon);
	}
}

void escalon (int muestreo, int precision, float ti,float delta_t)
{
	int i;
	float time;
	
	printf("%s", MSG_XFX);
	
	for(i=0;i<=muestreo;i++)
	{
		time=ti+i*delta_t;

		if(time<0)
		{
			printf("\n%2.*f %50.*f\n" ,precision,time,precision,0.0);
	                continue;
		}
		printf("\n%2.*f\t%50.*f\n" ,precision,time,precision,1.0);
	}
}
void parh (int muestreo,int precision,float ti,float delta_t)
{
	int i;
	float x_a,x_b,fparh,time;

	printf("%s\n",MSG_HIP_DESCRIP);

	printf("%s\n",MSG_HIP_X_A );
	scanf("%f",&x_a);

	while (x_a==0) 
	{
			
		printf("%s\n",MSG_HIP_ERROR_A0B);
		scanf("%f",&x_a);
	}

	printf("%s\n",MSG_HIP_X_B );
	scanf("%f",&x_b);

	while (x_b==0) 
	{
		printf("%s\n",MSG_HIP_ERROR_A0B);
		scanf("%f",&x_b);
	}
	
	printf("%s", MSG_XFXY);

	for (i = 0; i<muestreo; i++)
	{
	  	time=ti+delta_t*i;
		fparh=(pow(time/x_a,2))+(pow(time/x_b,2));

		printf("\n(%.*f,%.*f)\t %50.4f\n",precision,time,precision,time,fparh);
	}
}