/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include <sstream>
#include <iomanip>      // setw, setprecision, ...
#include <string>
#include <regex>

#include "utilities.h"

#include "setTraceOahIfDesired.h"
#ifdef TRACE_OAH
  #include "traceOah.h"
#endif

#include "generalOah.h"
#include "lpsrOah.h"


using namespace std;

namespace MusicXML2
{

//______________________________________________________________________________
S_lpsrScoreOutputKindAtom lpsrScoreOutputKindAtom::create (
  string               shortName,
  string               longName,
  string               description,
  string               valueSpecification,
  string               variableName,
  lpsrScoreOutputKind& lpsrScoreOutputKindVariable)
{
  lpsrScoreOutputKindAtom* o = new
    lpsrScoreOutputKindAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName,
      lpsrScoreOutputKindVariable);
  assert(o!=0);
  return o;
}

lpsrScoreOutputKindAtom::lpsrScoreOutputKindAtom (
  string               shortName,
  string               longName,
  string               description,
  string               valueSpecification,
  string               variableName,
  lpsrScoreOutputKind& lpsrScoreOutputKindVariable)
  : oahValuedAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName),
    fLpsrScoreOutputKindVariable (
      lpsrScoreOutputKindVariable)
{}

lpsrScoreOutputKindAtom::~lpsrScoreOutputKindAtom ()
{}

S_oahValuedAtom lpsrScoreOutputKindAtom::handleOptionUnderName (
  string   optionName,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    gLogOstream <<
      "==> option '" << optionName << "' is a lpsrScoreOutputKindAtom" <<
      endl;
  }
#endif

  // an option value is needed
  return this;
}

void lpsrScoreOutputKindAtom::handleValue (
  string   theString,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrScoreOutputKindAtom'" <<
      endl;
  }
#endif

  // theString contains the score output kind:
  // is it in the score output kinds map?

#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrScoreOutputKindAtom'" <<
      endl;
  }
#endif

  map<string, lpsrScoreOutputKind>::const_iterator
    it =
      gLpsrScoreOutputKindsMap.find (
        theString);

  if (it == gLpsrScoreOutputKindsMap.end ()) {
    // no, score output kind is unknown in the map

    stringstream s;

    s <<
      "LPSR score output kind '" << theString <<
      "' is unknown" <<
      endl <<
      "The " <<
      gLpsrScoreOutputKindsMap.size () <<
      " known LPSR score output kinds are:" <<
      endl;

    gIndenter++;

    s <<
      existingLpsrScoreOutputKinds (K_NAMES_LIST_MAX_LENGTH);

    gIndenter--;

    oahError (s.str ());
  }

  setLpsrScoreOutputKindVariable (
    (*it).second);
}

void lpsrScoreOutputKindAtom::acceptIn (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrScoreOutputKindAtom::acceptIn ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrScoreOutputKindAtom>*
    p =
      dynamic_cast<visitor<S_lpsrScoreOutputKindAtom>*> (v)) {
        S_lpsrScoreOutputKindAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrScoreOutputKindAtom::visitStart ()" <<
            endl;
        }
#endif
        p->visitStart (elem);
  }
}

void lpsrScoreOutputKindAtom::acceptOut (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrScoreOutputKindAtom::acceptOut ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrScoreOutputKindAtom>*
    p =
      dynamic_cast<visitor<S_lpsrScoreOutputKindAtom>*> (v)) {
        S_lpsrScoreOutputKindAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrScoreOutputKindAtom::visitEnd ()" <<
            endl;
        }
#endif
        p->visitEnd (elem);
  }
}

void lpsrScoreOutputKindAtom::browseData (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrScoreOutputKindAtom::browseData ()" <<
      endl;
  }
#endif
}

string lpsrScoreOutputKindAtom::asShortNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fShortName << " " <<
    lpsrScoreOutputKindAsString (fLpsrScoreOutputKindVariable);

  return s.str ();
}

string lpsrScoreOutputKindAtom::asActualLongNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fLongName << " " <<
    lpsrScoreOutputKindAsString (fLpsrScoreOutputKindVariable);

  return s.str ();
}

void lpsrScoreOutputKindAtom::print (ostream& os) const
{
  const int fieldWidth = K_OAH_FIELD_WIDTH;

  os <<
    "OptionsLpsrScoreOutputKindAtom:" <<
    endl;

  gIndenter++;

  printValuedAtomEssentials (
    os, fieldWidth);

  os << left <<
    setw (fieldWidth) <<
    "fVariableName" << " : " <<
    fVariableName <<
    endl <<
    setw (fieldWidth) <<
    "fOptionsLpsrScoreOutputKindVariable" << " : \"" <<
    lpsrScoreOutputKindAsString (
      fLpsrScoreOutputKindVariable) <<
    "\"" <<
    endl;
}

void lpsrScoreOutputKindAtom::printAtomOptionsValues (
  ostream& os,
  int      valueFieldWidth) const
{
  os << left <<
    setw (valueFieldWidth) <<
    fVariableName <<
    " : \"" <<
    lpsrScoreOutputKindAsString (
      fLpsrScoreOutputKindVariable) <<
    "\"" <<
    endl;
}

ostream& operator<< (ostream& os, const S_lpsrScoreOutputKindAtom& elt)
{
  elt->print (os);
  return os;
}

//______________________________________________________________________________
S_lpsrPitchesLanguageAtom lpsrPitchesLanguageAtom::create (
  string             shortName,
  string             longName,
  string             description,
  string             valueSpecification,
  string             variableName,
  msrQuarterTonesPitchesLanguageKind&
                     lpsrPitchesLanguageKindVariable)
{
  lpsrPitchesLanguageAtom* o = new
    lpsrPitchesLanguageAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName,
      lpsrPitchesLanguageKindVariable);
  assert(o!=0);
  return o;
}

lpsrPitchesLanguageAtom::lpsrPitchesLanguageAtom (
  string             shortName,
  string             longName,
  string             description,
  string             valueSpecification,
  string             variableName,
  msrQuarterTonesPitchesLanguageKind&
                     lpsrPitchesLanguageKindVariable)
  : oahValuedAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName),
    fMsrQuarterTonesPitchesLanguageKindVariable (
      lpsrPitchesLanguageKindVariable)
{}

lpsrPitchesLanguageAtom::~lpsrPitchesLanguageAtom ()
{}

S_oahValuedAtom lpsrPitchesLanguageAtom::handleOptionUnderName (
  string   optionName,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    gLogOstream <<
      "==> option '" << optionName << "' is a lpsrPitchesLanguageAtom" <<
      endl;
  }
#endif

  // an option value is needed
  return this;
}

void lpsrPitchesLanguageAtom::handleValue (
  string   theString,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrPitchesLanguageAtom'" <<
      endl;
  }
#endif

  // theString contains the language name:
  // is it in the pitches languages map?

#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrPitchesLanguageAtom'" <<
      endl;
  }
