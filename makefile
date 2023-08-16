CMR = g++
PORJ = sockets

socket:
	$(CMR) src/wsadata_control.cpp -c 
	$(CMR) src/socket_base.cpp     -c 
	$(CMR) src/socket_client.cpp   -c
