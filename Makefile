
CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = Evidence1.3.1

SRCS = Evidence1.3.1.cpp

OBJS = $(SRCS:.cpp=.o)


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)


run: $(TARGET)
	./$(TARGET)
