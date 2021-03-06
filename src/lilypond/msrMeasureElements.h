/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#ifndef ___msrMeasureElements___
#define ___msrMeasureElements___

#include "msrElements.h"


namespace MusicXML2
{

//______________________________________________________________________________
class msrMeasureElement : public msrElement
{
  public:

    // constants
    // ------------------------------------------------------

    #define K_NO_MEASURE_NUMBER          "*unknown*"

    #define K_NO_POSITION_MEASURE_NUMBER rational (-222222, 1)

    #define K_NO_WHOLE_NOTES             rational (-444444, 1)

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    msrMeasureElement (
      int inputLineNumber);

    virtual ~msrMeasureElement ();

  public:

    // set and get
    // ------------------------------------------------------

    void                  setMeasureElementMeasureNumber (
                            string positionInMeasure)
                              {
                                fMeasureElementMeasureNumber =
                                  positionInMeasure;
                              }

    string                getMeasureElementMeasureNumber ()
                              { return fMeasureElementMeasureNumber; }

    void                  setMeasureElementPositionInMeasure (
                            rational positionInMeasure,
                            string   context);

    rational              getMeasureElementPositionInMeasure ()
                              { return fMeasureElementPositionInMeasure; }

    void                  setMeasureElementSoundingWholeNotes (
                            rational wholeNotes,
                            string   context);

    rational              getMeasureElementSoundingWholeNotes () const
                              { return fMeasureElementSoundingWholeNotes; }

  public:

    // services
    // ------------------------------------------------------

    static bool           compareMeasureElementsByIncreasingPositionInMeasure (
                            const SMARTP<msrMeasureElement>& first,
                            const SMARTP<msrMeasureElement>& second);

  public:

    // visitors
    // ------------------------------------------------------

    virtual void          acceptIn  (basevisitor* v);
    virtual void          acceptOut (basevisitor* v);

    virtual void          browseData (basevisitor* v) = 0;

  public:

    // print
    // ------------------------------------------------------

    virtual std::string   asShortString () const;
    virtual std::string   asString () const;

    virtual void          print (ostream& os) const;

    virtual void          printSummary (ostream& os) {}

  protected:

    // fields
    // ------------------------------------------------------

    string                fMeasureElementMeasureNumber;
    rational              fMeasureElementPositionInMeasure;
    rational              fMeasureElementSoundingWholeNotes;
};
typedef SMARTP<msrMeasureElement> S_msrMeasureElement;
EXP ostream& operator<< (ostream& os, const S_msrMeasureElement& elt);


} // namespace MusicXML2


#endif
