#include <stdio.h>
#include <stdlib.h>

struct producto{
    int id;
    char nombre[30];
    char codigo [30];
    int precio;

}productos[100];

int cantProductos = 0;

void menu_productos();
void crearProductos();
void editarProductos();
void mostrarProductos();
void mostrarProducto(int);
int  buscarProducto();

int main()
{
    menu_productos();

    return 0;
}
void menu_productos(){
	int opcion;
	do{
		printf("MENU PRODUCTOS\n");
		printf("1. Crear productos\n");
		printf("2. Editar productos\n");
		printf("3. Mostrar productos\n");
		printf("4. Buscar productos\n");
		printf("0. Salir\n");
		printf("Ingrese su opcion: \n");
		printf("\n");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: crearProductos();
				break;
			case 2: editarProductos();
				break;
			case 3: mostrarProductos();
				break;
			case 4: buscarProducto();
				break;
			case 0: exit(0);
				break;
			default: printf("Opcion no valida\n");
		}
	}while(opcion != 0);
}

void crearProductos(){
    printf("crear productos\n");
    printf("producto No. %d\n", cantProductos + 1);
	productos[cantProductos].id = cantProductos;
	printf("nombre del producto\n");
	fflush(stdin);
	fgets(productos[cantProductos].nombre, 30, stdin);
	printf("codigo del producto\n");
	scanf("%d",&productos[cantProductos].codigo);
	printf("valor del producto\n");
	scanf("%d",&productos[cantProductos].precio);
	printf("\n");
	system("pause");
	system("cls");

}

void editarProductos(){
    printf("Editar producto\n");
	int idProducto = buscarProducto();
	if(idProducto != -1){
        printf("producto No. %d\n", idProducto+ 1);
        printf("nombre del producto\n");
        fgets(productos[idProducto].nombre, 30, stdin);
        printf("codigo del producto\n");
        scanf("%d",&productos[idProducto].codigo);
        printf("valor del producto\n");
        scanf("%d",&productos[idProducto].precio);
        printf("\n\n");
	}

}
void mostrarProductos(){
    int i;
	printf("Mostrar Clientes\n");
	for(i = 0; i < cantProductos; i++){
		printf("producto No. %d\n", productos[i].id + 1);
		printf("Nombre del producto: %s\n", productos[i].nombre);
		printf("codigo del producto: %d\n", productos[i].codigo);
		printf("valor del producto: %d\n", productos[i].precio);
		printf("\n\n");
	}
}
void mostrarProducto(int idProducto){
    int i;
    printf("Mostrar productos\n");
	for(i = 0; i < cantProductos; i++){
		printf("Cliente No. %d\n", productos[i].id + 1);
		printf("nombre del producto\n", productos[i].nombre);
		printf("codigo del producto\n", productos[i].codigo);
        printf("valor del producto\n", productos[i].precio);
        printf("\n\n");

}
}

int buscarProducto(){
    int productoBuscar, i;
	printf("Buscar producto\n");
	printf("Ingrese codigo del producto: ");
	scanf("%d", &productoBuscar);
	printf("\n");
	for(i = 0; i < cantProductos; i++){
		if(productoBuscar == productos[i].codigo){
			mostrarProducto(productos[i].id);
			return productos[i].id;
		}
	}
	printf("El producto no existe \n");
	return -1;
}
