//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file src/PhysicsList.cc
/// \brief Implementation of the PhysicsList class
//
//
#include "PhysicsList.hh"

#include "GeneralPhysics.hh"
#include "EMPhysics.hh"
#include "MuonPhysics.hh"

#include "G4OpticalPhysics.hh"
#include "G4OpticalProcessIndex.hh"

#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::PhysicsList() : G4VModularPhysicsList()
{
	// default cut value  (1.0mm)
	defaultCutValue = 1.0*mm;

	// General Physics
	RegisterPhysics( new GeneralPhysics("general") );

	// EM Physics
	RegisterPhysics( new EMPhysics("standard EM"));

	// Muon Physics
	RegisterPhysics( new MuonPhysics("muon"));


	/* THIS PART CAN BE USED TO SIMULATE THE PHOTONS PROPAGATION INTO THE SCINTILLATOR

	// Optical Physics
	G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
	RegisterPhysics( opticalPhysics );

	opticalPhysics->SetWLSTimeProfile("delta");

	opticalPhysics->SetScintillationYieldFactor(1.0);
	opticalPhysics->SetScintillationExcitationRatio(0.0);

	opticalPhysics->SetMaxNumPhotonsPerStep(100);
	opticalPhysics->SetMaxBetaChangePerStep(10.0);

	opticalPhysics->SetTrackSecondariesFirst(kCerenkov,true);
	opticalPhysics->SetTrackSecondariesFirst(kScintillation,true); 

	 */

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::~PhysicsList() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::SetCuts(){
	//  " G4VUserPhysicsList::SetCutsWithDefault" method sets
	//   the default cut value for all particle types
	SetCutsWithDefault();
}
