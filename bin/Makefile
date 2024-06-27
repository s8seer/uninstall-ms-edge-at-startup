all: edgeChecker edgeUninstaller

edgeChecker:
	g++ -mwindows --static -g --std=c++20 -I../include ../src/edgeChecker.cpp -o edgeChecker

edgeUninstaller:
	g++ -mwindows --static -g --std=c++20 -I../include ../src/edgeUninstaller.cpp -o edgeUninstaller adminPrivileges.o
