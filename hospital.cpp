#include <iostream>
#include <conio.h>
using namespace std;
 
struct registro{
	char nombre[35];
	char condicionC[50];
	string documento,fechaN;
	string direccion,telefono,eps;
	char tipoD[35];
	int piso,Eps1,Regimen,nivel;
	int piso1;
};
registro paciente[20];
int main(){
 void registro();
 void listado();
 void consulta();
 void mostrar();
 void disponibilidad1();
 void disponibilidad2();
 void disponibilidad3();
 void disponibilidad4();
        cout<<"\nHOSPITAL \t\n";
		cout<<"1.REGISTRAR PACIENTE\n";
		cout<<"2.LISTADO DE PACIENTES\n";
		cout<<"3.CONSULTA INFORMACION DE PACIENTES\n";
		cout<<"4.MOSTRAR DISPONIBILIDAD DE CAMAS\n";
		cout<<"5.SALIR\n";
		cout<<"Escoja una opcion\n";
		cin>>opcion;
     switch(opcion) {
	        case 1:cout<<"\nREGISTRO DE PACIENTES\n";
			registro();
			break;
			case 2:cout<<"LISTADO DE PACIENTES\n";
			listado();
			break;
			case 3:cout<<"CONSULTA INFORMACION DE PACIENTES\n";
			consulta();
			break;
			case 4:cout<<"MOSTRAR DISPONIBILIDAD DE CAMA\n";
			mostrar();
			break;
			case 5:cout<<"\t\nSALIENDO\n";
			return 0;
			break;
			default:cout<<"\tERROR DE OPCION\n\n";
			break;
		}
		cout<<"Desea regresar al menu\n";
		cout<<"1.SI/2.NO\n";
		cin>>op1;


	return 0;
	}