#endif

  map<string, msrQuarterTonesPitchesLanguageKind>::const_iterator
    it =
      gQuarterTonesPitchesLanguageKindsMap.find (
        theString);

  if (it == gQuarterTonesPitchesLanguageKindsMap.end ()) {
    // no, language is unknown in the map

    stringstream s;

    s <<
      "LPSR pitches language '" << theString <<
      "' is unknown" <<
      endl <<
      "The " <<
      gQuarterTonesPitchesLanguageKindsMap.size () <<
      " known LPSR pitches languages are:" <<
      endl;

    gIndenter++;

    s <<
      existingQuarterTonesPitchesLanguageKinds (K_NAMES_LIST_MAX_LENGTH);

    gIndenter--;

    oahError (s.str ());
  }

  setMsrQuarterTonesPitchesLanguageKindVariable (
    (*it).second);
}

void lpsrPitchesLanguageAtom::acceptIn (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrPitchesLanguageAtom::acceptIn ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrPitchesLanguageAtom>*
    p =
      dynamic_cast<visitor<S_lpsrPitchesLanguageAtom>*> (v)) {
        S_lpsrPitchesLanguageAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrPitchesLanguageAtom::visitStart ()" <<
            endl;
        }
#endif
        p->visitStart (elem);
  }
}

void lpsrPitchesLanguageAtom::acceptOut (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrPitchesLanguageAtom::acceptOut ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrPitchesLanguageAtom>*
    p =
      dynamic_cast<visitor<S_lpsrPitchesLanguageAtom>*> (v)) {
        S_lpsrPitchesLanguageAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrPitchesLanguageAtom::visitEnd ()" <<
            endl;
        }
#endif
        p->visitEnd (elem);
  }
}

void lpsrPitchesLanguageAtom::browseData (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrPitchesLanguageAtom::browseData ()" <<
      endl;
  }
#endif
}

string lpsrPitchesLanguageAtom::asShortNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fShortName << " " <<
    msrQuarterTonesPitchesLanguageKindAsString (
      fMsrQuarterTonesPitchesLanguageKindVariable);

  return s.str ();
}

string lpsrPitchesLanguageAtom::asActualLongNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fLongName << " " <<
    msrQuarterTonesPitchesLanguageKindAsString (
      fMsrQuarterTonesPitchesLanguageKindVariable);

  return s.str ();
}

void lpsrPitchesLanguageAtom::print (ostream& os) const
{
  const int fieldWidth = K_OAH_FIELD_WIDTH;

  os <<
    "OptionsLpsrPitchesLanguageAtom:" <<
    endl;

  gIndenter++;

  printValuedAtomEssentials (
    os, fieldWidth);

  os << left <<
    setw (fieldWidth) <<
    "fVariableName" << " : " <<
    fVariableName <<
    endl <<
    setw (fieldWidth) <<
    "fOptionsLpsrPitchesLanguageVariable" << " : \"" <<
    msrQuarterTonesPitchesLanguageKindAsString (
      fMsrQuarterTonesPitchesLanguageKindVariable) <<
    "\"" <<
    endl;
}

void lpsrPitchesLanguageAtom::printAtomOptionsValues (
  ostream& os,
  int      valueFieldWidth) const
{
  os << left <<
    setw (valueFieldWidth) <<
    fVariableName <<
    " : \"" <<
    msrQuarterTonesPitchesLanguageKindAsString (
      fMsrQuarterTonesPitchesLanguageKindVariable) <<
    "\"" <<
    endl;
}

ostream& operator<< (ostream& os, const S_lpsrPitchesLanguageAtom& elt)
{
  elt->print (os);
  return os;
}

//______________________________________________________________________________
S_lpsrChordsLanguageAtom lpsrChordsLanguageAtom::create (
  string             shortName,
  string             longName,
  string             description,
  string             valueSpecification,
  string             variableName,
  lpsrChordsLanguageKind&
                     lpsrChordsLanguageKindVariable)
{
  lpsrChordsLanguageAtom* o = new
    lpsrChordsLanguageAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName,
      lpsrChordsLanguageKindVariable);
  assert(o!=0);
  return o;
}

lpsrChordsLanguageAtom::lpsrChordsLanguageAtom (
  string             shortName,
  string             longName,
  string             description,
  string             valueSpecification,
  string             variableName,
  lpsrChordsLanguageKind&
                     lpsrChordsLanguageKindVariable)
  : oahValuedAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName),
    fLpsrChordsLanguageKindVariable (
      lpsrChordsLanguageKindVariable)
{}

lpsrChordsLanguageAtom::~lpsrChordsLanguageAtom ()
{}

S_oahValuedAtom lpsrChordsLanguageAtom::handleOptionUnderName (
  string   optionName,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    gLogOstream <<
      "==> option '" << optionName << "' is a lpsrChordsLanguageAtom" <<
      endl;
  }
#endif

  // an option value is needed
  return this;
}

void lpsrChordsLanguageAtom::handleValue (
  string   theString,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrChordsLanguageAtom'" <<
      endl;
  }
#endif

  // theString contains the language name:
  // is it in the chords languages map?

#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrChordsLanguageAtom'" <<
      endl;
  }
#endif

  map<string, lpsrChordsLanguageKind>::const_iterator
    it =
      gLpsrChordsLanguageKindsMap.find (theString);

  if (it == gLpsrChordsLanguageKindsMap.end ()) {
    // no, language is unknown in the map
    stringstream s;

    s <<
      "LPSR chords language '" << theString <<
      "' is unknown" <<
      endl <<
      "The " <<
      gLpsrChordsLanguageKindsMap.size () - 1 <<
      " known LPSR chords languages apart from the default Ignatzek are:" <<
      endl;

    gIndenter++;

    s <<
      existingLpsrChordsLanguageKinds (K_NAMES_LIST_MAX_LENGTH);

    gIndenter--;

    oahError (s.str ());
  }

  setLpsrChordsLanguageKindVariable (
    (*it).second);
}

void lpsrChordsLanguageAtom::acceptIn (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrChordsLanguageAtom::acceptIn ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrChordsLanguageAtom>*
    p =
      dynamic_cast<visitor<S_lpsrChordsLanguageAtom>*> (v)) {
        S_lpsrChordsLanguageAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrChordsLanguageAtom::visitStart ()" <<
            endl;
        }
#endif
        p->visitStart (elem);
  }
}

void lpsrChordsLanguageAtom::acceptOut (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrChordsLanguageAtom::acceptOut ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrChordsLanguageAtom>*
    p =
      dynamic_cast<visitor<S_lpsrChordsLanguageAtom>*> (v)) {
        S_lpsrChordsLanguageAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrChordsLanguageAtom::visitEnd ()" <<
            endl;
        }
#endif
        p->visitEnd (elem);
  }
}

void lpsrChordsLanguageAtom::browseData (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrChordsLanguageAtom::browseData ()" <<
      endl;
  }
#endif
}

string lpsrChordsLanguageAtom::asShortNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fShortName << " " <<
    lpsrChordsLanguageKindAsString (fLpsrChordsLanguageKindVariable);

  return s.str ();
}

string lpsrChordsLanguageAtom::asActualLongNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fLongName << " " <<
    lpsrChordsLanguageKindAsString (fLpsrChordsLanguageKindVariable);

  return s.str ();
}

void lpsrChordsLanguageAtom::print (ostream& os) const
{
  const int fieldWidth = K_OAH_FIELD_WIDTH;

  os <<
    "OptionsLpsrChordsLanguageAtom:" <<
    endl;

  gIndenter++;

  printValuedAtomEssentials (
    os, fieldWidth);

  os << left <<
    setw (fieldWidth) <<
    "fVariableName" << " : " <<
    fVariableName <<
    setw (fieldWidth) <<
    "fLpsrChordsLanguageKindVariable" << " : \"" <<
    lpsrChordsLanguageKindAsString (
      fLpsrChordsLanguageKindVariable) <<
    "\"" <<
    endl;
}

