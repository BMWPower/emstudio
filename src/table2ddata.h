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

#ifndef TABLE2DDATA_H
#define TABLE2DDATA_H
#include <QString>
#include <QList>
#include <QByteArray>

class Table2DData
{
public:
	Table2DData();
	Table2DData(unsigned short locationid,QByteArray payload);
	void setData(unsigned short locationid,QByteArray payload);
	QByteArray data();
private:
	unsigned short m_locationId;
	QList<unsigned short> m_xaxis;
	QList<unsigned short> m_yaxis;
	QString xAxisLabel;
	QString yAxisLabel;
};

#endif // TABLE2DDATA_H
