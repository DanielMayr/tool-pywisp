#ifndef TCPSERVER_CLASS_H
#define TCPSERVER_CLASS_H
#include <bur/plctypes.h>
#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
#include <AsTCP.h>
#include <AsIOTime.h>
#include "../Comm.h"

/** \file TCPServer.h
 *  \class TCPServer
 *  \brief Klasse Aufsetzen eines TCP Servers
 *
 *  �ber die AsTCP Bibliothek wird der TCP Server initialisiert und ausgef�hrt.
 *  Die Funktionsbl�cke werden als Pointer der Klasse �bergeben und im Code
 *  aufgerufen. Zudem wird der Eventlogger verwendet, um evtl. Fehler zu loggen.
 */

class TCPServer: public Comm{
	public:
	/** Status definition der Klasse*/
	enum Status
	{
		ERROR = 0xFF,
		STOP = 0,
		BUSY,
		READY
	};
	private:
	/* Variablen f�r Verbindungsparameter*/
	const int server_port;
	unsigned long ident;
	unsigned long outlen;
	unsigned long client_ip;
	unsigned long client_ident;
	unsigned int client_port;
	unsigned long client_outlen;
	
	unsigned short tcp_step;
	/* Statusvariablen*/
	Status _status;
	Status _status_sub;
	/* Pointer auf Funktionsbl�cke*/
	struct TcpOpen TcpOpen_0;
	struct TcpServer TcpServer_0;
	struct TcpIoctl TcpIoctl_0;
	struct TcpRecv TcpRecv_0;
	struct TcpSend TcpSend_0;
	struct TcpClose TcpClose_0;
	struct tcpLINGER_typ linger_opt;
	unsigned int linger_opt_len;
	/**< Sende- und Empfangsbuffer mit L�ngen und cursor*/
	struct frame buffer_out[255];
	unsigned int outc;
	unsigned char buffer_in[255 * (MAX_PAYLOAD + 1)];
	unsigned int recvlength;
	/**< Tcp read und write Funktionen*/
	Status read();
	Status write();
	
	Comm *transp;
    
	public:
	TCPServer(int port)
		:server_port(port),
		status(_status)
	{};
	/**< Initialisierungsmethode*/
	void deinit();
	void init();
	/**< Zyklische Lese- und Schreibmethode*/
	void sync();
	/**< Schlie�en der Sockets*/
	void close_sockets();
	/**< Readonly methode um Status zu lesen*/
	const Status &status;
	/** Method to queue communication frame */
	void handleFrame(unsigned char id, unsigned char buf[MAX_PAYLOAD]);
	void registerListener(Comm *transp);
};
#endif //TCPSERVER_CLASS_H
