# Makes the missile launcher
all: missileCommand

missileCommand:
	g++ main.cpp missile_launcher.cpp -lusb -L/usr/lib -o missileCommand