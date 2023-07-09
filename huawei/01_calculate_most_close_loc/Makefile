
Targets := main.o

out : ${Targets}
	gcc -o $@ $^

%.o : %.s
	gcc -c -o $@ $^

%.s : %.c
	gcc -S -o $@ $^



./PHONY: clean
clean:
	rm -rf *.o *.s *.out
	rm -rf out
	

