English translation of the tasks given->
Task 9.1. Program Code
Write a program that displays the program code in C++ by removing comments that are preceded by // along with those characters. To remove comments, you can use the ignore method. Use the file kod.txt. Handle the situation when the file does not exist by catching the appropriate exception.
Hint: The peek method allows you to preview the next character. You can use it to check if two // characters appear consecutively.

Task 9.2. Oczko (Twenty-One)
Write a program in which the user will enter a positive integer until the sum of the numbers entered by the user is less than twenty-one (21). If the sum is equal to 21, then display the appropriate message and end the program. If the sum exceeds 21, throw an exception indicating that the sum has been exceeded. Handle the exception, allowing the user to re-enter the last number. The program should handle the situation when the user enters a data type other than a number. In that case, the user should be asked to enter the number again. The program should display how many attempts (successful and unsuccessful) it took to achieve twenty-one.

Task 9.3. Student Record System

Write a program to manage a student record system. The data for the task is located in the "data.csv" file, where the first line contains the headers of individual columns: first name, last name, gender, grade, and optionally email. In the following lines, there is information about each student. Each line contains information about one person. The data is separated by semicolons. The user provides the file path to load data into the program (address book) and has the following options:

1. Display the address book on the console in the form of an unbordered table with columns for first name, last name, gender, grade, and possibly email. Constant spacing (e.g., 20) should be applied between columns, and empty spaces should be filled with the underscore character (_).

2. Add another person to the address book. The first name and last name should start with a capital letter of the alphabet; only Latin alphabet letters may appear in the first name and last name. Gender is either K (female) or M (male), and the email must contain the @ symbol. Handle the situation where any of the data is incorrect.

3. Display people with a given last name on the console.

4. Create files k.csv and m.csv. The k.csv file will contain data for women, and the m.csv file will contain data for men. Remember to add headers to the files.

5. Display the first X students, where X is a number entered by the user. Handle the situation where there are fewer students than the specified number X.

6. Sort students by grade in ascending order.

7. Exit the program.

Ensure error control for potential user input errors from the console. Additionally, consider the case where the file with the given name does not exist.

Store the loaded student data from the file in a container of your choice from the STL library. Store information about an individual student as an object of a class. After the program ends, the data of all added students should be appended to the existing "data.csv" file.
