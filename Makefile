SRC=src/
INC=includes/

all: $(SRC)*.c $(INC)*.h
	cc -Wall -Wextra -Werror -I $(INC) $(SRC)*.c -o bsq
test:
	cc -I $(INC) $(SRC)*.c -o bsq
ctest:
	clang -Wall -Wextra -Werror -I $(INC) $(SRC)*.c -o bsq
clean:
	rm -f *.o
fclean:
	rm -f bsq
re: fclean all	
