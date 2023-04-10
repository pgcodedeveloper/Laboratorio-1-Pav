main: main.o DtSocio.o DtClase.o DtEntrenamiento.o DtSpinning.o Spinning.o Entrenamiento.o Clase.o Fecha.o Socio.o Inscripcion.o
	g++ main.o DtSocio.o DtClase.o DtEntrenamiento.o DtSpinning.o Spinning.o Entrenamiento.o Clase.o Fecha.o Socio.o Inscripcion.o -o sistema

Clase.o: Clase.cpp

Entrenamiento.o: Entrenamiento.cpp

Spinning.o: Spinning.cpp

Fecha.o: Fecha.cpp

DtSocio.o: DtSocio.cpp

DtClase.o: DtClase.cpp

DtSpinning.o: DtSpinning.cpp

DtEntrenamiento.o: DtEntrenamiento.cpp

Socio.o: Socio.cpp

Inscripcion.o: Inscripcion.cpp

main.o: main.cpp

clean:
	rm -rf *.o sistema sistema.exe
	clear