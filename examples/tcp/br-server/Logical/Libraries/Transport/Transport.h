#ifndef TRANSPORT_CLASS_H
#define TRANSPORT_CLASS_H

#include "../Comm.h"
#include "Frame.h"
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

class Transport: public Comm {
	public:
	void handleFrame(Frame frame);

	void sendData();
	
	void registerServer(Comm *serv);

	private:
	Comm *tcp;

	void unpackExp(Frame frame);

	void unpackBenchData(Frame frame);

	void unpackTrajRampData(Frame frame);
};

#endif //TRANSPORT_CLASS_H
