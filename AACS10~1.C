#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable:4996)// Disables a specific compiler warning (likely related to a deprecated function)
// Define some constants for grade points
#define A_PLUS 4.00
#define A_MINUS 3.75
#define B_PLUS 3.50
#define B_NORMAL 3.00
#define B_MINUS 2.75
#define C_PLUS 2.50
#define C_NORMAL 2.00
#define F_NORMAL 0.00
#define Max_words 100



// Function to choose user type (staff or student)
int student() {
    int choice;
    printf("=======================================================\n");
    printf("(>_<) Welcome to Kolej Pasar GPA/CGPA Calculator! (>_<)\n");
    printf("=======================================================\n");
    printf("Select User Type:\n");
    printf("1.Kolej Pasar Staff Administrator\n");
    printf("2.Kolej Pasar Student\n");
    printf("3.Exit\n");
    printf("\n=======================================================\n");
    printf("Enter your choice(eg:1, 2 or 3) : ");
    scanf("%d", &choice);


    return choice;

}
int menu() {
    int choice1;


    printf("=======================================================\n");
    printf("(^o^)           Welcome to staff Mode             (^o^)\n");
    printf("=======================================================\n");
    printf("1.Log In : \n");
    printf("2.Sign Up : \n");
    printf("3.Return To Menu:\n");
    printf("you should sign up an account before log in\n\n");
    printf("Please Enter your Choice:");
    scanf("%d", &choice1);
    rewind(stdin);
    system("cls");// Clear the console screen
    return choice1;
}



