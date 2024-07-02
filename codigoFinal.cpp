#include <iostream>
#include <string>
#include <vector> 
using namespace std;
struct Paciente {
    string nombre;
    int edad;
    string domicilio;
    string curp;
    string sexo;
    string motivo;
    string familiares;
    string gradoestudio;
    string telefono;
int camaAsignada; 
};

static const int totalCamas = 20; 
static int camasDisponibles = totalCamas;
static int camasOcupadas = 0;

void mostrarDisponibilidadCamas() {
    cout << "Disponibilidad de camas:" << endl;
    cout << "Camas ocupadas: " << camasOcupadas << endl;
    cout << "Camas disponibles: " << camasDisponibles << endl;
}

void registrarPaciente(vector<Paciente>& pacientes) {
    Paciente nuevoPaciente;
    cout << "Registro de pacientes\n";
    cout << "Ingresar todos los datos del paciente\n";

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevoPaciente.nombre);

    cout << "Edad: ";
    cin >> nuevoPaciente.edad;

    cin.ignore();
    cout << "Curp: ";
    getline(cin, nuevoPaciente.curp);

    cout << "Sexo: ";
    getline(cin, nuevoPaciente.sexo);

    cout << "Motivo de su visita: ";
    getline(cin, nuevoPaciente.motivo);

    cout << "Domicilio: ";
    getline(cin, nuevoPaciente.domicilio);

    cout << "Familiar responsable: ";
    getline(cin, nuevoPaciente.familiares);

    cout << "Grado de estudio: ";
    getline(cin, nuevoPaciente.gradoestudio);

    cout << "Número de teléfono: ";
    getline(cin, nuevoPaciente.telefono);

    
    if (camasDisponibles > 0) {
        
        nuevoPaciente.camaAsignada = totalCamas - camasDisponibles + 1;

        
        camasDisponibles--;
        camasOcupadas++;

        pacientes.push_back(nuevoPaciente);

        cout << "Paciente registrado con éxito. Se le asignó la cama número " << nuevoPaciente.camaAsignada << endl;
    } else {
        cout << "Lo sentimos, no hay camas disponibles actualmente.\n";
    }
}

void mostrarPacientes(const vector<Paciente>& pacientes) {
    cout << "\nLista de pacientes registrados:\n";
    for (const auto& paciente : pacientes) {
        cout << "Nombre: " << paciente.nombre << endl;
        cout << "Edad: " << paciente.edad << endl;
        cout << "Curp: " << paciente.curp << endl;
        cout << "Sexo: " << paciente.sexo << endl;
        cout << "Motivo de visita: " << paciente.motivo << endl;
        cout << "Domicilio: " << paciente.domicilio << endl;
        cout << "Familiar responsable: " << paciente.familiares << endl;
        cout << "Grado de estudio: " << paciente.gradoestudio << endl;
        cout << "Número de teléfono: " << paciente.telefono << endl;
        cout << "----------------------------------\n";
    }
}
string obtenerficha(int horallegada) {
    static int fichamañana = 1;
    static int fichatarde = 1;
    static int fichanoche = 1;

    int hora = horallegada;

    if (hora >= 7 && hora <= 13) {
        cout << "Se asigna la ficha numero " << fichamañana << " para el turno mañana" << endl;
        fichamañana++;
        return "Turno mañana";
    } else if (hora >= 14 && hora <= 19) {
        cout << "Se asigna la ficha numero " << fichatarde << " para el turno de la tarde" << endl;
        fichatarde++;
        return "Turno tarde";
    } else if (hora >= 20 && hora <= 24) {
        cout << "Se asigna la ficha numero " << fichanoche << " para el turno de la noche" << endl;
        fichanoche++;
        return "Turno noche";
    } else {
        cout << "Hora de llegada no válida" << endl;
        return "Invalido";
    }
}



