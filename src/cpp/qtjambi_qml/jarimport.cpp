/****************************************************************************
**
** Copyright (C) 2009-2020 Dr. Peter Droste, Omix Visualization GmbH & Co. KG. All rights reserved.
**
** This file is part of Qt Jambi.
**
** ** $BEGIN_LICENSE$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
** $END_LICENSE$
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QHash>
#include "jarimport.h"
#include "qtjambi_jarimport.h"
#include "qtjambi_qml_repository.h"
#include <qtjambi/qtjambi_core.h>
#include <qtjambi/qtjambi_cast.h>

Jarimport::Jarimport()
    : QQmlExtensionPlugin() {}

void Jarimport::registerTypes(const char * uri){
    if(JNIEnv* env = qtjambi_current_environment()){
        QTJAMBI_JNI_LOCAL_FRAME(env, 200)
        Java::QtQml::QmlTypes.registerModule(env, qtjambi_cast<jobject>(env, baseUrl()), env->NewStringUTF(uri));
    }
}


extern "C" QObject* qtjambi_qml_create_jarimport(quintptr ptr){
    static QHash<quintptr,QPointer<Jarimport>> hash;
    if(!hash.contains(ptr) || hash[ptr].isNull())
        hash[ptr] = new Jarimport();
    return hash[ptr].data();
}
