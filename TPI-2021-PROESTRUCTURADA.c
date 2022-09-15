#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct fecha{
    int dia;
    int mes;
    int anio;
    long t;
}fech;

struct cliente{
    char nombre[30];
    unsigned dni;
    char ape[30];
    struct fecha naci;
    char direccion[30];
    char correo[45];
    unsigned fijo;
    unsigned celular;
}clt;

struct factura{
    unsigned dni;
    char name[30];
    char ape[30];
    float importe;
    int renglon;
    char desservicio[100];
    struct fecha facturacion;
    struct fecha periodo;
    struct fecha vencimiento;
}fact;


struct serviciocable{
   unsigned codigo;
   float basico;
   float costo;
   char descripciom[100];

}cable;

struct serviciointernet{
   unsigned codigo;
   float monto;
   int megas;
}internet;


struct contrato
{
    unsigned codigo;
    char name[30];
    unsigned dni;
    char ape[30];
    char direccion[30];
    char correo[45];
    int megas;
    unsigned fijo;
    unsigned celular;
    struct fecha nmnto;
    char descripcion[100];
    float total;
    float tvbase;
    float costo_plan;
    float descuento;
    struct fecha  inicio;
    struct fecha  fin;
    struct fecha  firma;
}con;

struct datos{
   unsigned dni;
   int renglon;
   char descrip[100];
   float parcial;
   unsigned codigoservicio;
}dat;

void fecha();
void cliente();
void administrador();
void consultas();
void verclientes();
void registrarcliente();
void crearcontrato(unsigned );
void servicio();
void primerafactura(unsigned);
void verservicios(int);
void Nuevo_Servicio();
void iniciar(unsigned);
void Nuevo_servicio();
void vercontrato(unsigned);
void verfacturas(unsigned);
void servicioscontratados(unsigned);
void estadocliente();
void movientredosfechas();
int numerocodigo();
void mostrar();
void contratotxt(unsigned,int);
void disponibles();
void movi_anio_mes();
void servi_contratacion();
void modificacion();

int main(){
      int opc;
           system("cls");
           printf("\t-EMPSEI-\n-Cliente[1]\n-Admistrador[2]\n-Salir[3]\n-opcion:\t");
           fflush(stdin);
           scanf("%d",&opc);
           while(opc> 3|| opc<=0){
           printf("opcion incorrecta.\n");
           system("pause");
           system("cls");
           printf("\t-EMPSEI-\n-Cliente[1]\n-Admistrador[2]\n-Salir[3]\n-opcion:\t");
           scanf("%d",&opc);
           system("cls");
           }
           switch (opc)
           {
           case 1:
                 cliente(); break;
           case 2:
                 administrador(); break;
            case 3:
                   exit(-1); break;
		   }

}

void cliente(){
      int opc;
           system("cls");
           printf("bienvenido sr cliente.\n");
           printf("\t-Cliente-\n-Registrarse[1]\n-Volver atras[2]\n-opcion:\t");
           scanf("%d",&opc);
           system("cls");
           while (opc>3 || opc<=0)
           {
              printf("vuelva a ingresar una opcion. \n");
              system("pause");
              system("cls");
              printf("\t-Cliente-\n-Registrarse[1]\n-Volver atras[2]\n-opcion:\t");
              scanf("%d",&opc);
           }

           switch (opc)
           {
           case 1: registrarcliente();break;
           case 2: main(); break;
           }
}

void iniciar(unsigned dni){
FILE *ini;
char n[30];
int opc;
         
         if((ini=fopen("cliente.bin","rb"))!=NULL)
         {
           fread(&clt,sizeof(clt),1,ini);
           while (!feof(ini))
           {
              if (dni==clt.dni)
              {
                 printf("usuario encontrado\n");
                 system("pause");
                 system("cls");
                 printf("Bienvenido: %s \n",clt.nombre);
                 printf("1-crear contrato\n");
                 printf("2-vercontrato\n");
                 printf("3-ver facturas\n");
                 printf("4-servicios contratados \n");
                 printf("5 -volver atras\n");
                 scanf("%d",&opc);
                 system("cls");
              while (opc>5 || opc<=0)
               {
                 printf("vuelva a ingresar una opcion. \n");
                 system("pause");
                 system("cls");
                 printf("Bienvenido: %s \n",clt.nombre);
                 printf("1-crear contrato\n");
                 printf("2-vercontrato\n");
                 printf("3-ver facturas\n");
                 printf("4-servicios contratados \n");
                 printf("5 -volver atras\n");
                 scanf("%d",&opc);
              }
               switch (opc)
               {
               case 1: crearcontrato(dni); break;
               case 2: vercontrato (dni);break;
               case 3: verfacturas(dni); break;
               case 4: servicioscontratados(dni);break;
               case 5: main(); break;
               }

               }

               fread(&clt,sizeof(clt),1,ini);
                }
                  fclose(ini);
                    }else printf("no se pudo");

}

