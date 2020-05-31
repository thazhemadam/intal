GCC = gcc

intal_client:	intal_client.o intal_function.o
	$(GCC) -g -Wall intal_client.o intal_function.o -o intal_client 
	
# test_suite: intal_function.o tests.o
# 	$(GCC) intal_function.o tests.o -o test_suite

tests.o: testsuite.c intal.h
	$(GCC) -c -g -Wall testsuite.c -o  tests.o

intal_client.o:	intal_sampletest.c intal.h
	$(GCC) -g -c -Wall intal_sampletest.c -o intal_client.o

intal_function.o:	PES2201800014.c intal.h
	$(GCC) -g -c -Wall intal.c -o intal_function.o

clean:
	rm *.o 
