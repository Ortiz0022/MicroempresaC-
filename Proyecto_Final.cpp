#include <iostream>
#include <vector>
#include <cstdlib>  //Para el numero random
#include <ctime>    //Para el numero random
#include <cmath>
#include <stdio.h>   //Para cambiar el color de fondo
using namespace std; 

class Persona {  //Clase que heredara a las clases administrador y cliente
	protected: 
		string nombre;
		string apellido;
		string direccion;
		int num;
		
	public:
		Persona (string _nombre, string _apellido, string _direccion, int _num){ //Contructor de la clase
			this->nombre=_nombre;
			this->apellido=_apellido;
			this->direccion=_direccion;
			this->num=_num;
		}
		
		void getDatos(){   //Para mostrar los datos almacenados
			cout<<"Nombre:          "<<nombre<<endl;
			cout<<"Apellidos:       "<<apellido<<endl;
			cout<<"Direccion:       "<<direccion<<endl;
			cout<<"Numero de contacto: "<<num<<endl;
		}
};

class Administrador : public Persona {  //Subclase Administrador
	private: 
		string password;
		
	public:
		Administrador(string _nombre, string _apellido, string _direccion, int _num) : Persona(_nombre, _apellido, _direccion, _num){
			this->password ="Shir8008"; // Contraseña ingresada de sistema.
		}
		
	void getDatosAdmin(){ //Para llamar al obtener datos de la clase Persona
		Persona::getDatos();
	}

	string getPassword(){ //Para poder hacer la comprobación de la contraseña, llamamos a este método
		return password;
	}
	
};

class Cliente : public Persona {  //Subclase Cliente
	private:
		string estadoCli;
		double codCliente = rand() % 100000 + 100; //Genera numero random para el código

	public:
		Cliente(string _nombre, string _apellido, string _direccion, int _num, string _estadoCli) : Persona(_nombre, _apellido, _direccion,_num){
			this->estadoCli=_estadoCli;
		}
		
	double getCodCliente() //Para retornar el codigo del cliente
	{
	return this->codCliente;	
	}
		
	void getDatosCliente(){ //Para mostrar los datos del cliente y el codigo generado
		cout<<"CLIENTE "<<estadoCli<<endl;
		Persona::getDatos();  //Se llama al método getDatos de persona
		
	}
	
};

class Articulo {  //Clase que heredara a Pedidos
	protected:
		float precio;
		string tipo;
		int cantidad;
		double codigo; 
	public:
		Articulo(float _precio, string _tipo, int _cantidad, double _codigo){ //Constructor de la clase
			this->precio=_precio;
			this->tipo=_tipo;
			this->cantidad=_cantidad;
			this->codigo=_codigo;
		}
		
	void getMostrarDatos(){  //Método para mostrar inventario de articulos.
		cout<<"  ||Producto:      "<<tipo<<endl;
		cout<<"  ||Cantidad:      "<<cantidad<<endl;
		cout<<"  ||Codigo:        "<<codigo<<endl;
		cout<<"  ||Precio:        "<<precio<<" colones."<<endl; 
	}

	int getCodigo() {
        return codigo;
    }

    float getPrecio() {
        return precio;
    }

    string getTipo() {
        return tipo;
    }	
    
    int getCantidad(){
    	return cantidad;
	}
	
	void agregarCantidad(int cant){
		this->cantidad+=cant; //cantidad= cantidad + cant;
	}
	
	void quitarCantidad(int cant){
		this->cantidad-=cant; //cantidad= cantidad - cant;
	}
};

class Pedidos : public Articulo { //Subclase destinada para los pedidos del cliente
	private:
		string fechaPedido;	
		float subtotalP;
		double codCli;
	public:
		Pedidos(float _precio, string _tipo, int _cantidad, double _codigo, string _fechaPedido, float _subtotalP, double _codCli) : Articulo (_precio, _tipo, _cantidad, _codigo){
			this->fechaPedido=_fechaPedido;
			this->subtotalP=_subtotalP;
			this->codCli=_codCli;
		}
	
