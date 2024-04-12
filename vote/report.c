/*Title: Implementation of a Voting System in C

Objective:
The objective of this lab is to implement a simple voting system in C programming language. 
The system allows an admin to add candidates, users to vote for candidates, 
and provides functionalities to count and display total votes as well as sort candidates based on the number of votes they receive.

Key Features: 
Admin Functionality:

Admin Login: The system allows the admin to log in securely, granting access to administrative functionalities.
Add Candidates: Admins can add candidates to the system, providing their names and signs.
Count Total Votes: The system enables admins to count the total number of votes cast for all candidates.
Sort Candidates: Admins can sort the list of candidates based on the number of votes they have received, facilitating result presentation.
User Functionality:

User Login: Users can log in to the system to cast their votes securely.
Vote for Candidates: Users have the ability to vote for their preferred candidates from the list provided by the system.
View Total Votes: Users can view the total number of votes they have cast, providing transparency and accountability.
Voting Process:

Simple and Intuitive Interface: The system provides a user-friendly interface for both admins and users, making the voting process straightforward.
Secure Voting: Users can cast their votes securely, ensuring the integrity of the election process.
Real-time Updates: The system updates vote counts in real-time, providing immediate feedback to users and admins.
Data Management:

Data Integrity: The system maintains data integrity by accurately recording votes and candidate information.
Efficient Storage: Candidate and user data are stored efficiently, allowing for scalability and performance.
Result Presentation:

Sorted Candidate List: The system sorts candidates based on the number of votes they have received, facilitating result presentation and analysis.
Total Vote Count: Users and admins can easily access the total number of votes cast, providing insights into voter turnout and candidate popularity.




Introduction:
Voting systems are crucial for democratic processes, allowing individuals to express their preferences and elect representatives. 
In this lab, we implemented a basic voting system using C programming language. 
The system consists of two main entities: admin and user. 
The admin is responsible for adding candidates, while users can log in to vote for their preferred candidates. 
Additionally, the system provides functionalities to count total votes, view total votes given by each user, and sort candidates based on votes received.




Materials and Methods:
The implementation of the voting system involves several steps and functionalities. Below are the key components and their functionalities:



Admin Login:

The adminLogin function allows the admin to log in to the system.
Upon successful login, the admin can add candidates, count total votes, and sort candidates based on votes.
User Login:

The userLogin function enables users to log in to the system.
Users can vote for their preferred candidates after logging in.
Adding Candidates:

The addCandidate function allows the admin to add candidates to the system.
The admin can input the candidate's name and sign, and the candidate is added to the list of candidates.
Voting:

The voteCandidate function enables users to vote for their preferred candidates.
Users can select a candidate from the list and cast their vote.
The system records the vote and updates the candidate's vote count.
Viewing Total Votes:

The viewTotalVotes function allows users to view the total votes they have given.
It displays the username of the user and the total number of votes they have cast.
Counting Total Votes:

The countTotalVotes function calculates the total number of votes cast for all candidates.
It iterates through the list of candidates and sums up their vote counts.
Sorting Candidates:

The sortCandidates function sorts the candidates based on the number of votes they have received.
It uses the bubble sort algorithm to rearrange the candidates in descending order of votes.
Results and Discussion:
The implemented voting system provides a basic yet functional platform for conducting elections. 
Users can log in to the system, vote for their preferred candidates, and view the total votes they have cast. 
The admin has the authority to add candidates, count total votes, and sort candidates based on votes received. 
Overall, the system facilitates democratic processes by allowing individuals to participate in elections and elect representatives.

Conclusion:
In conclusion, the implementation of the voting system in C programming language demonstrates the application of fundamental programming concepts such as data structures, control flow, and user input/output. 
The system provides essential functionalities for conducting elections and serves as a foundation for more complex voting systems with additional features and security measures.

Future work: 
Strengthen authentication with multi-factor authentication and encryption for data security.
Improve user interface for better accessibility and real-time feedback during voting.
Enhance system scalability and performance through optimization and cloud solutions.
Ensure data integrity and auditability with robust validation, logging, and blockchain technology.
Develop advanced analytics and reporting tools for insights into voting patterns and compliance with regulations.*/