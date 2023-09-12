SRC=src/
INC=includes/
OUTPUT=bsq

all: $(OUTPUT)
	cc -Wall -Wextra -Werror -I $(INC) $(SRC)*.c -o $(OUTPUT)
test:
	cc -I $(INC) $(SRC)*.c -o bsq
ctest:
	clang -Wall -Wextra -Werror -I $(INC) $(SRC)*.c -o bsq
clean:
	rm -f *.o
fclean:
	rm -f bsq
re: fclean all	
