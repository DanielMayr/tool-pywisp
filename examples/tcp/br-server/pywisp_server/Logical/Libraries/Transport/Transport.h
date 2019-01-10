#ifndef TRANSPORT_CLASS_H
#define TRANSPORT_CLASS_H

#include "../Comm.h"
/** \file Transport.h
 *  \class Transport
 *  \brief Klasse zum Ent- und Packen der Kommunikationsdaten zu Pywisp
 *
 *  Die Klasse wird mit zwei Buffer initialisiert, einen Eingangsbuffer und
 *  einen Ausgangsbuffer. Diese Buffer m�ssen die gleiche L�nge besitzen wie
 *  die auf Pywisp. Will man mehrere Frames schicken, so k�nnen weitere Buffer
 *  �ber die addOutBuffer() Methode hinzugef�gt werden. Damit diese auch
 *  gesendet werden, muss entsprechender Frame in sendData() gepackt werden.
 *  Eingangsseitig gibt es nur einen Buffer der die Frames liefert. Mit
 *  der Methode run() kann kontrolliert werden, ob Eingangsseitig Daten
 *  ausgewertet werden m�ssen. Mittels runExp() kann kontrolliert werden
 *  ob ein Experiment ausgef�hrt werden soll.
 */




class Transport: public Comm{
	private:
	Comm *tcp;
	/**< Unpack Frame nach entsprechender ID*/
	void unpackExp(unsigned char *payload);
	/**< Flag ob Experiment aktiviert oder nicht*/
	bool bActivateExperiment;
	/**< Z�hlvariablen und Cursoren zum Bufferschreiben*/
	unsigned char framecounter;
	unsigned char frame;
	unsigned char obuf_cur;
	unsigned char ibuf_cur;
	
	public:
	/**< R�ckgabe des Experimenten Flags*/
	bool runExp() {return this->bActivateExperiment; }
	/**< Senden der Daten in Frames*/
	void sendData();
	/**< Funktion zum Auswerten eingegangener Daten*/
	void handleFrame(unsigned char id, unsigned char buf[MAX_PAYLOAD]);
	void registerServer(Comm *serv);
	
	unsigned long lTime;
};

#endif //TRANSPORT_CLASS_H
