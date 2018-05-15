TARGET = ChessForKids
LIBS = -lm #Math Library, just a placeholder
HEADERS = StudentData.h MenuFunctionalities.h newRatingCalculator.h
OBJECTS = StudentData.o ChessForKids.o MenuFunctionalities.o newRatingCalculator.o
CXX = g++
CXX_FLAGS = -Wall -std=c++11 #C++11 just for reference, not necessary

.PHONY: default all clean

default: $(TARGET)
all: default

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
