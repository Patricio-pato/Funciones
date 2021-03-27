#include<iostream> //Biblioteca estándar de C++
#include<cmath> //Biblioteca de funciones matemáticas de C++
#include<conio.h> //Biblioteca de la consola de C
#include<graphics.h> //Biblioteca para realizar gráficos en C
const int AnchoVentana = 720, AltoVentana = 720, pi = 3.141592653; //Declarar constantes utilizadas en el programa
using namespace std;
void dibujarLinea( int moverX, int moverY, int dibujarX, int dibujarY, int color, int colorFondo, int textoX, int textoY, char *nombre ) { //Función utilizada para graficar lineas rectas.
    moveto   ( moverX, moverY ); //Punto inicial de la linea
    setcolor ( color ); //Color del trazo de la linea
    setbkcolor ( colorFondo ); //Color del fondo del trazo
    lineto   ( dibujarX, dibujarY ); //Punto final de la linea
    outtextxy( textoX, textoY, nombre ); //Texto de referencia de la linea.
}

void ejesCartesianos ( ) {	//Dibujar los ejes cartesianos para la función

    dibujarLinea( 0, AltoVentana / 2, AnchoVentana, AltoVentana / 2, BLACK, WHITE, AnchoVentana - 20, AltoVentana / 2 + 10, "X" );//Dibujar eje X
    dibujarLinea( AnchoVentana / 2, 0, AnchoVentana / 2, AltoVentana, BLACK, WHITE, AnchoVentana / 2 + 10, 0, "Y" ); //Dibujar eje Y
}
    
