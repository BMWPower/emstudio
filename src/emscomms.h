/***************************************************************************
*   Copyright (C) 2012  Michael Carpenter (malcom2073)                     *
*                                                                          *
*   This file is a part of EMStudio                                        *
*                                                                          *
*   EMStudio is free software: you can redistribute it and/or modify       *
*   it under the terms of the GNU General Public License version 2 as      *
*   published by the Free Software Foundation.                             *
*                                                                          *
*   EMStudio is distributed in the hope that it will be useful,            *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
*   GNU General Public License for more details.                           *
									   *
*   You should have received a copy of the GNU General Public License      *
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
****************************************************************************/
#ifndef EMSCOMMS_H
#define EMSCOMMS_H

#include <QThread>
#include <QFile>
#include <QMutex>
#include <QVariant>
#include <QDateTime>
#include "logloader.h"
#include "headers.h"
class EmsComms : public QThread
{
	Q_OBJECT
public:
	EmsComms(QObject *parent) : QThread(parent) {}
	virtual void stop()=0;
	virtual void setLogsEnabled(bool enabled)=0;
	virtual void setLogDirectory(QString dir)=0;
	virtual void setPort(QString portname)=0;
	virtual void setBaud(int baudrate)=0;
	virtual void setLogFileName(QString filename)=0;
	virtual bool sendPacket(unsigned short payloadid,QList<QVariant> arglist=QList<QVariant>(),QList<int> argsizelist=QList<int>(),bool haslength=false)=0;
	virtual int getLocationIdInfo(unsigned short locationid)=0;
	virtual int getInterfaceVersion()=0;
	virtual int getFirmwareVersion()=0;
	virtual int getMaxPacketSize()=0;
	virtual int getDecoderName()=0;
	virtual int getFirmwareBuildDate()=0;
	virtual int getCompilerVersion()=0;
	virtual int getOperatingSystem()=0;
	virtual int echoPacket(QByteArray packet)=0;
	virtual int getLocationIdList(unsigned char listtype, unsigned short listmask)=0;
	virtual int softReset()=0;
	virtual int hardReset()=0;
	virtual bool sendSimplePacket(unsigned short payload)=0;
	virtual void connectSerial(QString port,int baud)=0;
	virtual void disconnectSerial()=0;
	virtual void loadLog(QString filename)=0;
	virtual void playLog()=0;
	//virtual void populateDataFields()=0;
	virtual QByteArray generatePacket(QByteArray header,QByteArray payload)=0;
	virtual int updateBlockInRam(unsigned short location,unsigned short offset, unsigned short size,QByteArray data)=0;
	virtual int updateBlockInFlash(unsigned short location,unsigned short offset, unsigned short size,QByteArray data)=0;
	virtual int retrieveBlockFromRam(unsigned short location, unsigned short offset, unsigned short size)=0;
	virtual int retrieveBlockFromFlash(unsigned short location, unsigned short offset, unsigned short size)=0;
	virtual int burnBlockFromRamToFlash(unsigned short location,unsigned short offset, unsigned short size)=0;
	virtual void setInterByteSendDelay(int milliseconds)=0;
	virtual void setlogsDebugEnabled(bool enabled)=0;
};

#endif // EMSCOMMS_H