void registrarcliente(){
   FILE *nc;
   unsigned dni;
   int band=0;
          printf("ingrese el dni: \n");
          scanf("%u",&dni);

     if ((nc=fopen("cliente.bin","r+b"))!=NULL)
     {
        fread(&clt,sizeof(clt),1,nc);
        while (!feof(nc))
        {
           if (dni==clt.dni)
           {
              band=1;
              printf("el dni ya fue ingresado antes,inicie sesion:\n");
              iniciar(dni);
              
           }

         fread(&clt,sizeof(clt),1,nc);
        }
        fclose(nc);
     }else printf("no se pudo abrir el archivo.\n");
     if (band==0)
     {
       if ((nc=fopen("cliente.bin","a+b"))!=NULL) {
         printf("ingrese el nombre del cliente: \n");
        getchar();
        gets(clt.nombre);
        printf("ingrese apellido del cliente:\n");
        gets(clt.ape);
        clt.dni=dni;
        printf("ingrese direccion del cliente: \n");
        getchar();
        gets(clt.direccion);
        printf("ingrese el mail del cliente: \n");
        gets(clt.correo);
        printf("ingrese el fijo del cliente:\n");
        fflush(stdin);
        scanf("%u",&clt.fijo);
        printf("ingrese el celular del cliente:\n");
        scanf("%u",&clt.celular);
        printf("ingrese fecha de nacimiento: \n");
        fflush(stdin);
        scanf("%d",&clt.naci.dia);
        scanf("%d",&clt.naci.mes);
        scanf("%d",&clt.naci.anio);
        fwrite(&clt,sizeof(clt),1,nc);
        printf("cliente registrado. \n");
        fclose(nc);
     }else printf("no se pudo abrir el archivo.\n");

     }

    system("pause");
    main();
}

void crearcontrato(unsigned dni){
 FILE *c,*ca,*nc,*f,*in,*dt;
 int band=0,opc,n=0,ren=1,ncont;
 float tv=0,inet=0;
 unsigned cod;
              printf("Desea actualizar la fecha antes de continuar?\n[1]-si\n[2]-no\n :\t");
                    scanf("%i",&opc);
                    if (opc==1)
                    {
                       fecha();
                    }else if (opc==2) {
                        getch();
                    }
                    system("pause");

   if ((c=fopen("contrato.bin","a+b"))!=NULL) {
      con.descripcion[0]=0;
         if ((nc=fopen("cliente.bin","rb"))!=NULL)
         {
            fread(&clt,sizeof(clt),1,nc);
            while (!feof(nc))
            {
               if (dni==clt.dni)
               {
                band=1;
                printf("-contrato-\n");
                con.codigo=numerocodigo();
                ncont = con.codigo;
                con.total=0;
                con.celular=clt.celular;
                con.dni=clt.dni;
                con.fijo=clt.fijo;
                strcpy(con.ape,clt.ape);
                strcpy(con.direccion,clt.direccion);
                strcpy(con.correo,clt.correo);
                strcpy(con.name,clt.nombre);
                con.nmnto.dia= clt.naci.dia;
                con.nmnto.mes= clt.naci.mes;
                con.nmnto.anio= clt.naci.anio;
                printf("Que servicio desea:\n[1]-tv\n[2]-internet.\n[0]-para salir.\n: ");
                fflush(stdin);
                scanf("%i",&opc);
                do
                {
                 if (opc==1)
                 {
                  verservicios(opc);
                  printf("ingresar el codigo del producto que quiere contratar: \n");
                  scanf("%u",&cod);
                   if((ca=fopen("serviciocable.bin","rb"))!=NULL){
                       fread(&cable,sizeof(cable),1,ca);
                       while (!feof(ca))
                       {
                          if (cod==cable.codigo)
                          {
                             con.tvbase=cable.basico;
                             tv=tv+cable.costo;
                              if ((dt=fopen("data.bin","a+b"))!=NULL)
                              {
                                 dat.dni=clt.dni;
                                 dat.renglon=ren;
                                 strcpy(dat.descrip,cable.descripciom);
                                 dat.parcial=cable.costo;
                                 dat.codigoservicio=cod;
                                 fwrite(&dat,sizeof(dat),1,dt);
                                 fclose(dt);
                              }else printf("error al abrir\n");

                             strcat(con.descripcion,cable.descripciom);
                             strcat(con.descripcion,"\n");
                             ren++;
                          }
                          
                          fread(&cable,sizeof(cable),1,ca);
                       }
                   fclose(ca);
                 }else printf("error \n");

               }else if (opc==2 && n==0)
               {
                   n=1;
                   verservicios(opc);
                   getchar();
                   printf("ingresar el codigo del producto que quiere contratar: \n");
                   scanf("%u",&cod);
                   if((in=fopen("serviciointernet.bin","rb"))!=NULL){
                      fread(&internet,sizeof(internet),1,in);
                      while (!feof(in))
                      {
                        if (cod==internet.codigo)
                        {
                           con.megas=internet.megas;
                           con.costo_plan=internet.monto;
                        }

                        fread(&internet,sizeof(internet),1,in);
                      }


                    fclose(in);
                 }else printf("error al abrir\n");

               }
                  printf("Que servicio desea:\n[1]-tv\n[2]-internet.\n[0]-para salir.\n: ");
                  fflush(stdin);
                  scanf("%i",&opc);
                } while (opc != 0);

                 con.total=con.costo_plan+con.tvbase+tv;

                 if (con.total>=3000 && con.total<=4000)
                    con.descuento=(con.total*0.2);
                 else if (con.total>=4001 && con.total<=6000)
                    con.descuento=(con.total*0.25);
                 else if (con.total>6000)
                    con.descuento=(con.total*0.3);

               }

               fread(&clt,sizeof(clt),1,nc);
            }
            fclose(nc);
         }else printf("error al abrir\n");

          if (band==0)
            {
               printf("el dni no esta registrado.\n");
            }

           if ((f=fopen("fecha.bin","rb"))!=NULL)
           {
              fread(&fech,sizeof(fech),1,f);
              con.firma.dia= fech.dia;
              con.firma.mes= fech.mes;
              con.firma.anio=fech.anio;
              con.firma.t= ((fech.anio*10000)+(fech.mes*100)+fech.dia);
              con.inicio.dia= fech.dia;
              con.inicio.mes= fech.mes;
              con.inicio.anio= fech.anio;
              con.inicio.t=((fech.anio*10000)+(fech.mes*100)+fech.dia);

            if (con.total<3000){
               if (fech.mes==12)
               {
                    if (fech.dia==1)
                    {
                       con.fin.dia=31;
                       con.fin.mes=fech.mes;
                       con.fin.anio=fech.anio;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }else if (fech.dia != 1)
                    {
                       con.fin.dia=fech.dia-1;
                       con.fin.mes=fech.mes+1;
                       con.fin.anio=fech.anio+1;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }
               }else if (fech.mes<12)
               {
                   if (fech.dia==1)
                    {
                       con.fin.dia=31;
                       con.fin.mes=fech.mes;
                       con.fin.anio=fech.anio;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }else if (fech.dia != 1)
                    {
                       con.fin.dia=fech.dia-1;
                       con.fin.mes=fech.mes+1;
                       con.fin.anio=fech.anio;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }
               }
               
            }
              if (con.total>=3000)
              {
                 if (fech.mes>6)
                 {
                    if (fech.dia==1)
                    {
                       con.fin.dia=31;
                       con.fin.mes=fech.mes-6;
                       con.fin.anio=fech.anio+1;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }else if (fech.dia != 1)
                    {
                       con.fin.dia=fech.dia-1;
                       con.fin.mes=fech.mes-6;
                       con.fin.anio=fech.anio+1;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }

                 }else if (fech.mes<6)
                 {
                    if (fech.dia==1)
                    {
                       con.fin.dia=31;
                       con.fin.mes=fech.mes+6;
                       con.fin.anio=fech.anio;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }else if (fech.dia != 1)
                    {
                       con.fin.dia=fech.dia-1;
                       con.fin.mes=fech.mes+6;
                       con.fin.anio=fech.anio;
                       con.fin.t=((con.fin.anio*10000)+(con.fin.mes*100)+con.fin.dia);
                    }

                 }

              }

              fclose(f);
           }else printf("error \n");
           fwrite(&con,sizeof(con),1,c);

           fclose(c);
         }else printf("no se pudo abrir el contrato.\n");
         printf("contrato creado. \n");
        primerafactura(dni);
        contratotxt(dni,ncont);
      system("pause");
      main();
}