	void getCatalogo(){ //Para mostrar inventario al cliente
		Articulo::getMostrarDatos();
	}
		
	void getIngresarPedido(){ //Para mostrar un desgloce de cada articulo en cada pedido
		subtotalP = precio * cantidad;
		cout<<"-----------------------------------"<<endl;
		cout<<"CODIGO CLIENTE: "<<codCli<<endl<<endl;
		cout<<"  ||Fecha de entrega: "<<this->fechaPedido<<endl;
		cout<<"  ||Producto:      "<<this->tipo<<endl;
		cout<<"  ||Codigo:        "<<this->codigo<<endl;
		cout<<"  ||Precio:        "<<this->precio<<" colones."<<endl; 
		cout<<"  ||Cantidad:      "<<this->cantidad<<endl;
		cout<<"  ||TOTAL:           "<<this->subtotalP<<" colones."<<endl;
		cout<<"-----------------------------------"<<endl;	
	}
};


class Ventas{ //Clase para inventario de ventas en dias festivos
	private:
		string registroProducto;
		float subtotal;
		int cantidadV;
		float total;
		string fecha;
		
	public:
		Ventas (string _registroProducto, float _subtotal, int _cantidadV, string _fecha){ //Constructor de la clase
			this->registroProducto=_registroProducto;
			this->subtotal=_subtotal;
			this->cantidadV=_cantidadV;
			this->fecha=_fecha;
			this->total;
		}
		
	void getSaldoVendido(){ //Desgloce del saldo
		total = subtotal * cantidadV;
		cout<<"  Fecha:        "<<fecha<<endl;
		cout<<"  Producto:     "<<registroProducto<<endl;
		cout<<"  Precio:       "<<subtotal<<endl;
		cout<<"  Cantidad:     "<<cantidadV<<endl;
		cout<<" SUBTOTAL=      "<<total<<" colones."<<endl;
	}
		
	float getSaldoTotal() //Saldo total
	{
		return this->total;
	}
};

class Reutilizados //Clase para mensajes reutilizados del programa
{
	public:
		void opcionValida(){
			system("cls");
			cout<<"\n-----------------------------------"<<endl;
			cout<<"    Ingrese una opcion valida."<<endl;
			cout<<"-----------------------------------"<<endl;
		}
	
		void datosIngresados(){
			system("cls");
			cout<<"\n-----------------------------------"<<endl;
			cout<<"  Datos almacenados correctamente."<<endl;
			cout<<"-----------------------------------"<<endl;
		}
			
		void noIngresados(){
			system("cls");
			cout<<"\n-----------------------------------"<<endl;
			cout<<"     No hay datos ingresados."<<endl;
			cout<<"-----------------------------------"<<endl;
		}
				
		void datosActualizados(){
			system("cls");
			cout<<"\n-----------------------------------"<<endl;
			cout<<" Inventario actualizado con exito."<<endl;
			cout<<"-----------------------------------"<<endl<<endl;
		}
};

