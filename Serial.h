#pragma once
#include <QApplication.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QIODevice.h>
#include<QListWidget>
#include <QMessageBox>


class SerialHandler : public QObject
{
	Q_OBJECT

public:
	
	SerialHandler( QObject* parent = nullptr );
	bool find_lordyphon_port();
	
	bool open_lordyphon_port();
	bool lordyphon_handshake();
	bool write_serial_data(const QByteArray& tx_data);
	QByteArray& read_serial_data();

private:
	
	QSerialPort lordyphon;
	QString lordyphon_portname;
	QByteArray input_buffer;
	const QByteArray hand_shake_tx_phrase = "!c++ is great!   ";
	const QByteArray hand_shake_rx_phrase = "YES INDEED";


};
