demo: demo.o dataset.o network.o vectors.o layer.o denselayer.o softmaxlayer.o relulayer.o
	c++ demo.o dataset.o network.o vectors.o layer.o denselayer.o softmaxlayer.o relulayer.o -o demo -lm -ltrapfpe -lpgplot -lcpgplot -lX11 -lm 

demo.o: demo.cpp dataset.h network.h vectors.h layer.h denselayer.h softmaxlayer.h relulayer.h
	c++ -c demo.cpp

dataset.o: dataset.cpp dataset.h
	c++ -c dataset.cpp

network.o: network.cpp network.h denselayer.h softmaxlayer.h relulayer.h vectors.h
	c++ -c network.cpp

vectors.o: vectors.cpp
	c++ -c vectors.cpp

layer.o: layer.cpp layer.h
	c++ -c layer.cpp

denselayer.o: denselayer.cpp denselayer.h layer.h
	c++ -c denselayer.cpp

softmaxlayer.o: softmaxlayer.cpp softmaxlayer.h layer.h
	c++ -c softmaxlayer.cpp

relulayer.o: relulayer.cpp relulayer.h layer.h
	c++ -c relulayer.cpp





