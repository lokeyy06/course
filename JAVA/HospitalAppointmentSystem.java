import java.util.Scanner;

public class HospitalAppointmentSystem {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("======================================");
        System.out.println(" HOSPITAL APPOINTMENT MANAGEMENT SYSTEM");
        System.out.println("======================================");

        System.out.print("Enter Patient ID: ");
        String pid = sc.nextLine();

        System.out.print("Enter Patient Name: ");
        String pname = sc.nextLine();

        System.out.print("Enter Age: ");
        int age = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Gender: ");
        String gender = sc.nextLine();

        System.out.println("\nDepartments:");
        System.out.println("1. Cardiology");
        System.out.println("2. Neurology");
        System.out.println("3. Orthopedics");
        System.out.println("4. Pediatrics");
        System.out.println("5. General Medicine");

        System.out.print("Select Department (1-5): ");
        int deptChoice = sc.nextInt();
        sc.nextLine();

        String department;

        switch (deptChoice) {
            case 1:
                department = "Cardiology";
                break;
            case 2:
                department = "Neurology";
                break;
            case 3:
                department = "Orthopedics";
                break;
            case 4:
                department = "Pediatrics";
                break;
            case 5:
                department = "General Medicine";
                break;
            default:
                department = "Invalid Department";
        }

        System.out.println("\nDoctors:");
        System.out.println("1. Dr. Kumar");
        System.out.println("2. Dr. Meena");
        System.out.println("3. Dr. Raj");
        System.out.println("4. Dr. Anita");

        System.out.print("Select Doctor (1-4): ");
        int doctorChoice = sc.nextInt();
        sc.nextLine();

        String doctor;

        switch (doctorChoice) {
            case 1:
                doctor = "Dr. Kumar";
                break;
            case 2:
                doctor = "Dr. Meena";
                break;
            case 3:
                doctor = "Dr. Raj";
                break;
            case 4:
                doctor = "Dr. Anita";
                break;
            default:
                doctor = "Invalid Doctor";
        }

        System.out.print("Enter Appointment Date (dd-mm-yyyy): ");
        String date = sc.nextLine();

        System.out.println("\n======================================");
        System.out.println("       APPOINTMENT SUMMARY");
        System.out.println("======================================");
        System.out.println("Patient ID       : " + pid);
        System.out.println("Patient Name     : " + pname);
        System.out.println("Age              : " + age);
        System.out.println("Gender           : " + gender);
        System.out.println("Department       : " + department);
        System.out.println("Doctor           : " + doctor);
        System.out.println("Appointment Date : " + date);
        System.out.println("======================================");
        System.out.println("Appointment Booked Successfully!");
    }
}