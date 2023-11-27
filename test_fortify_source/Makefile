TARGETS = fortify_test fortify_test2
 
all: $(TARGETS)

fortify_test: fortify_test.c
	gcc -D_FORTIFY_SOURCE=1 -o fortify_test fortify_test.c
fortify_test2: fortify_test2.c
	gcc -D_FORTIFY_SOURCE=2 -o fortify_test2 fortify_test2.c
clean:
	rm -rf $(TARGETS)
