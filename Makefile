main: main.c
	gcc -o main main.c pattern1.c

results: main
	(echo "Pattern 1:" 1>&2; ./main 1 ${shell bc --expression="$$RANDOM % 15 + 5"}; \
	echo 1>&2; \
	echo "Pattern 2:" 1>&2; ./main 2 ${shell bc --expression="$$RANDOM % 15 + 5"}; \
	echo 1>&2; \
	echo "Pattern 3:" 1>&2; ./main 3 ${shell bc --expression="$$RANDOM % 20 + 5"}) \
		2> results.txt

clean:
	rm -f main
