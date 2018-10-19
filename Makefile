CXXFLAGS += -std=c++14
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

ex: choice.o choiceChipotle.o
		$(CXX) $(CXXFLAGS) -o choice choice.o  choiceChipotle.o $(GTKFLAGS)
choice.o: choice.cpp choice.h
		$(CXX) $(CXXFLAGS) -c choice.cpp $(GTKFLAGS)
 choiceChipotle.o: choice.h  choiceChipotle.cpp
		$(CXX) $(CXXFLAGS) -c  choiceChipotle.cpp $(GTKFLAGS)