void administrador(){
int opc;
           system("cls");
           printf("Administrador.\n");
           printf("\t-Sistema-\n-Fecha[1]\n-Servicios[2]\n-Consultas[3]\n-Ver Clientes[4]\n-Ver todos los contratos[5]\n--Volver atras[6]\nopcion:\t");
           scanf("%d",&opc);
           system("cls");
           while (opc>6 || opc<=0)
           {
              printf("vuelva a ingresar una opcion. \n");
              system("pause");
              system("cls");
              printf("\t-Sistema-\n-Fecha[1]\n-Servicios[2]\n-Consultas[3]\n-Ver Clientes[4]\n-Ver todos los contratos[5]\n--Volver atras[6]\nopcion:\t");
              scanf("%d",&opc);
           }

           switch (opc)
           {
           case 1: fecha(); break;
           case 2: servicio();break;
           case 3: consultas(); break;
           case 4: verclientes();break;
           case 5: mostrar(); break;
           case 6: main();break;
           }
}

void consultas(){
   int opc;
           system("cls");
         printf("\t-Listados-Consultas-\n\n");
		   printf("[1]-Clientes Activos/No Activos\n");
		   printf("[2]-Servicios Contratados\n");
		   printf("[3]-Servicios Contratados entre Dos Fechas\n");
		   printf("[4]-Servicio +Contratacion / -Contratacion\n");
		   printf("[5]-Movimientos Alta/Baja segun Mes\n");
         printf("[6]-Volver atras\n-opcion: [ ]\b\b");
		   scanf("%d",&opc);
           while(opc>6 || opc<=0){
           printf("opcion incorrecta.\n");
           system("pause");
           system("cls");
           printf("\t-Listados-Consultas-\n\n");
		     printf("[1]-Clientes Activos/No Activo\n");
		     printf("[2]-Servicios Contratados\n");
		     printf("[3]-Servicios Contratados entre Dos Fechas\n");
		     printf("[4]-Servicio +Contratacion / -Contratacion\n");
		     printf("[5]-Movimientos Alta/Baja segun Mes\n");
           printf("[6]-Volver atras\n-opcion: [ ]\b\b");
           scanf("%d",&opc);
           system("cls");

           }
           switch (opc)
           {
            case 1: estadocliente(); break;
            case 2: disponibles(); break;
         	case 3: movientredosfechas();break;
            case 4: servi_contratacion(); break;
            case 5: movi_anio_mes(); break;
            case 6: main(); break;

           }

}

void servicio(){
  int opc;
           system("cls");
           printf("\t-SERVICIOS-\n-Nuevo[1]\n-Modificar[2]\n-Volver atras[3]\n-opcion:\t");
           scanf("%d",&opc);
           while(opc>4 || opc<=0){
           printf("opcion incorrecta.\n");
           system("pause");
           system("cls");
           printf("\t-SERVICIOS-\n-Nuevo[1]\n-Modificar[2]\n-Volver atras[3]\n-opcion:\t");
           scanf("%d",&opc);
           system("cls");

           }
           switch (opc)
           {
           case 1: Nuevo_servicio(); break;
           case 2: modificacion(); break;
           case 3: main(); break;
           }
            system("pause");
    main();
}

