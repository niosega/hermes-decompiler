hermes-decompiler: hermes-decompiler.c utils.c
	gcc -o $@ $^

clean:
	rm -rf hermes-decompiler