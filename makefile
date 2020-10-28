SRCDIR := src

TARGET := build/dc2

SRCS     := $(shell FORFILES /P $(SRCDIR) /S /M *.cpp /C "CMD /C ECHO @relpath")
SRCS     := $(patsubst ".\\%",$(SRCDIR)\\%,$(SRCS))
CXXFLAGS := -static-libstdc++

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
