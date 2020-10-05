  # the compiler: gcc for C program, define as g++ for C++
  CC = g++

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -O3 -Wall -std=c++17

  # the build target executable:
  TARGET = calcbasic

  all: $(TARGET)

  $(TARGET): *.cpp
	$(CC) $(CFLAGS) -o $(TARGET) *.cpp

  clean:
	$(RM) $(TARGET)
