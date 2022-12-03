#include <iostream>
using namespace std;

class PyME {
    private:
        string nombreP, razonSocial, direccion, director;
        int cantTrabajadores, pesosGenerados;

    public:
        PyME():nombreP(""),razonSocial(""),direccion(""),director(""),cantTrabajadores(0),pesosGenerados(0){}
        PyME(string nom, string razSoc, string direc, string director, int numT, int pesos):nombreP(nom),razonSocial(razSoc),direccion(direc),director(director),cantTrabajadores(numT),pesosGenerados(pesos){}
        string get_nombreP(){return nombreP;}
        string get_razonSocial(){return razonSocial;}
        string get_direccion(){return direccion;}
        string get_director(){return director;}
        int get_cantTrabajadores(){return cantTrabajadores;}
        int get_pesosGenerados(){return pesosGenerados;}
        void set_nombreP(){cin >> nombreP;}
        void set_razonSocial(){cin >> razonSocial;}
        void set_direccion(){cin >> direccion;}
        void set_director(){cin >> director;}
        void set_cantTrabajadors(){cin >> cantTrabajadores;}
        void set_pesosGenerados(){cin >> pesosGenerados;}
};

class Trabajador: public PyME {
    private:
        string nombreT, puesto, nombreEmpresa, direccionEmpresa, razonSocialEmpresa;
        int edad, sueldo;

    public:
        string get_nombreT(){return nombreT;}
        string get_puesto(){return puesto;}
        string get_nombreEmpresa(){return nombreEmpresa;}
        string get_direccionEmpresa(){return direccionEmpresa;}
        string get_razonSocialEmpresa(){return razonSocialEmpresa;}
        int get_edad(){return edad;}
        int get_sueldo(){return sueldo;}
        void set_nombreT(){cin >> nombreT;}
        void set_puesto(){cin >> puesto;}
        void set_edad(){cin >> edad;}
        void set_sueldo(){cin >> sueldo;}
        void set_datosEmpresa(string nombre, string direccion, string razon){
            nombreEmpresa = nombre;
            direccionEmpresa = direccion;
            razonSocialEmpresa = razon;
        }
};

int menu(){
    int op;
    cout << "-------------------------------" << endl;
    cout << "1. Agregar PyME" << endl;
    cout << "2. Agregar Trabajador" << endl;
    cout << "3. Consultar PyME" << endl;
    cout << "4. Consultar Trabajador" << endl;
    cout << "5. Salir" << endl;
    cout << "-------------------------------" << endl;
    cout << "Ingrese una opción: ";
    cin >> op;
    cout << "-------------------------------" << endl;
    return op;
}


// Se declaran de manera global (fuera del main) para poder usarlos dentro de las clases
PyME contadorP[20];
Trabajador contadorT[400];
int op, numPyMES = 0, numTrabajadores = 0, buscador = 0;
string nom;

int main(){
    while(true){
        op = menu();
        switch(op){
            case 1:
                cout << "Ingrese el nombre de la PyME: ";
                contadorP[numPyMES].set_nombreP();
                cout << "Ingresa la razón social de la Empresa: ";
                contadorP[numPyMES].set_razonSocial();
                cout << "Ingresa la dirección de la Empresa: ";
                contadorP[numPyMES].set_direccion();
                cout << "Ingresa el nombre del Director: ";
                contadorP[numPyMES].set_director();
                cout << "Ingresa el número de Trabajadores: ";
                contadorP[numPyMES].set_cantTrabajadors();
                cout << "Ingresa la cantidad de pesos que genera al año: ";
                contadorP[numPyMES].set_pesosGenerados();
                cout << "-------------------------------" << endl;
                cout << "PyME guardada" << endl;
                numPyMES = numPyMES + 1;
                break;
            case 2:
                cout << "Ingrese el nombre de la PyME a la que pertenece el empleado: ";
                cin >> nom;
                for(int i = 0; i < 20; i++){
                    if (contadorP[i].get_nombreP() == nom){
                        cout << "Ingresa el nombre del empleado: ";
                        contadorT[numTrabajadores].set_nombreT();
                        cout << "Ingresa el puesto del empleado: ";
                        contadorT[numTrabajadores].set_puesto();
                        cout << "Ingresa la edad del empleado: ";
                        contadorT[numTrabajadores].set_edad();
                        cout << "Ingresa el sueldo del empleado: ";
                        contadorT[numTrabajadores].set_sueldo();
                        contadorT[numTrabajadores].set_datosEmpresa(contadorP[i].get_nombreP(),contadorP[i].get_direccion(),contadorP[i].get_razonSocial());
                        cout << "-------------------------------" << endl;
                        cout << "Empleado guardado" << endl;
                        numTrabajadores = numTrabajadores + 1;
                        buscador = 1;
                    }
                }
                if(buscador == 0){
                    cout << "Esta PyME no esta registrada" << endl;
                }
                buscador = 0;
                break;
            case 3:
                cout << "Ingresa el nombre del PyME que deseas consultar: ";
                cin >> nom;
                cout << "-------------------------------" << endl;
                for(int i = 0; i < 20; i++){
                    if (contadorP[i].get_nombreP() == nom){
                        cout << "Nombre de la empresa: " << contadorP[i].get_nombreP() << endl;
                        cout << "Razón social: " << contadorP[i].get_razonSocial() << endl;
                        cout << "Dirección: " << contadorP[i].get_direccion() << endl;
                        cout << "Director: " << contadorP[i].get_director() << endl;
                        cout << "Número de trabajadores: " << contadorP[i].get_cantTrabajadores() << endl;
                        cout << "Pesos generados al año: $" << contadorP[i].get_pesosGenerados() << endl;
                        buscador = 1;
                    }
                }
                if(buscador == 0){
                    cout << "Esta PyME no esta registrada" << endl;
                }
                buscador = 0;
                break;
            case 4:
                cout << "Ingrese el nombre del empleado que deseas buscar: ";
                cin >> nom;
                for(int i = 0; i < 400; i++){
                    if (contadorT[i].get_nombreT() == nom){
                        cout << "Nombre: " << nom << endl;
                        cout << "Nombre de la empresa: " << contadorT[i].get_nombreEmpresa() << endl;
                        cout << "Edad: " << contadorT[i].get_edad() << endl;
                        cout << "Puesto: " << contadorT[i].get_puesto() << endl;
                        cout << "Sueldo: " << contadorT[i].get_sueldo() << endl;
                        cout << "Dirección de la Empresa: " << contadorT[i].get_direccionEmpresa() << endl;
                        cout << "Razón Social de la Empresa: " << contadorT[i].get_razonSocialEmpresa() << endl;
                        buscador = 1;
                    }
                }
                if(buscador == 0){
                    cout << "Esta empleado no esta registrado" << endl;
                }
                buscador = 0;
                break;
            case 5:
                cout << "Programa terminado" << endl;
                cout << "-------------------------------" << endl;
                return false;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    }
}