CXX=g++-4.7
CXXFLAGS=-std=c++11 -Wall -O3 -g
SRCS=laser-eye-surgery.cc drawing.cc face/roomba/roomba.cc
OBJECTS=$(subst .cc,.o,$(SRCS))
BINARIES=laser-eye-surgery

RGB_INCDIR=matrix/include
RGB_LIBDIR=matrix/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

LDFLAGS+=-L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) \
          -lrt -lm -lpthread

all : laser-eye-surgery

laser-eye-surgery : $(OBJECTS) $(RGB_LIBRARY)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(RGB_LIBRARY): FORCE
	$(MAKE) -C $(RGB_LIBDIR)


#laser-eye-surgery.o : laser-eye-surgery.cc

%.o : %.cc
	$(CXX) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)
	$(MAKE) -C $(RGB_LIBDIR) clean

FORCE:
.PHONY: FORCE