🏥 Hospital Patient Queue System (C++)
A console-based hospital management system built using C++ STL to manage patients based on severity.

📌 Overview
This system:
Stores patient details
Separates critical and normal patients
Serves patients based on priority
Allows searching by ID
Displays waiting list

🧠 Data Structures Used
unordered_map → Fast patient lookup (O(1))
queue → Normal patients (FIFO)
priority_queue → Critical patients (Higher severity first)

⚙️ Severity Rule
Severity 7–10 → Critical
Severity 1–6 → Normal
Critical patients are always served first.

🚀 Features
Add Patient
Serve Next Patient
Search Patient
Display Waiting List