void lpsrChordsLanguageAtom::printAtomOptionsValues (
  ostream& os,
  int      valueFieldWidth) const
{
  os << left <<
    setw (valueFieldWidth) <<
    fVariableName <<
    " : \"" <<
    lpsrChordsLanguageKindAsString (
      fLpsrChordsLanguageKindVariable) <<
    "\"" <<
    endl;
}

ostream& operator<< (ostream& os, const S_lpsrChordsLanguageAtom& elt)
{
  elt->print (os);
  return os;
}

//______________________________________________________________________________
S_lpsrTransposeAtom lpsrTransposeAtom::create (
  string  shortName,
  string  longName,
  string  description,
  string  valueSpecification,
  string  variableName,
  S_msrSemiTonesPitchAndOctave&
          lpsrTransposeVariable)
{
  lpsrTransposeAtom* o = new
    lpsrTransposeAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName,
      lpsrTransposeVariable);
  assert(o!=0);
  return o;
}

lpsrTransposeAtom::lpsrTransposeAtom (
  string  shortName,
  string  longName,
  string  description,
  string  valueSpecification,
  string  variableName,
  S_msrSemiTonesPitchAndOctave&
          lpsrTransposeVariable)
  : oahValuedAtom (
      shortName,
      longName,
      description,
      valueSpecification,
      variableName),
    fMsrSemiTonesPitchAndOctaveVariable (
      lpsrTransposeVariable)
{}

lpsrTransposeAtom::~lpsrTransposeAtom ()
{}

S_oahValuedAtom lpsrTransposeAtom::handleOptionUnderName (
  string   optionName,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    gLogOstream <<
      "==> option '" << optionName << "' is a lpsrTransposeAtom" <<
      endl;
  }
#endif

  // an option value is needed
  return this;
}

void lpsrTransposeAtom::handleValue (
  string   theString,
  ostream& os)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrTransposeAtom'" <<
      endl;
  }
#endif

  // theString contains the language name:
  // is it in the chords languages map?

#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah) {
    os <<
      "==> oahAtom is of type 'lpsrTransposeAtom'" <<
      endl;
  }
#endif

  // create the semitones pitch and octave from theString
  S_msrSemiTonesPitchAndOctave
    semiTonesPitchAndOctave =
      msrSemiTonesPitchAndOctave::createFromString (
        K_NO_INPUT_LINE_NUMBER,
        theString);

  // set the transpose atom variable value
  setMsrSemiTonesPitchAndOctaveVariable (
    semiTonesPitchAndOctave);
}

void lpsrTransposeAtom::acceptIn (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrTransposeAtom::acceptIn ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrTransposeAtom>*
    p =
      dynamic_cast<visitor<S_lpsrTransposeAtom>*> (v)) {
        S_lpsrTransposeAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrTransposeAtom::visitStart ()" <<
            endl;
        }
#endif
        p->visitStart (elem);
  }
}

void lpsrTransposeAtom::acceptOut (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrTransposeAtom::acceptOut ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrTransposeAtom>*
    p =
      dynamic_cast<visitor<S_lpsrTransposeAtom>*> (v)) {
        S_lpsrTransposeAtom elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrTransposeAtom::visitEnd ()" <<
            endl;
        }
#endif
        p->visitEnd (elem);
  }
}

void lpsrTransposeAtom::browseData (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrTransposeAtom::browseData ()" <<
      endl;
  }
#endif
}

string lpsrTransposeAtom::asShortNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fShortName << " " <<
    fMsrSemiTonesPitchAndOctaveVariable->asString ();

  return s.str ();
}

string lpsrTransposeAtom::asActualLongNamedOptionString () const
{
  stringstream s;

  s <<
    "-" << fLongName << " " <<
    fMsrSemiTonesPitchAndOctaveVariable->asString ();

  return s.str ();
}

void lpsrTransposeAtom::print (ostream& os) const
{
  const int fieldWidth = K_OAH_FIELD_WIDTH;

  os <<
    "lpsrTransposeAtom:" <<
    endl;

  gIndenter++;

  oahElement::printOptionEssentials (
    os, fieldWidth);

  gIndenter++;
  os <<
    gIndenter.indentMultiLineString (
      fDescription) <<
    endl;
  gIndenter--;

  gIndenter--;
}

void lpsrTransposeAtom::printAtomOptionsValues (
  ostream& os,
  int      valueFieldWidth) const
{
  os << left <<
    setw (valueFieldWidth) <<
    fVariableName <<
    " : ";
  if (fMsrSemiTonesPitchAndOctaveVariable) {
    os << endl;
    gIndenter++;
    os <<
      fMsrSemiTonesPitchAndOctaveVariable;
    gIndenter--;
  }
  else {
    os <<
      "none" <<
      endl;
  }
}

ostream& operator<< (ostream& os, const S_lpsrTransposeAtom& elt)
{
  elt->print (os);
  return os;
}

//_______________________________________________________________________________
S_lpsrOah gLpsrOah;
S_lpsrOah gLpsrOahUserChoices;
S_lpsrOah gLpsrOahWithDetailedTrace;

S_lpsrOah lpsrOah::create (
  S_oahHandler handlerUpLink)
{
  lpsrOah* o = new lpsrOah (
    handlerUpLink);
  assert(o!=0);
  return o;
}

lpsrOah::lpsrOah (
  S_oahHandler handlerUpLink)
  : oahGroup (
    "LPSR",
    "hlpsr", "help-lpsr",
R"(These options control the way LPSR data is handled.)",
    kElementVisibilityAlways,
    handlerUpLink)
{
  // append this options group to the options handler
  // if relevant
  if (handlerUpLink) {
    handlerUpLink->
      appendGroupToHandler (this);
  }

  // initialize it
  initializeLpsrOah (false);
}

lpsrOah::~lpsrOah ()
{}

#ifdef TRACE_OAH
void lpsrOah::initializeLpsrTraceOah (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Trace",
        "hlpsrtrace", "help-lpsr-trace",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // trace- lpsr

  fTraceLpsr            = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "tlpsr", "trace-lpsr",
R"(Write a trace of the LPSR graphs visiting activity to standard error.)",
        "traceLpsr",
        fTraceLpsr));

  // trace lilypond version

  fTraceLilypondVersion = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "tlpv", "trace-lilypond-version",
R"(Write a trace of the LilyPond version to standard error.)",
        "traceLilypondVersion",
        fTraceLilypondVersion));

  // trace lpsr visitors

  fTraceLpsrVisitors    = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "tlpsrv", "trace-lpsr-visitors",
R"(Write a trace of the LPSR graphs visiting activity to standard error.)",
        "traceLpsrVisitors",
        fTraceLpsrVisitors));

  // trace lpsr blocks

  fTraceLpsrBlocks      = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "tlpsrb", "trace-lpsr-blocks",
R"(Write a trace of the LPSR blocks to standard error.)",
        "traceLpsrBlocks",
        fTraceLpsrBlocks));

  // trace scheme functions

  fTraceSchemeFunctions = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "tsf", "trace-scheme-functions",
