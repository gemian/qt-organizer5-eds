/*
 * Copyright 2013 Canonical Ltd.
 *
 * This file is part of canonical-pim-service
 *
 * contact-service-app is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * contact-service-app is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __QORGANIZER_EDS_COLLECTION_ENGINEID_H__
#define __QORGANIZER_EDS_COLLECTION_ENGINEID_H__

#include <libedataserver/libedataserver.h>
#include <libecal/libecal.h>
#include <QtCore/QSharedData>

class QOrganizerEDSCollectionEngineId : public QSharedData
{
public:
    QOrganizerEDSCollectionEngineId();
    QOrganizerEDSCollectionEngineId(const QOrganizerEDSCollectionEngineId& other);
    QOrganizerEDSCollectionEngineId(const QString& idString);
    QOrganizerEDSCollectionEngineId(ESource *source);
    ~QOrganizerEDSCollectionEngineId();

    bool isEqualTo(const QOrganizerEDSCollectionEngineId* other) const;
    bool isLessThan(const QOrganizerEDSCollectionEngineId* other) const;

    QString managerUri() const;
    QOrganizerEDSCollectionEngineId *clone() const;

    QString toString() const;
    QByteArray toByteArray() const;

    uint hash() const;

#ifndef QT_NO_DEBUG_STREAM
    QDebug& debugStreamOut(QDebug& dbg) const;
#endif

private:
    QString m_collectionId;
    ESource *m_esource;
    ECalClientSourceType m_sourceType;

    friend class SourceRegistry;
    //friend class ViewWatcher;
    friend class QOrganizerEDSEngine;

};



#endif
