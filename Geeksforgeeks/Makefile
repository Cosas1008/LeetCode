default : run
FILE = "file"

runc:
	@echo "runc " $(FILE)
	gcc $(FILE).c -o $(FILE).o && ./$(FILE).o

run:
	@echo "run " $(FILE)
	g++ $(FILE).cpp -o $(FILE).o && ./$(FILE).o

clean:
	rm -rf *.o