struct student
{
    int creditHours, creditHours1;
    double gradePoint, gradePoint1, gpaScore, totalcgpaScore, allcredithours, totalgpaScore, totalcreditHours, totalgradePoint, totalgradePoint1, calgpaScore, totalScore, totalScore1;
    char grade[100], studentName[50], studentID[50], grade1[100], courseCode[50], courseCode1[50], courseName[50], courseName1[50];


};
// Main function
void main() {

    // Declare various variables for student data and choices
    int  semester = 3, creditHours, creditHours1, i, numofstudent;
    char  courseCode[50], grade[100], grade1[100], courseName[51], courseName1[51], studentID[50], studentName[51];
    double gradePoint, gradePoint1, gpaScore = 0.0, totalcgpaScore = 0.0, allcredithours = 0.0;
    double  totalgpaScore = 0.0, totalgradePoint = 0.0, totalgradePoint1 = 0.0, totalcreditHours = 0.0, calgpaScore = 0.0
        , totalScore = 0.0, totalScore1 = 0.0;
    // Declare an array of student structs
    struct student cal_Score[6];

    int choice;

    // Choose user type (staff or student)
    do {
        printf("\n\n");
        choice = student();
        rewind(stdin);
        system("cls");// Clear the console screen
        if (choice == 1) {// Code for staff mode

            FILE* studentData;
            char filename[10000], staffName[50], password[20], staffPassword[30], staffConfirm[50], name[50];
            studentData = fopen("TEST60.txt", "w");
            int choice1 = 0;


            do {

                choice1 = menu();


                // Code for staff login
                if (choice1 == 1) {
                    printf("\n=======================================================\n");
                    printf("(^o^)           WELCOME TO LOG IN PAGE            (^o^)\n");
                    printf("=======================================================\n");
                    printf("Please Enter Your Name  : ");
                    scanf(" %[^\n]", &name);


                    while (strcmp(name, staffName) != 0) {
                        system("cls");
                        printf("\n=======================================================\n");
                        printf("(^o^)           WELCOME TO LOG IN PAGE            (^o^)\n");
                        printf("=======================================================\n");
                        printf("Name Invalid\n");
                        printf("Please Enter Your Name : ");
                        scanf(" %[^\n]", &name);



                    }





                    printf("Please Enter Your Password : ");
                    scanf(" %[^\n]", &password);
                    while (strcmp(password, staffPassword) != 0) {
                        system("cls");
                        printf("\n=======================================================\n");
                        printf("(^o^)           WELCOME TO LOG IN PAGE            (^o^)\n");
                        printf("=======================================================\n");
                        printf("Please Enter Your Name  :%s \n", name);
                        printf("Password Invalid\n");
                        printf("Please Enter Your Password : ");
                        scanf(" %[^\n]", &password);



                    }
                }






                // Code for staff sign-up
                if (choice1 == 2) {
                    printf("\n=======================================================\n");
                    printf("(^o^)          WELCOME TO SIGN UP PAGE            (^o^)\n");
                    printf("=======================================================\n");
                    printf("Please Enter Your Name : ");
                    scanf(" %[^\n]s", &staffName);
                    printf("Please Enter Your Password : ");
                    scanf(" %[^\n]s", &staffPassword);

                    printf("\n\nPlease Confirm Your Password : ");
                    scanf(" %[^\n]s", &staffConfirm);

                    while (strcmp(staffConfirm, staffPassword) != 0) {
                        system("cls");
                        printf("\n=======================================================\n");
                        printf("(^o^)          WELCOME TO SIGN UP PAGE            (^o^)\n");
                        printf("=======================================================\n");
                        printf("Please Enter Your Name : %s\n", staffName);
                        printf("Please Enter Your Password :%s \n", staffPassword);
                        printf("\n\nPlease Confirm Your Password : ");
                        scanf(" %[^\n]s", &staffConfirm);

                        system("cls");

                    }

                }
                system("cls");
                if (choice1 == 3) {

                    choice = student();
                    system("cls");
                    rewind(stdin);



                    // Code for student mode
                    if (choice == 2) {
                        while (choice != 1) {

                            char studentID1[50];
                            printf("=======================================================");
                            printf("(^o^)           WWLCOME TO STUDENT MODE           (^o^)\n");
                            printf("=======================================================\n\n");
                            printf("Please Enter The Student Details:\n");
                            printf("Enter Your Student ID: ");
                            scanf("%s", studentID1);

                            char filename[10000];
                            sprintf(filename, "%s.txt", studentID1);

                            FILE* studentData2 = fopen(filename, "r");
                            if (studentData2 == NULL) {
                                printf("Student Data Not Found.\n");

                            }

                            else {
                                char ch[10000];
                                while (fgets(ch, 10000, studentData2)) {
                                    printf("%s", ch);
                                }


                                fclose(studentData2);

                            }


                            choice = student();
                            system("cls");
                        }
                        /////
                    }
                    else if (choice == 3) {
                        return 0;
                    }

                    ////
                    //

                //choice1!=4

                }//choice1==3
            } while (choice1 != 1);

            //
            system("cls");

            do {
                printf("=======================================================\n");
                printf("(^o^)             NUMBER OF STUDENT              (^o^)\n");
                printf("=======================================================\n");
                printf("Please Type How Many Student You Want To Count:\n>");
                scanf("%d", &numofstudent);
                rewind(stdin);
                if (numofstudent <= 0) {
                    printf("\nPlease Enter Again Number Of Student\n");
                }
            } while (numofstudent <= 0);



            system("cls");
            for (int j = 1;j <= numofstudent;j++) {



                printf("=======================================================\n");
                printf("(^o^)           WELCOME TO STUDENT MODE             (^o^)\n");
                printf("=======================================================\n");
                printf("Please Enter The Student Details:\n");
                printf("Please Enter Student ID \t:");
                scanf(" %[^\n]s", &studentID);
                printf("Please Enter Student Name\t:");
                scanf(" %[^\n]s", &studentName);

                sprintf(filename, "%s.txt", studentID);
                studentData = fopen(filename, "w");







                system("cls");
                for (int i = 1;i <= semester; i++)
                {


                    printf("=======================================================\n");
                    printf("                       SEMESTER %d                    \n", i);
                    printf("=======================================================\n");
                    printf("Enter Course Details for Semester %d \t:", i);
                    printf("\nPlease Enter Course Name 1\t:");
                    rewind(stdin);
                    scanf(" %[^\n]s", &cal_Score[i].courseName);
                    for (int o = 0;o <= Max_words;o++) {
                        cal_Score[i].courseName[o] = toupper(cal_Score[i].courseName[o]);
                    }


                    printf("Please Enter Course Code 1\t:");
                    rewind(stdin);
                    scanf(" %[^\n]s", &cal_Score[i].courseCode);
                    for (int o = 0;o <= Max_words;o++) {

                        cal_Score[i].courseCode[o] = toupper(cal_Score[i].courseCode[o]);
                    }


                    do {
                        printf("Please Enter Student Grade 1 \t:");
                        scanf("%s", &cal_Score[i].grade);
                        rewind(stdin);
                        for (int o = 0;o <= Max_words;o++) {

                            cal_Score[i].grade[o] = toupper(cal_Score[i].grade[o]);
                        }

                        if (strcmp(cal_Score[i].grade, "A-") != 0 && strcmp(cal_Score[i].grade, "A") != 0 && strcmp(cal_Score[i].grade, "B") != 0 && strcmp(cal_Score[i].grade, "B-") != 0 && strcmp(cal_Score[i].grade, "B+") != 0 &&
                            strcmp(cal_Score[i].grade, "C+") != 0 && strcmp(cal_Score[i].grade, "C") != 0 && strcmp(cal_Score[i].grade, "C-") != 0 && strcmp(cal_Score[i].grade, "F") != 0) {
                            printf("Grade Invalid\n");
                        }

                    } while (strcmp(cal_Score[i].grade, "A-") != 0 && strcmp(cal_Score[i].grade, "A") != 0 && strcmp(cal_Score[i].grade, "B") != 0 && strcmp(cal_Score[i].grade, "B-") != 0 && strcmp(cal_Score[i].grade, "B+") != 0 &&
                        strcmp(cal_Score[i].grade, "C+") != 0 && strcmp(cal_Score[i].grade, "C") != 0 && strcmp(cal_Score[i].grade, "C-") != 0 && strcmp(cal_Score[i].grade, "F") != 0);


                    do {
                        printf("Please Enter Credit Hours 1\t:");
                        scanf("%d", &cal_Score[i].creditHours);
                        rewind(stdin);

                        if (cal_Score[i].creditHours <= 0) {
                            printf("Invalid\n");
                        }
                    } while (cal_Score[i].creditHours <= 0);

                    printf("\n");
                    printf("Please Enter Course Name 2\t:");
                    scanf(" %[^\n]s", &cal_Score[i].courseName1);
                    rewind(stdin);
                    for (int o = 0;o <= Max_words;o++) {

                        cal_Score[i].courseName[o] = toupper(cal_Score[i].courseName[o]);
                    }



                    printf("Please Enter Course Code 2\t:");
                    scanf(" %[^\n]s", &cal_Score[i].courseCode1);
                    rewind(stdin);
                    for (int o = 0;o <= Max_words;o++) {

                        cal_Score[i].courseCode1[o] = toupper(cal_Score[i].courseCode1[o]);
                    }



                    do {
                        printf("Please Enter Student Grade 2 \t:");
                        scanf("%s", &cal_Score[i].grade1);
                        rewind(stdin);
                        for (int o = 0;o <= Max_words;o++) {

                            cal_Score[i].grade1[o] = toupper(cal_Score[i].grade1[o]);
                        }

                        if (strcmp(cal_Score[i].grade1, "A-") != 0 && strcmp(cal_Score[i].grade1, "A") != 0 && strcmp(cal_Score[i].grade1, "B") != 0 && strcmp(cal_Score[i].grade1, "B-") != 0 && strcmp(cal_Score[i].grade1, "B+") != 0 &&
                            strcmp(cal_Score[i].grade1, "C+") != 0 && strcmp(cal_Score[i].grade1, "C") != 0 && strcmp(cal_Score[i].grade1, "C-") != 0 && strcmp(cal_Score[i].grade1, "F") != 0) {
                            printf("Grade Invalid\n");
                        }

                    } while (strcmp(cal_Score[i].grade1, "A-") != 0 && strcmp(cal_Score[i].grade1, "A") != 0 && strcmp(cal_Score[i].grade1, "B") != 0 && strcmp(cal_Score[i].grade1, "B-") != 0 && strcmp(cal_Score[i].grade1, "B+") != 0 &&
                        strcmp(cal_Score[i].grade1, "C+") != 0 && strcmp(cal_Score[i].grade1, "C") != 0 && strcmp(cal_Score[i].grade1, "C-") != 0 && strcmp(cal_Score[i].grade1, "F") != 0);


                    do {
                        printf("Please Enter Credit Hours 2\t:");
                        scanf("%d", &cal_Score[i].creditHours1);
                        rewind(stdin);

                        if (cal_Score[i].creditHours1 <= 0) {
                            printf("Invalid\n");
                        }
                    } while (cal_Score[i].creditHours1 <= 0);


                    if (strcmp(cal_Score[i].grade, "A") == 0)
                    {
                        cal_Score[i].gradePoint = A_PLUS;
                    }
                    else if (strcmp(cal_Score[i].grade, "A-") == 0)
                    {
                        cal_Score[i].gradePoint = A_MINUS;
                    }
                    else if (strcmp(cal_Score[i].grade, "B+") == 0)
                    {
                        cal_Score[i].gradePoint = B_PLUS;
                    }
                    else if (strcmp(cal_Score[i].grade, "B") == 0)
                    {
                        cal_Score[i].gradePoint = B_NORMAL;
                    }
                    else if (strcmp(cal_Score[i].grade, "B-") == 0)
                    {
                        cal_Score[i].gradePoint = B_MINUS;
                    }

                    else if (strcmp(cal_Score[i].grade, "C+") == 0)
                    {
                        cal_Score[i].gradePoint = C_PLUS;
                    }
                    else if (strcmp(cal_Score[i].grade, "C") == 0)
                    {
                        cal_Score[i].gradePoint = C_NORMAL;
                    }
                    else if (strcmp(cal_Score[i].grade, "F") == 0)
                    {
                        cal_Score[i].gradePoint = F_NORMAL;
                    }
                    else
                    {
                        printf("\n\n");
                        printf("Invalid");
                        printf("\n\n");
                        return cal_Score[i].gradePoint;

                    }
                    if (strcmp(cal_Score[i].grade1, "A") == 0)
                    {
                        cal_Score[i].gradePoint1 = A_PLUS;
                    }
                    else if (strcmp(cal_Score[i].grade1, "A-") == 0)
                    {
                        cal_Score[i].gradePoint1 = A_MINUS;
                    }
                    else if (strcmp(cal_Score[i].grade1, "B+") == 0)
                    {
                        cal_Score[i].gradePoint1 = B_PLUS;
                    }
                    else if (strcmp(cal_Score[i].grade1, "B") == 0)
                    {
                        cal_Score[i].gradePoint1 = B_NORMAL;
                    }
                    else if (strcmp(cal_Score[i].grade1, "B-") == 0)
                    {
                        cal_Score[i].gradePoint1 = B_MINUS;

                    }
                    else if (strcmp(cal_Score[i].grade1, "C+") == 0)
                    {
                        cal_Score[i].gradePoint1 = C_PLUS;
                    }
                    else if (strcmp(cal_Score[i].grade1, "C") == 0)
                    {
                        cal_Score[i].gradePoint1 = C_NORMAL;
                    }
                    else if (strcmp(cal_Score[i].grade1, "F") == 0)
                    {
                        cal_Score[i].gradePoint1 = F_NORMAL;
                    }
                    else
                    {
                        printf("\n\n");
                        printf("Invalid");
                        printf("\n\n");
                        return cal_Score[i].gradePoint1;
                    }

                    cal_Score[i].totalgradePoint = (cal_Score[i].gradePoint * cal_Score[i].creditHours);

                    cal_Score[i].totalgradePoint1 = (cal_Score[i].gradePoint1 * cal_Score[i].creditHours1);



                    cal_Score[i].gpaScore = cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint1;
                    cal_Score[i].totalcreditHours = cal_Score[i].creditHours + cal_Score[i].creditHours1;
                    cal_Score[i].calgpaScore = cal_Score[i].gpaScore / cal_Score[i].totalcreditHours;



                    printf("Quality Point Scores In Course 1\t:%.2lf \n", cal_Score[i].totalgradePoint);
                    printf("Quality Point Scores In Course 2\t:%.2lf \n", cal_Score[i].totalgradePoint1);
                    printf("GPA Scores\t:%.2lf \n", cal_Score[i].calgpaScore);


                    printf("\n");
                    system("pause");


                }
                ///
                int count = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;

                count1 = cal_Score[1].creditHours1 + cal_Score[1].creditHours;
                count2 = cal_Score[2].creditHours1 + cal_Score[2].creditHours;
                count4 = cal_Score[2].creditHours1 + cal_Score[2].creditHours + count1;
                count3 = cal_Score[3].creditHours1 + cal_Score[3].creditHours;
                count5 = cal_Score[3].creditHours1 + cal_Score[3].creditHours + count2 + count1;

                for (int i = 1;i <= 1;i++) {
                    //semester1

                    cal_Score[i].gpaScore = cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint1;
                    cal_Score[i].totalcreditHours = cal_Score[i].creditHours + cal_Score[i].creditHours1;
                    cal_Score[i].calgpaScore = cal_Score[i].gpaScore / cal_Score[i].totalcreditHours;





                    cal_Score[i].totalgpaScore = cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint1 + cal_Score[i].totalgradePoint1 + cal_Score[i].totalgradePoint1;
                    cal_Score[i].allcredithours = cal_Score[i].totalcreditHours + cal_Score[i].totalcreditHours + cal_Score[i].totalcreditHours;
                    cal_Score[i].totalcgpaScore = cal_Score[i].totalgpaScore / cal_Score[i].allcredithours;


                    fprintf(studentData, "Student Name:%s\n", studentName);
                    fprintf(studentData, "%10s\n", "SEMESTER 1");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");
                    fprintf(studentData, "%-31.2lf%s%31.2lf\n", cal_Score[1].calgpaScore, "|", cal_Score[i].totalcgpaScore);
                    fprintf(studentData, "%-31s%s%31s\n", "GPA", "|", "CGPA");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");
                    fprintf(studentData, "%-31d%s%31d\n", count1, "|", count1);
                    fprintf(studentData, "%-31s%s%31s\n", "Credit Hour Earned", "|", "Total Credit Hour Earned");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");


                    fprintf(studentData, "%.2lf", cal_Score[1].totalcgpaScore);
                    fprintf(studentData, "\n");
                    if (cal_Score[i].totalcgpaScore == 4.00) {
                        fprintf(studentData, "Congratulations! You've achieved a perfect CGPA. Maintain your dedication and commitment to excellence.\n");
                        fprintf(studentData, "Maintain a 4.00 CGPA throughout your academic journey.\n");
                        fprintf(studentData, "With consistent effort and focus, you can continue to earn a 4.00 CGPA.\n");
                    }
                    else if (cal_Score[i].totalcgpaScore >= 3.75) {
                        fprintf(studentData, "Outstanding work! Keep up your exceptional performance and strive for continuous improvement.\n");
                        fprintf(studentData, "Aim to consistently maintain or exceed a 3.75 CGPA.\n");
                        fprintf(studentData, "Your commitment to excellence will likely result in maintaining a CGPA above 3.75.\n");
                    }
                    else if (cal_Score[i].totalcgpaScore >= 3.50) {
                        fprintf(studentData, "You're doing exceptionally well. Stay focused and aim for academic growth.\n");
                        fprintf(studentData, "Set a goal to maintain or surpass a 3.50 CGPA.\n");
                        fprintf(studentData, "With determination, you should be able to maintain or exceed a 3.50 CGPA.\n");
                    }
                    else if (cal_Score[i].totalcgpaScore >= 3.25) {
                        fprintf(studentData, "You're above average, which is commendable. Keep working hard to reach higher.\n");
                        fprintf(studentData, "Strive for a CGPA above 3.25 in your upcoming terms.\n");
                        fprintf(studentData, "With consistent effort, you can maintain or improve your CGPA beyond 3.25.\n");
                    }
                    else if (cal_Score[i].totalcgpaScore >= 3.00) {
                        fprintf(studentData, "You're in good standing academically. Focus on refining your study habits and time management.\n");
                        fprintf(studentData, "Aim to maintain or exceed a 3.00 CGPA to ensure a strong academic record.\n");
                        fprintf(studentData, "With dedication, you should be able to maintain or improve your CGPA above 3.00.\n");
                    }
                    else if (cal_Score[i].totalcgpaScore >= 2.50) {
                        fprintf(studentData, "You're passing your courses, but there's room for growth. Identify areas for improvement.\n");
                        fprintf(studentData, "Set a goal to consistently achieve a CGPA higher than 2.50.\n");
                        fprintf(studentData, "With focused efforts, you can maintain or raise your CGPA above 2.50.\n");
                    }
                    else if (cal_Score[i].totalcgpaScore >= 2.00) {


                        fprintf(studentData, "You're making progress, but consider seeking academic support if needed.\n");
                        fprintf(studentData, "Aim to maintain or exceed a 2.00 CGPA to stay on track.\n");
                        fprintf(studentData, "With diligence, you can maintain or improve your CGPA above 2.00.\n");
                    }
                    else {
                        fprintf(studentData, "You're facing academic challenges, but it's not insurmountable. Seek help, adjust your study strategies, and persevere.\n");
                        fprintf(studentData, "Work toward raising your CGPA above 2.00 through consistent improvement.\n");
                        fprintf(studentData, "With focused efforts and support, you can raise your CGPA above 2.00 over time.\n");
                    }

                    fprintf(studentData, "\n");

                    //semester2

                    cal_Score[i].gpaScore = cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint1;
                    cal_Score[i].totalcreditHours = cal_Score[i].creditHours + cal_Score[i].creditHours1;
                    cal_Score[i].calgpaScore = cal_Score[i].gpaScore / cal_Score[i].totalcreditHours;


                    cal_Score[i].totalgpaScore = cal_Score[1].totalgradePoint + cal_Score[2].totalgradePoint + cal_Score[3].totalgradePoint + cal_Score[1].totalgradePoint1 + cal_Score[2].totalgradePoint1 + cal_Score[3].totalgradePoint1;
                    cal_Score[i].allcredithours = cal_Score[i].totalcreditHours + cal_Score[i].totalcreditHours + cal_Score[i].totalcreditHours;
                    cal_Score[i].totalcgpaScore = cal_Score[i].totalgpaScore / cal_Score[i].allcredithours;


                    totalScore1 = (cal_Score[1].gpaScore + cal_Score[2].gpaScore) / (cal_Score[1].totalcreditHours + cal_Score[2].totalcreditHours);
                    fprintf(studentData, "%10s\n", "SEMESTER 2");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");
                    fprintf(studentData, "%-31.2lf%s%31.2lf\n", cal_Score[2].calgpaScore, "|", totalScore1);
                    fprintf(studentData, "%-31s%s%31s\n", "GPA", "|", "CGPA");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");
                    fprintf(studentData, "%-31d%s%31d\n", count2, "|", count4);
                    fprintf(studentData, "%-31s%s%31s\n", "Credit Hour Earned", "|", "Total Credit Hour Earned");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");


                    fprintf(studentData, "%.2lf", totalScore1);
                    fprintf(studentData, "\n");
                    if (totalScore1 == 4.00) {
                        fprintf(studentData, "Congratulations! You've achieved a perfect CGPA. Maintain your dedication and commitment to excellence.\n");
                        fprintf(studentData, "Maintain a 4.00 CGPA throughout your academic journey.\n");
                        fprintf(studentData, "With consistent effort and focus, you can continue to earn a 4.00 CGPA.\n");
                    }
                    else if (totalScore1 >= 3.75) {
                        fprintf(studentData, "Outstanding work! Keep up your exceptional performance and strive for continuous improvement.\n");
                        fprintf(studentData, "Aim to consistently maintain or exceed a 3.75 CGPA.\n");
                        fprintf(studentData, "Your commitment to excellence will likely result in maintaining a CGPA above 3.75.\n");
                    }
                    else if (totalScore1 >= 3.50) {
                        fprintf(studentData, "You're doing exceptionally well. Stay focused and aim for academic growth.\n");
                        fprintf(studentData, "Set a goal to maintain or surpass a 3.50 CGPA.\n");
                        fprintf(studentData, "With determination, you should be able to maintain or exceed a 3.50 CGPA.\n");
                    }
                    else if (totalScore1 >= 3.25) {
                        fprintf(studentData, "You're above average, which is commendable. Keep working hard to reach higher.\n");
                        fprintf(studentData, "Strive for a CGPA above 3.25 in your upcoming terms.\n");
                        fprintf(studentData, "With consistent effort, you can maintain or improve your CGPA beyond 3.25.\n");
                    }
                    else if (totalScore1 >= 3.00) {
                        fprintf(studentData, "You're in good standing academically. Focus on refining your study habits and time management.\n");
                        fprintf(studentData, "Aim to maintain or exceed a 3.00 CGPA to ensure a strong academic record.\n");
                        fprintf(studentData, "With dedication, you should be able to maintain or improve your CGPA above 3.00.\n");
                    }
                    else if (totalScore1 >= 2.50) {
                        fprintf(studentData, "You're passing your courses, but there's room for growth. Identify areas for improvement.\n");
                        fprintf(studentData, "Set a goal to consistently achieve a CGPA higher than 2.50.\n");
                        fprintf(studentData, "With focused efforts, you can maintain or raise your CGPA above 2.50.\n");
                    }
                    else if (totalScore1 >= 2.00) {
                        fprintf(studentData, "You're making progress, but consider seeking academic support if needed.\n");
                        fprintf(studentData, "Aim to maintain or exceed a 2.00 CGPA to stay on track.\n");
                        fprintf(studentData, "With diligence, you can maintain or improve your CGPA above 2.00.\n");
                    }
                    else {
                        fprintf(studentData, "You're facing academic challenges, but it's not insurmountable. Seek help, adjust your study strategies, and persevere.\n");
                        fprintf(studentData, "Work toward raising your CGPA above 2.00 through consistent improvement.\n");
                        fprintf(studentData, "With focused efforts and support, you can raise your CGPA above 2.00 over time.\n");
                    }

                    fprintf(studentData, "\n");

                    //semester3
                    cal_Score[i].gpaScore = cal_Score[i].totalgradePoint + cal_Score[i].totalgradePoint1;
                    cal_Score[i].totalcreditHours = cal_Score[i].creditHours + cal_Score[i].creditHours1;
                    cal_Score[i].calgpaScore = cal_Score[i].gpaScore / cal_Score[i].totalcreditHours;

                    totalScore = (cal_Score[1].gpaScore + cal_Score[2].gpaScore + cal_Score[3].gpaScore) / (cal_Score[1].totalcreditHours + cal_Score[2].totalcreditHours + cal_Score[3].totalcreditHours);



                    fprintf(studentData, "%10s\n", "SEMESTER 3");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");
                    fprintf(studentData, "%-31.2lf%s%31.2lf\n", cal_Score[3].calgpaScore, "|", totalScore);
                    fprintf(studentData, "%-31s%s%31s\n", "GPA", "|", "CGPA");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");
                    fprintf(studentData, "%-31d%s%31d\n", count3, "|", count5);
                    fprintf(studentData, "%-31s%s%31s\n", "Credit Hour Earned", "|", "Total Credit Hour Earned");
                    fprintf(studentData, "%63s\n", "---------------------------------------------------------------");


                    fprintf(studentData, "%.2lf", totalScore);
                    fprintf(studentData, "\n");
                    if (totalScore == 4.00) {
                        fprintf(studentData, "Congratulations! You've achieved a perfect CGPA. Maintain your dedication and commitment to excellence.\n");
                        fprintf(studentData, "Maintain a 4.00 CGPA throughout your academic journey.\n");
                        fprintf(studentData, "With consistent effort and focus, you can continue to earn a 4.00 CGPA.\n");
                    }
                    else if (totalScore >= 3.75) {
                        fprintf(studentData, "Outstanding work! Keep up your exceptional performance and strive for continuous improvement.\n");
                        fprintf(studentData, "Aim to consistently maintain or exceed a 3.75 CGPA.\n");
                        fprintf(studentData, "Your commitment to excellence will likely result in maintaining a CGPA above 3.75.\n");
                    }
                    else if (totalScore >= 3.50) {
                        fprintf(studentData, "You're doing exceptionally well. Stay focused and aim for academic growth.\n");
                        fprintf(studentData, "Set a goal to maintain or surpass a 3.50 CGPA.\n");
                        fprintf(studentData, "With determination, you should be able to maintain or exceed a 3.50 CGPA.\n");
                    }
                    else if (totalScore >= 3.25) {
                        fprintf(studentData, "You're above average, which is commendable. Keep working hard to reach higher.\n");
                        fprintf(studentData, "Strive for a CGPA above 3.25 in your upcoming terms.\n");
                        fprintf(studentData, "With consistent effort, you can maintain or improve your CGPA beyond 3.25.\n");
                    }
                    else if (totalScore >= 3.00) {
                        fprintf(studentData, "You're in good standing academically. Focus on refining your study habits and time management.\n");
                        fprintf(studentData, "Aim to maintain or exceed a 3.00 CGPA to ensure a strong academic record.\n");
                        fprintf(studentData, "With dedication, you should be able to maintain or improve your CGPA above 3.00.\n");
                    }
                    else if (totalScore >= 2.50) {


                        fprintf(studentData, "You're passing your courses, but there's room for growth. Identify areas for improvement.\n");
                        fprintf(studentData, "Set a goal to consistently achieve a CGPA higher than 2.50.\n");
                        fprintf(studentData, "With focused efforts, you can maintain or raise your CGPA above 2.50.\n");
                    }
                    else if (totalScore >= 2.00) {
                        fprintf(studentData, "You're making progress, but consider seeking academic support if needed.\n");
                        fprintf(studentData, "Aim to maintain or exceed a 2.00 CGPA to stay on track.\n");
                        fprintf(studentData, "With diligence, you can maintain or improve your CGPA above 2.00.\n");
                    }
                    else {
                        fprintf(studentData, "You're facing academic challenges, but it's not insurmountable. Seek help, adjust your study strategies, and persevere.\n");
                        fprintf(studentData, "Work toward raising your CGPA above 2.00 through consistent improvement.\n");
                        fprintf(studentData, "With focused efforts and support, you can raise your CGPA above 2.00 over time.\n");
                    }

                    fprintf(studentData, "\n");

                    //all coursename
                    fprintf(studentData, "\n\n");
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", "Course Code", "Course Name", "Grade");
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", cal_Score[1].courseCode, cal_Score[1].courseName, cal_Score[1].grade);
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", cal_Score[1].courseCode1, cal_Score[1].courseName1, cal_Score[1].grade1);
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", cal_Score[2].courseCode, cal_Score[2].courseName, cal_Score[2].grade);
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", cal_Score[2].courseCode1, cal_Score[2].courseName1, cal_Score[2].grade1);
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", cal_Score[3].courseCode, cal_Score[3].courseName, cal_Score[3].grade);
                    fprintf(studentData, "%-20s | %-50s | %-10s\n", cal_Score[3].courseCode1, cal_Score[3].courseName1, cal_Score[3].grade1);
                    fprintf(studentData, "\n\n");

                    for (int i = 1;i <= 3;i++) {
                        for (int g = 1;g <= 1;g++) {

                            fprintf(studentData, "\n");
                            fprintf(studentData, "%s:\n", cal_Score[i].courseName);


                            if (strcmp(cal_Score[i].grade, "A") == 0) {
                                fprintf(studentData, "Congratulations! You're excelling in your studies.\n");
                                fprintf(studentData, "Continue to stay engaged, participate actively, and explore advanced topics in your courses.\n");
                                fprintf(studentData, "Consider taking on challenging projects or research opportunities to further enhance your academic profile.\n");
                                fprintf(studentData, "Maintain a healthy work - life balance to prevent burnout.\n");
                            }
                            else if (strcmp(cal_Score[i].grade, "A-") == 0) {
                                fprintf(studentData, "Great job! You're performing at a high level.\n");
                                fprintf(studentData, "Focus on fine - tuning your study habits and time management skills for even better results.\n");
                                fprintf(studentData, "Seek out opportunities for extracurricular activities or internships to gain practical experience.\n");
                                fprintf(studentData, "Keep an eye on your GPA to ensure you maintain this excellent performance.\n");
                            }
                            else if (strcmp(cal_Score[i].grade, "B+") == 0) {
                                fprintf(studentData, "Well done! You're above average in your studies.\n");
                                fprintf(studentData, "Review your study methods to see if there's room for improvement.\n");
                                fprintf(studentData, "Consider forming study groups or seeking tutoring if you're facing challenges.\n");
                                fprintf(studentData, "Aim to maintain or improve this grade in future courses.\n");

                            }
                            else if (strcmp(cal_Score[i].grade, "B") == 0) {
                                fprintf(studentData, "You're doing solid work, keep it up!\n");
                                fprintf(studentData, "Continue to attend classes regularly and actively participate.\n");
                                fprintf(studentData, "Identify areas where you can apply your knowledge to real - world situations.\n");
                                fprintf(studentData, "Strive for consistent performance to enhance your overall GPA.\n");
                            }
                            else if (strcmp(cal_Score[i].grade, "B-") == 0) {
                                fprintf(studentData, "You're on the right track, but there's room for improvement.\n");
                                fprintf(studentData, "Evaluate your study habits and time management to avoid slipping grades.\n");
                                fprintf(studentData, "Seek assistance from professors or academic advisors if you're struggling in specific subjects.\n");
                                fprintf(studentData, "Consider revisiting your academic goals and developing a plan for growth.\n");
                            }
                            else if (strcmp(cal_Score[i].grade, "C+") == 0) {
                                fprintf(studentData, "You're passing, but there's potential for improvement.\n");
                                fprintf(studentData, "Focus on strengthening your understanding of the course material.\n");
                                fprintf(studentData, "Attend office hours or seek peer support if you're facing challenges.\n");
                                fprintf(studentData, "Reevaluate your study schedule and make adjustments as needed.\n");

                            }
                            else if (strcmp(cal_Score[i].grade, "C") == 0) {
                                fprintf(studentData, "You're meeting the minimum requirements, but consider aiming higher.\n");
                                fprintf(studentData, "Reflect on your study methods and seek help if you're having trouble.\n");
                                fprintf(studentData, "Set clear goals for the next term to improve your performance.\n");
                                fprintf(studentData, "Don't hesitate to consult with academic advisors for guidance.\n");

                            }
                            else if (strcmp(cal_Score[i].grade, "F") == 0) {
                                fprintf(studentData, "Receiving an F can be discouraging, but it's an opportunity to learn and grow.\n");
                                fprintf(studentData, "Review what led to this grade and identify areas for improvement.\n");
                                fprintf(studentData, "Speak with your professor to understand what went wrong and if there's a chance for remediation.\n");
                                fprintf(studentData, "Develop a plan for retaking the course or addressing academic challenges to avoid future failures.\n");
                            }




                            fprintf(studentData, "\n");
                            fprintf(studentData, "%s:\n", cal_Score[i].courseName1);



                            if (strcmp(cal_Score[i].grade1, "A") == 0) {
                                fprintf(studentData, "Congratulations! You're excelling in your studies.\n");
                                fprintf(studentData, "Continue to stay engaged, participate actively, and explore advanced topics in your courses.\n");
                                fprintf(studentData, "Consider taking on challenging projects or research opportunities to further enhance your academic profile.\n");
                                fprintf(studentData, "Maintain a healthy work - life balance to prevent burnout.\n");
                            }
                            else if (strcmp(cal_Score[i].grade1, "A-") == 0) {
                                fprintf(studentData, "Great job! You're performing at a high level.\n");
                                fprintf(studentData, "Focus on fine - tuning your study habits and time management skills for even better results.\n");
                                fprintf(studentData, "Seek out opportunities for extracurricular activities or internships to gain practical experience.\n");
                                fprintf(studentData, "Keep an eye on your GPA to ensure you maintain this excellent performance.\n");
                            }
                            else if (strcmp(cal_Score[i].grade1, "B+") == 0) {
                                fprintf(studentData, "Well done! You're above average in your studies.\n");
                                fprintf(studentData, "Review your study methods to see if there's room for improvement.\n");
                                fprintf(studentData, "Consider forming study groups or seeking tutoring if you're facing challenges.\n");
                                fprintf(studentData, "Aim to maintain or improve this grade in future courses.\n");

                            }
                            else if (strcmp(cal_Score[i].grade1, "B") == 0) {
                                fprintf(studentData, "You're doing solid work, keep it up!\n");
                                fprintf(studentData, "Continue to attend classes regularly and actively participate.\n");
                                fprintf(studentData, "Identify areas where you can apply your knowledge to real - world situations.\n");
                                fprintf(studentData, "Strive for consistent performance to enhance your overall GPA.\n");


                            }
                            else if (strcmp(cal_Score[i].grade1, "B-") == 0) {
                                fprintf(studentData, "You're on the right track, but there's room for improvement.\n");
                                fprintf(studentData, "Evaluate your study habits and time management to avoid slipping grades.\n");
                                fprintf(studentData, "Seek assistance from professors or academic advisors if you're struggling in specific subjects.\n");
                                fprintf(studentData, "Consider revisiting your academic goals and developing a plan for growth.\n");
                            }
                            else if (strcmp(cal_Score[i].grade1, "C+") == 0) {
                                fprintf(studentData, "You're passing, but there's potential for improvement.\n");
                                fprintf(studentData, "Focus on strengthening your understanding of the course material.\n");
                                fprintf(studentData, "Attend office hours or seek peer support if you're facing challenges.\n");
                                fprintf(studentData, "Reevaluate your study schedule and make adjustments as needed.\n");

                            }
                            else if (strcmp(cal_Score[i].grade1, "C") == 0) {
                                fprintf(studentData, "You're meeting the minimum requirements, but consider aiming higher.\n");
                                fprintf(studentData, "Reflect on your study methods and seek help if you're having trouble.\n");
                                fprintf(studentData, "Set clear goals for the next term to improve your performance.\n");
                                fprintf(studentData, "Don't hesitate to consult with academic advisors for guidance.\n");


                            }
                            else if (strcmp(cal_Score[i].grade1, "F") == 0) {
                                fprintf(studentData, "Receiving an F can be discouraging, but it's an opportunity to learn and grow.\n");
                                fprintf(studentData, "Review what led to this grade and identify areas for improvement.\n");
                                fprintf(studentData, "Speak with your professor to understand what went wrong and if there's a chance for remediation.\n");
                                fprintf(studentData, "Develop a plan for retaking the course or addressing academic challenges to avoid future failures.\n");
                            }
                        }
                    }

                }

                system("cls");
            }
            printf("THE STUDENT DATA HAVE BEEN SAVE SUCCESSFUL^-^\n");


            fclose(studentData);

        }

        else if (choice == 2) {

            char studentID1[50];
            printf("=======================================================\n");
            printf("(^o^)        WELCOME TO STUDENT LOGIN PAGE        (^o^)\n");
            printf("=======================================================\n");
            printf("Please Enter The Student Detail:\n");
            printf("Enter Your Student ID: ");
            scanf("%s", studentID1);
            printf("\n");











            char filename[10000];
            sprintf(filename, "%s.txt", studentID1);

            FILE* studentData2 = fopen(filename, "r");
            if (studentData2 == NULL) {
                printf("Student data not found.\n");
            }

            else {
                char ch[10000];
                while (fgets(ch, 100000, studentData2)) {
                    printf("%s", ch);
                }


                fclose(studentData2);
            }


        }

        else if (choice == 3) {
            printf("EXIT");
            return 0;
        }


        printf("\n");

    } while (choice != 4);
    return 0;
}