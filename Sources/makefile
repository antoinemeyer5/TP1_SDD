CC=gcc
main_tests:../Tests/TestsCodes.o OutilsCommuns.o PremierNiveau.o SecondNiveau.o ../Tests/teZZt.o
	$(CC) -o main_tests ../Tests/TestsCodes.o OutilsCommuns.o PremierNiveau.o SecondNiveau.o ../Tests/teZZt.o -lm 
	@echo "=> Lancer les tests avec  ./main_tests" 
main:main.o OutilsCommuns.o PremierNiveau.o SecondNiveau.o ../Tests/teZZt.o
	$(CC) -o main main.o OutilsCommuns.o PremierNiveau.o SecondNiveau.o ../Tests/teZZt.o -lm 
	@echo "=> Lancer le programme avec  ./main" 

teZZt.o:../Tests/teZZt.c ../Tests/teZZt.h
	$(CC) -c ../Tests/teZZt.c -o ../Tests.teZZt.o
TestsCodes.o:../Tests/TestsCodes.c
	$(CC) -c ../Tests/TestsCodes.c -g -Wall -Wextra

OutilsCommuns.o:OutilsCommuns.c OutilsCommuns.h
	$(CC) -c OutilsCommuns.c -g -Wall -Wextra
PremierNiveau.o:PremierNiveau.c PremierNiveau.h
	$(CC) -c PremierNiveau.c -g -Wall -Wextra
SecondNiveau.o:SecondNiveau.c SecondNiveau.h
	$(CC) -c SecondNiveau.c -g -Wall -Wextra
main.o:main.c
	$(CC) -c main.c -g -Wall -Wextra 
clean:
	rm -rf main main.o main_tests OutilsCommuns.o PremierNiveau.o SecondNiveau.o ../Tests/TestsCodes.o ../Tests/teZZt.o *.gch
