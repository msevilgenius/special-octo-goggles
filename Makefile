CXXFLAGS=-Wall -O3 -g
SRCS=laser-eye-surgey.cc
OBJECTS=$(subst .cc,.o,$(SRCS))
BINARIES=laser-eye-surgey

RGB_INCDIR=matrix/include
RGB_LIBDIR=matrix/lib
RGB_LIBRARY_NAME=rgbmatrix
RGB_LIBRARY=$(RGB_LIBDIR)/lib$(RGB_LIBRARY_NAME).a

LES_INCDIR=les/include
LES_LIBDIR=les/lib
LES_LIBRARY_NAME=laser-eye-surgey
LES_LIBRARY=$(LES_LIBDIR)/lib$(LES_LIBRARY_NAME).a

LDFLAGS+=-L$(LES_LIBDIR) -l$(LES_LIBRARY_NAME) \
         -L$(RGB_LIBDIR) -l$(RGB_LIBRARY_NAME) \
          -lrt -lm -lpthread

all : laser-eye-surgey

laser-eye-surgey : $(OBJECTS) $(RGB_LIBRARY) $(LES_LIBRARY)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

$(RGB_LIBRARY): FORCE
	$(MAKE) -C $(RGB_LIBDIR)

$(LES_LIBRARY): FORCE
	$(MAKE) -C $(LES_LIBDIR)

#laser-eye-surgey.o : laser-eye-surgey.cc

%.o : %.cc
	$(CXX) -I$(LES_INCDIR) -I$(RGB_INCDIR) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(BINARIES)
	$(MAKE) -C $(RGB_LIBDIR) clean
	$(MAKE) -C $(LES_LIBDIR) clean

FORCE:
.PHONY: FORCE