R"(Write a trace of the activity regarding Scheme functions to standard error.)",
        "traceSchemeFunctions",
        fTraceSchemeFunctions));
}
#endif

void lpsrOah::initializeLpsrDisplayOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Display",
        "hlpsrd", "help-lpsr-display",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // display LPSR

  fDisplayLpsr = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "dlpsr", "display-lpsr",
R"(Write the contents of the LPSR data to standard error.)",
        "displayLpsr",
        fDisplayLpsr));
}

void lpsrOah::initializeLpsrScoreOutputOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "LilyPond score output",
        "hlpso", "help-lilypond-score-output",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // LilyPond version

  string lilyPondVersionDefaultValue = "2.19.83";

  fLilyPondVersion = lilyPondVersionDefaultValue;

  subGroup->
    appendAtomToSubGroup (
      oahStringAtom::create (
        "lpv", "lilypond-version",
        replaceSubstringInString (
R"(Set the LilyPond '\version' to STRING in the LilyPond code.
The default is 'DEFAULT_VALUE'.)",
          "DEFAULT_VALUE",
          lilyPondVersionDefaultValue),
        "STRING",
        "lilyPondVersion",
        fLilyPondVersion));

  // LPSR score output kind

  const lpsrScoreOutputKind
    lpsrScoreOutputKindDefaultValue =
      kScoreOnly; // default value

  fScoreOutputKind = lpsrScoreOutputKindDefaultValue;

  subGroup->
    appendAtomToSubGroup (
      lpsrScoreOutputKindAtom::create (
        "lpsok", "lpsr-score-output-kind",
        replaceSubstringInString (
          replaceSubstringInString (
            replaceSubstringInString (
R"(Use OUTPUT_KIND to create the LPSR blocks,
as well as in the generated LilyPond code.
The NUMBER LilyPond output kinds available are:
  OUTPUT_KINDS.
'-one-file' means that LilyPond will produce a single file containing all the scores and/or parts.
Otherwise, one file will be generated for each score and/or part.
The default is 'DEFAULT_VALUE'.)",
              "NUMBER",
              to_string (gLpsrScoreOutputKindsMap.size ())),
            "OUTPUT_KINDS",
            existingLpsrScoreOutputKinds (K_NAMES_LIST_MAX_LENGTH)),
          "DEFAULT_VALUE",
          lpsrScoreOutputKindAsString (
            lpsrScoreOutputKindDefaultValue)),
        "OUTPUT_KIND",
        "scoreOutputKind",
        fScoreOutputKind));
}

void lpsrOah::initializeLpsrGlobalStaffSizeOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Global staff size",
        "hlpsrgss", "help-lpsr-gss",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // global staff size

  fStaffGlobalSizeDefaultValue = 20; // LilyPond default
  fGlobalStaffSize = fStaffGlobalSizeDefaultValue;

  subGroup->
    appendAtomToSubGroup (
      oahFloatAtom::create (
        "gss", "global-staff-size",
        replaceSubstringInString (
R"(Set the LilyPond '#(set-global-staff-size ...)' to FLOAT in the LilyPond code.
FLOAT should be a floating point or integer number.
The default is 'DEFAULT_VALUE'.)",
          "DEFAULT_VALUE",
          to_string (fStaffGlobalSizeDefaultValue)),
        "FLOAT",
        "globalStaffSize",
        fGlobalStaffSize));
}

void lpsrOah::initializeLpsrPaperOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Paper",
        "hlpsrpaper", "help-lpsr-paper",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // length unit kind

  fLengthUnitKindDefaultValue = kMillimeterUnit; // default value;
  fLengthUnitKind = fLengthUnitKindDefaultValue;

  subGroup->
    appendAtomToSubGroup (
      oahLengthUnitKindAtom::create (
        "length-unit", "",
        replaceSubstringInString (
          replaceSubstringInString (
            replaceSubstringInString (
R"(Set the LilyPond length variables unit to UNIT in the forthcoming options.
The NUMBER LilyPond length variables units available are:
LENTGTH_UNITS.
This option should precede options that set paper size and indents
if they don't specify a unit.
The default is 'DEFAULT_VALUE'.)",
              "NUMBER",
              to_string (gMsrLengthUnitKindsMap.size ())),
            "LENTGTH_UNITS",
            gIndenter.indentMultiLineString (
              existingMsrLengthUnitKinds (K_NAMES_LIST_MAX_LENGTH))),
          "DEFAULT_VALUE",
          msrLengthUnitKindAsString (
            fLengthUnitKindDefaultValue)),
        "UNIT",
        "lengthUnitKind",
        fLengthUnitKind));

  // paper height

  fPaperHeight.setLengthUnitKind (kMillimeterUnit);
  fPaperHeight.setLengthValue (297);

  subGroup->
    appendAtomToSubGroup (
      oahLengthAtom::create (
        "paper-height", "",
R"(Set the LilyPond 'paper-height' paper variable to HEIGHT in the LilyPond code.
HEIGHT should be a positive floating point or integer number,
immediately followed by a unit name, i.e. 'in', 'mm' or 'cm'.
The default value is 210 mm (A4 format).)",
        "HEIGHT",
        "paperHeight",
        fPaperHeight));

  // paper width

  fPaperWidth.setLengthUnitKind (kMillimeterUnit);
  fPaperWidth.setLengthValue (210);

  subGroup->
    appendAtomToSubGroup (
      oahLengthAtom::create (
        "paper-width", "",
R"(Set the LilyPond 'paper-width' paper variable to WIDTH in the LilyPond code.
WIDTH should be a positive floating point or integer number,
immediately followed by a unit name, i.e. 'in', 'mm' or 'cm'.
The default value is 297 mm (A4 format).)",
        "WIDTH",
        "paperWidth",
        fPaperWidth));

  // fPaperHorizontalShift is 0.0 mm by default

  subGroup->
    appendAtomToSubGroup (
      oahLengthAtom::create (
        "hshift", "horizontal-shift",
R"(Set the LilyPond 'horizontal-shift' paper variable to SHIFT in the LilyPond code.
SHIFT should be a floating point or integer number,
immediately followed by a unit name, i.e. 'in', 'mm' or 'cm'.
The default value is 0.0 mm.)",
        "SHIFT",
        "paperHorizontalShift",
        fPaperHorizontalShift));

  // fPaperIndent is 0.0 mm by default

  subGroup->
    appendAtomToSubGroup (
      oahLengthAtom::create (
        "indent", "",
R"(Set the LilyPond 'indent' paper variable to INDENT in the LilyPond code.
INDENT should be a floating point or integer number,
immediately followed by a unit name, i.e. 'in', 'mm' or 'cm'.
The default value is 0.0 mm.)",
        "INDENT",
        "paperIndent",
        fPaperIndent));

  // short indent

  // fPaperShortIndent is 0.0 mm by default

  subGroup->
    appendAtomToSubGroup (
      oahLengthAtom::create (
        "short-indent", "",
R"(Set the LilyPond 'short-indent' paper variable to SHORT_INDENT in the LilyPond code.
SHORT_INDENT should be a floating point or integer number,
immediately followed by a unit name, i.e. 'in', 'mm' or 'cm'.
The default value is 0.0 mm.)",
        "SHORT_INDENT",
        "paperShortIndent",
        fPaperShortIndent));

  // fMarkupSystemSpacingPadding is 0.0 mm by default

  subGroup->
    appendAtomToSubGroup (
      oahLengthAtom::create (
        "mssp", "markup-system-spacing.padding",
R"(Set the LilyPond 'markup-system-spacing.padding' paper variable to PADDING in the LilyPond code.
PADDING should be a floating point or integer number,
immediately followed by a unit name, i.e. 'in', 'mm' or 'cm'.
LilyPond's default value is 0.0 mm.)",
        "INDENT",
        "markupSystemSpacingPadding",
        fMarkupSystemSpacingPadding));

  // ragged bottom

  fRaggedBottom = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "ragged-bottom", "",
