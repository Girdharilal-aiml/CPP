// 10. Concepts: The Diamond Problem, Generic Utility Functions, and Raw Memory (Binary) Storage.
// You are building the patient intake software for a busy metropolitan hospital.

// 1. The Patient Hierarchy: A base Patient entity has a medicalID (integer) set when they enter the hospital.
// Rule: An Inpatient is a Patient. An ERPatient is a Patient.
// Rule: An IntensiveCarePatient acts as both an Inpatient and an ERPatient simultaneously, combining all their traits.
// Crucial Rule: Even though an Intensive Care patient merges two roles, they are still a single human being. Your architecture must guarantee that an IntensiveCarePatient has exactly one physical medicalID in memory. Demonstrate how their constructor bypasses the intermediate roles to set this ID directly.

// 2. The Triage Utility:
// Rule: Write a generic medical utility tool called prioritize. It must accept any two entities, provided they are of the exact same data type.
// Rule: Inside this utility, call a method .getSeverityScore() on both entities. Return the entity that has the higher score.

// 3. The Archiving System:
// Rule: The hospital tracks basic data using a simple entity called VitalRecord (containing int patientID and double heartRate). Create an array of exactly 50 VitalRecord objects.
// Rule: Save the entire array to a file named archive.dat exactly as it appears in RAM-as a single, raw block of memory bytes in one direct operation. Do not format it using standard text insertion operators.

#include"iostream"
#include"fstream"
using namespace std;

class Patient{
protected:    
    int medicalID;
public:   
    Patient(int id) : medicalID(id){}
};        

class Inpatient : virtual public Patient{
public:   
    Inpatient(int id) : Patient(id){}
};

class ERPatient : virtual public Patient{
public:   
    ERPatient(int id) : Patient(id){}
};

class IntensiveCarePatient : public Inpatient, public ERPatient{
    int severityScore;
public:   
    IntensiveCarePatient(int id, int score) : Inpatient(id), ERPatient(id), Patient(id), severityScore(score){}

    int getMedicalID(){
        return medicalID;
    }

    int getSeverityScore(){
        return severityScore;
    }
};

template<typename T>
T prioritize(T a, T b){
    if(a.getSeverityScore() > b.getSeverityScore()){
        return a;
    }else{
        return b;
    }
}

struct VitalRecord{
    int patientID;
    double heartRate;
};

int main(){
    IntensiveCarePatient ICP(12345, 85);
    IntensiveCarePatient ICP2(54321, 90);

    IntensiveCarePatient prioritizedPatient = prioritize(ICP, ICP2);

    cout << "Prioritized Patient ID: " << prioritizedPatient.getMedicalID() << " with Severity Score: " << prioritizedPatient.getSeverityScore() << endl;

    VitalRecord records[50];
    for(int i=0; i<50; i++){
        records[i].patientID = 1000 + i;
        records[i].heartRate = 60.0 + i;
    }

    ofstream outFile("archive.dat", ios::binary);
    if(outFile.is_open()){
    }
}