void verservicios(int opc){
  FILE *ca,*in;

           while (opc>2 || opc<=0)
           {
               printf("opcion incorrecta.\n");
               system("pause");
               system("cls");
               printf("Ver costos:\n[1]-tv\n[2]-internet.\n");
               scanf("%i",&opc);
               system("cls");
           }
           switch (opc)
           {
           case 1:
                   if((ca=fopen("serviciocable.bin","rb"))!=NULL){
                   printf("codigo:\tdescripcion:\tcosto:\tbasico:\n\n");
                   fread(&cable,sizeof(cable),1,ca);
                   while (!feof(ca))
                  {
                  printf("%u\t%s\t%0.2f\t%0.2f \n",cable.codigo,cable.descripciom,cable.costo,cable.basico);

                  fread(&cable,sizeof(cable),1,ca);
                       }
                    fclose(ca);
                 }else printf("error \n");break;

           case 2:
                 if((in=fopen("serviciointernet.bin","rb"))!=NULL){
                  printf("codigo:\tmegas:\tcosto:\n\n");
                  fread(&internet,sizeof(internet),1,in);
                  while (!feof(in))
                  {
                  printf("%u\t%i\t %0.2f \n",internet.codigo,internet.megas,internet.monto);
                  fread(&internet,sizeof(internet),1,in);
                      }
                   fclose(in);
                 }else printf("error al abrir\n"); break;
           }
               printf("\n \n \n");
               printf("-Promociones Disponibles-\n");
               printf("Adquiriendo entre 3000 y 4000 de monto, obtiene un 20% \n");
               printf("Adquiriendo entre 4001 y 6000 de monto, obtiene un 25% \n");
               printf("Adquiriendo mas de 6000 de monto, obtiene un 30% \n");

     system("pause");
     system("cls");
}

void verclientes(){
FILE *nc;
         
     if ((nc=fopen("cliente.bin","rb"))!=NULL)
     {
     	system("cls");
		printf("\n\t\t    ==> LISTADO DE CLIENTES REGISTRADOS <==\n");
		
		printf(" --------------------------------------------------------------------------------------------------------\n");
		printf("%6s\t\t%-15.15s%-15s%-20s%-15s%-15s%-15s\n","DNI","APELLIDO","NOMBRE","DIRECCION","CELULAR","FIJO","MAIL");
		printf(" --------------------------------------------------------------------------------------------------------\n");
       fread(&clt,sizeof(clt),1,nc);
       while (!feof(nc))
       {
         
         printf("%8u\t%-12s%-18s\t%-18s%12u%12u%-10s%\n",clt.dni,clt.ape,clt.nombre,clt.direccion,clt.celular,clt.fijo,clt.correo);
         
         fread(&clt,sizeof(clt),1,nc);
       }
        fclose(nc);printf("\n");
     }else 
          printf("error\n");

     system("pause");
     main();

}

void Nuevo_servicio(){
 FILE *ca,*in;
 int opc;

          printf("ingrese que tipo de servicio quiere agregar: \n");
          printf("-Cable[1]\n-Internet[2]-\n:");
          scanf("%d",&opc);
          if (opc==1)
          {
                 printf("Cable.\n");
                 if((ca=fopen("serviciocable.bin","a+b"))!=NULL){
                 printf("ingrese el precio basico de Tv: \n");
                 scanf("%f",&cable.basico);
                 printf("ingrese el nombre del producto: \n");
                 getchar();
                 gets(cable.descripciom);
                 printf("ingrese precio adcional: \n");
                 scanf("%f",&cable.costo);
                 printf("ingrese codigo del producto:\n");
                 fflush(stdin);
                 scanf("%u",&cable.codigo);
                 fwrite(&cable,sizeof(cable),1,ca);
                 fclose(ca);
                 }else printf("error al abrir \n");

          }else if (opc==2)
          {
                 printf("Internet. \n");
                 if((in=fopen("serviciointernet.bin","a+b"))!=NULL){
                 printf("ingrese codigo del producto:\n");
                 fflush(stdin);
                 scanf("%u",&internet.codigo);
                 printf("ingrese la cantidad de megas:\n");
                 scanf("%d",&internet.megas);
                 printf("ingrese el costo de internet.\n");
                 scanf("%f",&internet.monto);
                 fwrite(&internet,sizeof(internet),1,in);
                 fclose(in);
          }else printf("error al abrir archivo \n");

          }

   servicio();
}

void vercontrato(unsigned dni){
FILE *c;
     if ((c=fopen("contrato.bin","rb"))!=NULL)
     {
       fread(&con,sizeof(con),1,c);
       while (!feof(c))
       {
       	if(dni == con.dni){
       		printf("codigo: %u \n",con.codigo);
     	      printf("nombre: %s \n",con.name);
     	      printf("apellido: %s \n",con.ape);
     	      printf("Dni: %u \n",con.dni);
     	      printf("Direccion: %s \n",con.direccion);
       		printf("telefono fijo: %u \n",con.fijo);
       		printf("correo: %s \n",con.correo);
         	printf("celular: %u \n",con.celular);
         	printf("cantidad de megas:%i \n",con.megas);
         	printf("costo de internet: %.2f \n",con.costo_plan);
         	printf("descripcion tv: %s \n",con.descripcion);
         	printf("fecha de firma: %d/%d/%d \n",con.firma.dia,con.firma.mes,con.firma.anio);
         	printf("fecha de nacimiento: %d/%d/%d \n",con.nmnto.dia,con.nmnto.mes,con.nmnto.anio);
            printf("descuento en el contrato: %.2f \n",con.descuento);
           	printf("costo total de contrato: %.2f \n",con.total);
            printf("fecha de inicio de servicio: %d/%d/%d \n",con.inicio.dia,con.inicio.mes,con.inicio.anio);
            printf("fecha de fin del servicio: %d/%d/%d \n",con.fin.dia,con.fin.mes,con.fin.anio);
		}
         fread(&con,sizeof(con),1,c);
       }
        fclose(c);
     }else printf("error");

     system("pause");
     main();
}

  void verfacturas(unsigned dni){
   FILE *fp,*fpdat,*fpcont;
   int renglon=0;
    if((fp=fopen("facturas.bin","rb"))!=NULL){
        fread(&fact,sizeof(fact),1,fp);
        while (!feof(fp)){
            if(dni == fact.dni){
                if((fpdat=fopen("data.bin","rb"))!=NULL){
                     fread(&dat,sizeof(dat),1,fpdat);
                     while(!feof(fpdat)){
                     if(dni == dat.dni){
                         printf("\nRenglon: %d\n",dat.renglon);
                         printf("Descripcion: %s\n",dat.descrip);
                         printf("Importe parcial: %.2f\n",dat.parcial);
                         renglon=dat.renglon;
                    }
                     fread(&dat,sizeof(dat),1,fpdat);
                    }
                    fclose(fpdat);
                 }else printf("\nError: arch data");
                if((fpcont=fopen("contrato.bin","rb"))!=NULL){
                    fread(&con,sizeof(con),1,fpcont);
                    while(!feof(fpcont)){
                        if(dni == con.dni && con.megas > 0){
                            printf("\nRenglon: %d\n",renglon+1);
                            printf("Megas: %d\n",con.megas);
                            printf("Importe parcial: %.2f\n",con.costo_plan);
                        }
                        
                        fread(&con,sizeof(con),1,fpcont);
                    }
                    
                    fclose(fpcont);
                }else printf("\nError: arch contrato");
                printf("\nImporte Total: %0.2f\n",con.total);
                printf("Fecha de facturacion: %d / %d / %d\n",con.firma.dia,con.firma.mes,con.firma.anio);
                printf("Fecha de vencimiento: %d / %d / %d\n",fact.vencimiento.dia,fact.vencimiento.mes,fact.vencimiento.anio);
                printf("Periodo: %d / %d / %d  hasta %d / %d / %d\n",con.firma.dia,con.firma.mes,con.firma.anio,con.fin.dia,con.fin.mes,con.fin.anio);
            }
            fread(&fact,sizeof(fact),1,fp);
        }
        fclose(fp);
    }else printf("\nError: arch facturas.");

}


