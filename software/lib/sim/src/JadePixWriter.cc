//---------------------------------------------------------------------------//
//      BOOST --- BESIII Object_Oriented Simulation Tool                     //
//---------------------------------------------------------------------------//
//Description: Handle database I/O and user interface 
//             for MDC geometry parameters
//Author: Yuan Ye(yuany@mail.ihep.ac.cn)
//Created: 4 Dec, 2003
//Modified:
//Comment: Used in "JadePix" now, should be insert in framwork later
//         The units are "mm" and "rad". 
//         Datum plane is the East Endplane of MDC.
//---------------------------------------------------------------------------//
#include "JadePixWriter.hh"

JadePixWriter::JadePixWriter():m_fout(NULL){
    if(m_JadePixWriter){G4cout<<"Wariing::JadePixWriter is constructed twice." << G4endl;}
    m_JadePixWriter=this;
}

JadePixWriter::~JadePixWriter(){
    if(m_fout) delete m_fout;
}

JadePixWriter* JadePixWriter::m_JadePixWriter=NULL;

JadePixWriter* JadePixWriter::Instance(){
    if(!m_JadePixWriter) m_JadePixWriter = new JadePixWriter();
    return m_JadePixWriter;
}

int JadePixWriter::OpenFile(string fileout){
    m_fout = new ofstream(fileout.c_str(),ios::out);
    if(m_fout == NULL){
        std::cerr << "Failed to open out file: "<< fileout << std::endl;
        return 0;
    }
    m_fout->precision(9);
    m_fout->setf(ios::left);
    (*m_fout)<<"TrkId \t ChId \t Edep \t\t time \t\t posX \t\t posY \t\t posZ \t enterAngle"<<endl;
    (*m_fout)<<"TrkId \t ChId \t RowId \t ColId \t ADC \t TDC"<<endl;
    (*m_fout)<<"***********************************************************************"<<endl;
    return 1;
}

void JadePixWriter::WriteEventTag(int id){
  (*m_fout)<<""<<endl;  
  (*m_fout)<<"EventId: "<<id<<endl;    
}

void JadePixWriter::WriteMcTag(int n){
    (*m_fout)<<"McTruth Hit No: "<<n<<endl;    
}

void JadePixWriter::WriteMc(JadePixHit* truthHit, G4double totalEdep){
  G4ThreeVector trPos = truthHit->GetPos();
  (*m_fout)<<truthHit->GetTrackID()<<"\t"<<truthHit->GetGlobalChipID()<<"\t"<<totalEdep<<"\t"<<truthHit->GetGlobalT()<<"\t"<<trPos.x()<<"\t"<<trPos.y()<<"\t"<<trPos.z()<<"\t"<<truthHit->GetEnterAngle()<<endl;
}

void JadePixWriter::WriteDigiTag(int n){
  (*m_fout)<<"Digi Hit No: "<<n<<endl;    
}

void JadePixWriter::WriteDigi(JadePixDigi* digiHit){
  (*m_fout)<<digiHit->GetTrackID()<<"\t"<<digiHit->GetGlobalChipID()<<"\t"<<digiHit->GetRow()<<"\t"<<digiHit->GetCol()<<"\t"<<digiHit->GetADC()<<"\t"<<digiHit->GetTDC()<<endl;
}


