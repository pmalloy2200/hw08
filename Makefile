GRAPH = gnuplot
EXECS = altitude angle velocity
LOGS = alt vel angl
PNGS = angle.png velocity.png altitude.png
CC = clang
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

velocity: velocity.o glider-demo.o glider-ode.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

angle: angle.o glider-demo.o glider-ode.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)
	
altitude: altitude.o glider-demo.o glider-ode.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

vel: velocity
	./velocity > vel
angl: angle
	./angle > angl
alt: altitude
	./altitude > alt
	
all: $(PNGS)
velocity.png: vel.gpl vel
	$(GRAPH) vel.gpl
angle.png: angle.gpl angl
	$(GRAPH) angle.gpl
altitude.png: alt.gpl alt
	$(GRAPH) alt.gpl


clean : 
	rm -f *~
	rm -f *.o
	rm -f $(EXECS)

veryclean : clean
	rm -f $(LOGS) $(PNGS)