R"(Set the LilyPond 'ragged-bottom' paper variable to '##f' in the LilyPond code.
LilyPond's default value is '##t'.)",
        "raggedBottom",
        fRaggedBottom));

  // ragged last bottom

  fRaggedLastBottom = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "ragged-last-bottom", "",
R"(Set the LilyPond 'ragged-last-bottom' paper variable to '##f' in the LilyPond code.
LilyPond's default value is '##t'.)",
        "raggedLastBottom",
        fRaggedLastBottom));

/* LPSR or LilyPond option?"
  // tagline

  fTagline = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "tagline", "",
R"(Set the LilyPond 'tagline' paper variable to '##f' in the LilyPond code.
LilyPond's default value is '##t'.)",
        "tagline",
        fTagline));
*/

  // page count

  fPageCount = -1;

  subGroup->
    appendAtomToSubGroup (
      oahIntegerAtom::create (
        "page-count", "",
R"(Set the LilyPond 'page-count' paper variable to PAGE_COUNT in the LilyPond code.
PAGE_COUNT should be a positive integer.
By default, this is left to LilyPond'.)",
        "PAGE_COUNT",
        "pageCount",
        fPageCount));

  // system count

  fSystemCount = -1;

  subGroup->
    appendAtomToSubGroup (
      oahIntegerAtom::create (
        "system-count", "",
R"(Set the LilyPond 'system-count' paper variable to SYSTEM_COUNT in the LilyPond code.
SYSTEM_COUNT should be a positive integer.
By default, this is left to LilyPond'.)",
        "SYSTEM_COUNT",
        "systemCount",
        fSystemCount));
}

void lpsrOah::initializeLpsrMeasuresOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Measures",
        "hlpsrmeasures", "help-lpsr-measures",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // replicate empty measure

  fReplicateEmptyMeasureNumber = "";
  fReplicateEmptyMeasureReplicas = 0;

  subGroup->
    appendAtomToSubGroup (
      oahStringAndIntegerAtom::create (
        "rem", "replicate-empty-measure",
R"###(Replicate an empty mesure, adding empty others according to SPECIFICATION.
SPECIFICATION should be of the form 'MEASURE_NUMBER REPLICATES',
where MEASURE_NUMBER is a string, and REPLICATES is the number
of empty measures to add after measure MEASURE_NUMBER.
MEASURE_NUMBER should be the number of an existing, empty measure,
and REPLICATES should be at least 1, , such as '17 3'.
This comes in handly when MusicXML data obtained by scanning contains
a single empty measure when there were several in the original score.
This option can be used any number of times.)###",
        "SPECIFICATION",
        "replicateEmptyMeasureNumber",
        fReplicateEmptyMeasureNumber,
        "replicateEmptyMeasureReplicas",
        fReplicateEmptyMeasureReplicas));
}

void lpsrOah::initializeLpsrWordsOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Words",
        "hlpsrwords", "help-lpsr-words",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // convert words to tempo

  fConvertWordsToTempo = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "cwtt", "convert-words-to-tempo",
R"(Convert words to tempo.
This may come in handy when MusicXML data has been obtained from scanned instrumental music images.)",
        "convertWordsToTempo",
        fConvertWordsToTempo));

  // add words from the lyrics

  fAddWordsFromTheLyrics = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "awftl", "add-words-from-the-lyrics",
R"(Add words with the lyrics contents, keeping the latter untouched.
This may come in handy when MusicXML data has been obtained from scanned images.)",
        "addWordsFromTheLyrics",
        fAddWordsFromTheLyrics));

  // convert tempos to rehearsal marks

  fConvertTemposToRehearsalMarks = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "cttrm", "convert-tempos-to-rehearsal-marks",
R"(Convert tempos to rehearsal marks.
This may come in handy when MusicXML data has been obtained from scanned instrumental music images.)",
        "convertTemposToRehearsalMarks",
        fConvertTemposToRehearsalMarks));

  // convert words to rehearsal marks

  fConvertWordsToRehearsalMarks = boolOptionsInitialValue;

  subGroup->
    appendAtomToSubGroup (
      oahBooleanAtom::create (
        "cwtrm", "convert-words-to-rehearsal-marks",
R"(Convert words to rehearsal marks.
This may come in handy when MusicXML data has been obtained from scanned instrumental music images.)",
        "convertWordsToRehearsalMarks",
        fConvertWordsToRehearsalMarks));
}

void lpsrOah::initializeLpsrLanguagesOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Languages",
        "hlpsrl", "help-lpsr-languages",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // lpsr pitches language

  if (! setLpsrQuarterTonesPitchesLanguage ("nederlands")) {
    stringstream s;

    s <<
      "INTERNAL INITIALIZATION ERROR: "
      "LPSR pitches language 'nederlands' is unknown" <<
      endl <<
      "The " <<
      gQuarterTonesPitchesLanguageKindsMap.size () <<
      " known LPSR pitches languages are:" <<
      endl;

    gIndenter++;

    s <<
      existingQuarterTonesPitchesLanguageKinds (K_NAMES_LIST_MAX_LENGTH);

    gIndenter--;

    oahError (s.str ());
  }

  const msrQuarterTonesPitchesLanguageKind
    msrQuarterTonesPitchesLanguageKindDefaultValue =
      fLpsrQuarterTonesPitchesLanguageKind;

  fLpsrQuarterTonesPitchesLanguageKind =
    msrQuarterTonesPitchesLanguageKindDefaultValue;

  subGroup->
    appendAtomToSubGroup (
      lpsrPitchesLanguageAtom::create (
        "lppl", "lpsr-pitches-language",
        replaceSubstringInString (
          replaceSubstringInString (
            replaceSubstringInString (
R"(Use LANGUAGE to display note pitches in the LPSR logs and views,
as well as in the generated LilyPond code.
The NUMBER LilyPond pitches languages available are:
PITCHES_LANGUAGES.
The default is 'DEFAULT_VALUE'.)",
              "NUMBER",
              to_string (gQuarterTonesPitchesLanguageKindsMap.size ())),
            "PITCHES_LANGUAGES",
            gIndenter.indentMultiLineString (
              existingQuarterTonesPitchesLanguageKinds (K_NAMES_LIST_MAX_LENGTH))),
          "DEFAULT_VALUE",
          msrQuarterTonesPitchesLanguageKindAsString (
            msrQuarterTonesPitchesLanguageKindDefaultValue)),
        "LANGUAGE",
        "lpsrPitchesLanguage",
        fLpsrQuarterTonesPitchesLanguageKind));

  // lpsr chords language

  const lpsrChordsLanguageKind
    lpsrChordsLanguageKindDefaultValue =
      k_IgnatzekChords; // LilyPond default

  fLpsrChordsLanguageKind =
    lpsrChordsLanguageKindDefaultValue;

  subGroup->
    appendAtomToSubGroup (
      lpsrChordsLanguageAtom::create (
        "lpcl", "lpsr-chords-language",
        replaceSubstringInString (
          replaceSubstringInString (
            replaceSubstringInString (
R"(Use LANGUAGE to display chord names, their root and bass notes,
in the LPSR logs and views and the generated LilyPond code.
The NUMBER LilyPond pitches languages available are:
CHORDS_LANGUAGES.
'ignatzek' is Ignatzek's jazz-like, english naming used by LilyPond by default.
The default is 'DEFAULT_VALUE'.)",
              "NUMBER",
              to_string (gLpsrChordsLanguageKindsMap.size ())),
            "CHORDS_LANGUAGES",
            gIndenter.indentMultiLineString (
              existingLpsrChordsLanguageKinds (K_NAMES_LIST_MAX_LENGTH))),
          "DEFAULT_VALUE",
          lpsrChordsLanguageKindAsString (
            lpsrChordsLanguageKindDefaultValue)),
        "LANGUAGE",
        "lpsr-chords-language",
        fLpsrChordsLanguageKind));
}

