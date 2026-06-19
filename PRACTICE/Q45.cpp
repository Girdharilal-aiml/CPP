// 9. Concepts: Abstraction, Custom Error Entities, Array Traversal (via Pointers), and Text Append Operations.
// You are designing the communication software for a ground control station.

// 1. The Core Concept: You have a general concept called Satellite. Every satellite has a designation (string).
// Rule: The system must strictly prevent a programmer from creating a direct object of a generic satellite. It must only exist as a base idea.
// Rule: Every satellite must be able to checkSignal().

// 2. Specific Entities: Create RelaySatellite and SpySatellite that implement the general concept.
// Rule: If a SpySatellite calculates its signal and the value is less than 10.0, it must immediately halt normal execution flow and signal a highly specialized error entity named SignalLostError. This error entity must integrate into the standard C++ error system and provide the custom message: "Critical: Orbital connection severed."









