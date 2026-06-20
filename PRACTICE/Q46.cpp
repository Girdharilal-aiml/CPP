// 10. Concepts: The Diamond Problem, Generic Utility Functions, and Raw Memory (Binary) Storage.
// You are building the patient intake software for a busy metropolitan hospital.

// 1. The Patient Hierarchy: A base Patient entity has a medicalID (integer) set when they enter the hospital.
// Rule: An Inpatient is a Patient. An ERPatient is a Patient.
// Rule: An IntensiveCarePatient acts as both an Inpatient and an ERPatient simultaneously, combining all their traits.
// Crucial Rule: Even though an Intensive Care patient merges two roles, they are still a single human being. Your architecture must guarantee that an IntensiveCarePatient has exactly one physical medicalID in memory. Demonstrate how their constructor bypasses the intermediate roles to set this ID directly.