void lpsrOah::initializeLpsrTransposeOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Transpose",
        "hlpsrt", "help-lpsr-transpose",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // lpsr transpose

  subGroup->
    appendAtomToSubGroup (
      lpsrTransposeAtom::create (
        "lpt", "lpsr-transpose",
R"(Use TRANSPOSITION to tranpose in the LPSR data,
thus as in the generated LilyPond code as well.
TRANSPOSITION should contain a diatonic pitch, followed if needed
by a sequence of ',' or '\'' octave indications.
Such indications cannot be mixed.
For example, 'a', 'f' and 'bes,' can be used respectively
for instruments in 'a', 'f' and B flat respectively)",
        "TRANSPOSITION",
        "lpsrTranspose",
        fTransposeSemiTonesPitchAndOctave));
}

void lpsrOah::initializeLpsrExitAfterSomePassesOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    subGroup =
      oahSubGroup::create (
        "Exit after some passes",
        "hlexit", "help-lpsr-exit",
R"()",
      kElementVisibilityAlways,
      this);

  appendSubGroupToGroup (subGroup);

  // exit after pass 3

  fExit3 = boolOptionsInitialValue;

  S_oahBooleanAtom
    exit3OahBooleanAtom =
      oahBooleanAtom::create (
        "e3", "exit-3",
R"(Exit after pass 3, i.e. after conversion
of the MSR to LPSR.)",
        "exit3",
        fExit3);

  subGroup->
    appendAtomToSubGroup (
      exit3OahBooleanAtom);
}

void lpsrOah::initializeLpsrOah (
  bool boolOptionsInitialValue)
{
#ifdef TRACE_OAH
  // trace and display
  // --------------------------------------
  initializeLpsrTraceOah (
    boolOptionsInitialValue);
#endif

  // display
  // --------------------------------------
  initializeLpsrDisplayOptions (
    boolOptionsInitialValue);

  // LilyPond score output
  // --------------------------------------
  initializeLpsrScoreOutputOptions (
    boolOptionsInitialValue);

  // global staff size
  // --------------------------------------
  initializeLpsrGlobalStaffSizeOptions (
    boolOptionsInitialValue);

  // paper
  // --------------------------------------
  initializeLpsrPaperOptions (
    boolOptionsInitialValue);

  // measures
  // --------------------------------------
  initializeLpsrMeasuresOptions (
    boolOptionsInitialValue);

  // words
  // --------------------------------------
  initializeLpsrWordsOptions (
    boolOptionsInitialValue);

  // languages
  // --------------------------------------
  initializeLpsrLanguagesOptions (
    boolOptionsInitialValue);

  // transpose
  // --------------------------------------
  initializeLpsrTransposeOptions (
    boolOptionsInitialValue);

  // exit after some passes
  // --------------------------------------
  initializeLpsrExitAfterSomePassesOptions (
    boolOptionsInitialValue);
}

S_lpsrOah lpsrOah::createCloneWithDetailedTrace ()
{
  S_lpsrOah
    clone =
      lpsrOah::create (0);
      // 0 not to have it inserted twice in the option handler

  // set the options handler upLink
  clone->fHandlerUpLink =
    fHandlerUpLink;

  // trace
  // --------------------------------------

#ifdef TRACE_OAH
  clone->fTraceLpsr =
    true;

  clone->fTraceLilypondVersion =
    true;

  clone->fTraceLpsrVisitors =
    true;

  clone->fTraceLpsrBlocks =
    true;

  clone->fTraceSchemeFunctions =
    true;
#endif

  // display
  // --------------------------------------

  clone->fDisplayLpsr =
    true;

  // LilyPond version
  // --------------------------------------

  clone->fLilyPondVersion =
    fLilyPondVersion;

  // LilyPond output kind
  // --------------------------------------

  clone->fScoreOutputKind =
    fScoreOutputKind;

  // global staff size
  // --------------------------------------

  clone->fGlobalStaffSize =
    fGlobalStaffSize;

  // paper
  // --------------------------------------

  clone->fLengthUnitKind =
    fLengthUnitKind;
  clone->fLengthUnitKindDefaultValue =
    fLengthUnitKindDefaultValue;

  clone->fPaperHeight =
    fPaperHeight;
  clone->fPaperWidth =
    fPaperWidth;

  clone->fPaperIndent =
    fPaperIndent;
  clone->fPaperShortIndent =
    fPaperShortIndent;

  clone->fMarkupSystemSpacingPadding =
    fMarkupSystemSpacingPadding;

  clone->fRaggedBottom =
    fRaggedBottom;
  clone->fRaggedLastBottom =
    fRaggedLastBottom;

  clone->fTagline =
    fTagline;

  clone->fPageCount =
    fPageCount;
  clone->fSystemCount =
    fSystemCount;

  // measures
  // --------------------------------------

  clone->fReplicateEmptyMeasureNumber =
    fReplicateEmptyMeasureNumber;
  clone->fReplicateEmptyMeasureReplicas =
    fReplicateEmptyMeasureReplicas;

  clone->fAddEmptyMeasuresStringToIntMap =
    fAddEmptyMeasuresStringToIntMap;

  // words
  // --------------------------------------

  clone->fConvertWordsToTempo =
    true;
  clone->fAddWordsFromTheLyrics =
    true;

  // rehearsal marks
  clone->fConvertTemposToRehearsalMarks =
    true;
  clone->fConvertWordsToRehearsalMarks =
    true;

  // languages
  // --------------------------------------

  clone->fLpsrQuarterTonesPitchesLanguageKind =
    fLpsrQuarterTonesPitchesLanguageKind;

  clone->fLpsrChordsLanguageKind =
    fLpsrChordsLanguageKind;

  // transpose
  // --------------------------------------

  clone->fTransposeSemiTonesPitchAndOctave =
    fTransposeSemiTonesPitchAndOctave;

  return clone;
}

