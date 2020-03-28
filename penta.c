#include<stdio.h>
#include<windows.h>
#include<conio.h>
void sonidoTecla(char teclas[]);
int main(void){
char v[]="drmfslid;";

sonidoTecla(v);
return 0;



}



void sonidoTecla(char tecla[]){
	int i=0;
	printf("********************TECLADO MUSICAL*********************\n");
 
	while(tecla[i]!=';'){
	
 
		if (tecla[i]=='d')
			Beep(523, 200);  //DO
		else if (tecla[i]=='r')
			Beep(587, 200);  //RE
		else if (tecla[i]=='m')
			Beep(659, 200);  //MI
		else if (tecla[i]=='f')
		    Beep(698, 200);  //FA
		else if (tecla[i]=='s')
			Beep(783, 200);  //SOL
		else if (tecla[i]=='l')
			Beep(880, 200);  //LA
		else if (tecla[i]=='i')
			Beep(987, 200);  //SI
	i++;
}
}
