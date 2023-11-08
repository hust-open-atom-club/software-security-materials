SRC:=vuln.c
BIN:=$(subst .c,, $(SRC))

.PHONY: all clean exploit

all: $(BIN)
	@echo "You can use python poc.py to test vuln"

$(BIN): $(SRC)
	gcc -g -fno-stack-protector -no-pie -o $(BIN) $(SRC)

exploit:
	python poc.py

clean:
	rm -rf $(BIN)
	rm -rf core*