void servicioscontratados(unsigned dni){
	FILE *fp;
	if((fp=fopen("contrato.bin","rb"))!=NULL){
		fread(&con,sizeof(con),1,fp);
		while(!feof(fp)){
			if(dni==con.dni){
				printf("Servicios de cable contratados: %s\n",con.descripcion);
				printf("Precio del cable basico %0.2f\n",con.tvbase);
				printf("Precio total de los servicios contratados: %0.2f\n",con.total);
				printf("Precio internet de %d megas = %0.2f\n",con.megas,con.costo_plan);
			}
			fread(&con,sizeof(con),1,fp);
		}


	}
   system("pause");
	main();
}

void fecha () {
	int dd,mm,aaaa,op,t;
	FILE *fp;
	system("cls");
	if((fp=fopen("fecha.bin","w+b"))!=NULL){
		fread(&fech,sizeof(fech),1,fp);
		printf("\t-Fecha-\n-Ingresar la fecha del dia:\n-");
		do{
		
			printf("-Dia: ");
			scanf("%d",&dd);
			fflush(stdin);
			if (dd>31 || dd<=0 )
				printf("Ingresar Dia valido\n");
		}while(dd>31 || dd<=0 );
		
		do{
		
		printf("-Mes: ");
		scanf("%d",&mm);
		fflush(stdin);
			if (mm>=13||mm<=0)
				printf("Ingresar Mes valido\n");
		}while(mm>=13||mm<=0&&mm<fech.mes);
		
		do{
		printf("-Anio: ");
		scanf("%d",&aaaa);
		fflush(stdin);
			if (aaaa>2030||aaaa<2021 && aaaa<fech.anio)
				printf("Ingresar Anio valido\n");
	}	while(aaaa>2040||aaaa<2021&&aaaa<fech.anio);
		
		t=(aaaa*10000)+(mm*100)+dd;
		fclose(fp);
	}else printf("No se pudo abrir el archivo de fecha");

	if(t<fech.t){
		printf("No se pude actualizar a fechas anteriore a la actual\n");
		system("pause");
		fecha();
	}
	system("cls");
	printf("-La fecha ingresada es %d / %d / %d\n-Correcto.\n-Si[1]\n-No[2] ",dd,mm,aaaa);
	scanf("%d",&op);
	if(op==1){
		if((fp=fopen("fecha.bin","w+b"))!=NULL){
			fech.dia=dd;
			fech.mes=mm;
			fech.anio=aaaa;
			fech.t=(aaaa*10000)+(mm*100)+dd;
			fwrite(&fech,sizeof(fech),1,fp);
			fclose(fp);
		}
	} else if(op==2){
				fecha();
			}
	system("pause");
	main();
}

void primerafactura(unsigned dni){
FILE *fac,*c,*f;
int ban=0;
         if ((fac=fopen("facturas.bin","a+b"))!=NULL)
         {
            if ((c=fopen("contrato.bin","rb"))!=NULL)
            {
               fread(&con,sizeof(con),1,c);
               while (!feof(c))
               {
                  if (dni==con.dni)
                  {
                  	ban=1;
                     fact.dni=dni;
                     fact.facturacion.dia=con.firma.dia;
                     fact.facturacion.mes=con.firma.mes;
                     fact.facturacion.anio=con.firma.anio;
                     fact.facturacion.t=con.firma.t;
                      if ((f=fopen("fecha.bin","rb"))!=NULL){
                          fread(&fech,sizeof(fech),1,f);
                           if (fech.mes==12 || fech.dia==1) {
                            fact.periodo.dia=31;
                            fact.periodo.mes=1;
                            fact.periodo.anio= fech.anio+1;
                            fact.periodo.t=((fact.periodo.anio*10000)+(fact.periodo.mes*100)+fact.periodo.dia);
                            fact.vencimiento.dia=10;
                            fact.vencimiento.mes=fech.mes+1;
                            fact.vencimiento.anio= fech.anio+1;
                            fact.vencimiento.t=((fact.vencimiento.anio*10000)+(fact.vencimiento.mes*100)+fact.vencimiento.dia);
                            
                           }else if (fech.mes<12 || fech.dia != 1){
                            fact.periodo.dia=fech.dia-1;
                            fact.periodo.mes=fech.mes+1;
                            fact.periodo.anio= fech.anio;
                            fact.periodo.t=((fact.periodo.anio*10000)+(fact.periodo.mes*100)+fact.periodo.dia);
                            fact.vencimiento.dia=fact.periodo.dia+10;
                            fact.vencimiento.mes=fech.mes+1;
                            fact.vencimiento.anio= fech.anio;
                            fact.vencimiento.t=((fact.vencimiento.anio*10000)+(fact.vencimiento.mes*100)+fact.vencimiento.dia);
                            }

                          fclose(f);
                      }else printf("error al abrir el archivo\n") ;

                      fact.importe=con.total;

                  }

                  fread(&con,sizeof(con),1,c);
               }
				if(ban==0){
					printf("No se ha registrado el dni");
				}
              fclose(c);
            }else printf("no se pudo abrir \n");

            fwrite(&fact,sizeof(fact),1,fac);
            fclose(fac);
         }else
              printf("error al abrir factura.\n");
}

