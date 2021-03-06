#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#define TAM 100
#define false 0
#define true 1



typedef struct elemento
{
    char dato;
    int visitado;
    int nodo;
    int girointerk;
    int giroexterk;
    int girointerp;
    int con;
    int un;
    struct elemento *sig;
    struct elemento *ant;
    struct elemento *sigA;
    struct elemento *antA;
}Elemento;
typedef struct ListaIdentificar
{
    Elemento *inicio;
    Elemento *fin;
    Elemento *seguir;
    Elemento *juntar;
    int tamano;
}Lista;
void separar(Lista *l);
void menu(void);
void nodo_principal(Lista *l);
void inicializa(Lista *);
Elemento * creaNodo(char );
void avanzar(Lista*, Elemento *);
void imprime_i_f(Lista *);
void imprime_f_i(Lista *);
char entero_c(int numero);
char * limpiar(char conca[]);
int inserta_primer_elem(Lista *, Elemento *);
int inserta_al_inicio(Lista *, Elemento *);
int inserta_al_final(Lista *, Elemento *);
int inserta_en_pos(Lista *, Elemento *, int);
int elimina_al_inicio(Lista *);
int elimina_al_final(Lista *);
int elimina_ultimo(Lista *);//lista con 1 elemento
int elimina_en_pos(Lista *, int);
void destruye_lista(Lista *);
void pop(Lista *l);
void unir(Lista *l,int c,char anidado[]);
int decimal(int h,int u);
int unidad(int h);
void separar(Lista *l);
char* colocar(char d[], int t1,int t2);
void kleen(Lista *l,int c,char anidado[]);
void positiva(Lista *l,int c,char anidado[]);
void push(Lista*l, Elemento *nvo);
void automata(Lista *l,Lista *laux, int t );
void main(int argc,char * argv[])
{
	char cadena[TAM],quintupla[TAM],dir[TAM];
    int opcion, pos,i,a,num;
    char cad;

    int ancho, cont=0;
    Lista l1,pila,pila2,nodos;
    Elemento *nvo,*nvo1,*nvo2,*puntador,*term;
    strcpy(cadena,argv[1]);
     int t=strlen(cadena);
        int r;
          for(r=0;r<t;r++){
          printf("%c",cadena[r]);
}
printf("\n");
        inicializa(&l1);
        inicializa(&pila);
        inicializa(&pila2);
        inicializa(&nodos);
        opcion=1;
        switch(opcion)
        {
            case 1: 
  
			        
			        ancho=strlen(cadena);
			        for(i=0;i<ancho;i++){
			        	nvo=creaNodo(cadena[i]);
			        	nvo2=creaNodo(cadena[i+1]);
			        	nvo1=creaNodo('.');
			        	if(cadena[i]==')'){
			        		pop(&pila);
			        	    push(&pila2,nvo2);
						}
			        	if(cadena[i]=='('){
			        		
			        		push(&pila,nvo);
						}  
			            if(cadena[i]=='|'){
			            	push(&pila2,nvo);
			            	cont=cont+1;
						}
						if((((cadena [i]>='a')&&(cadena[i]<='z'))||((cadena[i]>='0')&&(cadena[i]<='9')))&&(i==(cont-1))){
							push(&pila2,nvo1);
						}
					
						
						if(((cadena [i]>='a')&&(cadena[i]<='z'))||((cadena[i]>='0')&&(cadena[i]<='9'))){
					             if(((cadena [i+1]>='a')&&(cadena[i+1]<='z'))||((cadena[i+1]>='0')&&(cadena[i+1]<='9'))){
								push(&pila2,nvo);
								push(&pila2,nvo2);
								push(&pila2,nvo1);
								i=i+1;
							}
							else{
								push(&pila2,nvo);
								push(&pila2,nvo1);
							}
						}
						
			            
					}
			        term=creaNodo('#');
           push(&pila2,term);
			        imprime_i_f(&pila2);
			        printf("\n");
			        printf("%d\n",cont);
			        //printf("%d",pila2.tamano);
 //imprime_i_f(&nodos);
			       automata(&nodos,&pila2, cont ); 
                   
                    break;
            
            case 2: printf("Hasta luego...");
                    break;
            default: printf("Opci�n inv�lida");
        }
        system("pause");
        destruye_lista(&l1);
   
}
void menu(void)
{
    system("cls ");
    printf("Men� .\n\n");
    printf("_____________________________\n");
    printf("1) Introducir regla\n");
    printf("2) Salir\n");
    printf("Opci�n: ");
}
void inicializa(Lista *l)
{
    l->inicio=NULL;
    l->fin=NULL;
    l->seguir=NULL;
    l->tamano=0;
}
Elemento * creaNodo(char cad)
{

    Elemento *nvo;
    nvo=(Elemento *)malloc(sizeof(Elemento));
    if(nvo!=NULL)
    {
        nvo->sig=NULL;
        nvo->ant=NULL;
        nvo->antA=NULL;
        nvo->sigA=NULL;
        nvo->dato=cad;
        nvo->visitado=false;
        nvo->giroexterk=false;
        nvo->girointerk=false;
        nvo->con=false;
        nvo->girointerp=false;
    }
    return nvo;
}




