all: sample

sample: sample_main.o sample_functions.o
	gcc -o sample sample_main.o sample_functions.o
	
sample_main.o: sample_main.c sample_header.h
	gcc -c sample_main.c
	
sample_functions.o: sample_functions.c sample_header.h
	gcc -c sample_functions.c
	
clean : 
	rm ./*.o sample