void estadocliente() {
   FILE *c,*f;
   int esta=0;
   unsigned dni;
               printf("ingrese el dni para ver estado:\n");
               scanf("%u",&dni);
               if ((c=fopen("contrato.bin","rb"))!=NULL)
               {
                  fread(&con,sizeof(con),1,c);

                  while (!feof(c))
                  {
                     if (dni==con.dni)
                     {
                        esta=1;
                        if ((f=fopen("fecha.bin","rb"))!=NULL){
                           fread(&fech,sizeof(fech),1,f);

                           if (fech.t>con.fin.t)
                           {
                               printf("-Cliente no Activo-\n");
                               printf("nombre: %s \n",con.name);
                               printf("apellido: %s \n",con.ape);
                               printf("Dni: %u \n",con.dni);
                               printf("Direccion: %s \n",con.direccion);
                               printf("telefono fijo: %u \n",con.fijo);
                               printf("correo: %s \n",con.correo);
                               printf("celular: %u \n",con.celular);
                               printf("fecha de fin del servicio: %d/%d/%d \n",con.fin.dia,con.fin.mes,con.fin.anio);

                           }else if(fech.t<con.fin.t)
                                    printf("-Cliente  Activo-\n");
                                    printf("nombre: %s \n",con.name);
                                    printf("apellido: %s \n",con.ape);
                                    printf("Dni: %u \n",con.dni);
                                    printf("Direccion: %s \n",con.direccion);
                                    printf("telefono fijo: %u \n",con.fijo);
                                    printf("correo: %s \n",con.correo);
                                    printf("celular: %u \n",con.celular);
                                    printf("fecha de fin del servicio: %d/%d/%d \n",con.fin.dia,con.fin.mes,con.fin.anio);
                           fclose(f);
                        }else printf("error al abrir \n");

                         }


                    fread(&con,sizeof(con),1,c);
                  }
                  if (esta==0)
                  {
                     printf("no existe ese dni\n");
                  }
                  fclose(c);
               }else printf("error al abrir \n");

   system("pause");
   consultas();
}

void movientredosfechas(){
   FILE *fp,*c;
	int di,mi,ai,df,mf,af;
	long ti,tf;
	printf("Ingresar desde que fecha:\nDia: ");
	scanf("%d",&di);
	printf("Mes: ");
	scanf("%d",&mi);
	printf("Year: ");
	scanf("%d",&ai);
	printf("Hasta que fecha: \nDia: ");
	scanf("%d",&df);
	printf("Mes: ");
	scanf("%d",&mf);
	printf("Year: ");
	scanf("%d",&af);
	printf("Buscar desde %d / %d / %d hasta %d / %d / %d ",di,mi,ai,df,mf,af);
	ti=(ai*10000)+(mi*100)+di;
	tf=(af*10000)+(mf*100)+df;
	printf("Desde %ld hasta %ld",ti,tf);
    if ((c=fopen("contrato.bin","rb"))!=NULL){
      fread(&con,sizeof(con),1,c);
      while (!feof(c))
      {
         if(con.inicio.t>=ti&&con.inicio.t<=tf){
             printf("\ncodigo:%u\ndescripcion:%s\ntotal:%0.2f\ndescuenti:%0.2f \t \n",con.codigo,con.descripcion,con.total,con.descuento);

         }
       fread(&con,sizeof(con),1,c);
      }
         fclose(c);
    }else printf("error al abrir archivo.\n");

    system("pause");
    consultas();
}


void mostrar() {
FILE *c;
     if ((c=fopen("contrato.bin","rb"))!=NULL)
     {
       fread(&con,sizeof(con),1,c);
       while (!feof(c))
       {
               printf("codigo: %u \n",con.codigo);
               printf("nombre: %s \n",con.name);
               printf("apellido: %s \n",con.ape);
               printf("Dni: %u \n",con.dni);
               printf("Direccion: %s \n",con.direccion);
               printf("telefono fijo: %u \n",con.fijo);
               printf("correo: %s \n",con.correo);
               printf("celular: %u \n",con.celular);
               printf("cantidad de megas:%i \n",con.megas);
               printf("costo de internet: %.2f \n",con.costo_plan);
               printf("descripcion tv: %s \n",con.descripcion);
               printf("fecha de firma: %d/%d/%d \n",con.firma.dia,con.firma.mes,con.firma.anio);
               printf("fecha de nacimiento: %d/%d/%d \n",con.nmnto.dia,con.nmnto.mes,con.nmnto.anio);
               printf("descuento en el contrato: %.2f \n",con.descuento);
               printf("costo total de contrato: %.2f \n",con.total);
               printf("fecha de inicio de servicio: %d/%d/%d \n",con.inicio.dia,con.inicio.mes,con.inicio.anio);
               printf("fecha de fin del servicio: %d/%d/%d \n",con.fin.dia,con.fin.mes,con.fin.anio);

         fread(&con,sizeof(con),1,c);
       }
        fclose(c);
     }else printf("error");

     system("pause");
     main();

}

