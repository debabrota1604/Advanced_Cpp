CXX = g++
CXXFLAGS = --std=c++11
EXEC = "vehicleLibrary.a"

EXEC: p3_car.o p5_bike.o
	ar ru $(EXEC) p3_car.o p5_bike.o
	rm *.o

p3_car.o: p3_car.cpp p2_car.hpp p1_vehicle.hpp
	$(CXX) $(CXXFLAGS) -c p2_car.hpp p3_car.cpp

p5_bike.o: p5_bike.cpp p4_bike.hpp p1_vehicle.hpp
	$(CXX) $(CXXFLAGS) -c p5_bike.cpp p4_bike.hpp

clean:
	rm $(EXEC) 