CC=g++-11
CFLAGS=-Wall -g
.PHONY: clean
# ***************************************************************

run:
	$(CC) Parte_2.cpp -o Parte_2
	./Parte_2
	gnuplot -persist plot_newton_basins

clean:
	-rm -f *.txt *.in* gen