//______________________________________________________________________________
bool lpsrOah::setLpsrQuarterTonesPitchesLanguage (string language)
{
  // is language in the note names languages map?
  map<string, msrQuarterTonesPitchesLanguageKind>::const_iterator
    it =
      gQuarterTonesPitchesLanguageKindsMap.find (language);

  if (it == gQuarterTonesPitchesLanguageKindsMap.end ()) {
    // no, language is unknown in the map
    return false;
  }

  fLpsrQuarterTonesPitchesLanguageKind = (*it).second;

  return true;
}

//______________________________________________________________________________
bool lpsrOah::setLpsrChordsLanguage (string language)
{
  // is language in the chords languages map?
  map<string, lpsrChordsLanguageKind>::const_iterator
    it =
      gLpsrChordsLanguageKindsMap.find (language);

  if (it == gLpsrChordsLanguageKindsMap.end ()) {
    // no, language is unknown in the map
    return false;
  }

  fLpsrChordsLanguageKind = (*it).second;

  return true;
}

//______________________________________________________________________________
void lpsrOah::enforceQuietness ()
{
#ifdef TRACE_OAH
  fTraceLpsr = false;
  fTraceLilypondVersion = false;
  fTraceLpsrVisitors = false;
  fTraceLpsrBlocks = false;
  fTraceSchemeFunctions = false;
#endif

  fDisplayLpsr = false;
}

//______________________________________________________________________________
void lpsrOah::checkOptionsConsistency ()
{
  // JMI
}

//______________________________________________________________________________
void lpsrOah::acceptIn (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrOah::acceptIn ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrOah>*
    p =
      dynamic_cast<visitor<S_lpsrOah>*> (v)) {
        S_lpsrOah elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrOah::visitStart ()" <<
            endl;
        }
#endif
        p->visitStart (elem);
  }
}

void lpsrOah::acceptOut (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrOah::acceptOut ()" <<
      endl;
  }
#endif

  if (visitor<S_lpsrOah>*
    p =
      dynamic_cast<visitor<S_lpsrOah>*> (v)) {
        S_lpsrOah elem = this;

#ifdef TRACE_OAH
        if (gOahOah->fTraceOahVisitors) {
          gLogOstream <<
            ".\\\" ==> Launching lpsrOah::visitEnd ()" <<
            endl;
        }
#endif
        p->visitEnd (elem);
  }
}

void lpsrOah::browseData (basevisitor* v)
{
#ifdef TRACE_OAH
  if (gOahOah->fTraceOahVisitors) {
    gLogOstream <<
      ".\\\" ==> lpsrOah::browseData ()" <<
      endl;
  }
#endif
}

//______________________________________________________________________________
void lpsrOah::printLpsrOahValues (int fieldWidth)
{
  gLogOstream <<
    "The LPSR options are:" <<
    endl;

  gIndenter++;

#ifdef TRACE_OAH
  // trace
  // --------------------------------------
  gLogOstream <<
    "Trace:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "traceLpsr" << " : " <<
    booleanAsString (fTraceLpsr) <<
    endl <<

    setw (fieldWidth) << "traceLilypondVersion" << " : " <<
    booleanAsString (fTraceLilypondVersion) <<
    endl <<

    setw (fieldWidth) << "traceLpsrVisitors" << " : " <<
    booleanAsString (fTraceLpsrVisitors) <<
    endl <<

    setw (fieldWidth) << "traceLpsrBlocks" << " : " <<
    booleanAsString (fTraceLpsrBlocks) <<
    endl <<

    setw (fieldWidth) << "traceSchemeFunctions" << " : " <<
    booleanAsString (fTraceSchemeFunctions) <<
    endl;

  gIndenter--;
#endif

  // display
  // --------------------------------------
  gLogOstream <<
    "Display:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "displayLpsr" << " : " <<
    booleanAsString (fDisplayLpsr) <<
    endl;

  gIndenter--;

  // LilyPond version
  // --------------------------------------

  gLogOstream <<
    "LilyPond version:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "lilyPondVersion" << " : " <<
    fLilyPondVersion <<
    endl;

  gIndenter--;

  // LilyPond output kind
  // --------------------------------------

  gLogOstream <<
    "LilyPond output kind:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "scoreOutputKind" << " : " <<
    lpsrScoreOutputKindAsString (fScoreOutputKind) <<
    endl;

  gIndenter--;

  // global staff size
  // --------------------------------------

  gLogOstream <<
    "Global staff size:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "fGlobalStaffSize" << " : " <<
    fGlobalStaffSize <<
    endl;

  gIndenter--;

  // paper
  // --------------------------------------

  gLogOstream <<
    "Paper:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "lengthUnitKind" << " : " <<
    msrLengthUnitKindAsString (fLengthUnitKind) <<
    endl <<

    setw (fieldWidth) << "paperHeight" << " : " <<
    fPaperHeight.asString () <<
    endl <<
    setw (fieldWidth) << "paperWidth" << " : " <<
    fPaperWidth.asString () <<
    endl <<

    setw (fieldWidth) << "paperIndent" << " : " <<
    fPaperIndent.asString () <<
    endl <<
    setw (fieldWidth) << "paperShortIndent" << " : " <<
    fPaperShortIndent.asString () <<
    endl <<

    setw (fieldWidth) << "markupSystemPpacingPadding" << " : " <<
    fMarkupSystemSpacingPadding.asString () <<
    endl <<

    setw (fieldWidth) << "raggedBottom" << " : " <<
    booleanAsString (fRaggedBottom) <<
    endl <<
    setw (fieldWidth) << "raggedLastBottom" << " : " <<
    booleanAsString (fRaggedLastBottom) <<
    endl <<

    setw (fieldWidth) << "tagline" << " : " <<
    booleanAsString (fTagline) <<
    endl <<

    setw (fieldWidth) << "pageCount" << " : " <<
    fPageCount <<
    endl <<
    setw (fieldWidth) << "systemCount" << " : " <<
    fSystemCount <<
    endl;

  gIndenter--;

  // measures
  // --------------------------------------

  gLogOstream <<
    "Measures:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "resetMeasureElementMeasureNumberMap" << " : ";
  if (! fAddEmptyMeasuresStringToIntMap.size ()) {
    gLogOstream << "empty";
  }
  else {
    map<string, int>::const_iterator
      iBegin = fAddEmptyMeasuresStringToIntMap.begin (),
      iEnd   = fAddEmptyMeasuresStringToIntMap.end (),
      i      = iBegin;
    for ( ; ; ) {
      gLogOstream << (*i).first << "=" << (*i).second;
      if (++i == iEnd) break;
      gLogOstream << ",";
    } // for
  }
  gLogOstream << endl;

  gIndenter--;

  // words
  // --------------------------------------

  gLogOstream <<
    "Words:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "convertWordsToTempo" << " : " <<
    booleanAsString (fConvertWordsToTempo) <<
    endl <<
    setw (fieldWidth) << "addWordsFromTheLyrics" << " : " <<
    booleanAsString (fAddWordsFromTheLyrics) <<
    endl;

  gIndenter--;

  // rehearsal marks
  // --------------------------------------

  gLogOstream <<
    "Rehearsal marks:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "convertTemposToRehearsalMarks" << " : " <<
    booleanAsString (fConvertTemposToRehearsalMarks) <<
    endl <<
    setw (fieldWidth) << "convertWordsToRehearsalMarks" << " : " <<
    booleanAsString (fConvertWordsToRehearsalMarks) <<
    endl;

  gIndenter--;

  // languages
  // --------------------------------------

  gLogOstream <<
    "Languages:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "lpsrQuarterTonesPitchesLanguage" << " : \"" <<
    msrQuarterTonesPitchesLanguageKindAsString (
      fLpsrQuarterTonesPitchesLanguageKind) <<
    "\"" <<
    endl <<

    setw (fieldWidth) << "lpsrChordsLanguage" << " : \"" <<
    lpsrChordsLanguageKindAsString (
      fLpsrChordsLanguageKind) <<
    "\"" <<
    endl;

  gIndenter--;

  // transpose
  // --------------------------------------

  gLogOstream <<
    "Transpose:" <<
    endl;

  gIndenter++;

  gLogOstream << left <<
    setw (fieldWidth) << "transposeSemiTonesPitchAndOctave" << " : ";

    if (fTransposeSemiTonesPitchAndOctave) {
      gLogOstream <<
        fTransposeSemiTonesPitchAndOctave->asString ();
    }
    else {
      gLogOstream <<
        "none";
    }
  gLogOstream << endl;

  gIndenter--;


  gIndenter--;
}