int numerocodigo(){
  int nc=99;
    FILE *fp;
    if((fp=fopen("nrocontrol.bin","r+b"))!=NULL){
        fread(&nc,sizeof(int),1,fp);
        nc++;
            fseek(fp,sizeof(int)*(-1),SEEK_CUR);
            fwrite(&nc,sizeof(int),1,fp);
            fclose(fp);
    }else if((fp=fopen("nrocontrol.bin","w+b"))!=NULL){
                fread(&nc,sizeof(int),1,fp);
                nc++;
                fseek(fp,sizeof(int)*(-1),SEEK_CUR);
                fwrite(&nc,sizeof(int),1,fp);
                fclose(fp);
            }else printf("No se pudo abrir el archivo");
    return (nc);

}

void contratotxt(unsigned dni,int nc){
FILE *fp,*fptxt;
    char apellidonombre[60];
    if((fp=fopen("contrato.bin","rb"))!=NULL){
        fread(&con,sizeof(con),1,fp);
        while(!feof(fp)){
        	if(dni == con.dni && nc == con.codigo){
        		      strcpy(apellidonombre,con.ape);
            	   strcat(apellidonombre,con.name);
            	   strcat(apellidonombre,".txt");
                  printf("Cliente: %s",apellidonombre);
            	if((fptxt=fopen(apellidonombre,"at"))!=NULL){
                	fprintf(fptxt,"codigo: %u \n",con.codigo);
               	fprintf(fptxt,"nombre: %s \n",con.name);
                	fprintf(fptxt,"apellido: %s \n",con.ape);
                	fprintf(fptxt,"Dni: %u \n",con.dni);
                	fprintf(fptxt,"Direccion: %s \n",con.direccion);
                	fprintf(fptxt,"telefono fijo: %u \n",con.fijo);
                	fprintf(fptxt,"correo: %s \n",con.correo);
                	fprintf(fptxt,"celular: %u \n",con.celular);
                	fprintf(fptxt,"cantidad de megas:%i \n",con.megas);
                	fprintf(fptxt,"costo de internet: %.2f \n",con.costo_plan);
                	fprintf(fptxt,"descripcion tv: %s",con.descripcion);
                	fprintf(fptxt,"fecha de firma: %d/%d/%d \n",con.firma.dia,con.firma.mes,con.firma.anio);
               	fprintf(fptxt,"fecha de nacimiento: %d/%d/%d \n",con.nmnto.dia,con.nmnto.mes,con.nmnto.anio);
                  fprintf(fptxt,"descuento en el contrato: %.2f \n",con.descuento);
                  fprintf(fptxt,"costo total de contrato: %.2f \n",con.total);
                  fprintf(fptxt,"fecha de inicio de servicio: %d/%d/%d \n",con.inicio.dia,con.inicio.mes,con.inicio.anio);
                  fprintf(fptxt,"fecha de fin del servicio: %d/%d/%d \n",con.fin.dia,con.fin.mes,con.fin.anio);
                  printf("codigo: %u \n",con.codigo);
                  printf("nombre: %s \n",con.name);
                  printf("apellido: %s \n",con.ape);
                  printf("Dni: %u \n",con.dni);
                  printf("Direccion: %s \n",con.direccion);
                  printf("telefono fijo: %u \n",con.fijo);
                  printf("correo: %s \n",con.correo);
                  printf("celular: %u \n",con.celular);
                  printf("cantidad de megas:%i \n",con.megas);
                  printf("costo de internet: %.2f \n",con.costo_plan);
                  printf("descripcion tv: %s \n",con.descripcion);
                  printf("fecha de firma: %d/%d/%d \n",con.firma.dia,con.firma.mes,con.firma.anio);
                  printf("fecha de nacimiento: %d/%d/%d \n",con.nmnto.dia,con.nmnto.mes,con.nmnto.anio);
                  printf("descuento en el contrato: %.2f \n",con.descuento);
                  printf("costo total de contrato: %.2f \n",con.total);
                  printf("fecha de inicio de servicio: %d/%d/%d \n",con.inicio.dia,con.inicio.mes,con.inicio.anio);
                  printf("fecha de fin del servicio: %d/%d/%d \n",con.fin.dia,con.fin.mes,con.fin.anio);
				}else printf("NO se creo el txt.");
            }
            fread(&con,sizeof(con),1,fp);
        }

    }else printf("\nError: arch contrato.");
    system("pause");
    exit(-1);
}


void movi_anio_mes(){
FILE *c,*fac;
int d,m,a,opc;
long time;
   
            printf("ingrese el mes: "); scanf("%d",&m);
            printf("ingrese el anio: ");scanf("%d",&a);
            
        while (a<=0 || m<1 || m>12) {
            printf("la fecha es invalida!!");
            printf("ingrese el mes: "); scanf("%d",&m);
            printf("ingrese el anio: ");scanf("%d",&a);
        }
         
          printf("ingrese:\n1[alta]\n2[baja]:\n");
          scanf("%i",&opc);

          if ((c=fopen("contrato.bin","rb"))!=NULL)
          {
            fread(&con,sizeof(con),1,c);
            while (!feof(c))
            {
                    if (opc==1)
                    {
                      if (con.fin.anio<a&&con.fin.mes<m)
                      {
                         printf("-Altas-\n");
                         printf("codigo: %u \n",con.codigo);
                         printf("nombre: %s \n",con.name);
                         printf("apellido: %s \n",con.ape);
                         printf("Dni: %u \n",con.dni);
                         printf("cantidad de megas:%i \n",con.megas);
                         printf("costo de internet: %.2f \n",con.costo_plan);
                         printf("descripcion tv: %s \n",con.descripcion);
                      }
                       
                    }else if (opc==2)
                    {
                      if (con.fin.anio>a&&con.fin.mes>m)
                      {
                         printf("Bajas \n");
                         printf("codigo: %u \n",con.codigo);
                         printf("nombre: %s \n",con.name);
                         printf("apellido: %s \n",con.ape);
                         printf("Dni: %u \n",con.dni);
                         printf("cantidad de megas:%i \n",con.megas);
                         printf("costo de internet: %.2f \n",con.costo_plan);
                         printf("descripcion tv: %s \n",con.descripcion);
                      }
                    }
             fread(&con,sizeof(con),1,c);
            }
             fclose(c);
          }else printf("error al abrir archivo\n");
          

    system("pause \n");
    consultas();
}


