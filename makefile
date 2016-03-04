all: compile_x86 compile_arm

compile_x86: clock_x86 time_x86

compile_arm: clock_arm time_arm
	
clock_x86: trabalho_clock.cpp
	g++ trabalho_clock.cpp -o clock_x86

time_x86: trabalho_time.cpp
	g++ trabalho_time.cpp -o time_x86

clock_arm: trabalho_clock.cpp
	arm-linux-gnueabihf-g++ trabalho_clock.cpp -o clock_arm

time_arm: trabalho_time.cpp
	arm-linux-gnueabihf-g++ trabalho_time.cpp -o time_arm	

clean:
	-rm clock_x86 time_x86 time_arm clock_arm