int main(){
  float fx=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0,n=0, Dm=0,Im=0,Dm1,Im1; //fx=valores de la función, Dm= rango en x a graficar de la función,Im= rango en y a graficar de la funcion, el resto de variables son utilizadas en las fórmulas
  int h=0,i=0,j=0,k=0,l=0,m=0; //Variables utilizadas para los exponentes en la función polinómica y racional.
  int tecla, conteoraices=0;
  float Farr=0,Farr2=0,x1=0,x2=0,x3=0;
  float Farr1[3];
  int VI=0,VI1=0,incremento=0;
  int opcion=0,opcion2=0,cantidadTerminos, preDm=0, preIm=0, incolor=1; //Variables auxiliares
  bool agregarFuncion;
  char arr[3], arr1[3],arr2[3];
 
  setlocale(LC_ALL, "");//Poder escribir caracteres especiales como á, é, í, ó, ú, ñ, etc. de manera directa en la salida.
  SetConsoleTitle("Graficador de funciones");//Cambiar nombre de la consola
 system("color F0");//Establecer el color F (Blanco) como el fondo de la consola y el color 0 (Negro) como el color del texto.
  
    initwindow( AnchoVentana, AltoVentana, "Gráfico de la función");//Inicializar la ventana en que se realizará el gráfico.
	setfillstyle(SOLID_FILL,15);
	floodfill(360 , 360 ,15); //Pintar el fondo de la ventana de color Blanco 

 printf("Digite el valor máximo del Dominio de su función (Por defecto es 360): ");scanf("%d",&preDm);//Pedir al usuario el rango a graficar en la función en X
 printf("Digite el valor máximo de la Imagen de su función (Por defecto es 360): "); scanf("%d",&preIm);
   
   
   do{Dm=360/preDm; //Es necesario dividir 360 (La mitad del tamaño de la ventana del grafico) por el valor ingresado por el usuario. Luego, en las funciones, se utiliza a este resultado para llegar al valor ingresado por el usuario.
   Im=360/preIm;//Idem al caso anterior

  // \n -> salto de linea
 printf("\n1. Función lineal (ax+b). \n2. Función cuadrática (a(x^2)+bx+c).\n3. Función polinómica (a(x^h)+b(x^i)+c(x^j)+d(x^k)+e(x^l)+f(x^m)+g).\n4. Función seno (asen(bx+c*pi)+d).\n5. Función coseno (acos(bx+c*pi)+d).\n6. Función tangente (atan(bx+c*pi)+d). \n7. Función exponencial (a(b^(x+c))+d). \n8. Vector (a+bi). \n9. Función racional ((a(x^h)+b(x^i)+c(x^j)+n)/(d(x^k)+e(x^l)+f(x^m)+g)).");
  //Lista de funciones disponibles
 printf("\n\nDigite la función que desea graficar: "); scanf("%d",&opcion);//Pedir la funcion a graficar
  
    switch(opcion){
      	case 1: printf("\nDigite el valor de a: "); scanf("%f",&a);//Funcion lineal
            printf("Digite el valor de b: "); scanf("%f",&b);
            
		   ejesCartesianos();//Crear la ventana con sus respectivos ejes
         
		    for(float x=-360/Dm;x<=360/Dm;x+=0.01){//Iterar los valores de x para conseguir todos los valores de la funcion
  	       	fx=a*x+b;//Formula de la función
  	       	putpixel(360+x*Dm,360-fx*Im,incolor);//Dibujar las coordenadas obtenidas con la formula
			}
			Farr=-b/a;
	        x1=360+(-b/a*Dm);
			sprintf(arr,"%.2f",Farr);
	    	outtextxy(20,50,arr);
	    	setcolor(RED);
	    	circle(x1,360,6);
	        setfillstyle(SOLID_FILL,RED);
	      	floodfill(x1,360,RED);
	    	
			break; 	//Si se cumple este caso, omitir los demás
			 
		case 2: printf("\nDigite el valor de a: "); scanf("%f",&a);//Funcion cuadrática
            printf("Digite el valor de b: "); scanf("%f",&b);
            printf("Digite el valor de c: "); scanf("%f",&c);
        
            ejesCartesianos(); 
			
         //   for(float x=-360/Dm;x<=360/Dm;x+=0.0001){
  	       //	fx=(a*pow(x,2)+b*x+c);
  	       //	putpixel(360+x*Dm,360-fx*Im,incolor);
  	        
		//	}	
	
   
	         for(float x=-360/Dm;x<=360/Dm;x+=0.0001){
  	       	fx=(a*pow(x,2)+b*x+c);
  	       	putpixel(360+x*Dm,360-fx*Im,incolor);
  	       		if(fx<0.0001 & fx>-0.0001) {
  	       		Farr=x;
  	       		x1=360+(x*Dm);
  	       		sprintf(arr1,"%.1f",Farr);
  	       		outtextxy(x1,370,arr1); 
   	       		setcolor(RED);
  	       		circle(x1,360,6);
  	       		setfillstyle(SOLID_FILL,RED);
	          	floodfill(x1,360,RED);   
  	            printf("%f",x);}
				  
				  }
	
  	       
  	      
				
        
	
	
		 // Farr1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
		  
  	        //Farr2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
		   //	printf("%f",Farr2);
	    /*	 if(Farr1>=0 & Farr2<=0){
	    	 	x2=360+(Farr1*Dm);
	    	 	x3=360-(Farr2*-Dm);
			 }	
			if(Farr1>=0 & Farr2>=0){
	    	 	x2=360+(Farr1*Dm);
	    	 	x3=360+(Farr2*Dm);
			 }	
		   	if(Farr1<=0 & Farr2<=0){
	    	 	x2=360-(Farr1*-Dm);
	    	 	x3=360-(Farr2*-Dm);
			 }	
	       
	        	printf("\n%f",x2);
	         	printf("\n%f",x3);
			sprintf(arr1,"%f.2",Farr1);
		     	printf("\n%f",Farr1);
			sprintf(arr2,"%.2f",Farr2);
		     	printf("\n%f",arr2);
	    //	outtextxy(30,30,arr1);
	    //	outtextxy(30,60,arr2);
		  //    circle(x2,360,6);
		 //     circle(x3,360,6);*/
		 
		
	    	
	   do{ if(!kbhit()){
		tecla=getch();
	       	for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
	       	fx=(a*pow(x,2)+b*x+c);
			putpixel(360+x*Dm,360-fx*Im,WHITE);
			}
			
		   if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
		     Dm=360/preDm;
	    	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
  	       	fx=(a*pow(x,2)+b*x+c);
  	       	putpixel(360+x*Dm,360-fx*Im,incolor);   
			}}       
			 if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
  	       	fx=(a*pow(x,2)+b*x+c);
  	       	putpixel(360+x*Dm,360-fx*Im,incolor);
        	}}
		    if(tecla=='a'){}
		   }	 
		   }while(tecla !='a');
		   VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   ejesCartesianos();
	      	    for(float x=-360/VI;x<=360/VI;x+=0.001){
  	       	fx=(a*pow(x,2)+b*x+c);
  	       	putpixel(360+x*Dm1,360-fx*Im1,incolor);
        	}
        	
			break; 	
			 
		case 3: printf("\nLa cantidad permitida de terminos es 6");//Función polinómica, 
		        printf("\nDigite la cantidad de términos de su polinomio: "); scanf("%d",&cantidadTerminos);//Pedir al usuario la cantidad de terminos que desea en el polinomio
		    
		     if(cantidadTerminos>=1){
		     	printf("\nDigite el valor de a: "); scanf("%f",&a);
		     	  printf("Digite el grado del término: "); scanf("%d",&h);//Pedir el exponente de la x en el termino actual
		     }
			 if(cantidadTerminos>=2){
		     	printf("\nDigite el valor de b: "); scanf("%f",&b);
		     	  printf("Digite el grado del término: "); scanf("%d",&i);
		     }
		     if(cantidadTerminos>=3){
		     	printf("\nDigite el valor de c: "); scanf("%f",&c);
		     	  printf("Digite el grado del término: "); scanf("%d",&j);
		     }
		     if(cantidadTerminos>=4){
		     	printf("\nDigite el valor de d: "); scanf("%f",&d);
		     	  printf("Digite el grado del término: "); scanf("%d",&k);
		     }
		     if(cantidadTerminos>=5){
		     	printf("\nDigite el valor de e: "); scanf("%f",&e);
		     	  printf("Digite el grado del término: "); scanf("%d",&l);
		     }
		     if(cantidadTerminos>=6){
		     	printf("\nDigite el valor de f: "); scanf("%f",&f);
		     	  printf("Digite el grado del término: "); scanf("%d",&m);
		     }
		     printf("\nDigite el valor del término independiente: ");scanf("%f",&g);//Pedir el valor del termino que no está acompañado por una x
		     
			 ejesCartesianos();
			 
			 for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			 fx=(a*(pow(x,h)))+(b*(pow(x,i)))+(c*(pow(x,j)))+(d*(pow(x,k)))+(e*(pow(x,l)))+(f*(pow(x,m)))+g;
			 putpixel(360+x*Dm,360-fx*Im,incolor);
			 }; 
		 do{if(!kbhit()){
			tecla=getch();	 
			for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 Dm=360/preDm;
	        fx=(a*(pow(x,h)))+(b*(pow(x,i)))+(c*(pow(x,j)))+(d*(pow(x,k)))+(e*(pow(x,l)))+(f*(pow(x,m)))+g;
			putpixel(360+x*Dm,360-fx*Im,WHITE);}
			
			if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
			Dm=360/preDm;
		   	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			fx=(a*(pow(x,h)))+(b*(pow(x,i)))+(c*(pow(x,j)))+(d*(pow(x,k)))+(e*(pow(x,l)))+(f*(pow(x,m)))+g;
		    putpixel(360+x*Dm,360-fx*Im,incolor);
	        }}
			 
			if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			fx=(a*(pow(x,h)))+(b*(pow(x,i)))+(c*(pow(x,j)))+(d*(pow(x,k)))+(e*(pow(x,l)))+(f*(pow(x,m)))+g;
		    putpixel(360+x*Dm,360-fx*Im,incolor);}}
            
			if(tecla=='a'){}
	    	} 
	       }while(tecla !='a');
	       VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   ejesCartesianos();
			for(float x=-360/VI;x<=360/VI;x+=0.001){
			fx=(a*(pow(x,h)))+(b*(pow(x,i)))+(c*(pow(x,j)))+(d*(pow(x,k)))+(e*(pow(x,l)))+(f*(pow(x,m)))+g;
		    putpixel(360+x*Dm1,360-fx*Im1,incolor);}
		    break; 
			 
			 
		case 4: printf("\nDigite el valor de a: "); scanf("%f",&a);//Función seno
            printf("Digite el valor de b: "); scanf("%f",&b);
            printf("Digite el valor de c: "); scanf("%f",&c);
            printf("Digite el valor de d: "); scanf("%f",&d);
            
            ejesCartesianos();
			
            for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
  	       	fx=a*sin(b*x+c*pi)+d;
  	       	putpixel(360+x*Dm,360-fx*Im,incolor); 
			}
				 do{if(!kbhit()){
			tecla=getch();	 
			for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 Dm=360/preDm;
	       fx=a*sin(b*x+c*pi)+d;
			putpixel(360+x*Dm,360-fx*Im,WHITE);}
			
			if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
			Dm=360/preDm;
		   	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			fx=a*sin(b*x+c*pi)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);
	        }}
			 
			if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
		  fx=a*sin(b*x+c*pi)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);}}
            
			if(tecla=='a'){}
	    	} 
	       }while(tecla !='a');
	       VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   	ejesCartesianos();
			for(float x=-360/VI;x<=360/VI;x+=0.001){
	     	fx=a*sin(b*x+c*pi)+d;
		    putpixel(360+x*Dm1,360-fx*Im1,incolor);}

			break;
			
		case 5: printf("\nDigite el valor de a: "); scanf("%f",&a); //Función coseno
            printf("Digite el valor de b: "); scanf("%f",&b);
            printf("Digite el valor de c: "); scanf("%f",&c);
            printf("Digite el valor de d: "); scanf("%f",&d);
            
            ejesCartesianos();
			
            for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
  	       	fx=a*cos(b*x+c*pi)+d;
  	       	putpixel(360+x*Dm,360-fx*Im,incolor); 
			}
			do{if(!kbhit()){
			tecla=getch();	 
			for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 Dm=360/preDm;
	      	fx=a*cos(b*x+c*pi)+d;
			putpixel(360+x*Dm,360-fx*Im,WHITE);}
			
			if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
			Dm=360/preDm;
		   	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			fx=a*cos(b*x+c*pi)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);
	        }}
			 
			if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
		 	fx=a*cos(b*x+c*pi)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);}}
            
			if(tecla=='a'){}
	    	} 
	       }while(tecla !='a');
	       VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   	 ejesCartesianos();
			for(float x=-360/VI;x<=360/VI;x+=0.001){
	     	fx=a*cos(b*x+c*pi)+d;
		    putpixel(360+x*Dm1,360-fx*Im1,incolor);}
	    	break; 			 
			
		case 6: printf("\nDigite el valor de a: "); scanf("%f",&a);//Función tangente
            printf("Digite el valor de b: "); scanf("%f",&b);
            printf("Digite el valor de c: "); scanf("%f",&c);
            printf("Digite el valor de d: "); scanf("%f",&d);
            
            ejesCartesianos();
			
            for(float x=(-360/Dm);x<=(360/Dm);x+=0.0001){
  	       	fx=a*tan(b*x+c*pi)+d;
  	       	putpixel(360+x*Dm,360-fx*Im,incolor); 
			}
					do{if(!kbhit()){
			tecla=getch();	 
			for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 Dm=360/preDm;
	      	fx=a*tan(b*x+c*pi)+d;
			putpixel(360+x*Dm,360-fx*Im,WHITE);}
			
			if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
			Dm=360/preDm;
		   	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			fx=a*tan(b*x+c*pi)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);
	        }}
			 
			if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
		 	fx=a*tan(b*x+c*pi)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);}}
            
			if(tecla=='a'){}
	    	} 
	       }while(tecla !='a');
	       VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   	ejesCartesianos();
			for(float x=-360/VI;x<=360/VI;x+=0.001){
	     	fx=a*tan(b*x+c*pi)+d;
		    putpixel(360+x*Dm1,360-fx*Im1,incolor);}
			break;
			
		case 7: printf("\nDigite el valor de a: "); scanf("%f",&a);//Función exponencial
            printf("Digite el valor de b: "); scanf("%f",&b);
            printf("Digite el valor de c: "); scanf("%f",&c);
            printf("Digite el valor de d: "); scanf("%f",&d);
            
            ejesCartesianos();
			
            for(float x=(-360/Dm);x<=(360/Dm);x+=0.0001){
  	       	fx=a*pow(b,x+c)+d;
  	       	putpixel(360+x*Dm,360-fx*Im,incolor);}
	     	do{if(!kbhit()){
			tecla=getch();	 
			for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 Dm=360/preDm;
	       	fx=a*pow(b,x+c)+d;
			putpixel(360+x*Dm,360-fx*Im,WHITE);}
			
			if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
			Dm=360/preDm;
		   	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			fx=a*pow(b,x+c)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);
	        }}
			 
			if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
		  	fx=a*pow(b,x+c)+d;
		    putpixel(360+x*Dm,360-fx*Im,incolor);}}
            
			if(tecla=='a'){}
	    	} 
	       }while(tecla !='a');
	       VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   	 ejesCartesianos();
			for(float x=-360/VI;x<=360/VI;x+=0.001){
	      	fx=a*pow(b,x+c)+d;
		    putpixel(360+x*Dm1,360-fx*Im1,incolor);}
			break; 	 			
			
		case 8: printf("\nDigite el valor de a: "); scanf("%f",&a); //Vectores
            printf("Digite el valor de b: "); scanf("%f",&b);
            
            ejesCartesianos();
			
			dibujarLinea(360, 360, 360+a*Dm, 360-b*Im, incolor, WHITE, 0, 0, " "); //Ya que un vector es solo una linea recta entre dos coordenadas, 0;0 y a;b, en vez de utilizar una itreación y graficar pixeles, se dibuja directamente una linea utilizando la función declarada al inicio

			 
			break; 	 
			
		case 9: printf("\nLa cantidad permitida de terminos por polinomio es 3");//Función racional
		        printf("\nDigite la cantidad de términos de su polinomio: "); scanf("%d",&cantidadTerminos);
		    
		     if(cantidadTerminos>=1){
		     	printf("\nDigite el valor de a: "); scanf("%f",&a);
		     	  printf("Digite el grado del término: "); scanf("%d",&h);
		     }
			 if(cantidadTerminos>=2){
		     	printf("\nDigite el valor de b: "); scanf("%f",&b);
		     	  printf("Digite el grado del término: "); scanf("%d",&i);
		     }
		     if(cantidadTerminos>=3){
		     	printf("\nDigite el valor de c: "); scanf("%f",&c);
		     	  printf("Digite el grado del término: "); scanf("%d",&j);
		     }
		     
		     printf("\nDigite el valor del termino independiente: "); scanf("%f",&n);
		     
		     if(cantidadTerminos>=1){
		     	printf("\nDigite el valor de d: "); scanf("%f",&d);
		     	  printf("Digite el grado del término: "); scanf("%d",&k);
		     }
		     if(cantidadTerminos>=2){
		     	printf("\nDigite el valor de e: "); scanf("%f",&e);
		     	  printf("Digite el grado del término: "); scanf("%d",&l);
		     }
		     if(cantidadTerminos>=3){
		     	printf("\nDigite el valor de f: "); scanf("%f",&f);
		     	  printf("Digite el grado del término: "); scanf("%d",&m);
		     }
		     
		     printf("\nDigite el valor del termino independiente: "); scanf("%f",&g);
		     
			 ejesCartesianos();
			 
			 for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 fx=(a*pow(x,h)+b*pow(x,i)+c*pow(x,j)+n)/(d*pow(x,k)+e*pow(x,l)+f*pow(x,m)+g);
			 putpixel(360+x*Dm,360-fx*Im,incolor);
	    	 } 
	    	 	do{if(!kbhit()){
			tecla=getch();	 
			for(float x=(-360/Dm);x<=(360/Dm);x+=0.001){
			 Dm=360/preDm;
	       	 fx=(a*pow(x,h)+b*pow(x,i)+c*pow(x,j)+n)/(d*pow(x,k)+e*pow(x,l)+f*pow(x,m)+g);
			putpixel(360+x*Dm,360-fx*Im,WHITE);}
			
			if(tecla=='w'){preDm-=1;preIm-=1;incremento--;
			Dm=360/preDm;
		   	for(float x=-360/Dm;x<=360/Dm;x+=0.001){
			 fx=(a*pow(x,h)+b*pow(x,i)+c*pow(x,j)+n)/(d*pow(x,k)+e*pow(x,l)+f*pow(x,m)+g);
		    putpixel(360+x*Dm,360-fx*Im,incolor);
	        }}
			 
			if(tecla=='s'){preDm+=1;preIm+=1;incremento++;
			Dm=360/preDm;
			for(float x=-360/Dm;x<=360/Dm;x+=0.001){
	    	 fx=(a*pow(x,h)+b*pow(x,i)+c*pow(x,j)+n)/(d*pow(x,k)+e*pow(x,l)+f*pow(x,m)+g);
		    putpixel(360+x*Dm,360-fx*Im,incolor);}}
            
			if(tecla=='a'){}
	    	} 
	       }while(tecla !='a');
	       VI=preDm-(incremento);
		   VI1=preIm-(incremento);
		   Dm1=360/VI;
		   Im1=360/VI1;
		   	ejesCartesianos();
			for(float x=-360/VI;x<=360/VI;x+=0.001){
	      	fx=(a*pow(x,h)+b*pow(x,i)+c*pow(x,j)+n)/(d*pow(x,k)+e*pow(x,l)+f*pow(x,m)+g);
		    putpixel(360+x*Dm1,360-fx*Im1,incolor);}
			 break;}
	        
			system("Cls");
			delay(500);
            printf("\n¿Desea incluir otra función? \n1. SI.\n2. NO.\n"); scanf("%d",&opcion2);
			switch(opcion2){
			case 1: agregarFuncion=1;
			incolor++;
			if(incolor==9){incolor==1;}
	      	system("Cls");
			break;
			case 2: agregarFuncion=0;	closegraph(); 
			system("Cls");
			printf("\nEXIT PROGRAM");//Cerrar la ventana con el grafico
		   exit(1);
			break;
			}
	    	} while(agregarFuncion==1); 
getch();//Función de la libreria conio.h, utilizada para evitar el cierre del programa hasta que el usuario lo indique
return 0;
}
