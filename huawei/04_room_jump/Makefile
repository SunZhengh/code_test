
Targets := main.o

out : ${Targets}
	gcc -o $@ $^ 

%.o : %.s
	gcc -c $^

%.s : %.i
	gcc -S $^

%.i : %.c
	gcc -E $^

./PHONY: clean
clean:
	rm -rf *.o *.s *.out
	rm -rf out
	

