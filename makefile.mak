all: stockSpan stockSpanBF

stockSpan: stockSpan.o
	g++ stockSpan.cpp -o stockSpan

stockSpanBF: stockSpanBF.o
	g++ stockSpanBF.cpp -o stockSpanBF

stockSpan.o: stockSpan.cpp
	g++ -c stockSpan.cpp

stockSpanBF.o: stockSpanBF.cpp
	g++ -c stockSpanBF.cpp

clean:
	rm *.o
	rm stockSpan
	rm stockSpanBF

runStack:
	stockSpan

runBF:
	stockSpanBF