void servi_contratacion(){
   FILE *fp,*fpservi;
    int aux=0,mayor=0,menor=100;
    unsigned servimayor,servimenor;
    char descripmayor[40],descripmenor[40];
    if((fpservi=fopen("serviciocable.bin","rb"))!=NULL){
        fread(&cable,sizeof(cable),1,fpservi);
        while(!feof(fpservi)){

            if((fp=fopen("data.bin","rb"))!=NULL){
                fread(&dat,sizeof(dat),1,fp);
                while(!feof(fp)){
                    if(cable.codigo==dat.codigoservicio){
                        aux++;
                    }
                    fread(&dat,sizeof(dat),1,fp);
                }
                if(aux > mayor){
                    mayor=aux;
                    servimayor=cable.codigo;
                    strcpy(descripmayor,cable.descripciom);
                }
                if(aux < menor){
                    menor = aux;
                    servimenor = cable.codigo;
                    strcpy(descripmenor,cable.descripciom);
                }
             fclose(fp);
            }else printf("error al abrir archivo.\n");
            fread(&cable,sizeof(cable),1,fpservi);
        }
           
        fclose(fpservi);
    }else printf("no se pudo abrir el archivo.\n");
    printf("Servicio mas contratado: %u %s",servimayor,descripmayor);
    printf("\tServicio menos contratado %u %s",servimenor,descripmenor);

}

void modificacion(){
    FILE *ca,*in;
    int button,existe=0;
    unsigned cod;
    float costo;
            printf("\t-Modificar Costo de Servicio-\n[1]cable\n[2]internet\n:");
            scanf("%d",&button);
            if (button==1)
            {
                printf("ingrese el codigo del producto a modificar.\n");
                fflush(stdin);
                scanf("%u",&cod);
                if ((ca=fopen("serviciocable.bin","r+b"))!=NULL)
                {
                    fread(&cable,sizeof(cable),1,ca);

                    while (!feof(ca))
                    {
                       if (cod==cable.codigo)
                       {
                             existe=1;
                             printf("%u %s %0.2f\n",cable.codigo,cable.descripciom,cable.costo);
                             printf("ingrese el costo nuevo: ");
                             scanf("%f",&cable.costo);
                             fseek(ca,sizeof(cable)*(-1),SEEK_CUR);
                             fwrite(&cable,sizeof(cable),1,ca);
                             fseek(ca,sizeof(cable),SEEK_END);
                       }
                       
                      fread(&cable,sizeof(cable),1,ca);
                    }

                    if (existe==0)
                    {
                        printf("no esta disponible ese producto \n");
                    }

                    fclose(ca);
                }else printf("error al abrir el archivo\n");
                
            }else if (button==2)
            {
                printf("ingrese el codigo del producto a modificar.\n");
                fflush(stdin);
                scanf("%u",&cod);
                if ((in=fopen("serviciointernet.bin","r+b"))!=NULL)
                {
                    fread(&internet,sizeof(internet),1,in);

                    while (!feof(in))
                    {
                       if (cod==internet.codigo)
                       {
                             existe=1;
                             printf("%u %i %0.2f\n",internet.codigo,internet.megas,internet.monto);
                             printf("ingrese el costo nuevo: ");
                             scanf("%f",&internet.monto);
                             fseek(in,sizeof(internet)*(-1),SEEK_CUR);
                             fwrite(&internet,sizeof(internet),1,in);
                             fseek(in,sizeof(internet),SEEK_END);
                       }
                       
                      fread(&internet,sizeof(internet),1,in);
                    }

                    if (existe==0)
                    {
                        printf("no esta disponible ese producto \n");
                    }

                    fclose(in);
                }else printf("error al abrir el archivo\n");
                

            }   
             
        system("pause");
	servicio();
}

void disponibles(){
    FILE *fp,*fp1;
    
    if((fp=fopen("serviciocable.bin","rb"))!=NULL){
        printf("Servicios de cable.\n");
        fread(&cable,sizeof(cable),1,fp);
        while(!feof(fp)){
            printf("Descripcion: %s\n",cable.descripciom);
            printf("Codigo: %u\n",cable.codigo);
            printf("Costo: %.2f\n\n",cable.costo);
            fread(&cable,sizeof(cable),1,fp);
        }
    fclose(fp);
    }else printf("No se pudo abrir el archivo servicio cable");

    if((fp1=fopen("serviciointernet.bin","rb"))!=NULL){
        printf("Servicios de Internet.\n");
        fread(&internet,sizeof(internet),1,fp1);
        while(!feof(fp1)){
            printf("Megas: %d\n",internet.megas);
            printf("Codigo: %u\n",internet.codigo);
            printf("Costo: %.2f\n\n",internet.monto);
            fread(&internet,sizeof(internet),1,fp1);
        }
        fclose(fp1);
    }else printf("No se pudo abrir el archivo servicio cable");
}

