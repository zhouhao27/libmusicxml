/*
  MusicXML Library
  Copyright (C) Grame 2006-2013

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

  Grame Research Laboratory, 11, cours de Verdun Gensoul 69002 Lyon - France
  research@grame.fr
*/

#include <iomanip>      // setw, setprecision, ...

#include "version.h"
#include "utilities.h"

#include "setTraceOptionsIfDesired.h"
#ifdef TRACE_OPTIONS
  #include "traceOptions.h"
#endif

#include "generalOptions.h"
#include "musicXMLOptions.h"


using namespace std;

namespace MusicXML2
{

//_______________________________________________________________________________

S_musicXMLOptions gMusicXMLOptions;
S_musicXMLOptions gMusicXMLOptionsUserChoices;
S_musicXMLOptions gMusicXMLOptionsWithDetailedTrace;

S_musicXMLOptions musicXMLOptions::create (
  S_oahHandler handler)
{
  musicXMLOptions* o = new musicXMLOptions(
    handler);
  assert(o!=0);
  return o;
}

musicXMLOptions::musicXMLOptions (
  S_oahHandler handler)
  : oahGroup (
    "MusicXML",
    "hmxml", "help-musicxml",
R"(These options control the way MusicXML data is translated.)",
    handler)
{
  // append this options group to the options handler
  // if relevant
  if (handler) {
    handler->
      appendGroupToHandler (this);
  }

  // initialize it
  initializeMusicXMLOptions (false);
}

musicXMLOptions::~musicXMLOptions ()
{}

#ifdef TRACE_OPTIONS
void musicXMLOptions::initializeMusicXMLTraceOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    traceSubGroup =
      oahSubGroup::create (
        "Trace",
        "hmxmlt", "help-musicxml-trace",
R"()",
        oahSubGroup::kSubGroupVisibilityAlways,
        this);

  appendSubGroup (traceSubGroup);

  // encoding

  fTraceEncoding = boolOptionsInitialValue;

  traceSubGroup->
    appendAtom (
      oahTwoBooleansAtom::create (
        "tenc", "trace-encoding",
R"(Encoding)",
        "traceEncoding",
        fTraceEncoding,
        gTraceOptions->fTracePasses));

  // divisions

  fTraceDivisions = boolOptionsInitialValue;

  traceSubGroup->
    appendAtom (
      oahTwoBooleansAtom::create (
        "tdivs", "trace-divisions",
R"(Divisions)",
        "traceDivisions",
        fTraceDivisions,
        gTraceOptions->fTracePasses));

  // backup

  fTraceBackup = boolOptionsInitialValue;

  traceSubGroup->
    appendAtom (
      oahTwoBooleansAtom::create (
        "tbackup", "trace-backup",
R"(Backup)",
        "traceBackup",
        fTraceBackup,
        gTraceOptions->fTracePasses));

  // MusicXML tree visiting

  fTraceMusicXMLTreeVisitors = boolOptionsInitialValue;

  traceSubGroup->
    appendAtom (
      oahBooleanAtom::create (
        "tmxmltv", "trace-musicxml-tree-visitors",
R"(Write a trace of the MusicXML tree visiting activity to standard error.)",
        "traceMusicXMLTreeVisitors",
        fTraceMusicXMLTreeVisitors));
}
#endif

void musicXMLOptions::initializeMusicXMLWorkOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    workSubGroup =
      oahSubGroup::create (
        "Work",
        "hmxmlw", "help-musicxml-work",
R"()",
        oahSubGroup::kSubGroupVisibilityAlways,
        this);

  appendSubGroup (workSubGroup);

  // file name as work title

  fUseFilenameAsWorkTitle = false;

  workSubGroup->
    appendAtom (
      oahBooleanAtom::create (
        "ufawt", "use-filename-as-work-title",
R"(Use the file name as work title if there is none in the MusicXML data.
Standard input (-) becomes 'Standard input' in that case.)",
        "useFilenameAsWorkTitle",
        fUseFilenameAsWorkTitle));
}

