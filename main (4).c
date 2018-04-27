#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const int L = 100;
int cantClientes = 0;
int cantEmpleados = 0;
int cantProveedores = 0;
int cantProductos = 0;
int cantVentas = 0;
int cantCompras = 0;
int opcion;

// estructura clientes
struct Cliente{
	int id;
	char nombre[30];
	int cedula;
	char direccion[30];
	char telefono[30];
}clientes[100];

// estructura productos
struct producto{
    int CgasolinaExtra;
    int CgasolinaCorriente;
    int CACPM;
    int CAceiteParaMotos;
    int CaceiteParaCarros;
    int Clubricantes;
    int CbrillaAutos;
}product={100,100,100,100,100,100,100};

//estructura proveedores
struct proveedor{
    int id;
    char nombre[30];
    int cedula;
    char telefono[30];
    char direccion[30];
    int ganancias;
}proveedores[100];

//estructura empleados

struct empleado{
    int id;
    char nombre[30];
    int cedula;
    char telefono[30];
    char direccion[30];
    char usuario[30];
    char contrasena[30];

}empleados[100];

//estructura compras
struct compra{
    int CgasolinaExtra;
    int CgasolinaCorriente;
    int CACPM;
    int CAceiteParaMotos;
    int CaceiteParaCarros;
    int Clubricantes;
    int CbrillaAutos;
    int GasolinaCorriente, GasolinaExtra, ACPM, AceitesParaMotos, AceitesParaCarros, Lubricantes, brillaAutos;

}compras[100];

//estructura ventas

struct venta{
    int id;
    int idCliente;
    int idProducto;
    int cantidad;
    float precio;
    float totalFatura;
    int idempleado;
}ventas;

//datos de la empresa
struct datosEmpresa{
    char nombre[30];
    char direccion[30];
    char telefono[15];
}empresa;

// clientes prototipo de funciones

void menuGasolinera();
void menuClientes();
void menuProductos();
void menuProveedores();
void menuEmpleados();
void menuCompras();
void menuVentas();
void menuDatosEmpresa();
void menuComprarProveedor();

// clientes
void crearCliente();
void editarCliente();
void eliminarCliente();
void mostrarClientes();
void mostrarCliente(int);
int buscarCliente();
int buscarCliente_ed();
void menu_editarCliente(int nro_cte);
void editarNombre(int i);
void cambiarDireccion(int r);
void cambiarTelefono(int r);

//productos
void Ver_Productos();

//proveedores
void crearproveedores();
void editarProveedor();
void eliminarProveedor();
void mostrarproveedores();
void mostrarproveedor(int);
int buscarProveedor();
int buscarProveedor_ed();
void menu_editarProveedor(int r);
void editarNombrePro(int r);
void cambiarDireccionPro(int r);
void cambiarTelefonoPro(int r);

//empleados
void crearEmpleados();
void editarEmpleado();
void eliminarEmpleado();
void mostrarEmpleados();
void mostrarEmpleado(int);
int buscarEmpleado();
int buscarEmpleado_ed();
void menu_editarEmpleado(int r);
void editarNombreEmp(int r);
void cambiarDireccionEmp(int r);
void cambiarTelefonoEmp(int r);

//compras
void compCombustible();
void compProductosVehiculos();
void mostrarFactura();
void GasolinaExtra(int );
void GasolinaCorriente(int );
void ACPM(int );
void aceitesParaCarros(int );
void aceiteParaMotos(int );
void lubricante(int );
void BrillaAutos(int );
void comprarGasolinaExtra(int );
void comprarGasolinaCorriente(int );
void comprarACPM(int );
void comprarAceiteParaCarros(int );
void comprarAceiteParaMotos(int );
void comprarLubricante(int );
void comprarBrillaAuto(int );
void GasolinaExtra();
// ventas
void CantProducVendidos();
void TotalProducVendidos();


//datos empresa
void datosEmpresa();

