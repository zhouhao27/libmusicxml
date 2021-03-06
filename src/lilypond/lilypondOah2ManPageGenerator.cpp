/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

//#include <iomanip>      // setw, setprecision, ...
//#include <cmath>
//#include <string>

#include "lilypondOah2ManPageGenerator.h"

#include "setTraceOahIfDesired.h"
#ifdef TRACE_OAH
  #include "traceOah.h"
#endif

#include "version.h"

#include "oahOah.h"

using namespace std;

namespace MusicXML2
{

//________________________________________________________________________
lilypondOah2ManPageGenerator::lilypondOah2ManPageGenerator (
  const S_oahHandler handler,
  indentedOstream&   logOstream,
  ostream&           manPageOutputStream)
    : oah2ManPageGenerator (
        handler,
        logOstream,
        manPageOutputStream)
{}

lilypondOah2ManPageGenerator::~lilypondOah2ManPageGenerator ()
{}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondScoreOutputKindAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondScoreOutputKindAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondScoreOutputKindAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondScoreOutputKindAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondAbsoluteOctaveEntryAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondAbsoluteOctaveEntryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondAbsoluteOctaveEntryAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondAbsoluteOctaveEntryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondRelativeOctaveEntryAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondRelativeOctaveEntryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondRelativeOctaveEntryAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondRelativeOctaveEntryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondFixedOctaveEntryAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondFixedOctaveEntryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondFixedOctaveEntryAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondFixedOctaveEntryAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondAccidentalStyleKindAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondAccidentalStyleKindAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondAccidentalStyleKindAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondAccidentalStyleKindAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondChordsDisplayAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondChordsDisplayAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondChordsDisplayAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondChordsDisplayAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_lilypondLyricsDurationsKindAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting lilypondLyricsDurationsKindAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_lilypondLyricsDurationsKindAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting lilypondLyricsDurationsKindAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}

//________________________________________________________________________
void lilypondOah2ManPageGenerator::visitStart (S_oahMidiTempoAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> Start visiting oahMidiTempoAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
/*
  fOah2ManPageOutputStream <<
    ".HP" <<
    endl <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getShortName (), "-", "\\-") <<
    "\\fR, " <<
    "\\fB\\-" <<
    replaceSubstringInString (elt->getLongName (), "-", "\\-") <<
    "\\fR, " <<
    endl <<

    ".IP" <<
    endl <<
    elt->getDescription () <<
    endl;
    */
}

void lilypondOah2ManPageGenerator::visitEnd (S_oahMidiTempoAtom& elt)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    fOah2ManPageLogOstream <<
      endl <<
      ".\\\" --> End visiting oahMidiTempoAtom" <<
      " \"" << elt->fetchNames () << "\"" <<
      endl;
  }
#endif
}


} // namespace
