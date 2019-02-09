
	i=0
	while [ "$i" -le 200 ]; do
	gcc -O3 algo1.c -o test"$i"
	./test"$i" $(cat in/test"$i".in)
	true $((i++))
	done
	rm test*
