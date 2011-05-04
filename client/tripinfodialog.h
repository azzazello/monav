/*
Copyright 2010  Christian Vetter veaac.fdirct@gmail.com

This file is part of MoNav.

MoNav is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MoNav is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with MoNav.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TRIPINFODIALOG_H
#define TRIPINFODIALOG_H

#include <QWidget>
#include <QDebug>
#include <QDateTime>

namespace Ui {
	class TripinfoDialog;
}

class TripinfoDialog : public QWidget
{
	Q_OBJECT

public:
	explicit TripinfoDialog( QWidget* parent = 0 );
	~TripinfoDialog();

public slots:
	// void routeChanged();
	// void trackChanged();
	void updateInformation();

signals:

	void cancelled();
	// void selected();

protected slots:

	// void populateData();
	// void select();

protected:

	struct PrivateImplementation;
	PrivateImplementation* d;
	Ui::TripinfoDialog* m_ui;
	QDateTime m_lastUpdateTime;
	// void trackTime(int);
	// void trackDistance(double);
	// void elevations(QVector<double>);
};

#endif // TRIPINFODIALOG_H
