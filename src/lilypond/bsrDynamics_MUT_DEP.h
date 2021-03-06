/*
  This file is to be included only by bsrMutualDependencies.h,
  to satisfy declarations mutual dependencies.
*/

//______________________________________________________________________________
class bsrDynamics : public bsrLineElement
{
  public:

    // creation
    // ------------------------------------------------------

    static SMARTP<bsrDynamics> create (
      int                          inputLineNumber,
      msrDynamics::msrDynamicsKind dynamicsKind);

  protected:

    // constructors/destructor
    // ------------------------------------------------------

    bsrDynamics (
      int                          inputLineNumber,
      msrDynamics::msrDynamicsKind dynamicsKind);

    virtual ~bsrDynamics ();

  public:

    // set and get
    // ------------------------------------------------------

    msrDynamics::msrDynamicsKind
                          getDynamicsKind () const
                              { return fDynamicsKind; }

  public:

    // public services
    // ------------------------------------------------------

    S_bsrCellsList        fetchCellsList () const
                              { return fDynamicsCellsList; }


    int                   fetchCellsNumber () const;

  private:

    // private services
    // ------------------------------------------------------

    S_bsrCellsList        noteValueKindAsCellsList () const;

    S_bsrCellsList        noteOctaveKindAsCellsList () const;

    S_bsrCellsList        buildCellsList () const;

  public:

    // visitors
    // ------------------------------------------------------

    virtual void          acceptIn  (basevisitor* v);
    virtual void          acceptOut (basevisitor* v);

    virtual void          browseData (basevisitor* v);

  public:

    // print
    // ------------------------------------------------------

    string                asString () const;

    virtual void          print (ostream& os) const;

  private:

    // fields
    // ------------------------------------------------------

    msrDynamics::msrDynamicsKind
                          fDynamicsKind;

    S_bsrCellsList        fDynamicsCellsList;
};
typedef SMARTP<bsrDynamics> S_bsrDynamics;
EXP ostream& operator<< (ostream& os, const S_bsrDynamics& elt);

