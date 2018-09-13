all:
	g++ -g -o expr expr.cc

arg='1+123+(9/10)*2'

run:
	./expr $(arg)

clean:
	rm expr
