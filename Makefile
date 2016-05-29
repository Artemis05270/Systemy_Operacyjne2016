send:send.c
	gcc send.c -o send
take:take.c
	gcc take.c -o take
clean:
	rm send take
