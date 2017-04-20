#ifndef FUNCIONES__H
#define FUNCIONES__H 
void parametros (void);
void senoidal (int, int, float, float);
void log_10 (int, int, float, float);
void loglineal (int, int, float, float);
void expon (int, int, float, float);
void escalon (int, int, float, float);
void mrua (int, int, float, float);
void parh (int, int, float, float);



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

#endif