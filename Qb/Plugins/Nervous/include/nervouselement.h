/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2013  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://kde-apps.org/content/show.php/Webcamoid?content=144796
 */

#ifndef NERVOUSELEMENT_H
#define NERVOUSELEMENT_H

#include <QImage>
#include <QColor>

#include <qb.h>

class NervousElement: public QbElement
{
    Q_OBJECT
    Q_PROPERTY(int nFrames READ nFrames WRITE setNFrames RESET resetNFrames)
    Q_PROPERTY(bool simple READ simple WRITE setSimple RESET resetSimple)

    public:
        explicit NervousElement();

        Q_INVOKABLE int nFrames() const;
        Q_INVOKABLE bool simple() const;

    private:
        int m_nFrames;
        bool m_simple;

        QbElementPtr m_convert;
        QVector<QImage> m_frames;
        QbCaps m_caps;
        int m_stride;

    public slots:
        void setNFrames(int nFrames);
        void setSimple(bool simple);
        void resetNFrames();
        void resetSimple();
        void iStream(const QbPacket &packet);
        void setState(QbElement::ElementState state);

    private slots:
        void processFrame(const QbPacket &packet);
};

#endif // NERVOUSELEMENT_H