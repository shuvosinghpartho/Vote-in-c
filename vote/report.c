/*Project Report: Voting System
Table of Contents
Introduction
Project Overview
Objectives
System Design
4.1 Functional Requirements
4.2 Non-functional Requirements
4.3 System Architecture
4.4 Technologies Used
Implementation
5.1 Admin Module
5.2 User Module
5.3 Candidate Module
Testing
6.1 Unit Testing
6.2 Integration Testing
6.3 User Acceptance Testing
Results
Conclusion
Future Enhancements
References
1. Introduction
The Voting System project aims to create a simple yet effective platform for conducting online elections. The system provides functionalities for both administrators to manage candidates and users to cast their votes securely.

2. Project Overview
The project involves the development of a command-line based voting system using the C programming language. It consists of three main modules: admin, user, and candidate modules. Each module serves a specific purpose in the overall functioning of the system.

3. Objectives
The primary objectives of the Voting System project include:

To provide a user-friendly interface for administrators to manage candidates and monitor voting activities.
To allow users to securely log in, view candidate information, and cast their votes.
To ensure the integrity and confidentiality of the voting process.
To accurately count and display the total votes received by each candidate.
4. System Design
4.1 Functional Requirements
The functional requirements of the system include:

Authentication: Users must log in with valid credentials to access the system.
Candidate Management: Administrators can add new candidates and view the list of existing candidates.
Voting: Users can select a candidate from the list and cast their vote.
Vote Counting: The system must accurately count and display the total votes received by each candidate.
4.2 Non-functional Requirements
The non-functional requirements of the system include:

Security: The system must ensure the confidentiality and integrity of user data and voting information.
Performance: The system should be able to handle multiple concurrent users without significant delays.
Usability: The user interface should be intuitive and easy to navigate for both administrators and users.
4.3 System Architecture
The system follows a client-server architecture, where the server hosts the main voting application, and clients (administrators and users) interact with it through a command-line interface.

4.4 Technologies Used
The project utilizes the following technologies:

Programming Language: C
Version Control: Git
Integrated Development Environment (IDE): Visual Studio Code
5. Implementation
The system is implemented in the C programming language and divided into three main modules: admin, user, and candidate.

5.1 Admin Module
The admin module allows administrators to perform the following tasks:

Login with valid credentials.
Add new candidates to the system.
View the total votes received by each candidate.
5.2 User Module
The user module enables users to:

Register with the system.
Login with valid credentials.
View the list of candidates.
Cast their votes for their preferred candidates.
5.3 Candidate Module
The candidate module includes functionalities related to managing candidate information, such as:

Storing candidate names and signs.
Counting and displaying the total votes received by each candidate.
6. Testing
The testing phase ensures the correctness and reliability of the system. It includes unit testing, integration testing, and user acceptance testing (UAT).

6.1 Unit Testing
Unit tests are conducted to verify the functionality of individual modules, functions, and procedures.

6.2 Integration Testing
Integration tests validate the interactions between different modules and ensure they work together as expected.

6.3 User Acceptance Testing
User acceptance tests involve real users interacting with the system to validate its usability, functionality, and overall user experience.

7. Results
The Voting System project has been successfully implemented and tested. It meets the specified requirements and objectives, providing a reliable platform for conducting online elections.

8. Conclusion
In conclusion, the Voting System project demonstrates the feasibility of developing a simple yet effective platform for conducting online voting. The system provides essential functionalities for administrators to manage candidates and users to cast their votes securely.

9. Future Enhancements
Future enhancements to the Voting System project may include:

Implementing a graphical user interface (GUI) for better usability.
Enhancing security features, such as encryption and user authentication mechanisms.
Adding support for multiple voting rounds and candidate categories.
*/