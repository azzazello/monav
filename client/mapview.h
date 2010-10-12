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

#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QDialog>
#include <QMenu>

#include "interfaces/irouter.h"
#include "overlaywidget.h"

namespace Ui {
	 class MapView;
}

class MapView : public QDialog {
	Q_OBJECT
public:
	MapView( QWidget *parent = 0 );
	~MapView();

	enum Mode {
		Source, Target, POI, NoSelection
	};

	static int selectPlaces( QVector< UnsignedCoordinate > places, QWidget* p = NULL );
	static bool selectStreet( UnsignedCoordinate* result, QVector< int >segmentLength, QVector< UnsignedCoordinate > coordinates, QWidget* p = NULL );

protected slots:
	void magnify();

	void mouseClicked( ProjectedCoordinate clickPos );

	void nextPlace();
	void previousPlace();

	void showContextMenu( QPoint globalPos );

	void settingsGeneral();
	void settingsRenderer();
	void settingsRouter();
	void settingsGPSLookup();
	void settingsAddressLookup();
	void settingsGPS();
	void settingsDataDirectory();

	void gotoSource();
	void gotoGPS();
	void gotoTarget();
	void gotoBookmark();
	void gotoAddress();

	void sourceByBookmark();
	void sourceByAddress();
	void sourceByGPS();

	void targetByBookmark();
	void targetByAddress();

	void addZoom();
	void substractZoom();

	void bookmarks();

	void setModeSourceSelection();
	void setModeTargetSelection();
	void setModePOISelection();
	void setModeNoSelection();
	void toogleLocked();

	void gotoMenu();
	void toolsMenu();
	void settingsMenu();
	void sourceMenu();
	void targetMenu();
	//void waypointMenu();
	//void addWaypoint();

	void showInstructions();

	void dataLoaded();
	void instructionsChanged();

protected:

	void connectSlots();
	void setupMenu();
	void setPlaces( QVector< UnsignedCoordinate > p );
	void setEdges( QVector< int > segmentLength, QVector< UnsignedCoordinate > coordinates );

	virtual void resizeEvent( QResizeEvent* event );

#ifdef Q_WS_MAEMO_5
	void grabZoomKeys( bool grab );
	void keyPressEvent( QKeyEvent* event );
#endif

	Ui::MapView *m_ui;

	int m_maxZoom;
	QVector< UnsignedCoordinate > m_places;
	int m_place;
	UnsignedCoordinate m_selected;
	int m_virtualZoom;

	bool m_fixed;

	OverlayWidget* m_targetOverlay;
	OverlayWidget* m_sourceOverlay;
	OverlayWidget* m_gotoOverlay;
	OverlayWidget* m_toolsOverlay;
	OverlayWidget* m_settingsOverlay;

	Mode m_mode;
	bool m_useMenus;

	QMenu* m_targetMenu;
	QMenu* m_sourceMenu;
	QMenu* m_gotoMenu;
	QMenu* m_toolsMenu;
	QMenu* m_settingsMenu;

	QAction* m_gotoGPSAction;
	QAction* m_gotoSourceAction;
	QAction* m_gotoTargetAction;
	QAction* m_gotoBookmarkAction;
	QAction* m_gotoAddressAction;

	QAction* m_sourceByTapAction;
	QAction* m_sourceByBookmarkAction;
	QAction* m_sourceByAddressAction;
	QAction* m_sourceByGPS;

	QAction* m_targetByTapAction;
	QAction* m_targetByBookmarkAction;
	QAction* m_targetByAddressAction;

	QAction* m_bookmarkAction;
	QAction* m_magnifyAction;
	QAction* m_modeSourceAction;
	QAction* m_modeTargetAction;
	QAction* m_mapViewAction;

	QAction* m_settingsGeneral;
	QAction* m_settingsGPSLookup;
	QAction* m_settingsRenderer;
	QAction* m_settingsRouter;
	QAction* m_settingsAddressLookup;
	QAction* m_settingsGPS;
	QAction* m_settingsDataDirectory;
};

#endif // MAPVIEW_H
