main: main.o DtSocio.o
	g++ main.o DtSocio.o -o sistema

Clase.o: Clase.cpp

Entrenamiento.o: Entrenamiento.cpp

Spinning.o: Spinning.cpp

Turno.o: Turno.cpp

Fecha.o: Fecha.cpp

DtSocio.o: DtSocio.cpp

main.o: main.cpp

clean:
	rm -rf *.o sistema
	clear