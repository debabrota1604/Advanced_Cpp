CXX = g++
CXXFLAGS = --std=c++11
EXEC = "lib_vehicleLibrary.a"

EXEC: p3_car.o p5_bike.o p8_vehicleFactory.cpp
	ar ru $(EXEC) p3_car.o p5_bike.o
	rm *.o

# p8_vehicleFactory.o: p7_vehicle_factory.hpp p8_vehicleFactory.cpp
# 	$(CXX) $(CXXFLAGS) -c p7_vehicle_factory.hpp p8_vehicleFactory.cpp

p3_car.o: p3_car.cpp p2_car.hpp p1_vehicle.hpp p8_vehicleFactory.cpp
	$(CXX) $(CXXFLAGS) -c p2_car.hpp p3_car.cpp

p5_bike.o: p5_bike.cpp p4_bike.hpp p1_vehicle.hpp p8_vehicleFactory.cpp
	$(CXX) $(CXXFLAGS) -c p5_bike.cpp p4_bike.hpp

clean:
	rm $(EXEC) 