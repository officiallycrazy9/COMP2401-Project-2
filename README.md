#Project 2 COMP2401

## Contributors
Aidan Power - 101296886
Mason Zhou - 101297838 

## Description
This project simulates a system that manages resources and processes. 
The simulation involves different systems that consume and produce resources, with the ability to simulate processing times and manage events. 
The manager coordinates these systems and resources, handles events, and updates the simulation state.

The key components of the simulation include:
- Systems: Represents different processes that consume and produce resources.
- Resources: Represents the items needed or produced by systems.
- Event Queue: Manages events related to systems, such as resource depletion or system capacity issues.
- Manager: This is the main controlling structure that runs the simulation along with processing events, and adjusting system states.

##Instructions to Compile

To compile the program, ensure that you have a C compiler installed (e.g., `gcc`). Once you are in the correct directory, use the following command in your terminal:

```bash
gcc -o simulation main.c manager.c system.c resource.c event_queue.c -lpthread