void musicXMLOptions::initializeMusicXMLClefsKeysTimesOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    clefsKeysTimesSubGroup =
      oahSubGroup::create (
        "Clefs, keys, times",
        "hmxmlckt", "help-musicxml-clefs-keys-times",
R"()",
        oahSubGroup::kSubGroupVisibilityAlways,
        this);

  appendSubGroup (clefsKeysTimesSubGroup);

  // redundant clefs

  fIgnoreRedundantClefs = boolOptionsInitialValue;

  fIgnoreRedundantClefsAtom =
      oahBooleanAtom::create (
        "irc", "ignore-redundant-clefs",
R"(Ignore clefs that are the same as the current one.)",
        "ignoreRedundantClefs",
        fIgnoreRedundantClefs);
  clefsKeysTimesSubGroup->
    appendAtom (
      fIgnoreRedundantClefsAtom);

  // redundant keys

  fIgnoreRedundantKeys  = boolOptionsInitialValue;

  fIgnoreRedundantKeysAtom =
      oahBooleanAtom::create (
        "irk", "ignore-redundant-keys",
R"(Ignore keys that are the same as the current one.)",
        "ignoreRedundantKeys",
        fIgnoreRedundantKeys);
  clefsKeysTimesSubGroup->
    appendAtom (
      fIgnoreRedundantKeysAtom);

  // redundant times

  fIgnoreRedundantTimes = boolOptionsInitialValue;

  fIgnoreRedundantTimesAtom =
      oahBooleanAtom::create (
        "irt", "ignore-redundant-times",
R"(Ignore times that are the same as the current one.)",
        "ignoreRedundantTimes",
        fIgnoreRedundantTimes);
  clefsKeysTimesSubGroup->
    appendAtom (
      fIgnoreRedundantTimesAtom);

  // '-loop' is hidden...

  fLoopToMusicXML = boolOptionsInitialValue;

  S_oahBooleanAtom
    loopOptionsBooleanAtom =
      oahBooleanAtom::create (
        "loop", "loop-to-musicxml",
R"(Close the loop, generating a MusicXML file from the MSR.
The file name receives a '_loop' suffix. Currently under development.)",
        "loopToMusicXML",
        fLoopToMusicXML);
  loopOptionsBooleanAtom->
    setIsHidden ();

  clefsKeysTimesSubGroup->
    appendAtom (
      loopOptionsBooleanAtom);
}

void musicXMLOptions::initializeMusicXMLCombinedOptionsOptions (
  bool boolOptionsInitialValue)
{
  S_oahSubGroup
    combinedSubGroup =
      oahSubGroup::create (
        "Combined options",
        "hmxmlco", "help-musicxml-combined-options",
R"()",
        oahSubGroup::kSubGroupVisibilityAlways,
        this);

  appendSubGroup (combinedSubGroup);

  // cubase

  fCubase = false;

  // create the 'cubase' combined atom
  S_oahCombinedBooleansAtom
    cubaseCombinedBooleansAtom =
      oahCombinedBooleansAtom::create (
        "cubase", "",
R"(Useful settings for MusicXML data exported from Cubase.
This option is set by default, and can be unset by 'noCubase'.)",
        "cubase",
        fCubase);

  combinedSubGroup->
    appendAtom (
      cubaseCombinedBooleansAtom);

  // set the '-cubase' option by default
  cubaseCombinedBooleansAtom->
    setCombinedBooleanVariables (fCubase);

  // populate the combined atoms
  cubaseCombinedBooleansAtom->
    addBooleanAtom (
      fIgnoreRedundantClefsAtom);
  cubaseCombinedBooleansAtom->
    addBooleanAtom (
      fIgnoreRedundantKeysAtom);
  cubaseCombinedBooleansAtom->
    addBooleanAtom (
      fIgnoreRedundantTimesAtom);

  // noCubase

  fNoCubase = false;

  S_oahBooleanAtom
    noCubaseBooleanAtom =
      oahBooleanAtom::create (
        "noCubase", "",
R"(Prevents the default 'cubase' option.)",
        "noCubase",
        fNoCubase);

  combinedSubGroup->
    appendAtom (
      noCubaseBooleanAtom);
 }

void musicXMLOptions::initializeMusicXMLOptions (
  bool boolOptionsInitialValue)
{
#ifdef TRACE_OPTIONS
  // trace
  // --------------------------------------
  initializeMusicXMLTraceOptions (
    boolOptionsInitialValue);
#endif

  // worktitle
  initializeMusicXMLWorkOptions (
    boolOptionsInitialValue);

  // clefs, keys, times
  // --------------------------------------
  initializeMusicXMLClefsKeysTimesOptions (
    boolOptionsInitialValue);

  // combined options
  // --------------------------------------
  initializeMusicXMLCombinedOptionsOptions (
    boolOptionsInitialValue);
}

