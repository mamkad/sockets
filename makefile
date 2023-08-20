CMR = g++
PORJ = sockets

socket:
	$(CMR) src/wsadata_control.cpp -c 
	$(CMR) src/socket_base.cpp     -c 
	$(CMR) src/socket_client.cpp   -c
	$(CMR) wsadata_control.o socket_base.o socket_client.o -shared -o lib.net.sockets.dll -lws2_32