//AQUI INICIA EL MAIN
main(){
	//VECTORES DEL PROGRAMA
	vector <Pedidos> ListaPedidos;
	vector <Ventas> ListaVentas;
	vector <Administrador> ListaAdministrador;
	vector <Cliente> ListaCliente;
	vector <Articulo> ListaArticulo;
	
	//Instancias del programa

	string registroProducto;
	float subtotal;
	int cantidadV;
	float total;
	string fecha;
	double codCli;
		
	Ventas ventas = Ventas(registroProducto, subtotal, cantidadV, fecha); //Instancia de ventas
	
	string pass, nom, apellidos, direccion;
	int num;
	string estadoCli;
		
	Cliente clien= Cliente(nom, apellidos, direccion, num, estadoCli);
	
	Administrador admin = Administrador(nom, apellidos, direccion, num); //Instancia de administrador
	
	int cantidad, codigo;
	float precio;
	string tipo;
	
	Articulo articulo = Articulo(precio, tipo, cantidad, codigo);
	
	float precioP;
	int cantidadP;
	string fechaPedido;
	double codP;
	float subtotalP;
	string articuloP;
	
	Pedidos pedidos = Pedidos(precioP, articuloP, cantidadP, codP, fechaPedido, subtotalP, codCli);
	
	Reutilizados reutilizados = Reutilizados();
	
	system("color 70");  //Para generar el color de fondo
	int opcion;
	srand(time(0)); //Para el random
	
	//Mensaje de bienvenida, INICIO DEL PROGRAMA
		system("cls");
	cout<<"\n\n           BIENVENIDO"<<endl;
	cout<<"=================================="<<endl;
	cout<<" Sistema de Control de Inventario "<<endl;
	cout<<"        para Microempresas"<<endl;
	cout<<"==================================\n\n"<<endl<<endl<<endl;
	system("pause");
	
	do{ // DO MENU PRINCIPAL
	menu:
		system("cls");
	cout<<"\n-----------------------------------"<<endl;
	cout<<"          MENU PRINCIPAL"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"1. Ingresar como administrador."<<endl;
	cout<<"2. Ingresar como cliente."<<endl<<endl;
	cout<<"3. Salir del sistema."<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"Ingrese una opcion: "<<endl;
	cin>>opcion;
	
	switch(opcion){ //AQUI INICIA SWITCH MENU PRINCIPAL
	
		case 1: { //CASE 1 MENU PRINCIPAL
		int opcionA;
				do{ //DO A
				system("cls");
				int opcionM;
				do{ // MENU REGISTRO
				system("cls");
					cout<<"\n-----------------------------------"<<endl;
					cout<<"      REGISTRO ADMINISTRADOR"<<endl;
					cout<<"-----------------------------------"<<endl;
					cout<<"1. Registrarme."<<endl;
					cout<<"2. Ya estoy registrado."<<endl<<endl;
					cout<<"3. Volver al menu principal."<<endl;
					cout<<"-----------------------------------"<<endl;
					cout<<"Ingrese una opcion: "<<endl;
					cin>>opcionM;
					cin.ignore();
				
				switch(opcionM){
					case 1: { //CASE 1 MENU REGISTRO
							if(ListaAdministrador.empty()) { 
							system("cls");
							cout<<"\nIngrese su nombre: ";
							getline(cin, nom);
							cout<<"\nIngrese sus apellidos: ";
							getline(cin, apellidos);
							cout<<"\nIngrese su direccion: ";
							getline(cin, direccion);
							cout<<"\nIngrese su numero de telefono: ";
							cin>>num;
							Administrador admin = Administrador(nom, apellidos, direccion, num); //Instancia para guardar los datos en este lugar
							ListaAdministrador.push_back(admin); //Para guardar los datos con el vector
							
							reutilizados.datosIngresados(); //LLAMAR CLASE REUTILIZADOS
							system("pause");
							break;
						}
						else{
							system("cls");
							cout<<"\n--------------------------------------"<<endl;
							cout<<"  Ya hay una persona registrada"<<endl;
							cout<<"--------------------------------------"<<endl<<endl;
						}
						system("pause");
						break;
					} //AQUI TERMINA CASE 1 MENU REGISTRO
					
					case 2:{ //CASE 2 MENU REGISTRO, YA ESTOY REGISTRADO
						system("cls");
					cout<<"\n\nCONTRASENIA: "; //Ingreso de contraseña a comparar
					cin>>pass;
					
					if (admin.getPassword()==pass){ //Comparación de la contraseña
						volverA://Volver a este campo
					system("cls");
						cout<<"\n----------------------------------------"<<endl;
						cout<<"          MENU ADMINISTRADOR"<<endl;
						cout<<"----------------------------------------"<<endl;
						cout<<"1. Ingresar productos al inventario."<<endl;
						cout<<"2. Actualizar inventario."<<endl;
						cout<<"3. Ver inventario."<<endl;
						cout<<"4. Ver pedidos."<<endl;
						cout<<"5. Ingresar productos vendidos en el dia."<<endl;
						cout<<"6. Ver productos vendidos en el dia."<<endl;
						cout<<"7. Ver saldo vendido en el dia."<<endl<<endl;
						cout<<"8. Volver al menu principal."<<endl;
						cout<<"----------------------------------------"<<endl;
						cout<<"Ingrese una opcion: "<<endl;
						cin>>opcionA;
						cin.ignore();
						
						switch(opcionA){
							case 1:{ //CASE 1 ADMINISTRADOR
							bool encontrado = false;
							
								system("cls");
								cout<<"\nIngrese el tipo de producto: ";
								getline(cin, tipo);
								cout<<"\nIngrese el precio: ";
								cin>>precio;
								cout<<"\nIngrese la cantidad: ";
								cin>>cantidad;
								cout<<"\nIngrese el codigo del producto registrado (Mas de dos numeros): ";
								cin>>codigo;
								for(int i=0; i<ListaArticulo.size(); i++) 
								{
									if(ListaArticulo[i].getCodigo() == codigo){ //Comparación
												encontrado = true;
									break;	
									}
								}
								
							if(!encontrado){
								Articulo articulo = Articulo(precio, tipo, cantidad, codigo); 
								ListaArticulo.push_back(articulo);
									
								reutilizados.datosIngresados();
							}	
							else{
								cout<<"-----------------------------------"<<endl;
								cout<<" El codigo ya esta en el sistema."<<endl;
								cout<<"-----------------------------------"<<endl;
								system("pause");
								system("cls");
								cout<<"\n\nSi desea actualizar datos, utilice la opcion 2 del menu administrador."<<endl<<endl;
							}
						system("pause");
						goto volverA;
					}//AQUI TERMINA EL CASE 1 ADMINISTRADOR
					
					case 2: { //CASE 2 ADMINIISTRADOR
						system("cls");
						int opcionDatos;
						cout<<"\n-----------------------------------"<<endl;
						cout<<"        EDITAR INVENTARIO"<<endl;
						cout<<"-----------------------------------"<<endl;
						cout<<"1. Agregar productos."<<endl;
						cout<<"2. Quitar productos."<<endl<<endl;
						cout<<"3. Volver al menu administrador."<<endl;
						cout<<"-----------------------------------"<<endl;
						cout<<"Ingrese una opcion: "<<endl;
						cin>>opcionDatos;
										
					switch(opcionDatos){ //SWITCH EDITAR DATOS
						case 1: { //CASE 1 AGREGAR 
							int posicion, cant;
							system("cls");
							cout<<"\n      LISTA DE ARTICULOS"<<endl;
							for(int i=0; i<ListaArticulo.size();i++){ 
								cout<<"-----------------------------------"<<endl;
								cout<<"    Posicion #"<<i+1<<endl;
								ListaArticulo[i].getMostrarDatos(); 
							}
							cout<<"-----------------------------------"<<endl<<endl;			
							cout<<"\nIngrese la posicion del producto que desea actualizar: ";
							cin>>posicion;
							posicion-=1;
							cout<<"\nIngrese la cantidad que desea agregar al inventario: ";
							cin>>cant;
							ListaArticulo[posicion].agregarCantidad(cant);	
							reutilizados.datosActualizados();
							system("pause");
							goto volverA;
							} //AQUI TERMINA CASE 1 AGREGAR D
									
						case 2: { //CASE 2 QUITAR 
							system("cls");
							int posicion, cant;
							cout<<"\n          LISTA DE ARTICULOS"<<endl;
							for(int i=0; i<ListaArticulo.size();i++){ 
								cout<<"-----------------------------------"<<endl;
								cout<<"        Posicion #"<<i+1<<endl;
								ListaArticulo[i].getMostrarDatos(); 
								cout<<"-----------------------------------"<<endl<<endl;
							}
							cout<<"\nIngrese la posicion del producto que desea actualizar: ";
							cin>>posicion;
							posicion-=1;
							cout<<"\nIngrese la cantidad que desea quitar del inventario: ";
							cin>>cant;
							ListaArticulo[posicion].quitarCantidad(cant);	
							reutilizados.datosActualizados();
							system("pause");
							goto volverA;
							} //AQUI TERMINA CASE 2 QUITAR
												
						case 3:{ //CASE 3 EDITAR DATOS
							goto volverA;}
																						
						default: {
							reutilizados.opcionValida();
							break;
							} //TERMINA MENU DE ACTUALIZAR DATOS
				}//SWITCH EDITAR DATOS
					while (opcion!=3); //while editar datos
						system("pause");
						goto volverA;
					}
					
					case 3: { //CASE 3 ADMINISTRADOR
						if(ListaArticulo.empty()) {
						reutilizados.noIngresados();
						system("pause");
						}
						else{
							system("cls");
							cout<<"\n          LISTA DE ARTICULOS"<<endl;
							for(int i=0; i<ListaArticulo.size();i++){ 
								cout<<"--------------------------------------"<<endl;
								ListaArticulo[i].getMostrarDatos(); 
								cout<<"--------------------------------------"<<endl;
							}
						}
						system("pause");
						goto volverA;
					} //AQUI TERMINA CASE 3 
					
					case 4: { //CASE 4 ADMINISTRADOR
						if(ListaCliente.empty()) {
						reutilizados.noIngresados();
						}
						else{
							system("cls");
							cout<<"\n          LISTA DE PEDIDOS"<<endl;
							for (int i = 0; i < ListaCliente.size(); i++) {	
							    cout<<"-----------------------------------"<<endl;
							    cout << "Cliente: " << ListaCliente[i].getCodCliente() << endl;
							    ListaCliente[i].getDatosCliente();	    
							}  
							  
							for (int i=0; i<ListaPedidos.size(); i++){
								ListaPedidos[i].getIngresarPedido();	
							}
						}
						system("pause");
						goto volverA;
					} //AQUI TERMINA CASE 4
					
					case 5: { //CASE 5 ADMINISTRADOR
							if(ListaVentas.empty()) {
								system("cls");
										cout<<"\nIngrese la fecha (DD/MM/AA): ";
										cin>>fecha;
										cin.ignore();
								}
								else{
									system("cls");
									cout<<"\n-----------------------------------"<<endl;
									cout<<"    Ya se ha ingresado una fecha."<<endl;
									cout<<"-----------------------------------"<<endl;
								}	
						cout<<"\nIngrese el tipo de producto: ";
						getline(cin, registroProducto);
						cout<<"\nIngrese el precio: ";
						cin>>subtotal;
						cout<<"\nIngrese la cantidad vendida: ";
						cin>>cantidadV;
						
						Ventas ventas = Ventas(registroProducto, subtotal, cantidadV, fecha); 
						ListaVentas.push_back(ventas);						

						reutilizados.datosIngresados();
						system("pause");	
						goto volverA;
					} //AQUI TERMINA CASE 5
					
					case 6: { //CASE 6 ADMINISTRADOR
								if(ListaVentas.empty()){
									reutilizados.noIngresados();
								}
								else{
									system("cls");
									cout<<"\n          LISTA DE VENTAS"<<endl;
									cout<<"---------------------------------------"<<endl;
									for(int i=0; i < ListaVentas.size(); i++) //Para ver todo lo que se ingreso de ventas
									{
									ListaVentas[i].getSaldoVendido();
									cout<<"---------------------------------------"<<endl;
									}
								}	
						system("pause");
						goto volverA;
					} //AQUI TERMINA CASE 6
					
					case 7: { //CASE 7 ADMINISTRADOR
							if(ListaVentas.empty())	{
									reutilizados.noIngresados();
								}
							else{
									system("cls");
									cout<<"\n             INGRESOS"<<endl;
									int totalt=0;
									for(int i=0; i < ListaVentas.size(); i++){ //Para ver todo lo que se ingreso de ventas
										cout<<"======================================"<<endl;
										ListaVentas[i].getSaldoVendido();
										totalt = totalt + ListaVentas[i].getSaldoTotal();
									}
								cout<<"\n======================================="<<endl;
								cout<<"INGRESOS TOTALES = "<<totalt<<" colones."<<endl;
								cout<<"======================================="<<endl;	
								}	
						system("pause");
						goto volverA;
					} //AQUI TERMINA CASE 7
					
					case 8:{ //CASE 8 ADMINISTRADOR
						goto menu;
					}
					
					default: {
					reutilizados.opcionValida();
						goto volverA;
					}
					system("pause");
					break;
				}//AQUI TERMINA SWITCH ADMINISTRADOR
			} //IF CONTRASENIA
					
					else { //ELSE DEL IF COMPARAR CONTRASEÑA
						cout<<"\n-----------------------------------"<<endl;
						cout<<"        ACCESO DENEGADO."<<endl;
						cout<<"-----------------------------------"<<endl;
						system("pause");
					}	
						goto menu;
					} //AQUI TERMINA EL CASE 2 MENU REGISTRO, YA ESTOY REGISTRADO
					
					case 3:{ //CASE 3 MENU REGISTRO 
						goto menu;
					}
					default:{
						reutilizados.opcionValida();
						break;	
						}	
					}		
				}
				while(opcionM!=3); //while menu registro
			} //AQUI TERMINA DO ADMINISTRADOR
			
			while(opcion!=8);
			break;	
			} //AQUI TERMINA CASE 1 MENU PRINCIPAL

				case 2: { //CASE 2 PRINCIPAL
				int opcionC;
				
				do{ //DO CLIENTE
				menuC:
				system("cls");
				cout<<"\n-------------------------------------------"<<endl;
				cout<<"         MENU DEL CLIENTE"<<endl;
				cout<<"-------------------------------------------"<<endl;
				cout<<"Si desea realizar pedidos debe registrarse."<<endl;
				cout<<"-------------------------------------------"<<endl;
				cout<<"1. Registrarme."<<endl;
				cout<<"2. Ver catalogo."<<endl;
				cout<<"3. Pedir productos."<<endl;
				cout<<"4. Ver informacion del administrador."<<endl<<endl;
				cout<<"5. Volver al menu principal."<<endl;
				cout<<"-------------------------------------------"<<endl;
				cout<<"Ingrese una opcion: "<<endl;
				cin>>opcionC;
				cin.ignore();
				
				switch(opcionC){ //SWITCH CLIENTE
					case 1: { //CASE 1 CLIENTE
						system("cls");
						
						cout<<"\nIngrese su nombre: ";
						getline(cin, nom);
						cout<<"\nIngrese sus apellidos: ";
						getline(cin, apellidos);
						cout<<"\nIngrese su direccion: ";
						getline(cin, direccion);
						cout<<"\nIngrese su numero de telefono: ";
						cin>>num;
						cout<<"\nEs usted cliente frecuente o nuevo? \n(Ingrese FRECUENTE o NUEVO): ";
						cin>>estadoCli;
						Cliente cliente= Cliente(nom, apellidos, direccion, num, estadoCli); 
						ListaCliente.push_back(cliente); 
						
						reutilizados.datosIngresados(); 

						cout<<"\nDebe usar este codigo para realizar los pedidos. \nSolo se mostrara una vez!"<<endl;
						cout<<"\n-----------------------------------"<<endl;
						cout<<"Codigo usuario: "<<ListaCliente[ListaCliente.size()-1].getCodCliente()<<endl; //MUESTRA EL ÚLTIMO CÓDIGO QUE SE GENERÓ
						cout<<"-----------------------------------"<<endl;
						system("pause");
						break;
					} //AQUI TERMINA CASE 1 CLIENTE
					
					case 2: { //CASE 2 CLIENTE
						if(ListaArticulo.empty()) {
							reutilizados.noIngresados();
						}
						else{
							system("cls");
							cout<<"\n      CATALOGO DE PRODUCTOS"<<endl;
							cout<<"-----------------------------------"<<endl;
							for(int i=0; i<ListaArticulo.size();i++){ //Para mostrar los articulos almacenados
							ListaArticulo[i].getMostrarDatos(); 
							cout<<"-----------------------------------"<<endl;
							}
						}
						system("pause");
						break;
					} //AQUI TERMINA CASE 2 CLIENTE
					
					case 3: { //CASE 3 CLIENTE	
						int cantidadP;
						int codCliente;
						system("cls");
						cout<<"\nIngrese su codigo de usuario: ";
						cin>>codCliente;
						
						for (int i=0; i<ListaCliente.size(); i++){
							if (ListaCliente[i].getCodCliente()==codCliente){ //Comparacion 
								cout <<"\nIngrese el codigo del articulo que desea: ";
								cin>>codP;
								
								if(ListaArticulo.empty()){
									reutilizados.noIngresados();	
								}
								else {	
									for (int i = 0; i < ListaArticulo.size(); i++) {
									if (ListaArticulo[i].getCodigo() == codP) {  //Comparacion
							    		ListaArticulo[i].getMostrarDatos();
							    		cout<<"\nIngrese la cantidad que desea comprar: ";
								        cin>>cantidadP;
								        cantidad = ListaArticulo[i].getCantidad();
								        
								        if(cantidad>=cantidadP){
								        	cout<<"\nIngrese la fecha para la que necesita el pedido (DD/MM/AA): ";
								        	cin>>fechaPedido;
								        	
									        precioP = ListaArticulo[i].getPrecio();
			        						articuloP = ListaArticulo[i].getTipo();
											
									        Pedidos pedidos =Pedidos(precioP, articuloP, cantidadP, codP, fechaPedido, subtotalP, codCliente);
									    	pedidos.getIngresarPedido();
										    ListaPedidos.push_back(pedidos);
									        system("pause");
									        
									 		reutilizados.datosIngresados();
										}
										else {
											cout<<"\n-------------------------------------------------"<<endl;
									        cout<<"La cantidad solicitada es superior al inventario." << endl;
									        cout<<"-------------------------------------------------"<<endl;
									        system("pause");
									        break;
										}
									} 
								} //segundo for
								} //primer else	
							} //primer if
							
						}	//primer for
						system("pause");
						break;
					} //AQUI TERMINA CASE 3 CLIENTE
					
					case 4: { //CASE 4 CLIENTE
						if(ListaAdministrador.empty()) {
							reutilizados.noIngresados();
						}
						else{
							system("cls");
						cout<<"\n     DATOS DEL ADMINISTRADOR"<<endl;
						int i=0;
						cout<<"======================================="<<endl;
						ListaAdministrador[i].getDatosAdmin(); //Para obtener los datos del administrador
						cout<<"======================================="<<endl;
						}
						system("pause");
						break;
					} //AQUI TERMINA CASE 4 CLIENTE
					
					case 5: { //CASE 5 CLIENTE
						goto menu;
					}
					
					default:{
					reutilizados.opcionValida();
						system("pause");
						break;
					}
					} //AQUI TERMINA SWITCH CLIENTE
				}//AQUI TERMINA DO C
				while(opcion != 5);  //WHILE CLIENTE
			break;
		} //AQUI TERMINA EL CASE 2 PRINCIPAL
		
		case 3: { //CASE 3 MENU PRINCIPAL
			system("cls");
			cout<<"\n==================================="<<endl;
			cout<<"      PROGRAMA FINALIZADO."<<endl;
			cout<<"===================================\n\n"<<endl;
			system("pause");
			break;
		} //AQUI TERMINA EL CASE 3 PRINCIPAL
		
		default: {
			reutilizados.opcionValida();
			system("pause");
			break;
		}//AQUI TERMINA DEFAULT PRINCIPAL	
	} //AQUI TERMINA EL SWITCH PRINCIPAL
	}while(opcion!=3); //WHILE MENU PRINCIPAL

} //AQUI TERMINA EL MAIN.