S_musicXMLOptions musicXMLOptions::createCloneWithDetailedTrace ()
{
  S_musicXMLOptions
    clone =
      musicXMLOptions::create (0);
      // 0 not to have it inserted twice in the option handler

  // set the options handler upLink
  clone->fHandlerUpLink =
    fHandlerUpLink;


  // clefs, keys, times
  // --------------------------------------

  clone->fIgnoreRedundantClefs =
    fIgnoreRedundantClefs;

  clone->fIgnoreRedundantKeys =
    fIgnoreRedundantKeys;

  clone->fIgnoreRedundantTimes =
    fIgnoreRedundantTimes;

  clone->fLoopToMusicXML =
    fLoopToMusicXML;


  // trace
  // --------------------------------------

#ifdef TRACE_OPTIONS
  clone->fTraceEncoding =
    fTraceEncoding;

  clone->fTraceDivisions =
    fTraceDivisions;

  clone->fTraceBackup =
    fTraceBackup;
#endif

  clone->fTraceMusicXMLTreeVisitors =
    fTraceMusicXMLTreeVisitors;

  return clone;
}

//______________________________________________________________________________
void musicXMLOptions::setAllMusicXMLTraceOptions (
  bool boolOptionsInitialValue)
{
#ifdef TRACE_OPTIONS
  // specific trace

    // encoding
    fTraceEncoding = boolOptionsInitialValue;

    // divisions
    fTraceDivisions = boolOptionsInitialValue;

    // backup
    fTraceBackup = boolOptionsInitialValue;
#endif
}

//______________________________________________________________________________
void musicXMLOptions::enforceQuietness ()
{
  fTraceMusicXMLTreeVisitors = false;
}

//______________________________________________________________________________
void musicXMLOptions::checkOptionsConsistency ()
{
  // JMI
}

//______________________________________________________________________________
void musicXMLOptions::printMusicXMLOptionsValues (int fieldWidth)
{
  gLogIOstream <<
    "The MusicXML options are:" <<
    endl;

  gIndenter++;

  // clefs, keys, times
  // --------------------------------------

  gLogIOstream <<
    "Clefs, keys, times:" <<
    endl;

  gIndenter++;

  gLogIOstream << left <<
    setw (fieldWidth) << "ignoreRedundantClefs" << " : " <<
    booleanAsString (fIgnoreRedundantClefs) <<
    endl <<

    setw (fieldWidth) << "ignoreRedundantKeys" << " : " <<
    booleanAsString (fIgnoreRedundantKeys) <<
    endl <<

    setw (fieldWidth) << "ignoreRedundantTimes" << " : " <<
    booleanAsString (fIgnoreRedundantTimes) <<
    endl <<

    setw (fieldWidth) << "loopToMusicXML" << " : " <<
    booleanAsString (fLoopToMusicXML) <<
    endl;

  gIndenter--;

  // trace
  // --------------------------------------

  gLogIOstream <<
    "Trace:" <<
    endl;

  gIndenter++;

  gLogIOstream << left <<
#ifdef TRACE_OPTIONS
    setw (fieldWidth) << "traceEncoding" << " : " <<
    booleanAsString (fTraceEncoding) <<
    endl <<

    setw (fieldWidth) << "traceDivisions" << " : " <<
    booleanAsString (fTraceDivisions) <<
    endl <<

    setw (fieldWidth) << "traceBackup" << " : " <<
    booleanAsString (fTraceBackup) <<
    endl <<
#endif

    setw (fieldWidth) << "traceMusicXMLTreeVisitors" << " : " <<
    booleanAsString (fTraceMusicXMLTreeVisitors) <<
    endl;

  gIndenter--;

  gIndenter--;
}

S_oahValuedAtom musicXMLOptions::handleAtom (
  ostream&  os,
  S_oahAtom atom)
{
  S_oahValuedAtom result;

  // JMI ???

  return result;
}

ostream& operator<< (ostream& os, const S_musicXMLOptions& elt)
{
  elt->print (os);
  return os;
}

//______________________________________________________________________________
void initializeMusicXMLOptionsHandling (
  S_oahHandler handler)
{
#ifdef TRACE_OPTIONS
  if (gOahBasicOptions->fTraceOptions && ! gGeneralOptions->fQuiet) {
    gLogIOstream <<
      "Initializing MusicXML options handling" <<
      endl;
  }
#endif

  // create the MusicXML options
  // ------------------------------------------------------

  gMusicXMLOptionsUserChoices = musicXMLOptions::create (
    handler);
  assert(gMusicXMLOptionsUserChoices != 0);

  gMusicXMLOptions =
    gMusicXMLOptionsUserChoices;

  // prepare for measure detailed trace
  // ------------------------------------------------------

  gMusicXMLOptionsWithDetailedTrace =
    gMusicXMLOptions->
      createCloneWithDetailedTrace ();
}


}
