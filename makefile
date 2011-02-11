# Makes the missile launcher
all:
	g++ main.cpp missile_launcher.cpp -lusb -L/usr/lib -o missileCommand