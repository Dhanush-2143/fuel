✅ ABSTRACT (Fuel Management System – Converted Version)
The Fuel Management System is a lightweight, terminal-based application developed entirely in C for managing fuel usage and refilling records efficiently. It allows users to add new fuel entries, view all stored records, search by vehicle or date, and delete records when required. All data is stored persistently in a binary fuel.dat file, ensuring complete data retention across multiple program sessions.
This project showcases essential C programming concepts such as structures, file handling, binary storage, and a menu-driven user interface — making it ideal for academic projects and small-scale fuel monitoring applications like transport services, logistics, schools, or company vehicle management.

✅ FEATURES (Converted)
Add new fuel records:


Vehicle Name / Number


Fuel Quantity (Litres)


Fuel Type (Petrol/Diesel)


Date


Purpose


Driver Name / Contact


View all existing fuel records


Search fuel records by:


Vehicle Name


Date of Fuel Entry


Delete fuel records using Record ID


Automatically generates unique IDs


Persistent data storage using fuel.dat


Fully terminal-based interface


Simple, clean, and readable C code design


Automatically creates data file if missing


Basic input validation and error handling



✅ TECHNICAL REQUIREMENTS (Converted)
1. System Requirements
Operating System: Windows / Linux / macOS


Terminal or Command Line


Minimum 4 MB RAM


Minimal disk space (few KB for .dat file)


2. Software Requirements
C Compiler: GCC / Clang / MSVC / MinGW


Any C IDE or text editor (VS Code, Code::Blocks, Dev-C++, etc.)


Optional: make for automated compilation


3. Programming Requirements
Programming Language: C


Supported Standards: C89 / C99 / C11


Required Header Files:


<stdio.h>


<stdlib.h>


<string.h>


<ctype.h>


4. File Handling Requirements
Read/Write access to program directory


Binary file: fuel.dat


Uses fread() and fwrite()


Auto-created if not found


5. Compilation Requirements
Compile using GCC:
gcc fuel_management.c -o fuel_management


✅ FUNCTIONAL REQUIREMENTS (Converted)
1. User Interface
Menu-driven fuel management system


Uses fgets() for safe string input


Runs continuously until the user chooses Exit


2. Fuel Record Operations
Add Fuel Record
Stores:
Unique ID


Vehicle name/number


Fuel quantity


Fuel type


Date


Purpose


Driver name/contact


View Fuel Records
Displays all stored fuel entries in tabular form.
Search Fuel Record
By Vehicle Name (case-insensitive)


By Date


Delete Fuel Record
Remove a fuel entry by ID


Uses temporary file rewrite method


3. Data Management
Persistent fuel data stored in fuel.dat


Reads and writes in binary format


Uses structures for clean organization


4. Program Flow
Clear, easy-to-understand menu


Uses switch-case for user operations


Displays success/failure messages



✅ PROJECT FILE STRUCTURE (Converted)
fuel-management-system/
│
├── fuel_management.c      # Source code
├── fuel.dat               # Auto-created on first run
└── README.md              # Documentation


✅ HOW TO COMPILE AND RUN
Step 1: Compile
gcc fuel_management.c -o fuel_management

Step 2: Run
For Windows:
fuel_management.exe

For Linux / macOS:
./fuel_management

Step 3: Data File
The program automatically creates fuel.dat


All records are saved permanently in this file



✅ SCREENSHOTS (Converted Titles)
Main Menu
 

<img width="309" height="207" alt="Screenshot 2025-12-10 120742" src="https://github.com/user-attachments/assets/281dc5f0-a2a2-4564-b8c9-4a647a014d83" />


Add New Fuel Record


<img width="405" height="263" alt="Screenshot 2025-12-10 120819" src="https://github.com/user-attachments/assets/4fa6ff0a-efb6-4c92-ad01-418739d0f1b3" />



View All Fuel Records


<img width="888" height="154" alt="Screenshot 2025-12-10 120806" src="https://github.com/user-attachments/assets/b20e81eb-d566-416d-93fb-d608727c8dfe" />


Search Fuel Record


<img width="320" height="308" alt="Screenshot 2025-12-10 120832" src="https://github.com/user-attachments/assets/22e6a3f4-2b78-4c24-939c-3d513d2f394a" />



Update Fuel Record
 

<img width="308" height="175" alt="Screenshot 2025-12-10 120845" src="https://github.com/user-attachments/assets/985d5b22-4268-4eec-a228-85d6ce28428a" />



Delete Fuel Record

<img width="738" height="150" alt="Screenshot 2025-12-10 120618" src="https://github.com/user-attachments/assets/dabfc09d-0fd6-413d-94dc-0256b1901e9d" />



Exit

<img width="301" height="47" alt="Screenshot 2025-12-10 120623" src="https://github.com/user-attachments/assets/876e9d01-8563-4597-b4ae-d0c17b389aad" />


 
