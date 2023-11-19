SRC:=vuln.c
BIN:=$(subst .c,, $(SRC))

.PHONY: all clean exploit

all: $(BIN)
	@echo "You can use python poc.py to test vuln"

$(BIN): $(SRC)
	gcc -g -fcf-protection=none -no-pie -o $(BIN) $(SRC)
	gcc -g -fcf-protection=none -no-pie -m32 -fstack-protector -o $(BIN)32bit $(SRC)

exploit:
	./poc.py

clean:
	rm -rf $(BIN)
	rm -rf core*
