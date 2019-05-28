/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include "msrMutualDependencies.h"

#include "setTraceOptionsIfDesired.h"
#ifdef TRACE_OPTIONS
  #include "traceOptions.h"
#endif

#include "msrOptions.h"


using namespace std;

namespace MusicXML2 
{

//______________________________________________________________________________
S_msrSyllable msrSyllable::create (
  int                   inputLineNumber,
  msrSyllableKind       syllableKind,
  msrSyllableExtendKind syllableExtendKind,
  rational              syllableWholeNotes,
  msrTupletFactor       syllableTupletFactor,
  S_msrStanza           syllableStanzaUplink)
{
  msrSyllable* o =
    new msrSyllable (
      inputLineNumber,
      syllableKind,
      syllableExtendKind,
      syllableWholeNotes,
      syllableTupletFactor,
      syllableStanzaUplink);
  assert(o!=0);

  return o;
}

msrSyllable::msrSyllable (
  int                   inputLineNumber,
  msrSyllableKind       syllableKind,
  msrSyllableExtendKind syllableExtendKind,
  rational              syllableWholeNotes,
  msrTupletFactor       syllableTupletFactor,
  S_msrStanza           syllableStanzaUplink)
    : msrElement (inputLineNumber)
{
  // sanity check
  msrAssert(
    syllableStanzaUplink != nullptr,
    "syllableStanzaUplink is null");
    
  // set syllable's stanza uplink
  fSyllableStanzaUplink =
    syllableStanzaUplink;
    
  fSyllableKind = syllableKind;
  
  fSyllableExtendKind = syllableExtendKind;
  
  // fSyllableNoteUplink will be set
  // by appendSyllableToNoteAndSetItsNoteUplink () later

  fSyllableWholeNotes = syllableWholeNotes;

  fSyllableTupletFactor = syllableTupletFactor;

#ifdef TRACE_OPTIONS
  if (gTraceOptions->fTraceLyrics) {
    gLogIOstream <<
      "Creating a syllable containing:" <<
      endl;

    gIndenter++;

    print (gLogIOstream);

    gIndenter--;
  }
#endif
}

msrSyllable::~msrSyllable ()
{}

S_msrSyllable msrSyllable::createSyllableNewbornClone (
  S_msrPart containingPart)
{
#ifdef TRACE_OPTIONS
  if (gTraceOptions->fTraceLyrics) {
    gLogIOstream <<
      "Creating a newborn clone of syllable '" <<
      asString () <<
      "'" <<
      endl;
  }
#endif

  // sanity check
  msrAssert(
    containingPart != nullptr,
    "containingPart is null");
    
  S_msrSyllable
    newbornClone =
      msrSyllable::create (
        fInputLineNumber,
        fSyllableKind,
        fSyllableExtendKind,
        fSyllableWholeNotes,
        fSyllableTupletFactor,
        fSyllableStanzaUplink);
    
  // append the lyric texts to the syllable clone
  for (
    list<string>::const_iterator i = fSyllableTextsList.begin ();
    i!=fSyllableTextsList.end ();
    i++) {
    newbornClone->
      appendLyricTextToSyllable ((*i));
  } // for

  // dont't set 'newbornClone->fSyllableStanzaUplink'
  // nor 'newbornClone->fSyllableNoteUplink',
  // this will be done by the caller

  newbornClone->fSyllableNoteUplink =
    fSyllableNoteUplink; // TEMP
  
  return newbornClone;
}

S_msrSyllable msrSyllable::createSyllableDeepCopy (
  S_msrPart containingPart)
{
#ifdef TRACE_OPTIONS
  if (gTraceOptions->fTraceLyrics) {
    gLogIOstream <<
      "Creating a newborn clone of syllable '" <<
      asString () <<
      "'" <<
      endl;
  }
#endif

  // sanity check
  msrAssert(
    containingPart != nullptr,
    "containingPart is null");
    
  S_msrSyllable
    syllableDeepCopy =
      msrSyllable::create (
        fInputLineNumber,
        fSyllableKind,
        fSyllableExtendKind,
        fSyllableWholeNotes,
        fSyllableTupletFactor,
        fSyllableStanzaUplink);
      
  // append the lyric texts to the syllable deep copy
  for (
    list<string>::const_iterator i = fSyllableTextsList.begin ();
    i!=fSyllableTextsList.end ();
    i++) {
    syllableDeepCopy->
      appendLyricTextToSyllable ((*i));
  } // for

  // dont't set 'newbornClone->fSyllableStanzaUplink'
  // nor 'newbornClone->fSyllableNoteUplink',
  // this will be done by the caller

  syllableDeepCopy->fSyllableNoteUplink =
    fSyllableNoteUplink; // TEMP
  
  return syllableDeepCopy;
}

void msrSyllable::appendLyricTextToSyllable (string text)
{
#ifdef TRACE_OPTIONS
  if (gTraceOptions->fTraceLyrics) {
    gLogIOstream <<
      "Appending text \"" <<
      text <<
      "\" to the texts list of syllable '" <<
      asString () <<
      "'" <<
      endl;
  }
#endif

  fSyllableTextsList.push_back (
    text);
}

void msrSyllable::appendSyllableToNoteAndSetItsNoteUplink (
  S_msrNote note)
{
  // sanity check
  msrAssert (
    note != nullptr,
    "note is empty");
    
  fSyllableNoteUplink = note;

/*
  // sanity check JMI ???
  msrAssert (
    fSyllableTextsList.size () != 0,
    "fSyllableTextsList is empty");
    */
    
  // append syllable to note
  note->
    appendSyllableToNote (this);

  // set it uplink to note
#ifdef TRACE_OPTIONS
  if (gTraceOptions->fTraceLyrics) {
    gLogIOstream <<
      "Setting syllable note uplink for:" <<
      endl;

    gIndenter++;
    
    gLogIOstream <<
      asString () <<
    // JMI    "to '" << note->asString () <<
      ", line " << note->getInputLineNumber () <<
      endl;

    gIndenter--;
  }
#endif
}

void msrSyllable::acceptIn (basevisitor* v)
{
  if (gMsrOptions->fTraceMsrVisitors) {
    gLogIOstream <<
      "% ==> msrSyllable::acceptIn ()" <<
      endl;
  }
      
  if (visitor<S_msrSyllable>*
    p =
      dynamic_cast<visitor<S_msrSyllable>*> (v)) {
        S_msrSyllable elem = this;
        
        if (gMsrOptions->fTraceMsrVisitors) {
          gLogIOstream <<
            "% ==> Launching msrSyllable::visitStart ()" <<
            endl;
        }
        p->visitStart (elem);
  }
}

void msrSyllable::acceptOut (basevisitor* v)
{
  if (gMsrOptions->fTraceMsrVisitors) {
    gLogIOstream <<
      "% ==> msrSyllable::acceptOut ()" <<
      endl;
  }

  if (visitor<S_msrSyllable>*
    p =
      dynamic_cast<visitor<S_msrSyllable>*> (v)) {
        S_msrSyllable elem = this;
      
        if (gMsrOptions->fTraceMsrVisitors) {
          gLogIOstream <<
            "% ==> Launching msrSyllable::visitEnd ()" <<
            endl;
        }
        p->visitEnd (elem);
  }
}

void msrSyllable::browseData (basevisitor* v)
{}

string msrSyllable::syllableWholeNotesAsMsrString () const
{
  string result;

  if (fSyllableNoteUplink) { // JMI
    switch (fSyllableNoteUplink->getNoteKind ()) {
      case msrNote::k_NoNoteKind:
      case msrNote::kRestNote:
      case msrNote::kUnpitchedNote:
      case msrNote::kStandaloneNote:
      case msrNote::kDoubleTremoloMemberNote:
      case msrNote::kGraceNote:
      case msrNote::kGraceChordMemberNote:
      case msrNote::kChordMemberNote:
        result =
          wholeNotesAsMsrString (
            fInputLineNumber,
            fSyllableWholeNotes);
        break;
        
      case msrNote::kSkipNote:
      case msrNote::kTupletMemberNote:
      case msrNote::kGraceTupletMemberNote:
      case msrNote::kTupletMemberUnpitchedNote:
        {
          stringstream s;

          s <<
            fSyllableNoteUplink->
      // JMI        noteSoundingWholeNotesAsMsrString () <<
              noteDisplayWholeNotesAsMsrString () <<
            "*" <<
            fSyllableTupletFactor.fTupletNormalNotes <<
            "/" <<
            fSyllableTupletFactor.fTupletActualNotes;

          result = s.str ();
        }
        break;
    } // switch
  }

  else {
    result =
      wholeNotesAsMsrString (
        fInputLineNumber,
          fSyllableWholeNotes);
  }
      
  return result;
}

string msrSyllable::syllableKindAsString (
  msrSyllableKind syllableKind)
{
  string result;
    
  switch (syllableKind) {
    case msrSyllable::kSyllableSingle:
      result = "syllableSingle";
      break;
      
    case msrSyllable::kSyllableBegin:
      result = "syllableBegin";
      break;
    case msrSyllable::kSyllableMiddle:
      result = "syllableMiddle";
      break;
    case msrSyllable::kSyllableEnd:
      result = "syllableEnd";
      break;
      
    case msrSyllable::kSyllableSkip:
      result = "syllableSkip";
      break;
      
    case msrSyllable::kSyllableMeasureEnd:
      result = "syllableMeasureEnd";
      break;
      
    case msrSyllable::kSyllableLineBreak:
      result = "syllableLineBreak";
      break;
    case msrSyllable::kSyllablePageBreak:
      result = "syllablePageBreak";
      break;
      
    case msrSyllable::kSyllableNone:
      result = "syllableNone";
      break;
  } // switch

  return result;
}

string msrSyllable::syllableKindAsString () const
{
  return syllableKindAsString (fSyllableKind);
}

string msrSyllable::syllableExtendKindAsString (
  msrSyllableExtendKind syllableExtendKind)
{
  string result;
  
  switch (syllableExtendKind) {
    case msrSyllable::kSyllableExtendSingle:
      result = "syllableExtendSingle";
      break;
    case msrSyllable::kSyllableExtendStart:
      result = "syllableExtendStart";
      break;
    case msrSyllable::kSyllableExtendContinue:
      result = "syllableExtendContinue";
      break;
    case msrSyllable::kSyllableExtendStop:
      result = "syllableExtendStop";
      break;
    case msrSyllable::kSyllableExtendNone:
      result = "syllableExtendNone";
      break;
  } // switch

  return result;
}

string msrSyllable::syllableExtendKindAsString () const
{
  return syllableExtendKindAsString (fSyllableExtendKind);
}

string msrSyllable::syllableNoteUplinkAsString () const
{
  string result;

  if (fSyllableNoteUplink) {
    result = fSyllableNoteUplink->asString ();
  }
  else {
    result = "none";
  }

  return result;
}

string msrSyllable::syllableTextsListAsString () const
{
  stringstream s;
  
  if (fSyllableTextsList.size ()) {
    list<string>::const_iterator
      iBegin = fSyllableTextsList.begin (),
      iEnd   = fSyllableTextsList.end (),
      i      = iBegin;
      
    for ( ; ; ) {
      s << "\"" << quoteStringIfNonAlpha (*i) << "\"";
      if (++i == iEnd) break;
      s << ", ";
    } // for
  }

  return s.str ();
} 

void msrSyllable::writeTextsList (
  const list<string>& textsList,
  ostream&            os)
{
  os << "[";

  if (textsList.size ()) {
    list<string>::const_iterator
      iBegin = textsList.begin (),
      iEnd   = textsList.end (),
      i      = iBegin;
      
    for ( ; ; ) {
      os << "\"" << quoteStringIfNonAlpha (*i) << "\"";
      if (++i == iEnd) break;
      os << ", ";
    } // for
  }

  os << "]";
} 

string msrSyllable::asString () const
{
  stringstream s;

  s <<
    "Syllable '" <<
    syllableKindAsString () <<
    "', syllableExtendKind: " <<
      syllableExtendKindAsString (fSyllableExtendKind) <<
    ", whole notes:" <<
    syllableWholeNotesAsMsrString () <<
    " (" << fSyllableWholeNotes << ")" <<
    ", syllableTupletFactor: " << fSyllableTupletFactor <<
    ", line " << fInputLineNumber <<
    ", texts list: ";
    
  writeTextsList (
    fSyllableTextsList,
    s);

  s <<
    ", " <<
    syllableNoteUplinkAsString ();

  switch (fSyllableKind) {
    case msrSyllable::kSyllableSingle:
    case msrSyllable::kSyllableBegin:
    case msrSyllable::kSyllableMiddle:
    case msrSyllable::kSyllableEnd:
    case msrSyllable::kSyllableSkip:
      break;
 
    case msrSyllable::kSyllableMeasureEnd:
      // fSyllableText contains the measure number
      s << 
        " measure ";

      writeTextsList (
        fSyllableTextsList,
        s);
      break;
      
    case msrSyllable::kSyllableLineBreak:
      // fSyllableText contains the measure number
      s << 
        " measure ";

      writeTextsList (
        fSyllableTextsList,
        s);
      break;
      
    case msrSyllable::kSyllablePageBreak:
      // fSyllableText contains the measure number JMI ???
      s << 
        " measure ";

      writeTextsList (
        fSyllableTextsList,
        s);
      break;
      
    case msrSyllable::kSyllableNone:
      msrInternalError (
        gGeneralOptions->fInputSourceName,
        fInputLineNumber,
        __FILE__, __LINE__,
        "syllable type has not been set");
      break;
  } // switch

  s <<
    ", in stanza " <<
    fSyllableStanzaUplink->getStanzaName ();

  return s.str ();
}

void msrSyllable::print (ostream& os)
{  
  os <<
    "Syllable" <<
    ", syllableKind: " <<
    syllableKindAsString () <<
    ", line " << fInputLineNumber <<
    endl;

  gIndenter++;

  const int fieldWidth = 21;
  os << left <<
    setw (fieldWidth) <<
    "syllableStanzaUplink" << " : " <<
    fSyllableStanzaUplink->getStanzaName () <<
    endl <<
    setw (fieldWidth) <<
    "syllableNoteUplink" << " : " <<
    syllableNoteUplinkAsString () <<      
    endl <<
    setw (fieldWidth) <<
    "syllableExtendKind" << " : " <<
    syllableExtendKindAsString (
      fSyllableExtendKind) <<
    endl <<
    setw (fieldWidth) <<
    "texts list" << " : ";
    
    writeTextsList (
      fSyllableTextsList,
      os);

  os << left <<
    endl <<
    setw (fieldWidth) <<
    "syllableKind" << " : " <<
    syllableKindAsString (fSyllableKind) <<
    endl;
    
  switch (fSyllableKind) { // JMI
    case msrSyllable::kSyllableSingle:
    case msrSyllable::kSyllableBegin:
    case msrSyllable::kSyllableMiddle:
    case msrSyllable::kSyllableEnd:
    case msrSyllable::kSyllableSkip:
      os << left <<
        setw (fieldWidth) <<
       "syllableWholeNotes" << " : " <<
        syllableWholeNotesAsMsrString () <<
        " (" << fSyllableWholeNotes << ")" <<
        endl <<
        setw (fieldWidth) <<
       "syllableTupletFactor" << " : " <<
        fSyllableTupletFactor;
     break;
      
    case kSyllableMeasureEnd:
    /* JMI
      // fSyllableText contains the measure number
      os << left <<
        endl <<
        setw (fieldWidth) <<
        "fSyllableTextsList [0]" << " : ";
        "measure '" << fSyllableTextsList.front () << "'";
        */
      break;
      
    case kSyllableLineBreak:
    /* JMI
      // fSyllableText contains the measure number
      os << left <<
        endl <<
        setw (fieldWidth) <<
        "measure '" << "fSyllableText ???" << "'";
        */
      break;
      
    case kSyllablePageBreak:
    /* JMI
      // fSyllableText contains the measure number JMI ???
      os << left <<
        endl <<
        setw (fieldWidth) <<
        "measure '" << "fSyllableText ???" << "'";
 */
      break;
      
    case kSyllableNone:
      msrInternalError (
        gGeneralOptions->fInputSourceName,
        fInputLineNumber,
        __FILE__, __LINE__,
        "syllable type has not been set");
      break;
  } // switch
  os <<
    endl;

  gIndenter--;
}

ostream& operator<< (ostream& os, const S_msrSyllable& elt)
{
  elt->print (os);
  return os;
}

       
}