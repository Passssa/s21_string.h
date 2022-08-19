TESTFLAGS = -lcheck -coverage
GCCFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: test gcov_report s21_string.a

test: s21_string.a
	gcc test.c $(GCCFLAGS) $(TESTFLAGS) -L. s21_string.a -o test

gcov_report: s21_string.a
	gcc $(GCCFLAGS) $(GCOVFLAGS) test.c $(TESTFLAGS) s21_string.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -rf gcovreport gcovreport.info s21_string.gcda s21_string.gcno test.gcda test.gcno

s21_string.o: s21_string.c
	gcc $(GCCFLAGS) -c s21_string.c

s21_string.a: s21_string.o
	ar -rc $@ s21_string.o
	ranlib $@

clean:
	rm -rf *.o *.a
