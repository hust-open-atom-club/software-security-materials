TARGETS = uaf_leak uaf_demo

all: $(TARGETS)
uaf_leak: uaf_leak.c
	gcc -g -o uaf_leak uaf_leak.c
test_uaf: test_uaf.c
	gcc -g  -o uaf_demo uaf_demo.c
clean:
	rm -rf $(TARGETS)
#