void imprime_i_f(Lista *l)
{
    Elemento *aux=l->inicio;
  
    while(aux!=NULL)
    {
        if(aux==l->inicio)
        {
        	printf(" %c ", aux->dato);
        aux=aux->sig;
		}
		else
		{
		
		printf(" %c ", aux->dato);
        aux=aux->sig;
    }
    }
   
}
 void imprime_f_i(Lista *l )
 {
 	 Elemento *aux=l->fin;

 	 printf("< ");
    while(aux!=NULL)
    {
        if(aux==l->fin)
        {
        	printf(" %c | ", aux->dato);
        aux=aux->ant;
		}
		else
		{
		
		printf(" %c | ", aux->dato);
        aux=aux->ant;
    }
    }
    printf(" b >\n");
 }
 
int inserta_primer_elem(Lista *l, Elemento *nvo)
{
        if(l->tamano==0)
        {
            l->inicio=nvo;
            l->fin=nvo;
            l->tamano++;
            return 1;
        }
        else
            return 0;
}
int inserta_al_inicio(Lista *l, Elemento *nvo)
{
    if(l->tamano>0)
    {
        nvo->sig=l->inicio;
        l->inicio->ant=nvo;
        l->inicio=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}
int inserta_al_final(Lista *l, Elemento *nvo)
{
    if(l->tamano>0)
    {
        l->fin->sig=nvo;
        nvo->ant=l->fin;
        l->fin=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}
int inserta_en_pos(Lista *l, Elemento *nvo, int pos)
{
    Elemento *aux=l->inicio;    int i;
    if(l->tamano>0)
    {
        if((pos>0)&&(pos<=(l->tamano)))
        {
            if(pos==1)
                return (inserta_al_inicio(l,nvo));
            else
            {
                for(i=1;i<pos;i++)
                    aux=aux->sig;
                nvo->sig=aux;
                aux->ant->sig=nvo;
                nvo->ant=aux->ant;
                aux->ant=nvo;
                l->tamano++;
                return 1;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}
int elimina_al_inicio(Lista *l)
{
    Elemento *aux=l->inicio;
    if(l->tamano>1)
    {
        l->inicio=l->inicio->sig;  
        l->inicio->ant=NULL;
        free(aux);
        l->tamano--;
        return 1;
    }
    else
        return 0;
}
int elimina_al_final(Lista *l)
{
    Elemento *aux=l->inicio;   int i;
    if(l->tamano>1)
    {
        for(i=1;i<=(l->tamano-2);i++)
            aux=aux->sig;
        l->fin=aux;
        l->fin=l->fin->ant;
        l->fin->sig=NULL;
        free(aux->sig);
        l->tamano--;
        return 1;
    }
    else
        return 0;
}
int elimina_ultimo(Lista *l)
{
    if(l->tamano==1)
    {
    	l->fin->sig=NULL;
    	l->inicio->ant=NULL;

        inicializa(l);
        return 1;
    }
    else
        return 0;
}
int unidad(int h){
int aux;
   if((h>=10)&&(h<20)){
    aux=h-10;
}
if((h>=20)&&(h<30)){
    aux=h-20;
}
if((h>=30)&&(h<40)){
    aux=h-30;
}
return aux;
}

int decimal(int h,int u){
int aux;
   if((h>=10)&&(h<20)){
    aux=(h-u)/10;
}
if((h>=20)&&(h<30)){
    aux=(h-u)/10;
}
if((h>=30)&&(h<40)){
    aux=(h-u)/10;
}
return aux;
}
int elimina_en_pos(Lista *l, int pos)
{
    Elemento *aux1=l->inicio, *aux2;   int i;
    if(l->tamano>0)
    {
        if((pos>0)&&(pos<=(l->tamano)))
        {
           if(pos==1)
           {
                if(l->tamano==1)
                    return (elimina_ultimo(l));
                else
                    return (elimina_al_inicio(l));
           }
           else
           {
                if(pos==l->tamano)
                    return (elimina_al_final(l));
                else
                {
                    for(i=1;i<=(pos-2);i++)
                        aux1=aux1->sig;
                    aux2=aux1->sig;
                    aux1->sig=aux2->sig;
                    aux1->ant=aux2->ant;
                    free(aux2);
                    l->tamano--;
                    return 1;
                }
            }
        }
        else
            return 0;
    }
    else
        return 0;
}
void avanzar(Lista*l, Elemento *nvo)
{
	int elem;
	if(l->tamano==0)
	  inserta_primer_elem(l,nvo);
	else
	 inserta_al_final(l,nvo);
}
void destruye_lista(Lista *l)
{
    int tmp;
    while(l->tamano>0)
    {
        if(l->tamano==1)
            tmp=elimina_ultimo(l);
        else
            tmp=elimina_al_inicio(l);
    }
}

char* colocar(char d[], int t1,int t2){

     char j1,j2,aux=' ' ,aux2=' ';
if((t1<10)&&(t2<10)){
                       j1=entero_c(t1);
			j2=entero_c(t2);

			d[0]=j1;
			d[1]='-';
			d[2]='>';
		        d[3]=j2;
}		

    if((t1>=10)&&(t2>=10)){
    
      j1=entero_c(decimal(t1,unidad(t1)));
         aux=entero_c(unidad(t1));
	j2=entero_c(decimal(t2,unidad(t2)));
         aux2=entero_c(unidad(t2));		

			d[0]=j1;
                        d[1]=aux;
			d[2]='-';
			d[3]='>';
		        d[4]=j2;
                        d[5]=aux2;

}
if((t1<10)&&(t2>=10)){
    
      j1=entero_c(t1);
	j2=entero_c(decimal(t2,unidad(t2)));
         aux2=entero_c(unidad(t2));		

			d[0]=j1;
                        d[1]='-';
			d[2]='>';
		        d[3]=j2;
                        d[4]=aux2;

}
 if((t1>=10)&&(t2<10)){
    
      j1=entero_c(decimal(t1,unidad(t1)));
         aux=entero_c(unidad(t1));
	j2=entero_c(t2);
         		

			d[0]=j1;
                        d[1]=aux;
			d[2]='-';
			d[3]='>';
		        d[4]=j2;
                     

}
       
return d;
}
void separar(Lista *l){
   Elemento *nvo1, *nvo2, *nvo;
                   
	   nvo1=creaNodo('e');
	   nvo2=creaNodo('e');
            Elemento * t=l->fin;
             
              t->un=true;
	   l->seguir=l->fin;
           
            l->fin->sig=nvo1;
            nvo1->ant=l->fin;
            l->fin=nvo1;
            l->tamano++;
            //segunda prioridad
            l->seguir->sigA=nvo2;
            nvo2->antA=l->seguir;
            l->seguir=nvo2;
            l->tamano++;
            l->juntar=l->seguir;


}

void unir(Lista *l,int c,char anidado[]){

     Elemento *nvo1;
     int i;
     
	 int x=strlen(anidado);
	 for(i=0;i<x;i++){
	 	if(((anidado[i]>='a')&&(anidado[i]<='z'))||((anidado[i]>='0')&&(anidado[i]<='9'))){
	 
		 
	 	 nvo1=creaNodo(anidado[i]);
                 nvo1->con=true;
	 	inserta_al_final(l,nvo1);
		
	 }
	 }
	
	

}

void kleen(Lista *l,int c,char anidado[]){
     Elemento *nvo1;
     int i;
     nvo1=creaNodo('e');
     nvo1->girointerk=true;
	 inserta_al_final(l,nvo1);
	 Elemento *aux=l->fin;
	 aux=aux->ant;
	 aux->giroexterk=true;
	 int x=strlen(anidado);
	 for(i=0;i<x;i++){
	 	if(((anidado[i]>='a')&&(anidado[i]<='z'))||((anidado[i]>='0')&&(anidado[i]<='9'))){
	 	
		 
	 	 nvo1=creaNodo(anidado[i]);
	 	 if(i==(x-1)){
	 	 	nvo1->girointerk=true;
		  }
	     inserta_al_final(l,nvo1);
		
	 }

	 }
	nvo1=creaNodo('e');
	nvo1->giroexterk=true;
	inserta_al_final(l,nvo1);

}
char * limpiar(char conca[]){
  int i;

for( i=0; i<strlen( conca ); i++ ){
	  	 conca[i]= '\0';
	  }
return conca;
}
void positiva(Lista *l,int c,char anidado[]){
     Elemento *nvo1,*nvo2;
     int i,j;
     nvo1=creaNodo('e');
     nvo1->girointerp=true;
	 inserta_al_final(l,nvo1);
	 int x=strlen(anidado);
        j=x-1;

	 for(i=0;i<x;i++){
	 	if(((anidado[i]>='a')&&(anidado[i]<='z'))||((anidado[i]>='0')&&(anidado[i]<='9'))){
		 
	     
	 	 nvo1=creaNodo(anidado[i]);
	 	 
	     inserta_al_final(l,nvo1);
		 
	 }
	 }
  nvo2=l->fin;
  nvo2->girointerp=true;
	nvo1=creaNodo('e');
	inserta_al_final(l,nvo1);

}

char entero_c(int numero){
    return numero + '0';
}
void automata(Lista *l,Lista *laux, int t ){
	char conca[TAM];
	int letras=0;
	Lista aux;
    int j,i;
	inicializa(&aux);
	Elemento *cont=laux->inicio;
	Elemento *apuntador=laux->inicio->sig;
	Elemento *c2=laux->inicio;
   Elemento *s=laux->inicio;
	Elemento *nvo,*nvo1,*nvo2,*in;
	int concatenacion=0;
int next=1;
while(s!=NULL){
    	s->nodo=next;
    	next+=1;
    	s=s->sig;	
	}
	while(apuntador!=NULL){
		if(t==0){
			if(l->tamano==0){
				nvo=creaNodo('i');
				inserta_primer_elem(l,nvo);
				
			}
			if(((apuntador->dato>='a')&&(apuntador->dato<='z'))||((apuntador->dato>='0')&&(apuntador->dato<='9'))){
				concatenacion=concatenacion +1;
				apuntador=apuntador->sig;
apuntador=apuntador->sig;
				
				
			}  //kleen 
			else{
				if(apuntador->dato=='.'){
					cont=apuntador;
 
cont=cont->sig;

					
					if((cont->dato=='*')||(cont->dato=='+')){
					
						
							while(((c2->dato>='a')&&(c2->dato<='z'))||((c2->dato>='0')&&(c2->dato<='9'))){
							
								conca[letras]=c2->dato;
								c2=c2->sig;
								letras++;
							}
						
							if(cont->dato=='*')
							{
									kleen(l,concatenacion,conca);
							}
						   if(cont->dato =='+'){
								positiva(l,concatenacion,conca);
							
						}
                     
					}
if(((cont->dato>='a')&&(cont->dato<='z'))||((cont->dato>='0')&&(cont->dato<='9'))||(cont->dato=='#')||(cont->dato=='|')){
while(((c2->dato>='a')&&(c2->dato<='z'))||((c2->dato>='0')&&(c2->dato<='9'))){

							
								conca[letras]=c2->dato;
								c2=c2->sig;
								letras++;
							}
         unir(l,concatenacion,conca);
}
       
           


	
				}
                          
			}


		}
		if(t==1){
           if(c2->dato=='|'){
	           cont=cont->sig;
		   apuntador=apuntador->sig;
		   c2=c2->sig;
		   l->seguir=l->fin;
		   l->fin=l->juntar;
		   printf("si llega");		}
		
		}
			
		if(l->tamano==0){
				nvo=creaNodo('i');
				inserta_primer_elem(l,nvo);
				separar(l);
			}
			if(((apuntador->dato>='a')&&(apuntador->dato<='z'))||((apuntador->dato>='0')&&(apuntador->dato<='9'))){
				concatenacion=concatenacion +1;
				apuntador=apuntador->sig;
                                apuntador=apuntador->sig;
				
				
			}  //kleen 
			else{
				if(apuntador->dato=='.'){
					cont=apuntador;
                                        cont=cont->sig;

					
					if((cont->dato=='*')||(cont->dato=='+')){
					
						
							while(((c2->dato>='a')&&(c2->dato<='z'))||((c2->dato>='0')&&(c2->dato<='9'))){
							
								conca[letras]=c2->dato;
								c2=c2->sig;
								letras++;
							}
							
							if(cont->dato=='*')
							{
									kleen(l,concatenacion,conca);
                                 printf("\nkleen");
							}
						   if(cont->dato =='+'){
								positiva(l,concatenacion,conca);
							
 printf("\npositiva");
						}
                     
					}
if(((cont->dato>='a')&&(cont->dato<='z'))||((cont->dato>='0')&&(cont->dato<='9'))||(cont->dato=='#')||(cont->dato=='|')){
while(((c2->dato>='a')&&(c2->dato<='z'))||((c2->dato>='0')&&(c2->dato<='9'))){

							
								conca[letras]=c2->dato;
								c2=c2->sig;
								letras++;
							}
         unir(l,concatenacion,conca);
}
       
	
				}
                          
			}
                
	imprime_i_f(l);	
    printf("\n");
   apuntador=cont;
    //printf("divide");
    
	  strcpy(conca,limpiar(conca));
	  letras=0;
      if((cont->dato=='#')&&(t>0)){
             printf("unios");
      	     nvo1=creaNodo('e');	 
	     inserta_al_final(l,nvo1);
	     l->seguir->sig=l->fin;
	     l->fin->antA=l->seguir;
            apuntador=NULL;
printf("uniosFFFFFFFF");
	  }
		if(apuntador->sig!=NULL){
    		cont=cont->sig;
    		apuntador=cont;
    		apuntador=apuntador->sig;
    		c2=cont;
    		c2=c2->ant;
    	
	}else{
		apuntador=apuntador->sig;
	}	
	}
//archivo gv
	Elemento *num=l->inicio;
	int nd=1;
	char ep[]="[label=\"&epsilon\"];\n";
	printf("ddddddddddd");	FILE* fichero;
	char d1[]=" ];\n",datos[3];
        char d2[]=" label=\" ";
        char d4[]="label=\"inicio\"";
    fichero = fopen("pr3.gv", "wt");
	char cadena1 []="digraph automata{ \n rankdir = LR; \n node[shape =circle];\n inicio ->1[ ";
        
	char cad1[]=";\n";
	fputs(cadena1, fichero); 
  char ax='\"';

	
	fputs(d4, fichero);

	
	
	fputs(d1, fichero);
    char cadena [8];
int nodoaux;
    char t1,t2;
    while(num!=NULL){
    	num->nodo=nd;
    	nd+=1;
    	num=num->sig;
    	if(t>1){
		
		if(num==l->seguir){
			num=l->juntar;
		}
	 }
			
	}
   num=l->inicio;

	Elemento *numI=l->inicio;
    Elemento *numD=l->inicio;
    numD=numD->sig;
   int lugar=0;
    char h1[]=" [label=\"";
    printf("si funciona");
    while(numD!=NULL){
  if(t==0){
   if((numD->girointerp==true)&&(numD->visitado==false)&&(numD->dato='e')&&(numI->dato=='i')){
        fputs(colocar(cadena,numI->nodo,numD->nodo), fichero);	
			fputs(ep, fichero);
strcpy(cadena,limpiar(cadena));
  Elemento *flecha=l->inicio;
  while(flecha!=NULL){
printf("%d",flecha->girointerp);
flecha=flecha->sig;
}
  printf("\n");
numD->visitado=true;
          nodoaux=numD->nodo;
         numD=numD->sig;
          while(numD->girointerp!=true){
    numD=numD->sig;
}
fputs(colocar(cadena,numD->nodo,nodoaux), fichero);	
			fputs(ep, fichero);
strcpy(cadena,limpiar(cadena));
  numD->visitado==true;
fputs(colocar(cadena,numD->nodo,((numD->nodo)+1)), fichero);	
			fputs(ep, fichero);
strcpy(cadena,limpiar(cadena));
  numD=numD->ant;
while(numD->girointerp!=true){
    numD=numD->ant;
}
   
        }
                
        
                if(((numI->giroexterk==true)&&(numI->visitado==false)&&(numD->girointerk==true)&&(numD->con!=true))||((numI->giroexterk==true)&&(numI->visitado==true)&&(numD->girointerk=true)&&(numD->con!=true))){
    printf("\n4");
                if((numI->giroexterk==true)&&(numD->girointerk==true)){
		  printf("\n1");

		
			fputs(colocar(cadena,numI->nodo,numD->nodo), fichero);
			//fputs(h1,fichero);
	
			fputs(ep, fichero);
			//printf("\nsi funciona1");
                      t1=' ';
                   t2=' ';
	                  
		}
strcpy(cadena,limpiar(cadena));
    	 	while(numD->giroexterk!=true){
    	 		numD=numD->sig;
			 }
			 
			fputs(colocar(cadena,numI->nodo,numD->nodo) ,fichero);
			
	
			fputs(ep, fichero);
                         
			numD->visitado=true;
			numI->visitado=true;
strcpy(cadena,limpiar(cadena));

         fputs(colocar(cadena,((numD->nodo)-1),numD->nodo), fichero);
		

			fputs(ep, fichero);


numI=numI->sig;
                        numD=numD->ant;
                        
         fputs(colocar(cadena,numD->nodo,numI->nodo), fichero);
			
	t1=' ';
                   t2=' ';
strcpy(cadena,limpiar(cadena));
			fputs(ep, fichero);
                        numD->visitado=true;
			numI->visitado=true;
                        

		        numD=numI;
			numI=numI->ant;
  
                        
		 }

if(((numD->girointerp==true)&&(numI->dato!='e')&&(numI->dato!='i'))){

			fputs(colocar(cadena,numI->nodo,numD->nodo), fichero);

strcpy(cadena,limpiar(cadena));
                   
			fputs(h1,fichero);
		    datos[0]=numD->dato;datos[1]='\"';
datos[2]=']';datos[3]=';';
                     
		    
		    fputs(datos, fichero);
					
				
			
}

      if(((numI->girointerk==true)&&(numD->dato!='e'))||((numD->girointerk==true)&&(numD->dato!='e'))||((numD->dato!='e')&&(numI->dato!='e')&&(numD->giroexterk!=true))||((numI->girointerp==true)&&(numD->dato!='e'))||(numD->con==true)){
			if(numD->dato=='e'){
printf("\n7");
			
			fputs(colocar(cadena,numI->nodo,numD->nodo), fichero);
			//fputs(h1,fichero);
		t1=' ';
                   t2=' ';
			fputs(ep, fichero);
		strcpy(cadena,limpiar(cadena));
			}else{
printf("\n8");
			

			fputs(colocar(cadena,numI->nodo,numD->nodo), fichero);

strcpy(cadena,limpiar(cadena));
                   
			fputs(h1,fichero);
		//	fputs(d2, fichero);
		//	fputs(ep, fichero);
		    datos[0]=numD->dato;datos[1]='\"';
datos[2]=']';datos[3]=';';
                     
		    
		    fputs(datos, fichero);
		//fputs(d1, fichero);
					
				
			}
		}

            }
            
            if((numD==l->seguir)&&(t>0)){
            	Elemento *final=l->fin;
            	fputs(colocar(cadena,numD->nodo,final->nodo), fichero);
			fputs(ep, fichero);
            	
            	
            	numD=l->juntar;
            	numI=l->juntar;
				numI=numI->ant;
				fputs(colocar(cadena,numI->nodo,numD->nodo), fichero);
		    	fputs(ep, fichero);
		    	numI=numI->sigA;
		    	numD=numD->sig;
				
				}

           numI=numI->sig;
	                  numD=numD->sig;
	}
     char fin[]="\n}";
    fputs(fin, fichero);
    fclose(fichero);
    system("dot -Tpng pr3.gv> sa.png");
	//->

	
}



//pila infijo a pos
void pop(Lista *l)
{
	Elemento *aux=l->fin;
	 if(l->tamano!=1)
    {
	elimina_al_final(l);
	printf("Elemento eliminado con exito\n");
    }
	else
	{
	elimina_ultimo(l);
	printf("Elemento eliminado con exito \n");
    }   
    
    
}
void push(Lista*l, Elemento *nvo)
{
	int elem;
	if(l->tamano==0)
	  inserta_primer_elem(l,nvo);
	else
	 inserta_al_final(l,nvo);
}
// pila

