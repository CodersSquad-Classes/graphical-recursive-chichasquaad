CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

TARGET = Evidence1.3.1
SRCS   = Evidence1.3.1.cpp
OBJS   = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) 256 512 896 512 4

clean:
	rm -f $(OBJS) $(TARGET) lines.txt