void lpsrOah::crackLilypondVersionNumber (
  string theString,
  int&   generationNumber,
  int&   majorNumber,
  int&   minorNumber)
{
  // obtains the three numbers in "2.19.83" or "2.20" for example

  // decipher theString with a three-number regular expression
  string regularExpression (
    "([[:digit:]]+)"
    "."
    "([[:digit:]]+)"
    "."
    "([[:digit:]]+)");

  regex  e (regularExpression);
  smatch sm;

  regex_match (theString, sm, e);

  unsigned smSize = sm.size ();

#ifdef TRACE_OAH
  if (gLpsrOah->fTraceLilypondVersion) {
    gLogOstream <<
      "There are " << smSize << " matches" <<
      " for version string '" << theString <<
      "' with regex '" << regularExpression <<
      "'" <<
      endl <<
      smSize << " elements: ";

      for (unsigned i = 0; i < smSize; ++i) {
        gLogOstream <<
          "[" << sm [i] << "] ";
      } // for

      gLogOstream << endl;
    }
#endif

  if (smSize == 4) {
    // found an n.x.y specification
    string
      generationNumberValue = sm [1],
      majorNumberValue      = sm [2],
      minorNumberValue      = sm [3];

#ifdef TRACE_OAH
    if (gLpsrOah->fTraceLilypondVersion) {
      gLogOstream <<
        "--> generationNumberValue = \"" << generationNumberValue << "\", " <<
        "--> majorNumberValue = \"" << majorNumberValue << "\", " <<
        "--> minorNumberValue = \"" << minorNumberValue << "\"" <<
        endl;
    }
#endif

    generationNumber = stoi (generationNumberValue);
    majorNumber      = stoi (majorNumberValue);
    minorNumber      = stoi (minorNumberValue);
  }

  else {
    // decipher theString with a two-number regular expression
    string regularExpression (
      "([[:digit:]]+)"
      "."
      "([[:digit:]]+)");

    regex  e (regularExpression);
    smatch sm;

    regex_match (theString, sm, e);

    unsigned smSize = sm.size ();

#ifdef TRACE_OAH
    if (gLpsrOah->fTraceLilypondVersion) {
      gLogOstream <<
        "There are " << smSize << " matches" <<
        " for chord details string '" << theString <<
        "' with regex '" << regularExpression <<
        "'" <<
        endl <<
        smSize << " elements: ";

        for (unsigned i = 0; i < smSize; ++i) {
          gLogOstream <<
            "[" << sm [i] << "] ";
        } // for

        gLogOstream << endl;
      }
#endif

    if (smSize == 3) {
      // found an n.x specification
      // assume implicit 0 minor number
      string
        generationNumberValue = sm [1],
        majorNumberValue      = sm [2];

#ifdef TRACE_OAH
      if (gLpsrOah->fTraceLilypondVersion) {
        gLogOstream <<
          "--> generationNumberValue = \"" << generationNumberValue << "\", " <<
          "--> majorNumberValue = \"" << majorNumberValue << "\", " <<
          endl;
      }
#endif

      generationNumber = stoi (generationNumberValue);
      majorNumber      = stoi (majorNumberValue);
      minorNumber      = 0;
    }

    else {
      stringstream s;

      s <<
        "version number argument '" << theString <<
        "' is ill-formed";

      oahError (s.str ());
    }
  }
}

bool lpsrOah::versionNumberGreaterThanOrEqualTo (
  string otherVersionNumber)
{
  bool result = false;

  int
    lilyPondVersionGenerationNumber,
    lilyPondVersionMajorNumber,
    lilyPondVersionMinorNumber;

  crackLilypondVersionNumber (
    fLilyPondVersion,
    lilyPondVersionGenerationNumber,
    lilyPondVersionMajorNumber,
    lilyPondVersionMinorNumber);

  int
    otherVersionNumbeGenerationNumber,
    otherVersionNumbeMajorNumber,
    otherVersionNumbeMinorNumber;

  crackLilypondVersionNumber (
    otherVersionNumber,
    otherVersionNumbeGenerationNumber,
    otherVersionNumbeMajorNumber,
    otherVersionNumbeMinorNumber);

  if (otherVersionNumbeGenerationNumber != 2) {
    gLogOstream <<
      "Using verstion \"" <<
      otherVersionNumbeGenerationNumber << ".x.y\" " <<
      "is probably not such a good idea" <<
      endl;
  }

  if (otherVersionNumbeMajorNumber < 19) {
    gLogOstream <<
      "Using a verstion older than \"" <<
      otherVersionNumbeGenerationNumber << ".19.y\" " <<
      "is not a good idea: the generated LilyPond code uses features introduced in the latter" <<
      endl;
  }

  if (lilyPondVersionGenerationNumber < otherVersionNumbeGenerationNumber) {
    result = false;
  }
  else if (lilyPondVersionGenerationNumber > otherVersionNumbeGenerationNumber) {
    result = true;
  }
  else {
    // same generation number
    if (lilyPondVersionMajorNumber < otherVersionNumbeMajorNumber) {
      result = false;
    }
    else if (lilyPondVersionMajorNumber > otherVersionNumbeMajorNumber) {
      result = true;
    }
    else {
      // same major number
      result =
        lilyPondVersionMinorNumber >= otherVersionNumbeMinorNumber;
    }
  }

  return result;
}

ostream& operator<< (ostream& os, const S_lpsrOah& elt)
{
  elt->print (os);
  return os;
}

//______________________________________________________________________________
void initializeLpsrOahHandling (
  S_oahHandler handler)
{
#ifdef TRACE_OAH
  if (gTraceOah->fTraceOah && ! gGeneralOah->fQuiet) {
    gLogOstream <<
      "Initializing LPSR options handling" <<
      endl;
  }
#endif

  // create the options variables
  // ------------------------------------------------------

  gLpsrOahUserChoices = lpsrOah::create (
    handler);
  assert(gLpsrOahUserChoices != 0);

  gLpsrOah =
    gLpsrOahUserChoices;

  // prepare for measure detailed trace
  // ------------------------------------------------------

/* JMI
  gLpsrOahWithDetailedTrace =
    gLpsrOah->
      createCloneWithDetailedTrace ();
      */
}


}