int main(){
    system("color 47");
    menuGasolinera();
    return 0;
}

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void menuGasolinera(){
    int opcion=0;
    do{
    gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("Menu Principal J'V'''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(18,7); printf("1: Clientes");
    gotoxy(44,7); printf("6: Ventas");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(18,9); printf("2: productos");
    gotoxy(44,9); printf("7: datos de la empresa");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(18,11); printf("3: Proveedores");
    gotoxy(44,11); printf("0: Salir");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(18,13); printf("4: empleados");
    gotoxy(69,13); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(18,15); printf("5: Compras");
    gotoxy(10,15); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,16); printf("*");
    gotoxy(10,16); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(10,17); printf("*");
    gotoxy(39,17); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(10,17); printf("************************************************************\n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &opcion);
       system("cls");
        switch(opcion){
            case 1: menuClientes();
            break;
            case 2: menuProductos();
            break;
            case 3: menuProveedores();
            break;
            case 4: menuEmpleados();
            break;
            case 5: menuCompras();
            break;
            case 6: menuVentas();
            break;
            case 7: system("cls");
                datosEmpresa();
                system("pause");
                system("cls");
            break;
            case 0: exit(0);
            break;
            default: printf("Opcion invalidad\n");
        }
    }while(opcion != 0);
}

void menuClientes(){
	int opcion;
	do{
    gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("MENU CLIENTES J'V'''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(18,7); printf("1: Crear Cliente");
    gotoxy(46,7); printf("0: Salir");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(18,9); printf("2: Editar Cliente");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(18,11); printf("3: Eliminar Cliente");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(18,13); printf("4: Mostrar Clientes");
    gotoxy(69,13); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(18,15); printf("5: Buscar Cliente");
    gotoxy(10,15); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,16); printf("*");
    gotoxy(10,16); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(10,17); printf("*");
    gotoxy(39,17); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(10,17); printf("************************************************************\n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1: crearCliente();
				break;
			case 2: editarCliente();
				break;
			case 3: eliminarCliente();
				break;
			case 4: mostrarClientes();
				break;
			case 5: buscarCliente();
				break;
			case 0: menuGasolinera();
				break;
			default: printf("Opcion no valida\n");
		}
	}while(opcion != 0);
}

void crearCliente(){
    printf("\n");
	printf("Crear Cliente\n");
	printf("Cliente No. %d\n", cantClientes + 1);
	clientes[cantClientes].id = cantClientes;
	printf("Nombre del Cliente: ");
	fflush(stdin);
	fgets(clientes[cantClientes].nombre, 30, stdin);
	fflush(stdin);
	printf("\n");
	printf("Cedula del Cliente: ");
	scanf("%d", &clientes[cantClientes].cedula);
	printf("\n");
	printf("Direccion del Cliente: ");
	fflush(stdin);
	fgets(clientes[cantClientes].direccion, 30, stdin);
	printf("\n");
	printf("Telefono del Cliente: ");
	fgets(clientes[cantClientes].telefono, 30, stdin);
	printf("\n");
	cantClientes += 1;
	system("cls");
	}



int buscarCliente_ed(){
    int buscarCedula,i;
    printf("Buscar Cliente a editar\n");
	printf("Ingrese cedula: ");
	scanf("%d",&buscarCedula);
	printf("\n");
	for(i = 0; i < cantClientes; i++){
		if(buscarCedula == clientes[i].cedula){
			mostrarCliente(clientes[i].id);
			return (clientes[i].id);
	   system("cls");
		}

	}
	printf("El cliente no existe \n");
	return -1;

}


void editarCliente(){
    int r;
    r=buscarCliente_ed();
    if(r != -1){
         menu_editarCliente(r);
 system("cls");
    }

}

    void menu_editarCliente(int r){
        int opcion=0;
        do{
    gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("MENU editar clientes J'V'''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(16,7); printf("1: editar nombre");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(16,9); printf("2: cambiar Direccion");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(16,11); printf("3: cambiar Telefono");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(16,13); printf("0: Salir");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1:editarNombre(r);
		    break;
		    case 2:cambiarDireccion(r);
		    break;
		    case 3:cambiarTelefono(r);
		    break;
		    case 0: system("cls");
		        menuClientes();
		        system("pause");
		    break;

		    }
	}while(opcion != 0);
}

        void editarNombre(int r){
                printf("Ingrese el nuevo nombre\n");
                fflush(stdin);
                fgets(clientes[r].nombre, 30, stdin);
        }
        void cambiarDireccion(int r){
            printf("ingrese la nueva direccion\n");
            fflush(stdin);
            fgets(clientes[r].direccion, 30, stdin);
        }
        void cambiarTelefono(int r){
            printf("ingrese el nuevo numero de telefono\n");
            fflush(stdin);
            fgets(clientes[r].telefono, 30, stdin);
            system("cls");

        }


void eliminarCliente(){
	int i;
	printf("Eliminar Cliente\n");
	int idCliente = buscarCliente();
	if(idCliente != -1){
		if(idCliente < cantClientes){
			for(i = idCliente; i < cantClientes; i++){
				clientes[i + 1].id = i;

			}
		}
		cantClientes -= 1;
	}
system("cls");
}

void mostrarClientes(){
        printf("mostrar cliente\n");
        for(int i=0; i<cantClientes;i++){
        printf("Nombre del Cliente: %s\n ",clientes[i].nombre);
        printf("Cedula del Cliente: %d\n ",clientes[i].cedula);
        printf("Direccion del Cliente: %s\n ",clientes[i].direccion);
        printf("Telefono del Cliente: %s\n",clientes[i].telefono);
        printf("\n\n");
    system("pause");
    system("cls");
        }
}

void mostrarCliente(int idCliente){
    printf("Mostrar Clientes\n");
	printf("Cliente No. %d\n", clientes[idCliente].id + 1);
    printf("Nombre del Cliente: %s\n ",clientes[idCliente].nombre);
    printf("Cedula del Cliente: %d\n ",clientes[idCliente].cedula);
    printf("Direccion del Cliente: %s\n ",clientes[idCliente].direccion);
    printf("Telefono del Cliente: %s\n",clientes[idCliente].telefono);
    printf("\n\n");
 system("pause");
 system("cls");

}

int buscarCliente(){
    int buscarCedula,i;
    printf("Buscar Cliente\n");
	printf("Ingrese cedula: ");
	scanf("%d",&buscarCedula);
	printf("\n");
	for(i = 0; i < cantClientes; i++){
		if(buscarCedula == clientes[i].cedula){
			mostrarCliente(clientes[i].id);
			return (clientes[i].id);
		system("cls");
		}
	}
	printf("El cliente no existe \n");
	return -1;
	system("cls");
}

void menuProductos(){
int opcion=0;
do{
	gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(24,3); printf("Productos De La Gasolinera 'J'V''''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(18,7); printf("1: Ver_Productos");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(69,9); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(39,10); printf("*");
	gotoxy(10,10); printf("*");
	gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(69,11); printf("*");
	gotoxy(10,11);printf("************************************************************");

    printf("\n \n");
    printf("ingrese su opcion: \n");
	scanf("%d", &opcion);
    system("cls");
    switch(opcion){

    	 case 1: Ver_Productos();
	     break;
	     case 0: menuGasolinera();
	     break;



	     default: printf("opcion no invalida \n");
	}
     system("cls");
    system("pause");

} while(opcion != 0);

}


void Ver_Productos(){

	gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("Lista De Productos J'V''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(15,7); printf("1: Gasolina Corriente");
    gotoxy(46,7); printf("Precio $8900");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(15,9); printf("2: Gasolina Extra");
    gotoxy(46,9); printf("Precio $10999");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(15,11); printf("3: ACPM");
    gotoxy(46,11); printf("Precio $5000");
	gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(15,13); printf("4: Aceite Para Carros");
    gotoxy(46,13); printf("Precio $100500");
	gotoxy(69,13); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(15,15); printf("5: Aceite Para Motos");
    gotoxy(46,15); printf("Precio $48000");
    gotoxy(10,15); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,16); printf("*");
    gotoxy(10,16); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(10,17); printf("*");
    gotoxy(39,17); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(15,17); printf("6: Lubricante");
	gotoxy(46,17); printf("Precio $18550");
	gotoxy(10,17); printf("*");
	gotoxy(39,18); printf("*");
    gotoxy(69,18); printf("*");
    gotoxy(10,18); printf("*");
    gotoxy(39,18); printf("*");
    gotoxy(69,19); printf("*");
    gotoxy(10,19); printf("*");
    gotoxy(39,19); printf("*");
    gotoxy(69,19); printf("*");
    gotoxy(15,19); printf("7: Brilla Autos");
    gotoxy(46,19); printf("Precio $50000");
	gotoxy(10,20); printf("*");
	gotoxy(39,20); printf("*");
	gotoxy(69,20); printf("*");
	gotoxy(10,21); printf("************************************************************");

    printf("\n \n");

   system("pause");
   system("cls");

}

void menuProveedores(){
int opcion;
	do{
    gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("MENU PROVEEDORES J'V'''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(16,7); printf("1: Crear proveedor");
    gotoxy(46,7); printf("5: Buscar proveedor");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(16,9); printf("2: Editar proveedor");
    gotoxy(46,9); printf("0: Salir");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(16,11); printf("3: Eliminar proveedor");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(16,13); printf("4: Mostrar proveedor");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");
	printf("Ingrese su opcion: \n");
	scanf("%d", &opcion);
	system("cls");
	switch(opcion){
			case 1: crearproveedores();
				break;
			case 2: editarProveedor();
				break;
			case 3: eliminarProveedor();
				break;
			case 4: mostrarproveedores();
				break;
			case 5: buscarProveedor();
				break;
			case 0: system("cls");
			    menuGasolinera();
			    system("pause");
				break;
			default: printf("Opcion no valida\n");
		}
	}while(opcion != 0);
}
//creamos los proveedores
void crearproveedores(){
    printf("\n");
	printf("Crear proveedor\n");
	printf("proveedor No. %d\n", cantProveedores + 1);
	clientes[cantProveedores].id = cantProveedores;
	printf("Nombre del proveedor: ");
	fflush(stdin);
	fgets(proveedores[cantProveedores].nombre, 30, stdin);
	fflush(stdin);
	printf("\n");
	printf("Cedula del proveedor: ");
	scanf("%d",&proveedores[cantProveedores].cedula);
	printf("\n");
	printf("Direccion del proveedor: ");
	fflush(stdin);
	fgets(proveedores[cantProveedores].direccion, 30, stdin);
	printf("\n");
	printf("Telefono del proveedor: ");
	fgets(proveedores[cantProveedores].telefono, 30, stdin);
	printf("\n");
	cantProveedores+= 1;
	system("pause");
	system("cls");
	}
// buscamos el proveedor para editarlo
int buscarProveedor_ed(){
    int buscarCedula,i;
    printf("Buscar proveedor a editar\n");
	printf("Ingrese cedula: ");
	scanf("%d",&buscarCedula);
	printf("\n");
	for(i = 0; i < cantProveedores; i++){
		if(buscarCedula == proveedores[i].cedula){
			mostrarproveedores(proveedores[i].id);
			return (proveedores[i].id);
		}
	}
	printf("El proveedor no existe \n");
	return -1;
	system("cls");
}
void editarProveedor(){
    int r;
    r=buscarProveedor_ed();
    if(r != -1){
         menu_editarProveedor(r);
    }
    system("cls");
    system("pause");
}

    void menu_editarProveedor(int r){
        int opcion=0;
        do{
    gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("MENU editar proveedor J'V'''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(16,7); printf("1: Editar Nombre");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(16,9); printf("2: Cambiar Direccion");
    gotoxy(46,9); printf("0: Salir");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(16,11); printf("3: Cambiar Telefono");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");
	printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1:editarNombrePro(r);
		    break;
		    case 2:cambiarDireccionPro(r);
		    break;
		    case 3:cambiarTelefonoPro(r);
		    break;
		    case 0: system("cls");
		        menuProveedores(r);
		        system("pause");
		    break;

		    }
	}while(opcion != 0);
}

void editarNombrePro(int r){
    printf("Ingrese el nuevo nombre\n");
    fflush(stdin);
    fgets(proveedores[r].nombre, 30, stdin);
    system("pause");
    system("cls");
}

void cambiarDireccionPro(int r){
    printf("ingrese la nueva direccion\n");
    fflush(stdin);
    fgets(proveedores[r].direccion, 30, stdin);
    system("pause");
    system("cls");
}

void cambiarTelefonoPro(int r){
    printf("ingrese el nuevo numero de telefono\n");
    fflush(stdin);
    fgets(proveedores[r].telefono, 30, stdin);
    system("pause");
    system("cls");
}
//creamos una funcion para eliminar al proveedor

void eliminarProveedor(){
    int i;
	printf("Eliminar proveedor\n");
	int idProveedor = buscarProveedor();
	if(idProveedor != -1){
		if(idProveedor < cantProveedores){
			for(i = idProveedor; i < cantProveedores; i++){
				proveedores[i + 1].id = i;
			}
		}
		cantProveedores -= 1;
	}
	system("pause");
    system("cls");
}

void mostrarproveedores(){
    printf("mostrar proveedor\n");

    for (int i=0; i<cantProveedores; i++){
        printf("Nombre del proveedor: %s\n",proveedores[i].nombre);
        printf("Cedula del proveedor: %d\n",proveedores[i].cedula);
        printf("Direccion del proveedor: %s\n",proveedores[i].direccion);
        printf("Telefono del proveedor: %s\n",proveedores[i].telefono);
    system("pause");
    system("cls");
    }

}

void mostrarproveedor(int idProveedor){
    printf("Mostrar proveedores\n");
	printf("proveedor No. %d\n", proveedores[idProveedor].id + 1);
    printf("Nombre del proveedor: %s\n ",proveedores[idProveedor].nombre);
    printf("Cedula del proveedor: %d\n ",proveedores[idProveedor].cedula);
    printf("Direccion del proveedor: %s\n ",proveedores[idProveedor].direccion);
    printf("Telefono del proveedor: %s\n",proveedores[idProveedor].telefono);
    printf("\n\n");
    system("cls");
    system("pause");
}

int buscarProveedor(){
    int buscarCedula,i;
    printf("Buscar proveedor\n");
	printf("Ingrese cedula: ");
	scanf("%d",&buscarCedula);
	printf("\n");
	for(i = 0; i < cantProveedores; i++){
		if(buscarCedula == proveedores[i].cedula){
			mostrarproveedor(proveedores[i].id);
			return (proveedores[i].id);
		}
	}
	printf("El proveedor no existe \n");
	return -1;
    system("pause");
    system("pause");
}



void menuEmpleados(){
    int opcion;
	do{
        gotoxy(10,1); printf("************************************************************");
        gotoxy(10,2); printf("*");
        gotoxy(69,2); printf("*");
        gotoxy(69,3); printf("*");
        gotoxy(10,3); printf("*");
        gotoxy(31,3); printf("MENU EMPLEADOS J'V'''");
        gotoxy(10,4); printf("*");
        gotoxy(69,4); printf("*");
        gotoxy(10,5); printf("************************************************************");
        gotoxy(10,6); printf("*");
        gotoxy(39,6); printf("*");
        gotoxy(69,6); printf("*");
        gotoxy(10,7); printf("*");
        gotoxy(39,7); printf("*");
        gotoxy(16,7); printf("1: Crear empleado");
        gotoxy(46,7); printf("0: Salir");
        gotoxy(69,7); printf("*");
        gotoxy(10,8); printf("*");
        gotoxy(39,8); printf("*");
        gotoxy(69,8); printf("*");
        gotoxy(10,9); printf("*");
        gotoxy(39,9); printf("*");
        gotoxy(16,9); printf("2: Editar Empleado");
        gotoxy(69,9); printf("*");
        gotoxy(10,10); printf("*");
        gotoxy(39,10); printf("*");
        gotoxy(69,10); printf("*");
        gotoxy(10,11); printf("*");
        gotoxy(39,11); printf("*");
        gotoxy(16,11); printf("3: Eliminar Empleado");
		gotoxy(69,11); printf("*");
        gotoxy(10,12); printf("*");
        gotoxy(39,12); printf("*");
        gotoxy(69,12); printf("*");
        gotoxy(10,13); printf("*");
        gotoxy(39,13); printf("*");
        gotoxy(16,13); printf("4: Mostrar Empleado");
        gotoxy(69,13); printf("*");
        gotoxy(10,14); printf("*");
        gotoxy(39,14); printf("*");
        gotoxy(69,14); printf("*");
        gotoxy(10,14); printf("*");
        gotoxy(10,15); printf("*");
        gotoxy(39,15); printf("*");
        gotoxy(16,15); printf("5: Buscar Empleado");
        gotoxy(69,13); printf("*");
        gotoxy(69,14); printf("*");
        gotoxy(10,14); printf("*");
        gotoxy(39,14); printf("*");
        gotoxy(10,15); printf("*");
        gotoxy(39,15); printf("*");
        gotoxy(69,15); printf("*");
        gotoxy(69,15); printf("*");
        gotoxy(10,16); printf("************************************************************\n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1: crearEmpleados();
				break;
			case 2: editarEmpleado();
				break;
			case 3: eliminarEmpleado();
				break;
			case 4: mostrarEmpleados();
				break;
			case 5: buscarEmpleado();
				break;
			case 0: system("cls");
			    menuGasolinera();
			    system("pause");
				break;
			default: printf("Opcion no valida\n");
		}
	}while(opcion != 0);
}

void crearEmpleados(){
    printf("\n");
	printf("Crear empleados\n");
	printf("Empleados No. %d\n", cantEmpleados + 1);
	empleados[cantEmpleados].id = cantEmpleados;
	printf("Nombre del Empleados: ");
	fflush(stdin);
	fgets(empleados[cantEmpleados].nombre, 30, stdin);
	fflush(stdin);
	printf("\n");
	printf("Cedula del Empleados: ");
	scanf("%d",&empleados[cantEmpleados].cedula);
	printf("\n");
	printf("Direccion del Empleados: ");
	fflush(stdin);
	fgets(empleados[cantEmpleados].direccion, 30, stdin);
	printf("\n");
	printf("Telefono del Empleados: ");
	fgets(empleados[cantEmpleados].telefono, 30, stdin);
	printf("\n");
	printf("usuario: ");
	fgets(empleados[cantEmpleados].usuario,30,stdin);
	printf("contrasena: \n");
	fgets(empleados[cantEmpleados].contrasena,30, stdin);
	printf("\n");
	cantEmpleados+= 1;
	system("pause");
	system("cls");
}
//buscamos el empleado que desamos editar
int buscarEmpleado_ed(){
    int buscarCedula,i;
    printf("Buscar Empleado a editar\n");
	printf("Ingrese cedula: ");
	scanf("%d",&buscarCedula);
	printf("\n");
	for(i = 0; i < cantEmpleados; i++){
		if(buscarCedula == empleados[i].cedula){
			mostrarEmpleado(empleados[i].id);
			return (empleados[i].id);
	   system("cls");
		}

	}
	printf("El empleado no existe \n");
	return -1;

}


void editarEmpleado(){
    int r;
    r=buscarEmpleado_ed();
    if(r != -1){
         menu_editarEmpleado(r);
 system("cls");
    }

}
void menu_editarEmpleado(int r){
     int opcion=0;
        do{
		gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("MENU EDITAR EMPLEADO J'V'''");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(40,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(40,7); printf("*");
    gotoxy(13,7); printf("1: editar nombre");
    gotoxy(46,7); printf("0: Salir");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(40,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(40,9); printf("*");
    gotoxy(13,9); printf("2: cambiar direccion");
    gotoxy(40,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(40,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(40,11); printf("*");
    gotoxy(13,11); printf("3: Cambiar numero Telefono");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(40,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(40,13); printf("*");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(40,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(40,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1:editarNombreEmp(r);
		    break;
		    case 2:cambiarDireccionEmp(r);
		    break;
		    case 3:cambiarTelefonoEmp(r);
		    break;
		    case 0: system("cls");
		        menuProveedores(r);
		        system("pause");
		    break;

		    }
	}while(opcion != 0);
}

void editarNombreEmp(int r){
    printf("Ingrese el nuevo nombre\n");
    fflush(stdin);
    fgets(empleados[r].nombre, 30, stdin);
    system("pause");
    system("cls");
}

void cambiarDireccionEmp(int r){
    printf("ingrese la nueva direccion\n");
    fflush(stdin);
    fgets(empleados[r].direccion, 30, stdin);
    system("pause");
    system("cls");
}
void cambiarTelefonoEmp(int r){
    printf("ingrese el nuevo numero de telefono\n");
    fflush(stdin);
    fgets(empleados[r].telefono, 30, stdin);
    system("pause");
    system("cls");
}
void eliminarEmpleado(){
    int i;
	printf("Eliminar empleado\n");
	int idEmpleado = buscarEmpleado();
	if(idEmpleado != -1){
		if(idEmpleado < cantEmpleados){
			for(i = idEmpleado; i < cantEmpleados; i++){
				empleados[i + 1].id = i;
			}
		}
		cantEmpleados -= 1;
	}
    system("pause");
    system("cls");
}
void mostrarEmpleados(){

    printf("mostrar empleado\n");
    for(int i=0; i<cantEmpleados; i++){
    printf("Nombre del Empleado: %s\n",empleados[i].nombre);
	printf("Cedula del Empleado: %d\n",empleados[i].cedula);
	printf("Direccion del Empleado: %s\n",empleados[i].direccion);
	printf("Telefono del Empleado: %s\n",empleados[i].telefono);
	printf("usuario: %s\n",empleados[i].usuario);
	printf("contrasena: %s\n",empleados[i].contrasena);
	cantEmpleados+= 1;
    }
    system("pause");
    system("cls");
}

void mostrarEmpleado(int idEmpleado){
    printf("Mostrar empleado\n");
	printf("empleado No. %d\n", empleados[idEmpleado].id + 1);
    printf("Nombre del empleado: %s\n ",empleados[idEmpleado].nombre);
    printf("Cedula del empleado: %d\n ",empleados[idEmpleado].cedula);
    printf("Direccion del empleado: %s\n ",empleados[idEmpleado].direccion);
    printf("Telefono del empleado: %s\n",empleados[idEmpleado].telefono);
    printf("usuario: %s\n",empleados[idEmpleado].usuario);
	printf("contrasena: %s\n",empleados[idEmpleado].contrasena);
    printf("\n\n");
    system("pause");
    system("cls");
}

int buscarEmpleado(){
    int buscarCedula,i;
    printf("Buscar empleado\n");
	printf("Ingrese cedula: ");
	scanf("%d",&buscarCedula);
	printf("\n");
	for(i = 0; i < cantEmpleados; i++){
		if(buscarCedula == empleados[i].cedula){
			mostrarEmpleado(empleados[i].id);
            return (empleados[i].id);
		}
	}
	printf("El empleado no existe \n");
	return -1;
	system("pause");
    system("cls");
}

void menuCompras(){
    int opcion=0;
        do{
	gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(35,3); printf("MENU Compras ");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(43,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(43,7); printf("*");
    gotoxy(12,7); printf("1: comprar combustible");
    gotoxy(46,7); printf("4: Comprar a Proveedor");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(43,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(43,9); printf("*");
    gotoxy(12,9); printf("2: comprar productos vehiculos");
    gotoxy(46,9); printf("5. Gastos proveedores");
    gotoxy(43,9); printf("*");
    gotoxy(69,9); printf("*");
    gotoxy(43,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(43,11); printf("*");
    gotoxy(12,11); printf("3: mostrar factura");
    gotoxy(46,11); printf("0. Salir");
	gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(43,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(43,13); printf("*");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(43,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(43,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");;
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1:compCombustible();
		    break;
		    case 2:compProductosVehiculos();
		    break;
		    case 3:mostrarFactura();
		    break;
		    case 4: menuComprarProveedor();
		    break;
		    case 5: GastosProveedores();
		    break;
		    case 0: menuGasolinera();
		    break;
		    }
	}while(opcion != 0);
}
void compCombustible(){
    int opcion=0;
    int idCliente = buscarCliente();
        do{
	gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(35,3); printf("MENU combustible ");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(43,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(43,7); printf("*");
    gotoxy(16,7); printf("1. Gasolina corriente");
    gotoxy(47,7); printf("0. Salir");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(43,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(43,9); printf("*");
    gotoxy(16,9); printf("2. Gasolina corriente");
    gotoxy(43,9); printf("*");
    gotoxy(69,9); printf("*");
    gotoxy(43,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(43,11); printf("*");
    gotoxy(16,11); printf("3. ACPM");
   	gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(43,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(43,13); printf("*");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(43,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(43,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1:GasolinaExtra(idCliente);
		    break;
		    case 2:GasolinaCorriente(idCliente);
		    break;
		    case 3:ACPM(idCliente);
		    break;
		    case 0: menuCompras();
		    break;

		    }
	}while(opcion != 0);
}

void GasolinaExtra(int idCliente){
    int precio=10999;
    if(product.CgasolinaExtra>=1){
        printf("Ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CgasolinaExtra);
        compras[idCliente].GasolinaExtra = precio * compras[idCliente].CgasolinaExtra;
        product.CgasolinaExtra -= compras[idCliente].CgasolinaExtra;

    }else{
        printf("Se acabo el producto\n");
    }
}

void GasolinaCorriente(int idCliente){
    int precio=8900;
    if(product.CgasolinaCorriente>=1){
        printf("ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CgasolinaCorriente);
        compras[idCliente].GasolinaCorriente = precio * compras[idCliente].CgasolinaCorriente;
        product.CgasolinaCorriente -= compras[idCliente].CgasolinaCorriente;

    }else{
        printf("Se acabo el producto\n");
    }

}
void ACPM(int idCliente){
    int precio=5000;
    if(product.CACPM>=1){
        printf("ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CACPM);
        compras[idCliente].ACPM= precio * compras[idCliente].CACPM;
        product.CACPM -= compras[idCliente].CACPM;
 }else{
        printf("Se acabo el producto\n");
    }
}

void compProductosVehiculos(){
    int opcion=0;
    int idCliente = buscarCliente();
        do{
	gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(35,3); printf("MENU PRODUCTOS PARA VEHICULOS ");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(43,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(43,7); printf("*");
    gotoxy(16,7); printf("1. Aceites para carros");
    gotoxy(47,7); printf("4. brilla autos");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(43,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(43,9); printf("*");
    gotoxy(16,9); printf("2. Aceites para motos");
    gotoxy(47,9); printf("0. Salir");
	gotoxy(43,9); printf("*");
    gotoxy(69,9); printf("*");
    gotoxy(43,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(43,11); printf("*");
    gotoxy(16,11); printf("3. lubricantes");
   	gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(43,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(43,13); printf("*");
    gotoxy(69,13); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(43,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(43,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(10,16); printf("************************************************************\n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1: aceitesParaCarros(idCliente);
		    break;
		    case 2:aceiteParaMotos(idCliente);
		    break;
		    case 3:lubricante(idCliente);
		    break;
		    case 4: BrillaAutos(idCliente);
		    break;
            case 0: menuCompras();
		    }
	}while(opcion != 0);
}

void aceitesParaCarros(int idCliente){
    int precio=100500;
    if(product.CaceiteParaCarros>=1){
        printf("ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CACPM);
        compras[idCliente].AceitesParaCarros= precio * compras[idCliente].CaceiteParaCarros;
        product.CaceiteParaCarros -= compras[idCliente].CaceiteParaCarros;
 }else{
        printf("Se acabo el producto\n");
    }
}
void aceiteParaMotos(int idCliente){
    int precio=48000;
    if(product.CAceiteParaMotos>=1){
        printf("ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CAceiteParaMotos);
        compras[idCliente].AceitesParaMotos= precio * compras[idCliente].CAceiteParaMotos;
        product.CAceiteParaMotos -= compras[idCliente].CAceiteParaMotos;
 }else{
        printf("Se acabo el producto\n");
    }
}
void lubricante(int idCliente){
    int precio=18550;
    if(product.Clubricantes>=1){
        printf("ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CACPM);
        compras[idCliente].Lubricantes= precio * compras[idCliente].Clubricantes;
        product.Clubricantes -= compras[idCliente].Clubricantes;
 }else{
        printf("Se acabo el producto\n");
    }
}
void BrillaAutos(int idCliente){
    int precio=50000;
    if(product.CbrillaAutos>=1){
        printf("ingrese la cantidad a comprar: \n");
        scanf("%d",&compras[idCliente].CbrillaAutos);
        compras[idCliente].brillaAutos= precio * compras[idCliente].CbrillaAutos;
        product.CbrillaAutos -= compras[idCliente].CbrillaAutos;
 }else{
        printf("Se acabo el producto\n");
    }
}

void mostrarFactura(){

}



void menuVentas(){
int opcion=0;
        do{
			gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(20,3); printf("MENU VENTAS");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(15,7); printf("1: Mostrar cantidad de productos vendidos ");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(15,9); printf("2: Mostrar valor total productos vendidos ");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(15,11); printf(" 0. Salir \n");
	gotoxy(69,11); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(69,13); printf("*");
	gotoxy(10,14); printf("************************************************************ \n");
		printf("Ingrese su opcion: \n");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
		    case 1: CantProducVendidos();
		    break;
		    case 2: TotalProducVendidos();
		    break;
		    case 0: menuGasolinera();
		    break;
		    }
	}while(opcion != 0);
}

void CantProducVendidos(){
    int suma1=0, suma2=0, suma3=0, suma4=0, suma5=0, suma6=0, suma7=0;
      for(int i=0; i<cantClientes; i++){
            suma1 += compras[i].CgasolinaExtra;
            suma2 += compras[i].CgasolinaCorriente;
            suma3 += compras[i].CACPM;
            suma4 += compras[i].CaceiteParaCarros;
            suma5 += compras[i].CAceiteParaMotos;
            suma6 += compras[i].Clubricantes;
            suma7 += compras[i].CbrillaAutos;
        }
      printf("Cantidad de Gasolina Extra vendida: %d\n", suma1);
      printf("Cantidad de Gasolina Corriente vendida %d\n", suma2);
      printf("Cantidad de ACPM %d\n", suma3);
      printf("Cantidad de Aceite Para Carros %d\n", suma4);
      printf("Cantidad de Aceite Para Motos %d\n", suma5);
      printf("Cantidad de lubricantes %d\n", suma6);
      printf("Cantidad de Brilla Autos %d\n", suma7);
}

void TotalProducVendidos(){
    int sumaTotal=0;
    int suma1=0, suma2=0, suma3=0, suma4=0, suma5=0, suma6=0, suma7=0;
      for(int i=0; i<cantClientes; i++){
            suma1 += compras[i].GasolinaExtra;
            suma2 += compras[i].GasolinaCorriente;
            suma3 += compras[i].ACPM;
            suma4 += compras[i].AceitesParaCarros;
            suma5 += compras[i].AceitesParaMotos;
            suma6 += compras[i].Lubricantes;
            suma7 += compras[i].brillaAutos;
        }
        sumaTotal = (suma1+suma2+suma3+suma4+suma5+suma6+suma7);
        printf("El valor total de ventas es: %d\n", sumaTotal);
}


void datosEmpresa(){
   gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(20,3); printf("ESTACION DE GASOLINA DE JUAN Y VIVIANA");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(15,7); printf("1: Direccion: ");
    gotoxy(42,7); printf(" cr5 #43-5 Barrio Alamos \n");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(15,9); printf("2: Numero De Telefono: ");
    gotoxy(42,9); printf(" 3124571231 \n");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(69,11); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
 	gotoxy(69,13); printf("*");
	gotoxy(10,14); printf("************************************************************ \n");

}

void menuComprarProveedor(){
    int opcion;
    int idCliente = buscarCliente();
    int idProveedor = buscarProveedor();
    do{
        gotoxy(10,1); printf("************************************************************");
    gotoxy(10,2); printf("*");
    gotoxy(69,2); printf("*");
    gotoxy(69,3); printf("*");
    gotoxy(10,3); printf("*");
    gotoxy(31,3); printf("Menu compras a proveedores");
    gotoxy(10,4); printf("*");
	gotoxy(69,4); printf("*");
	gotoxy(10,5); printf("************************************************************");
    gotoxy(10,6); printf("*");
    gotoxy(39,6); printf("*");
    gotoxy(69,6); printf("*");
    gotoxy(10,7); printf("*");
    gotoxy(39,7); printf("*");
    gotoxy(15,7); printf("1: Gasolina Corriente");
    gotoxy(69,7); printf("*");
    gotoxy(10,8); printf("*");
    gotoxy(39,8); printf("*");
    gotoxy(69,8); printf("*");
    gotoxy(10,9); printf("*");
    gotoxy(39,9); printf("*");
    gotoxy(15,9); printf("2: Gasolina Extra");
    gotoxy(69,9); printf("*");
    gotoxy(10,10); printf("*");
    gotoxy(39,10); printf("*");
    gotoxy(69,10); printf("*");
    gotoxy(10,11); printf("*");
    gotoxy(39,11); printf("*");
    gotoxy(15,11); printf("3: ACPM");
    gotoxy(69,11); printf("*");
    gotoxy(10,12); printf("*");
    gotoxy(39,12); printf("*");
    gotoxy(69,12); printf("*");
    gotoxy(10,13); printf("*");
    gotoxy(39,13); printf("*");
    gotoxy(15,13); printf("4: Aceite Para Carros");
    gotoxy(69,13); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(39,14); printf("*");
    gotoxy(69,14); printf("*");
    gotoxy(10,14); printf("*");
    gotoxy(10,15); printf("*");
    gotoxy(39,15); printf("*");
    gotoxy(69,15); printf("*");
    gotoxy(15,15); printf("5: Aceite Para Motos");
    gotoxy(10,15); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,16); printf("*");
    gotoxy(10,16); printf("*");
    gotoxy(39,16); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(10,17); printf("*");
    gotoxy(39,17); printf("*");
    gotoxy(69,17); printf("*");
    gotoxy(15,17); printf("6: Lubricante");
	gotoxy(10,17); printf("*");
	gotoxy(39,18); printf("*");
    gotoxy(69,18); printf("*");
    gotoxy(10,18); printf("*");
    gotoxy(39,18); printf("*");
    gotoxy(69,19); printf("*");
    gotoxy(10,19); printf("*");
    gotoxy(39,19); printf("*");
    gotoxy(69,19); printf("*");
    gotoxy(15,19); printf("7: Brilla Autos");
    gotoxy(10,20); printf("*");
	gotoxy(39,20); printf("*");
	gotoxy(69,20); printf("*");
	gotoxy(10,21); printf("************************************************************ \n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
                switch(opcion){
            case 1: comprarGasolinaExtra(idCliente);
            break;
            case 2: comprarGasolinaCorriente(idCliente);
            break;
            case 0: break;
            default: printf("Opcion invalida\n");
        }
    }while(opcion!=0);
}

void comprarGasolinaExtra(int idCliente){
    int precio=5000;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.CgasolinaExtra+=cant;
}

void comprarGasolinaCorriente(int idCliente){
    int precio=4000;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.CgasolinaCorriente+=cant;
}

void comprarACPM(int idCliente){
    int precio=2500;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.CACPM+=cant;
}
void comprarAceiteParaCarros(int idCliente){
    int precio=5000;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.CaceiteParaCarros+=cant;



}
void comprarAceiteParaMotos(int idCliente){
    int precio=25000;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.CAceiteParaMotos+=cant;
}

void comprarLubricante(int idCliente){
    int precio=9000;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.Clubricantes+=cant;
}
void comprarBrillaAuto(int idCliente){
    int precio=25000;
    int cant;
    int total=0;
    printf("Ingrese la cantidad a comprar: \n");
    scanf("%d",&cant);
    total = precio*cant;
    proveedores[idCliente].ganancias = total;
    product.CbrillaAutos+=cant;
}

void GastosProveedores(){
}