int main() {
    vector<Paciente> pacientes; 
    int opcion;

    string user, contraseña;
    int op1, op2, op3;

    
    int intentos = 0;
    const int maximoIntentos = 3;

    do {
        cout << "Ingrese su usuario: ";
        cin >> user;
        cout << "Ingrese su contraseña: ";
        cin >> contraseña;

        if (user == "hospitalSIGIH" && contraseña == "12345") {
            cout << "Bienvenido\n";
            break;
        } else {
            intentos++;
            int intentosRestantes = maximoIntentos - intentos;
            if (intentosRestantes > 0) {
                cout << "Los datos ingresados son incorrectos. Quedan "
                     << intentosRestantes << " intentos.\n";
            } else {
                cout << "El número de intentos permitidos se ha excedido. Cerrando sesión.\n";
                exit(0);
            }
        }
    } while (intentos < maximoIntentos);

    do {
        cout << "\nSeleccione el tipo de usuario:\n";
        cout << "1. Recepcionista\n";
        cout << "2. Enfermera\n";
        cout << "3. Doctor\n";
        cout << "4. Salir del sistema\n";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Opción de recepcionista seleccionada\n";
                cout << "Elija la opción necesaria\n";
                cout << "1. Registrar al paciente\n";
                cout << "2. Dar ficha al paciente\n";
                cout << "3. Mostrar disponibilidad de camas\n";
                cout << "4. Mostrar pacientes registrados\n";
                cin >> op1;

                switch (op1) {
                    case 1: {
                        registrarPaciente(pacientes);
                        break;
                    }
                    case 2: {
                        int horallegada;
                        cout << "Dar ficha al paciente\n";
                        cout << "Ingrese la hora en la que llegó (formato de 24 horas): ";
                        cin >> horallegada;

                        string ficha = obtenerficha(horallegada);
                        cout << "FICHA ASIGNADA AL PACIENTE QUE LLEGÓ A LAS " << horallegada << ":00 de la " << ficha << endl;
                        break;
                    }
                    case 3: {
                        cout << "Mostrar disponibilidad de camas\n";
                        
                        break;
                    }
                    case 4:{
                        cout << "Mostrar pacientes registrados\n";
                        mostrarPacientes(pacientes);
                    }
                    default:
                        cout << "Opción no válida. Intente nuevamente.\n";
                        break;
                }
                break;
            }
            case 2: {
                char continuar;
                int medicosDisponibles = 20;

                do {
                    cout << "Opción de Enfermera seleccionada\n";
                    cout << "Seleccione la opción necesaria\n";
                    cout << "1. Tomar signos vitales\n";
                    cout << "2. Educación al paciente\n";
                    cout << "3. Salir del sistema\n";
                    cin >> op2;

                    switch (op2) {
                        case 1: {
                            string nombre;
                            int presion, peso, estatura, oxigeno, temperatura;
                            do {
                                cout << "Tomar los signos vitales:\n";
                                cout << "Ingrese el nombre del paciente: ";
                                cin.ignore();
                                getline(cin, nombre);
                                cout << "Ingrese la presión arterial: ";
                                cin >> presion;
                                cout << "Ingrese el peso del paciente (en Kg): ";
                                cin >> peso;
                                cout << "Ingrese la estatura (en metros): ";
                                cin >> estatura;
                                cout << "Ingrese el nivel de oxígeno: ";
                                cin >> oxigeno;
                                cout << "Ingrese la temperatura corporal: ";
                                cin >> temperatura;
                                cout << "Signos vitales registrados correctamente\n";

                                medicosDisponibles--;
                                cout << "Médicos disponibles: " << medicosDisponibles << endl;
                                cout << "¿Desea tomar los signos vitales de otro paciente? (s/n): ";
                                cin >> continuar;
                            } while (continuar == 's' || continuar == 'S');
                            break;
                        }
                        case 2: {
                            int opcion3;
                            cout << "Educación al paciente\n";
                            cout << "Elija un tema de educación:\n";
                            cout << "1. Educación sobre la sexualidad\n";
                            cout << "2. Educación sobre la salud mental\n";
                            cout << "3. Educación sobre las enfermedades crónicas\n";
                            cout << "4. Educación sobre la buena alimentación\n";
                            cin >> opcion3;
                            switch (opcion3) {
                                case 1: {
                                    cout << "Educación sobre la sexualidad:\n";
                                    cout << "La sexualidad es una dimensión integral de la persona que abarca el sexo biológico, la identidad de género, el rol de género, la orientación sexual, el erotismo, la intimidad y la reproducción. Es importante entender que la sexualidad va más allá de la actividad sexual y abarca aspectos emocionales, sociales y culturales.\n";
                                    break;
                                }
                                case 2: {
                                    cout << "Educación sobre la salud mental:\n";
                                    cout << "La salud mental se refiere al estado de bienestar emocional, psicológico y social en el que una persona es capaz de enfrentar el estrés, trabajar de manera productiva y contribuir a la comunidad. Incluye la gestión de emociones, el manejo del estrés y la autoestima positiva.\n";
                                    break;
                                }
                                case 3: {
                                    cout << "Educación sobre las enfermedades crónicas:\n";
                                    cout << "Las enfermedades crónicas son afecciones de larga duración que requieren cuidados continuos. Ejemplos comunes incluyen la diabetes, la hipertensión, la artritis, la EPOC y la enfermedad cardíaca.\n";
                                    break;
                                }
                                case 4: {
                                    cout << "Educación sobre la buena alimentación:\n";
                                    cout << "Una alimentación saludable es clave para mantener un peso saludable, prevenir enfermedades crónicas, fortalecer el sistema inmunológico y promover el bienestar general.\n";
                                    break;
                                }
                                default:
                                    cout << "Opción no válida. Intente nuevamente.\n";
                                    break;
                            }
                            break;
                        }
                        case 4: {
                            cout << "Saliendo del sistema.\n";
                            return 0;
                        }
                        default:
                            cout << "Opción no válida. Intente nuevamente.\n";
                            break;
                    }
                } while (op2 != 4);
                break;
            }
            case 3: {
                cout << "Opción de doctor seleccionada.\n";
                cout << "Elija la opción necesaria\n";
                cout << "1. Ver causas de ingreso del paciente\n";
                cout << "2. Recetar medicamento\n";
                cout << "3. Hacer estudios o cirugía\n";
                cout << "4. Agendar otra cita\n";
                cin >> op3;

                switch (op3) {
                    case 1: {
                        cout << "Ver causas de ingreso del paciente\n";
                        cout << "El motivo del ingreso del paciente es: " << pacientes[0].motivo << endl;

                        break;
                    }
                    case 2: {
                        cout << "Recetar medicamentos\n";
                            string name, genero, sintomas, diagnostico, medicacion, dosis, nombreMedico, fecha;
                            int edad, cedulaProfesional;

                            cout << "Ingrese el nombre del paciente: ";
                            cin >> name;  
                            cout << "Ingrese la edad del paciente: ";
                            cin >> edad;

                            cout << "Ingrese el género del paciente: ";
                            cin >> genero;

                            cin.ignore(); 

                            cout << "Ingrese los síntomas del paciente: ";
                            getline(cin, sintomas);  

                            cout << "Ingrese el diagnóstico médico: ";
                            getline(cin, diagnostico);  

                            cout << "Ingrese la medicación recomendada: ";
                            getline(cin, medicacion);

                            cout << "Ingrese la dosis recomendada para la medicación: ";
                            getline(cin, dosis);

                            cout << "Ingrese el nombre del médico: ";
                            getline(cin, nombreMedico);

                            cout << "Ingrese la fecha de la receta: ";
                            getline(cin, fecha);
                            cout << "Ingrese cedula profesional: ";
                            cin >> cedulaProfesional;

                            cout << "Receta registrada correctamente\n";
                            cout << "--------------------------------------\n";
                            cout << "              RECETA MEDICA          \n";
                            cout << "--------------------------------------\n";
                            cout << "Paciente: " << name << endl;
                            cout << "Edad: " << edad << endl;
                            cout << "Género: " << genero << endl;
                            cout << "--------------------------------------\n";
                            cout << "Síntomas: " << sintomas << endl;
                            cout << "Diagnóstico: " << diagnostico << endl;
                            cout << "--------------------------------------\n";
                            cout << "Medicación Recomendada: " << medicacion << endl;
                            cout << "Dosis: " << dosis << endl;
                            cout << "--------------------------------------\n";
                            cout << "Médico: " << nombreMedico << endl;
                            cout << "Fecha: " << fecha << endl;
                            cout << "Cedula Profesional: " << cedulaProfesional << endl;
                            cout << "--------------------------------------\n";
                            break;
                        }
                    case 3:{
                        int diaestudios, diacirugia, cirugia, estudios;
                        string horaestudios, horacirugia;

                        cout << "Hacer estudios o cirugía\n";
                        cout << "El paciente va a nesecitar estudios? 1.SI 2.NO\n";
                        cin >> estudios;
                        if (estudios == 1){
                            cout <<"Que dia van a hacer los estuios?";
                            cout << "1.Lunes 2.Martes 3.Miercoles 4.Jueves 5.Viernes 6.Sabado\n";
                            cin >> diaestudios;
                            cout << "A que hora se le van a realizar los estuios al paciente?";
                            cin >> horaestudios;
                            cout << "Al paciente se le van a hacer los estudios el dia" << diaestudios << "a las " << endl;
                            cout << "El paciente va a nesecitar cirugia? 1.SI 2.NO\n";
                            cin >> cirugia;
                            if (cirugia == 1){
                                cout << "Que dia va hacer la cirugia?";
                                cout << "1.Lunes 2.Martes 3.Miercoles 4.Jueves 5.Viernes 6.Sabado\n";
                                cin >> diacirugia;
                                cout << "A que hora se le realizara la cirugia al paciente?";
                                cin >> horacirugia;
                                cout <<"Al paciente se le va a realizar la cirugia el dia" << diacirugia << " a las " << horacirugia << endl;
                            }else{
                                cout << "El paciente no va a nesecitar de cirugia\n";
                            }

                        }else {
                            cout << "El paciente no va a nesecitar de estudios\n";
                        }

                        break;
                    }
                    case 4: {
                        int cita,diacita;
                            string horacita;
                            cout << "Agendar otra cita\n";
                            cout << "Quiere agendar otra cita? 1.SI 2.NO\n";
                            cin >> cita;
                            if (cita==1){
                            cout << "Para que dia quiere agendar su cita?\n";
                            cout << "Lunes 1, Martes 2, Miercoles 3, Jueves 4, Viernes 5, Sabado 6\n";
                            cin >> diacita;
                            cout << "para que hora quiere la cita?\n";
                            cin >> horacita;
                            cout << "Su cita ha sido agendada para el dia " << diacita << " a las " << horacita << " horas\n";
                            }else {
                                cout << "no se ha agendado ninguna cita.\n";
                            }   
                            break; 
                        }
                    default:
                        cout << "Opción no válida. Intente nuevamente.\n";
                        break;
                }
                break;
            }
            case 4: {
                cout << "Saliendo del sistema.\n";
                break;
            }
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
