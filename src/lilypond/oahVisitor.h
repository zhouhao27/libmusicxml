/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef __oahVisitors__
#define __oahVisitors__

#include "visitor.h"

#include "oahBasicTypes.h"


namespace MusicXML2
{

//________________________________________________________________________
class oahVisitor : public smartable,

	public visitor<S_oahHandler>

{
  public:

    oahVisitor (
      const S_oahHandler handler);

    virtual ~oahVisitor ();

    virtual void          visitTheHandler () = 0;

  protected:

    S_oahHandler          fVisitedOahHandler;
};
typedef SMARTP<oahVisitor> S_oahVisitor;


} // namespace MusicXML2


#endif
